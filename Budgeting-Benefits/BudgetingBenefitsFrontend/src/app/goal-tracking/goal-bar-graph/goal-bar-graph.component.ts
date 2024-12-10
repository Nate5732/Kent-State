import { Component, Input, OnInit, ViewChild, ElementRef, OnChanges, SimpleChanges, OnDestroy } from '@angular/core';
import { Chart, ChartConfiguration, ChartType, ScaleOptions } from 'chart.js/auto';

@Component({
  selector: 'app-goal-bar-graph',
  templateUrl: './goal-bar-graph.component.html',
  styleUrls: ['./goal-bar-graph.component.css']
})
export class GoalBarGraphComponent  implements OnInit, OnChanges, OnDestroy {
  @Input() allocation: number = 0;
  @Input() totalIncome: number = 0;
  @Input() category: string = '';

  @ViewChild('allocationChart', { static: false })
  chartCanvas!: ElementRef;
  
  chart: Chart | null = null;
  allocationPercentage: number = 0;

  ngOnInit() {
    this.calculateAllocationPercentage();
  }

  ngOnChanges(changes: SimpleChanges) {
    if ((changes['allocation'] || changes['totalIncome']) && this.chartCanvas) {
      this.calculateAllocationPercentage();
      this.updateChart();
    }
  }

  private calculateAllocationPercentage() {
    this.allocationPercentage = this.totalIncome > 0 
      ? Math.min((this.allocation / this.totalIncome) * 100, 100)
      : 0;
  }

  ngAfterViewInit() {
    this.createChart();
  }

  private createChart() {
    if (this.chart) {
      this.chart.destroy();
    }

    if (!this.chartCanvas || this.totalIncome === 0) {
      return;
    }

    const remainingAmount = Math.max(this.totalIncome - this.allocation, 0);

    const chartConfig: ChartConfiguration = {
      type: 'bar' as ChartType,
      data: {
        labels: [this.category],
        datasets: [
          {
            label: this.category,
            data: [this.allocation],
            backgroundColor: ['#2563eb'],
            borderWidth: 0,
            borderRadius: 9999
          },
          {
            label: 'Remaining',
            data: [remainingAmount],
            backgroundColor: ['#e5e7eb'],
            borderWidth: 0,
            borderRadius: 9999
          }
        ]
      },
      options: {
        indexAxis: 'x',
        responsive: true,
        maintainAspectRatio: false,
        plugins: {
          legend: {
            display: false
          },
          tooltip: {
            callbacks: {
              label: (context) => {
                if (context.datasetIndex === 0) {
                  return `${this.category}: $${this.allocation.toFixed(2)} (${this.allocationPercentage.toFixed(2)}%)`;
                }
                return `Remaining: $${remainingAmount.toFixed(2)}`;
              }
            }
          }
        },
        scales: this.getScaleOptions()
      }
    };

    try {
      this.chart = new Chart(this.chartCanvas.nativeElement, chartConfig);
    } catch (error) {
      console.error('Error creating chart:', error);
    }
  }

  private getScaleOptions(): { 
    x: ScaleOptions; 
    y: ScaleOptions 
  } {
    return {
      x: {
        stacked: true,
        grid: {
          display: false
        },
        ticks: {
          display: false
        }
      },
      y: {
        stacked: true,
        beginAtZero: true,
        max: this.totalIncome,
        grid: {
          display: false
        },
        ticks: {
          display: false
        }
      }
    };
  }

  private updateChart() {
    if (this.chart) {
      try {
        const remainingAmount = Math.max(this.totalIncome - this.allocation, 0);
  
        this.chart.data.datasets[0].data = [this.allocation];
        this.chart.data.datasets[1].data = [remainingAmount];
        
        if (this.chart.options.scales) {
          const yScale = this.chart.options.scales['y'];
          if (yScale) {
            yScale.max = this.totalIncome;
          }
        }
        
        this.chart.update();
      } catch (error) {
        console.error('Error updating chart:', error);
        this.createChart();
      }
    } else {
      this.createChart();
    }
  }

  ngOnDestroy() {
    if (this.chart) {
      this.chart.destroy();
    }
  }
}