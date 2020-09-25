#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct term{//����ʽ��Ľṹ�� 
	double coef;//ϵ��
	int expn;//ָ��
	struct term *next;//ָ����һ���ָ�� 
};
typedef struct term* Link;//ָ����һ���ָ�����Ͷ���ΪLink
Link init(){//�޲γ�ʼ�� 
	Link tmp=(Link)malloc(sizeof(struct term));
	tmp->next=NULL;
	return tmp;
}
Link init2(double c,int e){//���γ�ʼ�� 
	Link tmp=(Link)malloc(sizeof(struct term));
	tmp->next=NULL;
	tmp->coef=c;
	tmp->expn=e;
	return tmp;
}
void insert(Link p,struct term t){//���� 
	Link q=p;
	while(q->next&&q->next->expn>t.expn)q=q->next;//qָ���Ȳ������ͺ��ƣ�����Ϊ��ʹ����ָ���ݼ�����
	if(q->next){//q����һ�����ǿս��
		if(q->next->expn==t.expn)//ָ����Ⱦ�ϵ�����
			q->next->coef+=t.coef;
		else{//���ȾͲ��м�
			Link tmp=init2(t.coef,t.expn);
			tmp->next=q->next;
			q->next=tmp;
		}
	}
	else{//q->next��˵��q�Ƕ�β
		Link tmp=init2(t.coef,t.expn);
		q->next=tmp;
	}
}
void create(Link p,int len){//��������ʽ 
	int i;
	struct term t;
	for(i=1;i<=len;i++){
		scanf("%lf%d",&t.coef,&t.expn);
		insert(p,t);
	}
}
void print(Link p){//�������ʽ 
	Link q=p->next;
	int output=0;
	while(q){
		if(q->coef){//ϵ����Ϊ0����� 
			output=1;
			if(q->expn==0)printf("%.1f",q->coef);//ָ��Ϊ0ϵ��������� 
			else{//ָ����Ϊ0��ϵ����+-1ʱ�������1 
				if(q->coef==-1)printf("-");//ϵ��-1ֻ�������3 
				else if(q->coef!=1)printf("%.1f",q->coef);//ϵ����Ϊ+-1����� 
				printf("x");
				if(q->expn!=1)printf("^%d",q->expn);//ָ����Ϊ1����� 
			}
		}
		q=q->next;
		if(q&&q->coef>0)printf("+");//����һ��ϵ��Ϊ�������ӡ'+'
	}
	if(!output)printf("0");//���û�����˵����0����ʽ�����0 
	printf("\n\n");
}
Link add(Link p1,Link p2){//�ӷ� 
	Link q;
	for(q=p2->next;q!=NULL;q=q->next)
		insert(p1,*q);//��p2��ÿһ����뵽p1��
	free(p2);
	return p1;
}
Link sub(Link p1,Link p2){//���� 
	Link q;
	for(q=p2->next;q!=NULL;q=q->next){
		q->coef=-(q->coef);
		insert(p1,*q);//��p2��ÿһ��ȡ������뵽p1��
	}
	free(p2);
	return p1;
}
Link multiply(Link p1,Link p2){//�˷� 
	Link q1,q2,L=init(),tmpp;
	struct term tmpt;
	for(q1=p1->next;q1!=NULL;q1=q1->next){
		tmpp=init();
		for(q2=p2->next;q2!=NULL;q2=q2->next){
			tmpt.coef=q1->coef*q2->coef;
			tmpt.expn=q1->expn+q2->expn;
			insert(tmpp,tmpt);
		}
		L=add(L,tmpp);//�˷�ʵ�����Ǽӷ�
	}
	return L;
}
void calculate(Link p){//����x��ֵ���� 
	double x;
	printf("����x��ֵ��");
	scanf("%lf",&x);
	Link q=p->next;
	double result=0;//��Ľ��
	while(q){
		result+=pow(x,q->expn)*q->coef;
		q=q->next;
	}
	printf("���Ϊ��%.5f\n\n",result);
}
int main()
{
	int i;
	for(i=1;i<=16;i++){//16������ 
		printf("Test%d:\n",i);
		Link p1=init(),p2=init(),p3=init();
		int len1,len2;

		printf("�����һ������ʽ��������");
		scanf("%d",&len1);
		create(p1,len1);
		printf("p1=");
		print(p1);

		printf("����ڶ�������ʽ��������");
		scanf("%d",&len2);
		create(p2,len2);
		printf("p2=");
		print(p2);

		printf("����Ҫѡ�������(+,-,*)��");
		getchar();//�������������з�
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
		default:printf("�����˴���ָ�");
		}

		calculate(p3);
		printf("\n\n\n");
	}
	system("pause");
}
