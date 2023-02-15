/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2022-07-25 16:45:26
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2022-07-26 10:59:45
 * @FilePath: \leetcode\648.单词替换.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=648 lang=cpp
 *
 * [648] 单词替换
 */

// @lc code=start
class Solution {
public:
    class Trie
    {
        public:
            class TrieNode
            {
                public:
                    bool value;
                    vector<TrieNode*> children;

                    TrieNode() : value{false}, children(26)  {}
            };

            TrieNode *root;

            Trie()
            {
                root = new TrieNode();
            }        
        
            void insert(string word)
            {
                TrieNode *p = root;
                for (auto ch : word)
                {
                    int i = ch - 'a';
                    if (!p->children[i])
                    {
                        p->children[i] = new TrieNode();
                    }
                    p = p->children[i];
                }
                p->value = true;
            }

            bool startiwith(string prefix)
            {
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



    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string> res; // 存放答案
        string ans; // 存放返回答案
        // 分割字符串
        vector<string> sentences;   // 用来存放分割后单词的数组
        istringstream sentence2(sentence);
        string out;
        while (sentence2 >> out)
        {
            sentences.push_back(out);
        }
        
        /* 将句子构建前缀树 */
        Trie* trie = new Trie();
        for (auto sentence : sentences)
        {
            trie->insert(sentence);
        }
        // 搜索每个单词的前缀，替换
        replaceWordsByTrie(dictionary, sentences, res, trie);
        int i;
        for (i = 0; i < res.size() - 1; i++)
        {
            if (i != res.size() - 1)
            {
                ans += res[i];
                ans += ' ';
            }
        }
        ans += res[i];
        
        return ans;
    }

    /**
     * @description: 
     *              用词根去构建前缀树，新建一个vector来存放前缀树路径中的字母
     *              让句子中的每个单词去匹配前缀树，更新vector，
     *              得到的vector就是匹配到的前缀
     *              再添加到res中
     * @param {vector<string>} &dictionary 词根
     * @param {vector<string>} &sentences string数组
     * @param {string} &res 返回值
     * @return {*}
     * @author: gou jiazhuo
     */    
    void replaceWordsByTrie(vector<string> &dictionary, vector<string> &sentences, vector<string> &res, Trie *trie)
    {
        for (int i = 0; i < sentences.size(); i++)
        {
            for (auto word : dictionary)
            {
                if (trie->startiwith(word) )
                {   // 前缀匹配成功， 替换
                    res.push_back(word);
                    break;
                }
            }
        }
        
    }


};
// @lc code=end

