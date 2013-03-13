using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Levelbuilder
{
    abstract class Gameobject
    {
        public abstract Image getImage();
    }
    
    class Ground : Gameobject
    {
        public string groundType { get; set; }

        public override Image getImage()
        {
            Image returnImage = null;
            switch (groundType)
            {
                case "TopLeft":
                    returnImage = Properties.Resources.groundTopLeft;
                    break;
                case "TopCenter":
                    returnImage = Properties.Resources.groundTopCenter;
                    break;
                case "TopRight":
                    returnImage = Properties.Resources.groundTopRight;
                    break;
                case "CenterLeft":
                    returnImage = Properties.Resources.groundCenterLeft;
                    break;
                case "CenterCenter":
                    returnImage = Properties.Resources.groundCenterCenter;
                    break;
                case "CenterRight":
                    returnImage = Properties.Resources.groundCenterRight;
                    break;
                case "BottomLeft":
                    returnImage = Properties.Resources.groundBottomLeft;
                    break;
                case "BottomCenter":
                    returnImage = Properties.Resources.groundBottomCenter;
                    break;
                case "BottomRight":
                    returnImage = Properties.Resources.groundBottomRight;
                    break;
            }
            return returnImage;
        }
    }

    class Pipe : Gameobject
    {
        public string pipeType { get; set; }
        public override Image getImage()
        {
            Image returnImage = null;
            switch (pipeType)
            {
                case "TopLeft":

                    break;

                case "TopCenter":

                    break;

                case "TopRight":

                    break;

                case "Left":

                    break;

                case "Center":

                    break;

                case "Right":

                    break;
            }

            return returnImage;
        }
    }

    class Block : Gameobject
    {
        public bool isSpecial { get; set; }
        public override Image getImage()
        {
            if (isSpecial)
                return Properties.Resources.SpecialBlock;
            return Properties.Resources.Block;
        }

    }

    class Hero : Gameobject
    {
        public string character { get; set; }
        public override Image getImage()
        {
            Image returnImage = null;
            switch (character)
            {
                case "Mario":
                    returnImage = Properties.Resources.Mario;
                    break;
            }

            return returnImage;
        }
    }
}
