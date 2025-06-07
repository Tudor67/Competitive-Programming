class DSU{
private:
    vector<int> parent;

public:
    DSU(const int N){
        parent.assign(N, 0);
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
        parent[max(xRoot, yRoot)] = min(xRoot, yRoot);
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        const int N = s1.length();
        const int M = baseStr.length();
        const int A = 26;
        const char FIRST_CHAR = 'a';

        DSU dsu(A);
        for(int i = 0; i < N; ++i){
            dsu.join(s1[i] - FIRST_CHAR, s2[i] - FIRST_CHAR);
        }

        string minBaseStr = baseStr;
        for(int i = 0; i < M; ++i){
            minBaseStr[i] = char(dsu.find(baseStr[i] - FIRST_CHAR) + FIRST_CHAR);
        }

        return minBaseStr;
    }
};