class Solution {
private:
    bool isValid(vector<int>& quantities, int n, int maxQ){
        for(int q: quantities){
            while(n >= 0 && q > 0){
                q -= maxQ;
                n -= 1;
            }
            if(n < 0){
                return false;
            }
        }
        return true;
    }
    
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        const int MAX_QUANTITY = *max_element(quantities.begin(), quantities.end());
        int l = 1;
        int r = MAX_QUANTITY;
        while(l != r){
            int mid = (l + r) / 2;
            if(isValid(quantities, n, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return r;
    }
};