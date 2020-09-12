class DSU{
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    DSU(const int& N){
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
            if(rank[x_root] <= rank[y_root]){
                parent[x_root] = y_root;
            }else{
                parent[y_root] = x_root;
            }
            if(rank[x_root] == rank[y_root]){
                rank[y_root] += 1;
            }
        }
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        const int N = nums.size();
        unordered_map<int, int> pos;
        for(int i = 0; i < N; ++i){
            pos[nums[i]] = i;
        }
        
        DSU dsu(N);
        for(const pair<int, int>& P: pos){
            int num = P.first;
            int position = P.second;
            if(num < INT_MAX && pos.count(num + 1)){
                dsu.join(position, pos[num + 1]);
            }
        }
        
        unordered_map<int, int> seq_size;
        for(const pair<int, int>& P: pos){
            int position = P.second;
            int position_root = dsu.find(position);
            seq_size[position_root] += 1;
        }
        
        int answer = 0;
        for(const pair<int, int>& P: seq_size){
            answer = max(P.second, answer);
        }
        
        return answer;
    }
};