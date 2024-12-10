import { ComponentFixture, TestBed } from '@angular/core/testing';

import { AllocationBarGraphComponent } from './allocation-bar-graph.component';

describe('AllocationBarGraphComponent', () => {
  let component: AllocationBarGraphComponent;
  let fixture: ComponentFixture<AllocationBarGraphComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [AllocationBarGraphComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(AllocationBarGraphComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
