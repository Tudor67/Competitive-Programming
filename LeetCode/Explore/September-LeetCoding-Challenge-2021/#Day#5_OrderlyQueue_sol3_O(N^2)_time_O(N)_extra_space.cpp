class Solution {
private:
    bool isLess(const string& A, const int& A_START_IDX, const int& A_END_IDX,
                const string& B, const int& B_START_IDX, const int& B_END_IDX){
        int i = A_START_IDX;
        int j = B_START_IDX;
        while(i < A_END_IDX && j < B_END_IDX){
            if(A[i] == B[j]){
                i += 1;
                j += 1;
            }else if(A[i] < B[j]){
                return true;
            }else{
                return false;
            }
        }
        return false;
    }
    
public:
    string orderlyQueue(string s, int k) {
        string smallestS;
        if(k == 1){
            const int N = s.length();
            string ss = s + s;
            smallestS = s;
            for(int i = 0; i < N; ++i){
                if(isLess(ss, i, i + N, smallestS, 0, N)){
                    copy(ss.begin() + i, ss.begin() + i + N, smallestS.begin());
                }
            }
        }else{
            const int ALPHABET_SIZE = 26;
            vector<int> count(ALPHABET_SIZE, 0);
            for(char c: s){
                count[c - 'a'] += 1;
            }
            for(char c = 'a'; c <= 'z'; ++c){
                smallestS.append(count[c - 'a'], c);
            }
        }
        return smallestS;
    }
};