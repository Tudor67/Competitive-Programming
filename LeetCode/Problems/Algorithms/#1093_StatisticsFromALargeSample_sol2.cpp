class Solution {
private:
    int kthElement(const vector<int>& COUNT, const int& K){
        int cnt = 0;
        for(int i = 0; i < COUNT.size(); ++i){
            cnt += COUNT[i];
            if(cnt >= K){
                return i;
            }
        }
        return -1;
    }
    
public:
    vector<double> sampleStats(vector<int>& count) {
        const int N = accumulate(count.begin(), count.end(), 0);
        vector<long long> elements(count.size());
        iota(elements.begin(), elements.end(), 0);
        double minimum = kthElement(count, 1);
        double maximum = kthElement(count, N);
        double sum = inner_product(elements.begin(), elements.end(), count.begin(), 0LL);
        double mean = sum / N;
        double median = (kthElement(count, N / 2) + kthElement(count, (N / 2) + ((N + 1) % 2))) / 2.0;
        double mode = max_element(count.begin(), count.end()) - count.begin();
        return {minimum, maximum, mean, median, mode};
    }
};