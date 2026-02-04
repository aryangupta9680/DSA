class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        int n = mices.size();
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());
        
        int ans = INT_MIN;
        
        for(int i = 0; i < n;i++)
        {
            ans = max(ans, abs(mices[i]-holes[i]));
        }
        
        return ans;
    }
};