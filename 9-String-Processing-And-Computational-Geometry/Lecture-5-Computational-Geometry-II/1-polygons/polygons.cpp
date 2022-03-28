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

#define PI acos(-1.0)

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

dtype find_perimeter(const vector<point> & p) {
    dtype perimeter = 0.0;
    for (int i = 0; i < (int) p.size()-1; i++)
        perimeter += dist(p[i], p[i+1]);
    return perimeter;
}

dtype find_area(const vector<point> & p) {
    dtype area = 0.0;
    dtype x1, x2, y1, y2;
    for (int i = 0; i < (int) p.size() - 1; i++) {
        x1 = p[i].x;
        x2 = p[i+1].x;
        y1 = p[i].y;
        y2 = p[i+1].y;
        area += (x1*y2 - x2*y1);
    }
    return fabs(area) / 2.0;
}

struct vec {
    dtype x, y;
    vec(dtype _x, dtype _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}

double cross(vec a, vec b) {
    return a.x*b.y - a.y * b.x;
}

bool ccw(point p, point q, point r) {
    vec pq = toVec(p,q);
    vec pr = toVec(p,r);
    return cross(pq, pr) > 0;
}

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double angle(point a, point o, point b) {  // returns angle aob in rad
  vec oa = toVec(o, a), ob = toVec(o, b);
  return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); 
}

bool is_convex(const vector<point> & p) {
    int n = (int) p.size();
    if (n <= 3) return false; // point and lines are not convex
    bool is_left = ccw(p[0], p[1], p[2]);
    for (int i = 1; i < n-1; i++)
        if (ccw(p[i], p[i+1], p[(i+2) == n ? 1 : i+2]) != is_left)
            return false; // p is concave
    return true; // p is convex
}   

bool inside_polygon(const vector<point> & p, const point & pt) {
    int n = (int) p.size();
    if (n == 0) return false;
    double sum = 0;
    for (int i = 0; i < n-1; i++) {
        if (ccw(pt, p[i], p[i+1]))
            sum += angle(p[i], pt, p[i+1]);
        else sum -= angle(p[i], pt, p[i+1]);
    }
    return fabs(fabs(sum) - 2*PI) < EPS;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if(getenv("LOCAL")){setIO();}

    int n; 
    dtype u, v;
    cin >> n;

    vector<point> polygon;
    for(int i = 0; i < n; i++) {
        cin >> u >> v;
        polygon.push_back({u, v});
    }
    polygon.push_back(polygon[0]);

    cout << "Perimeter of polygon: " << find_perimeter(polygon) << endl;
    cout << "Area of polygon: " << find_area(polygon) << endl;
    cout << "Is polygon convex? " << (is_convex(polygon) ? true : false) << endl;

    point pt = {1,1};

    cout << "Point pt=(" << pt.x << "," << pt.y << ") inside polygon? " << inside_polygon(polygon, pt) << endl;

    return 0;
}
