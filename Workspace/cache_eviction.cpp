// bt.cpp
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <unordered_map>


using namespace std;

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) < (Y)) ? (Y) : (X))


class LRUCache {
    struct Node {
        Node* nxt;
        Node* prv;
        int key;
        int val;
        Node(int k, int v) {
            key = k;
            val = v;
            nxt = prv = NULL;
        }
    };
    int maxCapacity;
    //create head entry for the double linked list
    Node* head;
    //create tail entry for the double linked list
    Node* tail;

    unordered_map<int, Node*> hash;
public:
    LRUCache(int capacity) {
        head = new Node(0, 0);
        tail = new Node(capacity, capacity);
        head->nxt = tail;
        tail->prv = head;
        maxCapacity = capacity;
    }

    int get(int key) {
        if (hash.find(key) != hash.end()) {
            //found key entry
            //move the key,val pair to the head of the linked list

            insert(hash[key]);
            return hash[key]->val;
        }
        else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (hash.find(key) != hash.end()) {
            //key entry already exist
            //update the value
            hash[key]->val = value;
        }
        else {
            //create a new entry
            if (hash.size() >= maxCapacity) {
                remove(tail->prv);
            }
            hash[key] = new Node(key, value);
        }
        //move the key,val pair to the head of the linked list
        insert(hash[key]);

        return;
    }

    void insert(Node* node) {
        //move to the top of the head
        //old entry, remove the node out from its place safely
        if (node->nxt) {
            node->nxt->prv = node->prv;
        }
        if (node->prv) {
            node->prv->nxt = node->nxt;
        }
        //insert the node after head
        node->nxt = head->nxt;
        node->prv = head;
        if (head->nxt) {
            head->nxt->prv = node;
        }
        head->nxt = node;

    }
    void remove(Node *node) {
        //remove the node out from its place safely
        hash.erase(node->key);
        node->nxt->prv = node->prv;
        node->prv->nxt = node->nxt;
        delete node;
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */



void cache_eviction_lru() {
    LRUCache *lRUCache = new LRUCache(2);
    
    lRUCache->put(1, 1); // cache is {1=1}
    lRUCache->put(2, 2); // cache is {1=1, 2=2}
    lRUCache->get(1);    // return 1
    lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache->get(2);    // returns -1 (not found)
    lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache->get(1);    // return -1 (not found)
    lRUCache->get(3);    // return 3
    lRUCache->get(4);    // return 4
	return;
}

class LFUCache {
    struct Node {
        Node* nxt;
        Node* prv;
        int key;
        int val;
        int freq;
        Node(int k, int v) {
            key = k;
            val = v;
            freq = 1;
            nxt = prv = NULL;
        }
    };
    int maxCapacity;
    unordered_map<int, Node*> hash;
    unordered_map<int, list<Node*>> hashFreqList;
    unordered_map<int, int> hashFreq;
    int minFreq;
public:
    LFUCache(int capacity) {
        maxCapacity = capacity;
        minFreq = INT_MAX;
    }

    int get(int key) {
        if (hash.find(key) != hash.end()) {
            //found key entry
            //move the key,val pair to the head of the linked list

            insert(hash[key]);
            return hash[key]->val;
        }
        else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (hash.find(key) != hash.end()) {
            //key entry already exist
            //update the value
            hash[key]->val = value;
        }
        else {
            //create a new entry
            if (hash.size() >= maxCapacity) {
                remove();
            }
            hash[key] = new Node(key, value);
        }
        //move the key,val pair to the head of the linked list
        insert(hash[key]);

        return;
    }

    void insert(Node* node) {        
        //find the node
        list<Node*>::iterator it;
        it=find(hashFreqList[node->freq].begin(), hashFreqList[node->freq].end(),node);
        if (it!= hashFreqList[node->freq].end()) {
            //found the node
            //delete it from the old freq index
            hashFreqList[node->freq].remove(node);
            node->freq++;
        }
        //increment frequency and add the node to the new freq index
        hashFreqList[node->freq].push_front(node);
        //update freqhash
        hashFreq[node->freq]++;

        int i = 1;
        while (hashFreq[i] != 0) { i++; }
        minFreq = i;
    }
    void remove() {
        //evict the least frequently used node, last node is the oldest node
        Node* oldNode = hashFreqList[minFreq].back();
        hashFreqList[minFreq].pop_back();
        hash.erase(oldNode->key);
        //if the minFreq list is empty find the next available min Freq
        //???
        delete(oldNode);
    }
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LRUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */



void cache_eviction_lfu() {
    LFUCache *lfu = new LFUCache(2);
    lfu->put(1, 1);   // cache=[1,_], cnt(1)=1
    lfu->put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
    lfu->get(1);      // return 1
                     // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu->put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                     // cache=[3,1], cnt(3)=1, cnt(1)=2
    lfu->get(2);      // return -1 (not found)
    lfu->get(3);      // return 3
                     // cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu->put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                     // cache=[4,3], cnt(4)=1, cnt(3)=2
    lfu->get(1);      // return -1 (not found)
    lfu->get(3);      // return 3
                     // cache=[3,4], cnt(4)=1, cnt(3)=3
    lfu->get(4);      // return 4
                     // cache=[4,3], cnt(4)=2, cnt(3)=3
    return;
}


void cache_eviction() {
    cache_eviction_lfu();
    return;
    cache_eviction_lru();

    return;
}