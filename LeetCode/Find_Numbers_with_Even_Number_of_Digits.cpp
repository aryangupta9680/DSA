class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n;i++)
        {
            int val = nums[i];
            int rem, count = 0;
            while(val != 0)
            {
                rem = val % 10;
                count++;
                val /= 10;
            }

            if(count%2 == 0)
            {
                ans++;
            }
        }

        return ans;
    }
};