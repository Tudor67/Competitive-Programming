class Solution {
private:
    int getMaxValidIndex(const string& S, const string& T){
        const int N = S.length();
        const int INF = 1e9;
        int j = 1;
        for(int i = N - 1; i >= 0; --i){
            if(S[i] == T[j]){
                j -= 1;
            }
            if(j == -1){
                return i;
            }
        }
        return -INF;
    }
    
public:
    int minimumOperations(string s) {
        const int N = s.length();

        // Case 1: delete all digits => N operations
        int res = N;

        // Case 2: if s contains at least one zero => make s equal to zero => (N - 1) operations
        if(find(s.begin(), s.end(), '0') != s.end()){
            res = min(res, N - 1);
        }
        
        // Case 3: s will be divisible by 25 only if the last digits will be "00" or "25" or "50" or "75"
        //         find the max valid index i such that s[i .. N - 1] contains subsequence "00" or "25" or
        //                                                                                 "50" or "75"
        //         we need (N - 2 - i) operations to make a valid/target suffix "00", "25", "50" or "75"
        vector<int> validIndices;
        validIndices.push_back(getMaxValidIndex(s, "00"));
        validIndices.push_back(getMaxValidIndex(s, "25"));
        validIndices.push_back(getMaxValidIndex(s, "50"));
        validIndices.push_back(getMaxValidIndex(s, "75"));
        
        int maxValidIndex = *max_element(validIndices.begin(), validIndices.end());

        res = min(res, N - 2 - maxValidIndex);

        return res;
    }
};