class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int rem = 1 % k;
        int len = 1;
        unordered_set<int> vis;

        while(rem != 0){
            vis.insert(rem);
            rem = (rem * 10 + 1) % k;
            len += 1;
            if(vis.count(rem)){
                return -1;
            }
        }

        return len;
    }
};