#include <iostream>

// Function to calculate the factorial of a given number
unsigned long long factorial(int n) {
    // Handling the base case for 0 and 1
    if (n == 0 || n == 1) return 1;
    
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int number;
    std::cout << "Enter a number to find its factorial: ";
    std::cin >> number;

    // Validate input
    if (number < 0) {
        std::cout << "Factorial is not defined for negative numbers." << std::endl;
    } else {
        std::cout << "Factorial of " << number << " is: " << factorial(number) << std::endl;
    }

    return 0;
}
