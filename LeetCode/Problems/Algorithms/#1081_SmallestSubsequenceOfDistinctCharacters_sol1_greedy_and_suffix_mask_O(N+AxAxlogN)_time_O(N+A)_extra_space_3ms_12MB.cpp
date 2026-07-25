class Solution {
private:
    int getFirstValidIndex(deque<int>& ids, int startIdx){
        auto it = lower_bound(ids.begin(), ids.end(), startIdx);
        if(it != ids.end()){
            return *it;
        }
        return INT_MAX;
    }

public:
    string smallestSubsequence(string s) {
        const int N = s.length();
        const int A = 26;

        vector<int> suffMask(N + 1);
        vector<deque<int>> indicesOf(A);
        for(int i = N - 1; i >= 0; --i){
            int charId = s[i] - 'a';
            suffMask[i] = (1 << charId) | suffMask[i + 1];
            indicesOf[charId].push_front(i);
        }

        const int TARGET_MASK = suffMask[0];
        const int RES_LEN = popcount((unsigned int)TARGET_MASK);

        string res(RES_LEN, '.');
        int resMask = 0;
        int sIdx = 0;

        for(int resIdx = 0; resIdx < RES_LEN; ++resIdx){
            for(char c = 'a'; c <= 'z'; ++c){
                int charId = c - 'a';
                int sNextIdx = getFirstValidIndex(indicesOf[charId], sIdx);
                if(((resMask >> charId) & 1) == 0 &&
                   ((TARGET_MASK >> charId) & 1) == 1 &&
                   (sNextIdx < N) &&
                   (resMask | suffMask[sNextIdx]) == TARGET_MASK){
                    res[resIdx] = c;
                    resMask |= (1 << charId);
                    while(!indicesOf[charId].empty() && indicesOf[charId].front() <= sNextIdx){
                        indicesOf[charId].pop_front();
                    }
                    sIdx = sNextIdx + 1;
                    break;
                }
            }
        }

        return res;
    }
};