class Solution {
private:
    void back(int startIdx, const string& NUM_STR, const int& TARGET_SUM,
              string expression, long long sum, long long prevTerm, vector<string>& expressions){
        if(startIdx == (int)NUM_STR.length()){
            if(sum == TARGET_SUM){
                expressions.push_back(expression);
            }
        }else{
            long long num = 0;
            for(int i = startIdx; i < (int)NUM_STR.length(); ++i){
                if(NUM_STR[startIdx] == '0' && i > startIdx){
                    return;
                }
                num = 10 * num + (NUM_STR[i] - '0');
                if(expression.empty()){
                    back(i + 1, NUM_STR, TARGET_SUM, to_string(num), num, num, expressions);
                }else{
                    back(i + 1, NUM_STR, TARGET_SUM, expression + "+" + to_string(num), sum + num, num, expressions);
                    back(i + 1, NUM_STR, TARGET_SUM, expression + "-" + to_string(num), sum - num, -num, expressions);
                    back(i + 1, NUM_STR, TARGET_SUM, expression + "*" + to_string(num), sum + prevTerm * num - prevTerm, prevTerm * num, expressions);
                }
            }
        }
    }
    
public:
    vector<string> addOperators(string numStr, int target) {
        vector<string> expressions;
        back(0, numStr, target, "", 0, 0, expressions);
        return expressions;
    }
};