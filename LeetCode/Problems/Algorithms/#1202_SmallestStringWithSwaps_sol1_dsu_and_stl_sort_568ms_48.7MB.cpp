class DSU{
private:
    const int N;
    vector<int> parent;
    vector<int> rank;
    
public:
    DSU(const int& N): N(N){
        rank.resize(N + 1, 0);
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
        int x_root = find(x);
        int y_root = find(y);
        if(x_root != y_root){
            // union
            if(rank[x_root] <= rank[y_root]){
                parent[x_root] = y_root;
            }else{
                parent[y_root] = x_root;
            }
            // update rank
            if(rank[x_root] == rank[y_root]){
                rank[y_root] += 1;
            }
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        const int N = s.length();
        
        DSU dsu(N);
        for(const vector<int>& PAIR: pairs){
            dsu.join(PAIR[0], PAIR[1]);
        }
        
        vector<string> string_of(N);
        for(int i = 0; i < N; ++i){
            int root = dsu.find(i);
            string_of[root].push_back(s[i]);
        }
        
        for(int root = 0; root < N; ++root){
            if(!string_of[root].empty()){
                sort(string_of[root].rbegin(), string_of[root].rend());
            }
        }
        
        string answer(N, '.');
        for(int i = 0; i < N; ++i){
            int root = dsu.find(i);
            answer[i] = string_of[root].back();
            string_of[root].pop_back();
        }
        
        return answer;
    }
};