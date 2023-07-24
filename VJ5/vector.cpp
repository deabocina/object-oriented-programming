#include "vector.hpp"
using namespace OOP;

Vec3::Vec3() {
    x = 2;
    y = 3;
    z = 1;
}

istream& OOP::operator >> (istream& is, OOP::Vec3& obj) {
    cout << "Enter x: ";
    is >> obj.x;
    cout << "Enter y: ";
    is >> obj.y;
    cout << "Enter z: ";
    is >> obj.z;
    cout << endl;
    return is;
}

ostream& OOP::operator << (ostream& os, const OOP::Vec3& obj) {
    os << obj.x << " ";
    os << obj.y << " ";
    os << obj.z << endl;
    return os;
}

Vec3 Vec3::operator = (const Vec3& obj) {
    this->x = obj.x;
    this->y = obj.y;
    this->z = obj.z;
    return *this;
}

Vec3 Vec3::operator = (float number) {
    this->x = number;
    this->y = number;
    this->z = number;
    return *this;
}

Vec3 Vec3::operator + (Vec3 const& obj) {
    Vec3 result;
    result.x = x + obj.x;
    result.y = y + obj.y;
    result.z = z + obj.z;
    return result;
}

Vec3 Vec3::operator - (Vec3 const& obj) {
    Vec3 result;
    result.x = x - obj.x;
    result.y = y - obj.y;
    result.z = z - obj.z;
    return result;
}

int Vec3::operator * (Vec3 const& obj) {
    return (this->x * obj.x + this->y * obj.y + this->z * obj.z);
}

Vec3 Vec3::operator * (float number) {
    Vec3 result;
    result.x = x * number;
    result.y = y * number;
    result.z = z * number;
    return result;
}

Vec3 Vec3::operator / (float number) {
    Vec3 result;
    result.x = x / number;
    result.y = y / number;
    result.z = z / number;
    return result;
}

Vec3 Vec3::operator += (const Vec3& obj) {
    this->x += obj.x;
    this->y += obj.y;
    this->z += obj.z;
    return *this;
}

Vec3 Vec3::operator += (float number) {
    this->x += number;
    this->y += number;
    this->z += number;
    return *this;
}

Vec3 Vec3::operator -= (const Vec3& obj) {
    this->x -= obj.x;
    this->y -= obj.y;
    this->z -= obj.z;
    return *this;
}

Vec3 Vec3::operator -= (float number) {
    this->x -= number;
    this->y -= number;
    this->z -= number;
    return *this;
}

Vec3 Vec3::operator *= (const Vec3& obj) {
    this->x *= obj.x;
    this->y *= obj.y;
    this->z *= obj.z;
    return *this;
}

Vec3 Vec3::operator *= (float number) {
    this->x *= number;
    this->y *= number;
    this->z *= number;
    return *this;
}

Vec3 Vec3::operator /= (const Vec3& obj) {
    this->x /= obj.x;
    this->y /= obj.y;
    this->z /= obj.z;
    return *this;
}

Vec3 Vec3::operator /= (float number) {
    this->x /= number;
    this->y /= number;
    this->z /= number;
    return *this;
}

void normalise(OOP::Vec3& vector) {
    float length = sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
    vector.x = vector.x / length;
    vector.y = vector.y / length;
    vector.z = vector.z / length;
}

float& Vec3::operator [] (char symbol) {
    if (symbol == 'x')
        return x;
    else if (symbol == 'y')
        return y;
    else if (symbol == 'z')
        return z;
}

Vec3::~Vec3() {

}
