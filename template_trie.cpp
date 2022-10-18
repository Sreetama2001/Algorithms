// trie template 
/**
 * Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
*/
class Trieintialise{
    
public:
    bool isEnd ;
    Trieintialise *children[26];
    
    Trieintialise(){
        isEnd=false;
        for(int i=0;i<26;i++){
            children[i] =NULL;       
        }
    }  
};

class Trie{
public:
    // constructor
    Trieintialise *root;
    Trie() {
     root=new Trieintialise();      
    }
    ~Trie(){
        clear(root);
    }
    void clear(Trieintialise* root){
        for(int i=0;i<26;i++){
            if(root->children[i])   clear(root->children[i]);
        }
        delete root;
    }
    void insert(string word) {
     
       Trieintialise *node =root ; // root node 
       for(int i =0;i<word.size();i++){
         int indx = word[i] -'a'; 
         if(!node->children[indx]) node->children[indx] = new Trieintialise();
         node = node->children[indx];
       }
     node->isEnd =true;
     // cout<< "String inserted "<< endl;
     return ;   
    }
    
    bool search(string word) {
     
        
        Trieintialise *node = root;
         for(int i =0;i<word.size();i++){
         int indx = word[i] -'a'; 
         if(!node->children[indx]) return false ;
         node = node->children[indx];
       }
    return node->isEnd;
    }
    
    bool startsWith(string prefix) {
         Trieintialise *node = root;
         for(int i =0;i<prefix.size();i++){
         int indx = prefix[i] -'a'; 
         if(!node->children[indx]) return false ;
         node = node->children[indx];
       }
    return true;;   
    }
};

// Explanation
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // return True
// trie.search("app");     // return False
// trie.startsWith("app"); // return True
// trie.insert("app");
// trie.search("app");
