class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int countLeft = 0, countRight = 0, countBlank = 0;
        for(int i = 0; i < n;i++)
        {
            if(moves[i] == 'L')
            {
                countLeft++;
            }
            else if(moves[i] == 'R')
            {
                countRight++;
            }
            else
            {
                countBlank++;
            }
        }

        return abs(countLeft-countRight)+countBlank;
    }
};