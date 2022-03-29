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

point line_intersect_seg(point p, point q, point A, point B) {
    double a = B.y - A.y;
    double b = A.x - B.x;
    double c = B.x * A.y - A.x + B.y;
    double u = fabs(a * p.x + b * p.y + c);
    double v = fabs(a * q.x + b * q.y + c);
    return point((p.x*v + q.x*u) / (u+v), (p.y*v + q.y*u) / (u+v));
}

vector<point> cut_polygon(point a, point b, const vector<point> & p) {
    vector<point> new_polygon;
    for (int i = 0; i < (int) p.size(); i++) {
        double left1 = cross(toVec(a, b), toVec(a, p[i])), left2 = 0;
        if (i != (int) p.size()-1) {
            left2 = cross(toVec(a, b), toVec(a, p[i+1]));
        }
        if (left1 > -EPS) {
            new_polygon.push_back(p[i]);
        }
        if (left1 * left2 < -EPS) {
            new_polygon.push_back(line_intersect_seg(p[i], p[i+1], a, b));
        }
    }
    
    if (!new_polygon.empty() && !(new_polygon.back() == new_polygon.front())) {
        new_polygon.push_back(new_polygon.front());
    }

    return new_polygon;
}

// Graham Scan algorithm for finding Convex Hull of a set of points P
bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; 
}

point pivot;
bool angleCmp(point a, point b) {                 // angle-sorting function
    if (collinear(pivot, a, b))                               // special case
        return dist(pivot, a) < dist(pivot, b);    // check which one is closer
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;    // compare two angles
}

vector<point> CH(vector<point> P) {   // the content of P may be reshuffled
    int i, j, n = (int)P.size();
    if (n <= 3) {
        if (!(P[0] == P[n-1])) P.push_back(P[0]); // safeguard from corner case
        return P;                           // special case, the CH is P itself
    }

    // first, find P0 = point with lowest Y and if tie: rightmost X
    int P0 = 0;
    for (i = 1; i < n; i++)
        if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
        P0 = i;

    point temp = P[0]; P[0] = P[P0]; P[P0] = temp;    // swap P[P0] with P[0]

    // second, sort points by angle w.r.t. pivot P0
    pivot = P[0];                    // use this global variable as reference
    sort(++P.begin(), P.end(), angleCmp);              // we do not sort P[0]

    // third, the ccw tests
    vector<point> S;
    S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);   // initial S
    i = 2;                                         // then, we check the rest
    while (i < n) {           // note: N must be >= 3 for this method to work
        j = (int)S.size()-1;
        if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);  // left turn, accept
        else S.pop_back(); }   // or pop the top of S until we have a left turn
    return S; 
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

    cout << "\nCutting polygon on points a and b" << endl; 
    auto new_polygon = cut_polygon({0,0}, {4,4}, polygon);
    for (auto p : new_polygon) {
        cout << "(" << p.x << "," << p.y << ")" << endl;
    }

    cout << "\nFinding convex hull of P:" << endl;

    cin >> n;
    vector<point> p;
    while (n--) {
        double u, v;
        cin >>u >> v;
        p.push_back({u,v});
    }

    cout << "P points:" << endl;
    for (auto p : p) {
        cout << "(" << p.x << "," << p.y << ")" << endl;
    }

    cout << "CH(P) points:" << endl;
    auto convex_hull = CH(p);
    for (auto p : convex_hull) {
        cout << "(" << p.x << "," << p.y << ")" << endl;
    }

    return 0;
}
