class Solution {
private:
    long long countRepairedCars(vector<int>& freq, long long maxMinutes){
        long long repairedCars = 0;
        for(int rank = 1; rank < (int)freq.size(); ++rank){
            long long carsPerMechanic = sqrt(maxMinutes / rank);
            repairedCars += freq[rank] * carsPerMechanic;
        }
        return repairedCars;
    }

public:
    long long repairCars(vector<int>& ranks, int cars) {
        const long long N = ranks.size();
        const long long MIN_RANK = *min_element(ranks.begin(), ranks.end());
        const long long MAX_RANK = *max_element(ranks.begin(), ranks.end());

        vector<int> freq(MAX_RANK + 1);
        for(int rank: ranks){
            freq[rank] += 1;
        }

        long long l = 0;
        long long r = MIN_RANK * cars * cars;
        while(l != r){
            long long mid = (l + r) / 2;
            if(countRepairedCars(freq, mid) < cars){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        return r;
    }
};