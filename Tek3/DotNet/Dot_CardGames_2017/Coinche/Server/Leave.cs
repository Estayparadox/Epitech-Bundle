using System;

namespace Server
{
    /// <summary>
    /// Leave class exception.
    /// </summary>
    [Serializable()]
    public class Leave : System.Exception
    {
        public Leave() : base() { }
        public Leave(string message) : base(message) { }
        public Leave(string message, System.Exception inner) : base(message, inner) { }

        /// <summary>
        /// Initializes a new instance of the <see cref="T:Server.Leave"/> class.
        /// A constructor is needed for serialization when an exception propagates from a remoting server to the client.
        /// </summary>
        /// <param name="info">Info.</param>
        /// <param name="context">Context.</param>
        protected Leave(System.Runtime.Serialization.SerializationInfo info,
            System.Runtime.Serialization.StreamingContext context)
        { }
    }

}