class DSU{
private:
    const int N;
    vector<long long> sum;
    vector<int> rank;
    vector<int> parent;
    
public:
    DSU(const vector<int>& NUMS): N(NUMS.size()){
        sum.resize(N);
        copy(NUMS.begin(), NUMS.end(), sum.begin());
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
                sum[yRoot] += sum[xRoot];
                rank[yRoot] += (int)(rank[xRoot] == rank[yRoot]);
            }else{
                parent[yRoot] = xRoot;
                sum[xRoot] += sum[yRoot];
            }
        }
    }
    
    long long getSum(int x){
        return sum[find(x)];
    }
};

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        const int N = nums.size();
        
        DSU dsu(nums);
        long long maxSum = 0;
        vector<bool> vis(N, false);
        
        vector<long long> res(N);
        for(int i = N - 1; i >= 0; --i){
            res[i] = maxSum;
            
            int pos = removeQueries[i];
            if(pos - 1 >= 0 && vis[pos - 1]){
                dsu.join(pos - 1, pos);
            }
            if(pos + 1 < N && vis[pos + 1]){
                dsu.join(pos, pos + 1);
            }
            
            maxSum = max(maxSum, dsu.getSum(pos));
            
            vis[pos] = true;
        }
        
        return res;
    }
};