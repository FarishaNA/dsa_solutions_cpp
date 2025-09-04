// Problem: 16. 3Sum Closest
// Difficulty: Medium
// Category: Arrays
// Approach: Sorting + Two Pointers
// Link: https://leetcode.com/problems/3sum-closest/
//
// Explanation:
// The goal is to find the sum of three integers in the array 
// that is closest to the target value.
//
// Steps:
// 1. Sort the array to apply the two-pointer technique.
// 2. Fix one number (nums[i]) and use two pointers (left, right) 
//    to search for the best pair that, along with nums[i], gives 
//    the closest sum to the target.
// 3. Update the current best (closest) sum whenever a smaller 
//    difference is found.
// 4. If an exact match is found (sum == target), return immediately.
// 5. Otherwise, adjust pointers: move `left` forward if sum < target, 
//    or move `right` backward if sum > target.
// 6. Return the closest sum found.
//
// Time Complexity: O(n^2)  -> O(n log n) for sorting + O(n^2) for the loop
// Space Complexity: O(1)   -> In-place sorting and constant extra space

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Sort the array to enable two-pointer traversal
        sort(nums.begin(), nums.end());

        // Initialize current best with the sum of first three numbers
        int closest_sum = nums[0] + nums[1] + nums[2];

        // Iterate through each number, treating it as the first element of the triplet
        for (int i = 0; i < nums.size(); i++) {
            int left = i + 1;
            int right = nums.size() - 1;

            // Apply two-pointer technique
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                // Update closest_sum if this sum is closer to target
                if (abs(sum - target) < abs(closest_sum - target)) {
                    closest_sum = sum;
                }

                // If exact target found, return immediately
                if (sum == target) {
                    return sum;
                }
                // Move pointers based on comparison with target
                else if (sum > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return closest_sum;
    }
};
