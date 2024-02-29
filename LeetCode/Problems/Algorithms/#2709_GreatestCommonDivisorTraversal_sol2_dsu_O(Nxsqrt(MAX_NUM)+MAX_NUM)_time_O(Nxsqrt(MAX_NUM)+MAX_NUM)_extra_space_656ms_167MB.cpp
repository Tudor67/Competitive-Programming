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

        vector<vector<int>> divisorToIndices(MAX_NUM + 1);
        for(int i = 0; i < N; ++i){
            for(int x = 2; x * x <= nums[i]; ++x){
                if(nums[i] % x == 0){
                    divisorToIndices[x].push_back(i);
                    divisorToIndices[nums[i] / x].push_back(i);
                }
            }
            if(nums[i] != 1){
                divisorToIndices[nums[i]].push_back(i);
            }
        }

        DSU dsu(N);
        for(int divisor = 1; divisor <= MAX_NUM; ++divisor){
            for(int j = 1; j < (int)divisorToIndices[divisor].size(); ++j){
                dsu.join(divisorToIndices[divisor][j - 1], divisorToIndices[divisor][j]);
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