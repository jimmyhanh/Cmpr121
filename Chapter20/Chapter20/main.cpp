#include<iostream>
#include "input.h"


int menuOption();
void Challenge1();
void Challenge3();
void Challenge4();
void Challenge6();
void Challenge7();
void Challenge11();
int main()
{
	do
	{
		switch (menuOption())
		{
		case 0: exit(1); break;
		case 1: Challenge1(); break;
		case 3: Challenge3(); break;
		case 4: Challenge4(); break;
		case 6: Challenge6(); break;
		case 7: Challenge7(); break;
			// case 8: Challenge8(); break;
			// case 9: Challenge9(); break;
			// case 10: Challenge10(); break;
		case 11: Challenge11(); break;
			// case 12: Challenge12(); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);
	return EXIT_SUCCESS;
}
long long FactorialIterative(long long n)
{
	long long result = 1;
	for (int i = 1; i <= n; i++)
		result *= i;
	return result;
}
long long FactorialRecursive(long long n)
{
	if (n == 1)
		return 1;
	else
		return n * FactorialRecursive(n - 1);
}

int menuOption()
{
	cout << "\nChapter 20";
	cout << "\n======================";
	cout << "\n1. Challenge";
	cout << "\n3. Challenge";
	cout << "\n4. Challenge";
	cout << "\n6. Challenge";
	cout << "\n7. Challenge";
	cout << "\n11. Challenge";
	return inputInteger("\nOption: ", 0, 12);
}
void Challenge1()
{
	int n = inputInteger("\nEnter a value of n: ", 1,25);
	cout << "iterative: " << n << "! = " << FactorialIterative(n) << '\n';
	cout << "recursive: " << n << "! = " << FactorialRecursive(n) << '\n';
}
void Challenge3()
{
	cout << "\nsee GeekForGeeks on recursive.\n";
}
int ArraySumInterative(int array[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += array[i];
	return sum;
}
int ArraySumRecursive(int array[], int size)
{
	if (size == 0)
		return 0;
	else
		return array[size-1] + ArraySumRecursive(array, size - 1);
}
void Challenge4()
{
	const int SIZE = 5;
	int array[SIZE] = { 6,8,2,33,666 };
	cout << "\narray sum (interative) : " << ArraySumInterative(array, SIZE) << '\
		n';
		cout << "\narray sum (recursive) : " << ArraySumRecursive(array, SIZE) << '\n';
}

long long PowerInterative(int base, int raise)
{
	long long result = 1;
	for (int i = 1; i <= raise; i++)
		result *= base;
	return result;
}

long long PowerRecursive(int base, int raise)
{
	if (raise == 0)
		return 1;
	else
		return base * PowerRecursive(base, raise - 1);
}
void Challenge6()
{
	int base = inputInteger("\nEnter the base value: ", true);
	int raise = inputInteger("\nEnter the raise value: ", true);
	cout << base << "^" << raise << " (interative): " << PowerInterative(base,
		raise) << '\n';
	cout << base << "^" << raise << " (recursive): " << PowerRecursive(base, raise)
		<< '\n';
}

int SumIterative(int n)
{
	int sum = 0;
	for (int i = 0; i <= n; i++)
		sum += i;
	return sum;
}

int SumRecursive(int n)
{
	if (n == 0)
		return 0;
	else
		return n + SumRecursive(n - 1);
}

void Challenge7()
{
	int n = inputInteger("\nEnter a value of n: ", true);
	cout << "iterative: " << n << " sum = " << SumIterative(n) << '\n';
	cout << "recursive: " << n << " sum = " << SumRecursive(n) << '\n';
}

bool isPalindrome(string input, int begin, int end)
{
	if (begin > end)
		return true;
	else
	{
		if (input[begin] != input[end])
			return false;
		else
			return isPalindrome(input, begin + 1, end - 1);
	}
}

void Challenge11()
{
	string input = inputString("\nEnter a string: ", true);
	for (int i = input.length() - 1; i >= 0; i-- )
		cout << input[i];
	cout << '\n';
	cout << input << " : " << isPalindrome(input, 0, input.length() -1) << '\n';
}

