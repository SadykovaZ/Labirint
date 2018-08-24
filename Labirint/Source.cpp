#include <iostream>

using namespace std;

const int n = 4; //строки
const int m = 4; // столбцы

int a[n][m] = { { 1, 1, 0, 0 }, { 0, 1, 1,0 }, { 0, 0, 1,1 }, {0, 0, 1,1} };

bool f[n][m] = { 0 };

void lab(int i, int j)
{

	if ((j >= 0 && j < n) && (i >= 0 && i < m))
	{
		if (a[m - 1][n - 1] == 1 && f[m - 1][n - 1] == true)
		{
			return;
		}
		f[i][j] = true;

		cout << i << " " << j << endl;

		if (a[i][j - 1] == 1 && f[i][j - 1] == false)

			lab(i, j - 1);

		if (a[i][j + 1] == 1 && f[i][j + 1] == false)

			lab(i, j + 1);

		if (a[i - 1][j] == 1 && f[i - 1][j] == false)

			lab(i - 1, j);

		if (a[i + 1][j] == 1 && f[i + 1][j] == false)

			lab(i + 1, j);
	}
}

void lab1(int i, int j) {

	lab(i, j);

	if (f[m - 1][n - 1] == true)
		cout << "Выход есть. " << endl;

	else
		cout << "Выхода нет." << endl;

}

int main()

{
	setlocale(LC_ALL, "Rus");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	lab1(0, 0);

	system("pause");
	return 0;

}