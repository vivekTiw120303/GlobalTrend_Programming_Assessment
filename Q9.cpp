#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum difference between any two elements in the array
int maxDifference(const std::vector<int>& arr) {
    if (arr.size() < 2) {
        std::cerr << "Array must contain at least two elements." << std::endl;
        return -1;
    }

    int minElement=INT_MAX, maxElement=INT_MIN;
    for(auto it:arr){
        minElement=min(minElement,it);
        maxElement=max(maxElement,it);
    }

    return maxElement-minElement;   
}

int main() {
    std::vector<int> arr = {7, 1, 5, 3, 6, 4};

    int result = maxDifference(arr);
    if (result != -1) {
        std::cout << "The maximum difference between any two elements in the array is: " << result << std::endl;
    }

    return 0;
}
