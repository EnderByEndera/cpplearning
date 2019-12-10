#include <iostream>
using namespace std;
 
class A {
public:
	int x;
	A(int x) : x(x)
	{
		cout << "Constructor" << endl;
	}
	A(A& a) : x(a.x)
	{
		cout << "Copy Constructor" << endl;
	}
	A& operator=(A& a)
	{
		x = a.x;
		cout << "Copy Assignment operator" << endl;
		return *this;
	}
	A(A&& a) : x(a.x)
	{
		cout << "Move Constructor" << endl;
	}
	A& operator=(A&& a)
	{
		x = a.x;
		cout << "Move Assignment operator" << endl;
		return *this;
	}
};
 
A GetA()
{
	return A(1);
}
 
A&& MoveA()
{
	return A(1);
}
 
int main()
{
	A a(1);
	A b = a;
	A c(a);
	b = a;
	A d = A(1);
	A e = std::move(a);
	A f = GetA();
	A&& g = MoveA();
	d = A(1);
 
	system("pause");
	return 0;
}