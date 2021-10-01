namespace lab06
{
    class Program
    {
        static void Task1() {
            CoffeMachine machine = new ExpressoMachine();
            Coffe coffe = machine.Make();
            coffe.CoffeName();

            machine = new AmericanoMachine();
            coffe = machine.Make();
            coffe.CoffeName();
            
            machine = new LatteMachine();
            coffe = machine.Make();
            coffe.CoffeName();

            machine = new CappuccinoMachine();
            coffe = machine.Make();
            coffe.CoffeName();

            machine = new MacchiatoMachine();
            coffe = machine.Make();
            coffe.CoffeName();
        }

        static void Task3() {
            ArithmeticButton arithmeticButton = new ArithmeticButton("+");
            DigitalButton digitalButton = new DigitalButton("2");
            CustomizeButton customizeButton = new CustomizeButton("-");
            Keyboard keyboard1 = new Keyboard(arithmeticButton);
            Keyboard keyboard2 = new Keyboard(digitalButton);
            Keyboard keyboard3 = new Keyboard(customizeButton);
            keyboard1.Action();
            keyboard2.Action();
            keyboard3.Action();
            keyboard1.ChangeAction();
            keyboard2.ChangeAction();
            keyboard3.ChangeAction();
            keyboard1.Action();
            keyboard2.Action();
            keyboard3.Action();
        }

        static void Task2() {
            DigitalClock digitalClock = new DigitalClock(14, 14);
            digitalClock.ShowTime();
            ClasicClock clasicClock = new ClasicClock(300, 180);
            Clock classicToDigital = new ClassicToDigitalAdapter(clasicClock);
            classicToDigital.ShowTime();
        }

        static void Main(string[] args)
        {
            Task1();
            Task2();
            Task3();
        }
    }
}
