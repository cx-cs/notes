#include<stdio.h>
#include<stdlib.h>
typedef struct student{//ѧ����¼���� 
    int grade,id;//�ɼ���ѧ�� 
}stu;
typedef struct node{//�����������Ľڵ�����
    stu data;
    struct node *left;
    struct node *right;
}binode,*BiTree;
BiTree init(){//�޲γ�ʼ�� 
	BiTree tmp=(BiTree)malloc(sizeof(stu));
	tmp->left=NULL;
	tmp->right=NULL;
	return tmp;
}
BiTree init2(int g,int i){//���γ�ʼ�� 
	BiTree tmp=(BiTree)malloc(sizeof(stu));
	tmp->left=NULL;
	tmp->right=NULL;
	tmp->data.grade=g;
	tmp->data.id=i;
	return tmp;
}
BiTree insert(BiTree T,stu s){//���ɼ����� 
    if(T==NULL){
        T=init2(s.grade,s.id);
        return T;
    }
    if(s.grade<T->data.grade)T->left=insert(T->left,s);//С������� 
    else if(s.grade==T->data.grade){//���ɼ���� 
    	if(s.id==T->data.id)return;// ѧ��һ��˵����ѧ���Ѵ��ڲ��ٲ��� 
    	else T->left=insert(T->left,s);//�������� 
    }
    else T->right=insert(T->right,s);//������Ҳ� 
    return T;
}
void inordersave(BiTree T,FILE* fout){//�������������bst.txt 
    if(T==NULL)return;
    inordersave(T->left,fout);
    fprintf(fout,"%d %d ",T->data.id,T->data.grade);
    inordersave(T->right,fout);
}
void inorder(BiTree T){//������� 
    if(T==NULL)return;
    inorder(T->left);
    printf("ѧ�ţ�%d  �ɼ���%d\n",T->data.id,T->data.grade);
    inorder(T->right);
}
int depth(BiTree T){//��� 
    if(T==NULL)return 0;
    int left=depth(T->left); 
    int right=depth(T->right);
    return left>right?left+1:right+1;//��ȵ�������������Ƚϴ��Ǹ���1 
}
int count_nodes(BiTree T){//������ 
	if(T==NULL)return 0;
    return 1+count_nodes(T->left)+count_nodes(T->right);//���������1+������������� 
}
 
int count_leaves(BiTree T){//��Ҷ���� 
    if(T==0)return 0;
    else if(T->left==NULL&&T->right==NULL)return 1;//��Ҷ�ӷ���1 
    else return count_leaves(T->left)+count_leaves(T->right);//����Ҷ�ӷ�����������Ҷ���� 
}
BiTree Delete(BiTree T,stu s){//ɾ����� 
    BiTree p;
    if(T==NULL)return NULL;
    if(T->data.grade>s.grade||(T->data.grade==s.grade&&T->data.id!=s.id))T->left=Delete(T->left,s);
    else if(T->data.grade<s.grade)T->right=Delete(T->right,s);//���ҵ��ýڵ� 
    else{
        if(T->left==NULL&&T->right==NULL){//�ý��ΪҶ��ֱ��ɾ�� 
            free(T);
            T=NULL;
        }
        else if(T->left){//�ý���������� 
            for(p=T->left;p->right;p=p->right);
            T->data=p->data; //������������ҵĽڵ�ֵ������Ҫɾ���Ľڵ�
            T->left=Delete(T->left,T->data); 
        }
        else{//�ýڵ���������
            for(p=T->right;p->left;p=p->left);
            T->data=p->data;//�������������Ľڵ�ֵ������Ҫɾ���Ľڵ�
            T->right=Delete(T->right,T->data);
        }
    }
    return T;
}
BiTree search_id(BiTree T,int id){//����ѧ�Ų�ѯ 
    if(T==NULL)return NULL;
    if(T->data.id==id)return T;
    else{
    	BiTree l=search_id(T->left,id);
    	BiTree r=search_id(T->right,id);
    	return l?l:r;
    }
}
void menu(){
    printf("1.�Ӽ�������һ��ѧ����¼��������������\n");
    printf("2.��������������\n");
    printf("3.���ļ��ָ��ڴ�Ķ���������\n");
    printf("4.�����������������\n");
    printf("5.��������������\n");
    printf("6.����������������нڵ�����Ҷ�ӽڵ���\n");
    printf("7.���������������һ����¼\n");
    printf("8.�Ӷ�����������ɾ��һ����¼\n");
    printf("9.�Ӷ����������в�ѯһ����¼\n");
    printf("-1.�˳�ϵͳ\n");
}
int main(){
    BiTree T=NULL;
    while(1){
		menu();
		int operation;
    	scanf("%d",&operation);
    	stu s;
    	switch(operation){
        case 1:
            printf("������ѧ���ĸ�����\n");
            int n;
            scanf("%d",&n);
            printf("������%d��ѧ����ѧ�źͳɼ����м��ÿո������\n",n);
            int i;
            for(i=0;i<n;i++){
                scanf("%d%d",&s.id,&s.grade);
                T=insert(T,s);
            }
            printf("�������\n");
            break;
        case 2:{
        	FILE *fout=fopen("bst.txt","w");
        	inordersave(T,fout);
        	fclose(fout);
        	printf("�ѱ�����bst.txt\n");
            break;
        }
        case 3:{
        	FILE *fin=fopen("bst.txt","r");
        	T=NULL;
        	while(fscanf(fin,"%d%d",&s.id,&s.grade)==2)
        		T=insert(T,s);
        	printf("��bst.txt�ָ����������������:\n");
        	inorder(T);
        	fclose(fin);
            break;
        }
        case 4:
            printf("�������������������Ϊ��\n");
            inorder(T);
            break;
        case 5:
            printf("���������������Ϊ��%d\n",depth(T));
            break;
        case 6:
            printf("���������������н�����Ϊ��%d\n",count_nodes(T));
            printf("����������������Ҷ�ӽ�����Ϊ��%d\n",count_leaves(T));
            break;
        case 7:
            printf("������ѧ����ѧ�źͳɼ����м��ÿո������\n");
            scanf("%d%d",&s.id,&s.grade);
            T=insert(T,s);
            break;
        case 8:
            printf("����������ɾ�����Ǹ��˵�ѧ�źͳɼ���\n");
            scanf("%d%d",&s.id,&s.grade);
            Delete(T,s);
            break;
        case 9:
            printf("������������ҵ�ѧ��\n");
            int id;
            BiTree p;
            scanf("%d",&id);
            p=search_id(T,id);
            if(p==NULL)printf("�Ҳ���\n");
            else{
            	printf("����ҵ�����˵���ϢΪ��\n");
            	printf("ѧ�ţ�%d\n",p->data.id);
            	printf("������%d\n",p->data.grade);
        	}
            break;
        case -1:
			system("pause");
			return 0;
        default:
            printf("��������������������룡\n");
            break;
        }
        printf("\n\n\n");
    }
}
