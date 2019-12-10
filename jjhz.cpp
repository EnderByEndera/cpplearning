#include <iostream>
#include <iomanip>
using namespace std;


class Point3D{
public:
    Point3D():x(0),y(0),z(0){};
    Point3D(double dx,double dy,double dz):x(dx),y(dy),z(dz){cout<<"ok";};
    Point3D(const Point3D& p):x(p.x),y(p.y),z(p.z){cout<<"no";};
    Point3D(Point3D&& p):x(p.x),y(p.y),z(p.z){cout<<"nice";};
    ~Point3D(){};
    Point3D translate(double dx, double dy, double dz){
        return Point3D(x+dx,y+dy,z+dz);
    };
    void get(){
        cout<<*this;
    }
    friend std::istream& operator>>(std::istream& is, Point3D& p);
    friend std::ostream& operator<<(std::ostream& os, const Point3D& p);
private:
    double x,y,z;
};

std::istream& operator>>(std::istream& is, Point3D& p){
    is>>p.x>>p.y>>p.z;
    return is;
};
std::ostream& operator<<(std::ostream& os, const Point3D& p){
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    os<<setprecision(2)<<"("<<p.x<<","<<p.y<<","<<p.z<<")";
    std::cout.unsetf(std::ios_base::floatfield);
    return os;
};


int main(){
    Point3D p1(1,2,3);
    Point3D p2(std::move(p1.translate(1, 1, 2)));
    p1.get();
    p2.get();
    return 0;
}