bool comp(pair<int, int>a, pair<int, int>b)
{
    return a.second < b.second;
}

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int, int>>timer;
        for(int i = 0; i < n;i++)
        {
            timer.push_back({start[i], end[i]});
        }
        sort(timer.begin(), timer.end(), comp);
        
        int total = 0; // maximum kitni meeting karwa sakta hu
        int ending = -1;
        
        for(int i = 0; i < n;i++)
        {
            if(timer[i].first > ending)
            {
                total++;
                ending = timer[i].second;
            }
        }
        
        return total;
    } 
};