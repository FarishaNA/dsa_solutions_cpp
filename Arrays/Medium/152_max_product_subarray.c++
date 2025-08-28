// Problem: 152. Maximum Product Subarray
// LeetCode Link: https://leetcode.com/problems/maximum-product-subarray/
// Difficulty: Medium
//
// ✅ Approach:
// - The maximum product subarray can be tricky because of negative numbers.
// - A negative number can flip the sign, making a small product become the largest after multiplication.
// - Therefore, we track both:
//      1. max_prod → the maximum product ending at current index
//      2. min_prod → the minimum product ending at current index
// - At each step, compute new max_prod and min_prod considering:
//      - current element
//      - current element * previous max_prod
//      - current element * previous min_prod
// - Update result with the maximum seen so far.
//
// ✅ Time Complexity: O(n)
//      - We iterate through the array once.
// ✅ Space Complexity: O(1)
//      - Only a few variables used (constant extra space).

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Initialize max, min, and result with the first element
        int max_prod = nums[0], min_prod = nums[0], result = nums[0];

        // Traverse from the second element
        for(int i = 1; i < nums.size(); i++) {
            int temp = max_prod; // Store current max before updating
            // Update max_prod and min_prod considering current number and previous values
            max_prod = max({nums[i], nums[i] * max_prod, nums[i] * min_prod});
            min_prod = min({nums[i], nums[i] * temp, nums[i] * min_prod});
            // Update the overall result
            result = max(result, max_prod);
        }

        return result;
    }
};
