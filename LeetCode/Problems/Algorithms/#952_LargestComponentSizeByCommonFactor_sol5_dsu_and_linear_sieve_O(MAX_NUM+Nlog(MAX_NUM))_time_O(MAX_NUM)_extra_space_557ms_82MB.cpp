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
        
        vector<int> primes;
        vector<int> minPrimeOf(MAX_NUM + 1, 1);
        for(int i = 2; i <= MAX_NUM; ++i){
            if(minPrimeOf[i] == 1){
                primes.push_back(i);
                minPrimeOf[i] = i;
            }
            for(int j = 0; j < (int)primes.size() && primes[j] <= minPrimeOf[i] && primes[j] * i <= MAX_NUM; ++j){
                minPrimeOf[primes[j] * i] = primes[j];
            }
        }
        
        DSU dsu(MAX_NUM);
        for(int num: nums){
            for(int x = num; x > 1; x /= minPrimeOf[x]){
                dsu.join(num, minPrimeOf[x]);
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