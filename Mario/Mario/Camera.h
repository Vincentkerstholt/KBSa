#ifndef CAMERA_H
#define CAMERA_H

const int MIDDLE = 672;

class Camera
{
public:
	Camera();
	~Camera();

	void setXPosition(int x);
	void setXMidPosition(int x);
	void setXPointPosition(int * x);
	void setXPointMidPosition(int * x);
	int getXPosition();

private:

	int xPos;
	int * XPoint;
	bool mid;

};

#endif // CAMERA_H