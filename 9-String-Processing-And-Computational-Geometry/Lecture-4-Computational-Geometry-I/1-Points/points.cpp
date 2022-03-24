#include <bits/stdc++.h>
using namespace std;

void setIO() {
    string file = __FILE__;
    file = string(file.begin(), file.end()-3);
    string in_file = file+"in";
    string out_file = file+"out";
    freopen(in_file.c_str(), "r", stdin);
    freopen(out_file.c_str(), "w", stdout);
}

#define PI 3.14159265

typedef double dtype;
const double EPS = 0.01;

struct point {
    dtype x, y;
    point() { x = y = 0.0; }
    point(dtype _x, dtype _y) : x(_x), y(_y) {}

    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }

    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && fabs(y - other.y) < EPS); 
    }
};

dtype dist (point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

dtype dot(point a, point b) {
    return a.x*b.x + a.y*b.y;
}

dtype norm(point a) {
    return dot(a, a);
}

dtype abs(point a) {
    return sqrt(norm(a));
}

dtype proj(point a, point b) {
    return dot(a, b) / abs(b);
}

dtype angle(point a, point b) {
    return acos((dot(a,b)) / (abs(a) * abs(b))); // in radians
}

dtype cross(point a, point b) {
    return a.x*b.y - a.y*b.x;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if(getenv("LOCAL")){setIO();}

    int n; cin >> n;
    vector<point> points(n);
    for(int i = 0; i < n; i++) {
        dtype x, y;
        cin >> x >> y;
        points[i] = {x,y};
    }

    cout << "Unsorted points:" << endl;
    for (auto p : points)
        cout << "(" << p.x << "," << p.y << ")" << endl;

    sort(points.begin(), points.end());

    cout << "\nSorted points:" << endl;
    for (auto p : points)
        cout << "(" << p.x << "," << p.y << ")" << endl;

    cout << "\nChecking if two points are equal: " << endl;
    auto p1 = points[0];
    auto p2 = points[1];

    cout << (p1 == p2) << endl;

    cout << "\nEuclidean distance between two points" << endl;
    cout << dist(points[0], points[3]) << endl;

    cout << endl << "Dot product properties:" << endl;
    point A = {0,3};
    point B = {6, 0};

    cout << "P1=(" << A.x << "," << A.y << ") P2=(" << B.x << "," << B.y << ")" << endl;
    cout << endl << "Dot product : " << dot(A, B) << endl;
    cout << "Norm of A : " << norm(A) << endl;
    cout << "Length of A : " << abs(A) << endl;
    cout << "Proj of A onto B : " << proj(A, B) << endl;
    cout << "Angle between A and B : " << angle(A, B) * 180.0 / PI << endl;

    cout << endl << "Cross product between A and B : " << cross(A, B) << endl;

    return 0;
}
