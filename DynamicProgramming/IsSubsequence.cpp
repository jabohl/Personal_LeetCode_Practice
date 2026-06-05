/**
 * LeetCode Problem: Is Subsequence (LeetCode 392)
 *
 * Problem Description:
 * Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
 * A subsequence of a string is a new string that is formed from the original string
 * by deleting some (not necessarily consecutive) characters without changing the
 * relative order of the remaining characters.
 *
 * Example 1:
 * Input: s = "ace", t = "abcde"
 * Output: true
 *
 * Example 2:
 * Input: s = "aec", t = "abcde"
 * Output: false
 *
 * Example 3:
 * Input: s = "", t = "abcde"
 * Output: true
 *
 * Constraints:
 * 0 <= s.length <= 100
 * 0 <= t.length <= 10^4
 * s and t consist only of lowercase English letters
 *
 * Time Complexity: O(m + n) where m = s.length() and n = t.length()
 * Space Complexity: O(n) for string operations
 */

#include <string>
#include <iostream>
#include <algorithm>

class Solution {
public:
    /**
     * Check if string s is a subsequence of string t.
     *
     * Args:
     *     subsequence: The potential subsequence string
     *     mainString: The main string to search in
     *
     * Returns:
     *     true if subsequence is a subsequence of mainString, false otherwise
     */
    bool isSubsequence(std::string subsequence, const std::string& mainString) {
        // Remove characters from subsequence that don't exist in mainString
        for (char character : subsequence) {
            if (mainString.find(character) == std::string::npos) {
                subsequence.erase(std::remove(subsequence.begin(), 
                                              subsequence.end(), 
                                              character), 
                                 subsequence.end());
            }
        }

        // Track position in the subsequence
        int subsequenceIndex = 0;

        if (!subsequence.empty()) {
            // Search for each character of subsequence in mainString in order
            for (size_t mainStringIndex = 0; mainStringIndex < mainString.size(); ++mainStringIndex) {
                if (subsequenceIndex < (int)subsequence.size()) {
                    if (subsequence[subsequenceIndex] == mainString[mainStringIndex]) {
                        std::cout << subsequence[subsequenceIndex] << std::endl;
                        ++subsequenceIndex;
                    }
                }
            }
        }

        // If we matched all characters in subsequence, it's a valid subsequence
        return subsequenceIndex == (int)subsequence.size();
    }
};
