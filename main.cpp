#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Point.h"
#include "Square.h"
using namespace std;


Point::Point(int px, int py) : x(px), y(py) {}
int Point::getX() const { return x; }
int Point::getY() const { return y; }
void Point::setX(int px) { x = px; }
void Point::setY(int py) { y = py; }

Square::Square(const string n, int px, int py, unsigned int s)
    : Point(px, py), name(n), side(s) {
    area = s * s;
}

unsigned int Square::getSide() const { return side; }
unsigned int Square::getArea() const { return area; }
string Square::getName() const { return name; }

void Square::setSide(unsigned int s) { side = s; area = s * s; }
void Square::setArea(unsigned int a) { area = a; }
void Square::setName(string n) { name = n; }

int main()
{
    int n;
    cin >> n;
    vector<Square> squares;

    for (int i = 0; i < n; i++) {
        string name;
        int x, y;
        unsigned int side;
        cin >> name >> x >> y >> side;
        squares.emplace_back(name, x, y, side);
    }
    cout << endl;


    sort(squares.begin(), squares.end(), [](const Square& a, const Square& b) {
        if (a.getArea() == b.getArea()) {
            if (a.getX() == b.getX()) return a.getY() < b.getY();
            return a.getX() < b.getX();
        }
        return a.getArea() < b.getArea();
    });

    cout << "Squares in increasing order of area" << endl;
    for (const auto& s : squares) {
        cout << s.getName() << "(" << s.getX() << ", " << s.getY() << ") "
            << "side=" << s.getSide() << ", area=" << s.getArea() << endl;
    }

    cout << endl;


    sort(squares.begin(), squares.end(), [](const Square& a, const Square& b) {
        int aMaxX = a.getX() + a.getSide();
        int bMaxX = b.getX() + b.getSide();
        if (aMaxX == bMaxX) return a.getY() < b.getY();
        return aMaxX < bMaxX;
    });

    cout << "Squares in increasing order of max x-coordinate" << endl;
    for (const auto& s : squares) {
        cout << s.getName() << "(" << s.getX() + s.getSide() << ", " << s.getY() << ") "
            << "side=" << s.getSide() << ", area=" << s.getArea() << endl;
    }

    cout << endl;

    sort(squares.begin(), squares.end(), [](const Square& a, const Square& b) {
        int aMaxY = a.getY() + a.getSide();
        int bMaxY = b.getY() + b.getSide();
        if (aMaxY == bMaxY) return a.getX() < b.getX();
        return aMaxY < bMaxY;
    });

    cout << "Squares in increasing order of max y-coordinate" << endl;
    for (const auto& s : squares) {
        cout << s.getName() << "(" << s.getX() << ", " << s.getY() + s.getSide() << ") "
            << "side=" << s.getSide() << ", area=" << s.getArea() << endl;
    }

    return 0;
}