class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int C = coins.size();
        const int A = amount;
        
        if(A == 0){
            return 0;
        }
        
        queue<int> q;
        vector<bool> vis(A + 1, false);
        for(int coin: coins){
            if(coin <= A){
                q.push(coin);
                vis[coin] = true;
            }
        }
        
        int level = 1;
        while(!q.empty()){
            for(int k = q.size(); k >= 1; --k){
                int sum = q.front();
                q.pop();
                
                if(sum == A){
                    return level;
                }
                
                for(int coin: coins){
                    if(sum <= A - coin && !vis[sum + coin]){
                        q.push(sum + coin);
                        vis[sum + coin] = true;
                    }
                }
            }
            level += 1;
        }
        
        return -1;
    }
};