struct node {
    int value, cnt;
    bool operator < (const node a)  const{//���أ��ڶ���const��ʾ���޸ĳ�Աֵ
        return (cnt != a.cnt) ? cnt > a.cnt : value < a.value;
    }
};
set<node> s;//����ʱ�Զ�����