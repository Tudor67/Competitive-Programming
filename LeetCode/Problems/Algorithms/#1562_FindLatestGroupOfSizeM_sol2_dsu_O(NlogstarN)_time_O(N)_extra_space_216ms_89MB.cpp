class DSU{
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    
public:
    DSU(const int& N){
        size.resize(N + 1, 1);
        rank.resize(N + 1, 1);
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
            if(rank[x] <= rank[y]){
                parent[xRoot] = yRoot;
                size[yRoot] += size[xRoot];
            }else{
                parent[yRoot] = xRoot;
                size[xRoot] += size[yRoot];
            }
            if(rank[xRoot] == rank[yRoot]){
                rank[yRoot] += 1;
            }
        }
    }
    
    int getSize(int x){
        return size[find(x)];
    }
};

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        const int N = arr.size();
        int answer = -1;
        
        vector<int> count(N + 1, 0);
        vector<bool> vis(N + 1, false);
        DSU dsu(N);
        for(int i = 0; i < N; ++i){
            // delete old sizes
            if(arr[i] - 1 >= 1 && vis[arr[i] - 1]){
                count[dsu.getSize(arr[i] - 1)] -= 1;
            }
            if(arr[i] + 1<= N && vis[arr[i] + 1]){
                count[dsu.getSize(arr[i] + 1)] -= 1;
            }
            
            // union/join (arr[i] - 1) arr[i] (arr[i] + 1) 
            if(arr[i] - 1 >= 1 && vis[arr[i] - 1]){
                dsu.join(arr[i] - 1, arr[i]);
            }
            if(arr[i] + 1 <= N && vis[arr[i] + 1]){
                dsu.join(arr[i], arr[i] + 1);
            }
            
            vis[arr[i]] = true;
            
            // add new size
            int currentSize = dsu.getSize(arr[i]);
            count[currentSize] += 1;
            
            // update answer
            if(count[m] >= 1){
                answer = i + 1;
            }
        }
        
        return answer;
    }
};