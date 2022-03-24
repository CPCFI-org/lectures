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

typedef double dtype;
const double EPS = 0.01;

struct line {
    dtype a, b, c;
};

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

void pointsToLine(point p1, point p2, line & l) {
    if (fabs(p1.x - p2.x) < EPS) {
        l.a = 1.0;
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x); // (y1-y2) / (x1 - x2)
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y; 
    }
}

bool areParallel(line l1, line l2) {
    return (fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS);
}

bool areSame(line l1, line l2) {
    return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}

bool intersect(line l1, line l2, point & p) {
    if (areParallel(l1, l2)) return false;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else                  p.y = -(l2.a * p.x + l2.c);
    return true;
}


struct vec {
    dtype x, y;
    vec(dtype _x, dtype _y) : x(_x), y(_y) {}
};

dtype dist (point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

dtype norm_sq(vec v) {
    return v.x*v.x + v.y*v.y;
}

dtype dot(vec a, vec b) {
    return a.x*b.x + a.y*b.y;
}

vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, dtype s) {
    return vec(v.x * s, v.y * s);
}

point translate(point p, vec v) {
    return point(p.x + v.x, p.y + v.y);
}

dtype distToLine(point p, point a, point b, point & c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    dtype u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p, c);
}

dtype distToLineSegment(point p, point a, point b, point & c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ap) / norm_sq(ab);
    if (u < 0.0) {
        c = {a.x, a.y};
        return dist(p, a);
    }
    if (u > 1.0) {
        c = {b.x, b.y};
        return dist(p, b);
    }
    return distToLine(p, a, b, c);
}

// counter clockwsie test
double cross(vec a, vec b) {
    return a.x*b.y - a.y * b.x;
}

bool ccw(point p, point q, point r) {
    vec pq = toVec(p,q);
    vec pr = toVec(p,r);
    return cross(pq, pr) > 0;
}

bool collinear(point p, point q, point r) {
    vec pq = toVec(p, q);
    vec pr = toVec(p, r);
    return fabs(cross(pq, pr)) < EPS;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if(getenv("LOCAL")){setIO();}

    point p1 = {2,2}, p2 = {4,4};
    line l;
    pointsToLine(p1, p2, l);

    cout << "Line from two points: " << l.a << "x + " << l.b << "y + " << l.c << endl;

    line l2;
    pointsToLine({2,-2}, {4,0}, l2);
    
    cout << "L1 and L2 parallel : " << areParallel(l, l2) << endl;

    line l1 = {-2, 1, -4};
    l2 = {2, 1, -4};
    point intersectionPoint;

    if (intersect(l1, l2, intersectionPoint)) {
        cout << "l1 and l2 intersect at (" << intersectionPoint.x << "," << intersectionPoint.y << ")" << endl;
    } else {
        cout << "l1 and l2 are parallel" << endl;
    }

    cout << endl << "Shortest distance between point p and line l" << endl;

    point p = {2, -4};
    point a = {2,0}, b = {5,6}, c;
    cout << "distance = " << distToLine(p, a, b, c) << endl;

    cout << endl << "Check if point is left/hand side of line l" << endl;

    p = {0,0};
    point q = {5, 0}, r = {2, 0};

    if (ccw(p, q, r)) {
        cout << "\tp is on the left hand side of line segment pq" << endl;
    } else if (collinear(p, q, r)) {
        cout << "\tp, q and r are collinear" << endl;
    } else {
        cout << "\tp is on the right hand side of line segment pq" << endl;
    }

    return 0;
}
