using System;
using System.Collections.Generic;
using static System.Console;

namespace lab05
{
    class Program
    {
        static void Task1() {
            Encyclopedia encyclopedia = new Encyclopedia() {
                Code = 123,
                Author = "Maksim",
                Name = "Sanya solnyshko",
                Year = 2021,
                Publisher = "Minsk",
                ForWhome = "For children"
            };

            Guide guide = new Guide() {
                Code = 124,
                Author = "Bomj",
                Name = "Smisl ponyaten???",
                Year = 2021,
                Publisher = "Brest",
                ForWhat = "For something"
            };

            encyclopedia.ShowInfo();
            Console.WriteLine();
            guide.ShowInfo();
        }
        
        static void Task2() {
            List<Vehicle> vehicles = new List<Vehicle>();
            Auto auto = new Auto() {
                Rentcost = 12.1,
                Rashod = 14
            };
            WriteLine("Auto:");
            WriteLine($"Time - {auto.GetTime(75, 200)}");
            WriteLine($"Cost for cargo - {auto.GetCostCargo(16.78, 200)}");
            WriteLine($"Cost for passangers - {auto.GetCostPass(3, 200)}");

            Bike bike = new Bike() {
                Rentcost = 2.5,
                Wheel = 2
            };
            WriteLine("Bike:");
            WriteLine($"Time - {bike.GetTime(75, 200)}");
            WriteLine($"Cost for cargo - {bike.GetCostCargo(16.78, 200)}");
            WriteLine($"Cost for passangers - {bike.GetCostPass(3, 200)}");

            Cart cart = new Cart() {
                Rentcost = 7.86,
                MaxWeight = 20
            };
            WriteLine("Cart:");
            WriteLine($"Time - {cart.GetTime(75, 200)}");
            WriteLine($"Cost for cargo - {cart.GetCostCargo(16.78, 200)}");
            WriteLine($"Cost for passangers - {cart.GetCostPass(3, 200)}");
            vehicles.Add(auto);
            vehicles.Add(bike);
            vehicles.Add(cart);
        }
        static void Main(string[] args)
        {
            //Task1();
            Task2();
        }
    }
}
