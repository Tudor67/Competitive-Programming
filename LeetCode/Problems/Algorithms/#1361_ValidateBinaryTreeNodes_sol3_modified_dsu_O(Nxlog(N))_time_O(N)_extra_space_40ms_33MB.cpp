class DSU{
private:
    vector<int> parent;
    int componentsCount;

public:
    DSU(const int N){
        componentsCount = N;
        parent.resize(N);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool join(int node, int child){
        int nodeRoot = find(node);
        int childRoot = find(child);
        if(nodeRoot == childRoot || childRoot != child){
            return false;
        }
        componentsCount -= 1;
        parent[childRoot] = nodeRoot;
        return true;
    }

    int getComponentsCount(){
        return componentsCount;
    }
};

class Solution {
public:
    bool validateBinaryTreeNodes(int N, vector<int>& leftChild, vector<int>& rightChild) {
        DSU dsu(N);
        for(int node = 0; node < N; ++node){
            for(int child: {leftChild[node], rightChild[node]}){
                if(child != -1){
                    if(!dsu.join(node, child)){
                        return false;
                    }
                }
            }
        }
        return (dsu.getComponentsCount() == 1);
    }
};