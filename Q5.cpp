#include <iostream>
#include <vector>
#include <algorithm>

// Function to rotate the array to the right by k steps
void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    k %= n; // If k is greater than n, take the modulus

    // Reverse the whole array
    std::reverse(nums.begin(), nums.end());
    
    // Reverse the first k elements
    std::reverse(nums.begin(), nums.begin() + k);
    
    // Reverse the remaining elements
    std::reverse(nums.begin() + k, nums.end());
}

void printArray(const std::vector<int>& nums) {
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    std::cout << "Original array: ";
    printArray(nums);

    rotate(nums, k);

    std::cout << "Rotated array: ";
    printArray(nums);

    return 0;
}
