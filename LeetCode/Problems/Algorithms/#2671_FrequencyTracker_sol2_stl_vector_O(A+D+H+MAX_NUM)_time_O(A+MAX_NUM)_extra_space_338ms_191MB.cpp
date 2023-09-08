class FrequencyTracker {
private:
    vector<int> f;
    vector<int> ff;

    void updateVectorSizes(int number){
        f.resize(max(number + 1, (int)f.size()));
        ff.resize(max(f[number] + 2, (int)ff.size()));
    }

public:
    FrequencyTracker() {
        f.resize(8);
        ff.resize(8);
    }
    
    void add(int number) {
        updateVectorSizes(number);
        ff[f[number]] -= 1;
        f[number] += 1;
        ff[f[number]] += 1;
    }
    
    void deleteOne(int number) {
        if(number < (int)f.size() && f[number] > 0){
            updateVectorSizes(number);
            ff[f[number]] -= 1;
            f[number] -= 1;
            ff[f[number]] += 1;
        }
    }
    
    bool hasFrequency(int frequency) {
        return (frequency < (int)ff.size() && ff[frequency] > 0);
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */