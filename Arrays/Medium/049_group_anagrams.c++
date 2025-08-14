// Problem: 49. Group Anagrams
// LeetCode Link: https://leetcode.com/problems/group-anagrams/
// Difficulty: Medium
// Time Complexity: O(n * k log k)   // n = number of strings, k = max length of a string
//                                    // Sorting each string takes O(k log k).
// Space Complexity: O(n * k)        // For the hash map storing groups of strings.
//
// Approach:
// - For each string in the input, create a key by sorting its characters.
// - Use an unordered_map where the key is the sorted string, and the value is a list of original strings.
// - Push each string into the corresponding group based on the sorted key.
// - Finally, collect all groups from the map into a result vector.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrms; 
        unordered_map<string, vector<string>> map;

        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(strs[i].begin(), strs[i].end());  // Sort to create the key
            map[strs[i]].push_back(temp);          // Group original string
        }

        for (auto &entry : map)
            anagrms.push_back(entry.second);

        return anagrms;
    }
};
