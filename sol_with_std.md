## 等腰直角三角形

折叠方法：先一直对折使长和宽比值在 $1:1~1:2$ 之间,然后沿两条角平分线折叠即可


~~~c++
#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    int cnt = 0;
    while (a < b) a *= 2, cnt++;
    cout << cnt + 1 << '\n';
}
~~~

## and & mul

首先我先向因为精度问题被卡了的同学致歉。出题人事先没有想想到精度会有问题

在题解之前，我先放下原来的题面


> 有一种魔法，每次运行可以让一个数 $x$ 等概率随机变为 $a * x$ 或 $x + b$ ，现在有 n 个数 $c1, c2, ..., cn$，想分别知道对每个数反复施法 $m$ 次之后大小期望 $E(c1), E(c2), ..., E(cn)$，该如何求解

但是很可惜这个题面被 gpt 秒了，于是就有了现在这个新的题面

不难证明这个题面与原体面是等价的，从这个题面出发

本题出出来预期的做法是注意到期望具有线性性，并且一直具有线性性质

也就是说无论几次魔法都有 $E(x) = kx + c$ 的形式

我们只需要维护多次魔法 $k,c$ 的取值就行

$k1,c1 = \frac{1+a}{2} k ,\frac{1+a}{2} c + \frac{b}{2}$

~~~ c++
#include <iostream>
#include <vector>
using namespace std;
using db = double;
using pii = pair<db, db>;
db a, b;
pii f(db k, db c) {
    return {k * (a + 1) / 2, (a * c + c + b) / 2};
}

int main() {
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int n, m;
    cin >> a >> b;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) cin >> a[i] >> b[i];
    db k = 1, c = 0;
    for (int i = 0; i < m; ++i) {
        auto [k1, c1] = f(k, c);
        k = k1, c = c1;
    }
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        printf("%.9lf ", tmp * k + c);
    }
    printf("\n");
}
~~~

## bingo

我们先算出不考虑最后一行的情况下，第 $i$ 个元素变成 1 能获得多少分数，记为 $a_i$

那么我们的得分则为 $$S = a_1p_1 + a_2p_2 + a_3p_3 + a_4p_4 + a_5p_5 + p_1p_2p_3p_4p_5$$

然后假如我们把 $S$ 看成 $p_1$ 的函数

对其求导，我们能得到 $a_1 + p_2p_3p_4p_5$

一个重要的观察是 $p_2p_3p_4p_5 \leq 1$

也就是说只要有两个格子 $i,j$  满足 $a_i > a_j$ 那么我们就要先将概率分配到第 $i$ 个格子

而如果格子的系数相等的话，考虑均匀分配

所以最后的分配方案是先分配 $a_i$ 较大的，分配不满考虑均匀分配

~~~ c++
#include<iostream>
#include<vector>
using namespace std;
int a[5][5],val[5],cnt_val[3];
using ldb = long double;
ldb assgin[3];
int main(){
    ldb P;
    for(int i=0;i<4;++i)for(int j=0;j<5;++j)cin>>a[i][j];
    cin >> P;
    for(int j=0;j<5;++j){
        int f = 1;
        for(int i=0;i<4;++i)f&=a[i][j];
        val[j]+=f;
    }
    val[4] += a[0][0] && a[1][1] && a[2][2] && a[3][3];
    val[0] += a[0][4] && a[1][3] && a[2][2] && a[3][1];
    for(int i=0;i<5;++i)cnt_val[val[i]]++;
    for(int i=2;i>=0;--i){
        if(P<=cnt_val[i]){assgin[i]=P/cnt_val[i];break;}
        else {assgin[i]=1,P-=cnt_val[i];}
    }
    ldb ans=0;
    for(int i=0;i<4;++i){
        int f = 1;
        for(int j=0;j<5;++j)f&=a[i][j];
        ans+=f;
    }
    for(int i=0;i<=2;++i){ans+=i*cnt_val[i]*assgin[i];}
    ldb tmp=1;
    for(int i=0;i<=2;++i)for(int j=0;j<cnt_val[i];++j)tmp*=assgin[i];
    printf("%.11LF",tmp+ans);
}
~~~