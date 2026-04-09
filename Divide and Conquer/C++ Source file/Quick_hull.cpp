#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

// Orientation function
// Returns:
// 0 -> collinear
// 1 -> clockwise
// -1 -> counterclockwise
int orientation(Point a, Point b, Point c) {
    int val = (b.x - a.x)*(c.y - a.y) - 
              (b.y - a.y)*(c.x - a.x);

    if (val == 0) return 0;
    return (val > 0) ? -1 : 1;  
}

// Distance from line AB (area * 2)
int lineDistance(Point a, Point b, Point p) {
    return abs((b.x - a.x)*(p.y - a.y) -
               (b.y - a.y)*(p.x - a.x));
}

void quickHullRec(vector<Point>& points,
                  Point A, Point B,
                  int side,
                  set<pair<int,int>>& hull)
{
    int idx = -1;
    int maxDist = 0;

    // Find farthest point from AB on given side
    for (int i = 0; i < points.size(); i++) {

        int temp = lineDistance(A, B, points[i]);

        if (orientation(A, B, points[i]) == side &&
            temp > maxDist) {

            idx = i;
            maxDist = temp;
        }
    }

    // No point found → AB is hull edge
    if (idx == -1) {
        hull.insert({A.x, A.y});
        hull.insert({B.x, B.y});
        return;
    }

    // Recur for two segments
    quickHullRec(points,points[idx], A,-orientation(points[idx], A, B),hull);

    quickHullRec(points,points[idx], B,-orientation(points[idx], B, A),hull);
}

void QuickHull(vector<Point>& points)
{
    if (points.size() < 3) {
        cout << "Convex hull not possible\n";
        return;
    }

    

    int min_x = 0, max_x = 0;

    for (int i = 1; i < points.size(); i++) {
        if (points[i].x < points[min_x].x)
            min_x = i;
        if (points[i].x > points[max_x].x)
            max_x = i;
    }

    set<pair<int,int>> hull;

    // Divide into two halves
    quickHullRec(points,
                 points[min_x],
                 points[max_x],
                 1,
                 hull);

    quickHullRec(points,
                 points[min_x],
                 points[max_x],
                 -1,
                 hull);

    cout << "Convex Hull Points:\n";
    for (auto p : hull) {
        cout << "(" << p.first
             << "," << p.second << ") ";
    }
    cout << endl;
}

int main() {

    vector<Point> points = {

        {0,0},{4,0},{2,4},{2,1}

    };

    QuickHull(points);

    return 0;
}