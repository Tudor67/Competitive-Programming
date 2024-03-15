class DSU{
private:
    vector<int> size;
    vector<int> parent;

public:
    DSU(const int N){
        size.resize(N, 1);
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
            if(size[xRoot] > size[yRoot]){
                swap(xRoot, yRoot);
            }
            parent[xRoot] = yRoot;
            size[yRoot] += size[xRoot];
        }
    }

    int getSize(int x){
        return size[find(x)];
    }
};

class Solution {
public:
    long long countPaths(int N, vector<vector<int>>& edges) {
        vector<bool> isPrime(N + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i <= N; ++i){
            if(isPrime[i]){
                for(int j = i + i; j <= N; j += i){
                    isPrime[j] = false;
                }
            }
        }

        DSU dsu(N + 1);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            if(!isPrime[a] && !isPrime[b]){
                dsu.join(a, b);
            }
        }

        long long res = 0;
        vector<long long> nonPrimesCount(N + 1);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];

            if(!isPrime[a] && isPrime[b]){
                swap(a, b);
            }

            if(isPrime[a] && !isPrime[b]){
                long long c = dsu.getSize(b);
                res += c * nonPrimesCount[a] + c;
                nonPrimesCount[a] += c;
            }
        }

        return res;
    }
};