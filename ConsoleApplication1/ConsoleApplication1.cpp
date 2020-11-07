#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

float min(vector<float> v)
{
	float min = 9999.;
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i] < min) min = v[i];
	}
	return min;
}

float max(vector<float> v)
{
	float max = -9999.;
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i] > max) max = v[i];
	}
	return max;
}

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
		float d_;

		if (d_inf == 0) {
			if ((a.get()[1] * x1_ - a.get()[0] * y1_) * x2_ == (l1.a.get()[1] * x2_ - l1.a.get()[0] * y2_) * x1_)
			{
				return 1; // equal
			}
			else
			{
				return 2; // parallel
			}
		}
		else {
			return 0;
		}
		//try
		//{
		//	if (d_inf == 0) 
		//	{
		//		throw exception("Прямые параллельны!");
		//		if ((a.get()[1] * x1_ - a.get()[0] * y1_) * x2_ == (l1.a.get()[1] * x2_ - l1.a.get()[0] * y2_) * x1_) throw exception("Прямые совпадают");
		//	}
		//	d_ = x1_ * x2_ / d_inf;
		//}
		//catch(exception&e)
		//{
		//	e.what();
		//	 
		//}
		////float d_inf = (y1_ * x2_ - y2_ * x1_);
		////if (d_inf == 0) 
		////{
		////if (a == l1.a || a == l1.b || b == l1.a || b == l1.b) return true;



		////float d_ = x1_ * x2_ / d_inf;
		//float x = d_ * ((-l1.a.get()[0] * y2_ + l1.a.get()[1] * x2_) / x2_ - (-a.get()[0] * y1_ + a.get()[1] * x1_) / x1_);

		////vector<float> lx = { a.get()[0], b.get()[0], l1.a.get()[0], l1.b.get()[0] };
		////vector<float> ly = { a.get()[1], b.get()[1], l1.a.get()[1], l1.b.get()[1] };

		//float y = ((x - a.get()[0]) * y1_ + a.get()[1] * x2_) / x1_;

		////float ax = min(lx), ay = min(ly), bx, by, cx = max(lx), cy = max(ly), dx, dy;

		//cout << x << endl;
		//cout << y << endl;

		////vector<float> v = { x,y };

		////Point ret(x, y);

		////return ret;
		///*if (ax <= x && x <= cx && ay <= y && y <= cy) return true;
		//else return false;*/
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
			case 0:
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
			case 1:
			{
				
			}
			case 2:
				return false;
		}
		

	}
};

int main()
{

	Point a(0, 0);
	Point b(5, 5);

	Point c(5, 5);
	Point d(5, 6);

	Line l1(a, b);
	Line l2(c, d);//
	
	//Point r = l1.IsIntersecLine(l2);

	return 0;
}
