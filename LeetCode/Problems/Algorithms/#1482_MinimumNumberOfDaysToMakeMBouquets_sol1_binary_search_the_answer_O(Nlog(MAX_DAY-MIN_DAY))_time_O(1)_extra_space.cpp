class Solution {
private:
    int countBouquets(vector<int>& bloomDays, const int& MAX_DAY, const int& BOUQUET_SIZE){
        int bouquets = 0;
        int bouquetSize = 0;
        for(int bloomDay: bloomDays){
            if(bloomDay <= MAX_DAY){
                bouquetSize += 1;
            }else{
                bouquetSize = 0;
            }
            if(bouquetSize == BOUQUET_SIZE){
                bouquets += 1;
                bouquetSize = 0;
            }
        }
        return bouquets;
    }
    
public:
    int minDays(vector<int>& bloomDays, int m, int k) {
        int l = *min_element(bloomDays.begin(), bloomDays.end());
        int r = *max_element(bloomDays.begin(), bloomDays.end());
        while(l != r){
            int mid = (l + r) / 2;
            if(countBouquets(bloomDays, mid, k) >= m){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        int answer = -1;
        if(countBouquets(bloomDays, r, k) >= m){
            answer = r;
        }
        
        return answer;
    }
};