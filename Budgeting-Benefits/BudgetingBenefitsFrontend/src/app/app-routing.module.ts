import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { HomeComponent } from './home/home.component';
import { AboutComponent } from './about/about.component';
import { LoginComponent } from './login/login.component';
import { DashComponent } from './dash/dash.component';
import { IncomeTrackerComponent } from './income-tracker/income-tracker.component';
import { GoalTrackingComponent } from './goal-tracking/goal-tracking.component';

const routes: Routes = [
  { path: 'home', component: HomeComponent },
  { path: 'about', component: AboutComponent },
  { path: '', component: LoginComponent},
  { path: 'dash', component: DashComponent},
  { path: 'inc', component: IncomeTrackerComponent},
  { path: 'goal', component: GoalTrackingComponent}
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
