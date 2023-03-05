class Solution {
private:
    bool isPowOf2(int num){
        return (num & (num - 1)) == 0;
    }
    
public:
    int minImpossibleOR(vector<int>& nums) {
        const int N = nums.size();

        unordered_set<int> powsOf2;
        for(int num: nums){
            if(isPowOf2(num)){
                powsOf2.insert(num);
            }
        }

        int p = 1;
        while(powsOf2.count(p)){
            p *= 2;
        }

        return p;
    }
};