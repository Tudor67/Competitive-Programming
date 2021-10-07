class DSU{
private:
    vector<int> parent;
    vector<int> rank;
    vector<long long> sum;
    
public:
    DSU(const int& N){
        sum.resize(N);
        rank.resize(N);
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
                sum[yRoot] += sum[xRoot];
            }else{
                parent[yRoot] = xRoot;
                sum[xRoot] += sum[yRoot];
            }
            if(rank[xRoot] == rank[yRoot]){
                rank[yRoot] += 1;
            }
        }
    }
    
    void setSum(int x, long long s){
        sum[find(x)] = s;
    }
    
    long long getSum(int x){
        return sum[find(x)];
    }
};

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        const int N = nums.size();
        const int MODULO = 1e9 + 7;
        
        // Step 1: sort nums in decreasing order and remember its indices in the original vector
        vector<pair<int, int>> v(N);
        for(int i = 0; i < N; ++i){
            v[i] = {nums[i], i};
        }
        
        sort(v.rbegin(), v.rend());
        
        // Step 2: each num represents a group
        //         set the sum of each group (initially is the num itself)
        DSU dsu(N);
        for(int i = 0; i < N; ++i){
            dsu.setSum(i, nums[i]);
        }
        
        // Step 3: process the numbers in decreasing order (from largest to smallest)
        //         a.) fix the current nums[idx] and look at adjacent nums[idx - 1] and nums[idx + 1];
        //         b.) if the adjacent num is larger (or equal, but in different group) then merge it with nums[idx]
        //              and update the group sum;
        //         c.) compute current product = nums[idx] * groupSumOfNums[idx];
        //             at this point nums[idx] is the minimum,
        //             because we process nums in decreasing order and merge them only with larger (or equal) adjacent nums; 
        //         d.) update maxProduct;
        long long maxProduct = 0;
        for(const pair<int, int>& P: v){
            int idx = P.second;
            for(int neighIdx: {idx - 1, idx + 1}){
                if(0 <= neighIdx && neighIdx < N && dsu.find(idx) != dsu.find(neighIdx)){
                    if(nums[idx] <= nums[neighIdx]){
                        dsu.join(idx, neighIdx);
                    }
                }
            }
            long long product = nums[idx] * dsu.getSum(idx);
            maxProduct = max(product, maxProduct);
        }
        
        return maxProduct % MODULO;
    }
};