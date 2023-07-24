#include "Board.hpp"
#include "Point.hpp"
#include <iostream>
#include <vector>
using namespace std;

// Define a class "Board" that will serve as a frame for drawing characters. The Board is a matrix whose dimensions 
// are specified in the constructor, and memory is allocated on the heap for it. The Board has a border that consists 
// of a certain character determined in the constructor.

int main() {
    int rows = 0, columns = 0;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> columns;

    Board board(rows, columns);
    Point point1, point2;

    for (;;) {
        cout << "Enter the x-coordinate of the first point: ";
        cin >> point1.x;
        cout << "Enter the y-coordinate of the first point: ";
        cin >> point1.y;

        if (point1.x == 0 && point1.y == 0) {
            break;
        }
        if (point1.x <= 1 || point1.x >= rows - 1 || point1.y <= 1 || point1.y >= columns - 1) {
            cout << "Coordinates are not entered correctly.\n";
            continue;
        }
        cout << "Enter the x-coordinate of the second point: ";
        cin >> point2.x;
        cout << "Enter the y-coordinate of the second point: ";
        cin >> point2.y;

        if (point2.x == 0 && point2.y == 0) {
            break;
        }
        if (point2.x <= 1 || point2.x >= rows - 1 || point2.y <= 1 || point2.y >= columns - 1) {
            cout << "Coordinates are not entered correctly.\n";
            continue;
        }
        board.drawLine(point1, point2, 'x');
        board.printBoard(board, rows, columns);
    }
}