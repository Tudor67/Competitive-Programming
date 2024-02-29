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

        vector<int> minPrime(MAX_NUM + 1, 0);
        vector<int> primes;
        for(int i = 2; i <= MAX_NUM; ++i){
            if(minPrime[i] == 0){
                minPrime[i] = i;
                primes.push_back(i);
            }
            for(int j = 0; j < (int)primes.size() && primes[j] <= minPrime[i] && primes[j] * i <= MAX_NUM; ++j){
                minPrime[primes[j] * i] = primes[j];
            }
        }

        unordered_map<int, vector<int>> factorToIndices;
        for(int i = 0; i < N; ++i){
            int x = nums[i];
            while(minPrime[x] > 1){
                factorToIndices[minPrime[x]].push_back(i);
                x /= minPrime[x];
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