class Solution {
public:
    int gcd(int a, int b) 
    {
        if(b == 0)
        {
            return a;
        }
        
        return gcd(b, a % b);
    }

    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        for(int i = 0; i < n;i++)
        {
            minimum = min(nums[i], minimum);
            maximum = max(nums[i], maximum);
        }

        return gcd(minimum, maximum);
    }
};