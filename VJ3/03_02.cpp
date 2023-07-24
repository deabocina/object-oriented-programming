#include <iostream>
#include <vector>
using namespace std;

// 1. Write a class representing a weapon.The weapon has its position in space(a single point in 3D space), 
// the number of bullets that fit in one magazine, and the current number of bullets in the magazine.
// It can shoot(shoot) and be reloaded(reload).
//
// 2. Write a class representing a target.The target is in the shape of a cuboid and is defined by its 
// bottom - left and top - right points.It has two states : hit and unhit.
//
// 3. Write a program that will generate n targets and one shooter (weapon).Assuming that the position of 
// the weapon is horizontal and that the weapon can rotate 360 degrees, calculate how many targets are hit with a single magazine.

class Point {
private:
	double x = 0, y = 0, z = 0;
public:
	void setCoordinates() {
		cout << "Enter x, y, and z values: ";
		cin >> x >> y >> z;
	}

	void setRandom(double start, double stop) {
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

class Weapon {
public:
	Point position;
	int magazine = 20, bullets = 9;

	void shoot() {
		if (bullets != 0) {
			bullets--;
		}
		else {
			cout << "Magazine is empty.\n";
		}
	}

	void report() {
		cout << bullets;
	}

	void reload() {
		bullets = magazine;
		cout << "Magazine is full.\n";
	}
};

class Target {
public:
	Point bottomLeft, topRight;
	string state = "untouched";

	void changeState() {
		state = "hit";
	}
};

int main() {
	srand(time(NULL));

	int n = 0, shot, counter = 0, choice;
	double start, stop;
	cout << "Enter lower and upper bounds of the interval: ";
	cin >> start >> stop;

	cout << "Enter the number of targets you want: ";
	cin >> n;

	Weapon AK47;
	AK47.position.setRandom(start, stop);

	vector<Target> CT;
	for (int i = 0; i < n; i++) {
		Target target;
		target.bottomLeft.setRandom(start, stop);
		target.topRight.setRandom(start, stop);
		CT.push_back(target);
	}

	for (;;) {
		for (; AK47.bullets > 0; AK47.shoot()) {
			shot = rand() % (n + n / 4);
			if (shot < n) {
				CT[shot].changeState();
			}
		}

		AK47.reload();

		for (Target i : CT) {
			if (i.state.compare("hit") == 0) {
				counter++;
			}
		}

		cout << "Number of hits: " << counter << " targets.\n";
		counter = 0;
		cout << "Do you want to continue? 0 - No, 1 - Yes: ";
		cin >> choice;

		if (choice == 0) {
			break;
		}
	}
	return 0;
}