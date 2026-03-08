class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n;i++)
        {
            int ans = -1;
            for(int j = i+1; j<n;j++)
            {
                ans = max(ans, arr[j]);
            }
            arr[i] = ans;
        }

        return arr;
    }
};