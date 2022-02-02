class Solution {
public:
    
    struct Node {
        char val;
        bool endLetter;
        map<char, struct Node*> next;
        
        Node(char c) {
            val = c;
            endLetter = false;
        }
    };
    
    void addWord(string word, struct Node *root) {
        int i, n;
        char letter;
        
        for(i=0, n=word.size(); i<n; i++) {
            letter = word[i];
            if(root->next[letter] == NULL) {
                struct Node *node = new Node(' ');
                root->next[letter] = node;
            }
            root = root->next[letter];
            if( i == n-1) {
                root->endLetter = true;
            }
        }
    }
    
    vector<string> getSuggestions(string key, bool runKey, struct Node *root, vector<string> &words, string word) {        
        if( words.size() == 3 ) {
                return words;
        } 
        
        if( runKey ) {
            for(char letter: key) {
                if(root->next[letter]){
                    root = root->next[letter];
                }
                else {
                    return words;
                }
            }
        }
        
        if(root and root->endLetter == true) {
            words.push_back(key+word);
        }       
        
        for(auto val: root->next) {
            if(val.second) {
                getSuggestions(key, false, root->next[val.first], words, word+val.first);
                if( words.size() == 3 ) {
                    return words;
                }
            }
        }
        
        return words;
    }
    
    void printTrie(struct Node *root, string word) {
        if(root and root->endLetter == true) {
            cout << word << '\n';
        }
        
        for(auto val: root->next) {
            if(val.second) {
                printTrie(root->next[val.first], word+val.first);
            }
        }
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& dictonary, string searchWord) {
        vector<vector<string>> ans;
        vector<string> suggestions;
        string word;
        struct Node *root = new Node(' ');
        int i, n;
        
        for(i=0, n=dictonary.size(); i<n; i++) {
            addWord(dictonary[i], root);
        }
        
        word = "";

        for(char letter: searchWord) {
            word += letter;

            getSuggestions(word, true, root, suggestions, "");
            
            ans.push_back(suggestions);
            
            suggestions.clear();
        }
        
        return ans;
    }
};
