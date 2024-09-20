#pragma once
#include<list>
using namespace std;

template<class T>
class MyQueue
{
private:
	list<T> array;

public:
	MyQueue()
	{
		array.clear();
	}

	void enqueue(T element)
	{
		array.push_back(element);
	}


	bool isEmpty() const
	{
		return array.empty();
	}

	T back() const
	{
		return array.back();
	}

	T front() const
	{
		return array.front();
	}

	void dequeue()
	{
		array.pop_front();
	}

	void display() const
	{
		for (auto element : array)
			cout << element << '\n';
	}
};

