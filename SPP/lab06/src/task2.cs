using System;

namespace lab06 {
    interface Clock {
        public void ShowTime();
    }
    class DigitalClock : Clock {
        private int _hour;
        private int _minutes;
        public DigitalClock(int hour, int minutes) {
            _hour = hour;
            _minutes = minutes;
        }
        public void ShowTime() {
            Console.WriteLine($"{_hour}:{_minutes}");
        }
    }

    class ClasicClock {
        public int HourDegrees { get; }
        public int MinutesDegrees { get; }
        public ClasicClock(int hourDegrees, int minutesDegrees) {
            HourDegrees = hourDegrees;
            MinutesDegrees = minutesDegrees;
        }
    }

    class ClassicToDigitalAdapter : Clock {
        private ClasicClock _classic;
        public ClassicToDigitalAdapter(ClasicClock classic) {
            _classic = classic;
        }
        public void ShowTime() {
            if (_classic.HourDegrees >= 30 && _classic.MinutesDegrees != 360) {
                Console.WriteLine($"{_classic.HourDegrees / 30}:{_classic.MinutesDegrees / 6}");
            } else if (_classic.MinutesDegrees == 360) {
                Console.WriteLine($"{_classic.HourDegrees / 30 + 1}:{0}");
            } else {
                Console.WriteLine($"{12}:{_classic.MinutesDegrees / 6}");
            }
        }
    }
}