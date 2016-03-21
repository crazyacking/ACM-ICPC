/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-06-15.53
 */
#include <queue>
#include <cstdio>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <climits>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);


class Vector3
{
    float x, y, z;
public:
    Vector3():x(0), y(0), z(0) {}
    Vector3(float x1, float y1, float z1):x(x1), y(y1), z(z1) {}
    Vector3(const Vector3 &v);
    ~Vector3();
    void operator=(const Vector3 &v);
    Vector3 operator+(const Vector3 &v);
    Vector3 operator-(const Vector3 &v);
    Vector3 operator/(const Vector3 &v);
    Vector3 operator*(const Vector3 &v);
    Vector3 operator+(float f);
    Vector3 operator-(float f);
    Vector3 operator/(float f);
    Vector3 operator*(float f);
    float dot(const Vector3 &v);
    float length();
    void normalize();
    Vector3 crossProduct(const Vector3 &v);
    void printVec3();
};


const double uZero = 1e-6;

Vector3::Vector3(const Vector3 &v):x(v.x), y(v.y), z(v.z){}

Vector3::~Vector3(){}

void Vector3::operator=(const Vector3 &v)
{
    x = v.x;
    y = v.y;
    z = v.z;
}

Vector3 Vector3::operator+(const Vector3 &v)
{
    return Vector3(x+v.x, y+v.y, z+v.z);
}

Vector3 Vector3::operator-(const Vector3 &v)
{
    return Vector3(x-v.x, y-v.y, z-v.z);
}

Vector3 Vector3::operator/(const Vector3 &v)
{
    if (fabsf(v.x) <= uZero || fabsf(v.y) <= uZero || fabsf(v.z) <= uZero)
    {
        std::cerr<<"Over flow!\n";
        return *this;
    }
    return Vector3(x/v.x, y/v.y, z/v.z);
}

Vector3 Vector3::operator*(const Vector3 &v)
{
    return Vector3(x*v.x, y*v.y, z*v.z);
}

Vector3 Vector3::operator+(float f)
{
    return Vector3(x+f, y+f, z+f);
}

Vector3 Vector3::operator-(float f)
{
    return Vector3(x-f, y-f, z-f);
}

Vector3 Vector3::operator/(float f)
{
    if (fabsf(f) < uZero)
    {
        std::cerr<<"Over flow!\n";
        return *this;
    }
    return Vector3(x/f, y/f, z/f);
}

Vector3 Vector3::operator*(float f)
{
    return Vector3(x*f, y*f, z*f);
}

float Vector3::dot(const Vector3 &v)
{
    return x*v.x + y*v.y + z*v.z;
}

float Vector3::length()
{
    return sqrtf(dot(*this));
}

void Vector3::normalize()
{
    float len = length();
    if (len < uZero) len = 1;
    len = 1/len;

    x *= len;
    y *= len;
    z *= len;
}

Vector3 Vector3::crossProduct(const Vector3 &v)
{
    return Vector3(y * v.z - z * v.y,
                   z * v.x - x * v.z,
                   x * v.y - y * v.x);
}

void Vector3::printVec3()
{
    std::cout<<"("<<x<<", "<<y<<", "<<z<<")"<<std::endl;
}

int main()
{
    int Cas;
    cin>>Cas;
    while(Cas--)
    {
        int N,M,T,S;
        cin>>N>>M>>T>>S;
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<M;++j)
                ;
        }
    }

    return 0;
}
/*

*/
