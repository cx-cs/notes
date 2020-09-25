#include<stdio.h>
//把一个int按一字节取反，即1234字节换成4321字节
int main(){ 
	unsigned int a,b;
	scanf("%u",&a);
	b=a&0x0ff;a>>=8;b<<=8;//和11111111按位与并左右移 
	b|=a&0x0ff;a>>=8;b<<=8;
	b|=a&0x0ff;a>>=8;b<<=8;
	b|=a&0x0ff;
	printf("%u\n",b);
}
