#include <iostream>
#include <Windows.h>
#include <conio.h>

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);
void Push_back(int* arr, int* push, const int n, const int s, int* element);
void Push_front(int* arr, int* arr_1, const int n);
void Insert (int* arr, int* arr_1, const int n);
void Pop_back(int* arr, int* arr_1, const int n);
void Pop_front(int* arr, int* arr_1, const int n);
void Erase(int* arr, int* arr_1, const int n);


int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN_MODE, &coord);

	int n;
	int element = 888;	
	int r;
	char e;

	do
	{
		std::cout << "Enter SIZE PARENT ARRAYS =  "; std::cin >> n;
		std::cout << "Enter srand "; std::cin >> r; std::cout << "\n";
		srand(r);
		int* arr = new int[n];
		int s = n + 1;
		int k = n - 1;
		int* push = new int[s];
		int* pop = new int[k];
		FillRand(arr, n);
		std::cout << "PARENT ARRAY" << std::endl;
		Print(arr, n);
		Push_back(arr, push, n, s, &element);		
		std::cout << "Push_back array" << std::endl;
		Print(push, s);
		delete[] arr;
		delete[] push;
		delete[] pop;
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

void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;
	std::cout << std::endl;	
	
}
void Push_back(int* arr, int* push, const int n, const int s, int* element)
{
	for (int i = 0; i < s; i++)
	{
		*(push + i) = *(arr + i);
	}
	*(push + s - 1) = *element;
	
}
void Push_front(int* arr, int* arr_1, int* n)
{

}
void Insert(int* arr, int* arr_1, const int n)
{

}
void Pop_back(int* arr, int* arr_1, const int n)
{

}
void Pop_front(int* arr, int* arr_1, const int n)
{

}
void Erase(int* arr, int* arr_1, const int n)
{

}
