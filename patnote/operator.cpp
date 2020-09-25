struct node {
    int value, cnt;
    bool operator < (const node a)  const{//重载，第二个const表示不修改成员值
        return (cnt != a.cnt) ? cnt > a.cnt : value < a.value;
    }
};
set<node> s;//插入时自动排序