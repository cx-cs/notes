#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct term{
	double coef;//系数
	int expn;//指数
	term *next;
	term():next(NULL){};
	term(double c,int e):coef(c),expn(e),next(NULL){};
};
typedef struct term* Link;//指向结构体term的指针类型定义为Link
void insert(Link p,term t){
	Link q=p;
	while(q->next&&q->next->expn<t.expn)q=q->next;//q指数比插入项小就后移，这是为了使链表按指数递增排列
	if(q->next){//q的下一个不是空结点
		if(q->next->expn==t.expn)//q<t==q->next，相等就相加
			q->next->coef+=t.coef;
		else{//q<t<q->next，不等就插中间
			Link tmp=new term(t.coef,t.expn);
			tmp->next=q->next;
			q->next=tmp;
		}
	}
	else{//q->next空说明q是队尾
		Link tmp=new term(t.coef,t.expn);
		q->next=tmp;
	}
}
void create(Link p,int len){
	term t;
	for(int i=1;i<=len;i++){
		printf("第%d个系数和指数：",i);
		scanf("%lf%d",&t.coef,&t.expn);
		insert(p,t);
	}
}
void print(Link p){
	Link q=p->next;
	while(q){
		if(q->coef!=0)printf("%.2fx^%d",q->coef,q->expn);//系数不为0才输出
		q=q->next;
		if(q&&q->coef>0)printf("+");//若下一项系数为正，则打印'+'
	}
	printf("\n\n");
}
Link add(Link p1,Link p2){
	Link q;
	for(q=p2->next;q!=NULL;q=q->next)
		insert(p1,*q);//将p2的每一项插入到p1中
	free(p2);
	return p1;
}
Link sub(Link p1,Link p2){
	Link q;
	for(q=p2->next;q!=NULL;q=q->next){
		q->coef=-(q->coef);
		insert(p1,*q);//将p2的每一项取负后插入到p1中
	}
	free(p2);
	return p1;
}
Link multiply(Link p1,Link p2){
	Link q1=p1->next,q2=p2->next,L=new term(),tmpp;
	term tmpt;
	if(q1&&q2){//这个不可能为假因为空多项式无意义
		for(q1=p1->next;q1!=NULL;q1=q1->next){
			tmpp=new term();
			for(q2=p2->next;q2!=NULL;q2=q2->next){
				tmpt.coef=q1->coef*q2->coef;
				tmpt.expn=q1->expn+q2->expn;
				insert(tmpp,tmpt);
			}
			L=add(L,tmpp);//乘法实际上是加法
		}
	}
	return L;
}
void calculate(Link p,double x){
	Link q=p->next;
	double result=0;//求的结果 
	while(q){
		result+=pow(x,q->expn)*q->coef;
		q=q->next;
	}
	printf("结果为：%.5f\n\n",result);
}
int main()
{
	Link p1=new term(),p2=new term(),p3=new term();
	int len1,len2;

	printf("输入第一个多项式的项数：");
	scanf("%d",&len1);
	create(p1,len1);
	printf("p1=");
	print(p1);

	printf("输入第二个多项式的项数：");
	scanf("%d",&len2);
	create(p2,len2);
	printf("p2=");
	print(p2);

	printf("输入要选择的运算(+,-,*)：");
	getchar();//读掉缓冲区换行符
	switch(getchar()){
	case '+':
		printf("p1+p2=");
		p3=add(p1,p2);
		print(p3);
		break;
	case '-':
		printf("p1-p2=");
		p3=sub(p1,p2);
		print(p3);
		break;
	case '*':
		printf("p1*p2=");
		p3=multiply(p1,p2);
		print(p3);
		break;
	default:printf("输入了错误指令！");
	}

	printf("是否代入X进行求值？(Y/N): ");
	getchar();//读掉缓冲区换行符
	if(getchar()=='Y'){
		double x;
		printf("输入x的值：");
		scanf("%lf",&x);
		calculate(p3,x);
	}
	else printf("不计算或输入了错误指令");
	system("pause");
}