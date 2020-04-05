#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int num;
    while(cin>>num){
        if(num==42)break;
        cout<<num<<endl;
    }

    return 0;
}
