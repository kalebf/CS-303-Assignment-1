#include "Operations.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

// Function to read data from file into array
int readData(int arr[], const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        throw runtime_error("Error opening input file!");
    }

    int i = 0;
    while (inputFile >> arr[i] && i < MAX_SIZE) {
        i++;
    }

    inputFile.close();
    return i;  // Return the number of elements read
}

// Function to check if an integer exists in the array
int checkExistence(int arr[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return i;  // Return the index where the number is found
        }
    }
    return -1;  // Return -1 if not found
}

// Function to modify the value of an integer at a specific index
void modifyValue(int arr[], int index, int newValue, int size) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range!");
    }

    int oldValue = arr[index];
    arr[index] = newValue;
    cout << "Old value: " << oldValue << ", New value: " << newValue << endl;
}

// Function to add a new integer to the end of the array
int addValue(int arr[], int newValue, int& size) {
    if (size >= MAX_SIZE) {
        throw overflow_error("Array is full! Cannot add new element.");
    }

    arr[size++] = newValue;
    return size;
}

// Function to remove an integer at a specific index or replace it with 0
void removeOrReplace(int arr[], int& size, int index, bool remove) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range!");
    }

    if (remove) {
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }
    else {
        arr[index] = 0;
    }
}
