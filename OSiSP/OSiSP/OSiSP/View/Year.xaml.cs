using System.Windows;
using OSiSP.Model;

namespace OSiSP.View
{
    public partial class Year : Window
    {
        public Year()
        {
            InitializeComponent();
            DataContext = new YearChartModel();
        }
    }
}
