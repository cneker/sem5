using System;
using System.IO;
using static System.Console;

namespace lab03
{
    class Program
    {
        static void Task1() {
            Triangle triangle = new Triangle();
            WriteLine(triangle.ToString());
            Triangle triangle1 = new Triangle(3, 3);
            WriteLine(triangle1.ToString());
            WriteLine(triangle.Equals(triangle1));
            WriteLine("Perimeter - {0}, Square - {1}", triangle1.Perimeter(), triangle1.Square());
        }

        static void Task2(string[] args) {
            if (args.Length == 0)
                First();
            else
                Second(args);
        }

        static void ExecuteCommand(string[] arr, Calculator calculator) {
            try {
                    switch (arr[0]) {
                        case "POP":
                            calculator.Pop();
                            break;
                        case "PUSH":
                            calculator.Push(arr[1]);
                            break;
                        case "+":
                            calculator.Add();
                            break;
                        case "-":
                            calculator.Sub();
                            break;
                        case "*":
                            calculator.Mul();
                            break;
                        case "/":
                            calculator.Div();
                            break;
                        case "SQRT":
                            calculator.Sqrt();
                            break;
                        case "PRINT":
                            calculator.Print();
                            break;
                        case "DEFINE":
                            calculator.Define(arr[1], arr[2]);
                            break;
                        case "#":
                            WriteLine(string.Join(' ', arr[1..]));
                            break;
                        default:
                            throw new UnknownCommandExceprion();
                    }
                }
                catch (Exception ex) {
                    WriteLine($"{ex.GetType()}: {ex.Message}");
                }
        }

        static void First() { //from console
            Calculator calculator = new Calculator();
            Write("Enter command: ");
            string command = ReadLine();
            while (command != "exit") {
                string[] arr = command.Split(' ');
                ExecuteCommand(arr, calculator);
                Write("Enter command: ");
                command = ReadLine();
            }
        }

        static void Second(string[] args) { //from file
            Calculator calculator = new Calculator();
            using StreamReader reader = File.OpenText(Path.Combine(Directory.GetCurrentDirectory(), args[0]));
            string command = string.Empty;
            command = reader.ReadLine();
            while (command != null) {
                string[] arr = command.Split(' ');
                ExecuteCommand(arr, calculator);
                command = reader.ReadLine();
            }
            reader.Close();
        }
        static void Main(string[] args)
        {
            //Task1();
            Task2(args);
        }
    }
}
