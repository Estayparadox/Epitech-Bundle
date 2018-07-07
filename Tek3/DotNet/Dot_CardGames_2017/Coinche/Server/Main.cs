using System;
using System.Net;

namespace Server
{
    /// <summary>
    /// Server handler.
    /// </summary>
    public class ServerHandler
    {
        private static string address;
        private static int port;

        /// <summary>
        /// The entry point of the program, where the program control starts and ends.
        /// </summary>
        /// <returns>The exit code that is given to the operating system after the program ends.</returns>
        public static int Main(string[] args)
        {
            GameManager manager;
            try
            {
                IPAddress.Parse("127.0.0.1");
                address = "127.0.0.1";
                port = Int32.Parse("8080");
            }
            catch
            {
                Console.Error.WriteLine("IP adress error.");
                return 84;
            }
            try
            {
                Console.WriteLine("Hi ! DOT_cardGames is running on address " + address + ":" + port + ".\nLauching lobby...");
                Console.WriteLine();
                manager = new GameManager(address, port);
                Lobby lobby = new Lobby();
                lobby.Run();
                Console.WriteLine("Bye ! DOT_cardGames is shutting down. Thanks for playing.");
                return 0;
            }
            catch (Exception e)
            {   
                Console.Error.WriteLine("Server error... " + e.Message);
                return 84;
            }
        }
    }
}