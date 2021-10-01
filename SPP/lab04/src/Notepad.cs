using System;
using System.Collections.Generic;

namespace lab04 {
    class Notepad {

        private Dictionary<DateTime, Record> _dates = new Dictionary<DateTime, Record>();

        public void AddRecord(DateTime dateTime, string rec) {
            if (!_dates.ContainsKey(dateTime)) {
                _dates.Add(dateTime, new Record());
            }
            var res = _dates[dateTime];
            res.AddRec(rec);
            _dates[dateTime] = res;
        }

        public void ShowRecords(DateTime dateTime) {
            if (_dates.TryGetValue(dateTime, out Record record)) {
                foreach (string rec in record.rec) {
                    Console.WriteLine (rec);
                }
            }
        }

        public class Record {
            public List<string> rec = new List<string>();
            public void AddRec(string r) {
                rec.Add(r);
            }
        }
    }
}