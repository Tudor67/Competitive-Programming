class Solution {
public:
    double trimMean(vector<int>& arr) {
        const int N = arr.size();
        const int MAX_ELEM = *max_element(arr.begin(), arr.end());

        vector<int> count(MAX_ELEM + 1);
        for(int elem: arr){
            count[elem] += 1;
        }

        int extraElems = N / 20;
        int index = 0;
        double sum = 0;
        for(int elem = 0; elem <= MAX_ELEM; ++elem){
            while(count[elem] > 0){
                if(extraElems <= index && index <= N - extraElems - 1){
                    sum += elem;
                }
                count[elem] -= 1;
                index += 1;
            }
        }
        
        return sum / (N - 2 * extraElems);
    }
};