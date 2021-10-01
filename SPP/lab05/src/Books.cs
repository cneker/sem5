using System;

namespace lab05 {
    abstract class Book {
        public int Code { get; set; }
        public string Author { get; set; }
        public string Name { get; set; }
        public int Year { get; set; }
        public string Publisher { get; set; }

        public virtual void ShowInfo() {
            Console.WriteLine(Code);
            Console.WriteLine(Author);
            Console.WriteLine(Name);
            Console.WriteLine(Year);
            Console.WriteLine(Publisher);
        }
    }

    class Encyclopedia : Book {
        public string ForWhome { get; set; }
        public override void ShowInfo()
        {
            base.ShowInfo();
            Console.WriteLine(ForWhome);
        }
    }

    class Guide : Book {
        public string ForWhat { get; set; }
        public override void ShowInfo()
        {
            base.ShowInfo();
            Console.WriteLine(ForWhat);
        }
    }
}