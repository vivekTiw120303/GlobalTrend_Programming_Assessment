#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(const std::string& s) {
        std::unordered_map<char, int> charIndexMap;
        int maxLength = 0, start = 0;

        for (int end = 0; end < s.size(); ++end) {
            if (charIndexMap.find(s[end]) != charIndexMap.end()) {
                start = std::max(charIndexMap[s[end]] + 1, start);
            }
            charIndexMap[s[end]] = end;
            maxLength = std::max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution solution;
    std::string s;

    // Example usage
    s = "abcabcbb";
    std::cout << "The length of the longest substring without repeating characters in \"" << s << "\" is: "
              << solution.lengthOfLongestSubstring(s) << std::endl;

    s = "bbbbb";
    std::cout << "The length of the longest substring without repeating characters in \"" << s << "\" is: "
              << solution.lengthOfLongestSubstring(s) << std::endl;

    s = "pwwkew";
    std::cout << "The length of the longest substring without repeating characters in \"" << s << "\" is: "
              << solution.lengthOfLongestSubstring(s) << std::endl;

    s = "";
    std::cout << "The length of the longest substring without repeating characters in \"" << s << "\" is: "
              << solution.lengthOfLongestSubstring(s) << std::endl;

    return 0;
}
