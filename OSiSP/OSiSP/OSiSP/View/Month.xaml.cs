using OSiSP.Model;
using System.Windows;

namespace OSiSP.View
{
    public partial class Month : Window
    {
        public Month()
        {
            InitializeComponent();
            DataContext = new MonthChartModel();
        }
    }
}
