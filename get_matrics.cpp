#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
二维数组这样申请是错误的，
static unsigned char *get_matrics(int m, int n)
{
	unsigned char **ptr = (unsigned char **)malloc(m*n);
	if (ptr == NULL)
		return NULL;

	memset(ptr, '1', m*n);

	return ptr;
}
unsigned char **ptr = get_matrics(m, n);
ptr[2][2]; 错误的
*/

/*
* memset 的官方说明是 The memset() function writes len bytes of value c (converted to an unsigned char) to the string b
是以bytes为步进的，
int arr[10];memset(arr,1,10);
       由于int占4个字节(byte)，因此"1"对应的二进制(32bits下)为"00000000000000000000000000000001"(4bytes)，塞到1byte(8bit)的中，高位被舍弃了。所以，填入数组中的值是"00000001"。然而总共有10*4=40个byte，却只有10个byte被填充，因此结果是"00000001……00000001**********"(前面总共10个"00000001")。因此，第一个数是"0x01010101"=16843009(10进制)，数组其余部分的值则是随机值，读取出来会是很离谱的数！
       有人说，可以这样memset(arr,1,sizeof(arr));
       其实这样做，就是将数组的所有值都填充为"0x01010101",也就是int数组的初始值变为了16843009 !这确实有点出乎我们的预料！
*/
#if 0 
#define C_STYLE 1

int main(void)
{
	int m=3, n=4;
	int **ptr;

	//ptr = (unsigned char **)get_matrics(m, n);
#ifdef C_STYLE
	ptr = (int**)malloc(sizeof(int*)*m);

	for (int i=0; i<m; i++) {
		ptr[i] = (int*)malloc(sizeof(int)*n);
		memset(ptr[i], 6, n);
		printf("i=%d\n", i);
	}

#else

	ptr = new int*[m];

	for (int i=0; i<m; i++) {

		ptr[i] = new int[n];
		memset(ptr[i], 7, n);
	}

#endif

	ptr[2][2] = 9;

	for(int i=0; i<m; i++) 
		for(int j=0; j<n; j++) {
			printf("ptr[%d][%d]=%d\n", i, j, ptr[i][j]);
		}

	//printf("ptr[3][4] = %d\n", ptr[2][2]);

	return 0;
}
#endif

//#define C_STYLE 

int main(void)
{
	int m=3, n=4;
	unsigned char **ptr;

	//ptr = (unsigned char **)get_matrics(m, n);
#ifdef C_STYLE
	ptr = (unsigned char**)malloc(sizeof(unsigned char*)*m);

	for (int i=0; i<m; i++) {
		ptr[i] = (unsigned char*)malloc(sizeof(unsigned char)*n);
		memset(ptr[i], 6, n);
		printf("i=%d\n", i);
	}

#else

	ptr = new unsigned char*[m];

	for (int i=0; i<m; i++) {
		ptr[i] = new unsigned char[n];
		memset(ptr[i], 7, n);
	}

#endif

	ptr[2][2] = 9;

	for(int i=0; i<m; i++) 
		for(int j=0; j<n; j++) {
			printf("ptr[%d][%d]=%d\n", i, j, ptr[i][j]);
		}

	//printf("ptr[3][4] = %d\n", ptr[2][2]);

	return 0;
}