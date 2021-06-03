class Solution {
private:
    int max_divisor_up_to_sqrt(const int& NUM){
        int divisor = NUM;
        for(int i = 2; i * i <= NUM; ++i){
            if(NUM % i == 0){
                divisor = i;
            }
        }
        return divisor;
    }
    
public:
    vector<int> closestDivisors(int num) {
        int num1_div1 = max_divisor_up_to_sqrt(num + 1);
        int num1_div2 = (num + 1) / num1_div1;
        int num2_div1 = max_divisor_up_to_sqrt(num + 2);
        int num2_div2 = (num + 2) / num2_div1;
        
        vector<int> answer;
        if(abs(num1_div1 - num1_div2) < abs(num2_div1 - num2_div2)){
            answer = {num1_div1, num1_div2};
        }else{
            answer = {num2_div1, num2_div2};
        }
        
        return answer;
    }
};