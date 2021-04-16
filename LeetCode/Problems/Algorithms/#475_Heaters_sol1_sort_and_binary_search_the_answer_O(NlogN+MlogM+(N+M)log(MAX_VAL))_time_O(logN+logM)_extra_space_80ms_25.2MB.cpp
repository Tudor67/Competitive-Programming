class Solution {
private:
    bool isValid(vector<int>& houses, vector<int>& heaters, const int& MAX_RADIUS){
        const int N = houses.size();
        const int M = heaters.size();
        for(int i = 0, j = 0; i < N; ++i){
            while(j < M && abs(houses[i] - heaters[j]) > MAX_RADIUS){
                j += 1;
            }
            if(j == M){
                return false;
            }
        }
        return true;
    }
    
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = 0;
        int r = max(houses.back(), heaters.back());
        while(l != r){
            int mid = (l + r) / 2;
            if(isValid(houses, heaters, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return r;
    }
};