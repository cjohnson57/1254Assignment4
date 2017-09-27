/*
	Author: Caleb Johnson
	Sort.h
*/

#include "Sort.h"
#include "Student.h"

using namespace std;

Sort::Sort()
{
	compareCount = 0;
	swapCount = 0;
}

int Sort::getcompareCount()
{
	int temp = compareCount;
	compareCount = 0;
	return temp;
}

int Sort::getswapCount()
{
	int temp = swapCount;
	swapCount = 0;
	return temp;
}

void Sort::Swap(Student A[], int i, int j)
{
	Student temp = A[i];
	A[i] = A[j];
	A[j] = temp;
	swapCount++;
}

void Sort::Merge(double (Student::*gradeFunction)() const, Student A[], int low, int pivot, int high)
{
	swapCount++;
	int i, j, k;
	int n1 = pivot - low + 1;
	int n2 = high - pivot;

	Student * L = new Student[n1];
	Student * R = new Student[n2];

	for (i = 0; i < n1; i++)
	{
		L[i] = A[low + i];
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = A[pivot + 1 + j];
	}

	i = 0;
	j = 0;
	k = low;
	while (i < n1 && j < n2)
	{
		compareCount++;
		if ((L[i].*gradeFunction)() <= (R[j].*gradeFunction)())
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		A[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		A[k] = R[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] R;
}

void Sort::BubbleSort(double (Student::*gradeFunction)() const, Student A[], int length)
{
	bool finishedsorting = false;
	while (!finishedsorting)
	{
		finishedsorting = true;
		for (int i = 0; i < length - 1; i++)
		{
			compareCount++;
			if ((A[i].*gradeFunction)() > (A[i + 1].*gradeFunction)())
			{
				finishedsorting = false;
				Swap(A, i, i + 1);
			}
		}
	}
}

void Sort::InsertionSort(double (Student::*gradeFunction)() const, Student A[], int length)
{
	for (int i = 1; i < length; i++)
	{
		Student key = A[i];
		int j = i - 1;
		compareCount++;
		while (j >= 0 && (A[j].*gradeFunction)() > (key.*gradeFunction)())
		{
			A[j + 1] = A[j];
			j--;
			swapCount++;
		}
		A[j + 1] = key;
	}
}

void Sort::SelectionSort(double (Student::*gradeFunction)() const, Student A[], int length)
{
	for (int i = 0; i < length; i++)
	{
		Student min = A[i];
		int minIndex = i;
		for (int j = i + 1; j < length; j++)
		{
			compareCount++;
			if ((A[j].*gradeFunction)() < (min.*gradeFunction)())
			{
				min = A[j];
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			Swap(A, i, minIndex);
		}
	}
}

void Sort::MergeSort(double (Student::*gradeFunction)() const, Student A[], int low, int high)
{
	if (low != high)
	{
		int pivot = (low + high - 1) / 2;
		MergeSort(gradeFunction, A, low, pivot);
		MergeSort(gradeFunction, A, pivot + 1, high);

		Merge(gradeFunction, A, low, pivot, high);
	}
}

void Sort::QuickSort(double (Student::*gradeFunction)() const, Student A[], int low, int high)
{
	if (!(low >= high))
	{
		int pivot = (low + high) / 2;
		int left = low;
		int right = high;
		while (left < pivot && right > pivot)
		{
			compareCount++;
			while ((A[left].*gradeFunction)() < (A[pivot].*gradeFunction)() && left < pivot)
			{
				left++;
				compareCount++;
			}
			compareCount++;
			while ((A[right].*gradeFunction)() > (A[pivot].*gradeFunction)() && right > pivot)
			{
				right--;
				compareCount++;
			}
			if (left < pivot && right > pivot)
			{
				Swap(A, left, right);
			}
		}
		while (left < pivot)
		{
			compareCount++;
			while ((A[left].*gradeFunction)() > (A[pivot].*gradeFunction)())
			{
				Swap(A, left, pivot - 1);
				Swap(A, pivot - 1, pivot);
				pivot--;
				compareCount++;
			}
			left++;
		}
		while (right > pivot)
		{
			compareCount++;
			while ((A[right].*gradeFunction)() < (A[pivot].*gradeFunction)())
			{
				Swap(A, right, pivot + 1);
				Swap(A, pivot, pivot + 1);
				pivot++;
				compareCount++;
			}
			right--;
		}
		QuickSort(gradeFunction, A, low, pivot - 1);
		QuickSort(gradeFunction, A, pivot + 1, high);
	}
}

