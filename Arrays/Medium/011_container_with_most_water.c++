/*
Problem: 11. Container With Most Water
LeetCode: https://leetcode.com/problems/container-with-most-water/

Approach:
- Use the two-pointer technique to maximize the area.
- Start with `left` at the beginning and `right` at the end of the array.
- Calculate the area formed by the lines at `left` and `right`:
    - Area = min(height[left], height[right]) * (right - left)
- Update the maximum area if the current area is larger.
- Move the pointer pointing to the smaller height inward because that might help in finding a bigger area.
- Repeat until `left` and `right` meet.

Time Complexity: O(n)
- Each element is visited at most once using the two-pointer approach.

Space Complexity: O(1)
- No extra space is used apart from variables.

*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int left = 0, right = height.size() - 1;

        while (left < right) {
            // Calculate area using the shorter line
            int mini = min(height[left], height[right]);
            max_area = max(max_area, mini * (right - left));

            // Move the pointer at the smaller height
            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return max_area;
    }
};
