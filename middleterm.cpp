#include <iostream>

class Point3D
{
private:
    double x;
    double y;
    double z;

public:
    Point3D()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Point3D(double &&dx, double &&dy, double &&dz)
    {
        x = dx;
        y = dy;
        z = dz;
    }

    Point3D(const Point3D &p)
    {
        x = p.x;
        y = p.y;
        z = p.z;
    }

    Point3D(Point3D &&p)
    {
        std::swap(x, p.x);
        std::swap(y, p.y);
        std::swap(z, p.z);
    }

    ~Point3D()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Point3D &operator=(const Point3D &p)
    {
        x = p.x;
        y = p.y;
        z = p.z;
        return *this;
    }

    Point3D &operator=(Point3D &&p)
    {
        std::swap(x, p.x);
        std::swap(y, p.y);
        std::swap(z, p.z);
        return *this;
    }

    /**
         * return a new Point3D where every coordinate is added by dx, dy and dz
         * @param dx amount of translation dx
         * @param dy amount of translation dy
         * @param dz amount of trnaslation dz
         * @return new Point3D which is already translated
         */
    Point3D translate(double dx, double dy, double dz)
    {
        Point3D p;
        p.x = x + dx;
        p.y = y + dy;
        p.z = z + dz;
        return p;
    }

    /**
         * return a new Point3D where x, y and z coordinated is scaled by sx, sy and sz
         * @param sx amplification x
         * @param sy amplification y
         * @param sz amplification z
         * @return a new Point3d which is already amplificated
         */
    Point3D scale(double sx, double sy, double sz) try
    {
        if (sx <= 0.0 || sy <= 0.0 || sz <= 0.0)
        {
            throw std::out_of_range("amplification failed");
        }
        Point3D p;
        p.x = x * sx;
        p.y = y * sy;
        p.z = z * sz;
        return p;
    }
    catch (const char *errmsg)
    {
        std::cout << errmsg << std::endl;
        Point3D p;
        return p;
    }

    friend std::istream &operator>>(std::istream &is, Point3D &p);
    friend std::ostream &operator<<(std::ostream &os, const Point3D &p);
};

std::istream &operator>>(std::istream &is, Point3D &p)
{
    is >> p.x >> p.y >> p.z;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Point3D &p)
{
    os << "(" << p.x << "," << p.y << "," << p.z << ")";
    return os;
}

int main()
{

    Point3D p1, p2;

    std::cin >> p1;
    p2 = p1.translate(2, 3, 4);
    p1 = p2.scale(1.5, 0.5, 2.5);
    std::cout << p1;

    return 0;
}