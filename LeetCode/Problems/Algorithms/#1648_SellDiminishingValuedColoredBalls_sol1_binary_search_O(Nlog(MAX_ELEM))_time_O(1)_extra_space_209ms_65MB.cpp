class Solution {
private:
    long long countEqualOrGreater(vector<int>& v, const int& MIN_PRICE){
        long long count = 0;
        for(long long elem: v){
            if(MIN_PRICE <= elem){
                count += (elem - MIN_PRICE + 1);
            }
        }
        return count;
    }
    
public:
    int maxProfit(vector<int>& inventory, int orders) {
        const int N = inventory.size();
        const int MAX_ELEM = *max_element(inventory.begin(), inventory.end());
        const int MODULO = 1e9 + 7;
        
        // binary search min price `x` you can afford when you will maximize your profit
        // so, you will sell all `orders` groups of balls with size >= `x`
        int l = 1;
        int r = MAX_ELEM;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(countEqualOrGreater(inventory, mid) >= orders){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        long long minPrice = r;
        long long totalProfit = 0;
        long long totalCount = 0;
        for(long long elem: inventory){
            if(minPrice <= elem){
                // k: the number of elements in range [minPrice .. elem]
                long long k = elem - minPrice + 1;
                // sum: the sum of elements in range [minPrice .. elem]
                long long sum = minPrice * k + (k - 1) * k / 2;
                totalProfit += sum;
                totalCount += k;
            }
        }
        
        return (totalProfit - (totalCount - orders) * minPrice) % MODULO;
    }
};