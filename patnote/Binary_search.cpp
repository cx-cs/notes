int binarysearch(int left,int right,int x){//严格递增精确查找x,[0,n-1]
	int mid;
	while(left<=right){
		mid=(left+right)/2;//防溢出left+(right-left)/2
		if(a[mid]==x)return mid;
		else if(a[mid]>x)right=mid-1;
		else left=mid+1;
	}
	return -1;
}
int lower_bound(int left,int right,int x){//递增查找第一个>=x,[0,n],x比a都大时返回n
	int mid;
	while(left<right){//等于时退出
		mid=(left+right)/2;
		if(a[mid]>=x)right=mid;//[left,mid]
		else left=mid+1;
	}
	return left;//right也可以
}
int upper_bound(int left,int right,int x){//递增查找第一个>x,[0,n],x比a都大时返回n
	int mid;
	while(left<right){//等于时退出
		mid=(left+right)/2;
		if(a[mid]>x)right=mid;//[left,mid]
		else left=mid+1;
	}
	return left;//right也可以
}