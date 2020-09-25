#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct term{//多项式项的结构体 
	double coef;//系数
	int expn;//指数
	struct term *next;//指向下一项的指针 
};
typedef struct term* Link;//指向下一项的指针类型定义为Link
Link init(){//无参初始化 
	Link tmp=(Link)malloc(sizeof(struct term));
	tmp->next=NULL;
	return tmp;
}
Link init2(double c,int e){//带参初始化 
	Link tmp=(Link)malloc(sizeof(struct term));
	tmp->next=NULL;
	tmp->coef=c;
	tmp->expn=e;
	return tmp;
}
void insert(Link p,struct term t){//插入 
	Link q=p;
	while(q->next&&q->next->expn>t.expn)q=q->next;//q指数比插入项大就后移，这是为了使链表按指数递减排列
	if(q->next){//q的下一个不是空结点
		if(q->next->expn==t.expn)//指数相等就系数相加
			q->next->coef+=t.coef;
		else{//不等就插中间
			Link tmp=init2(t.coef,t.expn);
			tmp->next=q->next;
			q->next=tmp;
		}
	}
	else{//q->next空说明q是队尾
		Link tmp=init2(t.coef,t.expn);
		q->next=tmp;
	}
}
void create(Link p,int len){//创建多项式 
	int i;
	struct term t;
	for(i=1;i<=len;i++){
		scanf("%lf%d",&t.coef,&t.expn);
		insert(p,t);
	}
}
void print(Link p){//输出多项式 
	Link q=p->next;
	int output=0;
	while(q){
		if(q->coef){//系数不为0才输出 
			output=1;
			if(q->expn==0)printf("%.1f",q->coef);//指数为0系数必须输出 
			else{//指数不为0则系数是+-1时不能输出1 
				if(q->coef==-1)printf("-");//系数-1只输出负号3 
				else if(q->coef!=1)printf("%.1f",q->coef);//系数不为+-1则输出 
				printf("x");
				if(q->expn!=1)printf("^%d",q->expn);//指数不为1才输出 
			}
		}
		q=q->next;
		if(q&&q->coef>0)printf("+");//若下一项系数为正，则打印'+'
	}
	if(!output)printf("0");//如果没输出过说明是0多项式，输出0 
	printf("\n\n");
}
Link add(Link p1,Link p2){//加法 
	Link q;
	for(q=p2->next;q!=NULL;q=q->next)
		insert(p1,*q);//将p2的每一项插入到p1中
	free(p2);
	return p1;
}
Link sub(Link p1,Link p2){//减法 
	Link q;
	for(q=p2->next;q!=NULL;q=q->next){
		q->coef=-(q->coef);
		insert(p1,*q);//将p2的每一项取负后插入到p1中
	}
	free(p2);
	return p1;
}
Link multiply(Link p1,Link p2){//乘法 
	Link q1,q2,L=init(),tmpp;
	struct term tmpt;
	for(q1=p1->next;q1!=NULL;q1=q1->next){
		tmpp=init();
		for(q2=p2->next;q2!=NULL;q2=q2->next){
			tmpt.coef=q1->coef*q2->coef;
			tmpt.expn=q1->expn+q2->expn;
			insert(tmpp,tmpt);
		}
		L=add(L,tmpp);//乘法实际上是加法
	}
	return L;
}
void calculate(Link p){//代入x的值计算 
	double x;
	printf("输入x的值：");
	scanf("%lf",&x);
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
	int i;
	for(i=1;i<=16;i++){//16个测试 
		printf("Test%d:\n",i);
		Link p1=init(),p2=init(),p3=init();
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

		calculate(p3);
		printf("\n\n\n");
	}
	system("pause");
}
