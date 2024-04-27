#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
    long long x, y;
};

int direction(Point p, Point q, Point r) {
    long long val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) {
        return 0; 
    } else if (val > 0) {
        return 1; 
    } else {
        return 2; 
    }
}

void convexHull(Point points[], int n) {
    if (n < 3) return;


    Point hull[n];


    int leftmost = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[leftmost].x) {
            leftmost = i;
        } else if (points[i].x == points[leftmost].x && points[i].y < points[leftmost].y) {
            leftmost = i;
        }
    }

    int p = leftmost, q;
    int hullSize = 0;
    do {
        hull[hullSize++] = points[p];
        q = (p + 1) % n;

        for (int i = 0; i < n; i++) {
            if (direction(points[p], points[i], points[q]) == 2) {
                q = i;
            }
        }

        p = q;
    } while (p != leftmost);


    cout << hullSize << endl;
    for (int i = 0; i < hullSize; i++) {
        cout << hull[i].x << " " << hull[i].y << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        Point points[n];
        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }

        convexHull(points, n);
    }

    return 0;
}
