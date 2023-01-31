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
        if(r < L || R < l){
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
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        const int N = scores.size();

        vector<int> sortedUniqueScores = scores;
        sort(sortedUniqueScores.begin(), sortedUniqueScores.end());
        sortedUniqueScores.resize(unique(sortedUniqueScores.begin(), sortedUniqueScores.end())
                                  - sortedUniqueScores.begin());

        vector<pair<int, int>> sortedAgesScores(N);
        for(int i = 0; i < N; ++i){
            sortedAgesScores[i] = {ages[i], scores[i]};
        }

        sort(sortedAgesScores.begin(), sortedAgesScores.end());

        // dp[i]: highest overall score of sorted players[0 .. i]
        //        when sorted player[i] is included in the best team
        vector<int> dp(N);
        SegmentTree tree(sortedUniqueScores.size());
        for(int i = 0; i < N; ++i){
            int score = sortedAgesScores[i].second;
            int compressedScore = lower_bound(sortedUniqueScores.begin(), sortedUniqueScores.end(), score)
                                  - sortedUniqueScores.begin();
            dp[i] = score + tree.query(0, compressedScore);
            tree.update(compressedScore, dp[i]);
        }

        return *max_element(dp.begin(), dp.end());
    }
};