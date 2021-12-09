#include <iostream>
#include <Windows.h>
#include <conio.h>

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
int** allocate(const int rows, const int cols);
void FillRand(int* arr, const int arr_length);
void FillRand(int** arr, const int rows, const int cols);
void Print(int* arr, const int arr_length);
void Print(int** arr, const int rows, const int cols);
int* Push_back(int* arr, int &arr_length,  int* element);
int* Push_front(int* arr, int &arr_length, int* element);
int* Insert(int* arr,  int &arr_length,  int* namber, int* element);
int* Pop_back(int* arr, int &arr_length);
int* Pop_front(int* arr, int &arr_length);
int* Erase(int* arr, int& arr_length, int* namber);
int** Push_row_back(int** arr, int& rows, const int cols);
int** Push_row_front(int** arr, int& rows, const int cols);
int** Insert_row(int** arr, int& rows, const int cols, int& namber);
void Push_col_back(int** arr, const int rows, int& cols);
void Push_col_front(int** arr, const int rows, int& cols);
void Erase_col(int** arr, const int rows, int& cols, int& namber);
void clear(int** arr, const int rows);

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
	int ROWS;
	int COLS;
	int namber;
	std::cout << "Enter ROWS "; std::cin >> ROWS; std::cout << std::endl;
	std::cout << "Enter COLS "; std::cin >> COLS; std::cout << std::endl;
	int** arr = allocate(ROWS, COLS);
	FillRand(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	std::cout << "\n========================================================\n";
	std::cout << "Push_row_back \n";
	arr = Push_row_back(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	std::cout << "\n========================================================\n";
	
	std::cout << "Push_row_front \n";
	arr = Push_row_front(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	
	std::cout << "\n========================================================\n";
	std::cout << "Enter the insertion position number "; std::cin >> namber; std::cout << "\n";
	arr = Insert_row(arr, ROWS, COLS, namber);
	Print(arr, ROWS, COLS);

	std::cout << "\n========================================================\n";
	std::cout << "Push_col_back \n";
	Push_col_back(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);

	std::cout << "\n========================================================\n";
	std::cout << "Push_col_front \n";
	Push_col_front(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);

	std::cout << "\n========================================================\n";
	std::cout << "Erase_col \n";
	std::cout << "Enter the number of the position to be deleted "; std::cin >> namber; std::cout << "\n";
	Erase_col(arr, ROWS, COLS, namber);
	Print(arr, ROWS, COLS);

	clear(arr, ROWS);

#endif // DYNAMIC_MEMORY_2

}
int** allocate(const int rows, const int cols)
{
	int** arr = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}
void FillRand(int* arr, const int arr_length)
{
	for (int i = 0; i < arr_length; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}
}
void Print(int* arr, const int arr_length)
{
	for (int i = 0; i < arr_length; i++)
	{
		std::cout << arr[i] << "\t";
	}
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << arr[i][j] << "\t";
		}
		std::cout << std::endl;
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
int** Push_row_back(int** arr,  int& rows, const int cols)
{
	int** buffer = new int* [rows+1]{};
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	delete[] arr;
	buffer[rows] = new int[cols] {};
	rows++;
	return buffer;
}
int** Push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1]{};
	for (int i = 0; i < rows; i++) buffer[i+1] = arr[i];
	delete[] arr;
	buffer[0] = new int[cols] {};
	rows++;
	return buffer;
}
int** Insert_row(int** arr, int& rows, const int cols, int& namber)
{
	int** buffer = new int* [rows + 1]{};
	for (int i = 0; i < namber; i++) buffer[i] = arr[i];
	for (int i = namber + 1; i <= rows; i++) buffer[i] = arr[i-1];
	delete[] arr;
	buffer[namber] = new int[cols] {};
	rows++;
	return buffer;
}
void Push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;	
}
void Push_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 1; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void Erase_col(int** arr, const int rows, int& cols, int& namber)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
		for (int j = 0; j < namber -1; j++) buffer[j] = arr[i][j];
		for (int j = namber - 1; j < cols; j++) buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void clear(int** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}