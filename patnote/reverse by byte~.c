#include<stdio.h>
//��һ��int��һ�ֽ�ȡ������1234�ֽڻ���4321�ֽ�
int main(){ 
	unsigned int a,b;
	scanf("%u",&a);
	b=a&0x0ff;a>>=8;b<<=8;//��11111111��λ�벢������ 
	b|=a&0x0ff;a>>=8;b<<=8;
	b|=a&0x0ff;a>>=8;b<<=8;
	b|=a&0x0ff;
	printf("%u\n",b);
}
