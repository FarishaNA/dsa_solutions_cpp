/*
Problem: 15. 3Sum
LeetCode: https://leetcode.com/problems/3sum/

Approach:
- Sort the array to simplify the process of avoiding duplicates and using two pointers.
- Iterate through the array with index `i`:
    - Skip duplicate elements to avoid duplicate triplets.
    - Use two-pointer technique (`left`, `right`) to find pairs such that nums[i] + nums[left] + nums[right] = 0.
    - If the sum matches 0, add the triplet to the result and skip duplicates for `left` and `right`.
    - If the sum is greater than 0, move `right` leftward; if smaller, move `left` rightward.
- Continue until all possible triplets are found.

Time Complexity: O(n^2)
- Sorting takes O(n log n), and the two-pointer approach for each element takes O(n).
- Overall: O(n^2).

Space Complexity: O(1)
- Apart from the result vector, no extra significant space is used.

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates for i
            
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    
                    left++;
                    right--;
                    
                    // Skip duplicates for left and right
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } 
                else if (sum > 0) {
                    right--; // Need a smaller sum
                } else {
                    left++;  // Need a larger sum
                }
            }
        }
        
        return res;
    }
};
