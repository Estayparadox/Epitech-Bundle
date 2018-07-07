namespace Server
{
    /// <summary>
    /// Status enum.
    /// </summary>
    public enum Status
    {
        AMOUNT,
        COINCH,
        SURCOINCH,
        CAPOT
    }

    /// <summary>
    /// Contract.
    /// </summary>
    public class Contract
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="T:Server.Contract"/> class.
        /// </summary>
        public Contract()
        {
            amount = 80;
            color = Color.HEART;
            status = Status.AMOUNT;
            team = Team.FIRST;
        }

        private int amount;
        private Color color;
        private Status status;
        private Team team;

        /// <summary>
        /// Gets the amount.
        /// </summary>
        /// <returns>The amount.</returns>
        public int getAmount()
        {
            return amount;
        }

        /// <summary>
        /// Gets the color.
        /// </summary>
        /// <returns>The color.</returns>
        public Color getColor()
        {
            return color;
        }

        /// <summary>
        /// Gets the status.
        /// </summary>
        /// <returns>The status.</returns>
        public Status getStatus()
        {
            return status;
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
        /// Sets the amount.
        /// </summary>
        /// <returns><c>true</c>, if amount is set, <c>false</c> otherwise.</returns>
        /// <param name="amount">Amount.</param>
        public bool setAmount(int amount)
        {
            if (this.amount >= amount || amount < 80)
                return false;
            this.amount = amount;
            return true;
        }

        /// <summary>
        /// Sets the color.
        /// </summary>
        /// <returns><c>true</c>, if color is set, <c>false</c> otherwise.</returns>
        /// <param name="color">Color.</param>
        public bool setColor(int color)
        {
            switch (color)
            {
                case 0:
                    this.color = Color.CLUB;
                    break;
                case 1:
                    this.color = Color.DIAMOND;
                    break;
                case 2:
                    this.color = Color.HEART;
                    break;
                case 3:
                    this.color = Color.SPADE;
                    break;
            }
            return true;
        }

        /// <summary>
        /// Sets the status.
        /// </summary>
        /// <returns><c>true</c>, if status is set, <c>false</c> otherwise.</returns>
        /// <param name="status">Status.</param>
        public bool setStatus(Status status)
        {
            this.status = status;
            return true;
        }

        /// <summary>
        /// Sets the team.
        /// </summary>
        /// <returns><c>true</c>, if team is set, <c>false</c> otherwise.</returns>
        /// <param name="team">Team.</param>
        public bool setTeam(Team team)
        {
            this.team = team;
            return true;
        }
    }
}