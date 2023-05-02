class Solution {
private:
    long long countCars(vector<int>& ranks, long long maxTime){
        long long totalCars = 0;
        for(long long rank: ranks){
            long long cars = floor(sqrt(maxTime / rank));
            totalCars += cars;
        }
        return totalCars;
    }
    
public:
    long long repairCars(vector<int>& ranks, int cars) {
        const int N = ranks.size();
        const int MIN_RANK = *min_element(ranks.begin(), ranks.end());
        
        long long l = 1;
        long long r = MIN_RANK * 1LL * cars * 1LL * cars;
        while(l != r){
            long long mid = (l + r) / 2;
            if(countCars(ranks, mid) >= cars){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        return r;
    }
};