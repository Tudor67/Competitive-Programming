class Solution {
private:
    void reverse(string& s, int i, int j){
        while(i < j){
            swap(s[i], s[j]);
            i += 1;
            j -= 1;
        }
    }
    
public:
    string reverseWords(string s) {
        const int N = s.length();
        
        int startPos = 0;
        while(startPos < N){
            int endPos = startPos;
            while(endPos < N && s[endPos] != ' '){
                endPos += 1;
            }
            reverse(s, startPos, endPos - 1);
            startPos = endPos + 1;
        }
        
        return s;
    }
};