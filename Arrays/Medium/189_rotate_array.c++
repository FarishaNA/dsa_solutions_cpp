// Problem: 189. Rotate Array
// LeetCode Link: https://leetcode.com/problems/rotate-array/
// Difficulty: Medium
// Time Complexity: O(n)       // Each reverse operation is O(n), and there are three reversals.
// Space Complexity: O(1)      // Rotation is done in-place using the reverse algorithm.

class Solution {
    public:
        void rotate(vector<int>& nums, int k) {  
             k %= nums.size();
          reverse(nums.begin(), nums.end());
          reverse(nums.begin(), nums.begin() + k);
          reverse(nums.begin() + k, nums.end());
    
        }
};