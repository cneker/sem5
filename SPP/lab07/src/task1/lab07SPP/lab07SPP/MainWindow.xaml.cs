using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Shapes;

namespace lab07SPP
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void ButtonBase_OnClick(object sender, RoutedEventArgs e)
        {
            var element = MyGrid.Children
                .OfType<Shape>()
                .FirstOrDefault(e => e.Name == "triangle");
            MyGrid.Children.Remove(element);
            element = MyGrid.Children
                .OfType<Shape>()
                .FirstOrDefault(e => e.Name == "point");
            MyGrid.Children.Remove(element);

            Polygon trianglePolygon = new Polygon()
            {
                Name = "triangle"
            };
            Polygon point = new Polygon()
            {
                Name = "point"
            };

            double[] x = {double.Parse(X0.Text), double.Parse(X1.Text), double.Parse(X2.Text), double.Parse(X3.Text)};
            double[] y = { double.Parse(Y0.Text), double.Parse(Y1.Text), double.Parse(Y2.Text), double.Parse(Y3.Text) };

            Point aPoint = new Point(x[1], y[1]);
            Point bPoint = new Point(x[2], y[2]);
            Point cPoint = new Point(x[3], y[3]);

            Point dPoint = new Point(x[0], y[0]);
            Point dPoint1 = new Point(x[0] + 1, y[0]);
            Point dPoint2 = new Point(x[0] + 1, y[0] + 1);
            Point dPoint3 = new Point(x[0], y[0] + 1);

            trianglePolygon.Points.Add(aPoint);
            trianglePolygon.Points.Add(bPoint);
            trianglePolygon.Points.Add(cPoint);
            trianglePolygon.Stroke = Brushes.Red;

            point.Points.Add(dPoint);
            point.Points.Add(dPoint1);
            point.Points.Add(dPoint2);
            point.Points.Add(dPoint3);
            point.Stroke = Brushes.Black;

            MyGrid.Children.Add(trianglePolygon);
            MyGrid.Children.Add(point);
            Grid.SetColumn(trianglePolygon, 2);
            Grid.SetColumn(point, 2);

            Result.Text = IsInside(x, y) ? "Inside" : "Outside";

        }

        private static bool IsInside(double[] x, double[] y)
        {
            double[] f = new double[3];
            f[0] = (x[1] - x[0]) * (y[2] - y[1]) - (x[2] - x[1]) * (y[1] - y[0]);
            f[1] = (x[2] - x[0]) * (y[3] - y[2]) - (x[3] - x[2]) * (y[2] - y[0]);
            f[2] = (x[3] - x[0]) * (y[1] - y[3]) - (x[1] - x[3]) * (y[3] - y[0]);

            if ((f[0] >= 0 && f[1] >= 0 && f[2] >= 0) || (f[0] <= 0 && f[1] <= 0 && f[2] <= 0))
            {
                return true;
            }

            return false;
        }
    }
}
