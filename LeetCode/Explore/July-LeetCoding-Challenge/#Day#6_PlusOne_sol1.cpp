class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> answer = digits;
        int carry = 1;
        for(int i = (int)digits.size() - 1; i >= 0; --i){
            int s = carry + digits[i];
            answer[i] = s % 10;
            carry = s / 10;
        }
        if(carry > 0){
            answer.insert(answer.begin(), carry);
        }
        return answer;
    }
};