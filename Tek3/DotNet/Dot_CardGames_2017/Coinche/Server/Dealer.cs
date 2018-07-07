using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;

namespace Server
{
    /// <summary>
    /// Game.
    /// </summary>
    public class Game
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="T:Server.Game"/> class.
        /// </summary>
        /// <param name="id">Identifier.</param>
        /// <param name="users">Users.</param>
        public Game(int id, List<UserManager> users)
        {
            this.id = id;
            deck = new List<Card>();
            players = new List<Player>();
            foreach (UserManager n in users)
            {
                players.Add(new Player(players.Count, (players.Count % 2 == 0 ? Team.FIRST : Team.SECOND), n));
                GameManager.SendPrivate(players.Last(), "You are player " + (players.Count - 1) + " and you are in the " + ((players.Count - 1) % 2 == 0 ? Team.FIRST : Team.SECOND) + " team.");
                GameManager.SendAll(players, "Player " + (players.Count - 1) + " is joining in the " + ((players.Count - 1) % 2 == 0 ? Team.FIRST : Team.SECOND) + " team.");
            }
            contract = new Contract();
        }

        private List<Card> deck;
        private List<Player> players;
        private Contract contract;
        private readonly int id;

        /// <summary>
        /// Gets the identifier.
        /// </summary>
        /// <returns>The identifier.</returns>
        public int GetId()
        {
            return id;
        }

        /// <summary>
        /// Gets the players.
        /// </summary>
        /// <returns>The players.</returns>
        public List<Player> getPlayers()
        {
            return players;
        }

        /// <summary>
        /// Adds the player.
        /// </summary>
        /// <param name="player">Player.</param>
        public void addPlayer(Player player)
        {
            players.Add(player);
        }

        /// <summary>
        /// Runs the game.
        /// </summary>
        /// <returns>The game.</returns>
        public List<UserManager> runGame()
        {
            List<UserManager> res = new List<UserManager>();
            try
            {
                distribution();
                playTheGame();
                countScore();
            }
            catch (Leave e)
            {
                Console.Error.WriteLine(e.Message);
            }
            finally
            {
                foreach (Player p in players)
                {
                    if (p.getUserManager().IsAlive())
                        res.Add(p.getUserManager());
                }
            }
            return res;
        }

        /// <summary>
        /// Distribution this instance.
        /// </summary>
        private void distribution()
        {
            foreach (Value i in Enum.GetValues(typeof(Value)))
            {
                foreach (Color j in Enum.GetValues(typeof(Color)))
                {
                    deck.Add(new Card(j, i));
                }
            }
            Random r = new Random();
            foreach (Player player in players)
            {
                for (int a = 0; a < 8; a += 1)
                {
                    int x = r.Next(0, deck.Count);
                    player.addCard(deck.ElementAt(x));
                    deck.Remove(deck.ElementAt(x));
                }
            }
        }

        /// <summary>
        /// Whos the won.
        /// </summary>
        /// <returns>The won.</returns>
        /// <param name="board">Board.</param>
        private int whoWon(List<Card> board)
        {
            int winner = -1;
            for (int i = 0; i != board.Count; i += 1)
            {
                if (i == 0)
                    winner = i;
                else
                {
                    if (board.ElementAt(i).getColor() == contract.getColor())
                    {
                        if (board.ElementAt(winner).getColor() == contract.getColor())
                        {
                            if (Array.IndexOf(Card.withAsset, board.ElementAt(i).getValue()) > Array.IndexOf(Card.withAsset, board.ElementAt(winner).getValue()))
                                winner = i;
                        }
                        else
                            winner = i;
                    }
                    else if (board.ElementAt(winner).getColor() != contract.getColor() && Array.IndexOf(Card.withAsset, board.ElementAt(i).getValue()) > Array.IndexOf(Card.withoutAsset, board.ElementAt(winner).getValue()))
                        winner = i;
                }
            }
            GameManager.SendAll(players, "\n  ***  Player " + winner + " won this round.  ***  \n");
            players.ElementAt(winner).addWonTrick(board);
            return (winner);
        }

        /// <summary>
        /// Plaies the game.
        /// </summary>
        private void playTheGame()
        {
            List<Card> board = new List<Card>();
            int b = 0;
            for (int a = 0; a != 8; a += 1)
            {
                board.Clear();
                int c = 0;
                while (c != 4)
                {
                    board.Add(players.ElementAt(b).play(board, contract));
                    c += 1;
                    b = (b == 3 ? 0 : b + 1);
                }
                b = whoWon(board);
            }
        }

        /// <summary>
        /// Counts the score.
        /// </summary>
        private void countScore()
        {
            int team1 = 0;
            int team2 = 0;
            GameManager.SendAll(players, " ");
            foreach (Player i in players)
            {
                i.countScore();
                GameManager.SendAll(players, "Player " + i.getId() + " of the " + i.getTeam() + " team got " + i.getScore() + " points.");
                if (i.getTeam() == Team.FIRST)
                    team1 += i.getScore();
                else
                    team2 += i.getScore();
            }
            GameManager.SendAll(players, "\n" + Team.FIRST + " team got " + team1 + " points.");
            GameManager.SendAll(players, Team.SECOND + " team got " + team2 + " points.");
        }
    }
}