// ============how it works=================
//Circle {Point, 半径}
//crosspoint(Circle1, Circle2)
  //vector<Point>　交点をすべて返す
// ========================================

//=============circle_intersection============================
const ld EPS = 1e-7;        // to be set appropriately
const ld PI = acosl(-1.0);
ld torad(int deg) {return (ld)(deg) * PI / 180;}
ld todeg(ld ang) {return ang * 180 / PI;}

/* Point */
struct Point {
    ld x, y;
    Point(ld x = 0.0, ld y = 0.0) : x(x), y(y) {}
    friend ostream& operator << (ostream &s, const Point &p) {return s << '(' << p.x << ", " << p.y << ')';}
};
inline Point operator + (const Point &p, const Point &q) {return Point(p.x + q.x, p.y + q.y);}
inline Point operator - (const Point &p, const Point &q) {return Point(p.x - q.x, p.y - q.y);}
inline Point operator * (const Point &p, ld a) {return Point(p.x * a, p.y * a);}
inline Point operator * (ld a, const Point &p) {return Point(a * p.x, a * p.y);}
inline Point operator * (const Point &p, const Point &q) {return Point(p.x * q.x - p.y * q.y, p.x * q.y + p.y * q.x);}
inline Point operator / (const Point &p, ld a) {return Point(p.x / a, p.y / a);}
inline Point conj(const Point &p) {return Point(p.x, -p.y);}
inline Point rot(const Point &p, ld ang) {return Point(cos(ang) * p.x - sin(ang) * p.y, sin(ang) * p.x + cos(ang) * p.y);}
inline Point rot90(const Point &p) {return Point(-p.y, p.x);}
inline ld cross(const Point &p, const Point &q) {return p.x * q.y - p.y * q.x;}
inline ld dot(const Point &p, const Point &q) {return p.x * q.x + p.y * q.y;}
inline ld norm(const Point &p) {return dot(p, p);}
inline ld abs(const Point &p) {return sqrt(dot(p, p));}
inline bool eq(const Point &p, const Point &q) {return abs(p - q) < EPS;}
inline bool operator < (const Point &p, const Point &q) {return (abs(p.x - q.x) > EPS ? p.x < q.x : p.y < q.y);}
inline bool operator > (const Point &p, const Point &q) {return (abs(p.x - q.x) > EPS ? p.x > q.x : p.y > q.y);}
inline Point operator / (const Point &p, const Point &q) {return p * conj(q) / norm(q);}

/* Circle */
struct Circle : Point {
    ld r;
    Circle(Point p = Point(0.0, 0.0), ld r = 0.0) : Point(p), r(r) {}
    friend ostream& operator << (ostream &s, const Circle &c) {return s << '(' << c.x << ", " << c.y << ", " << c.r << ')';}
};

// 円の交点
vector<Point> crosspoint(const Circle &e, const Circle &f) {
    vector<Point> res;
    ld d = abs(e - f);
    if (d < EPS) return vector<Point>();
    if (d > e.r + f.r + EPS) return vector<Point>();
    if (d < abs(e.r - f.r) - EPS) return vector<Point>();
    ld rcos = (d * d + e.r * e.r - f.r * f.r) / (2.0 * d), rsin;
    if (e.r - abs(rcos) < EPS) rsin = 0;
    else rsin = sqrt(e.r * e.r - rcos * rcos);
    Point dir = (f - e) / d;
    Point p1 = e + dir * Point(rcos, rsin);
    Point p2 = e + dir * Point(rcos, -rsin);
    res.push_back(p1);
    if (!eq(p1, p2)) res.push_back(p2);
    return res;
}
//=================================================
