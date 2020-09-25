int findFather(int x) {
    int a = x;
    while(x != father[x])//先找到根x
        x = father[x];
    while(a != father[a]) {//把沿路根全改掉
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;//返回根
}
void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) father[faA] = faB;//根不相等就合并
}
for(int i = 1; i <= n; i++)
	father[i] = i;//根初始值为自己
Union(a,b);//把a并到b，左右无所谓但要注意选定根,U(a,c)U(a,d)
for(int i = 1; i <= n; i++)
	findFather(i)==i;//集团数++
for(int i=1;i<N+1;++i)
	result[findFather(i)]++;//相应集团里人数++