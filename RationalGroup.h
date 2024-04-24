#include <string>
using namespace std;


class RationalGroup:public Corp
{
public:
    RationalGroup()
    {
        setType(1);
    }
    ~RationalGroup()
    {
        //cout<<"destruct";
    }
    void testIsEqual(double a,double b)
    {
        if(a<b)
        {
            cout<<a<<"<"<<b;
        }
        else if(a>b)
        {
            cout<<a<<">"<<b;
        }
        else if(a==b)
        {
            cout<<a<<"="<<b;
        }
    }
    void additionOperation(double a,double b)
    {
        cout<<a+b;
    }
    void substractionOperation(double a, double b)
    {
        cout<<(a-b);
    }
    void multiplyOperation(double a,double b)
    {
        cout<<a*b;
    }
    void divideOperation(double a,double b)
    {
        cout<<(a/b);
    }
    void inverseElement(double a)
    {
        cout<<a*(-1)<<" and "<<1/a;
    }
    void neutralsElements()
    {
        cout<<0<<" and "<<1;
    }
    void orderElement(double a)
    {
        cout<<"Nu avem ordine";
    }
};


