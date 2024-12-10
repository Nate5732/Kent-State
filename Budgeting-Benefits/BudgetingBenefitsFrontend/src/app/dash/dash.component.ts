import { Component, Inject, OnInit, PLATFORM_ID } from '@angular/core';
import { UserService, User, MonthlyIncome } from '../Services/user.service';
import { AuthService } from '../login/auth/auth.service';
import { isPlatformBrowser, isPlatformServer } from '@angular/common';


@Component({
  selector: 'app-dash',
  templateUrl: './dash.component.html',
  styleUrl: './dash.component.css'
})
export class DashComponent implements OnInit{

  constructor(private userService: UserService, private authService: AuthService, @Inject(PLATFORM_ID) private platformId: Object) {}

  user: User | null = null;
  income: MonthlyIncome | null = null;
  currentInc: number = 0;

  async ngOnInit(): Promise<void> {
      
      const userId = sessionStorage.getItem('id');
      const token = sessionStorage.getItem('access_token');
      if(token && userId){
        this.user = await this.userService.getUserById(Number(userId), token);
        console.log(this.user);
        this.income = this.user.monthlyInc
        this.currentInc = this.income[getYM()];
        console.log(this.income);
        
        
      }
        
  }

  logout(): void {
    this.authService.logout();
  }

}


function getYM(): string {
  const dateObj = new Date();
  const year = dateObj.getUTCFullYear();
  const month = dateObj.getUTCMonth() + 1;
  console.log(`${year}-${month}`)
  return `${year}-${month}`
}
