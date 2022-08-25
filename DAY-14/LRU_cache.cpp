/* While inserting the {key,val} pair into the DDL we need to make sure that we are inserting it from the back tail to the head.
// The cache will tell us when the {key, value} pair is used/inserted.

// So, while inserting the {key,val}pair, we need to:
➡ Check if the {key,val} pair is already present in Cache or not.
➡ Check for the capacity, if the (Cache size == capacity) then while inserting the new pair we need to remove the LRU and insert the new pair right after the head & while removing the node we need to make sure that we remove the {value, node} pair from the cache.
➡Finally check, If the key is not present in the Cache then return -1; */

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

// using double linked list O(1)
class LRUCache {
public:
    class Node {
        public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int _key,int _val)
        {
            key = _key;
            val = _val;
            prev = NULL;
            next = NULL;
        } 
    };
    unordered_map<int,Node* > mp;
    Node* head=new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail ->prev = head;
    }
    void addnode(Node* temp)
    {
        Node* nextptr = head->next;
        temp->next = nextptr;
        nextptr->prev = temp;
        head->next = temp;
        temp->prev =  head;
    }
    void deletenode(Node* temp)
    {
       Node* nextptr = temp->next;
        Node* prevptr = temp->prev;
        nextptr->prev = prevptr;
        prevptr->next = nextptr;
    }
    int get(int key) {
        if(mp.find(key) == mp.end())
        {
            return -1;
        }
        Node* x = mp[key];
        deletenode(x);
        addnode(x);
        mp[key] = head->next;
        return x->val;
    }
    
    void put(int key, int value) {
       
        if(mp.find(key) != mp.end())
        {
             deletenode(mp[key]);
            mp.erase(key);
           
        }
         Node* temp =new Node(key,value);
        addnode(temp);
        if(mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
         
        }
        mp[key] = head->next;
    }
};
