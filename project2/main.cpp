#include <iostream>

using namespace std;

int main() {
    
    int num1 {100};
    int num2 {200};
    
    num2 = num1=10000;
    
    cout<<"num 1 is"<<num1<<endl;
    cout<<"num 2 is"<<num2<<endl;  
    
    cout<<endl;
    return 0;
    
}