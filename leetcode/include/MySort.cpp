#include "MySort.h"

/**
 * @brief 快排
 * 
 * @param nums int数组 
 */
void quickSort(int left, int right, vector<int> &nums)
{
    int base = nums[left];
    int i = left, j = right;
    while(i < j)
    {
        while (nums[j] >= base && (j > i))
            j--;
        while (nums[i] <= base && (i < j))
            i++;
        
        if (i < j)
        {   // 交换
            nums[i] = nums[i] ^ nums[j];
            nums[j] = nums[i] ^ nums[j];
            nums[j] = nums[i] ^ nums[j];
        }
        //基准数归位
        nums[left] = nums[i];
        nums[i] = base;
        quickSort(left, i - 1, nums);//递归左边
        quickSort(i + 1, right, nums);//递归右边


        
        
    } 
}