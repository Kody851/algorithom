
# chapter1 复杂度、递归复杂度、二分、异或、选择冒泡插入
不用辅助空间实现交换

```c++
void swap_withoutSpace(vector<int>&arr, int i, int j) {
        arr[i] = arr[i] ^ arr[j];
        arr[j] = arr[i] ^ arr[j];
        arr[i] = arr[i] ^ arr[j];
    }



mid = L + ((R - L) >> 1)//不用(L+R)/2防止数据越界，位操作更快


int rightOne = eor & (~eor + 1); // 提取出最右的1
```


二分法时间复杂度 O(logn)，每次砍一半，多少次能砍成1。  
2^x=n,x=logn
时间复杂度排名：
![clipboard](AFD640E215934490A836ADBC06232026)
递归问题复杂度：
T(N)=aT(N/b)+O(N^d)
要求：子问题是等规模的

a=2,b=2,d=0
```c++
public class Code08_GetMax {

    public static int getMax(int[] arr) {
        return process(arr, 0, arr.length - 1);
    }

    // arr[L..R]范围上求最大值         N
    public static int process(int[] arr, int L, int R) {
        if (L == R) { // arr[L..R]范围上只有一个数，直接返回，base case
            return arr[L];
        }
        int mid = L + ((R - L) >> 1); // 中点
        int leftMax = process(arr, L, mid);
        int rightMax = process(arr, mid + 1, R);
        return Math.max(leftMax, rightMax);
    }
}
```



chapter2 归并、堆、快排
归并排序复杂度

小和问题、逆序对问题（笔试面试每年都出现）
归并迭代方式，p从1、2、4、8、16递增，一直到超过数组长度(共logn次)，每次相邻p个数merge，因此时间复杂度O(nlogn).
堆
要实现这两个方法，堆很适合

用数组表示完全二叉树（满的，或者从左到右依次变满的）：
堆的实现是数组，只是想象成树的样子。

大顶堆：每一个子树的最大值都是根节点的完全二叉树
每添加一个数，就与其父节点比较，若大于父节点就交换。

heapinsert添加新元素的复杂度为logn，只与n个数组成树的高度有关。
荷兰国旗问题（划分3块），理工科大浪漫：



快排1.0

2.0：分3块
3.0：时间复杂度nlogn，空间logn

chapter3 比较器、基数排序、排序总结
比较器
bool cmp1(int a, int b){
    return a<b ;
}
bool cmp2(int a,int b){
    return a>b;
}
sort(arr.begin(),arr.end(),cmp1);//asc
sort(arr.begin(),arr.end(),cmp2);//desc

基数排序，复杂度log_10^max * N，有多少个十进制位，就遍历多少次。


快排--快排的常数时间最低
堆--额外空间最少
归并--稳定

贱逼题：（拿快排怼面试官）

sort() 工程上的改进：
当输入是基础类型时，会调用快排（因为不用考虑稳定性），若样本量小（如小于60），会调用插入排序，因为常数时间低；当输入是非基础类型时，会调用归并；
chapter4 哈希


