#include<iostream>

using namespace std;
int display(int num);


int main()
{

    int num,f;
    cout<<"Please input the number of boolean\n";
    cin>>num;
    f=display(num);
    cout<<"The frequecy is: "<<f<<endl;
    return 0;
    
}

int display(int n){
    int len = 1<<n;
    int counter=0;
    for(int i=0;i<len;i++)
    {
        int mask=1<<n-1;
        int flag=0;
        cout<<"seq"<<(++counter)<<": <";
        for(int j=0;j<n;j++)
        {
           if(flag)
           cout<<",";
           if(i&mask)
           cout<<"true";
           else
           cout<<"false";
           flag=1;
           mask>>=1;
        }
        cout<<">\n";
    }
    return len;

}