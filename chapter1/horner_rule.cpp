#include<iostream>
#include<cmath>
#include<random>
#include <chrono>

using namespace std;
using namespace chrono;

double horner(double *a, double x, int max_num)
{
       if(!max_num)
       return *a;
       else
       return horner(a+1, x, max_num-1)*x+*a;
}

double pol(double *a, double x, int n)
{
    double temp = 0;
    for(int i=0;i<=n;i++){
        temp+=(a[i]*pow(x,i));
    }
    return temp;
}

int main()
{
    const int num = 10;
    double lower_bound = 0.0;
    double upper_bound = 1.0;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double>dis(lower_bound,upper_bound);

    double a[11];
    std::cout<<"随机数序列如下所示"<<std::endl;
    for(int i=0;i<11;i++)
      {
         a[i]=dis(gen);
         if(10==i)
         {
            std::cout<<"x = "<<a[i];continue;
         }
         std::cout<<"a"<<i<<" = "<<a[i]<<",";
      } 
      std::cout<<std::endl;

      std::cout<<horner(a,a[10],9)<<std::endl;
      std::cout<<pol(a,a[10],9)<<std::endl;

      auto start_time = std::chrono::high_resolution_clock::now();
      for(int i=0;i<100000000;i++)
         horner(a,a[10],9);
      auto end_time = std::chrono::high_resolution_clock::now();

      auto duration = duration_cast<std::chrono::microseconds>(end_time - start_time);

      std::cout<<"horner方法所用时间："<<duration.count()<<"us"<<std::endl;

      auto start_time2 = std::chrono::high_resolution_clock::now();
      for(int i=0;i<100000000;i++)
         pol(a,a[10],9);
      auto end_time2 = std::chrono::high_resolution_clock::now();

      auto duration2 = duration_cast<std::chrono::microseconds>(end_time2 - start_time2);

      std::cout<<"pol方法所用时间："<<duration2.count()<<"us"<<std::endl;




    return 0;
}

