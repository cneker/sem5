namespace lab05 {
    abstract class Vehicle {
        public double Rentcost { get; set; }
        public virtual double GetTime(double speed, double distance) => distance / speed;
        public virtual double GetCostPass(double count, double distance) => count * 75.0 / distance * Rentcost;
        public virtual double GetCostCargo(double weight, double distance) => weight / distance * Rentcost;
    }

    class Auto : Vehicle {
        public double Rashod { get; set; }
        public override double GetCostPass(double count, double distance)
        {
            if (count > 4) count = 4;
            return base.GetCostPass(count, distance)  + Rashod * 2.07;
        }
        public override double GetCostCargo(double weight, double distance)
        {
            return base.GetCostCargo(weight, distance) + Rashod * 2.07;
        }
    }

    class Bike : Vehicle {
        public int Wheel { get; set; }
        public override double GetCostPass(double count, double distance)
        {
            if (count > 2) count = 2;
            return base.GetCostPass(count, distance) + Wheel;
        }
    }

    class Cart : Vehicle {
        public double MaxWeight { get; set; }
        public override double GetCostCargo(double weight, double distance)
        {
            if (weight > MaxWeight) weight = MaxWeight;
            return base.GetCostCargo(weight, distance);
        }
    }
}