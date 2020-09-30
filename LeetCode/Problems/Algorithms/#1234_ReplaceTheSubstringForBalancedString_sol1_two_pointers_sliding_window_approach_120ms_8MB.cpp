class Solution {
private:
    bool valid(map<char, int>& excessCnt, map<char, int>& cnt){
        for(const pair<char, int>& P: excessCnt){
            if(P.second > 0 && cnt[P.first] < P.second){
                return false;
            }
        }
        return true;
    }
    
public:
    int balancedString(string s) {
        const int N = s.length();
        
        map<char, int> excessCnt;
        for(char c: string("QWER")){
            excessCnt[c] = max(0, (int)count(s.begin(), s.end(), c) - (N / 4));
        }
        
        map<char, int> cnt;
        int answer;
        if(valid(excessCnt, cnt)){
            answer = 0;
        }else{
            answer = N;
            for(int i = 0, j = 0; j < N; ++j){
                cnt[s[j]] += 1;
                while(valid(excessCnt, cnt)){
                    answer = min(j - i + 1, answer);
                    cnt[s[i]] -= 1;
                    i += 1;
                }
            }
        }
        
        return answer;
    }
};