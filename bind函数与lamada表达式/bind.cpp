#include <iostream>

using namespace std;
#include <functional>

class parent
{
public:
    void fun1()
    {
        cout << "parent::fun1" << endl;
    }
    virtual void fun2()
    {
        cout << "parent::fun2" << endl;
    }
};

class child : public parent
{
public:
    void fun1()
    {
        cout << "child::fun1" << endl;
    }
    virtual void fun2()
    {
        cout << "child::fun2" << endl;
    }
};

void func(int a, char c, double d)
{
    cout << a << " " << c << " " << d << endl;
}

int main()
{
    //静态绑定------编译时就已经绑定
    child c;
    parent * p = &c;
    p->fun1();//----调用farent::fun1
    //动态绑定----在运行是才确定调用的是哪个函数
    p->fun2();//----调用child::fun2
    //自定义绑定
    /*
     * 1.bind1st
       2.bind2nd

       3.bind
    */
    //typedef (*pfun)(int, char, double)---定义函数指针类型
    function<void(int, char, double)> f;//函数类型定义 函数变量
    f = func;
    f(100, 'a', 10.2);

    f = bind(func, placeholders::_1, placeholders::_2, placeholders::_3);
    f(10, 's', 2.3);

    //function<void(char, int, double)> f1;//函数类型定义 函数变量
    auto f1 = bind(func, placeholders::_3, placeholders::_2, placeholders::_1);
    f1(5.3, 'd', 12);

    //function<void(char, double)> f2;
    auto f2 = bind(func, 300, placeholders::_2, placeholders::_1);
    f2(1.2, 'r');

    //注意用auto，不然定义函数参数类型不匹配也会输出错误，上面两种不用auto都会出错
    /*--------------------------------------------------
placeholders ,占位符。表示新的函数对象中参数的位置。当调用新的函数对象时，新函数对象会调用被调用函数，并且其参数会传递到被调用函数参数列表中持有与新函数对象中位置对应的占位符。

举个例子：

        void function(arg1,arg2,arg3,arg4,arg5)

        {

            //do something

        }

        auto g = bind(function,a,b,_2,c,_1);

        新的函数对象：g

        被调用函数：function

        当调用函数对象g时候，函数对象g会调用function函数，并把其参数传给function函数，g的第一个参数会传给function的持有占位符_1的位置，即arg5。第二个参数会传给function的持有占位符_2的位置，即arg3。

        void g(X,Y);

        相对于调用下面函数

        function(function,a,b,Y,c,X);

        其中的arg1,arg2,arg4已经被绑定到a,b,c上。



        placeholders是一个命名空间，其本身定义在std命名空间中。placeholder中有名字_n (1,2,3,4,……n)。为了使用这些名字，两个命名空间都必须写上。例如：

using namespace std::placeholders::_1;

      与bind函数一样，placeholders命名空间也定义在functional中

    */
    return 0;
}
