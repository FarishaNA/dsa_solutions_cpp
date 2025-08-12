// Problem: 217. Contains Duplicate
// LeetCode Link: https://leetcode.com/problems/contains-duplicate/
// Difficulty: Easy
// Time Complexity: O(n)       // Single pass through the array; unordered_set insert/find is O(1) average.
// Space Complexity: O(n)      // In worst case, all elements are stored in the set.

// Approach:
// - Use a hash set to track seen numbers.
// - If a number is already in the set, return true immediately.
// - If the loop finishes without finding a duplicate, return false.

class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            unordered_set<int> seen;
            for (int num : nums) {
                if (seen.find(num) != seen.end())
                    return true;
                seen.insert(num);
            }  
            return false; 
        }
};
    