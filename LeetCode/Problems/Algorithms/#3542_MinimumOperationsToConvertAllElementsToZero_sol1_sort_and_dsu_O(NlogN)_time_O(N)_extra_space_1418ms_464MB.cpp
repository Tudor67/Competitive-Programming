class DSU{
private:
    vector<int> parent;
    vector<int> size;

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
        if(xRoot == yRoot){
            return;
        }
        if(size[xRoot] > size[yRoot]){
            swap(xRoot, yRoot);
        }
        parent[xRoot] = yRoot;
        size[yRoot] += size[xRoot];
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int N = nums.size();

        map<int, vector<int>> numToIndices;
        for(int i = 0; i < N; ++i){
            numToIndices[nums[i]].push_back(i);
        }

        numToIndices.erase(0);

        int totalOps = 0;
        DSU dsu(N);
        unordered_set<int> vis;

        for(auto it = numToIndices.rbegin(); it != numToIndices.rend(); it = next(it)){
            const vector<int>& INDICES = it->second;

            for(int i: INDICES){
                if(i - 1 >= 0 && nums[i - 1] >= nums[i]){
                    dsu.join(i - 1, i);
                }
                if(i + 1 < N && nums[i + 1] >= nums[i]){
                    dsu.join(i + 1, i);
                }
            }

            vis.clear();
            for(int i: INDICES){
                vis.insert(dsu.find(i));
            }

            totalOps += (int)vis.size();
        }

        return totalOps;
    }
};