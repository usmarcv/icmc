#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
using ll = long long;
using pii = pair<int, int>;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }

template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) { cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl; }
template<class num> inline void rd(num& x) { cin >> x; }
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }
template<class num> inline void print(num&& x) { cout << x; }
template <class Ty, class... Args> inline void print(Ty&& x, Args&&... args) { print(x); print(' '); print(args...); }
#define print(...) print(__VA_ARGS__), print('\n')

/** ==== GEOMETRY NOTEBOOK ========================================================================================== */
const double EPS = 1e-12;

template<typename T> inline char sign(T x) { return abs(x) < EPS ? 0 : x > 0 ? 1 : -1; }

template<typename T> struct Point {
	T x, y;

	Point() : x(), y() {}
	Point(T x, T y) : x(x), y(y) {}
	template<typename Tp> Point(Point<Tp> p) : x(p.x), y(p.y) {}

	// basic operators
	template<typename Tp> Point<T> operator+(Point<Tp> const& p) const { return Point<T>(x + p.x, y + p.y); }
	template<typename Tp> Point<T> operator-(Point<Tp> const& p) const { return Point<T>(x - p.x, y - p.y); }
	template<typename Tp> Point<T> operator*(Tp&& p) const { return Point<T>{x * p, y * p}; }
	template<typename Tp> Point<T> operator/(Tp&& p) const { return Point<T>{x / p, y / p}; }
	template<typename Tp> Point<T> operator%(Tp&& p) const { return Point<T>{x % p, y % p}; }

	template<typename Tp> Point<T>& operator+=(Point<Tp> const& p) { return (*this) = (*this) + p; }
	template<typename Tp> Point<T>& operator-=(Point<Tp> const& p) { return (*this) = (*this) - p; }
	template<typename Tp> Point<T>& operator*=(Tp&& p) { return (*this) = (*this) * p; }
	template<typename Tp> Point<T>& operator/=(Tp&& p) { return (*this) = (*this) / p; }
	template<typename Tp> Point<T>& operator%=(Tp&& p) { return (*this) = (*this) % p; }

	template<typename Tp> bool operator<(Point<Tp> const& p) const { return x == p.x ? y < p.y : x < p.x; }
	template<typename Tp> bool operator==(Point<Tp> const& p) const { return x == p.x && y == p.y; }

	inline T len2() const { return x * x + y * y; }
	inline double len() const { return hypot(x, y); }
	template<typename Tp> inline T dist2(Point<Tp> const& p) const { return (*this - p).len2();  }
	template<typename Tp> inline double dist(Point<Tp> const& p) const { return hypot(x - p.x, y - p.y); }

	template<typename Tp> inline T dot(Point<Tp> const& p) const { return x * p.x + y * p.y; }    // |u| * |v| * cos(alpha)
	template<typename Tp> inline T cross(Point<Tp> const& p) const { return x * p.y - y * p.x; }  // |u| * |v| * sin(alpha)
	template<typename Tp1, typename Tp2> inline T dot(Point<Tp1> const& a, Point<Tp2> const& b) const { return (a - *this).dot(b - *this); }
	template<typename Tp1, typename Tp2> inline T cross(Point<Tp1> const& a, Point<Tp2> const& b) const { return (a - *this).cross(b - *this); }

	/** Orientation of (*this) according to segment AB. 0: collinear, 1: right, -1: left */
	inline char orientation(Point const& a, Point const& b) const { return sign((*this - b).cross(b - a)); }

	/** Orthogonal projection of vector (*this) on vector u.
	 * The point of projection of AB on AC will be at A + AC * AB.proj(AC). */
	inline double proj(Point const& u) const { return static_cast<double>(u.dot(*this)) / u.len2(); }

	/** Distance from (*this) to segment AB */
	inline double dist_to_segment(Point const& a, Point const& b) const {
		Point<T> p = *this;
		if (a.dist2(b) <= EPS) return p.dist(a);
		Point<double> ap = p - a, ab = b - a;
		// if projection doesnt lie on segment, the minimum distance will be to A or B
		double u = clamp(ap.proj(ab), 0., 1.);
		Point<double> c = ab * u + a;
		return p.dist(c);
	}

	/** Checks whether point (*this) is in segment AB */
	inline bool in_segment(Point const& a, Point const& b) const {
		Point<T> AB = b - a, AP = (*this) - a;
		return sign(AB.cross(AP)) == 0 && AB.dot(AP) >= 0 && AB.dot(AP) <= AB.len2();
	}

	/** Rotate current vector rotated counter-clockwise by alpha (in radians) */
	inline Point<double> rotate(double alpha) {
		Point<double> ans;
		ans.x = cos(alpha) * x - sin(alpha) * y;
		ans.y = sin(alpha) * x + cos(alpha) * y;
		return ans;
	}

	/** Returns resized version of current vector with length len */
	inline Point<double> resize(double len) {
		Point<double> ans = *this;
		ans /= ans.len();
		ans *= len;
		return ans;
	}
};

template<typename T> istream& operator>>(istream& in, Point<T>& p) { return in >> p.x >> p.y; }
template<typename T> ostream& operator<<(ostream& out, Point<T>& p) { return out << p.x << ' ' << p.y; }
