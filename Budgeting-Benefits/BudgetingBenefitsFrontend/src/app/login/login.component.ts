import { Component, OnInit } from '@angular/core';
import { AuthService } from './auth/auth.service';
import { Router } from '@angular/router';
import { FormBuilder, Validators, FormGroup } from '@angular/forms';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css']
})
export class LoginComponent implements OnInit {
  loginForm: FormGroup;
  signUpForm: FormGroup;
  loading: boolean = false;
  error: string = '';
  isSignUp: boolean = false;

  constructor(private authService: AuthService, private router: Router, private formBuilder: FormBuilder) {
    this.loginForm = this.formBuilder.group({
      email: ['', [Validators.required, Validators.email]],
      password: ['', [ Validators.required, Validators.minLength(6)]]
    });

    this.signUpForm = this.formBuilder.group({
      name: ['', Validators.required],
      email: ['', [Validators.required, Validators.email]],
      password: ['', [Validators.required, Validators.minLength(6)]]
    });
  }

  ngOnInit(): void {
  }

  async onSubmit() {
    this.loading = true;
    try {
      await this.authService.login(this.loginForm.value.email, this.loginForm.value.password);
      this.router.navigate(['/dash']);
    } catch (error: any) {
      this.error = error.message;
      this.loading = false;
    }
  }

  async onSignUp() {
    this.loading = true;
    try {
      await this.authService.signUp(this.signUpForm.value.name, this.signUpForm.value.email, this.signUpForm.value.password);
      this.isSignUp = false;
      this.loading = false;
    } catch (error: any) {
      this.error = error.message;
      this.loading = false;
    }
  }

  toggleForm() {
    this.isSignUp = !this.isSignUp;
  }
}