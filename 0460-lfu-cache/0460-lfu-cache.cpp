class Node {
public:
    int key;
    int val;
    int freq;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        val = v;
        freq = 1; // bcz every new node must have 1 frequency
        prev = nullptr;
        next = nullptr;
    }
};

class LFUCache {
private:
    class DLL {
    public:
        Node* head;
        Node* tail;
        int size;

        DLL() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            size = 0;
            head->next = tail;
            tail->prev = head;
        }

        void add_at_front(Node* newNode) {

            // link it just after the head
            Node* nextNode = head->next;

            newNode->next = nextNode;
            newNode->prev = head;
            head->next = newNode;
            nextNode->prev = newNode;
        }

        void removeLink(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;

            node->prev = nullptr;
            node->next = nullptr;
        }
    };

    void update_freq(Node* oldNode) {
        // get the the node's frequency

        int oldFreq = oldNode->freq;
        oldNode->freq++;

        // remove the node from the older
        freq_check[oldFreq]->removeLink(oldNode);
        freq_check[oldFreq]->size--;
        // if the whole value at key is empty remove both key and value
        if (freq_check[oldFreq]->size == 0) {
            if (oldFreq == min_freq) { // update the min_freq
                min_freq++;
            }
            // else delete its old freq as it no longer matters
            delete freq_check[oldFreq];
            freq_check.erase(oldFreq);
        }

        if (freq_check.find(oldNode->freq) == freq_check.end()) {
            // create a new DLL
            freq_check[oldNode->freq] = new DLL();
        }
        freq_check[oldNode->freq]->add_at_front(oldNode);
        freq_check[oldNode->freq]->size++;
    }

public:
    int capacity;
    int min_freq;

    unordered_map<int, Node*> look_up;
    // for freq check and also the dll(in lfru style ) for tie breaker
    unordered_map<int, DLL*> freq_check;

    LFUCache(int capacity) {
        this->capacity = capacity;
        min_freq = 0;
    }

    int get(int key) {
        if (look_up.find(key) == look_up.end())
            return -1;

        Node* node = look_up[key];

        update_freq(node);

        return node->val;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        // if key already exists
        if (look_up.find(key) != look_up.end()) {
            // update the postion and and it in the front if head
            Node* oldNode = look_up[key];
            oldNode->val = value;
            update_freq(oldNode);

            return;
        }

        if (look_up.size() == capacity) {
            // remove the min freq node
            // but check if the key already exists or not
            // remove the lru cache
            Node* lru = freq_check[min_freq]->tail->prev;
            int lruKey = lru->key;
            freq_check[min_freq]->removeLink(lru); // unlink from the list
            freq_check[min_freq]->size--;
            look_up.erase(lruKey); // remove from map using saved key
            delete lru;

            // now if after removal the dll at that freq becomes empty
            if (freq_check[min_freq]->size == 0) {
                // delete the key from freq_chec_map
                delete freq_check[min_freq]; // deleting value of key before key
                                             // itself to prevent memory leakage
                                             // fromn the memory
                // then delete the key itself
                freq_check.erase(min_freq);
            }
        }
        // key not present
        // create a new node
        Node* newNode = new Node(key, value);
        if (freq_check.find(1) == freq_check.end()) {
            // then create a new list and add the created node at the
            freq_check[1] = new DLL();
        }
        // Always insert add the created node at the front
        freq_check[1]->add_at_front(newNode);
        freq_check[1]->size++;
        // now update the look_up map
        look_up[key] = newNode;
        min_freq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */