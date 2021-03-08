class Solution {
private:
    bool isPrefix(const string& A, const string& B){
        for(int i = 0; i < (int)min(A.length(), B.length()); ++i){
            if(A[i] != B[i]){
                return false;
            }
        }
        return (A.length() <= B.length());
    }
    
public:
    int minimumLengthEncoding(vector<string>& words) {
        for(string& word: words){
            reverse(word.begin(), word.end());
        }
        
        sort(words.begin(), words.end());
        words.push_back("#");
        
        int answer = 0;
        for(int i = 1; i < (int)words.size(); ++i){
            if(!isPrefix(words[i - 1], words[i])){
                answer += words[i - 1].length() + 1;
            }
        }
        
        return answer;
    }
};