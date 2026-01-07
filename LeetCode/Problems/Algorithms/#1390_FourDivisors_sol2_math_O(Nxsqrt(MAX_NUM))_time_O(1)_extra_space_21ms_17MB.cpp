class Solution {
private:
    pair<int, int> countAndSumOfDivisors(int num){
        int count = 0;
        int sum = 0;
        for(int i = 1; i * i <= num; ++i){
            if(num % i == 0){
                count += 1;
                sum += i;
                if(num / i != i){
                    count += 1;
                    sum += num / i;
                }
            }
        }
        return {count, sum};
    }

public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(int num: nums){
            auto [divsCount, divsSum] = countAndSumOfDivisors(num);
            if(divsCount == 4){
                sum += divsSum;
            }
        }
        return sum;
    }
};