class Solution {
public:
    void solve(vector<int>&arr, int n)
    {
        for(int i = 0; i < n;i++)
        {
            if(arr[i]==0)
            {
                for(int j = n-2; j >= i;j--)
                {
                    arr[j+1] = arr[j];
                }

                if(i+1 < n)
                {
                    arr[i+1] = 0;
                }

                i++;
            }
        }
    }

    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        solve(arr, n);
    }
};