using static System.Console;

namespace lab06 {
    interface Button {
        public void Action();
    }

    class DigitalButton : Button {
        private string _symbol;
        public DigitalButton(string symbol) {
            _symbol = symbol;
        }
        public void Action() {
            WriteLine($"Enter this: {_symbol}");
        }
    }

    class ArithmeticButton : Button {
        private string _symbol;
        public ArithmeticButton(string symbol) {
            _symbol = symbol;
        }
        public void Action() {
            WriteLine($"Doing this: {_symbol}");
        }
    }

    class CustomizeButton : Button {
        private string _symbol;
        public CustomizeButton(string symbol) {
            _symbol = symbol;
        }
        public void Action() {
            WriteLine($"Enter(doing) this: {_symbol}");
        }
    }

    class Keyboard {
        private Button _button;
        public Keyboard(Button button) {
            _button = button;
        }
        public void Action() {
            _button.Action();
        }
        public void ChangeAction() {
            if (_button is CustomizeButton) {
                var btn = new CustomizeButton("r");
                _button = btn;
            }
        }
        public bool IsCustomized() {
            return _button is CustomizeButton;
        }
    }
}