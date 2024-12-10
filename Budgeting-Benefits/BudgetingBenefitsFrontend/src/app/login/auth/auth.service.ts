import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { firstValueFrom, Observable } from 'rxjs';
import { first, tap } from 'rxjs/operators';
import { Router, RouterLink } from '@angular/router';

@Injectable({
  providedIn: 'root'
})
export class AuthService {
  private apiUrl = 'http://localhost:3000';

  constructor(private http: HttpClient, private router: Router) { }

 async login(email: string, password: string): Promise<any> {
      let response = await firstValueFrom(this.http.post<any>(`${this.apiUrl}/auth/login`, {email, password}));
      if(response && response.access_token && response.id) {
        sessionStorage.setItem('access_token', response.access_token);
        sessionStorage.setItem('id', response.id);
      } else {
        throw Error("Authorization Error")
      }
  }


  getToken(): string | null {
    return sessionStorage.getItem('access_token');
  }

  isLoggedIn(): boolean {
    return !!this.getToken();
  }

  logout(): void {
    sessionStorage.removeItem('access_token');
    sessionStorage.removeItem('id');
    this.router.navigate(['']);
  }

  async signUp(name: string, email: string, password: string): Promise<any> {
    let response = await firstValueFrom(this.http.post<any>(`${this.apiUrl}/user`, {name, email, password}));
    if(response && response.name && response.email) {
      sessionStorage.setItem('access_token', response.access_token);
      sessionStorage.setItem('id', response.id);
    } else {
      throw Error("Authorization Error")
    }
  }
}