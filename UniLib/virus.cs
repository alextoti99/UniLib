using System.Diagnostics;

namespace UniLib.virus
{
    public class FileSystem
    {
        public static void OpenFile(int times, string filePath, ProcessWindowStyle style, bool unlimited = false)
        {
            if (filePath.Length <= 0 || filePath == null)
                return;

            if (times > 1 || unlimited)
            {
                if (!unlimited)
                {
                    for (int i = 0; i < times; i++)
                    {
                        startProcess(filePath, style);
                    }
                }
                else
                {
                    for (; ; )
                    {
                        startProcess(filePath, style);
                    }
                }
            }
            else
            {
                startProcess(filePath, style);
            }
        }

        private static void startProcess(string filePath, ProcessWindowStyle style)
        {
            Process p = new Process();
            // Configure the process using the StartInfo properties.
            p.StartInfo.FileName = filePath;
            p.StartInfo.WindowStyle = style;
            p.Start();
            p.WaitForExit();
        }
    }
}
