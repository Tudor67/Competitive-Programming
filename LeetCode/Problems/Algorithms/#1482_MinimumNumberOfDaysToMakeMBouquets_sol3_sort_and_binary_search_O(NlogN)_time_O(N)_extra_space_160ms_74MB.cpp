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
        
        vector<int> sortedCandidates = bloomDays;
        sort(sortedCandidates.begin(), sortedCandidates.end());
        sortedCandidates.resize(unique(sortedCandidates.begin(), sortedCandidates.end()) - sortedCandidates.begin());
        
        int l = 0;
        int r = (int)sortedCandidates.size() - 1;
        while(l != r){
            int mid = (l + r) / 2;
            if(countBouquets(bloomDays, k, sortedCandidates[mid]) < m){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        if(countBouquets(bloomDays, k, sortedCandidates[r]) >= m){
            return sortedCandidates[r];
        }

        return -1;
    }
};