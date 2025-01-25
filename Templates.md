**Templates are expanded at compiler time. This is like macros. 
The difference is, that the compiler does type-checking before template expansion. 
The idea is simple, source code contains only function/class, but compiled code may contain multiple copies of the same function/class.**

![image](https://github.com/user-attachments/assets/74a9da18-f891-414b-9749-296b087a8ee4)

Function Templates
We write a generic function that can be used for different data types. Examples of function templates are sort(), max(), min(), printArray(). 

To know more about the topic refer to Generics in C++.
```
// C++ Program to demonstrate
// Use of template
#include <iostream>
using namespace std;

// One function works for all data types. This would work
// even for user defined types if operator '>' is overloaded
template <typename T> T myMax(T x, T y)
{
    return (x > y) ? x : y;
}

int main()
{
    // Call myMax for int
    cout << myMax<int>(3, 7) << endl;
    // call myMax for double
    cout << myMax<double>(3.0, 7.0) << endl;
    // call myMax for char
    cout << myMax<char>('g', 'e') << endl;

    return 0;
}
```
