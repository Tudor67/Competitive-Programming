class Solution {
private:
    int computeMaxVariance(string& s, char a, char b){
        int maxVariance = 0;
        int balance = 0;
        int minBalance = 0;
        int minBalanceBeforeLastA = 0;
        bool visitedA = false;
        bool visitedB = false;

        for(char c: s){
            if(c == a){
                minBalanceBeforeLastA = minBalance;
                balance -= 1;
                visitedA = true;
            }else if(c == b){
                balance += 1;
                visitedB = true;
            }

            if(visitedA && visitedB){
                maxVariance = max(maxVariance, balance - minBalanceBeforeLastA);
            }

            minBalance = min(minBalance, balance);
        }

        return maxVariance;
    }

public:
    int largestVariance(string s) {
        const int N = s.length();

        int maxVariance = 0;
        for(char a = 'a'; a <= 'z'; ++a){
            for(char b = 'a'; b <= 'z'; ++b){
                if(a != b){
                    maxVariance = max(maxVariance, computeMaxVariance(s, a, b));
                }
            }
        }

        return maxVariance;
    }
};