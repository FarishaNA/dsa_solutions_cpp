// Problem: 136. Single Number
// LeetCode Link: https://leetcode.com/problems/single-number/
// Difficulty: Easy
// Time Complexity: O(n)       // We iterate through all elements once.
// Space Complexity: O(1)      // Only one variable used (result).
//
// Approach:
// - Use XOR to find the unique element.
// - XOR properties: a ^ a = 0 and a ^ 0 = a.
// - Therefore, XOR-ing all numbers cancels out duplicates and leaves the single number.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int n : nums) {
            result ^= n;   // XOR operation
        }
        return result;
    }
};
