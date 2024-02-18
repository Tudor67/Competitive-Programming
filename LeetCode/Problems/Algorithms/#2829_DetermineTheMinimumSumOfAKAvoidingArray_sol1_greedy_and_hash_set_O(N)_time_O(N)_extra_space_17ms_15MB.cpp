class Solution {
public:
    int minimumSum(int n, int k) {
        int sum = 0;
        int num = 1;
        unordered_set<int> numsSet;
        
        while((int)numsSet.size() < n){
            if(!numsSet.count(k - num)){
                numsSet.insert(num);
                sum += num;
            }
            num += 1;
        }

        return sum;
    }
};