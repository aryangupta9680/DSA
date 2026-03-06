class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        set<int>s;

        for(auto x: nums1)
        {
            s.insert(x);
        }

        for(auto x: nums2)
        {
            if(s.count(x))
            {
                ans.push_back(x);
                s.erase(x);
            }
        }

        return ans;
    }
};