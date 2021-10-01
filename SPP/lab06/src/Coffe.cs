using static System.Console;

namespace lab06 {
    abstract class Coffe {
        public abstract void CoffeName();
    }

    class Espresso : Coffe {
        public override void CoffeName()
        {
            WriteLine("This is espresso");
        }
    }

    class Americano : Coffe {
        public override void CoffeName()
        {
            WriteLine("This is americano");
        }
    }

    class Latte : Coffe {
        public override void CoffeName()
        {
            WriteLine("This is latte");
        }
    }

    class Cappuccino : Coffe {
        public override void CoffeName()
        {
            WriteLine("This is cappuccino");
        }
    }
    
    class Macchiato : Coffe {
        public override void CoffeName()
        {
            WriteLine("This is macchiato");
        }
    }
}