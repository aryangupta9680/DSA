class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int>freq;
        for(auto x: arr)
        {
            freq[x]++;
        }

        set<int>s;

        for(auto x: freq)
        {
            if(s.count(x.second))
            {
                return false;
            }

            s.insert(x.second);
        }

        return true;
    }
};