using System.Windows;
using OSiSP.ViewModel;

namespace OSiSP.View
{
    public partial class Add : Window
    {
        public Add()
        {
            InitializeComponent();
            DataContext = new ApplicationViewModel("Add");
        }

        private void Accept_Click(object sender, RoutedEventArgs e)
        {
            this.DialogResult = true;
        }
    }
}
