#ifndef VECTOR_H
#define VECTOR_H
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <string>

namespace Math
{

#ifndef SMALLEST
#define SMALLEST 1.e-7f
#endif

#ifndef DEG_TO_RAD 
#define DEG_TO_RAD (M_PI / 180.0f)
#endif

	struct Vec2
	{
		float x, y;
		//Load
		inline void load(float x_, float y_)
		{
			x = x_;
			y = y_;
		}
		//Default constructor
		inline Vec2(float n = float(0.0f))
		{
			load(n, n);
		}
		//Default load constructor 
		inline Vec2(float x_, float y_)
		{
			load(x_, y_);
		}
		//Copy Constructor
		inline Vec2(const Vec2 &a_)
		{
			load(a_.x, a_.y);
		}
		//Vec2 Array
		const float operator[] (int index_)const
		{
			return *(&x + index_);
		}
		//Array 
		float& operator [] (int index_)
		{
			return *(&x + index_);
		}
		//Override =
		inline  Vec2& operator =(const Vec2& a_)
		{
			load(a_.x, a_.y);
			return *this;
		}
		//Override +
		inline const Vec2  operator +(const Vec2 &a_) const
		{
			return Vec2(x + a_.x, y + a_.y);
		}
		//Override +=
		inline const Vec2 operator +=(const Vec2 &a_)
		{
			x += a_.x;
			y += a_.y;
			return *this;
		}
		//Override -
		inline const Vec2 operator -(const Vec2 &a_) const
		{
			return Vec2(x - a_.x, y - a_.y);
		}
		//Override -=
		inline const Vec2 operator -=(const Vec2 &a_)
		{
			x -= a_.x;
			y -= a_.y;
			return *this;

		}
		//Override -(negative)
		inline const Vec2 operator -() const
		{
			return Vec2(-x, -y);
		}
		//Override *
		inline const Vec2 operator *(const float s_) const 
		{
			return Vec2(s_ * x, s_ * y);
		}
		//Override *
		inline friend Vec2 operator *(const float s_, const Vec2 &a_)
		{
			return a_ * s_;
		}
		//Override *=
		inline Vec2& operator *=(const float s_)
		{
			x *= s_;
			y *= s_;
			return *this;
		}
		//Override /
		inline const Vec2 operator /(const float s_) const
		{
			//check if the numebr is to small to divide 
			if (std::fabs(s_) < 1.0e-7)
			{
				std::string errMsg("Number is to small to divide");
				throw errMsg;
			}
			return Vec2(x / s_, y / s_);
		}
		//Override /=
		inline const Vec2 operator /=(const float s_)
		{
			//check if the numebr is to small to divide 
			if (std::fabs(s_) < 1.0e-7)
			{
				std::string errMsg("Number is to small to divide");
				throw errMsg;
			}
			x /= s_;
			y /= s_;
			return *this;
		}
		//Override ==
		inline const bool operator ==(const Vec2 &a_) const
		{
			return(x == a_.x, y == a_.y);
		}
		//Override !=
		inline const bool operator !=(const Vec2 &a_) const
		{
			return(x != a_.x, y != a_.y);
		}
		//Override >= 
		inline const bool operator >=(const Vec2 &a_) const
		{
			return(x >= a_.x || y >= a_.y);
		}
		//Override <=
		inline const bool operator <=(const Vec2 &a_) const
		{
			return(x <= a_.x || y <= a_.y);
		}

	};
	struct Vec3 : public Vec2
	{
		float z;
		//load 
		inline void load(float x_, float y_, float z_)
		{
			x = x_;
			y = y_;
			z = z_;
		}
		//Defualt Constructor 
		inline Vec3(float n_ = float(0.0f))
		{
			x = n_;
			y = n_;
			z = n_;
		}
		//Load Constructor
		inline Vec3(float x_, float y_, float z_)
		{
			load(x_, y_, z_);
		}
		//Load Constructor 
		inline Vec3(const Vec3 &a_)
		{
			load(a_.x, a_.y, a_.z);
		}
		//Vec3 Array 
		const float operator [](int index_) const
		{
			return *(&x + index_);
		}
		//Array
		float& operator [] (int index_)
		{
			return *(&x + index_);
		}
		//Override =
		inline Vec3& operator =(const Vec3 &a_)
		{
			load(a_.x, a_.y, a_.x);
			return *this;
		}
		//Override +
		inline const Vec3 operator +(const Vec3 &a_)const
		{
			return Vec3(x + a_.x, y + a_.y, z + a_.z);
		}
		//Override  +=
		inline const Vec3 operator +=(const Vec3 &a_)
		{
			x += a_.x;
			y += a_.y;
			z += a_.z;
			return *this;
		}
		//Override -
		inline const Vec3 operator -(const Vec3 &a_) const
		{
			return Vec3(x - a_.x, y - a_.y, z - a_.z);
		}
		//Override -=
		inline Vec3& operator -=(const Vec3 &a_)
		{
			x -= a_.x;
			y -= a_.y;
			z -= a_.z;
			return *this;
		}
		//Override *
		inline const Vec3 operator *(const float s_) const
		{
			return Vec3(x * s_, y * s_, z * s_);
		}
		//Override *
		inline friend Vec3 operator *(const float s_, const Vec3& a_)
		{
			return a_ * s_;
		}
		//Override /
		inline const Vec3 operator /(const float s_) const
		{
			//check if the number that is being divided is 0 or close to 0.
			if (std::fabs(s_) < 1.0e-7)
			{
				std::string errMsg("Dividing by or nearly 0");
				throw errMsg;
			}
			return Vec3(x / s_, x / s_, z / s_);
		}
		//Override /=
		inline Vec3& operator /=(const float s_)
		{
			//check if the number that is being divided is 0 or close to 0.
			if (std::fabs(s_) < 1.0e-7)
			{
				std::string errMsg("Dividing by or nearly 0");
				throw errMsg;
			}
			x /= s_;
			y /= s_;
			z /= s_;
			return *this;
		}
		//Override ==
		inline const bool operator ==(const Vec3 &a_) const
		{
			return(x == a_.x, y == a_.y, z == a_.z);
		}
		//Override  !=
		inline const bool operator !=(const Vec3 &a_) const
		{
			return(x != a_.x, y != a_.y, z != a_.z);
		}
		//Override <=
		inline const bool operator <=(const Vec3 &a_) const
		{
			return(x <= a_.x || y <= a_.y || z <= a_.z);
		}
		//Override >=
		inline const bool operator >=(const Vec3 &a_) const
		{
			return(x >= a_.x || y >= a_.y || z >= a_.z);
		}
	};
};

#endif
