class SegmentTree{
private:
    const int N;
    vector<int> tree;

    void update(int node, int l, int r, const int& POS, const int& VAL){
        if(l == r){
            tree[node] = VAL;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                update(2 * node + 1, l, mid, POS, VAL);
            }else{
                update(2 * node + 2, mid + 1, r, POS, VAL);
            }
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int query(int node, int l, int r, const int& L, const int& R){
        if(R < l || r < L){
            return 0;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return max(query(2 * node + 1, l, mid, L, R),
                   query(2 * node + 2, mid + 1, r, L, R));
    }

public:
    SegmentTree(const int& N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
    }

    void update(const int& POS, const int& VAL){
        update(0, 0, N - 1, POS, VAL);
    }

    int query(const int& L, const int& R){
        if(L > R){
            return 0;
        }
        return query(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        const int N = obstacles.size();

        // Step 1: coordinate compression
        vector<int> sortedHeights = obstacles;
        sort(sortedHeights.begin(), sortedHeights.end());
        sortedHeights.resize(unique(sortedHeights.begin(), sortedHeights.end()) - sortedHeights.begin());

        // Step 2: DP with SegmentTree
        //         segmentTree.query(a, b): max length of a non-decreasing subsequence/course
        //                                  with last compressedHeight in range [a, b]
        SegmentTree tree(sortedHeights.size());
        vector<int> answer(N);
        for(int i = 0; i < N; ++i){
            int compressedHeight = lower_bound(sortedHeights.begin(), sortedHeights.end(), obstacles[i])
                                   - sortedHeights.begin();

            int maxLen = 1 + tree.query(0, compressedHeight);
            answer[i] = maxLen;

            tree.update(compressedHeight, maxLen);
        }

        return answer;
    }
};