import { Component, Input, OnInit, ViewChild, ElementRef, OnChanges, SimpleChanges } from '@angular/core';
import { Chart, ChartConfiguration, ChartType } from 'chart.js/auto';

@Component({
  selector: 'app-allocation-bar-graph',
  templateUrl: './allocation-bar-graph.component.html',
  styleUrls: ['./allocation-bar-graph.component.css']
})
export class AllocationBarGraphComponent implements OnInit, OnChanges {
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

    const chartConfig: ChartConfiguration = {
      type: 'bar' as ChartType,
      data: {
        labels: [this.category],
        datasets: [{
          label: this.category,
          data: [this.allocation],
          backgroundColor: ['#2563eb'],
          borderWidth: 0,
          borderRadius: 9999
        }]
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
              label: () => {
                return `${this.category}: $${this.allocation.toFixed(2)} (${this.allocationPercentage.toFixed(2)}%)`
              }
            }
          }
        },
        scales: {
          x: {
            grid: {
              display: false
            },
            ticks: {
              display: false
            }
          },
          y: {
            beginAtZero: true,
            max: this.totalIncome,
            grid: {
              display: false
            },
            ticks: {
              display: false
            }
          }
        }
      }
    };

    try {
      this.chart = new Chart(this.chartCanvas.nativeElement, chartConfig);
    } catch (error) {
      console.error('Error creating chart:', error);
    }
  }

  private updateChart() {
    if (this.chart) {
      try {
        this.chart.data.datasets[0].data = [this.allocation];
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