class Solution {
private:
    long long countCars(vector<int>& count, long long maxTime){
        long long totalCars = 0;
        for(int rank = 1; rank < (int)count.size(); ++rank){
            long long cars = count[rank] * 1LL * floor(sqrt(maxTime / rank));
            totalCars += cars;
        }
        return totalCars;
    }
    
public:
    long long repairCars(vector<int>& ranks, int cars) {
        const int N = ranks.size();
        const int MIN_RANK = *min_element(ranks.begin(), ranks.end());
        const int MAX_RANK = *max_element(ranks.begin(), ranks.end());

        vector<int> count(MAX_RANK + 1);
        for(int rank: ranks){
            count[rank] += 1;
        }
        
        long long l = 1;
        long long r = MIN_RANK * 1LL * cars * 1LL * cars;
        while(l != r){
            long long mid = (l + r) / 2;
            if(countCars(count, mid) >= cars){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        return r;
    }
};