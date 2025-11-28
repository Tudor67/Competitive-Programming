class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int rem = 1 % k;
        unordered_set<int> vis = {rem};

        while(rem != 0){
            rem = (rem * 10 + 1) % k;
            if(vis.count(rem)){
                return -1;
            }
            vis.insert(rem);
        }

        return vis.size();
    }
};