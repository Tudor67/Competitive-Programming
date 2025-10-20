class Solution {
private:
    const int ALPHABET_SIZE = 26;
    const char FIRST_CHAR = 'a';

    bool areAnagrams(const string& A, const string& B){
        if(A.length() != B.length()){
            return false;
        }

        vector<int> balance(ALPHABET_SIZE);
        for(int i = 0; i < (int)A.length(); ++i){
            balance[A[i] - FIRST_CHAR] += 1;
            balance[B[i] - FIRST_CHAR] -= 1;
        }

        for(int b: balance){
            if(b != 0){
                return false;
            }
        }
        
        return true;
    }

public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        for(string& word: words){
            if(res.empty() || !areAnagrams(res.back(), word)){
                res.push_back(word);
            }
        }
        return res;
    }
};