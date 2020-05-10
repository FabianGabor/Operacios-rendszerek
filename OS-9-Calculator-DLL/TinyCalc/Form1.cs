using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Calculator;

namespace TinyCalc
{
    public partial class Form1 : Form
    {
        string input = string.Empty;
        string a = string.Empty;
        string b = string.Empty;
        char op = '\0';
        double solution = 0.0;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }


        private void button0_Click(object sender, EventArgs e)
        {
            input += "0";
            this.textBoxSolution.Text = "";            
            this.textBoxSolution.Text += input;
        }

        private void button1_Click(object sender, EventArgs e)
        {            
            input += "1";
            this.textBoxSolution.Text = "";
            this.textBoxSolution.Text += input;
        }

        private void button2_Click(object sender, EventArgs e)
        {            
            input += "2";
            this.textBoxSolution.Text = "";
            this.textBoxSolution.Text += input;
        }

        private void button3_Click(object sender, EventArgs e)
        {            
            input += "3";
            this.textBoxSolution.Text = "";
            this.textBoxSolution.Text += input;
        }

        private void button4_Click(object sender, EventArgs e)
        {            
            input += "4";
            this.textBoxSolution.Text = "";
            this.textBoxSolution.Text += input;
        }

        private void button5_Click(object sender, EventArgs e)
        {            
            input += "5";
            this.textBoxSolution.Text = "";
            this.textBoxSolution.Text += input;
        }

        private void button6_Click(object sender, EventArgs e)
        {            
            input += "6";
            this.textBoxSolution.Text = "";
            this.textBoxSolution.Text += input;
        }

        private void button7_Click(object sender, EventArgs e)
        {            
            input += "7";
            this.textBoxSolution.Text = "";
            this.textBoxSolution.Text += input;
        }

        private void button8_Click(object sender, EventArgs e)
        {            
            input += "8";
            this.textBoxSolution.Text = "";
            this.textBoxSolution.Text += input;
        }

        private void button9_Click(object sender, EventArgs e)
        {            
            input += "9";
            this.textBoxSolution.Text = "";
            this.textBoxSolution.Text += input;
        }

       

        private void add_Click(object sender, EventArgs e)
        {
            this.textBoxHistory.Text += input + " + ";
            if (op.Equals('\0'))
                a = input;
            else
                b = input;
            op = '+';
            input = string.Empty;
        }

        private void sub_Click(object sender, EventArgs e)
        {
            this.textBoxHistory.Text += input + " - ";
            if (op.Equals('\0'))
                a = input;
            else
                b = input;
            op = '-';
            input = string.Empty;
        }

        private void mult_Click(object sender, EventArgs e)
        {
            this.textBoxHistory.Text += input + " x ";
            if (op.Equals('\0'))
                a = input;
            else
                b = input;
            op = '*';
            input = string.Empty;
        }

        private void div_Click(object sender, EventArgs e)
        {
            this.textBoxHistory.Text += input + " / ";
            if (op.Equals('\0'))
                a = input;
            else
                b = input;
            op = '/';
            input = string.Empty;
        }

        private void clear_Click(object sender, EventArgs e)
        {
            this.textBoxSolution.Text = "";
            this.textBoxHistory.Text = "";
            this.input = string.Empty;
            this.a = string.Empty;
            this.b = string.Empty;
        }

        private void eq_Click(object sender, EventArgs e)
        {
            if (input.Length > 0) {
                b = input;
                input += " = ";
                this.textBoxHistory.Text += input;
                input = string.Empty;
            }

            double num1, num2;
            double.TryParse(a, out num1);
            double.TryParse(b, out num2);

            calculate cal = new calculate();


            switch (op)
            {
                case '+':
                    {
                        solution = cal.Add(num1, num2);
                        if (solution.ToString().Length > 12)
                            textBoxSolution.Text = solution.ToString().Remove(12);
                        else
                            textBoxSolution.Text = solution.ToString();
                        textBoxHistory.Text = a + " " + op + " " + b + " =";
                        a = solution.ToString();

                        break; 
                    }
                case '-':
                    {
                        solution = cal.Substract(num1, num2);
                        if (solution.ToString().Length > 12)
                            textBoxSolution.Text = solution.ToString().Remove(12);
                        else
                            textBoxSolution.Text = solution.ToString();
                        textBoxHistory.Text = a + " " + op + " " + b + " =";
                        a = solution.ToString();

                        break;
                    }
                case '*':
                    {
                        solution = cal.Multiply(num1, num2);
                        textBoxSolution.Text = solution.ToString();
                        textBoxHistory.Text = a + " " + op + " " + b + " =";
                        a = solution.ToString();

                        break;
                    }
                case '/':
                    {
                        solution = Math.Round(cal.Divide(num1, num2), 10);
                        if (solution.ToString().Length > 12)
                            textBoxSolution.Text = solution.ToString().Remove(12);
                        else
                            textBoxSolution.Text = solution.ToString();
                        textBoxHistory.Text = a + " " + op + " " + b + " =";
                        a = solution.ToString();

                        break;
                    }
            }
        }
    }
}
