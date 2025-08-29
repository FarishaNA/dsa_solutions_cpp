// Problem: 153. Find Minimum in Rotated Sorted Array
// LeetCode Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Difficulty: Medium
//
// Approach:
// - The array is originally sorted, but rotated. We need to find the smallest element.
// - Use **binary search** instead of linear scan for O(log n) complexity.
// - Compare `nums[mid]` with `nums[right]`:
//      • If nums[mid] > nums[right], the minimum is in the right half → move left to mid + 1.
//      • Else, the minimum is in the left half (including mid) → move right to mid.
// - Loop continues until left == right, which will be the index of the minimum.
//
// Time Complexity: O(log n)
//      - Each iteration halves the search space.
// Space Complexity: O(1)
//      - No extra data structures used.

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2;
            // If mid element is greater than right element, min must be to the right
            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid; // min is at mid or to its left
        }

        return nums[left]; // left == right is the index of the minimum element
    }
};
