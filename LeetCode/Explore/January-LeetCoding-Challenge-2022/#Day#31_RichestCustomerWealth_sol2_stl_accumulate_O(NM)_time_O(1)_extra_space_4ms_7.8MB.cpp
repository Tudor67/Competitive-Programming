class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        const int N = accounts.size();
        const int M = accounts[0].size();
        
        int maxWealth = 0;
        for(const vector<int>& ACCOUNT: accounts){
            int wealth = accumulate(ACCOUNT.begin(), ACCOUNT.end(), 0);
            maxWealth = max(maxWealth, wealth);
        }
        
        return maxWealth;
    }
};