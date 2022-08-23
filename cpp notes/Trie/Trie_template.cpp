class TrieNode{
public:
    bool isEnd;
    int count;
    TrieNode* next[26];  

    TrieNode() {
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
        isEnd = false;
        count = 0;
    }
};

/*
root = new TrieNode();
for (auto w: words){
    TrieNode *node = root;
    for (auto c: w){
        if (node->next[c - 'a'] == NULL)
            node->next[c - 'a'] = new TrieNode();
        node = node->next[c - 'a'];
    }
    node->isEnd = 1;
}

// check
void dfs(TrieNode* root){
    if (!root)
        return;
    for (int i = 0; i < 26; i++){
        if (root->next[i]){
            cout << char(i + 'a') << " ";
            dfs(root->next[i]);
        }
    }
    cout << endl;
}

//remove count
void remove(string &word){
    TrieNode* node = root;
    for (auto c: word){
        node = node->next[c - 'a'];
        node->count--;
    }
    node->isEnd = 0;
}

*/
