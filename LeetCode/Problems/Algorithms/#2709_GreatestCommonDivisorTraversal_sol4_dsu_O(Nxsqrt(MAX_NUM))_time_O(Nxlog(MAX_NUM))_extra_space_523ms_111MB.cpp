class DSU{
private:
    vector<int> rank;
    vector<int> parent;

public:
    DSU(const int N){
        rank.resize(N);
        parent.resize(N);
        iota(parent.begin(), parent.end(), 0);
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
            if(rank[xRoot] <= rank[yRoot]){
                parent[xRoot] = yRoot;
                rank[yRoot] += (int)(rank[xRoot] == rank[yRoot]);
            }else{
                parent[yRoot] = xRoot;
            }
        }
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        unordered_map<int, vector<int>> factorToIndices;
        for(int i = 0; i < N; ++i){
            int x = nums[i];
            for(int f = 2; f * f <= x; ++f){
                if(x % f == 0){
                    while(x % f == 0){
                        x /= f;
                    }
                    factorToIndices[f].push_back(i);
                }
            }
            if(x > 1){
                factorToIndices[x].push_back(i);
            }
        }

        DSU dsu(N);
        for(const pair<const int, vector<int>>& P: factorToIndices){
            const vector<int>& INDICES = P.second;
            for(int i: INDICES){
                dsu.join(INDICES[0], i);
            }
        }

        for(int i = 1; i < N; ++i){
            if(dsu.find(0) != dsu.find(i)){
                return false;
            }
        }

        return true;
    }
};