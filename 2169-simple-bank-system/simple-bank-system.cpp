class Bank {
private:
    vector<long long> arr;
public:
    Bank(vector<long long>& balance) {
        arr = balance;
    }
    bool isValidAccount(int account)
    {
        return account >= 1 && account <= arr.size();
    }
    bool transfer(int account1, int account2, long long money) {
        if(!isValidAccount(account1) || !(isValidAccount(account2)))
            return false;

        if(arr[account1 - 1] < money)
            return false;
        
        arr[account1 - 1] -= money;
        arr[account2 - 1] += money;

        return true;
    }
    
    bool deposit(int account, long long money) {
        if(!isValidAccount(account))
            return false;

        arr[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!isValidAccount(account) || arr[account-1] < money)
            return false;
        
        arr[account-1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */