using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculator
{
    
    public partial class Form1 : Form
    {
        double n1;
        string op;

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            label1.Text = label1.Text + "1";
        }

        private void button6_Click(object sender, EventArgs e)
        {
            label1.Text = label1.Text + "2";
        }

        private void button7_Click(object sender, EventArgs e)
        {
            label1.Text = label1.Text + "3";
        }

        private void button9_Click(object sender, EventArgs e)
        {
            label1.Text = label1.Text + "4";
        }

        private void button10_Click(object sender, EventArgs e)
        {
            label1.Text = label1.Text + "5";
        }

        private void button11_Click(object sender, EventArgs e)
        {
            label1.Text = label1.Text + "6";
        }

        private void button13_Click(object sender, EventArgs e)
        {
            label1.Text = label1.Text + "7";
        }

        private void button16_Click(object sender, EventArgs e)
        {
            label1.Text = label1.Text + "8";
        }

        private void button17_Click(object sender, EventArgs e)
        {
            label1.Text = label1.Text + "9";
        }

        private void button14_Click(object sender, EventArgs e)
        {
            n1 = Convert.ToDouble(label1.Text);
            label1.Text = "0";
            op = "1/x";
        }

        private void button21_Click(object sender, EventArgs e)
        {
            n1 = Convert.ToDouble(label1.Text);
            label1.Text = "0";
            op = "x^2";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            n1 = Convert.ToDouble(label1.Text);
            label1.Text = "0";
            op = "x^3";
        }

        private void button20_Click(object sender, EventArgs e)
        {
            n1 = Convert.ToDouble(label1.Text);
            label1.Text = "0";
            op = "√x";
        }

        private void button4_Click(object sender, EventArgs e)
        {
            label1.Text = label1.Text + ".";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            label1.Text = label1.Text + "0";
        }

        private void button8_Click(object sender, EventArgs e)
        {
            n1 = Convert.ToDouble(label1.Text);
            label1.Text = "0";
            op = "+";
        }

        private void button12_Click(object sender, EventArgs e)
        {
            n1 = Convert.ToDouble(label1.Text);
            label1.Text = "0";
            op = "-";
        }

        private void button18_Click(object sender, EventArgs e)
        {
            n1 = Convert.ToDouble(label1.Text);
            label1.Text = "0";
            op = "x";
        }

        private void button19_Click(object sender, EventArgs e)
        {
            n1 = Convert.ToDouble(label1.Text);
            label1.Text = "0";
            op = "/";
        }

        private void button15_Click(object sender, EventArgs e)
        {
            n1 = Convert.ToDouble(label1.Text);
            label1.Text = "0";
            op = "%";
        }

        private void button23_Click(object sender, EventArgs e)
        {
            label1.Text = "0";
        }

        private void button22_Click(object sender, EventArgs e)
        {
            label1.Text = "0";
        }

        private void button5_Click(object sender, EventArgs e)
        {
            double result;
            double n2;

            n2 = Convert.ToDouble(label1.Text);

            if(op=="+")
            {
                result = (n1 + n2);
                label1.Text = Convert.ToString(result);
                n1 = result;
            }
            if (op == "-")
            {
                result = (n1 - n2);
                label1.Text = Convert.ToString(result);
                n1 = result;
            }
            if (op == "x")
            {
                result = (n1 * n2);
                label1.Text = Convert.ToString(result);
                n1 = result;
            }
            if (op == "/")
            {
                if(n2==0)
                {
                    label1.Text = "Error!";
                }
                else
                {
                    result = (n1 / n2);
                    label1.Text = Convert.ToString(result);
                    n1 = result;
                }
            }
            if (op == "%")
            {
                result = (n1 / 100);
                label1.Text = Convert.ToString(result);
                n1 = result;
            }
            if (op == "1/x")
            {
                result = (1 / n1);
                label1.Text = Convert.ToString(result);
                n1 = result;
            }
            if (op == "x^2")
            {
                result = (n1 * n1);
                label1.Text = Convert.ToString(result);
                n1 = result;
            }
            if (op == "x^3")
            {
                result = (n1 * n1 * n1);
                label1.Text = Convert.ToString(result);
                n1 = result;
            }
            if (op == "√x")
            {
                result = Math.Sqrt(n1);
                label1.Text = Convert.ToString(result);
                n1 = result;
            }

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
