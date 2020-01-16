#include<stdio.h>

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

//��������ĺ���
int split(int a[], int low, int high)
{
    int i = low;    //iָ��Ƚ�Ԫ�ص�����λ��
    int x = a[i];    //���������һ��Ԫ������Ϊ�Ƚ�Ԫ��
    //������ĵڶ���Ԫ����ʼ���������ҵ���Ԫ�ش��ڱȽ�Ԫ�أ�������
    for(int j = low+1;j<=high;j++)
        //���ҵ���С�ڱȽ�Ԫ�ص�����������ǰ��ϴ�������н���
        if (a[j] <= x)
        {
            i++;
            swap(a[i], a[j]);
        }
    swap(a[low], a[i]);    //���Ƚ�Ԫ�ؽ���������λ��
    return i;
}

//��������
void quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int i = split(a, low, high);    //�������鲢��ñȽ�Ԫ��λ��
        quicksort(a, low, i - 1);    //�ԱȽ�Ԫ����߽�������
        quicksort(a, i + 1, high);    //�ԱȽ�Ԫ���ұ߽�������
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
