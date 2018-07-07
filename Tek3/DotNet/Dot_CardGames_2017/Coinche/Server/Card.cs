using System;
using System.Collections.Generic;

namespace Server
{
    /// <summary>
    /// Card.
    /// </summary>
    public class Card
    {
        /// <summary>
        /// Initializes a new instance of the <see cref="T:Server.Card"/> class.
        /// </summary>
        /// <param name="color">Color.</param>
        /// <param name="value">Value.</param>
        public Card(Color color, Value value)
        {
            this.color = color;
            this.value = value;
        }

        private readonly Color color;
        private readonly Value value;

        /// <summary>
        /// The with asset.
        /// </summary>
        public static readonly Value[] withAsset =
            {Value.SEVEN, Value.EIGHT, Value.NINE, Value.TEN, Value.JACK, Value.QUEEN, Value.KING, Value.ACE};

        /// <summary>
        /// The without asset.
        /// </summary>
        public static readonly Value[] withoutAsset =
            {Value.SEVEN, Value.EIGHT, Value.QUEEN, Value.KING, Value.TEN, Value.ACE, Value.NINE, Value.JACK};

        public static readonly int[] scoreValue = { 0, 0, 0, 2, 3, 4, 10, 19 };

        /// <summary>
        /// Gets the color.
        /// </summary>
        /// <returns>The color.</returns>
        public Color getColor()
        {
            return color;
        }

        /// <summary>
        /// Gets the value.
        /// </summary>
        /// <returns>The value.</returns>
        public Value getValue()
        {
            return value;
        }

        /// <summary>
        /// Do you have suit.
        /// </summary>
        /// <returns><c>true</c>, if the user have suit, <c>false</c> otherwise.</returns>
        /// <param name="deck">Deck.</param>
        public bool doYouHaveSuit(List<Card> deck)
        {
            foreach (Card i in deck)
            {
                if (i.getColor() == color)
                    return true;
            }
            return false;
        }

        /// <summary>
        /// Is it biggest.
        /// </summary>
        /// <returns><c>true</c>, if the card is the biggest, <c>false</c> otherwise.</returns>
        /// <param name="deck">Deck.</param>
        /// <param name="asset">If set to <c>true</c> asset.</param>
        public bool isItBiggest(List<Card> deck, bool asset)
        {
            foreach (Card i in deck)
            {
                if (asset)
                {
                    if (Array.IndexOf(withAsset, value) <= Array.IndexOf(withAsset, i.getValue()))
                        return true;
                }
                else
                {
                    if (Array.IndexOf(withAsset, value) <= Array.IndexOf(withAsset, i.getValue()))
                        return true;
                }
            }
            return false;
        }
    }
}