namespace Levelbuilder
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.gb_Tiles = new System.Windows.Forms.GroupBox();
            this.comboBox_Theme = new System.Windows.Forms.ComboBox();
            this.label_Theme = new System.Windows.Forms.Label();
            this.hScrollBar = new System.Windows.Forms.HScrollBar();
            this.button_CreateXML = new System.Windows.Forms.Button();
            this.panel = new System.Windows.Forms.Panel();
            this.pictureBox_Empty = new System.Windows.Forms.PictureBox();
            this.pictureBox_SpecialBlock = new System.Windows.Forms.PictureBox();
            this.pictureBox_Block = new System.Windows.Forms.PictureBox();
            this.pictureBox_Ground_BottomRight = new System.Windows.Forms.PictureBox();
            this.pictureBox_Ground_BottomCenter = new System.Windows.Forms.PictureBox();
            this.pictureBox_Ground_BottomLeft = new System.Windows.Forms.PictureBox();
            this.pictureBox_Ground_CenterRight = new System.Windows.Forms.PictureBox();
            this.pictureBox_Ground_CenterCenter = new System.Windows.Forms.PictureBox();
            this.pictureBox_Ground_CenterLeft = new System.Windows.Forms.PictureBox();
            this.pictureBox_Ground_TopRight = new System.Windows.Forms.PictureBox();
            this.pictureBox_Ground_TopCenter = new System.Windows.Forms.PictureBox();
            this.pictureBox_Ground_TopLeft = new System.Windows.Forms.PictureBox();
            this.pictureBox_Mario = new System.Windows.Forms.PictureBox();
            this.gb_Tiles.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Empty)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_SpecialBlock)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Block)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Ground_BottomRight)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Ground_BottomCenter)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Ground_BottomLeft)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Ground_CenterRight)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Ground_CenterCenter)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Ground_CenterLeft)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Ground_TopRight)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Ground_TopCenter)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Ground_TopLeft)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Mario)).BeginInit();
            this.SuspendLayout();
            // 
            // gb_Tiles
            // 
            this.gb_Tiles.Controls.Add(this.pictureBox_Mario);
            this.gb_Tiles.Controls.Add(this.button_CreateXML);
            this.gb_Tiles.Controls.Add(this.pictureBox_Empty);
            this.gb_Tiles.Controls.Add(this.pictureBox_SpecialBlock);
            this.gb_Tiles.Controls.Add(this.pictureBox_Block);
            this.gb_Tiles.Controls.Add(this.pictureBox_Ground_BottomRight);
            this.gb_Tiles.Controls.Add(this.pictureBox_Ground_BottomCenter);
            this.gb_Tiles.Controls.Add(this.pictureBox_Ground_BottomLeft);
            this.gb_Tiles.Controls.Add(this.pictureBox_Ground_CenterRight);
            this.gb_Tiles.Controls.Add(this.pictureBox_Ground_CenterCenter);
            this.gb_Tiles.Controls.Add(this.pictureBox_Ground_CenterLeft);
            this.gb_Tiles.Controls.Add(this.pictureBox_Ground_TopRight);
            this.gb_Tiles.Controls.Add(this.pictureBox_Ground_TopCenter);
            this.gb_Tiles.Controls.Add(this.pictureBox_Ground_TopLeft);
            this.gb_Tiles.Controls.Add(this.comboBox_Theme);
            this.gb_Tiles.Controls.Add(this.label_Theme);
            this.gb_Tiles.Location = new System.Drawing.Point(13, 13);
            this.gb_Tiles.Name = "gb_Tiles";
            this.gb_Tiles.Size = new System.Drawing.Size(284, 737);
            this.gb_Tiles.TabIndex = 0;
            this.gb_Tiles.TabStop = false;
            this.gb_Tiles.Text = "Tiles";
            // 
            // comboBox_Theme
            // 
            this.comboBox_Theme.FormattingEnabled = true;
            this.comboBox_Theme.Items.AddRange(new object[] {
            "Landscape",
            "Dungeon",
            "Sky",
            "Water"});
            this.comboBox_Theme.Location = new System.Drawing.Point(72, 19);
            this.comboBox_Theme.Name = "comboBox_Theme";
            this.comboBox_Theme.Size = new System.Drawing.Size(145, 24);
            this.comboBox_Theme.TabIndex = 1;
            this.comboBox_Theme.SelectedIndexChanged += new System.EventHandler(this.comboBox_Theme_SelectedIndexChanged);
            // 
            // label_Theme
            // 
            this.label_Theme.AutoSize = true;
            this.label_Theme.Location = new System.Drawing.Point(7, 22);
            this.label_Theme.Name = "label_Theme";
            this.label_Theme.Size = new System.Drawing.Size(56, 17);
            this.label_Theme.TabIndex = 0;
            this.label_Theme.Text = "Theme:";
            // 
            // hScrollBar
            // 
            this.hScrollBar.Location = new System.Drawing.Point(303, 751);
            this.hScrollBar.Name = "hScrollBar";
            this.hScrollBar.Size = new System.Drawing.Size(1223, 21);
            this.hScrollBar.TabIndex = 12;
            this.hScrollBar.Scroll += new System.Windows.Forms.ScrollEventHandler(this.hScrollBar_Scroll);
            // 
            // button_CreateXML
            // 
            this.button_CreateXML.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.button_CreateXML.Location = new System.Drawing.Point(3, 702);
            this.button_CreateXML.Name = "button_CreateXML";
            this.button_CreateXML.Size = new System.Drawing.Size(278, 32);
            this.button_CreateXML.TabIndex = 15;
            this.button_CreateXML.Text = "Create XML";
            this.button_CreateXML.UseVisualStyleBackColor = true;
            this.button_CreateXML.Click += new System.EventHandler(this.button_CreateXML_Click);
            // 
            // panel
            // 
            this.panel.BackgroundImage = global::Levelbuilder.Properties.Resources.backgroundSky;
            this.panel.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.panel.Location = new System.Drawing.Point(303, 13);
            this.panel.Name = "panel";
            this.panel.Size = new System.Drawing.Size(1223, 737);
            this.panel.TabIndex = 11;
            this.panel.Paint += new System.Windows.Forms.PaintEventHandler(this.panel_Paint);
            this.panel.MouseClick += new System.Windows.Forms.MouseEventHandler(this.panel_MouseClick);
            // 
            // pictureBox_Empty
            // 
            this.pictureBox_Empty.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox_Empty.Location = new System.Drawing.Point(206, 71);
            this.pictureBox_Empty.Name = "pictureBox_Empty";
            this.pictureBox_Empty.Size = new System.Drawing.Size(32, 32);
            this.pictureBox_Empty.TabIndex = 14;
            this.pictureBox_Empty.TabStop = false;
            this.pictureBox_Empty.Click += new System.EventHandler(this.pictureBox_Click);
            // 
            // pictureBox_SpecialBlock
            // 
            this.pictureBox_SpecialBlock.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox_SpecialBlock.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox_SpecialBlock.Image")));
            this.pictureBox_SpecialBlock.Location = new System.Drawing.Point(172, 71);
            this.pictureBox_SpecialBlock.Name = "pictureBox_SpecialBlock";
            this.pictureBox_SpecialBlock.Size = new System.Drawing.Size(32, 32);
            this.pictureBox_SpecialBlock.TabIndex = 13;
            this.pictureBox_SpecialBlock.TabStop = false;
            this.pictureBox_SpecialBlock.Click += new System.EventHandler(this.pictureBox_Click);
            // 
            // pictureBox_Block
            // 
            this.pictureBox_Block.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox_Block.Image = global::Levelbuilder.Properties.Resources.Block;
            this.pictureBox_Block.Location = new System.Drawing.Point(138, 71);
            this.pictureBox_Block.Name = "pictureBox_Block";
            this.pictureBox_Block.Size = new System.Drawing.Size(32, 32);
            this.pictureBox_Block.TabIndex = 12;
            this.pictureBox_Block.TabStop = false;
            this.pictureBox_Block.Click += new System.EventHandler(this.pictureBox_Click);
            // 
            // pictureBox_Ground_BottomRight
            // 
            this.pictureBox_Ground_BottomRight.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox_Ground_BottomRight.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox_Ground_BottomRight.Image")));
            this.pictureBox_Ground_BottomRight.Location = new System.Drawing.Point(73, 137);
            this.pictureBox_Ground_BottomRight.Name = "pictureBox_Ground_BottomRight";
            this.pictureBox_Ground_BottomRight.Size = new System.Drawing.Size(32, 32);
            this.pictureBox_Ground_BottomRight.TabIndex = 10;
            this.pictureBox_Ground_BottomRight.TabStop = false;
            this.pictureBox_Ground_BottomRight.Click += new System.EventHandler(this.pictureBox_Click);
            // 
            // pictureBox_Ground_BottomCenter
            // 
            this.pictureBox_Ground_BottomCenter.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox_Ground_BottomCenter.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox_Ground_BottomCenter.Image")));
            this.pictureBox_Ground_BottomCenter.Location = new System.Drawing.Point(40, 137);
            this.pictureBox_Ground_BottomCenter.Name = "pictureBox_Ground_BottomCenter";
            this.pictureBox_Ground_BottomCenter.Size = new System.Drawing.Size(32, 32);
            this.pictureBox_Ground_BottomCenter.TabIndex = 9;
            this.pictureBox_Ground_BottomCenter.TabStop = false;
            this.pictureBox_Ground_BottomCenter.Click += new System.EventHandler(this.pictureBox_Click);
            // 
            // pictureBox_Ground_BottomLeft
            // 
            this.pictureBox_Ground_BottomLeft.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox_Ground_BottomLeft.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox_Ground_BottomLeft.Image")));
            this.pictureBox_Ground_BottomLeft.Location = new System.Drawing.Point(7, 137);
            this.pictureBox_Ground_BottomLeft.Name = "pictureBox_Ground_BottomLeft";
            this.pictureBox_Ground_BottomLeft.Size = new System.Drawing.Size(32, 32);
            this.pictureBox_Ground_BottomLeft.TabIndex = 8;
            this.pictureBox_Ground_BottomLeft.TabStop = false;
            this.pictureBox_Ground_BottomLeft.Click += new System.EventHandler(this.pictureBox_Click);
            // 
            // pictureBox_Ground_CenterRight
            // 
            this.pictureBox_Ground_CenterRight.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox_Ground_CenterRight.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox_Ground_CenterRight.Image")));
            this.pictureBox_Ground_CenterRight.Location = new System.Drawing.Point(73, 104);
            this.pictureBox_Ground_CenterRight.Name = "pictureBox_Ground_CenterRight";
            this.pictureBox_Ground_CenterRight.Size = new System.Drawing.Size(32, 32);
            this.pictureBox_Ground_CenterRight.TabIndex = 7;
            this.pictureBox_Ground_CenterRight.TabStop = false;
            this.pictureBox_Ground_CenterRight.Click += new System.EventHandler(this.pictureBox_Click);
            // 
            // pictureBox_Ground_CenterCenter
            // 
            this.pictureBox_Ground_CenterCenter.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox_Ground_CenterCenter.Image = global::Levelbuilder.Properties.Resources.groundCenterCenter;
            this.pictureBox_Ground_CenterCenter.Location = new System.Drawing.Point(40, 104);
            this.pictureBox_Ground_CenterCenter.Name = "pictureBox_Ground_CenterCenter";
            this.pictureBox_Ground_CenterCenter.Size = new System.Drawing.Size(32, 32);
            this.pictureBox_Ground_CenterCenter.TabIndex = 6;
            this.pictureBox_Ground_CenterCenter.TabStop = false;
            this.pictureBox_Ground_CenterCenter.Click += new System.EventHandler(this.pictureBox_Click);
            // 
            // pictureBox_Ground_CenterLeft
            // 
            this.pictureBox_Ground_CenterLeft.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox_Ground_CenterLeft.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox_Ground_CenterLeft.Image")));
            this.pictureBox_Ground_CenterLeft.Location = new System.Drawing.Point(7, 104);
            this.pictureBox_Ground_CenterLeft.Name = "pictureBox_Ground_CenterLeft";
            this.pictureBox_Ground_CenterLeft.Size = new System.Drawing.Size(32, 32);
            this.pictureBox_Ground_CenterLeft.TabIndex = 5;
            this.pictureBox_Ground_CenterLeft.TabStop = false;
            this.pictureBox_Ground_CenterLeft.Click += new System.EventHandler(this.pictureBox_Click);
            // 
            // pictureBox_Ground_TopRight
            // 
            this.pictureBox_Ground_TopRight.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox_Ground_TopRight.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox_Ground_TopRight.Image")));
            this.pictureBox_Ground_TopRight.Location = new System.Drawing.Point(73, 71);
            this.pictureBox_Ground_TopRight.Name = "pictureBox_Ground_TopRight";
            this.pictureBox_Ground_TopRight.Size = new System.Drawing.Size(32, 32);
            this.pictureBox_Ground_TopRight.TabIndex = 4;
            this.pictureBox_Ground_TopRight.TabStop = false;
            this.pictureBox_Ground_TopRight.Click += new System.EventHandler(this.pictureBox_Click);
            // 
            // pictureBox_Ground_TopCenter
            // 
            this.pictureBox_Ground_TopCenter.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox_Ground_TopCenter.Image = global::Levelbuilder.Properties.Resources.groundTopCenter;
            this.pictureBox_Ground_TopCenter.Location = new System.Drawing.Point(40, 71);
            this.pictureBox_Ground_TopCenter.Name = "pictureBox_Ground_TopCenter";
            this.pictureBox_Ground_TopCenter.Size = new System.Drawing.Size(32, 32);
            this.pictureBox_Ground_TopCenter.TabIndex = 3;
            this.pictureBox_Ground_TopCenter.TabStop = false;
            this.pictureBox_Ground_TopCenter.Click += new System.EventHandler(this.pictureBox_Click);
            // 
            // pictureBox_Ground_TopLeft
            // 
            this.pictureBox_Ground_TopLeft.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox_Ground_TopLeft.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox_Ground_TopLeft.Image")));
            this.pictureBox_Ground_TopLeft.Location = new System.Drawing.Point(7, 71);
            this.pictureBox_Ground_TopLeft.Name = "pictureBox_Ground_TopLeft";
            this.pictureBox_Ground_TopLeft.Size = new System.Drawing.Size(32, 32);
            this.pictureBox_Ground_TopLeft.TabIndex = 2;
            this.pictureBox_Ground_TopLeft.TabStop = false;
            this.pictureBox_Ground_TopLeft.Click += new System.EventHandler(this.pictureBox_Click);
            // 
            // pictureBox_Mario
            // 
            this.pictureBox_Mario.BackgroundImage = global::Levelbuilder.Properties.Resources.Mario;
            this.pictureBox_Mario.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox_Mario.Location = new System.Drawing.Point(7, 196);
            this.pictureBox_Mario.Name = "pictureBox_Mario";
            this.pictureBox_Mario.Size = new System.Drawing.Size(32, 32);
            this.pictureBox_Mario.TabIndex = 16;
            this.pictureBox_Mario.TabStop = false;
            this.pictureBox_Mario.Click += new System.EventHandler(this.pictureBox_Click);
            // 
            // MainForm
            // 
            this.ClientSize = new System.Drawing.Size(1538, 840);
            this.Controls.Add(this.hScrollBar);
            this.Controls.Add(this.panel);
            this.Controls.Add(this.gb_Tiles);
            this.KeyPreview = true;
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.MainForm_KeyDown);
            this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.MainForm_KeyUp);
            this.gb_Tiles.ResumeLayout(false);
            this.gb_Tiles.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Empty)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_SpecialBlock)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Block)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Ground_BottomRight)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Ground_BottomCenter)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Ground_BottomLeft)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Ground_CenterRight)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Ground_CenterCenter)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Ground_CenterLeft)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Ground_TopRight)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Ground_TopCenter)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Ground_TopLeft)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_Mario)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox gb_Tiles;
        private System.Windows.Forms.ComboBox comboBox_Theme;
        private System.Windows.Forms.Label label_Theme;
        private System.Windows.Forms.PictureBox pictureBox_Ground_BottomRight;
        private System.Windows.Forms.PictureBox pictureBox_Ground_BottomCenter;
        private System.Windows.Forms.PictureBox pictureBox_Ground_BottomLeft;
        private System.Windows.Forms.PictureBox pictureBox_Ground_CenterRight;
        private System.Windows.Forms.PictureBox pictureBox_Ground_CenterCenter;
        private System.Windows.Forms.PictureBox pictureBox_Ground_CenterLeft;
        private System.Windows.Forms.PictureBox pictureBox_Ground_TopRight;
        private System.Windows.Forms.PictureBox pictureBox_Ground_TopCenter;
        private System.Windows.Forms.PictureBox pictureBox_Ground_TopLeft;
        private System.Windows.Forms.Panel panel;
        private System.Windows.Forms.HScrollBar hScrollBar;
        private System.Windows.Forms.PictureBox pictureBox_SpecialBlock;
        private System.Windows.Forms.PictureBox pictureBox_Block;
        private System.Windows.Forms.PictureBox pictureBox_Empty;
        private System.Windows.Forms.Button button_CreateXML;
        private System.Windows.Forms.PictureBox pictureBox_Mario;
    }
}

