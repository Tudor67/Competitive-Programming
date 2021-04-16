class Solution {
private:
    bool isValid(vector<int>& positions, const int& MIN_DIST, int m){
        int prevPos = -MIN_DIST;
        for(int pos: positions){
            if(pos - prevPos >= MIN_DIST){
                prevPos = pos;
                m -= 1;
            }
        }
        return (m <= 0);
    }
    
public:
    int maxDistance(vector<int>& positions, int m) {
        sort(positions.begin(), positions.end());
        int l = 1;
        int r = (positions.back() - positions.front()) / (m - 1);
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isValid(positions, mid, m)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return r;
    }
};