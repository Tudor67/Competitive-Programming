class Solution {
private:
    int consumeSpaces(const string& S, int pos, const int& N){
        while(pos < N && S[pos] == ' '){
            pos += 1;
        }
        return pos;
    }
    
    int ignoreSpaces(const string& S, int pos, const int& N){
        while(pos < N && S[pos] != ' '){
            pos += 1;
        }
        return pos;
    }
    
public:
    string reverseWords(string s) {
        const int N = s.length();
        
        // Step 1: reverse words
        reverse(s.begin(), s.end());
        
        int startPos = 0;
        int endPos = 0;
        while(endPos < N){
            startPos = consumeSpaces(s, startPos, N);
            endPos = ignoreSpaces(s, startPos, N);
            reverse(s.begin() + startPos, s.begin() + endPos);
            startPos = endPos;
        }
        
        // Step 2: remove redundant spaces
        startPos = 0;
        endPos = 0;
        while(endPos < N){
            endPos = consumeSpaces(s, endPos, N);
            while(endPos < N && s[endPos] != ' '){
                s[startPos] = s[endPos];
                startPos += 1;
                endPos += 1;
            }
            if(endPos < N){
                s[startPos] = s[endPos];
                startPos += 1;
                endPos += 1;
            }
        }
        
        s.resize(startPos);
        
        while(s.back() == ' '){
            s.pop_back();
        }
        
        return s;
    }
};