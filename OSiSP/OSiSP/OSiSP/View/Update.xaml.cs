using System.Windows;
using OSiSP.Model;
using OSiSP.ViewModel;

namespace OSiSP.View
{
    public partial class Update : Window
    {
        public Update(TicketModel model)
        {
            InitializeComponent();
            var app = new ApplicationViewModel {SelectedTicket = model};
            DataContext = app;
        }

        private void Accept_Click(object sender, RoutedEventArgs e)
        {
            this.DialogResult = true;
        }
    }
}
