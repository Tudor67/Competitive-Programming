class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> a(n);
        a[0] = 1;
        
        int minVal = 2;
        int maxVal = n;
        for(int i = 1; i <= k - 1; ++i){            
            if(i % 2 == 1){
                a[i] = maxVal;
                maxVal -= 1;
            }else{
                a[i] = minVal;
                minVal += 1;
            }
        }
        
        if(k % 2 == 1){
            iota(a.begin() + k, a.end(), minVal);
        }else{
            iota(a.rbegin(), a.rbegin() + n - k, minVal);            
        }
        
        return a;
    }
};