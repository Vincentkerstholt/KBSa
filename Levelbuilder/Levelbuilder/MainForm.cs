﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;

namespace Levelbuilder
{
    public partial class MainForm : Form
    {
        const int ROWS = 22;
        const int COLUMNS = 215;
        Node[][] level;
        List<Node> selectedNodes = new List<Node>();
        int viewColumn = 1;
        bool shiftKeyIsDown = false;
        bool HeroIsSet = false;
        Point lastSelectedNode = new Point(-1,-1);

        public MainForm()
        {
            InitializeComponent();

            level = new Node[COLUMNS][];
            for (int i = 0; i < COLUMNS; i++)
            {
                level[i] = new Node[ROWS];
            }

            for (int x = 0; x < COLUMNS; x++)
            {
                for (int y = 0; y < ROWS; y++)
                {
                    level[x][y] = new Node();
                }
            }

            panel.Width = 42 * 32 + 1;
            panel.Height = 22 * 32 + 1;
            gb_Tiles.Height = 22 * 32 + 1;
            hScrollBar.Maximum = 59;
            hScrollBar.LargeChange = 3;
            hScrollBar.Location = new Point(panel.Location.X, panel.Location.Y + panel.Height);
            hScrollBar.Width = panel.Width;
            this.Height = panel.Location.Y + panel.Height + hScrollBar.Height + 60;
            this.Width = gb_Tiles.Width + panel.Width + 50;

            comboBox_Theme.SelectedIndex = 0;

            this.Focus();
        }

        private void comboBox_Theme_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (comboBox_Theme.SelectedItem.ToString())
            {
                case "Landscape":
                    panel.BackgroundImage = Properties.Resources.backgroundSky;
                    break;

                case "Dungeon":
                    panel.BackgroundImage = Properties.Resources.backgroundCave;
                    break;

                case "Sky":

                    break;

                case "Water":

                    break;
            }
        }

        private void panel_Paint(object sender, PaintEventArgs e)
        {
            Pen p = new Pen(Color.Black);
            Brush b = new SolidBrush(Color.FromArgb(150, Color.Gray));

            for (int x = viewColumn; x < (43 + viewColumn); x++)
            {
                for (int y = 0; y < ROWS; y++)
                {
                    level[x - 1][y].drawGameObject(e.Graphics, x - viewColumn, y);

                    if (selectedNodes.Contains(level[x - 1][y]))
                        e.Graphics.FillRectangle(b, (x - viewColumn) * 32, y * 32, 32, 32);
                }
            }

            for (int i = 0; i <= COLUMNS; i++)
            {
                e.Graphics.DrawLine(p, i * 32, 0, i * 32, ROWS * 32);
            }

            for (int i = 0; i <= ROWS; i++)
            {
                e.Graphics.DrawLine(p, 0, i * 32, COLUMNS * 32, i * 32);
            }
        }

        private void panel_MouseClick(object sender, MouseEventArgs e)
        {
            int x = (e.X / 32) + viewColumn;
            int y = e.Y / 32;

            if (shiftKeyIsDown)
            {
                if (x < lastSelectedNode.X)
                {
                    for (int i = x - 1; i <= lastSelectedNode.X; i++)
                    {
                        if (y < lastSelectedNode.Y)
                        {
                            for (int j = y; j <= lastSelectedNode.Y; j++)
                            {
                                selectedNodes.Add(level[i][j]);
                            }
                        }
                        else if (y >= lastSelectedNode.Y)
                        {
                            for (int j = lastSelectedNode.Y; j <= y; j++)
                            {
                                selectedNodes.Add(level[i][j]);
                            }
                        }
                    }
                }
                else if (x >= lastSelectedNode.X)
                {
                    for (int i = lastSelectedNode.X; i < x; i++)
                    {
                        if (y < lastSelectedNode.Y)
                        {
                            for (int j = y; j <= lastSelectedNode.Y; j++)
                            {
                                selectedNodes.Add(level[i][j]);
                            }
                        }
                        else if (y >= lastSelectedNode.Y)
                        {
                            for (int j = lastSelectedNode.Y; j <= y; j++)
                            {
                                selectedNodes.Add(level[i][j]);
                            }
                        }
                    }
                }
            }
            else
            {
                selectedNodes.Clear();
                selectedNodes.Add(level[x - 1][y]);
            }
            lastSelectedNode = new Point(x - 1, y);

            panel.Invalidate();
        }

        private void hScrollBar_Scroll(object sender, ScrollEventArgs e)
        {
            if (e.OldValue > e.NewValue)
            {
                int diff = e.OldValue - e.NewValue;
                //Left
                if (viewColumn < 4)
                    viewColumn = 1;
                else
                    viewColumn -= 3 * diff;
            }
            else if(e.OldValue < e.NewValue)
            {
                int diff = e.NewValue - e.OldValue;
                //Right
                if (viewColumn > (COLUMNS - 43) - 4)
                    viewColumn = COLUMNS - 43;
                else
                    viewColumn += 3 * diff;
            }

            panel.Invalidate();
        }

