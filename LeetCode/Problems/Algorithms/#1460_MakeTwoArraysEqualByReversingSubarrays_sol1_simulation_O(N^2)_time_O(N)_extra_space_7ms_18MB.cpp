class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        const int N = arr.size();

        vector<int> newArr = arr;
        for(int i = 0; i < N; ++i){
            int j = find(newArr.begin() + i, newArr.end(), target[i]) - newArr.begin();
            if(j < N){
                reverse(newArr.begin() + i, newArr.begin() + j + 1);
            }else{
                return false;
            }
        }

        return true;
    }
};