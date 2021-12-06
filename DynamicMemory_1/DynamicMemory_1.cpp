#include <iostream>
#include <Windows.h>
#include <conio.h>

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void FillRand(int* arr, const int arr_length);
void Print(int* arr, const int arr_length);
int* Push_back(int* arr, int &arr_length,  int* element);
int* Push_front(int* arr, int &arr_length, int* element);
int* Insert(int* arr,  int &arr_length,  int* namber, int* element);
int* Pop_back(int* arr, int &arr_length);
int* Pop_front(int* arr, int &arr_length);
int* Erase(int* arr, int& arr_length, int* namber);

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN_MODE, &coord);
#ifdef DYNAMIC_MEMORY_1
	int n;
	int element;
	int namber;
	int r;
	char e;

	do
	{
		std::cout << "Enter SIZE PARENT ARRAYS =  "; std::cin >> n;
		std::cout << "Enter srand "; std::cin >> r; std::cout << "\n";
		srand(r);
		int* arr = new int[n];
		
		FillRand(arr, n);
		std::cout << "PARENT ARRAY" << std::endl;
		Print(arr, n); std::cout << "\n\n";

		std::cout << "Enter namber push_bag "; std::cin >> element;
		arr = Push_back(arr,  n, &element);
		std::cout << "Push_back ARRAY" << std::endl;
		Print(arr, n); std::cout << "\n\n";

		std::cout << "Enter namber push_front "; std::cin >> element;
		arr = Push_front(arr, n, &element);
		std::cout << "Push_front ARRAY" << std::endl;
		Print(arr, n); std::cout << "\n\n";

		std::cout << "Enter the number of the inserted element "; std::cin >> namber; std::cout << "\n";
		std::cout << "Enter element "; std::cin >> element; std::cout << "\n";
		arr = Insert(arr, n, &namber, &element);
		std::cout << "Insert  ARRAY" << std::endl;
		Print(arr, n); std::cout << "\n\n";

		arr = Pop_back(arr, n);
		std::cout << "Pop_back ARRAY" << std::endl;
		Print(arr, n); std::cout << "\n\n";

		arr = Pop_front(arr, n);
		std::cout << "Pop_front ARRAY" << std::endl;
		Print(arr, n); std::cout << "\n\n";

		std::cout << "Enter the number of the erased element "; std::cin >> namber; std::cout << "\n";
		arr = Erase(arr, n, &namber);
		std::cout << "Erase  ARRAY" << std::endl;
		Print(arr, n); std::cout << "\n\n";
		delete[] arr;
		
		std::cout << " To exit the program, press ESCAPE, to continue work, press any key." << std::endl;
		e = _getch();
	} while (e != 27);
	#endif // DYNAMIC_MEMORY_1
#ifdef DYNAMIC_MEMORY_2

#endif // DYNAMIC_MEMORY_2

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
int* Push_back(int* arr, int &arr_length, int* element)
{
	int* buffer = new int[arr_length + 1];
	for (int i = 0; i < arr_length; i++) buffer[i] = arr[i];
	delete[] arr;
	buffer[arr_length] = *element;	
	arr_length++;
	return buffer;
}
int* Push_front(int* arr, int &arr_length, int* element)
{
	int* buffer = new int[arr_length + 1];
	for (int i = 0; i < arr_length; i++) buffer[i+1] = arr[i];
	delete[] arr;
	buffer[0] = *element;
	return buffer;
}
int* Insert(int* arr,  int &arr_length,  int* namber, int* element)
{
	int* buffer = new int[++arr_length];
	for (int i = 0; i < *namber; i++) buffer[i] = arr[i];
	for (int i = *namber + 1; i < arr_length; i++) buffer[i] = arr[i - 1];
	delete[] arr;
	buffer[*namber] = *element;
	return buffer;
}
int* Pop_back(int* arr, int &arr_length)
{
	int* buffer = new int[--arr_length];
	for (int i = 0; i < arr_length; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int* Pop_front(int* arr, int &arr_length)
{
	int* buffer = new int[--arr_length];
	for (int i = 0; i < arr_length; i++) buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
int* Erase(int* arr, int &arr_length, int* namber)
{
	int* buffer = new int[--arr_length];
	for (int i = 0; i < *namber - 1; i++) buffer[i] = arr[i];
	for (int i = *namber - 1; i < arr_length; i++) buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;	
}