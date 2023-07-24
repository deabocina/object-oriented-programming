#include <iostream>
#include <cmath>
using namespace std;

// Write a class for representing a point in 3D space, which has three double data members : length, width, and height(x, y, z coordinates).
// The class should have the following functions:
//
// A function to set the values of the members(with default values of 0).
// A function to set pseudo - random values for the members(with interval bounds as parameters).
// A function to retrieve the values of the members.
// A function to calculate the distance to another point in 2D space(ignoring the z coordinate).
// A function to calculate the distance to another point in 3D space.

class Point {
private:
	double x = 0, y = 0, z = 0;
public:
	void setCoordinates() {
		cout << "Enter x, y, and z values: ";
		cin >> x >> y >> z;
	}

	void setRandom() {
		double start, stop;
		cout << "Enter lower and upper bounds of the interval: ";
		cin >> start >> stop;
		x = start + (double)rand() / RAND_MAX * (stop - start);
		y = start + (double)rand() / RAND_MAX * (stop - start);
		z = start + (double)rand() / RAND_MAX * (stop - start);
	}

	void display() {
		cout << x << " " << y << " " << z << "\n";
	}

	double distance2D(Point point2) {
		return sqrt(pow(point2.x - x, 2) + pow(point2.y - y, 2));
	}

	double distance3D(Point point2) {
		return sqrt(pow(point2.x - x, 2) + pow(point2.y - y, 2) + pow(point2.z - z, 2));
	}
};

int main() {
	srand(time(NULL));
	Point point1, point2;

	point1.setCoordinates();
	point1.display();
	point1.setRandom();
	point1.display();

	point2.setCoordinates();
	point2.display();
	point2.setRandom();
	point2.display();

	cout << point1.distance2D(point2) << "\n";
	cout << point2.distance2D(point1) << "\n";
	cout << point1.distance3D(point2) << "\n";
	cout << point2.distance3D(point1) << "\n";

	return 0;
}