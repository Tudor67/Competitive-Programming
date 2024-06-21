class Solution {
private:
    int countBouquets(vector<int>& bloomDays, int k, int bloomDayLimit){
        int bouquets = 0;
        int consecutiveBlooms = 0;
        for(int bd: bloomDays){
            if(bd <= bloomDayLimit){
                consecutiveBlooms += 1;
            }else{
                consecutiveBlooms = 0;
            }
            if(consecutiveBlooms >= k){
                bouquets += 1;
                consecutiveBlooms = 0;
            }
        }
        return bouquets;
    }

public:
    int minDays(vector<int>& bloomDays, int m, int k) {
        const int N = bloomDays.size();
        const int MAX_BLOOM_DAY = *max_element(bloomDays.begin(), bloomDays.end());

        int l = 0;
        int r = MAX_BLOOM_DAY;
        while(l != r){
            int mid = (l + r) / 2;
            if(countBouquets(bloomDays, k, mid) < m){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        if(countBouquets(bloomDays, k, r) >= m){
            return r;
        }

        return -1;
    }
};