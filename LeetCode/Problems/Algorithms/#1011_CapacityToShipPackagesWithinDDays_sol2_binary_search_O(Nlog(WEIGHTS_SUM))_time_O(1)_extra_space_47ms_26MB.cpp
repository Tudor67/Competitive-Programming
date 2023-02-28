class Solution {
private:
    bool isPossible(vector<int>& weights, int maxDays, int maxCapacity){
        int weightsSum = 0;
        int days = 1;

        for(int weight: weights){
            if(weightsSum + weight > maxCapacity){
                days += 1;
                weightsSum = weight;
            }else{
                weightsSum += weight;
            }

            if(days > maxDays){
                return false;
            }
        }

        return true;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        const int N = weights.size();
        const int MAX_WEIGHT = *max_element(weights.begin(), weights.end());
        const int WEIGHTS_SUM = accumulate(weights.begin(), weights.end(), 0);

        int l = MAX_WEIGHT;
        int r = WEIGHTS_SUM;
        while(l != r){
            int mid = (l + r) / 2;
            if(isPossible(weights, days, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }

        return r;
    }
};