#include <string>

using namespace std;

class Score
{
public:
	void setScore(char * score);
	int getScore();
	string toString();
private:
	string strScore;
	int intScore;
};