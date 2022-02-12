using System;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading;
using System.Windows;
using System.Windows.Media;
using OSiSP.Command;
using OSiSP.Model;

namespace OSiSP.ViewModel
{
    public class ApplicationViewModel : INotifyPropertyChanged
    {
        private static int _port = 8005;
        private static string _address = "127.0.0.1";
        private static Socket _socket;
        private Extensions _extensions;

        private TicketModel _selectedTicket;

        private ObservableCollection<TicketModel> _tickets;
        public TicketContext Context { get; set; }

        public ObservableCollection<TicketModel> Tickets
        {
            get => _tickets;
            set
            {
                _tickets = value;
                OnPropertyChanged();
            }
        }

        public TicketModel SelectedTicket
        {
            get => _selectedTicket;
            set
            {
                _selectedTicket = value;
                OnPropertyChanged();
            }
        }

        #region AddCommand
        private RelayCommand _addCommand;

        public RelayCommand AddCommand
        {
            get
            {
                return _addCommand ??= new RelayCommand(obj =>
                {
                    if (obj is TicketModel ticket)
                    {
                        using (Context = new TicketContext())
                        {
                            Context.Tickets.Add(ticket);
                            Context.SaveChanges();
                        }
                    }
                });
            }
        }
        #endregion

        #region UpdateCommand
        private RelayCommand _updateCommand;

        public RelayCommand UpdateCommand
        {
            get
            {
                return _updateCommand ??= new RelayCommand(obj =>
                {
                    if (obj is TicketModel ticket)
                    {
                        using (Context = new TicketContext())
                        {
                            Context.Tickets.Update(ticket);
                            Context.SaveChanges();
                        }
                    }
                });
            }
        }
        #endregion

        private RelayCommand _checkFofUpdates;

        public RelayCommand CheckForUpdates
        {
            get
            {
                return _checkFofUpdates ??= new RelayCommand(obj =>
                {
                    try
                    {
                        IPEndPoint ipPoint = new IPEndPoint(IPAddress.Parse(_address), _port);
                        _socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                        _socket.Connect(ipPoint);

                        string version = GetCurrentVersion();
                        SendMessangeToServer(version);
                        GetResponseFromServer(out StringBuilder builder);

                        MessageBox.Show(builder.ToString());

                        _socket.Shutdown(SocketShutdown.Both);
                        _socket.Close();
                    }
                    catch (Exception ex)
                    {
                        Debug.WriteLine(ex.Message);
                    }
                });
            }
        }

        #region Constructors
        public ApplicationViewModel()
        {
            using (Context = new TicketContext())
            {
                Tickets = new ObservableCollection<TicketModel>(Context.Tickets);
            }

            SetExtensions();
        }

        public ApplicationViewModel(string param)
        {
            using (Context = new TicketContext())
            {
                Tickets = new ObservableCollection<TicketModel>(Context.Tickets);
            }

            var date = DateTime.Now.Day.ToString() + "/"
                                                    + DateTime.Now.Month.ToString() + "/"
                                                    + DateTime.Now.Year.ToString();

            SelectedTicket = new TicketModel()
            {
                Number = 0,
                Sum = 0,
                Date = date
            };
            SetExtensions();
        }
        #endregion

        public void UpdateItemSource()
        {
            using (Context = new TicketContext())
            {
                Tickets = new ObservableCollection<TicketModel>(Context.Tickets);
            }
        }

        private void SetExtensions()
        {
            if (Application.Current.MainWindow != null)
            {
                _extensions = new Extensions();
                foreach (Window currentWindow in Application.Current.Windows)
                {
                    currentWindow.FontSize = _extensions.FontSize;
                    currentWindow.FontFamily = new FontFamily(_extensions.FontFamily);
                    currentWindow.FontWeight = _extensions.Bold ? FontWeights.Bold : FontWeights.Normal;
                }
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;
        public void OnPropertyChanged([CallerMemberName] string prop = "")
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(prop));
        }

        private static string GetCurrentVersion()
        {
            using var streamReader = new StreamReader("../../../version.txt");
            string version = streamReader.ReadLine();
            streamReader.Close();
            return version;
        }

        private static void SendMessangeToServer(string message)
        {
            byte[] data = Encoding.Unicode.GetBytes(message);
            _socket.Send(data);
        }

        private static void GetResponseFromServer(out StringBuilder builder)
        {
            builder = new StringBuilder();
            var data = new byte[256];
            int bytes = 0;
            Thread.Sleep(2000);
            do
            {
                bytes = _socket.Receive(data, data.Length, 0);
                builder.Append(Encoding.Unicode.GetString(data, 0, bytes));
            } while (_socket.Available > 0);
        }
    }
}