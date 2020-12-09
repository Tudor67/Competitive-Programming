class Solution {
public:
    int integerReplacement(int N) {
        unordered_set<long long> vis;
        vis.insert(N);
        queue<pair<long long, int>> q;
        q.push({N, 0});
        
        while(!q.empty()){
            long long num = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            if(num == 1){
                return dist;
            }
            
            if(num % 2 == 0){
                if(!vis.count(num / 2)){
                    q.push({num / 2, dist + 1});
                    vis.insert(num / 2);
                }
            }else{
                if(!vis.count(num + 1)){
                    q.push({num + 1, dist + 1});
                    vis.insert(num + 1);
                }
                if(!vis.count(num - 1)){
                    q.push({num - 1, dist + 1});
                    vis.insert(num - 1);
                }
            }
        }
        
        return -1;
    }
};