
class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0;
        int prev1 = 0;

        for (int i = 0; i < nums.size(); i++) {
            int rob = nums[i] + prev2;
            int skip = prev1;

            int curr = max(rob, skip);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
