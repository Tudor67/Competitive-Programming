class Solution {    
public:
    int maxProduct(vector<int>& nums) {
        int answer = nums[0];
        
        int maxNegProd = 0;
        int prod = 1;
        for(int i = 0; i < (int)nums.size(); ++i){
            prod *= nums[i];

            if(prod >= 0){
                answer = max(prod, answer);
            }else if(maxNegProd < 0){
                answer = max(prod / maxNegProd, answer);
            }
            
            if(prod < 0){
                if(maxNegProd == 0 || maxNegProd < prod){
                    maxNegProd = prod;
                }
            }
            
            if(prod == 0){
                maxNegProd = 0;
                prod = 1;
            }
        }
        
        return answer;
    }
};