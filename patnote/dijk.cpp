/*ȫ����һά��d(inf),cost(inf),wei(0),numroad(0),numpoint(0)
d[src]=0,cost[src]=0,wei[src]=wei[src],numroad[src]=1,numpoint[src]=1
�洢һ�������ڵڼ���·map[a*10000+b]=4��map[b*10000+a]=4������10000*10000����ʵ

һ����������͡�
û���ʹ��ҿɴ�
1�������С
2����������
numroad
2����Ȩ�͸���/���Ѻ͸�С/������ȵ�����
�ó�һ��pre����󣨲�Ҫ�����·���Ͳ�Ҫ��*/
void dfs(int v){
	if(v==src){
		cout<<v;
		return;
	}
	dfs(pre[v]);
	cout<<v;
}

//�������
//�޷�dijk���Դ�ȫ��pre��dfs
void dfs(int v){
	tmp.push_back(v);
	if(v==src){
		����������·������
		����·����path
		tmp.pop_back();
		return;
	}
	for(int i=0;i<pre[v].size();i++)
		dfs(pre[v][i]);
	}
	tmp.pop_back();
}

//Ҫ��ת�������½��鷳���ڴ��������ǲ���dijkֱ��dfs����Ŀ����ʱ�ÿ��ܺ�ʱ���ࣩ
void dfs(int v,cnt){
	tmp.push_back(v);
	if(v==dst){
		�Ƿ�����
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