#pragma once
#include <iostream>
#include <vector>
using namespace std;

namespace OOP {
    class Vec3 {
    public:
        float x, y, z;
        Vec3();
        friend istream& operator>>(istream&, Vec3& obj);
        friend ostream& operator<< (ostream& os, const Vec3& obj);
        Vec3 operator=(const Vec3& obj);
        Vec3 operator=(float number);
        Vec3 operator + (Vec3 const& obj);
        Vec3 operator - (Vec3 const& obj);
        int operator * (Vec3 const& obj);
        Vec3 operator * (float number);
        Vec3 operator / (float number);
        Vec3 operator += (const Vec3& obj);
        Vec3 operator += (float number);
        Vec3 operator -= (const Vec3& obj);
        Vec3 operator -= (float number);
        Vec3 operator *= (const Vec3& obj);
        Vec3 operator *= (float number);
        Vec3 operator /= (const Vec3& obj);
        Vec3 operator /= (float number);
        float& operator [] (char symbol);
        ~Vec3();
    };
}

void normalise(OOP::Vec3& vector);
