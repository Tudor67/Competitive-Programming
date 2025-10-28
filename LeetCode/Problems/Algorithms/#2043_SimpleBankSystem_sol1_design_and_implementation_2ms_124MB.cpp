class Bank {
private:
    vector<long long> balance;

    bool isValid(int accountID){
        return (0 <= accountID && accountID < (int)balance.size());
    }

public:
    Bank(vector<long long>& balance) {
        this->balance = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        account1 -= 1;
        account2 -= 1;
        if(isValid(account1) && isValid(account2) && balance[account1] >= money){
            balance[account1] -= money;
            balance[account2] += money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        account -= 1;
        if(isValid(account)){
            balance[account] += money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        account -= 1;
        if(isValid(account) && balance[account] >= money){
            balance[account] -= money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */