
/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
public:
    class TrieNode
    {
        public:
            bool val;   // 因为只用确定有没有，所以用布尔
            vector<TrieNode *>  children;

            // 有类成员对象的时候，要用这个类的构造函数初始化, vector是个类
            TrieNode() : children(26), val(false) { }

    };

    TrieNode *root; // 前缀树根节点


    Trie() {
        root = new TrieNode();  // 初始化根节点
    }
    
    /**
     * @description: 
     * @param {string} word
     * @return {*}
     * @author: gou jiazhuo
     */    
    void insert(string word) {
        TrieNode *p = root;
        for (auto ch : word)
        {
            int i = ch - 'a';   // 换成int
            if (!p->children[i])
            {   // 说明孩子有，但是每开空间，那么就开
                p->children[i] = new TrieNode();
            }
            // 继续往孩子走
            p = p->children[i];
        }
        // 最后p指向最后一个字母，这条路上的单词组成的字符串存在，末尾设为true
        p->val = true;

    }
    
    /**
     * @description: 判断在前缀树中是否找到这个单词 
     * @param {string} word
     * @return {bool}
     * @author: gou jiazhuo
     */    
    bool search(string word) {
        TrieNode *p = root;
        for (auto ch : word)
        {
            int i = ch - 'a';
            if (!p->children[i])
            {   // 说明没找到，直接返回false
                return false;
            }
            p = p->children[i];
        }
        return p->val;
    }
    
    /**
     * @description: 
     * @param {string} prefix
     * @return {*}
     * @author: gou jiazhuo
     */    
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (auto ch : prefix)
        {
            int i = ch - 'a';
            if (!p->children[i])
            {
                return false;
            }
            p = p->children[i];
        }
        return true;
    }   
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

