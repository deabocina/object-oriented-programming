#pragma once
#include "Point.hpp"
#include <iostream>
#include <vector>
using namespace std;

class Board {
public:
    vector<vector<char>> matrix;
    Board(int rows, int columns);
    Board(const Board& copy);
    Board(Board&& move);
    void printBoard(Board board, int rows, int columns);
    void drawLine(Point point1, Point point2, char symbol);
    ~Board();
};