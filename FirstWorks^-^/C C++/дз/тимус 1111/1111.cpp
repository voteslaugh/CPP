#include <algorithm>
#include <vector>
#include <iostream>
//Прямые вычисления расстояний между точками и линиями с использованием стандартного метода векторной проекции.
struct Point
{
    double x, y;
    Point(double x, double y) : x(x), y(y) { }
    Point() { }
    Point  operator- (const Point& p) const { return Point(x - p.x, y - p.y); }
    bool   operator==(const Point& p) const { return p.x == x && p.y == y; }
    Point  operator+ (const Point& p) const { return Point(x + p.x, y + p.y); }
    Point  operator/ (long long t)     const { return Point(x / t, y / t); }
    Point  operator* (const double& t) const { return Point(x * t, y * t); }
    double operator* (const Point& p)  const { return x * p.x + y * p.y; }
  
    double length2()                   const { return x * x + y * y; }

    double dist2(Point v, Point w) // Квадрат расстояния между v и w
    {
        Point p = { x, y };
        Point wv = w - v;
        Point pv = p - v;
        return (wv * ((pv * wv) / (wv.length2())) - pv).length2();
    }
};

struct Square
{
    std::vector<Point> points;

    Square(long long x1, long long y1, long long x2, long long y2)
    {
        Point a(x1, y1), b, c(x2, y2), d;
        // Даны противоположные точки, поэтому оставшиеся два вектора вычисляются путем взятия вектора
        // половинный вектор между этими двумя точками, повернутый на +-90 градусов
        Point cent = (c - a) / 2;
        b = a + cent + Point{ -cent.y, cent.x };
        d = a + cent - Point{ -cent.y, cent.x };
        points = { a, b, c, d };
    }

    double dist2(Point p) const
    {
        double min = double(std::numeric_limits<double>::infinity());
        bool inside = true;
        for (long long i = 0; i < 4; i++) // для каждой стороны квадрата
        {
            Point w = points[(i + 1) % 4];
            Point v = points[i];

            if (v == w) // случай точечного квадрата
            {
                min = std::min(min, (v - p).length2());
                continue;
            }

            Point u = w - v;
            Point P = p - v;
            // Мы находимся внутри квадрата, если все стороны квадрата находятся справа от точки запроса, в смысле перекрестного произведения
            inside &= double(0) < (P.x * u.y - P.y * u.x);

            double t = (p - v) * (w - v) / (w - v).length2();
            if (t < double(0.0) || double(1.0) < t)
                min = std::min(min, std::min((w - p).length2(), (v - p).length2()));
            else
                min = std::min(p.dist2(v, w), min);
        }
        return inside ? 0 : min;
    }
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::pair<int, Square>> v; // { id, square }
    for (int i = 1; i <= n; i++)
    {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        v.push_back({ i, Square(x1, y1, x2, y2) });
    }
    int px, py;
    std::cin >> px >> py;
    Point p(px, py);

    // Сортировка входных данных в зависимости от расстояния
    std::sort(v.begin(), v.end(), [&p](const std::pair<int, Square>& a,
        const std::pair<int, Square>& b)
        {
            double dista = a.second.dist2(p), distb = b.second.dist2(p);
            return dista == distb
                ? a.first < b.first
                : a.second.dist2(p) < b.second.dist2(p);
        });

    for (int i = 0; i < v.size(); i++)
        std::cout << v[i].first << " ";
}