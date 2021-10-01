using System.Collections.Generic;
using System;
namespace lab03 {
    class Calculator {
        private Stack<double> _values;
        private Dictionary<string, double> _definitions;

        public Calculator() {
            _values = new Stack<double>();
            _definitions = new Dictionary<string, double>();
        }

        public double Pop() {
            if (_values.TryPop(out double result)) {
                return result;
            }
            else {
                throw new EmptyException();
            }
        }

        public void Push(string a) {
            if (_definitions.ContainsKey(a)) {
                _values.Push(_definitions.GetValueOrDefault(a));
            }
            else if (double.TryParse(a, out double b)) {
                _values.Push(b);
            }
            else {
                throw new DefineException();
            }
        }

        public void Add () {
            if (!ContainTwo()) throw new EmptyException();
            double a = Pop();
            double b = Pop();
            _values.Push(a + b);
        }

        public void Sub() {
            if (!ContainTwo()) throw new EmptyException();
            double a = Pop();
            double b = Pop();
            _values.Push(a - b);
        }

        public void Mul() {
            if (!ContainTwo()) throw new EmptyException();
            double a = Pop();
            double b = Pop();
            _values.Push(a * b);
        }

        public void Div() {
            if (!ContainTwo()) throw new EmptyException();
            double a = Pop();
            double b = Pop();
            _values.Push(a / b);
        }

        public void Sqrt() {
            double a = Pop();
            _values.Push(Math.Sqrt(a));
        }

        public void Print() {
            if (_values.TryPeek(out double a))
                Console.WriteLine(a);
            else throw new EmptyException();
        }

        public void Define(string a, string b) {
            if (!_definitions.TryAdd(a, double.Parse(b))) {
                throw new DefineExistExceprion();
            }
        }

        private bool ContainTwo() => _values.Count >= 2;
    }
}