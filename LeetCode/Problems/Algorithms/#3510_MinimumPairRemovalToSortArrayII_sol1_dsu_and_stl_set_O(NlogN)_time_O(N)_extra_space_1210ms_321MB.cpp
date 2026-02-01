class DSU{
private:
    vector<int> parent;
    vector<long long> sum;
    vector<int> left;
    vector<int> right;

public:
    DSU(const int N){
        parent.resize(N);
        sum.resize(N);
        left.resize(N);
        right.resize(N);

        for(int i = 0; i < N; ++i){
            parent[i] = i;
            sum[i] = 0;
            left[i] = i;
            right[i] = i;
        }
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
        if(right[xRoot] - left[xRoot] > right[yRoot] - left[yRoot]){
            swap(xRoot, yRoot);
        }
        parent[xRoot] = yRoot;
        sum[yRoot] += sum[xRoot];
        left[yRoot] = min(left[yRoot], left[xRoot]);
        right[yRoot] = max(right[yRoot], right[xRoot]);
    }

    void setSum(int x, long long newSum){
        sum[find(x)] = newSum;
    }

    long long getSum(int x){
        return sum[find(x)];
    }

    int getLeft(int x){
        return left[find(x)];
    }

    int getRight(int x){
        return right[find(x)];
    }
};

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        const int N = nums.size();
        const long long INF = 1e15;

        DSU dsu(N + 2);
        dsu.setSum(0, INF);
        dsu.setSum(N + 1, INF);
        for(int i = 0; i < N; ++i){
            dsu.setSum(i + 1, nums[i]);
        }

        set<pair<long long, int>> s;
        int badAdjPairs = -1;
        for(int i = 0; i <= N; ++i){
            s.insert({dsu.getSum(i) + dsu.getSum(i + 1), i});
            badAdjPairs += (int)(dsu.getSum(i) > dsu.getSum(i + 1));
        }

        int minOps = 0;
        while(badAdjPairs > 0){
            minOps += 1;

            int i = s.begin()->second;
            int j = dsu.getRight(i) + 1;

            assert(s.erase({dsu.getSum(dsu.getLeft(i) - 1) + dsu.getSum(i), dsu.find(dsu.getLeft(i) - 1)}));
            assert(s.erase({dsu.getSum(i) + dsu.getSum(j), dsu.find(i)}));
            assert(s.erase({dsu.getSum(j) + dsu.getSum(dsu.getRight(j) + 1), dsu.find(j)}));

            badAdjPairs -= (int)(dsu.getSum(dsu.getLeft(i) - 1) > dsu.getSum(i));
            badAdjPairs -= (int)(dsu.getSum(i) > dsu.getSum(j));
            badAdjPairs -= (int)(dsu.getSum(j) > dsu.getSum(dsu.getRight(j) + 1));

            dsu.join(i, j);
            s.insert({dsu.getSum(dsu.getLeft(i) - 1) + dsu.getSum(i), dsu.find(dsu.getLeft(i) - 1)});
            s.insert({dsu.getSum(i) + dsu.getSum(dsu.getRight(i) + 1), dsu.find(i)});

            badAdjPairs += (int)(dsu.getSum(dsu.getLeft(i) - 1) > dsu.getSum(i));
            badAdjPairs += (int)(dsu.getSum(i) > dsu.getSum(dsu.getRight(i) + 1));
        }

        return minOps;
    }
};