using System.Windows;
using OSiSP.ViewModel;

namespace OSiSP.View
{
    public partial class Extentions : Window
    {
        public Extentions()
        {
            InitializeComponent();
            DataContext = new ExtensionsViewModel();
        }
    }
}
