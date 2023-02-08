class Solution {
public:
    double trimMean(vector<int>& arr) {
        const int N = arr.size();

        vector<int> v = arr;
        int extraElements = N / 20;
        nth_element(v.begin(), v.end() - extraElements, v.end());
        nth_element(v.begin(), v.begin() + extraElements, v.end() - extraElements);
        
        double sum = 0;
        for(int i = extraElements; i < N - extraElements; ++i){
            sum += v[i];
        }

        return sum / (N - 2 * extraElements);
    }
};