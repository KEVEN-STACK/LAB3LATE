/** \file Lab3.cpp
 *
 *  \brief     Program with Menu that executes various calculations based on input.
 *  \author    keven aggrey
 *  \version   1.0
 *  \date      17/04/2022
 */

#include <iostream>
#include <cassert>
using namespace std;

// Function prototypes
int printMenu();
void fillInArray(int[], const int);
void multArrays(const int[], const int[], int[], const int);
void displayArray(const int[], const int);
int sumOddArray(const int[], const int);
bool isAllPositive(const int[], const int);
void avgOddArray(const int[], const int, int&);

/**
 * <code>main</code> is the main function of this program.
 * <BR>
 * @return Returns 0 if success, any other value otherwise.
 */
int main() {
    int choice, avg = 0;
    const int SIZE = 10;


    // Initialize array price
    int price[SIZE] = { 12, 4, 8, 1, 17, 2, 4, 2, 9, 1 };
    // Declare array quantity and total
    int quantity[SIZE], total[SIZE];

    // Interactive menu
    do {
        choice = printMenu();

        switch (choice) {
            // Enter quantity
            case 1:
                fillInArray(quantity, SIZE);
                break;
                // Calculate total
            case 2:
                multArrays(quantity, price, total, SIZE);
                break;
                // Print total
            case 3:
                displayArray(total, SIZE);
                break;
                // Sums odd numbers in array
            case 4:
                cout << "\nSum of Odd Numbers: " << sumOddArray(quantity, SIZE) << endl;
                break;
                // Displays if all values are positive
            case 5:
                if (isAllPositive(quantity, SIZE) == 1)
                    cout << "\nAll Values are Positive." << endl;
                else
                    cout << "\nNot all Values are Positive." << endl;
                break;
                // Displays average of all the odd numbers
            case 6:
                avgOddArray(quantity, SIZE, avg);
                cout << "\nAverage: " << avg << endl;
                break;
            case 7:
                break;
            default:
                assert(true);
        }
    } while (choice != 7);

    cout << "\nHave a nice day :)" << endl;

    return 0;
}

/**
 * <code>printMenu</code> shows a menu and accepts the choice
 * from the user which is returned.
 * <BR>
 * @return Returns the menu choice
 */
int printMenu() {
    int choice;

    do {
        cout << "\n == MENU ==";
        cout << "\n1) Enter quantity";
        cout << "\n2) Calculate total";
        cout << "\n3) Print total";
        cout << "\n4) Sum of Odd Numbers";
        cout << "\n5) Are all values positive";
        cout << "\n6) Average of all the odd numbers";
        cout << "\n7) Exit";

        cout << "\nEnter the choice: ";
        cin >> choice;

        if (choice < 1 || choice > 7) {
            cout << "\nWrong choice, try again.";
        }
    } while (choice < 1 || choice > 8);
    return choice;
}

/**
 * <code>fillInArray</code> is a function that will
 * fill in the elements of an array.
 * <BR>
 * @param arr The array to be filled in.
 * @param size The size of the array.
 */
void fillInArray(int arr[], const int size) {
    assert(size > 1);

    for (int i = 0; i < size; ++i) {
        cout << "\nEnter an element for the array at " << i << ": ";
        cin >> arr[i];
    }
}

/**
 * <code>multArrays</code> Multiplies the value of elements of the source array
 * to the corresponding value at the destination array. NOTE: precondition
 * is that the arrays have the same size.
 * <BR>
 * @param arrQuantity Array containing the source elements.
 * @param arrPrice Array containing price elements.
 * @param arrTotal Array containing the destination elements.
 * @param size The size of the arrays.
 */
void multArrays(const int arrQuantity[], const int arrPrice[], int arrTotal[], const int size) {
    assert(size > 0);

    for (int i = 0; i <= size; ++i) {
        arrTotal[i] = arrQuantity[i] * arrPrice[i];
    }
}

/**
 * <code>displayArray</code> prints the value of each of the elements of the
 * array. In addition the function sums up the value of all the elements and
 * print the total.
 * <BR>
 * @param ar The array containing the values
 * @param size The size of the array.
 */
void displayArray(const int arr[], const int size) {
    int sum = 0;

    for (int i = 0; i < size; ++i) {
        cout << "\nValue at " << i << ": " << arr[i];
        sum += arr[i];
    }

    cout << "\nThe total is: " << sum;
}

/**
 * <code>sumOddArray</code>  Sums the odd numbers in the array and returns the result
 * <BR>
 * @param arr The array containing the values
 * @param size The size of the array.
 * @return Returns the result
 */
int sumOddArray(const int arr[], const int size) {

    int result = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0)
            result += arr[i];
    }

    return result;
}


/**
 * <code>isAllPositive</code>  Return true if all the values in the array are positive
 * <BR>
 * @param arr The array containing the values
 * @param size The size of the array.
 * @return Returns true if all values are positive
 */
bool isAllPositive(const int arr[], const int size) {

    for (int i = 0; i < size; i++) {
        if (arr[i] < 0)
            return 0;
    }

    return 1;
}


/**
 * <code>avgOddArray</code>  Finds the average of all the odd numbers in the array and stores this in the last argument
 * <BR>
 * @param arr The array containing the values
 * @param size The size of the array.
 * @param avgOdd The average of all odd numbers
 */
void avgOddArray(const int arr[], const int size, int& avgOdd) {

    int odd[10], j = 0, x = 0;

    for (int i = 0; i < size; i++) { // Transfers all odd numbers in "arr" array to "odd" array
        if (arr[i] % 2 != 0) {
            odd[j] = arr[i];
            j++;
        }

    }

    odd[j] = '\0';

    while (odd[x] != '\0') // Calculates size of odd array
        x++;

    for (int i = 0; i < x; i++)
        avgOdd += odd[i];

    avgOdd /= x;
}