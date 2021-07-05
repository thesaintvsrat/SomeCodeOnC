#include <iostream> 
#include <stdio.h> 

int** dynamic_memory(int n, int m); 
int matrix_enter(int n, int m, int** ptr_arr); 
void matrix_print(int n, int m, int** ptr_arr);
bool Proverka(int n, int m, int** ptr_arr); 

int main()
{
	int n, m;
	printf("Enter n: "); scanf_s("%d", &n);
	printf("Enter m: "); scanf_s("%d", &m);
	int** ptr_arr;
	ptr_arr = dynamic_memory(n, m);
	matrix_enter(n, m, ptr_arr);
	matrix_print(n, m, ptr_arr);
	if (Proverka)
	{
		printf("Yavlyaetsa. \n");
	}
	else
	{
		printf("Ne yavlyaetsa. \n");
	}
	system("pause");
	return 0;
}

int** dynamic_memory(int n, int m)
{
	int** ptr_arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		ptr_arr[i] = new int[m];
	}
	return ptr_arr;
}

int matrix_enter(int n, int m, int** ptr_arr)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &ptr_arr[i][j]);
		}
	}
	return **ptr_arr;
}
// Печать матрицы 
void matrix_print(int n, int m, int** ptr_arr)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%6d", ptr_arr[i][j]);
		}
		printf("\n");
	}
}
// Проверка строк, столбцов и диагоналей матрицы 
bool Proverka(int n, int m, int** ptr_arr)
{
	// Проверка диагоналей 
	int k1 = 0, k2 = 0;
	int j = m - 1;
	for (int i = 0; i < n; i++)
	{
		k1 = k1 + ptr_arr[i][i];
		k2 = k2 + ptr_arr[j][j];
		j = j - 1;
	}
	if (k1 != k2)
	{
		return false;
	}
	int c = k1;
	// Проверка строк и столбцов 
	k1 = 0; k2 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			k1 = k1 + ptr_arr[i][j];
			k2 = k2 + ptr_arr[j][i];
		}
		if (k1 != c)
		{
			return false;
		}
		if (k2 != c)
		{
			return false;
		}
	}
	return true;
}