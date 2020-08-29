

#include <iostream>
#include <queue>
#include <cstring>

struct Point {
   int x;
   int y;
};

bool operator>(const Point& p1, const Point& p2) {
    if (p1.x == p2.x)
        return p1.y > p2.y;

    return p1.x > p2.x;
}

using namespace std;

int main() {
    priority_queue<Point, deque<Point>, greater<Point>> fp;

    int i;

    for(i = 0; i < 10; i++) {
        int x, y;
        cout << "Informe o valor de X: ";
        cin >> x;
        cout << "Informe o valor de Y: ";
        cin >> y;
        Point point = { x, y };
        fp.push(point);
    }

    cout << "\n --- Em ordem --- \n";

    while(!fp.empty()) {
        cout << "X: " << fp.top().x << "\tY: " << fp.top().y << endl;
        fp.pop();
    }
}
