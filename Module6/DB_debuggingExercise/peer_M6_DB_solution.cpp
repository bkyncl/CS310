// Discussionboardweek6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// Define an enumeration for days of the week
enum Day { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

// Function to convert Day enum to string
std::string dayToString(Day day) {
    switch (day)
    {
    case Sunday:
        return "Sunday";
    case Monday:
        return "Monday";
    case Tuesday:
        return "Tuesday";
    case Wednesday:
        return "Wednesday";
    case Thursday:
        return "Thursday";
    case Friday:
        return "Friday";
    case Saturday:
        return "Saturday";
    default:
        return "Unknown";
    }
}
int main() {
    Day today = Wednesday;

    std::cout << "Today is " << dayToString(today) << std::endl; // FIX: added missing namespace 'std'
    // FIX: Used dayToString() function to convert 'Day' enum to matching string
    // WHY: You were attempting to directly print the enumberation which only printed the underlying integer value

    std::cout << "Numeric value of today: " << today << std::endl;

    return 0;
}