import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-income-tracker',
  templateUrl: './income-tracker.component.html',
  styleUrls: ['./income-tracker.component.css']
})
export class IncomeTrackerComponent implements OnInit {
  
  currentInc: number = 5000;

  
  foodAllocation: number = 1250;
  rentAllocation: number = 1250;
  billsAllocation: number = 2000;
  otherAllocation: number = 500;

  constructor() { }

  ngOnInit(): void {
    
  }

  
  editIncome() {
    console.log('Edit Income clicked');
    // Implement income editing logic
  }

  editFoodAllocation() {
    console.log('Edit Food Allocation clicked');
    // Implement food allocation editing logic
  }

  editRentAllocation() {
    console.log('Edit Rent Allocation clicked');
    // Implement rent allocation editing logic
  }

  editBillsAllocation() {
    console.log('Edit Bills Allocation clicked');
    // Implement bills allocation editing logic
  }

  editOtherAllocation() {
    console.log('Edit Other Allocation clicked');
    // Implement other allocation editing logic
  }

  logout() {
    console.log('Logout clicked');
    // Implement logout logic
  }
}