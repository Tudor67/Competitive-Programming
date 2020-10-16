class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int maxSaved = 0;
        int saved = 0;
        for(int i = 0, j = 0; j < customers.size(); ++j){
            saved += (customers[j] * grumpy[j]);
            if(j - i + 1 > X){
                saved -= (customers[i] * grumpy[i]);
                i += 1;
            }
            maxSaved = max(saved, maxSaved);
        }
        
        int answer = maxSaved;
        for(int i = 0; i < customers.size(); ++i){
            answer += (customers[i] * !grumpy[i]);
        }
        
        return answer;
    }
};