// first method: 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int>freq;

        for(auto x: nums)
        {
            freq[x]++;
        }

        for(auto x: freq)
        {
            if(x.second == 1)
            {
                return x.first;
            }
        }

        return -1;
    }
};




// second method
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for(auto x: nums)
        {
            ans = ans ^ x;
        }

        return ans;
    }
};