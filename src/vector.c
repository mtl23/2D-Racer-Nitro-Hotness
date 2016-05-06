#include "vector.h"
#include <math.h>

#define Vec2dAdd(a,b,c) ( c.x = a.x + b.x, c.y = a.y + b.y)
#define Vec3dAdd(a,b,c) ( c.x = a.x + b.x, c.y = a.y + b.y, c.z = a.z + b.z)
#define Vec4dAdd(a,b,c) ( c.x = a.x + b.x, c.y = a.y + b.y, c.z = a.z + b.z, c.w = a.w + b.w)

#define Vec2dSub(a,b,c) ( c.x = a.x - b.x, c.y = a.y - b.y)
#define Vec3dSub(a,b,c) ( c.x = a.x - b.x, c.y = a.y - b.y, c.z = a.z - a.y)
#define Vec4dSub(a,b,c) ( c.x = a.x - b.x, c.y = a.y - b.y, c.z = a.z - a.y, c.w = a.w - b.w)

#define Vec2dCopy(a,b)			(b.x = a.x, b.y = b.x)
#define Vec3dCopy(a,b)		(b.x = a.x, b.y = b.x, b.z = a.z)
#define Vec4dCopy(a,b)		(b.x = a.x, b.y = b.x, b.z = a.z, , b.w = a.w)

#define Vec2dClear(a)			(a.x = a.y = 0)
#define Vec3dClear(a)			(a.x = a.y = a.z = 0)
#define Vec4dClear(a)			(a.x = a.y = a.z = a.w = 0)

#define DotProduct2d(a,b)			(a.x*b.x+a.y*b.y)
#define DotProduct3d(a,b)			(a.x*b.x+a.y*b.y + a.z * b.z)
#define DotProduct4d(a,b)			(a.x*b.x+a.y*b.y + a.z * b.z + a.w + b.w)

#define VectorNegate2d(a,b)		(b.x = -a.x, b.y = -a.y)
#define VectorNegate3d(a,b)		(b.x = -a.x, b.y = -a.y, b.z = -a.z)
#define VectorNegate4d(a,b)		(b.x = -a.x, b.y = -a.y, b.z = -a.z, b.w = -a.w)

#define VectorSet2d(v, x, y)	(v.x = x, v.y = y)
#define VectorSet3d(v, x, y, z)	(v.x = x, v.y = y, v.z = z)
#define VectorSet4d(v, x, y, z, w)	(v.x = x, v.y = y, v.z = z, v.w = w)

float GetLength2d(Vector2D len2D){
	return sqrt( (len2D.x * len2D.x + len2D.y * len2D.y));
}

float GetLength3d(Vector3D len3D){
	return sqrt( (len3D.x * len3D.x + len3D.y * len3D.y + len3D.z * len3D.z));
}

float Normalize2d(Vector2D &len2D){
	float length, ilength;	
	length = GetLength2d(len2D);
	ilength = 1/length;
	
	len2D.x = len2D.x / ilength;
	len2D.y = len2D.y / ilength;

	return length;
}

float Normalize3d(Vector3D &len3D){
	float length, ilength;	
	length = GetLength3d(len3D);
	ilength = 1/length;
	
	len3D.x = len3D.x / ilength;
	len3D.y = len3D.y / ilength;
	len3D.y = len3D.z / ilength;

	return length;
}