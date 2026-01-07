class Solution {
private:
    void extractDivisors(int num, vector<int>& divisors){
        divisors.clear();
        for(int i = 1; i * i <= num; ++i){
            if(num % i == 0){
                divisors.push_back(i);
                if(num / i != i){
                    divisors.push_back(num / i);
                }
            }
        }
    }

public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        vector<int> divisors;
        for(int num: nums){
            extractDivisors(num, divisors);
            if((int)divisors.size() == 4){
                sum += accumulate(divisors.begin(), divisors.end(), 0);
            }
        }
        return sum;
    }
};