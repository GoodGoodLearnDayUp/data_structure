#include <iostream>
#include <chrono>

// 要测试的函数
void myFunction()
{
    for (int i = 0; i < 1000000000; ++i) {
        // do something
    }
}

int main()
{
    // 获取当前时间
    auto start_time = std::chrono::high_resolution_clock::now();

    // 调用要测试的函数
    myFunction();

    // 获取结束时间
    auto end_time = std::chrono::high_resolution_clock::now();

    // 计算函数调用所花费的时间
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    std::cout << "myFunction() took " << duration.count() << " microseconds." << std::endl;

    return 0;
}
