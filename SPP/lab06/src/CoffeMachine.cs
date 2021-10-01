namespace lab06 {
    abstract class CoffeMachine {
        abstract public Coffe Make();
    }

    class ExpressoMachine : CoffeMachine {
        public override Coffe Make()
        {
            return new Espresso();
        }
    }
    class AmericanoMachine : CoffeMachine {
        public override Coffe Make()
        {
            return new Americano();
        }
    }
    class LatteMachine : CoffeMachine {
        public override Coffe Make()
        {
            return new Latte();
        }
    }
    class CappuccinoMachine : CoffeMachine {
        public override Coffe Make()
        {
            return new Cappuccino();
        }
    }
    class MacchiatoMachine : CoffeMachine {
        public override Coffe Make()
        {
            return new Macchiato();
        }
    }
}