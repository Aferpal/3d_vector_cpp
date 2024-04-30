#pragma once

class Point3D{
private:
	float x, y, z;
public:
	Point3D(float, float, float);
	Point3D(const Point3D&);
	Point3D(Point3D&&);
	float getX()const;
	float getY()const;
	float getZ()const;
	void setX(float);
	void setY(float);
	void setZ(float);
	bool operator==(const Point3D& other);
};
