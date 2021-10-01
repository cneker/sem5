using System;
using System.IO;
using System.Collections.Generic;
using static System.Console;

namespace lab02
{
    class Program
    {
        static void Task1() {
            string path = Path.Combine(Directory.GetCurrentDirectory(), "file.txt");
            string path1 = Path.Combine(Directory.GetCurrentDirectory(), "file1.txt");
            if (File.Exists(path)) {

                using var reader = File.OpenText(path);
                using var writer = File.CreateText(path1);
                
                string line = reader.ReadLine();
                var set = new HashSet<string>();

                do {
                    string[] split = line.Split(' ', StringSplitOptions.RemoveEmptyEntries);
                    foreach (string word in split) {
                        if (!set.Contains(word)) {
                            set.Add(word);
                            writer.Write(word + " ");
                            Write(word + " ");
                        }
                    }
                    if (split.Length != 0) {
                        writer.Write("\n");
                        WriteLine();
                    }
                    line = reader.ReadLine();
                } while (line != null);

                reader.Close();
                writer.Close();
            }

        }

        static void Task2(string[] arg) {
            if (arg.Length == 0) {
                throw new ArgumentException();
            }
            string path = string.Empty;
            string fileInfo = string.Empty;
            string read = string.Empty;
            string[] args = arg[0].Split(' ');
            for (int i = 1; i < args.Length; i++) {
                if (args[i] == ">") {
                    
                    path = Path.Combine(Directory.GetCurrentDirectory(), args[++i]);
                    using var writer = File.CreateText(path);
                    writer.Write(fileInfo);
                    writer.Close();
                    
                    continue;
                }
                if (args[i] == "-") {
                    read = ReadLine();
                    fileInfo += read + "\n";
                    Console.WriteLine(read);
                    continue;
                }
                else {
                    path = Path.Combine(Directory.GetCurrentDirectory(), args[i]);
                    using var reader = File.OpenText(path);
                    read = reader.ReadToEnd();
                    fileInfo += read;
                    Write(read);
                    reader.Close();
                }
            }
        }

        static void Main(string[] args)
        {
            //Task1();
            Task2(args);
        }
    }
}
