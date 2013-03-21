#include "Camera.h"

Camera::Camera()
{
	XPoint = 0;
	xPos = 0;
	mid = false;
}

int Camera::getXPosition()
{
	if (mid == true)
	{
		if ( xPos > MIDDLE )
		{
			if ( xPos - MIDDLE > 5454)
				return 5454;
			return xPos - MIDDLE;
		}
		if (XPoint != 0)
			if ( *XPoint > MIDDLE )
				return *XPoint - MIDDLE;

		return 0;
	}

	if ( xPos > 0)
		return xPos;
	
	if ( *XPoint > 0 )
		return *XPoint;


	return 0;
}

void Camera::setXPosition(int x)
{
	xPos = x;
	XPoint = 0;
	mid = false;
}

void Camera::setXMidPosition(int x)
{
	xPos = x;
	XPoint = 0;
	mid = true;
}

void Camera::setXPointPosition(int * x)
{
	XPoint = x;
	xPos = 0;
	mid = false;
}

void Camera::setXPointMidPosition(int * x)
{
	XPoint = x;
	xPos = 0;
	mid = true;
}

Camera::~Camera()
{

}