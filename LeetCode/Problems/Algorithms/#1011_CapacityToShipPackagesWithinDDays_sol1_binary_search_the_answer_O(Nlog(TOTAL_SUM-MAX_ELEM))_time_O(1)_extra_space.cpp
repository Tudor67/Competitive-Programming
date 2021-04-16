class Solution {
private:
    int minDays(vector<int>& weights, const int& CAPACITY){
        int days = 1;
        int weightSum = 0;
        for(int weight: weights){
            weightSum += weight;
            if(weightSum > CAPACITY){
                days += 1;
                weightSum = weight;
            }
        }
        return days;
    }
    
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        while(l != r){
            int mid = (l + r) / 2;
            if(minDays(weights, mid) <= D){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return r;
    }
};