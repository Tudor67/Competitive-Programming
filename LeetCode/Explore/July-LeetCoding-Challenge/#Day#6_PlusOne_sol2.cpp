class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> answer(digits.rbegin(), digits.rend());
        int carry = 1;
        for(int i = 0; i < digits.size(); ++i){
            int s = carry + answer[i];
            answer[i] = s % 10;
            carry = s / 10;
        }
        if(carry > 0){
            answer.push_back(carry);
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};