using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Levelbuilder
{
    public partial class MainForm : Form
    {
        const int ROWS = 22;
        const int COLUMNS = 43;
        Gameobject[][] level;


        public MainForm()
        {
            InitializeComponent();

            level = new Gameobject[ROWS][];
            for (int i = 0; i < ROWS; i++)
            {
                level[i] = new Gameobject[COLUMNS];
            }

            dataGridView.DataSource = level;
            for (int i = 0; i < COLUMNS; i++)
            {
                DataGridViewImageColumn img = new DataGridViewImageColumn();
                img.HeaderText = "Image";
                img.Name = i.ToString();
                img.ValuesAreIcons = false;

                dataGridView.Columns.Add(img);
            }

            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLUMNS; j++)
                {
                    dataGridView.Rows[i].Cells[j].Value = Properties.Resources.ground;
                }
            }
        }

        private void comboBox_Theme_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (comboBox_Theme.SelectedItem.ToString())
            {
                case "Landscape":
                    //tableLayoutPanel.BackgroundImage = Properties.Resources.backgroundSky;
                    break;

                case "Dungeon":
                    //tableLayoutPanel.BackgroundImage = Properties.Resources.backgroundCave;
                    break;

                case "Sky":

                    break;

                case "Water":

                    break;
            }
        }

        private void dataGridView_Scroll(object sender, ScrollEventArgs e)
        {
            dataGridView.Invalidate();
        }
    }
}
