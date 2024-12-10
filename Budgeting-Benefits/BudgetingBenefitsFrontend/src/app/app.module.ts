import { NgModule } from '@angular/core';
import { BrowserModule, provideClientHydration } from '@angular/platform-browser';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { HomeComponent } from './home/home.component';
import { AboutComponent } from './about/about.component';
import { LoginComponent } from './login/login.component';
import { ReactiveFormsModule } from '@angular/forms';
import { HttpClientModule, HTTP_INTERCEPTORS } from '@angular/common/http';
import { AuthInterceptor } from './login/auth/auth.interceptor';
import { DashComponent } from './dash/dash.component';
import { IncomeTrackerComponent } from './income-tracker/income-tracker.component';
import { AllocationBarGraphComponent } from './income-tracker/allocation-bar-graph/allocation-bar-graph.component';
import { GoalTrackingComponent } from './goal-tracking/goal-tracking.component';
import { GoalBarGraphComponent } from './goal-tracking/goal-bar-graph/goal-bar-graph.component';


@NgModule({
  declarations: [
    AppComponent,
    HomeComponent,
    AboutComponent,
    LoginComponent,
    DashComponent,
    IncomeTrackerComponent,
    AllocationBarGraphComponent,
    GoalTrackingComponent,
    GoalBarGraphComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    ReactiveFormsModule,
    HttpClientModule  
  ],
  providers: [
    provideClientHydration(), { provide: HTTP_INTERCEPTORS, useClass: AuthInterceptor, multi: true }
  ],
  bootstrap: [AppComponent]
})
export class AppModule { }
