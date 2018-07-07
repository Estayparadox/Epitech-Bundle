using System;
using System.Net;
using System.Net.Sockets;

namespace Client
{
    /// <summary>
    /// Client handler.
    /// </summary>
    public class ClientHandler
    {
        private static string address;
        private static int port;

        /// <summary>
        /// The entry point of the program, where the program control starts and ends.
        /// </summary>
        /// <returns>The exit code that is given to the operating system after the program ends.</returns>
        public static int Main(string[] args)
        {
            try
            {
                try
                {
                    IPAddress.Parse("127.0.0.1");
                    address = "127.0.0.1";
                    port = Int32.Parse("8080");
                }
                catch
                {
                    Console.Error.WriteLine("IP Adress error.");
                    return 84;
                }
                Server.UserManager server = new Server.UserManager((new TcpClient(address, port)).Client);
                Console.WriteLine("Hi ! You're joining the DOT_cardGames on adress " + address + ":" + port + ".\nWaiting for other players...\nWrite 'exit' to leave.");
                while (true)
                {
                    string message = server.GetReader().ReadLine();
                    if (message.Equals("alive"))
                        continue;
                    bool answer = (message != "" && message[0] == 'W');
                    Console.WriteLine(message);
                    if (answer)
                    {
                        string input = Console.ReadLine();
                        if (input == "exit")
                        {
                            Console.WriteLine("\nBye ! Thanks for playing DOT_cardGames !");
                            break;
                        }
                        server.GetWriter().WriteLine(input);
                    }
                }
            }
            catch (SocketException)
            {
                Console.Error.WriteLine("Socket error.\nNo server found...");
                return 84;
            }
            catch (Exception)
            {
                Console.Error.WriteLine("Server disconnected...");
                return 84;
            }
            return 0;
        }
    }
}
