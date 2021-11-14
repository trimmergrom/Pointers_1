#include <iostream>

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);
int even_odd(int* arr, const int n, int* s);


int main()
{
	int n;
	int s;
	int k;
	std::cout << "Enter n "; std::cin >> n;

	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);
	even_odd(arr, n, &s);	
	std::cout << "s = " << s << std::endl;
	k = n - s;
	std::cout << "k = " << k;
	int* even = new int[s];
	int* odd = new int[k];

	delete[] arr;
	delete[] even;
	delete[] odd;
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
int even_odd(int* arr, const int n, int* s)
{
	*s = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0) { *s += 1; }
	}
	return *s;
}