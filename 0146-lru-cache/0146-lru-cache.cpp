class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    int capacity;
    Node* head;
    Node* tail;
    // not just for look up for also for direct access to each node of dll
    unordered_map<int, Node*> look_up;

    LRUCache(int cap) {
        capacity = cap;

        // initialize both as dummy nodes with -1 as key and val value
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        // link with each other
        head->next = tail;
        tail->prev = head;
        // now the actual nodes will be b/w both head and tail
    }

    int get(int key) {
        if (look_up.find(key) == look_up.end()) {
            return -1;
        }
        // else updaet the position of node and return the value of that node
        Node* node = look_up[key];
        removeLink(node);
        addOld_at_front(node);

        return node->val;
    }

    void put(int key, int value) {

        // 1st check whether the key is present or not already
        // if yes then update the position
        if (look_up.find(key) != look_up.end()) {
            // Key exists
            Node* oldNode = look_up[key];
            int oldVal = oldNode->val;
            oldNode->val = value;
            // 1st remove the old link properly
            removeLink(oldNode);
            // pick it and place at front of head
            addOld_at_front(oldNode);

        } else {
            // before creating newnode check the capacity
            if (look_up.size() == capacity) {
                // remove the least recenlty used cache(node, jsut before the )
                Node* lru = tail->prev;
                int lruKey = lru->key; // save the key *BEFORE* deleting the node
                removeLink(lru);       // unlink from the list
                look_up.erase(lruKey); // remove from map using saved key
                delete lru;            // now safe to free memory
            }
            // create a new Node and at at front
            Node* newNode = new Node(key, value);

            // now place it
            addNew_at_front(newNode);
            // now add the key and its node to hashmap
            look_up[key] = newNode;
        }
    }

private:
    void addNew_at_front(Node* newNode) {

        // link it just after the head
        Node* nextNode = head->next;

        newNode->next = nextNode;
        newNode->prev = head;
        head->next = newNode;
        nextNode->prev = newNode;

        // return newNode;
    }
    // for the already present one
    void addOld_at_front(Node* oldnode) {
        Node* nextNode = head->next;

        oldnode->next = nextNode;
        oldnode->prev = head;
        head->next = oldnode;
        nextNode->prev = oldnode;
    }
    // removing the old link properly
    void removeLink(Node* oldNode) {

        Node* nextNode = oldNode->next;
        Node* prevNode = oldNode->prev;

        nextNode->prev = prevNode;
        prevNode->next = nextNode;

        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */