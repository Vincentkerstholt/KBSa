#include "ThemeFactory.h"

class LandThemeFactory : public IThemeFactory{
public:
	Obstacle createPipe();
	Obstacle createBlock();
};