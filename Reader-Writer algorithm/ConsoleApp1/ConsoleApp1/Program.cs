using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Timers;

namespace Laiksakritīgi_procesi
{

    enum ProcessType // processu iedalīšana 2 daļās: lasītājs vai rakstītājs
    {
        Reader,
        Writer
    }

    struct ProcessTimingItem // processu ilguma laiks
    {
        public int pauseMin;
        public int pauseMax;
        public int usageMin;
        public int usageMax;
        public ProcessTimingItem(int pauseMin, int pauseMax, int usageMin, int usageMax)
        {
            this.pauseMin = pauseMin;
            this.pauseMax = pauseMax;
            this.usageMin = usageMin;
            this.usageMax = usageMax;
        }
    }

    class ProcessRunner // izmanto procesa attelošanai
    {
        public bool isRunning = false;
        public ProcessType processType;
        public static int readCount = 0;

        private ProcessTimingItem timing;
        private Random rng;
        public ProcessRunner(ProcessTimingItem timingData, ProcessType typeValue, Random rng)
        {
            this.rng = rng;
            this.timing = timingData;
            this.processType = typeValue;

        }

        public void ProcessWriter(object data) // rakstitāju loģika (izmantojot semaforus)
        {
            while (true)
            {
                Thread.Sleep(rng.Next(this.timing.pauseMin, this.timing.pauseMax)); // pauze starp darbībām

                Program.writingSemaphore.WaitOne();
                this.isRunning = true;
                Thread.Sleep(rng.Next(this.timing.usageMin, this.timing.usageMax)); //  darbība
                this.isRunning = false;
                Program.writingSemaphore.Release();
            }
        }

        public void ProcessReader(object data) // lasītāju loģika (izmantojot semaforus)
        {
            while (true)
            {
                Thread.Sleep(rng.Next(this.timing.pauseMin, this.timing.pauseMax)); // pauze starp darbībām

                Program.readingSemaphore.WaitOne();
                readCount++;
                if (readCount == 1) Program.writingSemaphore.WaitOne();
                Program.readingSemaphore.Release();

                this.isRunning = true;
                Thread.Sleep(rng.Next(this.timing.usageMin, this.timing.usageMax)); //  darbība
                this.isRunning = false;

                Program.readingSemaphore.WaitOne();
                readCount--;
                if (readCount == 0) Program.writingSemaphore.Release();
                Program.readingSemaphore.Release();
            }
        }

    }

    class Program
    {

        // programmas mainīgie
        static List<ProcessRunner> runnerList = new List<ProcessRunner>();
        public static Semaphore writingSemaphore = new Semaphore(1, 1);
        public static Semaphore readingSemaphore = new Semaphore(1, 1);

        static void Main(string[] args)
        {
            // inicializācijas mainīgie
            int config_UpdateSpeed;
            int config_WriterCount;
            List<ProcessTimingItem> config_WriterTiming = new List<ProcessTimingItem>();
            int config_ReaderCount;
            List<ProcessTimingItem> config_ReaderTiming = new List<ProcessTimingItem>();


            // sākuma parametri
            Console.WriteLine("Sakuma parametri:\n Rakstitāji(M) = 1\n Lasitāji(N) = 4");
            config_WriterCount = 1;
            config_ReaderCount = 4;

            // rakstitāju un lasitāju darbības laiks (ir randomizēts)
            Random rng = new Random();
            for (int i = 0; i < config_WriterCount; i++)
            {
                config_WriterTiming.Add(new ProcessTimingItem(
                    rng.Next(1000, 2000),
                    rng.Next(2000, 4000),
                    rng.Next(500, 1500),
                    rng.Next(1500, 2000)
                    ));
            }
            for (int i = 0; i < config_ReaderCount; i++)
            {
                config_ReaderTiming.Add(new ProcessTimingItem(
                    rng.Next(125, 250),
                    rng.Next(250, 500),
                    rng.Next(125, 250),
                    rng.Next(250, 500)
                    ));
            }
            // processu atjaunošanas ātrums
            config_UpdateSpeed = 50;
            Console.WriteLine("Nospiediet jebkuru taustiņu, lai uzsāktu algoritmu.");
            Console.ReadKey();
            Console.Clear();
            Console.Write(new string('\n', Console.WindowHeight));

            System.Timers.Timer displayTimer = new System.Timers.Timer();
            displayTimer.Interval = config_UpdateSpeed;
            displayTimer.Elapsed += UpdateDisplay;

            // līniju izveide
            for (int i = 0; i < config_WriterCount; i++)
            {
                runnerList.Add(new ProcessRunner(config_WriterTiming[i], ProcessType.Writer, new Random(i)));
            }
            for (int i = 0; i < config_ReaderCount; i++)
            {
                runnerList.Add(new ProcessRunner(config_ReaderTiming[i], ProcessType.Reader, new Random(i + config_WriterCount)));
            }
            for (int i = 0; i < runnerList.Count; i++) // palaiž līnijas
            {
                if (runnerList[i].processType == ProcessType.Writer)
                    new Thread(new ParameterizedThreadStart(runnerList[i].ProcessWriter)).Start();
                else
                    new Thread(new ParameterizedThreadStart(runnerList[i].ProcessReader)).Start();
            }

            displayTimer.Start();
        }

        static void UpdateDisplay(object sender, ElapsedEventArgs e) // izvada datus 
        {
            int oldConsoleLine = Console.CursorTop;

            Console.SetCursorPosition(0, Console.CursorTop);
            Console.Write(new string(' ', Console.BufferWidth));
            Console.SetCursorPosition(0, Console.CursorTop);
            for (int i = 0; i < runnerList.Count; i++)
            {
                string processCharacter = "L";
                if (runnerList[i].processType == ProcessType.Writer) processCharacter = "R";
                Console.Write("\t" + processCharacter + (i + 1).ToString());
            }
            Console.SetCursorPosition(0, oldConsoleLine);

            for (int i = 0; i < runnerList.Count; i++)
            {
                switch (runnerList[i].isRunning)
                {
                    case true:
                        Console.Write("\t║");
                        break;
                    case false:
                        Console.Write("\t ");
                        break;
                }
            }
            Console.WriteLine();
        }
    }
}


