#include <iostream>
#include <vector>
#include <cctype>   // for toupper()

using namespace std;

// Function prototypes
void print_menu();
char get_selection();
void print_numbers(const vector<int>& numbers);
void add_number(vector<int>& numbers);
void display_mean(const vector<int>& numbers);
void display_smallest(const vector<int>& numbers);
void display_largest(const vector<int>& numbers);

int main() 
{
    vector<int> numbers {};
    char selection {};

    do 
    {
        print_menu();
        selection = get_selection();

        switch(selection) 
        {
            case 'P':
                print_numbers(numbers);
                break;
            case 'A':
                add_number(numbers);
                break;
            case 'M':
                display_mean(numbers);
                break;
            case 'S':
                display_smallest(numbers);
                break;
            case 'L':
                display_largest(numbers);
                break;
            case 'Q':
                cout << "Goodbye" << endl;
                break;
            default:
                cout << "Unknown selection, please try again" << endl;
        }

    } while (selection != 'Q');

    return 0;
}

// Displays the menu
void print_menu() 
{
    cout << "\nP - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;
    cout << "\nEnter your choice: ";
}

// Reads user input and converts to uppercase
char get_selection() 
{
    char choice {};
    cin >> choice;
    return toupper(choice);
}

// Prints all numbers in the vector
void print_numbers(const vector<int>& numbers) 
{
    if (numbers.size() == 0)
        cout << "[] - the list is empty" << endl;
    else 
    {
        cout << "[ ";
        for (int num : numbers)
            cout << num << " ";
        cout << "]" << endl;
    }
}

// Adds a number to the vector
void add_number(vector<int>& numbers) 
{
    int num {};
    cout << "Enter an integer to add to the list: ";
    cin >> num;
    numbers.push_back(num);
    cout << num << " added" << endl;
}

// Calculates and displays mean
void display_mean(const vector<int>& numbers) 
{
    if (numbers.size() == 0)
        cout << "Unable to calculate the mean - no data" << endl;
    else 
    {
        int total = 0;
        for (int num : numbers)
            total += num;

        double mean = static_cast<double>(total) / numbers.size();
        cout << "The mean is: " << mean << endl;
    }
}

// Finds and displays smallest number
void display_smallest(const vector<int>& numbers) 
{
    if (numbers.size() == 0)
        cout << "Unable to determine the smallest number - list is empty" << endl;
    else 
    {
        int smallest = numbers.at(0);
        for (int num : numbers)
        {
            if (num < smallest)
                smallest = num;
        }
        cout << "The smallest number is: " << smallest << endl;
    }
}

// Finds and displays largest number
void display_largest(const vector<int>& numbers) 
{
    if (numbers.size() == 0)
        cout << "Unable to determine the largest number - list is empty" << endl;
    else 
    {
        int largest = numbers.at(0);
        for (int num : numbers)
        {
            if (num > largest)
                largest = num;
        }
        cout << "The largest number is: " << largest << endl;
    }
}