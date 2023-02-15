/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2022-10-21 19:01:45
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2022-10-21 19:22:19
 * @FilePath: \leetcode\901.股票价格跨度.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

// @lc code=start
class StockSpanner {
public:
    int index;
    stack<pair<int, int>> s;

    StockSpanner() {
        index = -1;
        pair<int, int> init(-1, INT_MAX);
        s.push(init);
    }
    
    int next(int price) {
        index++;
        while(price >= s.top().second)
        {
            s.pop();
        }
        int res = index - s.top().first;
        pair<int, int> node(index, price);
        s.push(node);
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

