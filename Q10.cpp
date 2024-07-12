#include <bits/stdc++.h>
using namespace std;

// Function to check if a string contains only alphabetic characters
bool containsOnlyAlphabets(const std::string& str) {
    for (char c : str) {
        if (!std::isalpha(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string str1 = "HelloWorld";
    std::string str2 = "Hello123";
    
    // Check if str1 contains only alphabetic characters
    if(containsOnlyAlphabets(str1)) {
        std::cout << "\"" << str1 << "\" contains only alphabetic characters." << std::endl;
    } 
    else{
        std::cout << "\"" << str1 << "\" does not contain only alphabetic characters." << std::endl;
    }
    
    // Check if str2 contains only alphabetic characters
    if(containsOnlyAlphabets(str2)) {
        std::cout << "\"" << str2 << "\" contains only alphabetic characters." << std::endl;
    } 
    else{
        std::cout << "\"" << str2 << "\" does not contain only alphabetic characters." << std::endl;
    }
    
    return 0;
}
