using System;
using System.IO;
using System.Text;

namespace UniLib.general
{
    public class utils
    {
        public static void createFile(string filePath, string fileName, string txt)
        {
            try
            {
                if (File.Exists(filePath + fileName))
                {
                    debug.log("File already exists!");
                    return;
                }

                // Create the file.
                using (FileStream fs = File.Create(filePath + fileName))
                {
                    Byte[] info = new UTF8Encoding(true).GetBytes(txt);
                    // Add some information to the file.
                    fs.Write(info, 0, info.Length);
                }
            }
            catch (Exception e)
            {
                debug.log(e.ToString());
            }
        }

        public static void createFile(string filePath, string fileName)
        {
            if (File.Exists(filePath + fileName))
            {
                debug.log("File already exists!");
                return;
            }

            File.Create(filePath + fileName);
        }
    }

    public class debug
    {
        public static void log(string text, bool getTime = false)
        {
            if (!getTime)
            {
                Console.WriteLine(text);
            }
            else
            {
                string time = DateTime.Now.ToString("h:mm:ss tt");
                Console.WriteLine("[" + time + "] " + text);
            }
        }

        public static void log(string text, string path)
        {
            string time = DateTime.Now.ToString("h:mm:ss tt");
            utils.createFile(path, time + ".txt", text);
        }

        public static void log(string text, string path, string fileName)
        {
            utils.createFile(path, fileName, text);
        }
    }
}
