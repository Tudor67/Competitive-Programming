class Solution {
public:
    int candy(vector<int>& ratings) {
        const int N = ratings.size();
        
        vector<vector<int>> G(N);
        vector<int> inDegree(N);
        for(int i = 0; i < N; ++i){
            if(i - 1 >= 0 && ratings[i - 1] > ratings[i]){
                G[i].push_back(i - 1);
                inDegree[i - 1] += 1;
            }
            if(i + 1 < N && ratings[i] < ratings[i + 1]){
                G[i].push_back(i + 1);
                inDegree[i + 1] += 1;
            }
        }
        
        queue<int> q;
        for(int node = 0; node < N; ++node){
            if(inDegree[node] == 0){
                q.push(node);
            }
        }
        
        vector<int> candies(N, 1);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int nextNode: G[node]){
                candies[nextNode] = max(candies[nextNode], candies[node] + 1);
                inDegree[nextNode] -= 1;
                if(inDegree[nextNode] == 0){
                    q.push(nextNode);
                }
            }
        }
        
        return accumulate(candies.begin(), candies.end(), 0);
    }
};