// Problem: 242. Valid Anagram
// LeetCode Link: https://leetcode.com/problems/valid-anagram/
// Difficulty: Easy
// Time Complexity: O(n)       // We iterate through both strings once.
// Space Complexity: O(1)      // Fixed size array (26 letters).
//
// Approach:
// - If lengths differ, return false immediately.
// - Use a frequency array of size 26 to count occurrences of characters.
// - Increment count for characters in s, decrement for characters in t.
// - If all counts are zero, strings are anagrams.

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> count(26, 0);  // Frequency array for 26 lowercase letters
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int c : count)
            if (c != 0) return false;

        return true;
    }
};
