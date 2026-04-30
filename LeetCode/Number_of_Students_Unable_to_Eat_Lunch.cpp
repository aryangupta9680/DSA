class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zero = 0, one = 0;

        for(int i = 0; i < students.size(); i++) 
        {
            if(students[i] == 0) 
            {
                zero++;
            }
            else 
            {
                one++;
            }    
        }

        for(int i = 0; i < sandwiches.size(); i++) 
        {
            if(sandwiches[i] == 0) 
            {
                if(zero == 0) 
                {
                    break;
                }
                zero--;
            } 
            else 
            {
                if(one == 0) 
                {
                    break;
                }
                one--;
            }
        }

        return zero + one;
    }
};