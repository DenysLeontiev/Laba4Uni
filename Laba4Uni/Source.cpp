#include<iostream>
#include<time.h>

using namespace std;

int setValue(const char v[]);
void outputArray(double** arr, int arraySize);
double** create2DArray(unsigned arraySize);
void swapAndGetLeftMinRightMax(double** arr, int arraySize, double& leftMin, double& rightMax);
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

	double minLeft;
	double maxRight;
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
		delete[] * (arr + i);
		//delete[] arr[i];
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
			//cout << arr[i][j] << "\t";
			cout << *(*(arr + i) + j) << "\t";
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
		//array2D[h] = new double[arraySize];
		*(array2D + h) = new double[arraySize];

		for (int w = 0; w < arraySize; w++)
		{
			//array2D[h][w] = rand() % 20;
			//array2D[h][w] = rand() % 20;
			*(*(array2D + h) + w) = rand() % 20;
		}
	}

	return array2D;
}

void swapAndGetLeftMinRightMax(double** arr, int arraySize, double& leftMin, double& rightMax)
{
	int iMin = 1, jMin = 0;
	int iMax = 0, jMax = 1;


	/*leftMin = arr[1][0];
	rightMax = arr[0][1];*/
	leftMin = *(*(arr + 1) + 0);
	rightMax = *(*(arr + 0) + 1);

	for (int i = 0; i < arraySize; i++)
	{
		for (int j = i + 1; j < arraySize; j++)
		{

			if (*(*(arr + i) + j) > rightMax)
			{
				iMax = i;
				jMax = j;
				rightMax = *(*(arr + i) + j);
			}

			if (*(*(arr + j) + i) < leftMin)
			{
				leftMin = *(*(arr + j) + i);
				iMin = j;
				jMin = i;
			}
			//if (i > j)
			//{
			//	if (leftMin >/* arr[i][j]*/  *(*(arr + i) + j))
			//	{
			//		leftMin = *(*(arr + i) + j);
			//		iMin = i;
			//		jMin = j;
			//	}
			//}
			//else if (j > i)
			//{
			//	if (rightMax < *(*(arr + i) + j))
			//	{
			//		rightMax = *(*(arr + i) + j);
			//		iMax = i;
			//		jMax = j;
			//	}
			//}
		}
	}

	/*int temp = arr[iMin][jMin];
	arr[iMin][jMin] = arr[iMax][jMax];
	arr[iMax][jMax] = temp;*/

	double temp = *(*(arr + iMin) + jMin);
	*(*(arr + iMin) + jMin) = *(*(arr + iMax) + jMax);
	*(*(arr + iMax) + jMax) = temp;
}

float averageValue(int a, int b)
{
	return (float)(a + b) / 2;
}

