class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int MODULO = 1e9 + 7;
        const int MAX_ELEM = *max_element(arr.begin(), arr.end());
        
        vector<long long> count(MAX_ELEM + 1, 0);
        for(int elem: arr){
            count[elem] += 1;
        }
        
        long long answer = 0;
        for(int x = 0; x <= MAX_ELEM; ++x){
            for(int y = x; y <= MAX_ELEM; ++y){
                int z = target - (x + y);
                if(y <= z && z <= MAX_ELEM && count[x] && count[y] && count[z]){
                    if(x == y && y == z){
                        answer += count[x] * (count[x] - 1) * (count[x] - 2) / 6;
                    }else if(x == y && y != z){
                        answer += count[z] * count[x] * (count[x] - 1) / 2;
                    }else if(x != y && y == z){
                        answer += count[x] * count[y] * (count[y] - 1) / 2;
                    }else if(x != y && y != z){
                        answer += count[x] * count[y] * count[z];
                    }
                    answer %= MODULO;
                }
            }
        }
        
        return (int)answer;
    }
};