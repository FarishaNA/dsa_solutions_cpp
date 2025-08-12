// Problem: 1. Two Sum
// LeetCode Link: https://leetcode.com/problems/two-sum/
// Difficulty: Easy
// Time Complexity: O(n)       // We traverse the array once; each map lookup/insert is O(1) average.
// Space Complexity: O(n)      // In worst case, the map stores all elements.

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
           unordered_map<int,int> map;
           for(int i =0;i<nums.size();i++)
           {
             if(map.count(target-nums[i]))
                return {i, map[target - nums[i]]};
            else map.insert({nums[i],i});   
           } 
           return {-1,-1};
        }
    
    };