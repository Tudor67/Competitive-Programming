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
    
    void reset(int x){
        parent[x] = x;
        rank[x] = 0;
    }
};

class Solution {
public:
    vector<int> findAllPeople(int N, vector<vector<int>>& meetings, int firstPerson) {
        vector<tuple<int, int, int>> v;
        for(const vector<int>& XYT: meetings){
            int x = XYT[0];
            int y = XYT[1];
            int t = XYT[2];
            v.emplace_back(t, x, y);
        }
        
        sort(v.begin(), v.end());
        v.emplace_back(-1, -1, -1);
        
        DSU dsu(N);
        dsu.join(0, firstPerson);
        
        int startPos = 0;
        for(int endPos = 0; endPos < (int)v.size(); ++endPos){
            if(get<0>(v[startPos]) != get<0>(v[endPos])){
                for(int i = startPos; i < endPos; ++i){
                    int x, y;
                    tie(ignore, x, y) = v[i];
                    dsu.join(x, y);
                }
                
                int root = dsu.find(0);
                for(int i = startPos; i < endPos; ++i){
                    int x, y;
                    tie(ignore, x, y) = v[i];
                    if(dsu.find(x) != root){
                        dsu.reset(x);
                        dsu.reset(y);
                    }
                }
                
                startPos = endPos;
            }
        }
        
        vector<int> answer;
        int root = dsu.find(0);
        for(int x = 0; x < N; ++x){
            if(dsu.find(x) == root){
                answer.push_back(x);
            }
        }
        
        return answer;
    }
};