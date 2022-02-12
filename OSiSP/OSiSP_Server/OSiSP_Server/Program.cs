using System;
using System.IO;
using System.Text;
using System.Net;
using System.Net.Sockets;

namespace OSiSP_Server
{
    class Program
    {
        static int port = 8005;
        static void Main(string[] args)
        {
            string version = GetCurrentVersion();


            IPEndPoint ipPoint = new IPEndPoint(IPAddress.Parse("127.0.0.1"), port);

            Socket listenSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            try
            {
                listenSocket.Bind(ipPoint);
                listenSocket.Listen(10);
                
                Console.WriteLine("Сервер запущен. Ожидайте подключений...");
                
                while (true)
                {
                    Socket handler = listenSocket.Accept();
                    StringBuilder stringBuilder = new StringBuilder();
                    int bytes = 0;
                    byte[] data = new byte[256];
                    string message;
                    do
                    {
                        bytes = handler.Receive(data);
                        stringBuilder.Append(Encoding.Unicode.GetString(data, 0, bytes));
                    } while (handler.Available > 0);

                    if (stringBuilder.ToString().Equals(version))
                    {
                        Console.WriteLine(DateTime.Now.ToShortTimeString() + ": " + "Текущая версия");
                        message = "Текущая версия";
                        data = Encoding.Unicode.GetBytes(message);
                        handler.Send(data);
                    }
                    else
                    {
                        Console.WriteLine(DateTime.Now.ToShortTimeString() + ": " + "Новая версия: обновление приложения");

                        string sourse = Path.Combine("../../../", "version.txt");
                        string destination = Path.Combine("../../../../../OSiSP/OSiSP/", "version.txt");
                        if (File.Exists(destination))
                        {
                            File.Delete(destination);
                        }
                        File.Copy(sourse, destination);

                        sourse = Path.Combine("../../../", "AboutApp.dll");
                        destination = Path.Combine("../../../../../OSiSP/OSiSP/bin/Debug/netcoreapp3.1/", "AboutApp.dll");
                        if (File.Exists(destination))
                        {
                            File.Delete(destination);
                        }
                        File.Copy(sourse, destination);

                        message = $"Новая версия {version} установлена!";
                        data = Encoding.Unicode.GetBytes(message);
                        handler.Send(data);

                        handler.Shutdown(SocketShutdown.Both);
                        handler.Close();
                    }

                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }

        static string GetCurrentVersion()
        {
            using var streamReader = new StreamReader("../../../version.txt");
            string version = streamReader.ReadLine();
            streamReader.Close();
            return version;
        }
    }
}
