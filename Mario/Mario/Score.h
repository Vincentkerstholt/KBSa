#include <string>

using namespace std;

class Score
{
public:
	Score();
	void setScore(string score);
	int getScore();
	string toString();
private:
	string strScore;
	int intScore;
};