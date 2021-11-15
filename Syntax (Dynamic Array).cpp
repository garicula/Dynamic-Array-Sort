// Garrick Morley
// CPSC 200 Project 5 B
// This program outputs numbers from a file in ascending order using a dynamic array

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cmath>
#include <fstream>
#include <cassert>
using namespace std;

// Sorts array[0..n-1] into ascending order
void sort (double array[], int n)
{
int i, j;
double tmp;

for (i=0; i<n-1; ++i)
    for (j=i+1; j<n; ++j)
        if (array[i] > array[j])
        {
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
}

main()
{
	double score;
	int i = 0;
	int a = 0;
	int size = 0;
	string file;
	
	cout << "Enter the file name: " << endl;
	cin >> file;

	//open the file
	ifstream input;
	input.open("file");
	
	//make sure it opened correctly
	if (input.fail())
	cout << "File did not open correctly" << endl;	
	
	//get the count (first line)
	while ((input >> score) && ( i < 0))
	{
		i++;
	}
	
	size = score;
	
	//create dynamic array
	typedef double* doublePtr;
	doublePtr d;
	d = new double[size];
	
	//feed numbers into array
	while (input >> score)
	{
		d[a] = score;
		a++;
	}
	
	//sort the numbers
	sort(d, size);
	
	for(int alpha = 0; alpha < size; alpha++)
	{
		cout << d[alpha] << endl;
	}
		
}








