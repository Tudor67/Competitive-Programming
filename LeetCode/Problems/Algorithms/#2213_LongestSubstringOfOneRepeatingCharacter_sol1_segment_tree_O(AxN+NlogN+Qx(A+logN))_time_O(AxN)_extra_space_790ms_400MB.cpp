class SegmentTree{
private:
    const int N;
    vector<int> lOnes;
    vector<int> rOnes;
    vector<int> maxOnes;

    void update(int node, int l, int r, const int POS, const int VAL){
        if(l == r){
            lOnes[node] = VAL;
            rOnes[node] = VAL;
            maxOnes[node] = VAL;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                update(2 * node + 1, l, mid, POS, VAL);
            }else{
                update(2 * node + 2, mid + 1, r, POS, VAL);
            }

            int leftSize = mid - l + 1;
            int rightSize = r - mid;
            
            if(lOnes[2 * node + 1] == leftSize){
                lOnes[node] = leftSize + lOnes[2 * node + 2];
            }else{
                lOnes[node] = lOnes[2 * node + 1];
            }

            if(rOnes[2 * node + 2] == rightSize){
                rOnes[node] = rOnes[2 * node + 1] + rightSize;
            }else{
                rOnes[node] = rOnes[2 * node + 2];
            }

            maxOnes[node] = max({maxOnes[2 * node + 1],
                                 maxOnes[2 * node + 2],
                                 rOnes[2 * node + 1] + lOnes[2 * node + 2]});
        }
    }

public:
    SegmentTree(const int N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        lOnes.assign(2 * minLeaves, 0);
        rOnes.assign(2 * minLeaves, 0);
        maxOnes.assign(2 * minLeaves, 0);
    }

    void update(const int POS, const int VAL){
        update(0, 0, N - 1, POS, VAL);
    }

    int getMaxOnes() const{
        return maxOnes[0];
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        const int N = s.length();
        const int Q = queryCharacters.length();
        const int A = 26;

        vector<SegmentTree> trees(A, {N});
        for(int i = 0; i < N; ++i){
            trees[s[i] - 'a'].update(i, 1);
        }

        vector<int> res(Q);
        for(int qIdx = 0; qIdx < Q; ++qIdx){
            int i = queryIndices[qIdx];
            int oldChar = s[i];
            int newChar = queryCharacters[qIdx];

            s[i] = newChar;
            trees[oldChar - 'a'].update(i, 0);
            trees[newChar - 'a'].update(i, 1);

            for(char c = 'a'; c <= 'z'; ++c){
                res[qIdx] = max(res[qIdx], trees[c - 'a'].getMaxOnes());
            }
        }

        return res;
    }
};