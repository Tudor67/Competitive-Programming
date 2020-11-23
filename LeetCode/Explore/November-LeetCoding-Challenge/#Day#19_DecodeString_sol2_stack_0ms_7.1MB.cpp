class Solution {
private:
    int nextInt(const string& S, const int& POS){
        int nextInt = 0;
        for(int i = POS; i < S.length() && isdigit(S[i]); ++i){
            nextInt = 10 * nextInt + (S[i] - '0');
        }
        return nextInt;
    }
    
    int nextPosIgnoringDigits(const string& S, const int& POS){
        int nextPos = POS + 1;
        while(nextPos < S.length() && isdigit(S[nextPos])){
            nextPos += 1;
        }
        return nextPos;
    }
    
    string repeat(const string& S, const int& N){
        string s;
        for(int i = 1; i <= N; ++i){
            s += S;
        }
        return s;
    }
    
public:
    string decodeString(string s) {
        stack<string> stringSt;
        stack<int> intSt;
        int k = 0;
        int pos = 0;
        while(pos < s.length()){
            if(isdigit(s[pos])){
                k = nextInt(s, pos);
                pos = nextPosIgnoringDigits(s, pos);
                intSt.push(k);
            }else if(s[pos] == '['){
                stringSt.push("");
                pos += 1;
            }else if(s[pos] == ']'){
                string sk = repeat(stringSt.top(), intSt.top());
                stringSt.pop();
                if(!stringSt.empty()){
                    sk = stringSt.top() + sk;
                    stringSt.pop();
                }
                stringSt.push(sk);
                intSt.pop();
                pos += 1;
            }else{
                if(stringSt.empty()){
                    stringSt.push("");
                }
                stringSt.top().push_back(s[pos]);
                pos += 1;
            }
        }
        return stringSt.top();
    }
};