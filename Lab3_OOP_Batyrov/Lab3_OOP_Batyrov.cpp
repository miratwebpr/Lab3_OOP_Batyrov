

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
	Node<T>*iterator;
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
	void pushBack(T newObj)
	{
		Node<T>* newNode = new Node<T>();
		newNode->Obj = newObj;
		newNode->next = NULL;
		newNode->prev = last;
		if(count != 0) last->next = newNode;
		else first = newNode;
		last = newNode;
		count++;
	}
	void pushFront(T newObj)
	{
		Node<T>* newNode = new Node<T>();
		newNode->Obj = newObj;
		newNode->next = first;
		newNode->prev = NULL;
		if (count != 0) first->prev = newNode;
		else last = newNode;
		first = newNode;
		count++;
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
	T getObjectAndDel(int index)
	{
		if (index < 0 || index >= count)
		{
			throw 0;
		}
		Node<T>* current = first;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		if (count == 1)
		{
			count = 0;
			first = NULL;
			last = NULL;
			return current->Obj;
		}
		if (current == first)
		{
			Node<T>* AftCurrent = current->next;
			AftCurrent->prev = NULL;
			first = AftCurrent;
			count--;
			return current->Obj;
		}
		else if (current == last)
		{
			Node<T>* BefCurrent = current->prev;
			BefCurrent->next = NULL;
			last = BefCurrent;
			count--;
			return current->Obj;
		}
		else
		{
			Node<T>* BefCurrent = current->prev;
			Node<T>* AftCurrent = current->next;
			BefCurrent->next = AftCurrent;
			AftCurrent->prev = BefCurrent;
			count--;
			return current->Obj;
		}
		
	}
	class Iterator
	{
	private:
		Node<T>* first;
	public:
		Iterator(Node<T>* first)
		{
			this->first = first;
		}
		Iterator operator++(int)
		{
			Iterator itr = *this;
			first = first->next;
			return itr;
		}
		T& operator*()
		{
			return first->Obj;
		}
		bool operator==(Iterator const comp) const
		{
			return first == comp.first;
		}
		bool operator!=(Iterator const comp) const
		{
			return !(first == comp.first);
		}
	};
	Iterator begin()
	{
		return Iterator(first);
	}
	Iterator end()
	{
		return Iterator(last->next);
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
class ColoredPoint :public Point
{
protected:
	int color;
public:
	ColoredPoint() : Point()
	{
		printf("ColoredPoint()\n");
		color = 0;
	}
	ColoredPoint(int x, int y, int color) : Point(x, y)
	{
		printf("ColoredPoint(int x, int y, int color)\n");
		this->color = color;
	}
	ColoredPoint(const ColoredPoint& p)
	{
		printf("ColoredPoint(const ColoredPoint &cp)\n");
		color = p.color;
		x = p.x;
		y = p.y;
	}
	~ColoredPoint()
	{
		printf("%d, %d color = %d\n", x, y, color);
		printf("~ColoredPoint()\n");
	}
	void change_color(int new_color)
	{
		color = new_color;
	}
};
using namespace std;
int main()
{
	Storage <Point*> MyStorage;
	Point *p1 = new Point(3, 19);
	Point* p2 = new Point(1, 32);
	Point* p3 = new Point(2, 125);
	MyStorage.pushFront(p1);
	MyStorage.pushBack(p2);
	MyStorage.pushBack(p3);


	Storage<Point*>::Iterator i = MyStorage.begin();
	for (i; i != MyStorage.end(); i++)
	{
		try
		{
			Point* p4 = *i;
			printf("%d\n", p4->x);
		}
		catch (int t)
		{
			if (t == 0) printf("Error: index is bigger than size of the storage");
		}
	}
}
/*
Point* p5 = new Point(1, 32);
Point* p6 = new Point(2, 125);
MyStorage.pushFront(p5);
MyStorage.pushBack(p6);
for (int i = 0; i < MyStorage.getCount(); i++)
{
	try
	{
		Point* p4 = MyStorage.getObject(i);
		printf("%d\n", p4->x);
	}
	catch (int t)
	{
		if (t == 0) printf("Error: index is bigger than size of the storage");
	}
}
*/