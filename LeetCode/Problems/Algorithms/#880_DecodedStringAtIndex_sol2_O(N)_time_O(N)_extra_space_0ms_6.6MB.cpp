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
        while(answer.empty()){
            int pos = lower_bound(tapeLength.begin(), tapeLength.end(), K) - tapeLength.begin();
            if(K == tapeLength[pos] || (pos >= 1 && K % tapeLength[pos - 1] == 0)){
                while(pos > 0 && isdigit(S[pos])){
                    pos -= 1;
                }
                answer = S[pos];
            }else{
                K %= tapeLength[pos - 1];
            }
        }
        
        return answer;
    }
};