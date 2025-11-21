class SegmentTree{
private:
    const int N;
    vector<int> tree;

    void update(int node, int l, int r, const int POS, const int VAL){
        if(l == r){
            tree[node] = VAL;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                update(2 * node + 1, l, mid, POS, VAL);
            }else{
                update(2 * node + 2, mid + 1, r, POS, VAL);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    int computeSum(int node, int l, int r, const int L, const int R){
        if(R < l || r < L){
            return 0;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return computeSum(2 * node + 1, l, mid, L, R) +
               computeSum(2 * node + 2, mid + 1, r, L, R);
    }

public:
    SegmentTree(const int N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.assign(2 * minLeaves, 0);
    }

    void update(const int POS, const int VAL){
        update(0, 0, N - 1, POS, VAL);
    }

    int computeSum(const int L, const int R){
        if(L > R){
            return 0;
        }
        return computeSum(0, 0, N - 1, L, R);
    }
};

class Solution {
private:
    int compress(vector<int>& sortedNums, int val){
        return lower_bound(sortedNums.begin(), sortedNums.end(), val) - sortedNums.begin();
    }

public:
    int intersectionSizeTwo(vector<vector<int>>& originalIntervals) {
        const int N = originalIntervals.size();

        // coordinate compression
        vector<int> sortedNums;
        sortedNums.reserve(2 * N);
        for(vector<int>& interval: originalIntervals){
            sortedNums.push_back(interval[0]);
            sortedNums.push_back(interval[1]);
        }

        sort(sortedNums.begin(), sortedNums.end());
        sortedNums.resize(unique(sortedNums.begin(), sortedNums.end()) - sortedNums.begin());

        vector<array<int, 2>> intervals(N);
        for(int i = 0; i < N; ++i){
            int l = compress(sortedNums, originalIntervals[i][0]);
            int r = compress(sortedNums, originalIntervals[i][1]);
            intervals[i] = {l, r};
        }

        // solve for compressed intervals
        map<int, vector<int>> endToStarts;
        for(int i = 0; i < N; ++i){
            int l = intervals[i][0];
            int r = intervals[i][1];
            endToStarts[r].push_back(l);
        }

        const int MAX_NUM = compress(sortedNums, sortedNums.back());
        SegmentTree tree(MAX_NUM + 1);

        set<int> waitingSet;
        for(int num = 0; num <= MAX_NUM; ++num){
            waitingSet.insert(num);
        }

        for(const auto& [r, ls]: endToStarts){
            for(int l: ls){
                while(tree.computeSum(l, r) < 2){
                    int num = *prev(waitingSet.upper_bound(r));
                    waitingSet.erase(num);
                    tree.update(num, 1);
                }
            }
        }

        return tree.computeSum(0, MAX_NUM);
    }
};