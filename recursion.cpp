#include <stdio.h>

static int func(int n)
{
	int a = 1;

	if (n != 0) {
		a = n*func(n-1);
		return a;
	}
		
	return a;

}

int main(void)
{
	int n = 0;

	scanf("%d", &n);

	n = func(n);

	printf("%d\n", n);
}
