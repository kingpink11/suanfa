#include<stdio.h>

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

//划分数组的函数
int split(int a[], int low, int high)
{
    int i = low;    //i指向比较元素的期望位置
    int x = a[i];    //将该数组第一个元素设置为比较元素
    //从数组的第二个元素起开始遍历，若找到的元素大于比较元素，则跳过
    for(int j = low+1;j<=high;j++)
        //若找到了小于比较元素的数，则将其与前面较大的数进行交换
        if (a[j] <= x)
        {
            i++;
            swap(a[i], a[j]);
        }
    swap(a[low], a[i]);    //将比较元素交换到期望位置
    return i;
}

//快速排序
void quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int i = split(a, low, high);    //划分数组并获得比较元素位置
        quicksort(a, low, i - 1);    //对比较元素左边进行排序
        quicksort(a, i + 1, high);    //对比较元素右边进行排序
    }
}

int main()
{
    int a[] = { 5,7,1,6,4,8,3,2 };
    int length = sizeof(a) / sizeof(a[0]);
    quicksort(a, 0, length - 1);
    for (int i = 0; i < length; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
