#include "Score.h"

void Score::setScore(char * score)
{
	strScore = score;
	int i=0, j=0;
	while ( score[i] != 0 && score[i] != ':' )
		i++;
	j=i;
	while ( score[j] != 0)
		j++;

	string strTemp = "";
	for ( int m=i+1 ; m<j ; m++ )
		strTemp += score[m];
	intScore = stoi(strTemp);
}

int Score::getScore()
{
	return intScore;
}

string Score::toString()
{
	return strScore;
}