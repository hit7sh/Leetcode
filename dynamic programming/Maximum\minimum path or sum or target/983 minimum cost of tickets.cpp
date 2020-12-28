class Solution {
public:
    int mem[366];
    bool day[366];
    int c1, c7, c30;
    int dp(int d){
        if(d>365)
            return 0;
        if(mem[d])
            return mem[d];
        int ans;
        if(day[d])
            ans = min({dp(d+1)+c1, dp(d+7)+c7, dp(d+30)+c30});
        else
            ans = dp(d+1);
        return mem[d]=ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for(int i=0;i<days.size();i++)
            day[days[i]]=1;
        c1=costs[0], c7=costs[1], c30=costs[2];
        return dp(1);
    }
    
};
