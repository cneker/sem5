using System;

namespace lab04
{
    class Program
    {
        static void Task1() {
            Notepad notepad = new Notepad();
            notepad.AddRecord(new DateTime(1999, 11, 12), "one more time");
            notepad.AddRecord(new DateTime(1999, 11, 12), "give me your money");
            notepad.ShowRecords(new DateTime(1999, 11, 12));
            notepad.AddRecord(new DateTime(2000, 11, 12), "siiiiiiiiiiii");
            notepad.ShowRecords(new DateTime(2000, 11, 12));
            notepad.AddRecord(new DateTime(1998, 11, 12), "kill me please");
            notepad.AddRecord(new DateTime(1999, 11, 12), "chiki briki");
            notepad.ShowRecords(new DateTime(1999, 11, 12));
        }

        static void Task2() {
            Strings strings = new Strings();
            Word word = new Word("ajsdbhasbdsabsaduabs");
            Word word1 = new Word("jdngkdfmgkmdgkmdfg");
            Character character = new Character(' ');
            strings.AddWord(word);
            strings.Show();
            strings.AddCharacter(character);
            strings.AddWord(word1);
            strings.Show();
        }
        static void Task3() {
            Teacher teacher1 = new Teacher("Name1");
            Teacher teacher2 = new Teacher("Name2");
            teacher1.AddCourse("PHP");
            teacher1.AddCourse("Scala");
            teacher2.AddCourse("Scala");
            Student student1 = new Student("Danya");
            Student student2 = new Student("Sanya");
            student1.EnterToCourse(teacher1, "PHP");
            student2.EnterToCourse(teacher1, "PHP");
            student2.EnterToCourse(teacher2, "Scala");
            teacher1.SetMark(9, student1, "PHP");
            teacher1.SetMark(7, student2, "PHP");
            teacher2.SetMark(10, student2, "Scala");
            Archive.ShowMarks();
        }

        static void Main(string[] args)
        {
            //Task1();
            //Task2();
            Task3();
        }
    }
}
