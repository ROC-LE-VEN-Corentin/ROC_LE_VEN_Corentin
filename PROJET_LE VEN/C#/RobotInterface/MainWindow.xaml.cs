using ExtendedSerialPort;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;

namespace RobotInterface
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        ReliableSerialPort serialPort1;
        string receivedText = "";
        DispatcherTimer timerAffichage;
        Robot robot = new Robot();
        
        
        public MainWindow()
        {
            InitializeComponent();

            serialPort1 = new ReliableSerialPort("COM4", 115200, System.IO.Ports.Parity.None, 8, System.IO.Ports.StopBits.One);
            serialPort1.DataReceived += SerialPort1_DataReceived;
            serialPort1.Open();

            timerAffichage = new DispatcherTimer();
            timerAffichage.Interval = new TimeSpan(0, 0, 0, 0, 100);
            timerAffichage.Tick += TimerAffichage_Tick;
            timerAffichage.Start();
        }

        private void TimerAffichage_Tick(object sender, EventArgs e)
        {
            //throw new NotImplementedException();
            if (robot.receivedText != "")
            {
                TextBoxReception.Text += robot.receivedText; //Oscillo analyseur de bus B1
                robot.receivedText = "";
            }
        }

        private void SerialPort1_DataReceived(object sender, DataReceivedArgs e)
        {
            //throw new NotImplementedException();
            robot.receivedText += Encoding.UTF8.GetString(e.Data, 0, e.Data.Length);
        }

        void SendMessage()
        {
            if (ButtonEnvoyer.Background == Brushes.RoyalBlue)
            {
                ButtonEnvoyer.Background = Brushes.Red;
            }
            else
            {
                ButtonEnvoyer.Background = Brushes.RoyalBlue;
            }
            serialPort1.WriteLine(TextBoxEmission.Text);
            //TextBoxReception.Text = TextBoxReception.Text + "Reçu : " + TextBoxEmission.Text + "\n";
            TextBoxEmission.Clear();
        }

        private void TextBoxEmission_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Enter)
            {
                SendMessage();
            }
        }

        private void ButtonEnvoyer_Click(object sender, RoutedEventArgs e)
        {
            SendMessage();
        }

        private void ButtonClear_Click(object sender, RoutedEventArgs e)
        {
            if (ButtonClear.Background == Brushes.RoyalBlue)
            {
                ButtonClear.Background = Brushes.Red;
            }
            else
            {
                ButtonClear.Background = Brushes.RoyalBlue;
            }
            TextBoxReception.Clear();
        }
    }
}
