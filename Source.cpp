#include<iostream>
using namespace std;

int simpleIS = 0;
int binaryIS = 0;
bool interpolationSearch(int* arr, int top, int bottom, int key)
{
	bool result;
	int size = top - bottom + 1;
	if (bottom <= top && key >= arr[bottom] && key <= arr[top])
	{
		if (size == 1)
		{
			if (arr[top] == key)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		int sub = (top - bottom);
		int num = key - arr[bottom];
		int den = arr[top] - arr[bottom];
		float div = (double)num / den;
		int i = sub * div + bottom;
		if (arr[i] == key)
		{
			return true;
		}
		else
		{
			if (arr[i] > key)
			{
				++simpleIS;
				result = interpolationSearch(arr, i - 1, bottom, key);
			}
			if (arr[i] < key)
			{
				++simpleIS;
				result = interpolationSearch(arr, top, i + 1, key);
			}
			return result;
		}
	}
	else
	{
		return false;
	}
}
bool interpolationSearchBinary(int* arr, int top, int bottom, int key)
{
	bool result;
	int size = top - bottom + 1;
	if (bottom <= top && key >= arr[bottom] && key <= arr[top])
	{
		if (size == 1)
		{
			if (arr[top] == key)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		int sub = (top - bottom);
		int num = key - arr[bottom];
		int den = arr[top] - arr[bottom];
		float div = (double)num / den;
		int i = sub * div + bottom;
		if (arr[i] == key)
		{
			return true;
		}
		else
		{
			if (arr[(int)bottom + (top - bottom) / 2] == key)
			{
				result = true;
			}
			if (arr[(int)bottom + (top - bottom) / 2] > key)
			{
				++binaryIS;
				result = interpolationSearchBinary(arr, (int)bottom + (top - bottom) / 2 - 1, bottom, key);
			}
			if (arr[(int)bottom + (top - bottom) / 2] < key)
			{
				++binaryIS;
				result = interpolationSearchBinary(arr, top, (int)bottom + (top - bottom) / 2 + 1, key);
			}
			return result;
		}
	}
	else
	{
		return false;
	}
}
int main()
{
	int n = 10;
	int arr[] = {10, 11, 15, 18, 20, 21, 25, 27, 33, 34 };
	int key = 12;
	cout <<"Element Found by Simple interpolation search: " << interpolationSearch(arr, n - 1, 0, key) << "\n";
	cout << "No of Bad Predictions by Interpolation Search: " << simpleIS << "\n";
	cout<<"Element Found by binary interpolation search: " << interpolationSearchBinary(arr, n - 1, 0, key)<<"\n";
	return 0;
}