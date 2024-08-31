class DSU{
private:
    vector<int> size;
    vector<int> parent;
    int connectedComponents;

public:
    DSU(const int N){
        size.assign(N, 1);
        parent.assign(N, 1);
        iota(parent.begin(), parent.end(), 0);
        connectedComponents = N;
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
        if(xRoot == yRoot){
            return;
        }
        if(size[xRoot] > size[yRoot]){
            swap(xRoot, yRoot);
        }
        parent[xRoot] = yRoot;
        size[yRoot] += size[xRoot];
        connectedComponents -= 1;
    }

    int getConnectedComponentsCount(){
        return connectedComponents;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        const int N = stones.size();

        DSU dsu(N);
        unordered_map<int, int> prevNodeAtRow;
        unordered_map<int, int> prevNodeAtCol;

        for(int i = 0; i < N; ++i){
            int row = stones[i][0];
            int col = stones[i][1];

            if(prevNodeAtRow.count(row)){
                dsu.join(prevNodeAtRow[row], i);
            }
            if(prevNodeAtCol.count(col)){
                dsu.join(prevNodeAtCol[col], i);
            }

            prevNodeAtRow[row] = i;
            prevNodeAtCol[col] = i;
        }

        return N - dsu.getConnectedComponentsCount();
    }
};