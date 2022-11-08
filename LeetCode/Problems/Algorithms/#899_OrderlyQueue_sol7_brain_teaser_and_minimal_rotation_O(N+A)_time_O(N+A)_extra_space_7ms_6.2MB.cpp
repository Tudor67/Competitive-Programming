class Solution {
public:
    string orderlyQueue(string s, int k) {
        const int N = s.length();
        const int A = 26;
        const int FIRST_CHAR = 'a';
        
        string res;
        if(k == 1){
            // Case 1: k == 1 (find minimal rotation)
            string ss = s + s;
            int resStartPos = 0;
            int j = 1;
            while(j < 2 * N){
                int len = 1;
                while(j + len - 1 < 2 * N && ss[resStartPos + len - 1] == ss[j + len - 1]){
                    len += 1;
                }
                if(j + len - 1 < 2 * N && ss[resStartPos + len - 1] > ss[j + len - 1]){
                    resStartPos = j % N;
                }
                j += len;
            }
            res = ss.substr(resStartPos, N);
        }else{
            // Case 2: k >= 2 (sort the initial string)
            vector<int> count(A);
            for(char c: s){
                count[c - FIRST_CHAR] += 1;
            }
            
            res.reserve(N);
            for(char c = FIRST_CHAR; c < FIRST_CHAR + A; ++c){
                res.append(count[c - FIRST_CHAR], c);
            }
        }
        
        return res;
    }
};