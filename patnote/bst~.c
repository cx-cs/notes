#include<stdio.h>
#include<stdlib.h>
typedef struct student{//学生记录类型 
    int grade,id;//成绩，学号 
}stu;
typedef struct node{//二叉排序树的节点类型
    stu data;
    struct node *left;
    struct node *right;
}binode,*BiTree;
BiTree init(){//无参初始化 
	BiTree tmp=(BiTree)malloc(sizeof(stu));
	tmp->left=NULL;
	tmp->right=NULL;
	return tmp;
}
BiTree init2(int g,int i){//带参初始化 
	BiTree tmp=(BiTree)malloc(sizeof(stu));
	tmp->left=NULL;
	tmp->right=NULL;
	tmp->data.grade=g;
	tmp->data.id=i;
	return tmp;
}
BiTree insert(BiTree T,stu s){//按成绩插入 
    if(T==NULL){
        T=init2(s.grade,s.id);
        return T;
    }
    if(s.grade<T->data.grade)T->left=insert(T->left,s);//小的往左插 
    else if(s.grade==T->data.grade){//若成绩相等 
    	if(s.id==T->data.id)return;// 学号一样说明该学生已存在不再插入 
    	else T->left=insert(T->left,s);//否则插左边 
    }
    else T->right=insert(T->right,s);//大的往右插 
    return T;
}
void inordersave(BiTree T,FILE* fout){//将树按中序存至bst.txt 
    if(T==NULL)return;
    inordersave(T->left,fout);
    fprintf(fout,"%d %d ",T->data.id,T->data.grade);
    inordersave(T->right,fout);
}
void inorder(BiTree T){//中序遍历 
    if(T==NULL)return;
    inorder(T->left);
    printf("学号：%d  成绩：%d\n",T->data.id,T->data.grade);
    inorder(T->right);
}
int depth(BiTree T){//深度 
    if(T==NULL)return 0;
    int left=depth(T->left); 
    int right=depth(T->right);
    return left>right?left+1:right+1;//深度等于左右子树深度较大那个加1 
}
int count_nodes(BiTree T){//求结点数 
	if(T==NULL)return 0;
    return 1+count_nodes(T->left)+count_nodes(T->right);//结点数等于1+左右子树结点数 
}
 
int count_leaves(BiTree T){//求叶子数 
    if(T==0)return 0;
    else if(T->left==NULL&&T->right==NULL)return 1;//是叶子返回1 
    else return count_leaves(T->left)+count_leaves(T->right);//不是叶子返回左右子树叶子数 
}
BiTree Delete(BiTree T,stu s){//删除结点 
    BiTree p;
    if(T==NULL)return NULL;
    if(T->data.grade>s.grade||(T->data.grade==s.grade&&T->data.id!=s.id))T->left=Delete(T->left,s);
    else if(T->data.grade<s.grade)T->right=Delete(T->right,s);//先找到该节点 
    else{
        if(T->left==NULL&&T->right==NULL){//该结点为叶子直接删除 
            free(T);
            T=NULL;
        }
        else if(T->left){//该结点有左子树 
            for(p=T->left;p->right;p=p->right);
            T->data=p->data; //将左子树下最靠右的节点值赋予想要删除的节点
            T->left=Delete(T->left,T->data); 
        }
        else{//该节点有右子树
            for(p=T->right;p->left;p=p->left);
            T->data=p->data;//将右子树下最靠左的节点值赋予想要删除的节点
            T->right=Delete(T->right,T->data);
        }
    }
    return T;
}
BiTree search_id(BiTree T,int id){//根据学号查询 
    if(T==NULL)return NULL;
    if(T->data.id==id)return T;
    else{
    	BiTree l=search_id(T->left,id);
    	BiTree r=search_id(T->right,id);
    	return l?l:r;
    }
}
void menu(){
    printf("1.从键盘输入一组学生记录建立二叉排序树\n");
    printf("2.二叉排序树存盘\n");
    printf("3.由文件恢复内存的二叉排序树\n");
    printf("4.中序遍历二叉排序树\n");
    printf("5.求二叉排序树深度\n");
    printf("6.求二叉排序树的所有节点数和叶子节点数\n");
    printf("7.向二叉排序树插入一条记录\n");
    printf("8.从二叉排序树中删除一条记录\n");
    printf("9.从二叉排序树中查询一条记录\n");
    printf("-1.退出系统\n");
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
            printf("请输入学生的个数：\n");
            int n;
            scanf("%d",&n);
            printf("请输入%d个学生的学号和成绩，中间用空格隔开：\n",n);
            int i;
            for(i=0;i<n;i++){
                scanf("%d%d",&s.id,&s.grade);
                T=insert(T,s);
            }
            printf("建树完成\n");
            break;
        case 2:{
        	FILE *fout=fopen("bst.txt","w");
        	inordersave(T,fout);
        	fclose(fout);
        	printf("已保存至bst.txt\n");
            break;
        }
        case 3:{
        	FILE *fin=fopen("bst.txt","r");
        	T=NULL;
        	while(fscanf(fin,"%d%d",&s.id,&s.grade)==2)
        		T=insert(T,s);
        	printf("从bst.txt恢复二叉树并中序遍历:\n");
        	inorder(T);
        	fclose(fin);
            break;
        }
        case 4:
            printf("二叉排序树的中序遍历为：\n");
            inorder(T);
            break;
        case 5:
            printf("二叉排序树的深度为：%d\n",depth(T));
            break;
        case 6:
            printf("二叉排序树中所有结点个数为：%d\n",count_nodes(T));
            printf("二叉排序树中所有叶子结点个数为：%d\n",count_leaves(T));
            break;
        case 7:
            printf("请输入学生的学号和成绩，中间用空格隔开：\n");
            scanf("%d%d",&s.id,&s.grade);
            T=insert(T,s);
            break;
        case 8:
            printf("请输入你想删除的那个人的学号和成绩：\n");
            scanf("%d%d",&s.id,&s.grade);
            Delete(T,s);
            break;
        case 9:
            printf("请输入你想查找的学号\n");
            int id;
            BiTree p;
            scanf("%d",&id);
            p=search_id(T,id);
            if(p==NULL)printf("找不到\n");
            else{
            	printf("你查找的这个人的信息为：\n");
            	printf("学号：%d\n",p->data.id);
            	printf("分数：%d\n",p->data.grade);
        	}
            break;
        case -1:
			system("pause");
			return 0;
        default:
            printf("你的输入有误，请重新输入！\n");
            break;
        }
        printf("\n\n\n");
    }
}
