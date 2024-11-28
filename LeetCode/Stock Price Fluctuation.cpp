// https://leetcode.com/problems/stock-price-fluctuation/description/

class StockPrice {
public:
    map<int, int> mp;
    multiset<int> mst;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        auto it = mp.find(timestamp);
        if(it != mp.end()){
            mst.erase(mst.find(it->second));
            mp.erase(it);
        }
        // add it and calculate on the new price
        mp[timestamp] = price;
        mst.insert(price);
    }
    
    int current() {
        return mp.rbegin()->second;     
    }
    
    int maximum() {
        return *mst.rbegin();
    }
    
    int minimum() {
        return *mst.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
