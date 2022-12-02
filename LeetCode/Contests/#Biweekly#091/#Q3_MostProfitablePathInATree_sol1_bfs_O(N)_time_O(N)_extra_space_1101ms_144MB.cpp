class Solution {
private:
    using Graph = vector<vector<int>>;
    const int INF = 1e9;
    
    void computeDist(int srcNode, const Graph& G, vector<int>& dist){
        queue<int> q;
        q.push(srcNode);
        
        fill(dist.begin(), dist.end(), INF);
        dist[srcNode] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int nextNode: G[node]){
                if(dist[node] + 1 < dist[nextNode]){
                    dist[nextNode] = dist[node] + 1;
                    q.push(nextNode);
                }
            }
        }
    }
    
    int computeMaxIncome(int alice, int bob, const Graph& G, vector<int>& aDist, vector<int>& bDist, vector<int>& amount){
        int maxIncome = INT_MIN;
        
        queue<pair<int, int>> q;
        q.push({alice, amount[alice]});
        while(!q.empty()){
            int node = q.front().first;
            int income = q.front().second;
            q.pop();
            
            bool isLeaf = true;
            for(int nextNode: G[node]){
                if(aDist[node] + 1 == aDist[nextNode]){
                    isLeaf = false;
                    int nextIncome = income;
                    if(aDist[nextNode] + bDist[nextNode] == aDist[bob]){
                        if(aDist[nextNode] == bDist[nextNode]){
                            nextIncome += amount[nextNode] / 2;
                        }else if(aDist[nextNode] < bDist[nextNode]){
                            nextIncome += amount[nextNode];
                        }
                    }else{
                        nextIncome += amount[nextNode];
                    }
                    q.push({nextNode, nextIncome});
                }
            }
            
            if(isLeaf){
                maxIncome = max(maxIncome, income);
            }
        }
        
        return maxIncome;
    }
    
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        const int N = amount.size();
        
        Graph G(N);
        for(const vector<int>& E: edges){
            int x = E[0];
            int y = E[1];
            G[x].push_back(y);
            G[y].push_back(x);
        }
        
        vector<int> aDist(N);
        computeDist(0, G, aDist);
        
        vector<int> bDist(N);
        computeDist(bob, G, bDist);
        
        return computeMaxIncome(0, bob, G, aDist, bDist, amount);
    }
};