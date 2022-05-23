class ATM {
private:
    const vector<long long> BANKNOTES_VALUES = {20, 50, 100, 200, 500};
    vector<long long> banknotesCount;
    
public:
    ATM() {
        banknotesCount.assign(BANKNOTES_VALUES.size(), 0);
    }
    
    void deposit(vector<int> depositBanknotesCount) {
        for(int i = 0; i < (int)banknotesCount.size(); ++i){
            banknotesCount[i] += depositBanknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> take(banknotesCount.size());
        for(int i = (int)take.size() - 1; i >= 0; --i){
            take[i] = min(banknotesCount[i], amount / BANKNOTES_VALUES[i]);
            amount -= take[i] * BANKNOTES_VALUES[i];
        }
        if(amount == 0){
            for(int i = (int)take.size() - 1; i >= 0; --i){
                banknotesCount[i] -= take[i];
            }
            return take;
        }
        return {-1};
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */