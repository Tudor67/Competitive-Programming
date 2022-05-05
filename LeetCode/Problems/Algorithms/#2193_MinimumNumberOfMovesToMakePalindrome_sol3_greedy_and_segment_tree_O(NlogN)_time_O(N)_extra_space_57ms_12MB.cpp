class SegmentTree{
private:
    const int N;
    vector<int> tree;
    
    void add(int node, int l, int r, const int& POS, const int& VAL){
        if(l == r){
            tree[node] += VAL;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                add(2 * node + 1, l, mid, POS, VAL);
            }else{
                add(2 * node + 2, mid + 1, r, POS, VAL);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
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
        return query(2 * node + 1, l, mid, L, R) +
               query(2 * node + 2, mid + 1, r, L, R);
    }
    
public:
    SegmentTree(const int& N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
    }
    
    void add(const int& POS, const int& VAL){
        add(0, 0, N - 1, POS, VAL);
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
    int minMovesToMakePalindrome(string s) {
        const int N = s.length();
        
        vector<list<int>> posOf(26);
        for(int i = 0; i < N; ++i){
            posOf[s[i] - 'a'].push_back(i);
        }
        
        SegmentTree segmentTree(N);
        for(int i = 0; i < N; ++i){
            segmentTree.add(i, 1);
        }
        
        int minMoves = 0;
        int i = 0;
        int j = N - 1;
        vector<bool> vis(N, false);
        while(i < j){
            if(vis[i]){
                i += 1;
            }else if(vis[j]){
                j -= 1;
            }else if(s[i] == s[j]){
                vis[i] = true;
                vis[j] = true;
                segmentTree.add(posOf[s[i] - 'a'].front(), -1);
                segmentTree.add(posOf[s[i] - 'a'].back(), -1);
                posOf[s[i] - 'a'].pop_front();
                posOf[s[i] - 'a'].pop_back();
                i += 1;
                j -= 1;
            }else{
                int moves1 = segmentTree.query(0, posOf[s[j] - 'a'].front() - 1);
                int moves2 = segmentTree.query(posOf[s[i] - 'a'].back() + 1, N - 1);
                if(moves1 <= moves2){
                    vis[posOf[s[j] - 'a'].front()] = true;
                    vis[posOf[s[j] - 'a'].back()] = true;
                    segmentTree.add(posOf[s[j] - 'a'].front(), -1);
                    segmentTree.add(posOf[s[j] - 'a'].back(), -1);
                    posOf[s[j] - 'a'].pop_front();
                    posOf[s[j] - 'a'].pop_back();
                    minMoves += moves1;
                    j -= 1;
                }else{
                    vis[posOf[s[i] - 'a'].front()] = true;
                    vis[posOf[s[i] - 'a'].back()] = true;
                    segmentTree.add(posOf[s[i] - 'a'].front(), -1);
                    segmentTree.add(posOf[s[i] - 'a'].back(), -1);
                    posOf[s[i] - 'a'].pop_front();
                    posOf[s[i] - 'a'].pop_back();
                    minMoves += moves2;
                    i += 1;
                }
            }
        }
        
        return minMoves;
    }
};