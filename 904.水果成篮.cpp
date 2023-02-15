/*
 * @Author: jiazhuoGou goujz@qq.com
 * @Date: 2022-10-18 15:22:59
 * @LastEditors: jiazhuoGou goujz@qq.com
 * @LastEditTime: 2022-10-18 15:37:04
 * @FilePath: \leetcode\904.水果成篮.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       // 找一个只含两种元素的最长子序列
        int res = 0, temp = 0, flag = 0;
        
        for (int i = 0; i < fruits.size(); i++)
        {
            flag = 0;
            temp = 0;
            vector<int> collections;
            collections.push_back(fruits[i]);
            temp++;
            for (int j = i + 1; j < fruits.size() && flag == 0; j++)
            {
                switch(collections.size())
                {
                    case 1:
                        if (fruits[j] == collections[0])
                        {
                            temp++;
                            //cout << " case 1   " << "i: " << i << " " << "j: " << j  << " " << "temp: " << temp <<  endl;
                        }
                        else 
                        { // meet a new one
                            collections.push_back(fruits[j]);
                            temp++;
                            //cout << " case 1   "  << "i: " << i << " " << "j: " << j << " " << "temp: " << temp <<  endl;
                        };
                        break;
                    case 2:
                        if (fruits[j] == collections[0] || fruits[j] == collections[1])
                        {
                            temp++;
                            //cout << " case 2   "  << "i: " << i << " " << "j: " << j << " " << "temp: " << temp <<  endl;
                        }
                        else 
                        {
                            flag = 1;
                            break;
                        };
                        break;
                    default:cout << "error" << endl;break;
                }
            }
            if (res < temp)
                {
                    res = temp;
                }
                if (res == fruits.size() || res == fruits.size() -1)
                {
                    return res;
                }
        }
        cout << temp << endl;
        return res; 
    }
};
// @lc code=end

