/*
Problem: 14. Longest Common Prefix
LeetCode: https://leetcode.com/problems/longest-common-prefix/

Approach:
- Start with the first string as the reference.
- For each character in the first string, check if the same character exists at the same position in all other strings.
- If any mismatch is found, return the prefix collected so far.
- If no mismatch occurs for that character, append it to the prefix.
- Continue until the end of the first string.

Time Complexity: O(N * M)
- N = number of strings, M = length of the first string (worst case: all strings have the same length).
- For each character in the first string, we compare across all other strings.

Space Complexity: O(1)
- Only using a prefix string to store the result.

*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pref;  // Stores the common prefix
        int k;

        // Iterate over each character of the first string
        for (int i = 0; i < strs[0].size(); i++) {
            k = 1;

            // Compare this character with the corresponding character in all other strings
            while (k < strs.size()) {
                if (strs[0][i] != strs[k][i])
                    return pref; // If mismatch found, return prefix
                k++;
            }

            // If all strings have the same character at position i, add to prefix
            pref.push_back(strs[0][i]);
        }

        return pref;
    }
};
