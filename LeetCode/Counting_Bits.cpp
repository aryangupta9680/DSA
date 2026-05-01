class Solution {
public:
    int countOnes(int num)
    {
        int count = 0;

        while(num != 0)
        {
            count += (num%2);
            num /= 2;
        }

        return count;
    }

    vector<int> countBits(int n) {
        vector<int>ans;

        for(int i = 0; i <= n;i++)
        {
            ans.push_back(countOnes(i));
        }

        return ans;
    }
};