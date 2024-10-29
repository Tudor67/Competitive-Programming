class Solution {
private:
    int encrypt(int num){
        string s = to_string(num);
        char maxChar = *max_element(s.begin(), s.end());
        fill(s.begin(), s.end(), maxChar);
        return stoi(s);
    }

public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        for(int num: nums){
            sum += encrypt(num);
        }
        return sum;
    }
};