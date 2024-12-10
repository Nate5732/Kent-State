import { Component, OnInit } from '@angular/core';

interface Goal {
  id: number;
  name: string;
  targetAmount: number;
  currentAmount: number;
  targetDate?: Date;
  category?: string;
}

@Component({
  selector: 'app-goal-tracking',
  templateUrl: './goal-tracking.component.html',
  styleUrls: ['./goal-tracking.component.css']
})
export class GoalTrackingComponent implements OnInit {
  goals: Goal[] = [
    {
      id: 1,
      name: 'Emergency Fund',
      targetAmount: 10000,
      currentAmount: 5000,
      targetDate: new Date(2024, 11, 31),
      category: 'Savings'
    },
    {
      id: 2,
      name: 'Vacation Fund',
      targetAmount: 5000,
      currentAmount: 2500,
      targetDate: new Date(2024, 6, 30),
      category: 'Travel'
    }
  ];

  get totalSavingsGoal(): number {
    return this.goals.reduce((sum, goal) => sum + goal.targetAmount, 0);
  }

  constructor() { }

  ngOnInit(): void {
  }

  addNewGoal() {
    const newGoal: Goal = {
      id: this.goals.length + 1,
      name: 'New Goal',
      targetAmount: 0,
      currentAmount: 0
    };
    this.goals.push(newGoal);
  }

  editGoal(goal: Goal) {
    // Implement goal editing logic
  }

  deleteGoal(goal: Goal) {
    this.goals = this.goals.filter(g => g.id !== goal.id);
  }

  logout() {
    // Implement logout logic
  }
}