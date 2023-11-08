class DSU{
private:
    vector<int> rank;
    vector<int> parent;
    int componentsCount;
    
public:
    DSU(const int N){
        rank.resize(N);
        parent.resize(N);
        iota(parent.begin(), parent.end(), 0);
        componentsCount = N;
    }
    
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void join(int x, int y){
        int xRoot = find(x);
        int yRoot = find(y);
        if(xRoot != yRoot){
            componentsCount -= 1;
            if(rank[xRoot] <= rank[yRoot]){
                parent[xRoot] = yRoot;
                rank[yRoot] += (int)(rank[xRoot] == rank[yRoot]);
            }else{
                parent[yRoot] = xRoot;
            }
        }
    }
    
    int getComponentsCount(){
        return componentsCount;
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        const int N = nums.size();
        
        unordered_map<int, vector<int>> factorsToIndices;
        for(int i = 0; i < N; ++i){
            int x = nums[i];
            for(int f = 2; f * f <= x; ++f){
                if(x % f == 0){
                    factorsToIndices[f].push_back(i);
                    while(x % f == 0){
                        x /= f;
                    }
                }
            }
            if(x > 1){
                factorsToIndices[x].push_back(i);
            }
        }
        
        DSU dsu(N);
        for(const pair<int, vector<int>>& P: factorsToIndices){
            const vector<int>& INDICES = P.second;
            for(int i: INDICES){
                dsu.join(INDICES[0], i);
            }
        }
        
        return (dsu.getComponentsCount() == 1);
    }
};