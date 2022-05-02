class Solution {
private:
    int computeCost(const vector<int>& DIGITS, int startAt, int moveCost, int pushCost){
        int i = 0;
        while(i < (int)DIGITS.size() && DIGITS[i] == 0){
            i += 1;
        }
        
        int cost = 0;
        int currentDigit = startAt;
        while(i < (int)DIGITS.size()){
            if(currentDigit != DIGITS[i]){
                currentDigit = DIGITS[i];
                cost += moveCost;
            }
            cost += pushCost;
            i += 1;
        }
        
        return cost;
    }
    
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int minCost = INT_MAX;
        
        for(int a = 0; a <= 9; ++a){
            for(int b = 0; b <= 9; ++b){
                for(int c = 0; c <= 9; ++c){
                    for(int d = 0; d <= 9; ++d){
                        if((a * 10 + b) * 60 + (c * 10 + d) == targetSeconds){
                            int cost = computeCost({a, b, c, d}, startAt, moveCost, pushCost);
                            minCost = min(minCost, cost);
                        }
                    }
                }
            }
        }
        
        return minCost;
    }
};