        private void pictureBox_Click(object sender, EventArgs e)
        {
            if (selectedNodes.Count > 0)
            {
                bool errorMessageShown = false;
                foreach (Node selectedNode in selectedNodes)
                {
                    if (selectedNode.gameObject != null && selectedNode.gameObject.GetType().Name == "Hero")
                        HeroIsSet = false;

                    switch (((PictureBox)sender).Name)
                    {
                        case "pictureBox_Ground_TopLeft":
                            selectedNode.gameObject = new Ground() { groundType = "TopLeft" };
                            break;

                        case "pictureBox_Ground_TopCenter":
                            selectedNode.gameObject = new Ground() { groundType = "TopCenter" };
                            break;

                        case "pictureBox_Ground_TopRight":
                            selectedNode.gameObject = new Ground() { groundType = "TopRight" };
                            break;

                        case "pictureBox_Ground_CenterLeft":
                            selectedNode.gameObject = new Ground() { groundType = "CenterLeft" };
                            break;

                        case "pictureBox_Ground_CenterCenter":
                            selectedNode.gameObject = new Ground() { groundType = "CenterCenter" };
                            break;

                        case "pictureBox_Ground_CenterRight":
                            selectedNode.gameObject = new Ground() { groundType = "CenterRight" };
                            break;

                        case "pictureBox_Ground_BottomLeft":
                            selectedNode.gameObject = new Ground() { groundType = "BottomLeft" };
                            break;

                        case "pictureBox_Ground_BottomCenter":
                            selectedNode.gameObject = new Ground() { groundType = "BottomCenter" };
                            break;

                        case "pictureBox_Ground_BottomRight":
                            selectedNode.gameObject = new Ground() { groundType = "BottomRight" };
                            break;

                        case "pictureBox_Block":
                            selectedNode.gameObject = new Block() { isSpecial = false };
                            break;

                        case "pictureBox_SpecialBlock":
                            selectedNode.gameObject = new Block() { isSpecial = true };
                            break;

                        case "pictureBox_Empty":
                            selectedNode.gameObject = null;
                            break;

                        case "pictureBox_Mario":
                            if (selectedNodes.Count == 1 && !HeroIsSet)
                            {
                                selectedNode.gameObject = new Hero() { character = "Mario" };
                                HeroIsSet = true;
                            }
                            else
                            {
                                if (!errorMessageShown)
                                {
                                    MessageBox.Show("This world is not big enough for more than one hero!");
                                    errorMessageShown = true;
                                }
                            }
                            break;
                    }
                }
                panel.Invalidate();
                selectedNodes.Clear();
            }
        }

