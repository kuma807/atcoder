//https://sen-comp.hatenablog.com/entry/2020/03/12/145742

const double EPS = 1e-10;
//a > 0ならば+1, a == 0ならば0, a < 0ならば-1　を返す。　基本的にEPS込みの評価はこれで行う。
//不等式は、加減算に直してこれに適用する。
int sgn(const double a) {
	return (a < -EPS ? -1 : (a > EPS ? +1 : 0));
}

struct Point {
	//2次元ベクトルのクラス

	double x, y;
	Point(double _x, double _y) {
		x = _x, y = _y;
	}
	Point() {
		x = 0, y = 0;
	}

	Point operator+() const {
		return *this;
	}
	Point operator-() const {
		return{ -x, -y };
	}
	Point operator+ (const Point& b) const {
		return{ x + b.x, y + b.y };
	}
	Point operator- (const Point& b) const {
		return{ x - b.x, y - b.y };
	}
	Point operator* (const double b) const {
		return{ x * b, y * b };
	}
	Point operator/ (const double b) const {
		return{ x / b, y / b };
	}
	Point operator+= (const Point& b) {
		x += b.x, y += b.y;
		return *this;
	}
	Point operator-= (const Point& b) {
		x -= b.x, y -= b.y;
		return *this;
	}
	Point operator*= (const double b) {
		x *= b, y *= b;
		return *this;
	}
	Point operator/= (const double b) {
		x /= b, y /= b;
		return *this;
	}
	bool operator== (const Point& b) {
		return b.x == x && b.y == y;
	}

	double lengthSquare() const {
		return (x * x + y * y);
	}
	double length() const {
		return std::sqrt(lengthSquare());
	}
	double dot(const Point& b) const {
		return x * b.x + y * b.y;
	}
	double cross(const Point& b) const {
		//Generally, cross product is vector, but in 2D, cross product is also scalar.
		return x * b.y - y * b.x;
	}
	double distanceFrom(const Point& b) const {
		return std::sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
	}
	Point normalized() const {
		return{ x / length(), y / length() };
	}
	bool isZero() const {
		return sgn(x) == 0 && sgn(y) == 0;
	}
	//単位法線ベクトル
	Point normalUnitVector() const {
		return{ -normalized().y, normalized().x };
	}
	//(0, 0)中心にarg(弧度法)回転した座標
	Point rotation(double arg) const {
		double cs = cos(arg), sn = sin(arg);
		return Point(x * cs - y * sn, x * sn + y * cs);
	}
	//(0, 0)中心の円上に乗ってるとしたときの、偏角
	double angle() const {
		return atan2(y, x);
	}
};

inline Point operator*(double a, const Point& b) {
	return{ b.x * a, b.y * a };
}
const Point error_val = { 114514.0, -191981.0 };
int iSP(const Point& a, const Point& b, const Point& c) {
	int flg = sgn((b - a).cross(c - a));
	if (flg == 1) {
		return +1;
	}
	else if (flg == -1) {
		return -1;
	}
	else {
		//ABC(CBA)
		if (sgn((b - a).dot(c - b)) > 0)
			return +2;
		//BAC(CAB)
		else if (sgn((a - b).dot(c - a)) > 0)
			return -2;
		//ACB(BCA)　CがA or Bと一致しても、こっちに含まれる。
		else
			return 0;
	}
}

//向きつき直線を想定。Segment
struct Line {

	//直線の通る二点。有向直線でないのならば、beginやendに違いはない。
	Point begin, end;

	Line() {
		begin = Point(), end = Point();
	}

	Line(const Point& b, const Point& e) {
		begin = b, end = e;
	}

	//ax+by+c=0
	Line(const double a, const double b, const double c) {
		if (sgn(a) == 0 && sgn(b) == 0) {
			assert(-1);
		}

		if (sgn(b) == 0) {
			//ax+c=0になる。
			begin = Point(-c / a, 0.0);
			end = Point(-c / a, 1.0);
		}
		else {
			//y=-(ax+c)/b　傾きは-a/bで、y切片が-c/b
			begin = Point(0, -c / b);
			end = Point(1.0, -(a + c) / b);
		}
	}

	Point vec() const {
		return end - begin;
	}

	Point countervec() const {
		return begin - end;
	}

};

//半直線なら、Lineと同じだけど、はっきりと区別する。
typedef Line Ray;
//線分の場合、Lineと同じものになるが、はっきりと区別する
typedef Line Segment;


//直線の交点を返す。交わってなければ、error_valを返す。
Point lineIntersection(const Line& l1, const Line& l2) {
	if (sgn(l1.vec().cross(l2.vec())) == 0)return error_val;

	Point ret;
	ret = l1.begin + l1.vec() *
		abs((l2.end - l1.begin).cross(l2.vec()) / l1.vec().cross(l2.vec()));
	return ret;
}

//線分が共通部分を持つかどうか？と線分の交点を返す。共通部分がない、もしくは交点が一意ではないなら、error_valを返す。
//trueなら、共通部分を持つ。falseなら、共通部分を持たない。
pair<bool, Point> segmentIntersection(const Segment& s1, const Segment& s2) {

	if (iSP(s1.begin, s1.end, s2.begin) * iSP(s1.begin, s1.end, s2.end) <= 0 &&
		iSP(s2.begin, s2.end, s1.begin) * iSP(s2.begin, s2.end, s1.end) <= 0) {

		//平行ならば、交点は定まらない。(完全に重なってるので)
		if (s1.vec().cross(s2.vec()) == 0)
			return make_pair(true, error_val);
		else //そうでないのなら、lineIntersection()で交点を返しておく。
			return make_pair(true, lineIntersection(s1, s2));

	}
	return make_pair(false, error_val);
}
