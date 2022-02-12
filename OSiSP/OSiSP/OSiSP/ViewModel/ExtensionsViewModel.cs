using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Windows;
using System.Windows.Media;
using OSiSP.Command;
using OSiSP.Model;

namespace OSiSP.ViewModel
{
    class ExtensionsViewModel : INotifyPropertyChanged
    {
        private Extensions _extensions;

        public Extensions Extensions
        {
            get => _extensions;
            set
            {
                _extensions = value;
                OnPropertyChanged();
            }
        }

        private RelayCommand _saveChangesCommand;

        public RelayCommand SaveCommand
        {
            get
            {
                return _saveChangesCommand ??= new RelayCommand(obj =>
                {
                    foreach (Window currentWindow in Application.Current.Windows)
                    {
                        currentWindow.FontSize = Extensions.FontSize;
                        currentWindow.FontFamily = new FontFamily(Extensions.FontFamily);
                        currentWindow.FontWeight = Extensions.Bold ? FontWeights.Bold : FontWeights.Normal;
                    }
                });
            } 
        }

        public ExtensionsViewModel()
        {
            Extensions = new Extensions();
        }

        public event PropertyChangedEventHandler PropertyChanged;
        public void OnPropertyChanged([CallerMemberName] string prop = "") =>
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(prop));
    }
}
