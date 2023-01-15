class Solution {
private:
    bool isPossible(vector<int>& v, int k, int diff){
        const int N = v.size();
        int prevTaken = v[0];
        k -= 1;
        for(int i = 1; i < N && k > 0; ++i){
            if(v[i] - prevTaken >= diff){
                k -= 1;
                prevTaken = v[i];
            }
        }
        return (k == 0);
    }
    
public:
    int maximumTastiness(vector<int>& price, int k) {
        const int N = price.size();
        const int MIN_PRICE = *min_element(price.begin(), price.end());
        const int MAX_PRICE = *max_element(price.begin(), price.end());
        
        vector<int> sortedPrice = price;
        sort(sortedPrice.begin(), sortedPrice.end());
        
        int l = 0;
        int r = MAX_PRICE - MIN_PRICE;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isPossible(sortedPrice, k, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        return r;
    }
};