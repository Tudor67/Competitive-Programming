class Solution {
private:
    const int A = 26;
    const int FIRST_CHAR = 'a';

    void countChars(const string& S, vector<int>& count){
        fill(count.begin(), count.end(), 0);        
        for(char c: S){
            count[c - FIRST_CHAR] += 1;
        }
    }

    bool isGood(vector<int>& currCount, vector<int>& maxCount){
        for(int i = 0; i < A; ++i){
            if(currCount[i] > maxCount[i]){
                return false;
            }
        }
        return true;
    }

public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> maxCount(A);
        countChars(chars, maxCount);

        int res = 0;
        vector<int> currCount(A);
        for(const string& WORD: words){
            countChars(WORD, currCount);
            if(isGood(currCount, maxCount)){
                res += WORD.length();
            }
        }

        return res;
    }
};