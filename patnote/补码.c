#include<stdio.h>
int main(){
	int a=-1;//补码32个1赋给a，有一个符号位 
	printf("%d\n%u\n",a,a);
	a=4294967295;//32个1，补码就是本身输出了-1 
	printf("%d\n%u\n",a,a);
	a=4294967296;//32个1+1，补码本身，截断剩下0 
	printf("%d\n%u\n",a,a);
	a=2147483647;//31个1，补码本身 
	printf("%d\n%u\n",a,a);
	a=2147483648;//31个1+1，补码本身100000，这是最大负数 
	printf("%d\n%u\n",a,a);
} 
