class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int index = -1;
        int n = nums.size();
        
        for(int i = 0; i < n;i++)
        {
            int LeftSum = 0, RightSum = 0;
            for(int j = 0; j < i;j++)
            {
                LeftSum += nums[j];
            }

            for(int j = i+1; j < n;j++)
            {
                RightSum += nums[j];
            }

            if(LeftSum == RightSum)
            {
                index = i;
                break;
            }
        }

        return index;
    }
};