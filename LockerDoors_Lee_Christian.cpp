/**
 * Written by Christian Lee Copyright 2022
 */
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int lockers;
    int passes;

    cout << "Welcome to the locker door problem\nHow many lockers would you like?\n";
    cin >> lockers;

    // Checks if the user inputted a valid integer that is also above 0
    while (cin.fail() || lockers <= 0)
    {
        cout << "Invalid input, please enter an integer above 0";
        cin.clear();
        cin >> passes;
    }

    cout << "How many passes of the lockers do you want\n";
    cin >> passes;

    // Checks if the user inputted a valid integer that is above 0 as well as more than the number of lockers
    while (cin.fail() || passes <= 0 || passes > lockers)
    {
        cout << "Invalid input, please enter an integer above 0 and less than the number of lockers";
        cin.clear();
        cin >> passes;
    }

    int lockerRow[lockers] = {};
    int passCounter = 0;

    // Changes the locker from closed to open and open to close for each pass
    for (int i = 0; i < passes; i++)
    {
        passCounter++;
        for (int j = passCounter - 1; j < lockers; j += passCounter)
        {
            if (lockerRow[j] == 0)
            {
                lockerRow[j] = 1;
            }
            else if (lockerRow[j] == 1)
            {
                lockerRow[j] = 0;
            }
        }
    }

    // Counts how many lockers are open as well as prints the locker numbers that are open
    int openCount = 0;
    cout << "The lockers that are open are ";
    for (int i = 0; i < lockers; i++)
    {
        if (lockerRow[i] == 1)
        {
            cout << i + 1 << " ";
            openCount++;
        }
    }
    cout << "\n";

    // Prints which lockers are open
    cout << "The lockers that are closed are ";
    for (int i = 0; i < lockers; i++)
    {
        if (lockerRow[i] == 0)
        {
            cout << i + 1 << " ";
        }
    }
    cout << "\nThe number of lockers that are open are " << openCount;
}