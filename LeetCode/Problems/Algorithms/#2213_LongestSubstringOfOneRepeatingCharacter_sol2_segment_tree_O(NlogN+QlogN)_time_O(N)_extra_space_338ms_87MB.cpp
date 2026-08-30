class SegmentTree{
private:
    const int N;
    vector<int> lLen;
    vector<int> rLen;
    vector<int> maxLen;
    vector<char> lChar;
    vector<char> rChar;

    void update(int node, int l, int r, const int POS, const char VAL){
        if(l == r){
            lLen[node] = 1;
            rLen[node] = 1;
            maxLen[node] = 1;
            lChar[node] = VAL;
            rChar[node] = VAL;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                update(2 * node + 1, l, mid, POS, VAL);
            }else{
                update(2 * node + 2, mid + 1, r, POS, VAL);
            }

            int leftSize = mid - l + 1;
            int rightSize = r - mid;
            
            if(rChar[2 * node + 1] == lChar[2 * node + 2] && lLen[2 * node + 1] == leftSize){
                lLen[node] = leftSize + lLen[2 * node + 2];
            }else{
                lLen[node] = lLen[2 * node + 1];
            }

            if(rChar[2 * node + 1] == lChar[2 * node + 2] && rLen[2 * node + 2] == rightSize){
                rLen[node] = rLen[2 * node + 1] + rightSize;
            }else{
                rLen[node] = rLen[2 * node + 2];
            }

            maxLen[node] = max(maxLen[2 * node + 1], maxLen[2 * node + 2]);
            if(rChar[2 * node + 1] == lChar[2 * node + 2]){
                maxLen[node] = max(maxLen[node], rLen[2 * node + 1] + lLen[2 * node + 2]);
            }

            lChar[node] = lChar[2 * node + 1];
            rChar[node] = rChar[2 * node + 2];
        }
    }

public:
    SegmentTree(const string& S): N(S.length()){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }

        lLen.assign(2 * minLeaves, 0);
        rLen.assign(2 * minLeaves, 0);
        maxLen.assign(2 * minLeaves, 0);
        lChar.assign(2 * minLeaves, 0);
        rChar.assign(2 * minLeaves, 0);

        for(int i = 0; i < N; ++i){
            update(i, S[i]);
        }
    }

    void update(const int POS, const char VAL){
        update(0, 0, N - 1, POS, VAL);
    }

    int getMaxLen() const{
        return maxLen[0];
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        const int N = s.length();
        const int Q = queryCharacters.length();

        SegmentTree tree(s);
        vector<int> res(Q);
        for(int qIdx = 0; qIdx < Q; ++qIdx){
            int i = queryIndices[qIdx];
            char newChar = queryCharacters[qIdx];
            tree.update(i, newChar);
            res[qIdx] = tree.getMaxLen();
        }

        return res;
    }
};