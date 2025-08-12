// Problem: 122. Best Time to Buy and Sell Stock II
// LeetCode Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Difficulty: Medium
// Time Complexity: O(n)       // Single pass through the price list.
// Space Complexity: O(1)      // Only a few variables used, no extra storage.

// Approach:
// - Buy whenever the price will go up the next day, sell the next day.
// - This is equivalent to summing all positive differences between consecutive days.

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int profit = 0;
            for (int i = 0; i < prices.size() - 1; i++) {
                if (prices[i] < prices[i + 1])
                    profit += (prices[i + 1] - prices[i]);
            }
            return profit;
        }
};