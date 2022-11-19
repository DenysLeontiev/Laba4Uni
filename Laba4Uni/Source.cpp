#include<iostream>
#include<time.h>

using namespace std;

int setValue(const char v[]);
void outputArray(int** arr, int arraySize);
int** create2DArray(unsigned height, unsigned width);
int getLeftMinimal(int** arr, int arraySize);
int getRightMaximum(int** arr, int arraySize);
void swapAndGetLeftMinRightMax(int** arr, int arraySize, int& leftMin, int& rightMax);


void main()
{
	srand(time(NULL));

	const int arraySize = 3;

	int** arr = create2DArray(arraySize, arraySize);

	outputArray(arr, arraySize);

	/*int leftMin = getLeftMinimal(arr, arraySize);
	int rightMax = getRightMaximum(arr, arraySize);*/


	int minLeft;
	int maxRight;
	swapAndGetLeftMinRightMax(arr, arraySize, minLeft, maxRight);

	cout << "============================================" << endl;
	cout << "leftMin = " << minLeft << endl;
	cout << "rightMax = " << maxRight << endl;

	cout << "============================================" << endl;
	cout << "After swapping: " << endl;
	outputArray(arr, arraySize);
}

void outputArray(int** arr, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			cout << arr[i][j] << "\t";
		}

		cout << endl;
	}
}

int setValue(const char v[])
{
	srand(time(NULL));

	int error;
	int value;
	do
	{
		error = 0;
		cout << "Please enter " << v << " = ";
		cin >> value;
		if (cin.fail())
		{
			cout.clear();
			cout << "Please enter a valid number" << endl;
			error = 1;
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (error == 1);

	return value;
}

int** create2DArray(unsigned height, unsigned width)
{
	int** array2D = 0;
	array2D = new int* [height];

	for (int h = 0; h < height; h++)
	{
		array2D[h] = new int[width];

		for (int w = 0; w < width; w++)
		{
			// fill in some initial values
			// (filling in zeros would be more logic, but this is just for the example)
			array2D[h][w] = rand() % 20;
		}
	}

	return array2D;
}

//int getLeftMinimal(int** arr, int arraySize)
//{
//	int leftMin = arr[1][0];
//	for (int i = 0; i < arraySize; i++)
//	{
//		for (int j = 0; j < arraySize; j++)
//		{
//			if (i > j)
//			{
//				if (leftMin > arr[i][j])
//				{
//					leftMin = arr[i][j];
//				}
//			}
//		}
//	}
//
//	return leftMin;
//}
//
//int getRightMaximum(int** arr, int arraySize)
//{
//	int rightMax = arr[0][1];
//	for (int i = 0; i < arraySize; i++)
//	{
//		for (int j = 0; j < arraySize; j++)
//		{
//			if (j > i)
//			{
//				if (rightMax < arr[i][j])
//				{
//					rightMax = arr[i][j];
//				}
//			}
//		}
//	}
//
//	return rightMax;
//}

void swapAndGetLeftMinRightMax(int** arr, int arraySize, int& leftMin, int& rightMax)
{
	int iMin = 1, jMin = 0;
	int iMax = 0, jMax = 1;


	leftMin = arr[1][0];
	rightMax = arr[0][1];

	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			if (i > j)
			{
				if (leftMin > arr[i][j])
				{
					leftMin = arr[i][j];
					iMin = i;
					jMin = j;
				}
			}
			else if (j > i)
			{
				if (rightMax < arr[i][j])
				{
					rightMax = arr[i][j];
					iMax = i;
					jMax = j;
				}
			}
		}
	}

	int temp = arr[iMin][jMin];
	arr[iMin][jMin] = arr[iMax][jMax];
	arr[iMax][jMax] = temp;
}

