// Problem: 953. Verifying an Alien Dictionary
// LeetCode Link: https://leetcode.com/problems/verifying-an-alien-dictionary/
// Difficulty: Easy
// Time Complexity: O(N * L) 
//      - N = number of words
//      - L = average length of words
// Space Complexity: O(1) 
//      - Only an array of size 26 is used to store character ranks
//
// Approach:
// - First, map each character in the custom 'order' string to its rank using an array of size 26.
// - Then, compare each pair of consecutive words to check if they are sorted according to this custom order.
// - To compare two words:
//     - Iterate through characters until they differ or one word ends.
//     - If characters differ, check their ranks from the rank array.
//     - If all characters match but the first word is longer than the second, return false (prefix case).
// - If all pairs are in correct order, return true.

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // Step 1: Build a rank mapping for each character
        int rank[26];
        for (int i = 0; i < 26; i++) {
            rank[order[i] - 'a'] = i;
        }

        // Step 2: Compare each adjacent pair of words
        for (int i = 0; i < words.size() - 1; i++) {
            if (!isOrdered(words[i], words[i + 1], rank)) {
                return false;
            }
        }
        return true;
    }

private:
    // Helper function to check if two words are in correct order
    bool isOrdered(const string& first, const string& second, int rank[]) {
        int len1 = first.size();
        int len2 = second.size();
        int minLen = min(len1, len2);

        for (int i = 0; i < minLen; i++) {
            if (first[i] != second[i]) {
                return rank[first[i] - 'a'] < rank[second[i] - 'a']; // Compare based on rank
            }
        }
        return len1 <= len2; // Handle case where one word is prefix of the other
    }
};
