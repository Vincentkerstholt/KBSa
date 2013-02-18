#include "ThemeFactory.h"

class LandThemeFactory : public IThemeFactory{
public:
	Obstacle createPipe();
	Obstacle createBlock();
};

class LandThemeBlock : public Block{

};

class LandThemePipe : public Pipe{

};