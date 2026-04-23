class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int digitSum = 0, elementSum = 0;
        for(int i = 0; i < nums.size();i++)
        {
            elementSum += nums[i];
            while(nums[i])
            {
                int rem = nums[i] % 10;
                digitSum += rem;
                nums[i] /= 10;
            }
        }

        return abs(digitSum-elementSum);
    }
};