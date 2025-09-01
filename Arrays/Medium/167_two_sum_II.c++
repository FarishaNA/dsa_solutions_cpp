/*
Problem: 167. Two Sum II - Input Array Is Sorted
LeetCode: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

Approach:
- The input array is sorted, so we can use a two-pointer approach.
- Initialize two pointers: `left` at the start and `right` at the end.
- Calculate the sum of the two elements:
    - If sum equals target → return 1-based indices.
    - If sum is greater than target → move the `right` pointer leftward.
    - If sum is less than target → move the `left` pointer rightward.
- Continue until the pointers meet.

Time Complexity: O(n)
- Each element is processed at most once using the two-pointer approach.

Space Complexity: O(1)
- No extra space used apart from variables for pointers and sum.

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = (int)numbers.size() - 1;
        
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            
            if (sum == target) {
                // Return 1-based indices as required by the problem
                return {left + 1, right + 1};
            }
            
            if (sum > target) {
                --right; // Decrease sum by moving the right pointer left
            } else {
                ++left;  // Increase sum by moving the left pointer right
            }
        }
        
        return {}; // Should never reach here as per problem constraints
    }
};
