class Solution {
private:
    long long countRepairedCars(vector<int>& ranks, long long maxMinutes){
        long long repairedCars = 0;
        for(int rank: ranks){
            repairedCars += sqrt(maxMinutes / rank);
        }
        return repairedCars;
    }

public:
    long long repairCars(vector<int>& ranks, int cars) {
        const long long N = ranks.size();
        const long long MIN_RANK = *min_element(ranks.begin(), ranks.end());

        long long l = 0;
        long long r = MIN_RANK * cars * cars;
        while(l != r){
            long long mid = (l + r) / 2;
            if(countRepairedCars(ranks, mid) < cars){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        return r;
    }
};