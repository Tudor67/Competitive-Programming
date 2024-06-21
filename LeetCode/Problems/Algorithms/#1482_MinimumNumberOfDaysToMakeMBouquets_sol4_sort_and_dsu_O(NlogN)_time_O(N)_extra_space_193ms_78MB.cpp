class DSU{
private:
    vector<int> size;
    vector<int> parent;

public:
    DSU(const int N){
        size.assign(N, 1);
        parent.assign(N, 1);
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

    void updateSize(int x, int newSize){
        size[find(x)] = newSize;
    }
};

class Solution {
public:
    int minDays(vector<int>& bloomDays, int m, int k) {
        const int N = bloomDays.size();

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                return (bloomDays[lhs] < bloomDays[rhs]);
             });

        DSU dsu(N);
        vector<bool> bloomed(N, false);
        int bouquets = 0;

        for(int i: p){
            bloomed[i] = true;

            if(i - 1 >= 0 && bloomed[i - 1]){
                dsu.join(i - 1, i);
            }
            if(i + 1 < N && bloomed[i + 1]){
                dsu.join(i, i + 1);
            }
            
            if(dsu.getSize(i) >= k){
                bouquets += 1;
                dsu.updateSize(i, dsu.getSize(i) - k);
            }

            if(bouquets >= m){
                return bloomDays[i];
            }
        }

        return -1;
    }
};