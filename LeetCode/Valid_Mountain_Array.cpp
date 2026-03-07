class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n < 3)
        {
            return false;
        }

        for(int i = 1; i < n-1;i++)
        {
            bool valid = true;

            for(int j = 0; j < i;j++)
            {
                if(arr[j] >= arr[j+1])
                {
                    valid = false;
                    break;
                }
            }

            for(int j = i; j < n-1;j++)
            {
                if(arr[j] <= arr[j+1])
                {
                    valid = false;
                    break;
                }
            }

            if(valid)
            {
                return true;
            }
        }

        return false;
    }
};