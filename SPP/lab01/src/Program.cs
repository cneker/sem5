using System;
using static System.Console;

namespace lab01
{
    class Program
    {
        public static void Task1() {
            Write("Enter a sequence of elements: ");
            string[] arr = ReadLine().Split(' ');
            try {
                if (arr.Length == 0) throw new ArgumentNullException();
            }
            catch (ArgumentNullException ex) {
                WriteLine("{0}: {1}", ex.GetType(), ex.Message);
            }
            bool isEqual = true;
            foreach (string el in arr) {
                if (el != arr[0]) {
                    isEqual = false;
                }
            }
            WriteLine("Is this sequance equal: {0}", isEqual);
        }

        public static void Task2() {

            double[] Subarray(double[] array, int startIndex, int endIndex) {
                if (startIndex < 0 || endIndex > array.Length - 1) throw new ArgumentOutOfRangeException();
                double[] newArray = array[startIndex..(endIndex + 1)];
                return newArray;
            }

            try {
                Write("Enter an array: ");
                string[] arr = ReadLine().Split(' ');
                Write("Enter start index: ");
                int startIndex = int.Parse(ReadLine());
                Write("Enter last index: ");
                int endIndex = int.Parse(ReadLine());
                double[] array = new double[arr.Length];
                for (int i = 0; i < arr.Length; i++) {
                    array[i] = double.Parse(arr[i]);
                }
                double[] newArray = Subarray(array, startIndex, endIndex);

                Write("Original array: ");
                foreach(double el in array) {
                    Write("{0} ", el);
                }   
                Write("\nNew array: ");
                foreach(double el in newArray) {
                    Write("{0} ", el);
                }
            }
            catch (Exception ex) {
                WriteLine("{0}: {1}", ex.GetType(), ex.Message);
            }
        }

        public static void Taks3() {

            string ShiftRight(string str, int shift) {
                if (str == null) return null;
                if (shift > 0) {
                    int newShift = shift % str.Length;
                    string newstr = str[(str.Length - newShift)..];
                    string addstr = str[..(str.Length - newShift)];
                    return newstr + addstr;
                }
                else {
                    int newShift = (str.Length - Math.Abs(shift)) % str.Length;
                    string newstr = str[(str.Length - newShift)..];
                    string addstr = str[..(str.Length - newShift)];
                    return newstr + addstr;
                }
            }
            try {
                Write("Enter string: ");
                string str = ReadLine();
                Write("Enter shift: ");
                int shift = int.Parse(ReadLine());
                WriteLine("Before: {0}", str);
                WriteLine("After: {0}", ShiftRight(str, shift));
            }
            catch (FormatException ex) {
                WriteLine("{0}: {1}", ex.GetType(), ex.Message);
            }
            
        }

        static void Main(string[] args)
        {
            //Task1();
            //Task2();
            Taks3();
        }
    }
}
