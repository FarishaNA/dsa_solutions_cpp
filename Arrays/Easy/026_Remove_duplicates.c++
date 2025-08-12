// Problem: 26. Remove Duplicates from Sorted Array
// LeetCode Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Difficulty: Easy
// Time Complexity: O(n)       // Single pass through the array.
// Space Complexity: O(1)      // In-place modification, no extra space used.

// Approach:
// - Use two pointers: 
//   - `i` iterates through all elements.
//   - `k` tracks the position to place the next unique element.
// - If the current element differs from the last unique one, move it to position `k` and increment `k`.
// - The first `k` elements of `nums` will be the unique values.

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int i = 1, k = 1;
            for (; i < nums.size(); i++) {
                if (nums[i] != nums[k - 1])
                    nums[k++] = nums[i];
            }
            return k;
        }
};
    