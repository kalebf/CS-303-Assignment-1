#pragma once
#include <string>

using namespace std;

const int MAX_SIZE = 100;  // Maximum size of the array

// Function declarations
int readData(int arr[], const string& filename);
int checkExistence(int arr[], int size, int num);
void modifyValue(int arr[], int index, int newValue, int size);
int addValue(int arr[], int newValue, int& size);
void removeOrReplace(int arr[], int& size, int index, bool remove = true);