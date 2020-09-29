class Solution {
private:
    static bool comp(const string& LHS, const string& RHS){
        return (LHS + RHS > RHS + LHS);
    }
    
public:
    string largestNumber(vector<int>& nums) {
        const int N = nums.size();
        
        vector<string> strNums(N);
        for(int i = 0; i < N; ++i){  
            strNums[i] = to_string(nums[i]);
        }
        
        sort(strNums.begin(), strNums.end(), comp);
        
        string answer;
        for(int i = 0; i < N; ++i){
            if(answer.empty() && strNums[i] == "0" && i != N - 1){
                continue;
            }
            answer += strNums[i];
        }
        
        return answer;
    }
};