class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int>freq;
        for(auto x: magazine)
        {
            freq[x]++;
        }

        for(auto x: ransomNote)
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