class Solution {
public:
    string decodeAtIndex(string S, int K) {
        const int N = S.length();
        vector<long long> a(N);
        
        long long tapeLength = 0;
        for(int i = 0; i < N; ++i){
            if(isdigit(S[i])){
                long long coef = 1;
                int j;
                for(j = i; j < S.length() && isdigit(S[j]); ++j){
                    coef *= (S[j] - '0');
                }
                tapeLength *= coef;
                a[i] = tapeLength;
                i = j - 1;
            }else{
                tapeLength += 1;
                a[i] = tapeLength;
            }
        }
        
        while(!a.empty() && a.back() == 0){
            a.pop_back();
        }
        
        for(int i = 1; i < N; ++i){
            if(a[i] == 0){
                a[i] = 1 + a[i - 1];
            }
        }
        
        string answer;
        while(answer.empty()){
            int pos = lower_bound(a.begin(), a.end(), K) - a.begin();
            if(K == a[pos] || (pos >= 1 && K % a[pos - 1] == 0)){
                while(pos > 0 && isdigit(S[pos])){
                    pos -= 1;
                }
                answer = S[pos];
            }else{
                K %= a[pos - 1];
            }
        }
        
        return answer;
    }
};