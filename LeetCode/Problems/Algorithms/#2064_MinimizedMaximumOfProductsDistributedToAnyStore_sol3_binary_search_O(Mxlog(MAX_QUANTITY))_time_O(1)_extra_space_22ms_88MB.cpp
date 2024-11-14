class Solution {
private:
    int computeMinStores(vector<int>& quantities, const int QUANTITY_LIMIT){
        int minStores = 0;
        for(int q: quantities){
            minStores += (q + QUANTITY_LIMIT - 1) / QUANTITY_LIMIT;
        }
        return minStores;
    }

public:
    int minimizedMaximum(int N, vector<int>& quantities) {
        const int MAX_QUANTITY = *max_element(quantities.begin(), quantities.end());

        int l = 1;
        int r = MAX_QUANTITY;
        while(l != r){
            int mid = (l + r) / 2;
            if(computeMinStores(quantities, mid) <= N){
                r = mid;
            }else{
                l = mid + 1;
            }
        }

        return r;
    }
};