#include<iostream>
using namespace std;
void shellsort(int arr[],int n){//ϣ������  ����
    for(int d=n/2;d>0;d/=2){//���d��Ϊһ����в�������
        for(int i=d;i<n;i++)
            for(int j=i;j-d>=0;j-=d)
                if(arr[j-d]>arr[j]){
                    int temp=arr[j-d];
                    arr[j-d]=arr[j];
                    arr[j]=temp;
                }
	}
}
int binarysearch(int arr[],int x,int n){//�ϸ������ȷ����x,[0,n-1]
	int mid,left=0,right=n-1;
	while(left<=right){
		mid=(left+right)/2;
		if(arr[mid]==x)return mid;
		else if(arr[mid]>x)right=mid-1;
		else left=mid+1;
	}
	return -1;//�Ҳ���
}
int main(){
	int arr[]={7,20,14,8,45,1,23,6,134,56,78,2,13,4};
	shellsort(arr,14);
	for(int i=0;i<14;i++)
		cout<<arr[i]<<" "<<(i==13?"\n":"");
	cout<<"6��λ�ã�"<<binarysearch(arr,6,14)<<endl;
	cout<<"14��λ�ã�"<<binarysearch(arr,14,14)<<endl;
	cout<<"56��λ�ã�"<<binarysearch(arr,56,14)<<endl;
	cout<<"7��λ�ã�"<<binarysearch(arr,7,14)<<endl;
	system("pause");
}