/*
        Author: Caleb Johnson
        main.cpp
*/

#include <string>
#include <iostream>
#include <fstream>
#include <istream>
#include <chrono>
#include "Student.h"
#include "Sort.h"

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

using namespace std;

void setList(Student list1[], Student list2[], int size)
{
	for (int i = 0; i < size; i++)
	{
		list2[i] = list1[i];
	}
}

void displayResults(string sort, string grade, int comparisons, int swaps, double time)
{
	cout << "*********************************" << endl;
	cout << "Sort:\t" << sort << endl;
	cout << "Grade:\t" << grade << endl;
	cout << "Comparisons:\t" << comparisons << endl;
	if (sort == "Merge")
	{
		cout << "Merges:\t" << swaps << endl;
	}
	else
	{
		cout << "Swaps:\t" << swaps << endl;
	}
	cout << "Time taken:\t" << time << " seconds" << endl;
}

void writeResults(string name, Student A[], int length)
{
	string list = "";
	for (int i = 0; i < length; i++)
	{
		list += A[i].toString() + '\n';
	}
	ofstream g;
	g.open(name + ".txt");
	g << list;
	g.close();
	list = list;
}

int main(int argc, char** argv)
{
	//argc = 2; //For testing

	if(argc < 2)
	{
		cout << "You must enter a filename by command line." << endl;
		cout << "The command should be as follows:" << endl;
		cout << argv[0] << " [file containing roster]." << endl;
		return 0;
	}

	ifstream f;
	f.open(argv[1]); //should be argv[1], for testing "C:\\Users\\Caleb\\Desktop\\1254 Projects\\prog3\\testRoster.txt"
	if(!f)
	{
		cout << "File " << argv[1] << " does not exist." << endl;
		return 0;
	}
	
	double hwWeight, qzWeight, fxWeight;
	int numInRoster;
	string tempS;
	
	f >> hwWeight >> qzWeight >> fxWeight >> numInRoster;

	Student list1[10000];
	int length = 0;

	for(int x = 0; x < numInRoster; x++)
	{
		
		int tempHw[4];
		int tempQz[4];
		int tempFx;
		string tempFn;
		string tempLn;
		f >> tempLn >> tempFn;
		for(int i = 0; i < 4; i++)
			f >> tempHw[i];
		for(int i = 0; i < 4; i++)
			f >> tempQz[i];
		f >> tempFx;
		
		Student *tempStudent = new Student(tempLn, tempFn, tempQz, tempHw, tempFx, qzWeight, hwWeight, fxWeight);
		list1[length] = *tempStudent;
		length++;
		
	}
	
	f.close();
	
	Student list2[10000];

	setList(list1, list2, length); //Makes a second list to be sorted. The first list is saved so the original order can be restored after the list is sorted

	Sort sorter;
	auto start = chrono::high_resolution_clock::now();
	auto finish = chrono::high_resolution_clock::now();
	auto microseconds = chrono::duration_cast<chrono::microseconds>(finish - start);
	double seconds = 0;
	
	//Bubble sort, base grade
	/******************************************************************************/
	start = chrono::high_resolution_clock::now();
	sorter.BubbleSort(&Student::calculateGrade, list2, length); //Bubble sort, base grade
	finish = chrono::high_resolution_clock::now();
	microseconds = chrono::duration_cast<chrono::microseconds>(finish - start);
	seconds = static_cast<double>(microseconds.count()) / 1000000;
	displayResults("Bubble", "Base", sorter.getcompareCount(), sorter.getswapCount(), seconds);
	writeResults("bubbleSortByGrade", list2, length);
	setList(list1, list2, length);
	/******************************************************************************/

	//Bubble sort, adjusted grade
	/******************************************************************************/
	start = chrono::high_resolution_clock::now();
	sorter.BubbleSort(&Student::calculateAdjustedGrade, list2, length); //Bubble sort, base grade
	finish = chrono::high_resolution_clock::now();
	microseconds = chrono::duration_cast<chrono::microseconds>(finish - start);
	seconds = static_cast<double>(microseconds.count()) / 1000000;
	displayResults("Bubble", "Adjusted", sorter.getcompareCount(), sorter.getswapCount(), seconds);
	writeResults("bubbleSortByAdjustedGrade", list2, length);
	setList(list1, list2, length);
	/******************************************************************************/

	//Insertion sort, base grade
	/******************************************************************************/
	start = chrono::high_resolution_clock::now();
	sorter.InsertionSort(&Student::calculateGrade, list2, length); //Bubble sort, base grade
	finish = chrono::high_resolution_clock::now();
	microseconds = chrono::duration_cast<chrono::microseconds>(finish - start);
	seconds = static_cast<double>(microseconds.count()) / 1000000;
	displayResults("Insertion", "Base", sorter.getcompareCount(), sorter.getswapCount(), seconds);
	writeResults("insertionSortByGrade", list2, length);
	setList(list1, list2, length);
	/******************************************************************************/

	//Insertion sort, adjusted grade
	/******************************************************************************/
	start = chrono::high_resolution_clock::now();
	sorter.InsertionSort(&Student::calculateAdjustedGrade, list2, length); //Bubble sort, base grade
	finish = chrono::high_resolution_clock::now();
	microseconds = chrono::duration_cast<chrono::microseconds>(finish - start);
	seconds = static_cast<double>(microseconds.count()) / 1000000;
	displayResults("Insertion", "Adjusted", sorter.getcompareCount(), sorter.getswapCount(), seconds);
	writeResults("insertionSortByAdjustedGrade", list2, length);
	setList(list1, list2, length);
	/******************************************************************************/

	//Selection sort, base grade
	/******************************************************************************/
	start = chrono::high_resolution_clock::now();
	sorter.SelectionSort(&Student::calculateGrade, list2, length); //Bubble sort, base grade
	finish = chrono::high_resolution_clock::now();
	microseconds = chrono::duration_cast<chrono::microseconds>(finish - start);
	seconds = static_cast<double>(microseconds.count()) / 1000000;
	displayResults("Selection", "Base", sorter.getcompareCount(), sorter.getswapCount(), seconds);
	writeResults("selectionSortByGrade", list2, length);
	setList(list1, list2, length);
	/******************************************************************************/

	//Selection sort, adjusted grade
	/******************************************************************************/
	start = chrono::high_resolution_clock::now();
	sorter.SelectionSort(&Student::calculateAdjustedGrade, list2, length); //Bubble sort, base grade
	finish = chrono::high_resolution_clock::now();
	microseconds = chrono::duration_cast<chrono::microseconds>(finish - start);
	seconds = static_cast<double>(microseconds.count()) / 1000000;
	displayResults("Selection", "Adjusted", sorter.getcompareCount(), sorter.getswapCount(), seconds);
	writeResults("selectionSortByAdjustedGrade", list2, length);
	setList(list1, list2, length);
	/******************************************************************************/

	//Merge sort, base grade
	/******************************************************************************/
	start = chrono::high_resolution_clock::now();
	sorter.MergeSort(&Student::calculateGrade, list2, 0, length - 1); //Bubble sort, base grade
	finish = chrono::high_resolution_clock::now();
	microseconds = chrono::duration_cast<chrono::microseconds>(finish - start);
	seconds = static_cast<double>(microseconds.count()) / 1000000;
	displayResults("Merge", "Base", sorter.getcompareCount(), sorter.getswapCount(), seconds);
	writeResults("mergeSortByGrade", list2, length);
	setList(list1, list2, length);
	/******************************************************************************/

	//Merge sort, adjusted grade
	/******************************************************************************/
	start = chrono::high_resolution_clock::now();
	sorter.MergeSort(&Student::calculateAdjustedGrade, list2, 0, length - 1); //Bubble sort, base grade
	finish = chrono::high_resolution_clock::now();
	microseconds = chrono::duration_cast<chrono::microseconds>(finish - start);
	seconds = static_cast<double>(microseconds.count()) / 1000000;
	displayResults("Merge", "Adjusted", sorter.getcompareCount(), sorter.getswapCount(), seconds);
	writeResults("mergeSortByAdjustedGrade", list2, length);
	setList(list1, list2, length);
	/******************************************************************************/

	//Quick sort, base grade
	/******************************************************************************/
	start = chrono::high_resolution_clock::now();
	sorter.QuickSort(&Student::calculateGrade, list2, 0, length - 1); //Bubble sort, base grade
	finish = chrono::high_resolution_clock::now();
	microseconds = chrono::duration_cast<chrono::microseconds>(finish - start);
	seconds = static_cast<double>(microseconds.count()) / 1000000;
	displayResults("Quick", "Base", sorter.getcompareCount(), sorter.getswapCount(), seconds);
	writeResults("quickSortByGrade", list2, length);
	setList(list1, list2, length);
	/******************************************************************************/

	//Quick sort, adjusted grade
	/******************************************************************************/
	start = chrono::high_resolution_clock::now();
	sorter.QuickSort(&Student::calculateAdjustedGrade, list2, 0, length - 1); //Bubble sort, base grade
	finish = chrono::high_resolution_clock::now();
	microseconds = chrono::duration_cast<chrono::microseconds>(finish - start);
	seconds = static_cast<double>(microseconds.count()) / 1000000;
	displayResults("Quick", "Adjusted", sorter.getcompareCount(), sorter.getswapCount(), seconds);
	writeResults("quickSortByAdjustedGrade", list2, length);
	setList(list1, list2, length);
	/******************************************************************************/
	
	return 0;
}
