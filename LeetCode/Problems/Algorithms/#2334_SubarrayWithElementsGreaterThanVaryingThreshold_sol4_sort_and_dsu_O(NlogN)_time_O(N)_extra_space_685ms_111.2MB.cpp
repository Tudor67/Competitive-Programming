class DSU{
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> groupSize;
    
public:
    DSU(const int& N){
        rank.resize(N);
        groupSize.resize(N, 1);
        parent.resize(N);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x){
        if(x != parent[x]){
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
                groupSize[yRoot] += groupSize[xRoot];
                rank[yRoot] += (int)(rank[xRoot] == rank[yRoot]);
            }else{
                parent[yRoot] = xRoot;
                groupSize[xRoot] += groupSize[yRoot];
            }
        }
    }
    
    int getGroupSize(int x){
        return groupSize[find(x)];
    }
};

class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        const int N = nums.size();
        
        vector<pair<int, int>> v(N);
        for(int i = 0; i < N; ++i){
            v[i] = {nums[i], i};
        }
        
        sort(v.begin(), v.end());
        
        DSU dsu(N);
        for(int i = N - 1; i >= 0; --i){
            int idx = v[i].second;
            if(idx - 1 >= 0 && nums[idx - 1] >= nums[idx]){
                dsu.join(idx - 1, idx);
            }
            if(idx + 1 < N && nums[idx] <= nums[idx + 1]){
                dsu.join(idx, idx + 1);
            }
            long long minNum = nums[idx];
            long long k = dsu.getGroupSize(idx);
            if(minNum * k > threshold){
                return k;
            }
        }
        
        return -1;
    }
};