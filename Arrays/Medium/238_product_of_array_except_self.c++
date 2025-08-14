// Problem: 238. Product of Array Except Self
// LeetCode Link: https://leetcode.com/problems/product-of-array-except-self/
// Difficulty: Medium
// Time Complexity: O(n)       // Two passes through the array (prefix and suffix).
// Space Complexity: O(1)      // Uses output array only, no extra arrays for prefix/suffix.
//
// Approach:
// - Use two passes: one forward pass to store prefix products, one backward pass to multiply suffix products.
// - For each index i:
//     answer[i] = product of all elements before i (prefix) * product of all elements after i (suffix).
// - This avoids using division and extra space for separate prefix/suffix arrays.

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1, suffix = 1;
        vector<int> answer(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            answer[i] = prefix;
            prefix *= nums[i];      // Build prefix product
        }

        for (int j = nums.size() - 1; j >= 0; j--) {
            answer[j] *= suffix;    // Multiply by suffix product
            suffix *= nums[j];
        }

        return answer;
    }
};
