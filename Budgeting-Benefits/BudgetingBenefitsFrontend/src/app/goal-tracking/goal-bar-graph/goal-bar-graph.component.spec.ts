import { ComponentFixture, TestBed } from '@angular/core/testing';

import { GoalBarGraphComponent } from './goal-bar-graph.component';

describe('GoalBarGraphComponent', () => {
  let component: GoalBarGraphComponent;
  let fixture: ComponentFixture<GoalBarGraphComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [GoalBarGraphComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(GoalBarGraphComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
