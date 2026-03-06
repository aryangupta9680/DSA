class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
        {
            return false;
        }

        unordered_map<char, int>freq;
        for(auto x: s)
        {
            freq[x]++;
        }

        for(auto x: t)
        {
            freq[x]--;

            if(freq[x] < 0)
            {
                return false;
            }
        }

        return true;
    }
};