// Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

struct node
{
	int data;
	node *next;
};

class stack
{
	private: node *head, *tail;
	public:	stack()
	{
		head = NULL;
		tail = NULL;
	}

	void display()
	{
		node *temp = new node;
		temp = tail;

		while (temp != NULL)
		{
			cout << temp->data << "\t";
			temp = temp->next;
		}
	}

	void push(int value)
	{
		node *temp = new node;
		node *last = new node;
		temp->data = value;
		temp->next = NULL;

		if (head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		} else
		{
			last = tail;
			while (last->next != NULL)
			{
				last = last->next;
			}

			last->next = temp;
			head = temp;
		}
	}

	void pop()
	{
		node *temp = new node;
		temp = tail;

		while (temp->next != NULL)
		{
			head = temp;
			temp = temp->next;
		}
		head->next = NULL;

		delete temp;
	}
};

int main()
{
	stack obj;
	obj.push(1);
	obj.push(2);
	obj.push(3);
	obj.pop();
	obj.push(4);
	obj.push(5);
	obj.push(6);
	obj.pop();
	obj.pop();
	obj.push(7);
	obj.display();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
