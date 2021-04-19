#include "Solution.h"
#include <iostream>

using namespace std;

double Solution::myPow(double x, int n) {
    if (n >= 0) {
        return powWithLoop(x, n);
    }
    else {
        //若n的值为int下界，直接取正会溢出
        //也可使用longlong类型接收n的值进行运算以避免此情况
        if (n == numeric_limits<int>::min()) {
            //先将n缩减为原来值的一半再取正以避免溢出
            double p = powWithLoop(x, -(n / 2));
            //此处必须以小括号包裹p*p
            //否则会先运算1.0/inf，得0，再运算0*inf，得-nan(ind)
            return 1.0 / (p * p);
        }
        return 1 / powWithLoop(x, -n);
    }
}

double Solution::powWithRecursion(double x, int n) {
    if (x == 1 || n ==0) {
        return 1.0;
    }
    //若n为正奇数
    if ((n & 1) != 0) {
        return x * myPow(x, (n - 1));
    }else {
        //若n为正偶数
        double p = myPow(x, n / 2);
        return p * p;
    }
}

double Solution::powWithLoop(double x, int n) {
    //迭代实现
    //将指数拆分为多个2的幂数之和，如求 x^77：
    //77=64+8+4+1，其中64、8、4、1皆为2的幂数（1为2的零次幂）
    //x^(77d(0b1001101))
    //=x^(64d(0b1000000)+8d(0b1000)+4d(0b100)+0b1)  
    //=x^(64d(0b1000000))∗x^8d(0b1000) ∗x^4d(0b100) ∗x^(1d(0b1))
    //其中，77的二进制形式中的1的个数恰好指示了拆分后的部分个数
    double ans = 1.0;
    //上述x^k，k为2的幂数
    double x_contribute = x;
    //在对n进行拆分的同时计算答案
    while (n > 0) {
        //如果n的最低位为1
        //该条件命中次数为n中1位的个数
        if ((n & 1) == 1) {
            ans = ans * x_contribute;
        }
        //取平方
        x_contribute = x_contribute*x_contribute;
        //舍弃n二进制表示的最低位
        n = n >> 1;
    }
    return ans;  
}

