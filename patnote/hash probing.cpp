//һ����ֱ�Ӷ�ַ(��ȱ任)��H(key)=key�����Ա任H(key)=a*key+b����������H(key)=key%mod
//�±�ΪH(key)��ռ����
//Linear Probing����ռ�þͿ�H(key)+1
//Quadratic Probing��H(key)+1^2,H(key)+2^2...
for(int step=0;step<size;step++){
        int index=(key+step*step)%size;//ƽ��̽�⣬key��Ҫ�����ֵ
        if(hashTable[index]==0){
            hashTable[index]=1;
            cout<<index;
		}
}