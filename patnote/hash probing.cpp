//一般是直接定址(恒等变换)即H(key)=key，线性变换H(key)=a*key+b，除留余数H(key)=key%mod
//下标为H(key)被占用了
//Linear Probing：被占用就看H(key)+1
//Quadratic Probing：H(key)+1^2,H(key)+2^2...
for(int step=0;step<size;step++){
        int index=(key+step*step)%size;//平方探测，key是要插入的值
        if(hashTable[index]==0){
            hashTable[index]=1;
            cout<<index;
		}
}