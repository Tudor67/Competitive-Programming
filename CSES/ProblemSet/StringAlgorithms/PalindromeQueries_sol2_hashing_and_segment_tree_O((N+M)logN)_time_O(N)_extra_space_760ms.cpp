#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
private:
    static const int ALPHABET_SIZE = 26;
    static const int FIRST_ELEM = 'a';
    const int N;
    const long long MODULO;
    vector<long long> COEF;
    vector<long long> tree;

    void update(int node, int l, int r, const int& POS, const int& VAL){
        if(l == r){
            tree[node] = (COEF[r] * (VAL - FIRST_ELEM + 1)) % MODULO;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                update(2 * node + 1, l, mid, POS, VAL);
            }else{
                update(2 * node + 2, mid + 1, r, POS, VAL);
            }
            tree[node] = (tree[2 * node + 1] + tree[2 * node + 2]) % MODULO;
        }
    }

    long long query(int node, int l, int r, const int& L, const int& R){
        if(r < L || R < l){
            return 0;
        }else if(L <= l && r <= R){
            return tree[node];
        }else{
            int mid = (l + r) / 2;
            return (query(2 * node + 1, l, mid, L, R) +
                    query(2 * node + 2, mid + 1, r, L, R)) % MODULO;
        }
    }

public:
    SegmentTree(const string& S, const long long& MODULO, const vector<long long>& COEF):
                N(S.length()), MODULO(MODULO), COEF(COEF){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
        for(int i = 0; i < N; ++i){
            update(0, 0, N - 1, i, S[i]);
        }
    }

    void update(const int& POS, const int& VAL){
        update(0, 0, N - 1, POS, VAL);
    }

    long long query(const int& L, const int& R){
        return query(0, 0, N - 1, L, R);
    }
};

class Solution{
public:
    void processPalindromeQueries(const string& S, vector<tuple<int, int, int>>& queries){
        const int N = S.length();
        const long long BASE = 131;
        const long long MODULO = 1e9 + 7;

        // hashing coefficients
        vector<long long> incCoef(N);
        incCoef[0] = 1;
        for(int i = 1; i < N; ++i){
            incCoef[i] = (incCoef[i - 1] * BASE) % MODULO;
        }
        vector<long long> decCoef(incCoef.rbegin(), incCoef.rend());

        // segment trees
        SegmentTree segTreeInc(S, MODULO, incCoef);
        SegmentTree segTreeDec(S, MODULO, decCoef);

        for(const tuple<int, int, int>& QUERY: queries){
            int queryType, x, y;
            tie(queryType, x, y) = QUERY;

            if(queryType == 1){
                --x;
                segTreeInc.update(x, y);
                segTreeDec.update(x, y);
            }else{
                --x;
                --y;
                long long incHash = segTreeInc.query(x, y);
                long long decHash = segTreeDec.query(x, y);
                incHash = (incHash * incCoef[N - 1 - y]) % MODULO;
                decHash = (decHash * incCoef[x]) % MODULO;
                if(incHash == decHash){
                    cout << "YES";
                }else{
                    cout << "NO";
                }
                cout << "\n";
            }
        }
    }
};

int main(){
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<tuple<int, int, int>> queries(m);
    for(int i = 0; i < m; ++i){
        int queryType;
        cin >> queryType;
        if(queryType == 1){
            int pos;
            char c;
            cin >> pos >> c;
            queries[i] = {queryType, pos, (int)c};
        }else{
            int a, b;
            cin >> a >> b;
            queries[i] = {queryType, a, b};
        }
    }

    Solution().processPalindromeQueries(s, queries);

    return 0;
}