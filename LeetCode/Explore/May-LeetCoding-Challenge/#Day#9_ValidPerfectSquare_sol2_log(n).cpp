class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1;
        int r = num;
        
        while(l != r){
            int mid = l + (r - l) / 2;
            if(mid < num / mid)
                l = mid + 1;
            else
                r = mid;
        }
        
        return (r <= num / r && r * r == num);
    }
};