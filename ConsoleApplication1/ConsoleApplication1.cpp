#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Point
{
private:
	float x, y;

public:
	Point() {
		x = 0.;
		y = 0.;
	}
	Point(float x_, float y_)
	{
		x = x_;
		y = y_;
	}

	vector<float> get() {
		vector<float> v = { x,y };
		return v;
	}
	friend bool operator==(const Point& p1, const Point& p2) {
		if (p1.x == p2.x && p1.y == p2.y) return true;
		else return false;
	}
};

class Line
{
private:
	Point a, b;
public:
	Line() {
		float x1, y1;
		cout << "enter the data, cunty" << endl;
		cin >> x1 >> y1;
		a = Point(x1, y1);
		cin >> x1 >> y1;
		b = Point(x1, y1);

	}
	Line(Point a_, Point b_) {
		a = a_;
		b = b_;

	}

	vector<Point> get() {
		vector<Point> v = { a,b };
		return v;
	}

	int IsIntersecLine(Line l1)
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
	bool IsIntersecSegments(Line l1) {
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

int main()
{

	Point a(0, 0);
	Point b(1, 0);

	Point c(2,0);
	Point d(4, 0);

	Line l1(a, b);
	Line l2(c, d);//
	
	//cout << l1.IsIntersecLine(l2) << endl;
	cout << "Is segments intersection? - "<< l1.IsIntersecSegments(l2) << endl;

	//Point r = l1.IsIntersecLine(l2);

	return 0;
}
