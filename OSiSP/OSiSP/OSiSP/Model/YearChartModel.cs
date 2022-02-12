using System;
using System.Collections.Generic;
using System.Linq;
using LiveCharts;
using LiveCharts.Wpf;
using OSiSP.ViewModel;
using SumForThePeriod;

namespace OSiSP.Model
{
    class YearChartModel
    {
        public SeriesCollection SeriesCollection { get; set; }
        public string[] Labels { get; set; }
        public Func<double, string> Formatter { get; set; }

        private ApplicationViewModel app = new ApplicationViewModel();

        public YearChartModel()
        {
            SetChart();
        }

        public void SetChart()
        {
            using (app.Context = new TicketContext())
            {
                List<decimal> year = new List<decimal>();

                for (int month = 1; month <= 12; month++)
                {
                    var temp = app.Context.Tickets
                        .ToList()
                        .Where(t => DateTime.Parse(t.Date).Year == DateTime.Now.Year)
                        .Where(t => DateTime.Parse(t.Date).Month == month)
                        .Select(t => t.Sum)
                        .Sum();
                    year.Add(temp);
                }

                TotalSum sum = new TotalSum();
                sum.Sum = app.Context.Tickets.Select(t => t.Sum).Sum();

                SeriesCollection = new SeriesCollection
                {
                    new ColumnSeries
                    {
                        Title = $"Total - {sum.Sum}",
                        Values = new ChartValues<decimal> (year)
                    }
                };
                Labels = new[] { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
            }

            Formatter = value => value.ToString("N");
        }
    }
}
