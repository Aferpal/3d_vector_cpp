#include"Point.h"

Point3D::Point3D(float x, float y, float z): x(x), y(y), z(z){}
Point3D::Point3D(const Point3D& other): Point3D(other.x, other.y, other.z){}
Point3D::Point3D(Point3D&& other): Point3D(other.x, other.y, other.z){}

float Point3D::getX() const { 
	return this->x;
}

float Point3D::getY() const {
	return this->y;
}

float Point3D::getZ() const {
	return this->z;
}

void Point3D::setX( float newX ){
	this->x = newX;
}

void Point3D::setY( float newY ){
	this->y=newY;
}

void Point3D::setZ( float newZ ){
	this->z=newZ;
}

