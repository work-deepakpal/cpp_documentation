#include <iostream>
#include <thread>


/* Thread can use callable object in following ways
    1. Function Pointer
    2. Function Object
    3. Lambda Function
    4. Member Function
    5. Static Member Function
*/


// 1. Function Pointer
void thread_function_t1()
{
    std::cout << "Thread Function using Function Pointer" << std::endl;
}

// 2. Function Object (Functor)
class thread_functor_t2
{
public : 
    void operator()(int i)
    {
        ++i;
        std::cout << "Thread Function using Function Object" << std::endl;
    }
};

// 3. Lambda Function
auto thread_lambda_function_t3 = [/*capture_var*/](/*params*/){
    std::cout << "Thread Function using Lambda Function" << std::endl;
};


class threadObj
{
public:
// 4. Member Function
    void thread_function_t4()
    {
        std::cout << "Thread Function using Member Function" << std::endl;
    }
// 5. Static Member Function
    static void thread_function_t5()
    {
        std::cout << "Thread Function using Static Member Function" << std::endl;
    }
};


bool isCpp20()
{
    #if __cplusplus >= 202002L
        return true;
    #else
        return false;
    #endif
}

int main()
{

if(isCpp20())
{
    std::cout << "C++20" << std::endl;
    //Use g++ -o output ./threads_joinable.cpp -std=c++20 -lpthread to compile


    // 1. Function Pointer
    std::jthread t1(thread_function_t1);

    // 2. Function Object
    std::jthread t2(thread_functor_t2(),10);

    // 3. Lambda Function
    std::jthread t3(thread_lambda_function_t3/*, params*/);

    // 4. Member Function
    threadObj Obj;
    std::jthread t4(&threadObj::thread_function_t4, &Obj);

    // 5. Static Member Function
    std::jthread t5(&threadObj::thread_function_t5);
}
else
{
    std::cout << "C++ Versions Other than C++20" << std::endl;
    // 1. Function Pointer
    std::thread t1(thread_function_t1);

    // 2. Function Object
    std::thread t2(thread_function_t2(),10);

    // 3. Lambda Function
    std::thread t3(thread_lambda_function_t3/*, params*/);

    // 4. Member Function
    threadObj Obj;
    std::thread t4(&threadObj::thread_function_t4, &Obj);

    // 5. Static Member Function
    std::thread t5(&threadObj::thread_function_t5);

    std::cout <<"Main Thread" << std::endl;

    if(t1.joinable())
        t1.join();

    if(t2.joinable())
        t2.join();

    if(t3.joinable())
        t3.join();

    if(t4.joinable())
        t4.join();
    
    if(t5.joinable())
        t5.join();
}

    std::this_thread::sleep_for(std::chrono::seconds(1));

    return 0;
}
