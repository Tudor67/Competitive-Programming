class Solution {
private:
    map<char, char> first_after  = {{'a', 'b'}, {'b', 'a'}, {'c', 'a'}};
    map<char, char> second_after = {{'a', 'c'}, {'b', 'c'}, {'c', 'b'}};
public:
    string getHappyString(int n, int k) {
        string answer;
        if(k <= 3 * (1 << (n - 1))){
            // Step 1: get the first letter
            int total = 3 * (1 << (n - 1));
            char first_letter;
            if(total / 3 >= k){
                first_letter = 'a';
            }else if(2 * total / 3 >= k){
                first_letter = 'b';
            }else{
                first_letter = 'c';
            }
            
            answer.push_back(first_letter);
            k -= (first_letter - 'a') * (total / 3);
            total /= 3;
            
            // Step 2: get the remaining letters
            while(total > 1){
                if(k <= total / 2){
                    answer.push_back(first_after[answer.back()]);
                }else{
                    answer.push_back(second_after[answer.back()]);
                    k -= total / 2;
                }
                total /= 2;
            }
        }
        return answer;
    }
};