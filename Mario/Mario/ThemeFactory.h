#include "Obstacle.h"
#include <string>

using namespace std;

class IThemeFactory{
public:
	virtual ~IThemeFactory();
	virtual Obstacle createPipe();
	virtual Obstacle createBlock();
};