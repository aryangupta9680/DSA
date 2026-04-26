class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        for(int i = 1; i < n;i++)
        {
            if(nums[i-1] > nums[i])
            {
                ans += (nums[i-1] - nums[i]);
            }
        }

        return ans;
    }
};