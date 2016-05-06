#ifndef __VECTOR_H__
#define __VECTOR_H__

/**
* @brief a simple 2d vector structure
*/
typedef struct{

float x; /**<the x component of the vector */ 
float y; /**<the y component of the vector */

}Vector2D;

/**
* @brief a simple 3d vector structure
*/
typedef struct{

union { float x;    /**<the x component of the vector */
		float r; }; /**<the red component of the color */

union { float y;  /**<the y component of the vector */
		float g; };/**<the green component of the color */

union { float z;  /**<the z component of the vector */
		float b; };/**<the blue component of the color */

}Vector3D;

/**
* @brief a simple 4d vector structure
*/
typedef struct{

union { float x;  /**<the x component of the vector */ 
		float r; }; /**<the red component of the color */
union { float y; /**<the y component of the vector */
		float g; }; /**<the green component of the color */
union { float z; /**<the z component of the vector */
		float b; }; /**<the blue component of the color */
union { float w;  /**<the w component of the vector */
		float a; };/**<the alpha component of the color */

				}Vector4D;

float GetLength2d(Vector2D len2D);
float GetLength3d(Vector3D len3D);

#define ZERO 0
#define Vector2D_add(a,b,c) (c.x=a.x+b.x,c.y=a.y+b.y)
#define Vector3D_add(a,b,c) (c.x=a.x+b.x,c.y=a.y+b.y,c.z=a.z+b.z)
#define Vector4D_add(a,b,c) (c.x=a.x+b.x,c.y=a.y+b.y,c.z=a.z+b.z,c.w=a.w+b.w)
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
typedef struct{

	int x,y,h,w;

				}rect;

/**
* @brief a simple circle structure
*/
typedef struct{

	int x,y,r;
			}circle;

/**
* @brief a simple triangle structure
*/
typedef struct{

	Vector2D v1,v2,v3;
			}triange;
enum shape
{
	Shape_RECT,
	Shape_CIRCLE,
	Shape_TRIANGLE
};
#endif

//multiply
//
//
