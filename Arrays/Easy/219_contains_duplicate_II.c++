// Problem: 219. Contains Duplicate II
// LeetCode Link: https://leetcode.com/problems/contains-duplicate-ii/
// Difficulty: Easy
// Time Complexity: O(n)       // We traverse the array once.
// Space Complexity: O(n)      // Hash map stores indices for up to n elements.
//
// Approach:
// - Use an unordered_map to store each element's most recent index.
// - For each element, check if it exists in the map and if the index difference ≤ k.
// - If true, return true; otherwise, update the index in the map.

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map; // Stores element -> last index
        for (int i = 0; i < nums.size(); i++) {
            if (map.count(nums[i]) && i - map[nums[i]] <= k)
                return true;  // Found duplicate within k distance
            map[nums[i]] = i; // Update index
        }
        return false;
    }
};
