class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Count frequency of each number
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // bucket[i] = numbers that appear i times
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto& [num, count] : freq) {
            bucket[count].push_back(num);
        }

        // Take elements from highest frequency to lowest
        vector<int> result;

        for (int i = nums.size(); i >= 1 && result.size() < k; i--) {
            for (int num : bucket[i]) {
                result.push_back(num);

                if (result.size() == k) {
                    break;
                }
            }
        }

        return result;
    }
};