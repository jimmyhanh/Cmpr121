#pragma once
#include <vector>
using namespace std;

template<class T>
class MyStack
{
private:
	vector<T> array;

public:
	MyStack()
	{
		array.clear();
	}


	void push(T element)
	{
		array.push_back(element);
	}

	void pop()
	{
		array.pop_back();
	}

	bool isEmpty()
	{
		return array.empty();
	}


	T top() const
	{
		return array.back();
	}

	void display() const
	{
		for (auto i = array.rbegin(); i != array.rend(); i++)
			cout << *i << "\n";
	}
};



