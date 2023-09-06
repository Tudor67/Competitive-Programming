class Solution {
private:
    bool isValid(string& s, int i, char c){
        for(int j = max(0, i - 2); j <= i - 1; ++j){
            if(s[j] == c){
                return false;
            }
        }
        return true;
    }
    
public:
    string smallestBeautifulString(string s, int k) {
        const int N = s.length();

        for(int i = N - 1; i >= 0; --i){
            for(char c = s[i] + 1; c <= 'a' + k - 1; ++c){
                if(isValid(s, i, c)){
                    s[i] = c;
                    
                    for(int j = i + 1; j < N; ++j){
                        for(char cj = 'a'; cj <= 'a' + k - 1; ++cj){
                            if(isValid(s, j, cj)){
                                s[j] = cj;
                                break;
                            }
                        }
                    }

                    return s;
                }
            }
        }
        
        return "";
    }
};