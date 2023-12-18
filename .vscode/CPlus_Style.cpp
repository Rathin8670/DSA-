#include<iostream>
using namespace std;
class rectangle{
    public:
    int len;
    int bred;

    void initialize(int l,int b){
        len=l;
        bred=b;
    }
    int area(){
        return len*bred;
    }
    int perimeter(){
        return 2*(len+bred);
    }

};
int main(){
    rectangle r;
    int l,b;
    cout<<"enter length and breadth"<<endl;
    cin>>l>>b;
    r.initialize(l,b);
    int a=r.area();
    int peri=r.perimeter();
    
    cout<<"area="<<a<<endl<<"perimeter="<<peri;
    return 0;
 
}