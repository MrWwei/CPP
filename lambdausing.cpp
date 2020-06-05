/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int a = 5, b = 7;
    auto total = [](int x, int y)->int {return x + y; };    //接受两个参数
    cout << total(a, b)<<endl;  //12
    auto fun1 = [=] {return a + b; };   //值传递捕捉父作用域变量
    cout << fun1() << endl; //12
    auto fun2 = [&](int c) {b = a + c; a = 1; };    //省略了返回值类型，引用捕获所有
    fun2(3);    //1 8
    cout << a <<" "<< b << endl;
    a = 5; b = 7;   //被修改后，重新赋值
    auto fun3 = [=, &b](int c) mutable {b = a + c; a = 1; };    //以值传递捕捉的变量，在函数体里如果要修改，要加mutaple,因为默认const修饰
    fun3(3);
    cout << a << " " <<b<< endl;    //5,8
    a = 5; b = 7;   //被修改后，重新赋值
    auto fun4 = [=](int x, int y) mutable->int {a += x; b += y; return a + b; };
    int t = fun4(10, 20);
    cout << t << endl;  //42
    cout << a <<" "<< b << endl;    //5 7
    return 0;
}
