// Problem: 88. Merge Sorted Array
// LeetCode Link: https://leetcode.com/problems/merge-sorted-array/
// Difficulty: Easy
// Time Complexity: O(m + n)   // Each element from nums1 and nums2 is compared at most once.
// Space Complexity: O(1)      // In-place merge, no extra significant space used.

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i = m - 1;       
            int j = n - 1;       
            int lst = m + n - 1; 
    
            while (i >= 0 && j >= 0)
            {
                if(nums1[i]<nums2[j])
                    nums1[lst--] = nums2[j--];
                else
                    nums1[lst--] = nums1[i--];
            }
            while (j >= 0)
                nums1[lst--] = nums2[j--];
        }
    };