#ifndef A_H
#define A_H

class Obstacle{
public:
	void print();
private:

};
#endif

#pragma once
class Pipe : public Obstacle{
public:
	Pipe();
};

class Obstacle;

class Block : public Obstacle{
public:
	Block();
};

