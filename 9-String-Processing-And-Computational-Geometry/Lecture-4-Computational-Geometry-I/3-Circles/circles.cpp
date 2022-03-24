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

typedef int dtype;
const double EPS = 0.01;

struct point {
    dtype x, y;
    point() { x = y = 0.0; }
    point(dtype _x, dtype _y) : x(_x), y(_y) {}
};

int insideCirlce(point p, point c, int r) {
    int dx = p.x - c.x, dy = p.y - c.y;
    int euc = dx*dx + dy*dy, rSq = r*r;
    return euc < rSq ? 0 : euc == rSq ? 1 : 2; 
    // 0: inside, 1: border, 2: outside
}

bool circle2PtsRad(point p1, point p2, double r, point &c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) + 
                (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;
    if (det < 0.0) return false;
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true; 
}     

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if(getenv("LOCAL")){setIO();}

    point p = {0, 4}, c = {0, 0};
    int r = 4;

    cout << "Point p inside/border/outside circle " << endl;
    cout << "\tResult = " << insideCirlce(p, c, r) << endl;

    cout << endl << "Circle 2 pts" << endl;
    point p1 = {0, 5};
    point p2 = {0, -6};
    point ans;
    double r = 5;
    circle2PtsRad(p1, p2, r, ans);
    cout << "C1 (" << ans.x << "," << ans.y << ")" << endl;
    circle2PtsRad(p2, p1, r, ans);
    cout << "C2 (" << ans.x << "," << ans.y << ")" << endl;

    return 0;
}
