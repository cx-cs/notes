int binarysearch(int left,int right,int x){//�ϸ������ȷ����x,[0,n-1]
	int mid;
	while(left<=right){
		mid=(left+right)/2;//�����left+(right-left)/2
		if(a[mid]==x)return mid;
		else if(a[mid]>x)right=mid-1;
		else left=mid+1;
	}
	return -1;
}
int lower_bound(int left,int right,int x){//�������ҵ�һ��>=x,[0,n],x��a����ʱ����n
	int mid;
	while(left<right){//����ʱ�˳�
		mid=(left+right)/2;
		if(a[mid]>=x)right=mid;//[left,mid]
		else left=mid+1;
	}
	return left;//rightҲ����
}
int upper_bound(int left,int right,int x){//�������ҵ�һ��>x,[0,n],x��a����ʱ����n
	int mid;
	while(left<right){//����ʱ�˳�
		mid=(left+right)/2;
		if(a[mid]>x)right=mid;//[left,mid]
		else left=mid+1;
	}
	return left;//rightҲ����
}