class LRUCache {
public:
    list<int> dll;
    map<int, pair<list<int>::iterator, int>> cahche;
    int capacity;

    LRUCache(int capacity) {
        this -> capacity = capacity;    
    }
    
    void recentlyUsed(int key){
        dll.erase(cahche[key].first);
        dll.push_front(key);
        cahche[key].first = dll.begin();
    }
    int get(int key) {
        if(!cahche.count(key)) return -1;

        recentlyUsed(key);
        return cahche[key].second;
    }
    
    void put(int key, int value) {
        if(cahche.count(key)){
            cahche[key].second = value;
            recentlyUsed(key);
        }
        else{
            dll.push_front(key);
            cahche[key] = {dll.begin(), value};
            capacity--;
        }

        if(capacity<0){
            cahche.erase(dll.back());
            dll.pop_back();
            capacity++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */