class Solution {
public:
    char findKthBit(int n, int k) {
        char res = '0';

        int l = 1;
        for(int r = (1 << n) - 1; r > 1; r /= 2){
            int mid = (l + r) / 2;
            if(k == mid){
                res ^= 1;
                break;
            }else if(k > mid){
                res ^= 1;
                k = mid - (k - mid);
            }
        }
        
        return res;
    }
};