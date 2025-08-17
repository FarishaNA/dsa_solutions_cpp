// Problem: 27. Remove Element
// LeetCode Link: https://leetcode.com/problems/remove-element/
// Difficulty: Easy
// Time Complexity: O(n)        // Single pass through the array
// Space Complexity: O(1)       // In-place modification
//
// Approach:
// - Use two pointers (k and j):
//     - j scans every element.
//     - k tracks the position where the next non-val element should be placed.
// - If nums[j] != val, copy nums[j] to nums[k] and increment k.
// - At the end, k is the new length of the array without val.

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[k++] = nums[j];
            }
        }
        return k;
    }
};
