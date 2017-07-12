#include "stdio.h"

void swap(int *a,int *b)
{                            /*序列中元素位置的交换*/
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void prin(int k[])
{
	int i;
	static int cont = 0;

	cont++;
	printf("\n num %d times\n",cont);
	for(i=0;i<10;i++)
	{
		printf("%d ",k[i]);
	}
	printf("\n");

}
void quicksort(int k[], int s,int t)
{                            /*快速排序*/
    int i,j;

    if(s<t)//划分结束条件
	{
        i = s;
        j = t+1;
        while(1)
		{
            do i++;
            while( ! (k[s]<=k[i] || i==t) );        //从第一个开始求出第一个大于基准值的元素位置i
            
			do j--;
            while(!(k[s]>=k[j] || j==s));        //从最后开始求出第一个小于基准值的元素位置j
           
			if(i<j)
			{
                swap(&k[i],&k[j]);            /*交换k[i]和k[j]的位置*/
				prin(k);
			}
            else
                break;

        }
        printf("lvfeng\n");
        swap(&k[s],&k[j]);                //将基准元素与从后往前的第一个大于s的元素进行交换，即放在中间
		quicksort(k,s,j-1);                    /*递归排序基准元素前面的子序列*/
		quicksort(k,j+1,t);                    /*递归排序基准元素后面的子序列*/
    }
}

int main()
{
    int k[10]={2,5,6,3,7,8,0,9,12,1} , i;
    printf("The data array is\n") ;
    for(i=0;i<10;i++)                        /*显示原序列之中的元素*/
        printf("%d ",k[i]);
	printf("\n");

    quicksort(k,0,9);                        /*快速排序*/
    printf("\nThe result of quick sorting for the array is\n");
    for(i=0;i<10;i++)                         /*显示排序后的结果*/
        printf("%d ",k[i]);
	printf("\n");

	return 0;
}


