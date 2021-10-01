using System;
namespace lab03 {
    class Triangle {
        public int side { get; set; }
        public int foundation { get; set; }

        public Triangle (int side11 = 2, int side22 = 1) {
            side = side11;
            foundation = side22;
            if (!this.IsExist()) throw new ArgumentException();
        }

        public Triangle (Triangle triangle) {
            side = triangle.side;
            foundation = triangle.foundation;
        }

        public int Perimeter () => side * 2 + foundation;

        public double Square () => 1.0 / 2.0 * (double)foundation * Math.Sqrt(side * side - foundation * foundation / 4);

        public bool IsExist() => side * 2 > foundation;

        public override string ToString()
        {
            return $"Triangle has sides = {side} and foundation = {foundation}";
        }

        public override bool Equals(object obj)
        {
            if (obj is Triangle triangle){
                return side == triangle.side && foundation == triangle.foundation;
            }
            else {
                throw new FormatException();
            }
        }
    }
}