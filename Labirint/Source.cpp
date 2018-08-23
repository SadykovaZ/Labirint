#include<iostream>
#include<time.h>
using namespace std;
const int n = 4;
const int m = 5;
int arr[n][m] = { { 1,1,1,0,0 },{ 0,0,1,1,1 },{ 0,0,0,1,1 },{ 1,1,0,0,1} };
bool fs[n][m] = { 0 };
int exitx, exity, flag;
int exit_lab(int i, int j)
{
	if (arr[i][j]==0)
	{
		return 0;
	}
	if (arr[exitx][exity] == 1)
	{
		flag = 1;
		return 0;
	}


	if ((j >= 0 && j < m) && (i >= 0 && i < n))
	{
		
		fs[i][j] = true;
		if (arr[i][j - 1] != 0 && fs[i][j - 1] == false) exit_lab(i, j - 1);
		if (arr[i][j + 1] != 0 && fs[i][j + 1] == false) exit_lab(i, j + 1);
		if (arr[i - 1][j] != 0 && fs[i - 1][j] == false) exit_lab(i - 1, j);
		if (arr[i + 1][j] != 0 && fs[i + 1][j] == false) exit_lab(i + 1, j);
		if (arr[i - 1][j - 1] != 0 && fs[i - 1][j - 1] == false) exit_lab(i - 1, j - 1);
		if (arr[i - 1][j + 1] != 0 && fs[i - 1][j + 1] == false) exit_lab(i - 1, j + 1);
		if (arr[i + 1][j - 1] != 0 && fs[i + 1][j - 1] == false) exit_lab(i + 1, j - 1);
		if (arr[i + 1][j + 1] != 0 && fs[i + 1][j + 1] == false) exit_lab(i + 1, j + 1);
		
	}

}

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	cout << "Ќа основе задачи с инфициированными клетками решите задачу лабиринта" << endl;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	exit_lab(1, 2);


	system("pause");
	return 0;
}