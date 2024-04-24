#include <string>
#include "NrComplex.h"
using namespace std;


class ComplexCorp:public Corp
{
public:
    ComplexCorp()
    {
        setType(2);
    }
    ~ComplexCorp()
    {
        //cout<<"destruct";
    }
    void testIsEqual(Nrcomplex a,Nrcomplex b)
    {
        if(a.modul()<b.modul())
        {
            cout<<a<<"<"<<b;
        }
        else if(a.modul()>b.modul())
        {
            cout<<a<<">"<<b;
        }
        else if(a==b)
        {
            cout<<a<<"="<<b;
        }
    }
    void additionOperation(Nrcomplex a,Nrcomplex b)
    {
        Nrcomplex c;
        c=a+b;
        cout<<c;
    }
    void substractionOperation(Nrcomplex a, Nrcomplex b)
    {
        Nrcomplex c;
        c=a-b;
        cout<<c;
    }
    void multiplyOperation(Nrcomplex a,Nrcomplex b)
    {
        Nrcomplex c;
        c=a*b;
        cout<<c;
    }
    void divideOperation(Nrcomplex a,Nrcomplex b)
    {
        Nrcomplex c;
        c=a/b;
        cout<<a;
    }
    void inverseElement(Nrcomplex a)
    {
        double real=a.getReal();
        double imaginar=a.getImaginar();
        cout<<real*(-1)<<" and "<<imaginar*(-1)<<"\n";
        Nrcomplex b(real/(real*real+imaginar*imaginar),imaginar/(real*real+imaginar*imaginar));
        cout<<b;
    }
    void neutralsElements()
    {
        cout<<0<<" and "<<1;
    }
    void orderElement(Nrcomplex a)
    {
        cout<<"Nu avem ordine";
    }
};


