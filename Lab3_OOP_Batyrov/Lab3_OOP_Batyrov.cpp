

#include "stdio.h"
#include <conio.h>

template<typename Point>
class Storage
{
protected:
	node* first;
	node* last;
	int cnt;

    Storage()
    {
        myObject = null;
    }
    Storage(Point Object)
    {
        
    }
};
template<typename Point>
class node
{
private:
	node* next;
	node* prev;
	Point* Obj;
public:
	node(Point* Obj)
	{
		this->Obj = Obj;
		prev = Obj - 1;
		next = Obj + 1;
	}
	void add(Point* Obj)
	{
		node(*Obj);
		next++;
		prev++;
	}
	friend class Storage;
};
class Point
{
public:
	int x, y;
	Point()
	{
		printf("Point()\n");
		x = 0;
		y = 0;
	}
	Point(int x, int y)
	{
		printf("Point(int x, y)\n");
		this->x = x;
		this->y = y;
	}
	Point(const Point& p)
	{
		printf("Point(const Point &p)\n");
		x = p.x;
		y = p.y;
	}
	~Point()
	{
		printf("%d, %d\n", x, y);
		printf("~Point()\n");
	}
	void move(int dx, int dy)
	{
		x = x + dx;
		y = y + dx;
	}
};
using namespace std;
int main()
{
	Storage <node<Point*>>;
	Point *p1 = new Point();
}
