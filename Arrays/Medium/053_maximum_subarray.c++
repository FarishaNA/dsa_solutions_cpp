// Problem: 53. Maximum Subarray
// LeetCode: https://leetcode.com/problems/maximum-subarray/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: Kadane's Algorithm

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = nums[0];
        int maxi = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            current_sum = max(nums[i], nums[i] + current_sum);
            maxi = max(maxi, current_sum);
        }
        
        return maxi;
    }
};
