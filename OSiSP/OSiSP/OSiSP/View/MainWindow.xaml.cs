using System.Windows;
using System.Windows.Controls;
using OSiSP.ViewModel;
using AboutApp;

namespace OSiSP.View
{
    public partial class MainWindow : Window
    {
        public ApplicationViewModel ApplicationVm = new ApplicationViewModel();

        public MainWindow()
        {
            InitializeComponent();
            DataContext = ApplicationVm;
        }

        private void Add(object sender, RoutedEventArgs e)
        {
            Add add = new Add();
            add.ShowDialog();
            ApplicationVm.UpdateItemSource();
        }

        private void Update(object sender, RoutedEventArgs e)
        {
            Update update = new Update(ApplicationVm.SelectedTicket);
            update.ShowDialog();
            ApplicationVm.UpdateItemSource();
        }

        private void Year(object sender, RoutedEventArgs e)
        {
            Year year = new Year();
            year.ShowDialog();
        }

        private void Month(object sender, RoutedEventArgs e)
        {
            Month month = new Month();
            month.ShowDialog();
        }

        private void AboutProgram(object sender, RoutedEventArgs e)
        {
            AboutProgram about = new AboutProgram();
            about.Show();
        }

        private void ChangeConditions(object sender, RoutedEventArgs e)
        {
            Extentions extentions = new Extentions();
            extentions.Show();
        }

        private void CheckForUpdates(object sender, RoutedEventArgs e)
        {
            
        }
    }
}
