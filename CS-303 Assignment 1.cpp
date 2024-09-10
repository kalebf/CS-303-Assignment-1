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
            case 1: {//Check if a number exists in the array
                int numToCheck;
                cout << "Enter the number to check: ";
                cin >> numToCheck;
                int index = checkExistence(arr, size, numToCheck);
                if (index != -1) {
                    cout << "Number " << numToCheck << " found at index " << index << endl;
                }
                else {
                    cout << "Number " << numToCheck << " not found in the array." << endl;
                }
                break;
            }
            case 2: {//Modify a value at a specific index
                int indexToModify, newValue;
                cout << "Enter the index to modify: ";
                cin >> indexToModify;
                cout << "Enter the new value: ";
                cin >> newValue;
                try {
                    modifyValue(arr, indexToModify, newValue, size);
                }
                catch (const out_of_range& e) {//error if index choice is out of bound
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 3: {//Add a new integer to the end of the array
                int newElement;
                cout << "Enter the new integer to add: ";
                cin >> newElement;
                try {
                    addValue(arr, newElement, size);
                    cout << "Added " << newElement << " to the array." << endl;
                }
                catch (const overflow_error& e) {//error if array is full, can't add more 
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 4: {//Remove an integer at a specific index
                int indexToRemove;
                cout << "Enter the index to remove: ";
                cin >> indexToRemove;
                try {
                    removeOrReplace(arr, size, indexToRemove, true);
                    cout << "Removed element at index " << indexToRemove << endl;
                }
                catch (const out_of_range& e) {//error if index choice is out of bound
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 5: {//Replace an integer at a specific index with 0
                int indexToReplace;
                cout << "Enter the index to replace with 0: ";
                cin >> indexToReplace;
                try {
                    removeOrReplace(arr, size, indexToReplace, false);
                    cout << "Replaced element at index " << indexToReplace << " with 0" << endl;
                }
                catch (const out_of_range& e) {//error if index choice is out of bound
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 6: {//Display the array
                cout << "Array content:" << endl;
                for (int i = 0; i < size; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            }
            case 7: {//Exits program
                running = false;
                cout << "Exiting program." << endl;
                break;
            }
            default: {//Makes sure user makes a choice from the menu
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