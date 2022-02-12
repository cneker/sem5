using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Windows;

namespace OSiSP.Model
{
    class Extensions : INotifyPropertyChanged
    {
        private double _fontSize;
        private string _fontFamily;
        private bool _bold;

        public double FontSize
        {
            get => _fontSize;
            set
            {
                _fontSize = value;
                OnPropertyChanged();
            }
        }

        public bool Bold
        {
            get => _bold;
            set
            {
                _bold = value;
                OnPropertyChanged();
            }
        }

        public string FontFamily
        {
            get => _fontFamily;
            set
            {
                _fontFamily = value;
                OnPropertyChanged();
            }
        }

        public Extensions()
        {
            if (Application.Current.MainWindow != null)
            {
                FontSize = Application.Current.MainWindow.FontSize;
                FontFamily = Application.Current.MainWindow.FontFamily.Source;
                Bold = Application.Current.MainWindow.FontWeight == FontWeights.Bold;
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;
        public void OnPropertyChanged([CallerMemberName] string prop = "") =>
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(prop));
    }
}
