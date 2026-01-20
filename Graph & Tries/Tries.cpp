#include<bits/stdc++.h>
using namespace std;

class Node{
    Node * links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node * node) {
        links[ch - 'a'] = node;
    }

    Node * get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }

};


int main() {
    // Example usage of Trie can be added here
    return 0;
}