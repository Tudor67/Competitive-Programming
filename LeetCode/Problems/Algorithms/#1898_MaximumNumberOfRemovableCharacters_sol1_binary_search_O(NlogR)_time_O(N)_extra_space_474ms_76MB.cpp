class Solution {
private:
    bool isSubsequence(const string& P, const string& S, const vector<bool>& isRemoved){
        const int N = S.length();
        int pIdx = 0;
        for(int i = 0; i < N; ++i){
            if(isRemoved[i]){
                continue;
            }
            if(S[i] == P[pIdx]){
                pIdx += 1;
            }
            if(pIdx == (int)P.length()){
                return true;
            }
        }
        return false;
    }
    
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        const int N = s.length();
        const int R = removable.size();
        vector<bool> isRemoved(N, false);
        int l = 0;
        int r = R + 1;
        while(l != r){
            int mid = (l + r) / 2;
            for(int i = 0; i < mid; ++i){
                isRemoved[removable[i]] = true;
            }
            if(isSubsequence(p, s, isRemoved)){
                l = mid + 1;
            }else{
                r = mid;
            }
            for(int i = 0; i < mid; ++i){
                isRemoved[removable[i]] = false;
            }
        }
        return r - 1;
    }
};