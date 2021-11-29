class DSU{
private:
    vector<int> rank;
    vector<int> parent;
    
public:
    DSU(const int& N){
        rank.assign(N + 1, 0);
        parent.assign(N + 1, 0);
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
                rank[yRoot] += (int)(rank[xRoot] == rank[yRoot]);
            }else{
                parent[yRoot] = xRoot;
            }
        }
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const int N = nums.size();
        
        DSU dsu(MAX_NUM);
        for(int num: nums){
            for(int x = 2; x * x <= num; ++x){
                if(num % x == 0){
                    for(int divisor: {x, num / x}){
                        dsu.join(num, divisor);
                    }
                }
            }
        }
        
        int maxSize = 1;
        unordered_map<int, int> sizeOf;
        for(int num: nums){
            int numRoot = dsu.find(num);
            sizeOf[numRoot] += 1;
            maxSize = max(maxSize, sizeOf[numRoot]);
        }
        
        return maxSize;
    }
};