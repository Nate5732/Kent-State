import { Injectable } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';
import { firstValueFrom, Observable } from 'rxjs';

export interface User {
  id: number;
  name: string;
  monthlyInc: MonthlyIncome;
}

export interface MonthlyIncome {
  [key: string]: number;
}


@Injectable({
  providedIn: 'root'
})
export class UserService {
  private apiUrl = 'http://localhost:3000/user';


  constructor(private http: HttpClient) { }

  

  async getUserById(id: number, token: string): Promise<User> {
    return firstValueFrom(this.http.get<User>(`${this.apiUrl}/${id}`, { headers: new HttpHeaders({
      'Content-Type': 'application/json',
      'Authorization': `Bearer ${token}`
    }) }));
  }



}
