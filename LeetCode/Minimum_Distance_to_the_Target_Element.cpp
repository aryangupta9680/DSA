class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int minimum = INT_MAX;
        for(int i = 0; i < n;i++)
        {
            if(nums[i] == target)
            {
                minimum = min(minimum, abs(i - start));
            }
        }

        return minimum;
    }
};