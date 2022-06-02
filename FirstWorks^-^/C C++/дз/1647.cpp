#include <iomanip>
#include <cmath>
#include <iostream>

struct point
{
    double x, y;
    point(double x = 0, double y = 0) : x(x), y(y) {}
    point operator- (const point& p) { return point(x - p.x, y - p.y); }
    point operator+ (const point& p) { return point(x + p.x, y + p.y); }
    point operator* (const double t) { return point(x*t, y*t); }
    double dist() { return std::sqrt(x*x + y*y); }
};

bool solve(point p1, point p2, point p3, point& S, point& T)
{
    double a = (p2-p1).dist(), b = (p3-p1).dist(), c = (p3-p2).dist();
    double p = a + b + c;
    double t;
    if(std::abs(p*p - 8*a*b) < 1e-9)
        t = p/(4*b);
    else
    {
        t = (p + std::sqrt(p*p - 8*a*b))/(4*b);
        if(t > 1)
            t = (p - std::sqrt(p*p - 8*a*b))/(4*b);
    }
    double s = 1/(2*t);
    if(t != t || s > 1 + 1e-9 || s	 < 0 - 1e-9 || t > 1 + 1e-9 || t < 0 - 1e-9)
        return false;
    S = p1 + (p2-p1)*s;
    T = p1 + (p3-p1)*t;
    return true;
}

int main()
{
    point p1, p2, p3, S, T;
    std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

    while(!solve(p1, p2, p3, S, T))
        std::swap(p1, p2), std::swap(p2, p3);
    std::cout << "YES\n" << std::setprecision(20) << S.x << " " << S.y << "\n" << T.x << " " << T.y;
}