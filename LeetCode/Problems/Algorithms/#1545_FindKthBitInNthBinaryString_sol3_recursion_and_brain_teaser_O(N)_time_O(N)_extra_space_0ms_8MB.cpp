class Solution {
private:
    int f(int l, int r, int k){
        int mid = (l + r) / 2;
        if(l == r){
            return 0;
        }
        if(k == mid){
            return 1;
        }
        if(k < mid){
            return f(l, mid - 1, k);
        }
        return 1 ^ f(l, mid - 1, mid - (k - mid));
    }

public:
    char findKthBit(int n, int k) {
        return char('0' + f(1, (1 << n) - 1, k));
    }
};