/*
	Author: Caleb Johnson
	Sort.h
*/

#include <iostream>
#include "Student.h"

using namespace std;

class Sort
{
private:
	int compareCount; //Keeps track of how many comparisons have been made
	int swapCount; //Keeps track of how many swaps have been made
public:
	Sort();
	int getcompareCount();
	int getswapCount();
	void Swap(Student A[], int i, int j);
	void Merge(double (Student::*gradeFunction)() const, Student A[], int low, int pivot, int high);
	void BubbleSort(double (Student::*gradeFunction)() const, Student A[], int length);
	void InsertionSort(double (Student::*gradeFunction)() const, Student A[], int length);
	void SelectionSort(double (Student::*gradeFunction)() const, Student A[], int length);
	void MergeSort(double (Student::*gradeFunction)() const, Student A[], int low, int high);
	void QuickSort(double (Student::*gradeFunction)() const, Student A[], int low, int high);
};
