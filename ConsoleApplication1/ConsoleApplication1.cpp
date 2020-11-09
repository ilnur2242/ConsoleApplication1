#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;




template <typename T>
class Point
{
private:
	T x, y;

public:
	Point() {

		
		x = 0.;
		y = 0.;
	}
	Point(T x_, T y_)
	{
		x = x_;
		y = y_;
	}

	vector<T> get() {
		vector<T> v = { x,y };
		return v;
	}
	friend bool operator==(const T& p1, const T& p2) {
		if (p1.x == p2.x && p1.y == p2.y) return true;
		else return false;
	}
};



template <typename T> class Line
{
private:
	Point<T> a, b;
public:
	Line() {
		float x1, y1;
		cout << "enter the data, cunty" << endl;
		cin >> x1 >> y1;
		a = Point<T>(x1, y1);
		cin >> x1 >> y1;
		b = Point<T>(x1, y1);

	}
	Line(Point<T> a_, PointT b_) {
		a = a_;
		b = b_;

	}

	vector<Point<T>> get() {
		vector<Point<T>> v = { a,b };
		return v;
	}

	int IsIntersecLine(Line<T> l1)
	{
		float x2_ = l1.b.get()[0] - l1.a.get()[0];
		float y2_ = l1.b.get()[1] - l1.a.get()[1];
		float x1_ = b.get()[0] - a.get()[0];
		float y1_ = b.get()[1] - a.get()[1];

		float d_inf = (y1_ * x2_ - y2_ * x1_);
		//float d_;

		if (d_inf == 0) {
			if ((a.get()[1] * x1_ - a.get()[0] * y1_) * x2_ == (l1.a.get()[1] * x2_ - l1.a.get()[0] * y2_) * x1_)
			{
				cout << " Lines are equal " << endl;
				return 1; // equal
			}
			else
			{
				cout << " Lines are parallel " << endl;
				return 2; // parallel
			}
		}
		else {
			cout << " Lines are intesection " << endl;
			return 0;
		}
		
	}
	
	bool IsIntersecSegments(Line<T> l1) {
		float x2_ = l1.b.get()[0] - l1.a.get()[0];
		float y2_ = l1.b.get()[1] - l1.a.get()[1];
		float x1_ = b.get()[0] - a.get()[0];
		float y1_ = b.get()[1] - a.get()[1];
		
		float x, y;

		float d_inf = (y1_ * x2_ - y2_ * x1_);


		int code = IsIntersecLine(l1);
		switch (code)
		{
			case 0: // intersrc
			{
				float d_ = x1_ * x2_ / d_inf;
				x = d_ * ((-l1.a.get()[0] * y2_ + l1.a.get()[1] * x2_) / x2_ - (-a.get()[0] * y1_ + a.get()[1] * x1_) / x1_);
				y = ((x - a.get()[0]) * y1_ + a.get()[1] * x2_) / x1_;
				if (((a.get()[0] <= x && x <= b.get()[0]) || (b.get()[0] <= x && x <= a.get()[0])) && ((l1.a.get()[0] <= x && x <= l1.b.get()[0]) || (l1.b.get()[0] <= x && x <= l1.a.get()[0]))) {
					if (((a.get()[1] <= x && x <= b.get()[1]) || (b.get()[1] <= x && x <= a.get()[1])) && ((l1.a.get()[1] <= x && x <= l1.b.get()[1]) || (l1.b.get()[1] <= x && x <= l1.a.get()[1]))) {
						return true;
					}
				}
				else
				{
					return false;
				}
			}
			case 1: // equal
			{
				
				float a10 = a.get()[0], a11 = a.get()[1]; 
				float b10 = b.get()[0], b11 = b.get()[1];
				float a20 = l1.a.get()[0], a21 = l1.a.get()[1];
				float b20 = l1.b.get()[0], b21 = l1.b.get()[1];
				// 
				if ((a10 <= a20 && a20 <= b10 && a11 <= a21 && a21 <= b11) || (a10 <= b20 && b20 <= b10 && a11 <= b21 && b21 <= b11)) { return true; }
				else if ((a20 <= a10 && a10 <= b20 && a21 <= a11 && a11 <= b21) || (a20 <= b10 && b10 <= b20 && a21 <= b11 && b11 <= b21)) { return true; }
				else return false;
			}
			case 2: // parallel
				return false;
		}
		

	}

	
};
template <typename T>
Point<T> CoordSegmentCenter(Point<T> A, Point<T> B);
template <typename T>
Point<T> CoordCircleCenterAboutTrig(Point<T> A, Point<T> B);

int main()
{

	Point<float> a(0., 0.);
	Point<float> b(1, 0);

	Point<float> c(0,1);
	Point<float> d(1, 2);

	Line<float> l1(a, b);
	Line<float> l2(c, d);//
	
	//cout << l1.IsIntersecLine(l2) << endl;
	cout << "Is segments intersection? - "<< l1.IsIntersecSegments(l2) << endl;

	//Point r = l1.IsIntersecLine(l2);

	return 0;
}
template <typename T>
Point<T> CoordSegmentCenter(Point<T> A, Point<T> B) 
{
	float x, y;
	float ax = A.get()[0], ay = A.get()[1], bx = B.get()[0], by = B.get()[1];
	vector<float> b = { B.get()[0] - A.get()[0] ,B.get()[1] - A.get()[1] };
	float k = b[1] / b[0];
	float m = -k * ay / ax + ay;
	float m1 = m - ay, m2 = m - by;

	x = (bx * bx + m2 * m2 - ax * ax - m1 * m1) / (2 * bx + 2 * k * m2 - 2 * ax - 2 * k * m1);
	y = k * x + m;
	return Point(x,y);
}
template <typename T>
Point<T> CoordCircleCenterAboutTrig(Point<T> A, Point<T> B)
{
	
}