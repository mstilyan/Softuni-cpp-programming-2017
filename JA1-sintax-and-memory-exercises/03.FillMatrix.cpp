#include <iostream>
using namespace std;

char startChar, fillChar;
short arrRows, arrCols;
short startRow, startCol;

bool possibleStepping(char **arr, int y, int x)
{
	return (y >= 0 && y < arrRows) && (x >= 0 && x < arrCols) &&
		arr[y][x] == startChar;
}

void twoDimArrFillTool(char **arr, int y, int x)
{
	if (!possibleStepping(arr, y, x))
		return;

	arr[y][x] = fillChar;
	twoDimArrFillTool(arr, y + 1, x);
	twoDimArrFillTool(arr, y - 1, x);
	twoDimArrFillTool(arr, y, x + 1);
	twoDimArrFillTool(arr, y, x - 1);
}

void inputArr(char **arr)
{
	for (size_t j = 0; j < arrRows; j++)
	{
		for (size_t i = 0; i < arrCols; i++)
			cin >> arr[j][i];
		cin.ignore();
	}
}

void outputArr(char **arr)
{
	for (size_t j = 0; j < arrRows; j++)
	{
		for (size_t i = 0; i < arrCols; i++)
			cout << arr[j][i];
		cout << endl;
	}
}

int main(int argc, char* argv[])
{
	cin >> arrRows >> arrCols;
	cin.ignore();

	char **arr = new char*[arrRows];
	for (size_t i = 0; i < arrRows; i++)
		arr[i] = new char[arrCols]();

	inputArr(arr);
	cin >> fillChar >> startRow >> startCol;
	startChar = arr[startRow][startCol];
	twoDimArrFillTool(arr, startRow, startCol);
	outputArr(arr);

	for (size_t i = 0; i < arrRows; i++)
		delete[] arr[i];

	return 0;
}
