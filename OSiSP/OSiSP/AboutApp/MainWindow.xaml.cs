using System.IO;
using System.Windows;
using System.Windows.Media;

namespace AboutApp
{
    public partial class AboutProgram : Window
    {
        public AboutProgram()
        {
            InitializeComponent();
            var verison = GetVersion();
            About.Text = "This program was written by\n" +
                         "Андрейчиков Даниил\n" +
                         "ПО - 4 3 курс\n" +
                         $"version: {verison}";
        }

        public string GetVersion()
        {
            using var streamReader = new StreamReader("../../../version.txt");
            string version = streamReader.ReadLine();
            streamReader.Close();
            return version;
        } 
    }
}
