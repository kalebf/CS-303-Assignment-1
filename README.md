This C++ program provides a menu-driven interface to perform various operations on an array of integers. It includes functions to check for the existence of a number, modify or add elements, and display the array. The program is also designed to handle errors such as out-of-bounds access or array overflow gracefully using exceptions.

Here’s a breakdown of the key components:

Features:
	1.	Check if a Number Exists in the Array: The user can input a number, and the program will check if the number exists in the array, returning its index or notifying that it’s not found.
	2.	Modify a Value at a Specific Index: Users can modify the value at a specific index. Error handling ensures that attempts to access invalid indices result in an error message.
	3.	Add a New Integer to the End of the Array: Users can add a new integer to the array unless the array is already full.
	4.	Remove or Replace an Integer at a Specific Index: The program allows users to either remove an integer from a specific index (shifting the rest of the array) or replace it with 0.
	5.	Display the Array: The user can view the entire content of the array at any time.
	6.	Exit: The program offers an option to exit cleanly.

Error Handling:
	•	Out of Range Access: If a user tries to modify or access an invalid index, an exception is thrown and caught, ensuring the program doesn’t crash.
	•	Array Overflow: When the array reaches its maximum size, attempts to add more elements are prevented by throwing an overflow_error.

Key Points:
	•	Menu Loop: The program continuously displays the menu after each operation, allowing the user to choose new actions until they choose to exit.
	•	Modular Design: Each case in the menu calls separate functions that handle specific tasks such as checking for existence, modifying elements, or adding new values.
	•	File Input: The program reads initial array values from an external file (A1input.txt).

This program structure provides a clear and simple way for users to interact with an array, while also managing common pitfalls like out-of-bound access and array capacity limits.
