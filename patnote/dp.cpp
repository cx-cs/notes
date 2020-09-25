/*
树塔问题：第n层n个，求塔顶到塔底一条路数字和最大。dp[i][j]表示从[i,j]到塔底的最大和，即求dp[1][1]，边界是dp[n][j]=f[n][j],状态转移方程
	dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+f[i][j]，即第i层出发等于i+1层较大的加
最大连续子序列和：dp[i]表示以A[i]结尾的连续子序列和，即求dp的最大值，边界是dp[0]=A[0]，状态转移方程
	dp[i]=max(A[i],dp[i-1]+A[i])，即取前i-1加上自己和自己较大的
最长不下降子序列(LIS)：dp[i]表示以A[i]结尾的最长不下降子序列个数，即求dp的最大值，边界是dp[i]=1，状态转移方程
	A[i]>=A[j]时,dp[i]=max(dp[j<i]+1)，即选最大的dp[j]
最长公共子序列(LCS)：dp[i][j]表示Ai和Bj号位之前（包括）的最长公共子序列长度，即求dp[lenA][lenB]，边界是dp[0][j]=dp[i][0]=0，状态转移方程
	A[i]=B[j]时,dp[i][j]=dp[i-1][j-1]+1;不等时max(dp[i-1][j],dp[i][j-1])
最长回文子串：dp[i][j]表示i到j是否是回文，即求i到j最大的，边界是dp[i][i]=1和dp[i][i+1]=0or1，状态转移方程
	s[i]=s[j]时dp[i+1][j-1],不等时为0
01背包：n件物品每件重量w[i]，价值c[i]，背包容量V，该怎么选使背包价值最大。dp[i][v]表示前i件放满容量为v的背包最大价值。
	dp[i][v]=dp[i-1][v]容量不够
			=max(dp[i-1][v],dp[i-1][v-w[i]]+c[i])容量够选放和不放大的
			 边界dp[0][v]=0
*/
for(i=1;i<=N;i++){//前i件物品
	for(j=1;j<=M;j++){//背包剩余空间
		if(w[i]>j)//第i件物品太大放不进去
			dp[i][j]=dp[i-1][j];
		else
			dp[i][j]=max(dp[i-1][j-w[i]]+v[i],dp[i-1][j]);//第i件物品放进去和不放进去(有没有放可以加个判断)
	}
//dp[N][M]表示N件物品V容量能取到的最大价值