int findFather(int x) {
    int a = x;
    while(x != father[x])//���ҵ���x
        x = father[x];
    while(a != father[a]) {//����·��ȫ�ĵ�
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;//���ظ�
}
void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) father[faA] = faB;//������Ⱦͺϲ�
}
for(int i = 1; i <= n; i++)
	father[i] = i;//����ʼֵΪ�Լ�
Union(a,b);//��a����b����������ν��Ҫע��ѡ����,U(a,c)U(a,d)
for(int i = 1; i <= n; i++)
	findFather(i)==i;//������++
for(int i=1;i<N+1;++i)
	result[findFather(i)]++;//��Ӧ����������++