class Solution {
private:
    vector<int> getCharCount(const string& S){
        vector<int> count(26, 0);
        for(char c: S){
            count[c - 'a'] += 1;
        }
        return count;
    }
    
    bool contains(vector<int>& countA, vector<int>& countB){
        // return true if countA contains countB
        for(int i = 0; i < (int)countA.size(); ++i){
            if(countA[i] < countB[i]){
                return false;
            }
        }
        return true;
    }
    
    void erase(vector<int>& countA, vector<int>& countB){
        // countA[i] -= countB[i] for all i
        for(int i = 0; i < (int)countA.size(); ++i){
            countA[i] -= countB[i];
        }
    }
    
public:
    string originalDigits(string s) {
        const vector<string> NUM2STR = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        
        vector<int> answerCount(10, 0);
        vector<int> sCount = getCharCount(s);
        for(int digit: {0, 2, 6, 8, 7, 3, 4, 5, 1, 9}){
            vector<int> dCount = getCharCount(NUM2STR[digit]);
            while(contains(sCount, dCount)){
                erase(sCount, dCount);
                answerCount[digit] += 1;
            }
        }
        
        string answer;
        for(int digit = 0; digit <= 9; ++digit){
            answer += string(answerCount[digit], char(digit + '0'));
        }
        
        return answer;
    }
};