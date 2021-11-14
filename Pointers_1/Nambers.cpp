#include <iostream>

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);


int main()
{
	int n;
	int s;
	int k;
	std::cout << "Enter n "; std::cin >> n;

	int* arr = new int[n];
	//int* even = new int[s];
	//int* odd = new int[k];

	FillRand(arr, n);
	Print(arr, n);

	delete[] arr;
	//delete[] even;
	//delete[] odd;
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
}