class Solution {
public:
    string decodeAtIndex(string S, int K) {
        const int N = S.length();
        vector<long long> tapeLength(N);
        
        long long currentTapeLength = 0;
        for(int i = 0; i < N; ++i){
            if(isdigit(S[i])){
                currentTapeLength *= (S[i] - '0');
            }else{
                currentTapeLength += 1;
            }
            tapeLength[i] = currentTapeLength;
        }
        
        string answer;
        for(int i = N - 1; i >= 0; --i){
            K %= tapeLength[i];
            if(K == 0 && !isdigit(S[i])){
                answer = S[i];
                break;
            }
        }
        
        return answer;
    }
};