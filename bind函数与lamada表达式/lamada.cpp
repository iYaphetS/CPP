#include <iostream>

using namespace std;
#include <functional>

int main(int argc, char *argv[])
{



    []{
        cout << "hello world" << endl;
    };//这是一个类型，没有调用，无法输出

    []{
        cout << "hello world" << endl;
    }();//这是一个匿名函数对象

    auto fun = []{

        cout  << "fun" << endl;
    };
    fun();

    function<void()> fun1 = []{

        cout  << "fun1" << endl;
    };
    fun1();

    //[]捕获列表， ()参数列表-可省略， ->type返回类型-可省略，  {}函数体
    function<int(int)> fun2 = [](int a)->int{

        return 1;
    };

    cout << "ret = " << fun2(10) << endl;

    function<int(int, int)> fun3 = [](int a, int b)
    {
        return 10;
    };
    cout << "lamada ret is " << fun3(1, 2) << endl;


    //[] 捕获的方式----------在定义就把外部的变量传过来，而普通的函数调用是在调用函数的时候传的参数
    //1.变量名   值捕获----const 不能修改
    //2.&       定义之前全部外部变量引用捕获----能够修改外面的值
    /*
    引用捕获外部的变量，一定时刻关注变量的生命周期，如果引用了局部变量，在其他函数调用这个
    lambada函数的时候，就会引用了一块非法内存***-----可用值捕获，加上mutable使之可修改
    */
    //3.值捕获加上mutable-----修改捕获的值（mutable改变了const属性使之能修改），不能修改外面的值
    //4.=       全部捕获lamada函数定义之前的所有值
    int a = 10;
    double b = 10.2;
    function<void(int, char)> fun4 = [=](int a, char c)
    {
        //同名隐藏，就近访问
        cout << a << " " << b << " " <<  c << endl;//100 10.2 a
    };

    fun4(100, 'a');
    return 0;
}
