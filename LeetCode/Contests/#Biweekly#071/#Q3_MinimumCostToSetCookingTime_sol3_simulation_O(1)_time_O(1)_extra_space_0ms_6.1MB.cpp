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
        
        for(int mm = (targetSeconds / 60) - 1; mm <= (targetSeconds / 60); ++mm){
            int ss = targetSeconds - (mm * 60);
            if(0 <= mm && mm <= 99 && 0 <= ss && ss <= 99){
                int a = mm / 10;
                int b = mm % 10;
                int c = ss / 10;
                int d = ss % 10;
                int cost = computeCost({a, b, c, d}, startAt, moveCost, pushCost);
                minCost = min(minCost, cost);
            }
        }
        
        return minCost;
    }
};