        private void MainForm_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.Shift)
                shiftKeyIsDown = true;
        }

        private void MainForm_KeyUp(object sender, KeyEventArgs e)
        {
            shiftKeyIsDown = false;
        }

        private void button_CreateXML_Click(object sender, EventArgs e)
        {
            button_CreateXML.Enabled = false;
            try
            {
                SaveFileDialog sfd = new SaveFileDialog();
                sfd.Filter = "XML|*.xml|All files|*.*";
                sfd.ShowDialog();

                if (sfd.FileName != "")
                {
                    XmlTextWriter writer = new XmlTextWriter(sfd.FileName, null);
                    //Opening the document
                    writer.WriteStartDocument();
                    writer.WriteWhitespace("\n");

                    //Opening the root node
                    writer.WriteStartElement("superMario");
                    writer.WriteWhitespace("\n");

                    //Creating the factory node
                    writer.WriteWhitespace("\t");
                    writer.WriteStartElement("factory");
                    writer.WriteAttributeString("name", comboBox_Theme.SelectedItem.ToString().ToLower());
                    writer.WriteEndElement();
                    writer.WriteWhitespace("\n");

                    //Opening the level node
                    writer.WriteWhitespace("\t");
                    writer.WriteStartElement("level");
                    writer.WriteAttributeString("width", COLUMNS.ToString());
                    writer.WriteAttributeString("height", ROWS.ToString());
                    writer.WriteWhitespace("\n");

                    //Opening the blocks node
                    writer.WriteWhitespace("\t\t");
                    writer.WriteStartElement("blocks");
                    writer.WriteWhitespace("\n");

                    for (int i = 0; i < COLUMNS; i++)
                    {
                        for (int j = 0; j < ROWS; j++)
                        {
                            if (level[i][j].gameObject != null && level[i][j].gameObject.GetType().Name == "Block")
                            {
                                //Opening a block node
                                writer.WriteWhitespace("\t\t\t");
                                writer.WriteStartElement("block");
                                writer.WriteAttributeString("isSpecial", ((Block)level[i][j].gameObject).isSpecial.ToString().ToLower());
                                writer.WriteWhitespace("\n");

                                //Creating a location node
                                writer.WriteWhitespace("\t\t\t\t");
                                writer.WriteStartElement("location");
                                writer.WriteAttributeString("x", i.ToString());
                                writer.WriteAttributeString("y", j.ToString());
                                writer.WriteEndElement();
                                writer.WriteWhitespace("\n");

                                //Opening a gadget node
                                writer.WriteWhitespace("\t\t\t\t");
                                writer.WriteStartElement("gadget");
                                writer.WriteWhitespace("\n");

                                //Creating a coin node
                                writer.WriteWhitespace("\t\t\t\t\t");
                                writer.WriteStartElement("coin");
                                writer.WriteAttributeString("value", "5");
                                writer.WriteEndElement();
                                writer.WriteWhitespace("\n");

                                //Closing a gadget node
                                writer.WriteWhitespace("\t\t\t\t");
                                writer.WriteEndElement();
                                writer.WriteWhitespace("\n");

                                //Closing a block node
                                writer.WriteWhitespace("\t\t\t");
                                writer.WriteEndElement();
                                writer.WriteWhitespace("\n");
                            }
                        }
                    }

                    //Closing the blocks node
                    writer.WriteWhitespace("\t\t");
                    writer.WriteEndElement();
                    writer.WriteWhitespace("\n");

                    //Opening the pipes node
                    writer.WriteWhitespace("\t\t");
                    writer.WriteStartElement("pipes");
                    writer.WriteWhitespace("\n");

                    for (int i = 0; i < COLUMNS; i++)
                    {
                        for (int j = 0; j < ROWS; j++)
                        {
                            if (level[i][j].gameObject != null && level[i][j].gameObject.GetType().Name == "Pipe")
                            {
                                //Opening a pipe node
                                writer.WriteWhitespace("\t\t\t");
                                writer.WriteStartElement("pipe");
                                writer.WriteAttributeString("type", ((Pipe)level[i][j].gameObject).pipeType.ToLower());
                                writer.WriteWhitespace("\n");

                                //Creating a location node
                                writer.WriteWhitespace("\t\t\t\t");
                                writer.WriteStartElement("location");
                                writer.WriteAttributeString("x", i.ToString());
                                writer.WriteAttributeString("y", j.ToString());
                                writer.WriteEndElement();
                                writer.WriteWhitespace("\n");

                                //Closing a pipe node
                                writer.WriteWhitespace("\t\t\t");
                                writer.WriteEndElement();
                                writer.WriteWhitespace("\n");
                            }
                        }
                    }

                    //Closing the pipes node
                    writer.WriteWhitespace("\t\t");
                    writer.WriteEndElement();
                    writer.WriteWhitespace("\n");

                    //Opening the grounds node
                    writer.WriteWhitespace("\t\t");
                    writer.WriteStartElement("grounds");
                    writer.WriteWhitespace("\n");

                    for (int i = 0; i < COLUMNS; i++)
                    {
                        for (int j = 0; j < ROWS; j++)
                        {
                            if (level[i][j].gameObject != null && level[i][j].gameObject.GetType().Name == "Ground")
                            {
                                //Opening a ground node
                                writer.WriteWhitespace("\t\t\t");
                                writer.WriteStartElement("ground");
                                writer.WriteAttributeString("type", ((Ground)level[i][j].gameObject).groundType.ToLower());
                                writer.WriteWhitespace("\n");

                                //Creating a location node
                                writer.WriteWhitespace("\t\t\t\t");
                                writer.WriteStartElement("location");
                                writer.WriteAttributeString("x", i.ToString());
                                writer.WriteAttributeString("y", j.ToString());
                                writer.WriteEndElement();
                                writer.WriteWhitespace("\n");

                                //Closing a ground node
                                writer.WriteWhitespace("\t\t\t");
                                writer.WriteEndElement();
                                writer.WriteWhitespace("\n");
                            }
                        }
                    }

                    //Closing the grounds node
                    writer.WriteWhitespace("\t\t");
                    writer.WriteEndElement();
                    writer.WriteWhitespace("\n");

                    //Closing the level node
                    writer.WriteWhitespace("\t");
                    writer.WriteEndElement();
                    writer.WriteWhitespace("\n");

                    //Closing the root node
                    writer.WriteEndElement();
                    writer.WriteWhitespace("\n");
                    //Closing the document
                    writer.WriteEndDocument();
                    //Closing the writer
                    writer.Close();
                }
                else
                {
                    MessageBox.Show("There is no file selected");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
            button_CreateXML.Enabled = true;
        }
    }
}