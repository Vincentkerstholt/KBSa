#include "Score.h"

Score::Score(){
	intScore = 0;
	strScore = "";
}

void Score::setScore(string score){
	int i=0, j=0;
	// find the ':'
	while ( score[i] != 0 && score[i] != ':' )
		i++;
	j=score.length();

	strScore = score;

	// fill the intScore with the score read form the string
	string strTemp = "";
	for ( int m=i+1 ; m<j ; m++ )
		strTemp += score[m];
	intScore = stoi(strTemp);
}

int Score::getScore(){
	return intScore;
}

string Score::toString(){
	return strScore;
}