class SegmentTree{
private:
    const int N;
    vector<int> tree;
    
    void update(int node, int l, int r, const int& POS, const int& NEW_VAL){
        if(l == r){
            tree[node] = NEW_VAL;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                update(2 * node + 1, l, mid, POS, NEW_VAL);
            }else{
                update(2 * node + 2, mid + 1, r, POS, NEW_VAL);
            }
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    int query(int node, int l, int r, const int& L, const int& R){
        if(r < L || R < l){
            return 0;
        }else if(L <= l && r <= R){
            return tree[node];
        }else{
            int mid = (l + r) / 2;
            return max(query(2 * node + 1, l, mid, L, R),
                       query(2 * node + 2, mid + 1, r, L, R));
        }
    }
    
public:
    SegmentTree(const int& N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
    }
    
    void update(const int& POS, const int& NEW_VAL){
        update(0, 0, N - 1, POS, NEW_VAL);
    }
    
    int query(const int& L, const int& R){
        return query(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        const int N = scores.size();
        const int MAX_AGE = *max_element(ages.begin(), ages.end());
        
        vector<pair<int, int>> sortedScoreAge(N);
        for(int i = 0; i < N; ++i){
            sortedScoreAge[i] = {scores[i], ages[i]};
        }
        
        sort(sortedScoreAge.begin(), sortedScoreAge.end());
        
        SegmentTree segmentTree(MAX_AGE + 1);
        for(int i = 0; i < N; ++i){
            int score = sortedScoreAge[i].first;
            int age = sortedScoreAge[i].second;
            int maxScore = score + segmentTree.query(1, age);
            segmentTree.update(age, maxScore);
        }
        
        return segmentTree.query(1, MAX_AGE);
    }
};