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
    
    int getMultCoef(vector<int>& countA, vector<int>& countB){
        // return multCoef = min(countA[i] / countB[i], countA[j] / countB[j], ...),
        //                   for all indices i, j, ... with countB[index] != 0
        int multCoef = INT_MAX;
        for(int i = 0; i < (int)countA.size(); ++i){
            if(countB[i] != 0){
                multCoef = min(countA[i] / countB[i], multCoef);
            }
        }
        return multCoef;
    }
    
    void erase(vector<int>& countA, const int& MULT_COEF, vector<int>& countB){
        // countA[i] -= MULT_COEF * countB[i] for all i
        for(int i = 0; i < (int)countA.size(); ++i){
            countA[i] -= MULT_COEF * countB[i];
        }
    }
    
public:
    string originalDigits(string s) {
        const vector<string> NUM2STR = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        
        vector<int> answerCount(10, 0);
        vector<int> sCount = getCharCount(s);
        for(int digit: {0, 2, 6, 8, 7, 3, 4, 5, 1, 9}){
            vector<int> dCount = getCharCount(NUM2STR[digit]);
            int multCoef = getMultCoef(sCount, dCount);
            if(contains(sCount, dCount)){
                erase(sCount, multCoef, dCount);
                answerCount[digit] = multCoef;
            }
        }
        
        string answer;
        for(int digit = 0; digit <= 9; ++digit){
            answer += string(answerCount[digit], char(digit + '0'));
        }
        
        return answer;
    }
};