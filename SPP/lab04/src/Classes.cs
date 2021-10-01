using System;

namespace lab04 {
    class Strings {
        private string str;

        public void AddWord(Word word) {
            str += word.ToString();
        }

        public void AddCharacter(Character character) {
            str += character.ToString();
        }

        public void Show() {
            Console.WriteLine(str);
        }
    }

    class Word {
        public string word { get; set; }
        public Word(string wrd) {
            word = wrd;
        }
        public override string ToString() {
            return word.ToString();
        }
    }

    class Character {
        public char character { get; set; }
        public Character(char ch) {
            character = ch;
        }
        public override string ToString()
        {
            return character.ToString();
        }
    }
}