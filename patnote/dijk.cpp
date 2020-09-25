/*全部用一维：d(inf),cost(inf),wei(0),numroad(0),numpoint(0)
d[src]=0,cost[src]=0,wei[src]=wei[src],numroad[src]=1,numpoint[src]=1
存储一条边属于第几条路map[a*10000+b]=4，map[b*10000+a]=4，定义10000*10000不现实

一般情况：“和”
没访问过且可达
1、距离和小
2、距离和相等
numroad
2、点权和更大/花费和更小/点数多等等条件
得出一个pre数组后（不要求输出路径就不要）*/
void dfs(int v){
	if(v==src){
		cout<<v;
		return;
	}
	dfs(pre[v]);
	cout<<v;
}

//复杂情况
//无法dijk可以存全部pre再dfs
void dfs(int v){
	tmp.push_back(v);
	if(v==src){
		用这条完整路径计算
		最优路径存path
		tmp.pop_back();
		return;
	}
	for(int i=0;i<pre[v].size();i++)
		dfs(pre[v][i]);
	}
	tmp.pop_back();
}

//要求转车数更新较麻烦出于代码量考虑不用dijk直接dfs（题目复杂时用可能耗时更多）
void dfs(int v,cnt){
	tmp.push_back(v);
	if(v==dst){
		是否最优
		tmp.pop_back();
		return;
	}
	visit=1;
	for(int i=0;i<v[v].size();i++){
		if(!visit)dfs(v[v][i],cnt+1);
	}
	visit=0;
	tmp.pop_back();
}