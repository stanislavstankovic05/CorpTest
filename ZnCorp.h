#include <string>
using namespace std;


class ZnCorp:public Corp
{
public:
    ZnCorp()
    {
        setType(0);
    }
    ZnCorp(int n)
    {
        setType(2);
        setCardinal(n);
    }
    ZnCorp(ZnCorp &z)
    {
        setCardinal(z.getCardinal());
        /*setMonoid1(z.getMonoid1());
        setMonoid2(z.getMonoid2());*/
    }
    ~ZnCorp()
    {
        //cout<<"destruct";
    }
    void setElementsZ()
    {
        int card=getCardinal();
        string *elementZ=new string[card+1];
        for(int index=1;index<=card;++index)
        {
            elementZ[index]=intToString(index-1);
        }
        setElements(elementZ,card);
    }
    void setTable()
    {
        int n=getCardinal();
        int **table1=new int*[n+1];
        int **table2=new int*[n+1];

        for(int j=1;j<=n;++j)
        {
            table1[j]=new int[n+1];
            table2[j]=new int[n+1];
        }

        for(int index=1;index<=n;++index)
        {
            for(int j=1;j<=n;++j)
            {
                //fout<<"cava\n";
                //fout<<((i-1)+(j-1))%n+1<<" ";
                table1[index][j]=((index-1)+(j-1))%n+1;
                table2[index][j]=((index-1)*(j-1))%n+1;
            }
        }
        setOpTable(table1,table2,n);
    }
    void testIsEqual(int a,int b)
    {
        int n=getCardinal();
        if(a%n<b%n)
        {
            cout<<a<<"<"<<b;
        }
        else if(a%n>b%n)
        {
            cout<<a<<">"<<b;
        }
        else if(a%n==b%n)
        {
            cout<<a<<"="<<b;
        }
    }
    void additionOperation(int a, int b)
    {
        cout<<(a+b)% getCardinal();
    }
    void substractionOperation(int a, int b)
    {
        cout<<(a-b)% getCardinal();
    }
    void divideOperation(int a, int b)
    {
        int k=1;
        while((b*k)%getCardinal()!=1)
            k++;
        cout<<(a*b)% getCardinal();
    }
    void multiplyOperation(int a, int b)
    {
        cout<<(a*b)% getCardinal();
    }
    void neutralsElements()
    {
        cout<<0<<" and "<<1;
    }
    void inverseElement(int a)
    {
        int k=1;
        int q=0;
        a=a%getCardinal();
        while((a*k)%getCardinal()!=1)
            k++;

        while((a+q)%getCardinal()!=0)
            q++;
        cout<<(q)%getCardinal()<<" and "<<k;
    }
    void orderElement(int a)
    {
        int k=1;
        int q=1;
        int current1=a;
        int current2=a;
        while(current1!=0)
        {
            k++;
            current1+=a;
            current1%=getCardinal();
            //cout<<getCardinal()<<" ";
            //cout<<k<<"\n";
        }
        while(current2!=1)
        {
            q++;
            current2*=a;
            current2%=getCardinal();
        }
        cout<<k<<" and "<<q;
    }
    void TestCast()
    {
        cout<<"Z/n - corp\n";
    }
};
