class LRUCache {
public:
    list<int>l;
    unordered_map<int,pair<list<int>::iterator,int>>mp;
    int maxsize;
    LRUCache(int capacity) {
        maxsize=capacity;
    }
    void move_to_front(int key)
    {
        l.erase(mp[key].first);
        l.push_front(key);
        mp[key].first = l.begin();
    }
    int get(int key) {
        if(mp.find(key) == mp.end())
        {
            return -1;
        }
        move_to_front(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
        {
            mp[key].second = value;
            move_to_front(key);
        }
        else
        {
            
            l.push_front(key);
            mp[key] = {l.begin(),value};
            if(l.size() > maxsize )
            {
                 mp.erase(l.back());
                l.pop_back();
            }
        
        }
    }
};
