using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;

namespace Server
{
    /// <summary>
    /// Game manager.
    /// </summary>
    public class GameManager
    {
        private static TcpListener myListner;

        /// <summary>
        /// Initializes a new instance of the <see cref="T:Server.GameManager"/> class.
        /// </summary>
        /// <param name="address">Address.</param>
        /// <param name="port">Port.</param>
        public GameManager(string address, int port)
        {
            myListner = new TcpListener(IPAddress.Parse(address), port);
            myListner.Start();
        }

        /// <summary>
        /// Sends a private message.
        /// </summary>
        /// <param name="player">Player.</param>
        /// <param name="message">Message.</param>
        public static void SendPrivate(Player player, string message)
        {
            try
            {
                player.getUserManager().GetWriter().WriteLine(message);
            }
            catch (Exception)
            {
                Leave e = new Leave("Someone has left the game...");
                throw e;
            }
        }

        /// <summary>
        /// Send a message to all players.
        /// </summary>
        /// <param name="players">Players.</param>
        /// <param name="message">Message.</param>
        public static void SendAll(List<Player> players, string message)
        {
            try
            {
                foreach (Player p in players)
                {
                    p.getUserManager().GetWriter().WriteLine(message);
                }
                Console.WriteLine("To all: " + message);
            }
            catch (Exception)
            {
                Leave e = new Leave("Someone has left the game...");
                throw e;
            }
        }

        /// <summary>
        /// Adds the user.
        /// </summary>
        /// <returns>The user.</returns>
        public static UserManager AddUser()
        {
            if (myListner.Pending())
                return new UserManager(myListner.AcceptSocket());
            return null;
        }

        /// <summary>
        /// Sends the networks.
        /// </summary>
        /// <returns>The networks.</returns>
        /// <param name="users">Users.</param>
        /// <param name="message">Message.</param>
        public static List<UserManager> SendNetworks(List<UserManager> users, string message)
        {
            List<UserManager> usersCopy = users.ToList();

            foreach (UserManager n in usersCopy)
            {
                try
                {
                    n.GetWriter().WriteLine(message);
                    if (message != "alive")
                        Console.WriteLine("Sending message to user: " + message);
                }
                catch (Exception)
                {

                    users.Remove(n);
                }
            }
            return users;
        }

        /// <summary>
        /// Gets my listener.
        /// </summary>
        /// <returns>The my listener.</returns>
        public TcpListener GetMyListener()
        {
            return myListner;
        }
    }
}