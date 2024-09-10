#include "Operations.h"
#include <iostream>

using namespace std;

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Check if a number exists in the array\n";
    cout << "2. Modify a value at a specific index\n";
    cout << "3. Add a new integer to the end of the array\n";
    cout << "4. Remove an integer at a specific index\n";
    cout << "5. Replace an integer at a specific index with 0\n";
    cout << "6. Display the array\n";
    cout << "7. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;

    try {
        // Read input file into the array
        size = readData(arr, "A1input.txt");

        bool running = true;
        while (running) {
            displayMenu();
            int choice;
            cin >> choice;

            switch (choice) {
            //Check if a number exists in the array
            case 1: { 
                int numToCheck;
                cout << "Enter the number to check: ";
                cin >> numToCheck;//number to check 
                int index = checkExistence(arr, size, numToCheck);
                if (index != -1) {
                    cout << "Number " << numToCheck << " found at index " << index << endl;
                }
                else {
                    cout << "Number " << numToCheck << " not found in the array." << endl;
                }
                break;
            }
            //Modify a value at a specific index
            case 2: {
                int indexToModify, newValue;
                cout << "Enter the index to modify: ";
                cin >> indexToModify;
                cout << "Enter the new value: ";
                cin >> newValue;
                try {
                    modifyValue(arr, indexToModify, newValue, size);
                }
                catch (const out_of_range& e) {//throws an error when choosing an invalid index
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            //Add a new integer to the end of the array
            case 3: {
                int newElement;
                cout << "Enter the new integer to add: ";
                cin >> newElement;
                try {
                    addValue(arr, newElement, size);
                    cout << "Added " << newElement << " to the array." << endl;
                }
                catch (const overflow_error& e) {
                    cerr << "Error: " << e.what() << endl; {//throws an error when adding an integer to a full array
                }
                break;
            }
            //Remove an integer at a specific index
            case 4: {
                int indexToRemove;
                cout << "Enter the index to remove: ";
                cin >> indexToRemove;
                try {
                    removeOrReplace(arr, size, indexToRemove, true);
                    cout << "Removed element at index " << indexToRemove << endl;
                }
                catch (const out_of_range& e) {//throws an error when choosing an invalid index
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            //Replace an integer at a specific index with 0
            case 5: {
                int indexToReplace;
                cout << "Enter the index to replace with 0: ";
                cin >> indexToReplace;
                try {
                    removeOrReplace(arr, size, indexToReplace, false);
                    cout << "Replaced element at index " << indexToReplace << " with 0" << endl;
                }
                catch (const out_of_range& e) {//throws an error when choosing an invalid index
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            //Display the array
            case 6: {
                cout << "Array content:" << endl;
                for (int i = 0; i < size; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            }
            //Exits program
            case 7: {
                running = false;
                cout << "Exiting program." << endl;
                break;
            }
            default: {//makes sure to keep user from choosing an option outside of the options 
                cout << "Invalid choice. Please select again." << endl;
                break;
            }
            }
        }

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}