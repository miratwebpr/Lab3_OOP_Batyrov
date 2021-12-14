

#include "stdio.h"
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
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
		Node<T>* current;
	public:
		Iterator(Node<T>* current)
		{
			this->current = current;
		}
		Iterator operator++(int)
		{
			Iterator itr = current;
			current = current->next;
			return itr;
		}
		Iterator operator--(int)
		{
			Iterator itr = current;
			current = current->prev;
			return itr;
		}
		T& operator*()
		{
			return current->Obj;
		}
		bool operator==(Iterator const comp) const
		{
			return current == comp.current;
		}
		bool hasCurrent() const
		{
			if (current != NULL)
				return true;
			return false;
		}
		bool operator!=(Iterator const comp) const
		{
			if (hasCurrent() == true && (current->next == NULL || current->prev == NULL))
				return true;
			else if (hasCurrent() == false)
				return false;
			return !(current == comp.current);
		}

	};
	Iterator begin()
	{
		return Iterator(first);
	}
	Iterator end()
	{
		return Iterator(last);
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
		//printf("Point(int x, y)\n");
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
	clock_t time_T = clock();
	srand(time(NULL));
	Storage <Point*> MyStorage;
	int actAmount = 0;
	int Action = 0;
	// 0 - getCount
	// 1 - create and pushBack
	// 2 - create and pushFront
	// 3 - getObject (byIndex)
	// 4 - getObjectAndDel (byIndex)
	// 5 - print all elements of the storage with iterator
	printf("Choose amount of random actions that you want to be done with the storage\n");
	scanf("%d", &actAmount);
	for (int i = 0; i < actAmount; i++)
	{
		Action = rand() % 6 + 0;
		printf("Action = %d\n", Action);
		switch (Action)
		{
			case 0:
			{
				int count = MyStorage.getCount();
				printf("Size of storage -- %d\n", count);
				break;
			}
			case 1:
			{
				int x = rand() % 100 + 10;
				int y = rand() % 100 + 10;
				Point* p1 = new Point(x, y);
				MyStorage.pushBack(p1);
				printf("Object p1->x = %d successfully pushed in back of the storage\n", p1->x);
				break;
			}
			case 2:
			{
				int x = rand() % 100 + 10;
				int y = rand() % 100 + 10;
				Point* p1 = new Point(x, y);
				MyStorage.pushFront(p1);
				printf("Object p1->x = %d successfully pushed in front of the storage\n", p1->x);
				break;
			}
			case 3:
			{
				if (MyStorage.getCount() > 0)
				{
					int index = rand() % MyStorage.getCount() + 0;
					try
					{
						Point* p4 = MyStorage.getObject(index);
						printf("MyStorage.getObject(%d) = p4->x = %d\n", index, p4->x);
					}
					catch (int t)
					{
						if (t == 0) printf("Error: index is bigger than size of the storage or equal");
					}
				}
				break;
			}

			case 4: 
			{
				if (MyStorage.getCount() > 0)
				{
					int index = rand() % MyStorage.getCount() + 0;
					try
					{
						Point* p4 = MyStorage.getObjectAndDel(index);
						printf("MyStorage.getObjectAndDel(%d) = p4->x = %d\n", index, p4->x);
					}
					catch (int t)
					{
						if (t == 0) printf("Error: index is bigger than size of the storage or equal");
					}
				}
				break;
			}		
			case 5:
			{
				Storage<Point*>::Iterator iter = MyStorage.end();
				int j = 0;
				for (; iter.hasCurrent(); iter--)
				{
					
					try
					{
						Point* p4 = *iter;
						printf("Getting all elements of Storage(reverse): j = %d, *iter->x = %d\n\n", j, p4->x);
						j++;
					}
					catch (int t)
					{
						if (t == 0) printf("Error: index is bigger than size of the storage or equal");
					}
				}
				break;
			}
			
		}
	}
	time_T = clock() - time_T;

	printf("Time execution of program: %lf", (double)time_T / CLOCKS_PER_SEC);
}