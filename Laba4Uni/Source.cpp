#include<iostream>
#include<time.h>

using namespace std;

int setValue(const char v[]);
void outputArray(double** arr, int arraySize);
double** create2DArray(unsigned arraySize);
//int getLeftMinimal(int** arr, int arraySize);
//int getRightMaximum(int** arr, int arraySize);
void swapAndGetLeftMinRightMax(double** arr, int arraySize, int& leftMin, int& rightMax);
float averageValue(int a, int b);


void main()
{
	srand(time(NULL));

	int arraySize = 0;

	while (arraySize <= 1)
	{
		arraySize = setValue("arraySize");
		cout.clear();
	}

	double** arr = create2DArray(arraySize);

	outputArray(arr, arraySize);

	/*int leftMin = getLeftMinimal(arr, arraySize);
	int rightMax = getRightMaximum(arr, arraySize);*/


	int minLeft;
	int maxRight;
	swapAndGetLeftMinRightMax(arr, arraySize, minLeft, maxRight);

	cout << "============================================" << endl;
	cout << "leftMin = " << minLeft << endl;
	cout << "rightMax = " << maxRight << endl;
	cout << "averageValue = " << averageValue(minLeft, maxRight) << endl;

	

	cout << "============================================" << endl;
	cout << "After swapping: " << endl;
	outputArray(arr, arraySize);

	for (int i = 0; i < arraySize; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

	arr = nullptr;
}

void outputArray(double** arr, int arraySize)
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

double** create2DArray(unsigned arraySize)
{
	//int** array2D = 0;
	double** array2D = new double* [arraySize];

	for (int h = 0; h < arraySize; h++)
	{
		array2D[h] = new double[arraySize];

		for (int w = 0; w < arraySize; w++)
		{
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

void swapAndGetLeftMinRightMax(double** arr, int arraySize, int& leftMin, int& rightMax)
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

float averageValue(int a, int b)
{
	return (float)(a + b) / 2;
}

