typedef long long LL;
LL mod(LL a,LL b,LL m){
	if(b==0)return 1;
	if(b&1)return a*mod(a,b-1,m)%m;//a^b=a*a^(b-1)
	else{
		LL tmp=mod(a,b/2,m);//a^b=a^(b/2)*a^(b/2);
		return tmp*tmp%m;
	}
}