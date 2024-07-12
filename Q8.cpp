#include <bits/stdc++.h>
using namespace std;

// Function to find the GCD of two numbers using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;
    std::cout << "Enter two numbers to find their GCD: ";
    std::cin >> num1 >> num2;

    cout<<"Using Euclidean algorithm"<<endl;
    std::cout << "The GCD of " << num1 << " and " << num2 << " is: " << gcd(num1, num2) << std::endl;
    cout<<"------------------------------------------------------\n";

    cout<<"Using STL libraries"<<endl;
    std::cout << "The GCD of " << num1 << " and " << num2 << " is: " << __gcd(num1, num2) << std::endl;

    return 0;
}
