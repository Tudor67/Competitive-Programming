class Solution {
public:
    int candy(vector<int>& ratings) {
        const int N = ratings.size();

        vector<vector<int>> G(N);
        for(int i = 0; i < N; ++i){
            if(i - 1 >= 0 && ratings[i - 1] < ratings[i]){
                G[i - 1].push_back(i);
            }
            if(i + 1 < N && ratings[i + 1] < ratings[i]){
                G[i + 1].push_back(i);
            }
        }

        vector<int> inDegree(N);
        for(int node = 0; node < N; ++node){
            for(int nextNode: G[node]){
                inDegree[nextNode] += 1;
            }
        }

        queue<int> q;
        for(int node = 0; node < N; ++node){
            if(inDegree[node] == 0){
                q.push(node);
            }
        }

        int totalCandies = 0;
        int level = 1;
        while(!q.empty()){
            for(int i = q.size(); i >= 1; --i){
                int node = q.front();
                q.pop();

                totalCandies += level;

                for(int nextNode: G[node]){
                    inDegree[nextNode] -= 1;
                    if(inDegree[nextNode] == 0){
                        q.push(nextNode);
                    }
                }
            }
            
            level += 1;
        }

        return totalCandies;
    }
};