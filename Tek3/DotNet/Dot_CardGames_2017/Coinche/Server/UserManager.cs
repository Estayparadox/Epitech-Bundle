using System;
using System.IO;
using System.Net.Sockets;

namespace Server
{
    /// <summary>
    /// User manager.
    /// </summary>
    public class UserManager
    {
        private Socket socket;
        private Stream stream;
        private StreamReader reader;
        private StreamWriter writer;

        /// <summary>
        /// Initializes a new instance of the <see cref="T:Server.UserManager"/> class.
        /// </summary>
        /// <param name="socket">Socket.</param>
        public UserManager(Socket socket)
        {
            this.socket = socket;
            stream = new NetworkStream(socket);
            reader = new StreamReader(stream);
            writer = new StreamWriter(stream)
            { AutoFlush = true };
        }

        /// <summary>
        /// Gets the reader.
        /// </summary>
        /// <returns>The reader.</returns>
        public StreamReader GetReader()
        {
            return reader;
        }

        /// <summary>
        /// Gets the writer.
        /// </summary>
        /// <returns>The writer.</returns>
        public StreamWriter GetWriter()
        {
            return writer;
        }

        /// <summary>
        /// Check if the user is connected to the server
        /// </summary>
        /// <returns><c>true</c>, if the user is "alive", <c>false</c> otherwise.</returns>
        public bool IsAlive()
        {
            try
            {
                writer.WriteLine("alive");
                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }
    }
}