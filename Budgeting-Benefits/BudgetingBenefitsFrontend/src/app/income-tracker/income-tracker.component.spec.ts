import { ComponentFixture, TestBed } from '@angular/core/testing';

import { IncomeTrackerComponent } from './income-tracker.component';

describe('IncomeTrackerComponent', () => {
  let component: IncomeTrackerComponent;
  let fixture: ComponentFixture<IncomeTrackerComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [IncomeTrackerComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(IncomeTrackerComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
