using System;
using System.Collections.Generic;
using System.Linq;
using LiveCharts;
using LiveCharts.Wpf;
using OSiSP.ViewModel;
using SumForThePeriod;

namespace OSiSP.Model
{
    class MonthChartModel
    {
        public SeriesCollection SeriesCollection { get; set; }
        public string[] Labels { get; set; }

        public Func<double, string> Formatter { get; set; }

        private ApplicationViewModel app = new ApplicationViewModel();

        public MonthChartModel()
        {
            SetChart();
        }

        public void SetChart()
        {
            using (app.Context = new TicketContext())
            {
                List<decimal> month = new List<decimal>();

                for (int i = 1; i < DateTime.DaysInMonth(DateTime.Now.Year, DateTime.Now.Month); i++)
                {
                    var temp = app.Context.Tickets
                        .ToList()
                        .Where(t => DateTime.Parse(t.Date).Month == DateTime.Now.Month)
                        .Where(t => DateTime.Parse(t.Date).Day == i)
                        .Select(t => t.Sum)
                        .Sum();
                    month.Add(temp);
                }

                TotalSum sum = new TotalSum();
                sum.Sum = app.Context.Tickets.ToList().Where(t => DateTime.Parse(t.Date).Month == DateTime.Now.Month)
                    .Select(t => t.Sum).Sum();

                SeriesCollection = new SeriesCollection
                {
                    new ColumnSeries
                    {
                        Title = $"Total - {sum.Sum}",
                        Values = new ChartValues<decimal>(month)
                    }
                };

                var daysInMonth = DateTime.DaysInMonth(DateTime.Now.Year, DateTime.Now.Month);

                string[] labels = new[]
                {
                    "1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
                    "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
                    "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"
                };
                Labels = labels[..(daysInMonth - 1)];
            }

            Formatter = value => value.ToString("N");
        }
    }
}
