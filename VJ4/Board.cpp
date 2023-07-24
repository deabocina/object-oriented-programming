#include "Point.hpp"
#include "Board.hpp"

Board::Board(int rows, int columns) {
    matrix.resize(rows);
    for (int i = 0; i < rows; i++) {
        if (i == 0 || i == rows - 1) {
            for (int j = 0; j < columns; j++) {
                matrix[i].push_back('0');
            }
        }
        else {
            matrix[i].push_back('0');
            for (int j = 1; j < columns - 1; j++) {
                matrix[i].push_back(' ');
            }
            matrix[i].push_back('0');
        }
    }
}

void Board::printBoard(Board board, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << board.matrix[i][j];
        }
        cout << "\n";
    }
}

Point::Point(double x1, double y1) {
    x = x1;
    y = y1;
}

Point::Point() {
    x = 0;
    y = 0;
}

Board::Board(const Board& copy) {
    matrix = copy.matrix;
}

Board::Board(Board&& move) {
    matrix = move.matrix;
}

Board::~Board() {
    matrix.clear();
}

void Board::drawLine(Point point1, Point point2, char symbol) {
    round(point1.x);
    round(point1.y);
    round(point2.x);
    round(point2.y);
    const bool steep = (fabs(point2.y - point1.y) > fabs(point2.x - point1.x));
    if (steep) {
        swap(point1.x, point1.y);
        swap(point2.x, point2.y);
    }

    if (point1.x > point2.x) {
        swap(point1.x, point2.x);
        swap(point1.y, point2.y);
    }

    const float dx = point2.x - point1.x;
    const float dy = fabs(point2.y - point1.y);

    float error = dx / 2.0f;
    const int ystep = (point1.y < point2.y) ? 1 : -1;
    int y = (int)point1.y;

    const int maxX = (int)point2.x;

    for (int x = (int)point1.x; x <= maxX; x++) {
        if (steep) {
            matrix[y][x] = symbol;
        }
        else {
            matrix[x][y] = symbol;
        }

        error -= dy;
        if (error < 0) {
            y += ystep;
            error += dx;
        }
    }
}
