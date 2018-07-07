using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading;

namespace Server
{
    /// <summary>
    /// Player.
    /// </summary>
    public class Player
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="T:Server.Player"/> class.
        /// </summary>
        /// <param name="id">Identifier.</param>
        /// <param name="team">Team.</param>
        /// <param name="userManager">User manager.</param>
        public Player(int id, Team team, UserManager userManager)
        {
            passed = false;
            this.id = id;
            cards = new List<Card>();
            this.team = team;
            wonTricks = new List<Card>();
            score = 0;
            this.userManager = userManager;
        }

        private int id;
        private List<Card> cards;
        private Team team;
        private List<Card> wonTricks;
        private bool passed;
        private int score;
        private UserManager userManager;

        /// <summary>
        /// Gets the user manager.
        /// </summary>
        /// <returns>The user manager.</returns>
        public UserManager getUserManager()
        {
            return userManager;
        }

        /// <summary>
        /// Sets the user manager.
        /// </summary>
        /// <param name="userManager">User manager.</param>
        public void setUserManager(UserManager userManager)
        {
            this.userManager = userManager;
        }

        /// <summary>
        /// Subs the card.
        /// </summary>
        /// <returns><c>true</c>, if card was subed, <c>false</c> otherwise.</returns>
        /// <param name="card">Card.</param>
        public bool subCard(Card card)
        {
            cards.Remove(card);
            return true;
        }

        /// <summary>
        /// Adds a card.
        /// </summary>
        /// <param name="card">Card.</param>
        public void addCard(Card card)
        {
            cards.Add(card);
        }

        /// <summary>
        /// Gets the score.
        /// </summary>
        /// <returns>The score.</returns>
        public int getScore()
        {
            return score;
        }

        /// <summary>
        /// Sets the score.
        /// </summary>
        /// <param name="score">Score.</param>
        public void setScore(int score)
        {
            this.score = score;
        }

        /// <summary>
        /// Gets the identifier.
        /// </summary>
        /// <returns>The identifier.</returns>
        public int getId()
        {
            return id;
        }

        /// <summary>
        /// Gets the cards.
        /// </summary>
        /// <returns>The cards.</returns>
        public List<Card> getCards()
        {
            return cards;
        }

        /// <summary>
        /// Gets the team.
        /// </summary>
        /// <returns>The team.</returns>
        public Team getTeam()
        {
            return team;
        }

        /// <summary>
        /// Dids you passed.
        /// </summary>
        /// <returns><c>true</c>, if you passed was dided, <c>false</c> otherwise.</returns>
        public bool didYouPassed()
        {
            return passed;
        }

        /// <summary>
        /// Adds the won trick.
        /// </summary>
        /// <param name="trick">Trick.</param>
        public void addWonTrick(List<Card> trick)
        {
            foreach (Card i in trick)
            {
                wonTricks.Add(i);
            }
        }

        /// <summary>
        /// Waits for message.
        /// </summary>
        /// <returns>The for message.</returns>
        public int WaitForMessage()
        {
            string answer = null;
            int res = 0;
            while (true)
            {
                answer = userManager.GetReader().ReadLine();
                if (Int32.TryParse(answer, out res))
                    break;
                GameManager.SendPrivate(this, "What are you trying to do?");
            }
            return res;
        }

        /// <summary>
        /// Plaies the check.
        /// </summary>
        /// <returns><c>true</c>, if check was played, <c>false</c> otherwise.</returns>
        /// <param name="board">Board.</param>
        /// <param name="n">N.</param>
        /// <param name="contract">Contract.</param>
        private bool playCheck(List<Card> board, int n, Contract contract)
        {
            try
            {
                cards.ElementAt(n);
                if (board.Count == 0)
                    return true;
                if (cards.ElementAt(n).getColor() == board.ElementAt(0).getColor())
                    return true;
                if (board.ElementAt(0).doYouHaveSuit(cards))
                    return false;
                if (cards.ElementAt(n).getColor() == contract.getColor())
                    return true;
                Card card = new Card(contract.getColor(), Value.ACE);
                return !card.doYouHaveSuit(cards);
            }
            catch (Exception)
            {
                GameManager.SendPrivate(this, "Out of range!");
                return false;
            }
        }

        /// <summary>
        /// Play the specified board and contract.
        /// </summary>
        /// <returns>The play.</returns>
        /// <param name="board">Board.</param>
        /// <param name="contract">Contract.</param>
        public Card play(List<Card> board, Contract contract)
        {
            if (board.Count != 0)
                GameManager.SendPrivate(this, "The current board is composed of :");
            foreach (Card i in board)
            {
                GameManager.SendPrivate(this, " - " + i.getValue() + " of " + i.getColor());
            }
            GameManager.SendPrivate(this, "Player " + this.id + "! Your turn! The asset's suit is " + contract.getColor() + ".");
            GameManager.SendPrivate(this, "Your current cards:");
            for (int j = 0; j != cards.Count; j += 1)
            {
                GameManager.SendPrivate(this, j + " -> " + cards.ElementAt(j).getValue() + " of " + cards.ElementAt(j).getColor());
            }
            GameManager.SendPrivate(this, "What is the number of the card you want to play?");
            int n = 0;
            bool end = false;
            while (!end)
            {
                n = WaitForMessage();
                if (!(end = playCheck(board, n, contract)))
                    GameManager.SendPrivate(this, "Wait... You can't play this card!");
            }
            GameManager.SendPrivate(this, "Great !");
            Card res = cards.ElementAt(n);
            cards.Remove(cards.ElementAt(n));
            return res;
        }

        /// <summary>
        /// Counts the score.
        /// </summary>
        public void countScore()
        {
            foreach (Card i in wonTricks)
            {
                score += Card.scoreValue[Array.IndexOf(Card.withAsset, i.getValue())];
            }
            wonTricks.Clear();
        }
    }
}