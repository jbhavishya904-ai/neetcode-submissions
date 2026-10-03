class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int>& nums, int target, int index, vector<int>& current) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            
            if (nums[i] > target)
                break;

            current.push_back(nums[i]);

            solve(nums, target - nums[i], i, current);

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<int> current;
        solve(nums, target, 0, current);

        return ans;
    }
};