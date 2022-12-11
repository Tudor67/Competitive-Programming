class Solution {
public:
    int bestClosingTime(string customers) {
        const int N = customers.length();
        
        int penalty = count(customers.begin(), customers.end(), 'Y');
        int minPenalty = penalty;
        int minTime = 0;
        for(int i = 0; i <= N; ++i){
            if(penalty < minPenalty){
                minPenalty = penalty;
                minTime = i;
            }
            if(i < N){
                if(customers[i] == 'Y'){
                    penalty -= 1;
                }else{
                    penalty += 1;
                }
            }
        }
        
        return minTime;
    }
};