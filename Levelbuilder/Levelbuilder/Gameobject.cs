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
            switch (groundType.ToLower())
            {
                case "topleft":
                    returnImage = Properties.Resources.groundTopLeft;
                    break;
                case "topcenter":
                    returnImage = Properties.Resources.groundTopCenter;
                    break;
                case "topright":
                    returnImage = Properties.Resources.groundTopRight;
                    break;
                case "centerleft":
                    returnImage = Properties.Resources.groundCenterLeft;
                    break;
                case "centercenter":
                    returnImage = Properties.Resources.groundCenterCenter;
                    break;
                case "centerright":
                    returnImage = Properties.Resources.groundCenterRight;
                    break;
                case "bottomleft":
                    returnImage = Properties.Resources.groundBottomLeft;
                    break;
                case "bottomcenter":
                    returnImage = Properties.Resources.groundBottomCenter;
                    break;
                case "bottomright":
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
            switch (pipeType.ToLower())
            {
                case "topleft":
                    returnImage = Properties.Resources.pipeTopLeft;
                    break;

                case "topcenter":
                    returnImage = Properties.Resources.pipeTopCenter;
                    break;

                case "topright":
                    returnImage = Properties.Resources.pipeTopRight;
                    break;

                case "bottomleft":
                    returnImage = Properties.Resources.pipeBottomLeft;
                    break;

                case "bottomcenter":
                    returnImage = Properties.Resources.pipeBottomCenter;
                    break;

                case "bottomright":
                    returnImage = Properties.Resources.pipeBottomRight;
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
            switch (character.ToLower())
            {
                case "mario":
                    returnImage = Properties.Resources.Mario;
                    break;
            }

            return returnImage;
        }
    }
}
