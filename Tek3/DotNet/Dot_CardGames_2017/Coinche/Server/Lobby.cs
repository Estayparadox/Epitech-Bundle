using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;

namespace Server
{
    /// <summary>
    /// Lobby.
    /// </summary>
    public class Lobby
    {
        private volatile List<UserManager> waiters = new List<UserManager>();
        private List<Thread> threads = new List<Thread>();

        /// <summary>
        /// Launch the game.
        /// </summary>
        /// <returns>The launching.</returns>
        private List<UserManager> GameLaunching()
        {
            waiters = GameManager.SendNetworks(waiters, "alive");
            List<UserManager> temp = new List<UserManager>();
            while (temp.Count != 4)
            {
                if (waiters.Count == 0)
                    return temp;
                if (waiters.First().IsAlive())
                {
                    temp.Add(waiters.First());
                    waiters.Remove(waiters.First());
                }
                else
                {
                    waiters.Remove(waiters.First());
                }
            }
            return temp;
        }

        /// <summary>
        /// Run this instance.
        /// </summary>
        public void Run()
        {
            int gamesId = 0;

            do
            {
                while (!Console.KeyAvailable)
                {
                    if (waiters.Count < 4)
                    {
                        waiters = GameManager.SendNetworks(waiters, "alive");
                        UserManager user = GameManager.AddUser();
                        if (user != null)
                            waiters.Add(user);
                        else
                        {
                            Thread.Sleep(100);
                            continue;
                        }
                        waiters = GameManager.SendNetworks(waiters, "Someone has joined the game.");
                    }
                    if (waiters.Count >= 4)
                    {
                        List<UserManager> temp = GameLaunching();
                        if (temp.Count != 4)
                        {
                            temp = GameManager.SendNetworks(temp, "Someone has left the game...");
                            foreach (UserManager n in temp)
                            {
                                if (n.IsAlive())
                                    waiters.Add(n);
                            }
                            temp.Clear();
                            continue;
                        }
                        Game game = null;
                        try
                        {
                            gamesId += 1;
                            game = new Game(gamesId, temp);
                        }
                        catch (Leave)
                        {
                            temp = GameManager.SendNetworks(temp, "Someone has left the game...");
                            foreach (UserManager n in temp)
                            {
                                if (n.IsAlive())
                                    waiters.Add(n);
                            }
                            temp.Clear();
                            continue;
                        }
                        Thread thread = new Thread(
                            () =>
                            {
                                try
                                {
                                    temp = GameManager.SendNetworks(temp, "The game is staring !");
                                    try
                                    {
                                        temp = game.runGame();
                                    }
                                    catch (Leave)
                                    {
                                        temp = GameManager.SendNetworks(temp, "Someone has left the game...");
                                    }
                                    if (temp.Count == 0)
                                        Console.WriteLine("Player error...");
                                    else if (temp.Count == 4)
                                        temp = GameManager.SendNetworks(temp, "\n");
                                    else
                                        temp = GameManager.SendNetworks(temp,
                                            "Someone has left the game... Back to the lobby!");
                                    foreach (UserManager n in temp)
                                    {
                                        if (n.IsAlive())
                                            waiters.Add(n);
                                    }
                                    temp.Clear();
                                }
                                catch (Exception)
                                {
                                    Console.Error.WriteLine("Thread error...");
                                }
                            }
                        );
                        thread.Start();
                        threads.Add(thread);
                    }
                }
            } while (Console.ReadKey(true).Key != ConsoleKey.Escape);
            try
            {
                List<Thread> threads2 = threads;
                foreach (Thread t in threads2)
                {
                    if (t.IsAlive)
                        t.Interrupt();
                }
            }
            catch (Exception)
            {
                Console.WriteLine("Readkey error...");
            }
        }
    }
}