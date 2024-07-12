#include <iostream>

// Function to compute the sum of the digits of a given number
int sumOfDigits(int num) {
    int sum = 0;
    num = abs(num); // Handle negative numbers by taking their absolute value

    while (num > 0) {
        sum += num % 10; // Extract the last digit
        num /= 10;       // Remove the last digit
    }
    
    return sum;
}

int main() {
    int number;
    std::cout << "Enter a number to compute the sum of its digits: ";
    std::cin >> number;

    std::cout << "Sum of the digits of " << number << " is: " << sumOfDigits(number) << std::endl;

    return 0;
}