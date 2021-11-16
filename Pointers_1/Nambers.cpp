#include <iostream>
#include <Windows.h>
#include<conio.h>

void FillRand(int arr[], const int n);
int even_odd_length(int* arr, const int n, int* s, int* k);
void Sort(int* arr, int* even, int* odd, const int n, const int s, const int k);
void Print(int* arr, int* even, int* odd, const int n, const int s, const int k);

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN_MODE, &coord);

	int n;
	int s;
	int k;
	int r;
	char e;

	do
	{
		std::cout << "Enter SIZE of PARENT ARRAYS =  "; std::cin >> n;
		std::cout << "Enter srand "; std::cin >> r;
		srand(r);
		int* arr = new int[n];
		FillRand(arr, n);
		even_odd_length(arr, n, &s, &k);	
		std::cout << "MIN SIZE of EVEN ARRAYS = " << s << std::endl;		
		std::cout << "MIN SIZE of ODD ARRAYS  = " << k << std::endl;
		int* even = new int[s];
		int* odd = new int[k];
		Sort(arr, even, odd, n, s, k);
		Print(arr, even, odd, n, s, k);
		delete[] arr;
		delete[] even;
		delete[] odd;
		std::cout << " To exit the program, press ESCAPE, to continue work, press any key." << std::endl;
	e = _getch();
	} while (e != 27);
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
int even_odd_length(int* arr, const int n, int* s, int* k)
{
	*s = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0) { *s += 1; }
	}
	*k = n - *s;
	return *k, *s;
}
void Sort(int* arr, int* even, int* odd, const int n, const int s, const int k)
{
	int l = 0; int m = 0;
	for (int i = 0; i < n; i++)
	{
		if (*(arr +i) % 2 == 0)	{ *(even + l) = arr[i]; l++; }
		else { *(odd + m) = arr[i]; m++; }
	}
}
void Print(int* arr, int* even, int* odd, const int n, const int s, const int k)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < s; i++)
	{
		std::cout << even[i] << "\t";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < k; i++)
	{
		std::cout << odd[i] << "\t";
	}
	std::cout << std::endl;

}