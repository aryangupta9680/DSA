class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ones = 0, ans = 0;
        for(int i = 0; i < n;i++)
        {
            if(nums[i]==1)
            {
                ones++;
                ans = max(ans, ones);
            }
            else
            {
                ones = 0;
            }
        }

        return ans;
    }
};