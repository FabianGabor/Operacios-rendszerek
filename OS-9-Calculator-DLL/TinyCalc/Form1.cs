using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TinyCalc
{
    public partial class Form1 : Form
    {
        string input = string.Empty;
        string a = string.Empty;
        string b = string.Empty;
        char op = string.Empty;
        double solution = 0.0;

        public Form1()
        {
            InitializeComponent();
        }
    }
}
