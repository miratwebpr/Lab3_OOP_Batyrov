

#include "stdio.h"
#include <conio.h>
//Первым делом в начало
template<class T>class Storage;

template<class T>
class Node
{
	friend class Storage<T>;
private:
	Node* next;
	Node* prev;
	T Obj;
};
template<class T>
class Storage
{
protected:
	Node<T>*first;
	Node<T>*last;
	int count;
public:
    Storage()
    {
		first = NULL;
		last = NULL;
		count = 0;
    }
	int getCount()
	{
		return count;
	}
	void push_back(T newObj)
	{
		Node<T>* newNode = new Node<T>();//ff
		newNode->Obj = newObj;//ff
		newNode->next = NULL;//ff
		newNode->prev = last;//ff
		if(count != 0) last->next = newNode;
		else first = newNode;//ff
		last = newNode;//ff
		count++;//ff
	}
	T getObject(int index)
	{
		if (index < 0 || index >= count)
		{
			throw 0;
		}
		Node<T>*current = first;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		return current->Obj;
	}
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
	Storage <Point*> MyStorage;
	Point *p1 = new Point(3, 19);
	Point* p2 = new Point(12, 32);
	Point* p3 = new Point(123, 125);
	
	MyStorage.push_back(p1);
	MyStorage.push_back(p2);
	MyStorage.push_back(p3);

	int count = MyStorage.getCount();
	printf("%d\n", count);

	for (int i = 0; i < count; i++)
	{
		Point* p4 = MyStorage.getObject(i);
		printf("%d\n", p4->x);
	}
	
}