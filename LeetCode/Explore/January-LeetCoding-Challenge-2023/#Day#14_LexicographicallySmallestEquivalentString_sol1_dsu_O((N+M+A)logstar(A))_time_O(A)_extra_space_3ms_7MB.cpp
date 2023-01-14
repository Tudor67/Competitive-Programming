class DSU{
private:
    vector<int> rank;
    vector<int> parent;

public:
    DSU(const int& N){
        rank.resize(N + 1);
        parent.resize(N + 1);
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
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        const int N = s1.length();
        const int M = baseStr.length();
        const int A = 26;
        const int FIRST_CHAR = 'a';

        DSU dsu(100 + A);
        for(int i = 0; i < N; ++i){
            dsu.join(s1[i], s2[i]);
        }

        vector<int> minChar(100 + A);
        iota(minChar.begin(), minChar.end(), FIRST_CHAR);
        for(int c = FIRST_CHAR; c < FIRST_CHAR + A; ++c){
            minChar[dsu.find(c)] = min(minChar[dsu.find(c)], c);
        }

        string res = baseStr;
        for(int i = 0; i < M; ++i){
            res[i] = minChar[dsu.find(baseStr[i])];
        }

        return res;
    }
};