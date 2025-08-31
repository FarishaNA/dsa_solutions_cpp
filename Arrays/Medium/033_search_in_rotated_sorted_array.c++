/*
Problem: 33. Search in Rotated Sorted Array
LeetCode: https://leetcode.com/problems/search-in-rotated-sorted-array/

Approach:
- Use a modified binary search since the array is rotated.
- Check which half (left or right) is sorted at every step.
- If the target lies in the sorted half, adjust search boundaries accordingly.
- Repeat until the target is found or the search space is empty.

Time Complexity: O(log n)
- Binary search reduces the search space by half each time.

Space Complexity: O(1)
- No additional space is used beyond a few variables.

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (nums[mid] == target)
                return mid;
            
            // Check if left half is sorted
            if (nums[left] <= nums[mid]) {
                if (target >= nums[left] && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            } 
            // Otherwise, right half must be sorted
            else {
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        
        return -1; // Target not found
    }
};
