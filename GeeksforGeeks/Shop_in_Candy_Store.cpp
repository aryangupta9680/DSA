class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        int n = prices.size();
        sort(prices.begin(), prices.end()); // ascending order
        int min_amount = 0, max_amount = 0;
        int i = 0, j = n-1;
        while(i<=j)
        {
            min_amount += prices[i];
            i++;
            j-=k;
        }
        
        i = n-1, j = 0;
        while(i>=j)
        {
            max_amount += prices[i];
            i--;
            j+=k;
        }
        
        vector<int>ans;
        ans.push_back(min_amount);
        ans.push_back(max_amount);
        
        return ans;
    }
};