#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
private:
    const int N;
    vector<int> tree;

    void buildTree(int node, int l, int r, const vector<int>& V){
        if(l == r){
            tree[node] = V[r];
        }else{
            int mid = (l + r) / 2;
            buildTree(2 * node + 1, l, mid, V);
            buildTree(2 * node + 2, mid + 1, r, V);
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int query(int node, int l, int r, const int& L, const int& R){
        if(r < L || R < l){
            return INT_MAX;
        }else if(L <= l && r <= R){
            return tree[node];
        }else{
            int mid = (l + r) / 2;
            return min(query(2 * node + 1, l, mid, L, R),
                       query(2 * node + 2, mid + 1, r, L, R));
        }
    }

public:
    SegmentTree(const vector<int>& V): N(V.size()){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.assign(2 * minLeaves, INT_MAX);
        buildTree(0, 0, N - 1, V);
    }

    int query(const int& L, const int& R){
        return query(0, 0, N - 1, L, R);
    }
};

class Solution{
private:
    void computeSuffixArray(const string& S, vector<int>& suff){
        const int N = S.length();
        const int LOG_N = 1 + floor(log2(N));

        vector<vector<int>> c(2, vector<int>(N));
        for(int i = 0; i < N; ++i){
            c[0][i] = S[i] - 'a';
        }

        vector<pair<pair<int, int>, int>> v(N);
        for(int k = 1; k <= LOG_N; ++k){
            int len = (1 << k);
            for(int i = 0; i < N; ++i){
                int l = c[(k - 1) % 2][i];
                int r = (i + len / 2 < N ? c[(k - 1) % 2][i + len / 2] : -1);
                v[i].first = {l, r};
                v[i].second = i;
            }

            sort(v.begin(), v.end());

            int classID = 0;
            for(int i = 0; i < N; ++i){
                if(i > 0 && v[i - 1].first != v[i].first){
                    ++classID;
                }
                c[k % 2][v[i].second] = classID;
            }
        }

        suff.resize(N);
        for(int i = 0; i < N; ++i){
            suff[c[LOG_N % 2][i]] = i;
        }
    }

    int lowerBound(const string& S, const string& WORD, vector<int>& suff){
        const int N = S.length();
        int l = 0;
        int r = N - 1;
        while(l != r){
            int mid = (l + r) / 2;
            if(S.compare(suff[mid], WORD.length(), WORD, 0, WORD.length()) < 0){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
    }

    int upperBound(const string& S, const string& WORD, vector<int>& suff){
        const int N = S.length();
        int l = 0;
        int r = N;
        while(l != r){
            int mid = (l + r) / 2;
            if(S.compare(suff[mid], WORD.length(), WORD, 0, WORD.length()) <= 0){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return r;
    }

public:
    void firstPosOfPatterns(const string& S, const vector<string>& P, vector<int>& firstPos){
        const int N = S.length();
        const int K = P.size();

        vector<int> suff;
        computeSuffixArray(S, suff);

        SegmentTree segmentTree(suff);

        firstPos.resize(K);
        for(int i = 0; i < K; ++i){
            int lowerIdx = lowerBound(S, P[i], suff);
            int upperIdx = upperBound(S, P[i], suff);
            if(lowerIdx <= upperIdx - 1){
                firstPos[i] = 1 + segmentTree.query(lowerIdx, upperIdx - 1);
            }else{
                firstPos[i] = -1;
            }
        }
    }
};

int main(){
    string s;
    cin >> s;

    int k;
    cin >> k;

    vector<string> p(k);
    for(int i = 0; i < k; ++i){
        cin >> p[i];
    }

    vector<int> firstPos;
    Solution().firstPosOfPatterns(s, p, firstPos);

    for(int i = 0; i < k; ++i){
        cout << firstPos[i] << "\n";
    }

    return 0;
}