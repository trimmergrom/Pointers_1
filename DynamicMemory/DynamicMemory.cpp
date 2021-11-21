#include <iostream>
#include <Windows.h>
#include <conio.h>

void FillRand(int* arr, const int arr_length);
void Print(int* arr, const int arr_length);
void Push_back(int* arr, int* arr_1, const int arr_length, const int arr_1_length, int* element);
void Push_front(int* arr, int* arr_1, const int arr_length, const int arr_1_length, int* element);
void Insert (int* arr, int* arr_1, const int arr_length, const int arr_1_length, int* namber, int* element);
void Pop_back(int* arr, int* arr_1, const int arr_length, const int arr_1_length);
void Pop_front(int* arr, int* arr_1, const int arr_length, const int arr_1_length);
void Erase(int* arr, int* arr_1, const int arr_length, const int arr_1_length, int* namber);

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN_MODE, &coord);

	int n;
	int element = 888;
	int namber;
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
		Print(arr, n); std::cout << "\n\n";
		Push_back(arr, push, n, s, &element);		
		std::cout << "Push_back ARRAY" << std::endl;
		Print(push, s); std::cout << "\n\n";
		Push_front(arr, push, n, s, &element);
		std::cout << "Push_front ARRAY" << std::endl;
		Print(push, s); std::cout << "\n\n";
		std::cout << "Enter the number of the inserted element "; std::cin >> namber; std::cout << "\n";
		Insert(arr, push, n, s, &namber, &element);
		std::cout << "Insert  ARRAY" << std::endl;
		Print(push, s); std::cout << "\n\n";
		Pop_back(arr, pop, n, k);
		std::cout << "Pop_back ARRAY" << std::endl;
		Print(pop, k); std::cout << "\n\n";
		Pop_front(arr, pop, n, k);
		std::cout << "Pop_front ARRAY" << std::endl;
		Print(pop, k); std::cout << "\n\n";
		std::cout << "Enter the number of the erased element "; std::cin >> namber; std::cout << "\n";
		Erase(arr, pop, n, k, &namber);
		std::cout << "Erase  ARRAY" << std::endl;
		Print(pop, k); std::cout << "\n\n";
		delete[] arr;
		delete[] push;
		delete[] pop;
		std::cout << " To exit the program, press ESCAPE, to continue work, press any key." << std::endl;
		e = _getch();
	} while (e != 27);
}
void FillRand(int* arr, const int arr_length)
{
	for (int i = 0; i < arr_length; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void Print(int* arr, const int arr_length)
{
	for (int i = 0; i < arr_length; i++)
	{
		std::cout << arr[i] << "\t";
	}
}
void Push_back(int* arr, int* arr_1, const int arr_length, const int arr_1_length, int* element)
{
	for (int i = 0; i < arr_1_length; i++)
	{
		*(arr_1 + i) = *(arr + i);
	}
	*(arr_1 + arr_1_length - 1) = *element;	
}
void Push_front(int* arr, int* arr_1, const int arr_length, const int arr_1_length, int* element)
{
	for (int i = 1; i < arr_1_length; i++)
	{
		*(arr_1 + i) = *(arr + i - 1);
	}
	*(arr_1) = *element;
}
void Insert(int* arr, int* arr_1, const int arr_length, const int arr_1_length, int* namber, int* element)
{
	for (int i = 0; i < *namber; i++)
	{
		*(arr_1 + i) = *(arr + i);
	}
		*(arr_1 + *namber) = *element;

	for (int i = *namber +1; i < arr_1_length; i++)
	{
		*(arr_1 + i) = *(arr + i - 1);
	}
}
void Pop_back(int* arr, int* arr_1, const int arr_length, const int arr_1_length)
{
	for (int i = 0; i < arr_1_length; i++)
	{
		*(arr_1 + i) = *(arr + i);
	}
}
void Pop_front(int* arr, int* arr_1, const int arr_length, const int arr_1_length)
{
	for (int i = 0; i < arr_1_length; i++)
	{
		*(arr_1 + i) = *(arr + i + 1);
	}
}
void Erase(int* arr, int* arr_1, const int arr_length, const int arr_1_length, int* namber)
{
	for (int i = 0; i < *namber -1; i++)
	{
		*(arr_1 + i) = *(arr + i);
	}
	
	for (int i = *namber - 1; i < arr_1_length; i++)
	{
		*(arr_1 + i) = *(arr + i + 1);
	}
}
