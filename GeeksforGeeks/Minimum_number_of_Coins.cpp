class Solution {
  public:
    int findMin(int n) {
        int currency[] = {10, 5, 2, 1};
        int notes = 0, i = 0;
        vector<int>ans;
        while(n)
        {
            notes = n/currency[i];
            while(notes--)
            {
                ans.push_back(currency[i]);
            }
            n %= currency[i];
            i++;
        }
        
        return ans.size();
    }
};