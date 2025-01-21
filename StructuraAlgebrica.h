#ifndef STRUCTURAALGEBRIC_H_
#define STRUCTURAALGEBRIC_H_

//abstract class
#include <string>
#include "monoid.h"
using namespace std;

/*map<string,Ring>M;
Ring Ring_Z;
M["Z"]=Ring_Z;

string s;
cin>>s;
Ring crt=M[s];*/

int extractNumber(string &str)
{
    int number=0;
    char s[str.length() + 1];
    strcpy(s, str.c_str());
    for(int i=2;s[i]!=0;++i)
    {
        if(isdigit(s[i])==1)
            number=number*10+(s[i]-'0');
    }
    cout<<s<<" | "<<number<<" "<<typeid(number).name()<<"\n";
    return number;
}
bool prim(int x)
{
    int d;
    if (x < 2)
    {
        return 0;
    }
    if (x == 2)
    {
        return 1;
    }
    if (x % 2 == 0)
    {
        return 0;
    }
    for (d = 3; d * d <= x; d += 2)
    {
        if (x % d == 0)
        {
            return 0;
        }
    }
    return 1;
}
class StructuraAlgebrica
{
protected:
    string nume;
    int cardinal;
    int type=0;
    string *elements;
    Monoid monoid2;//multiply
    Monoid monoid1;
public:

    StructuraAlgebrica()
    {
        nume="";
        cardinal=0;
        type=0;
    }

    StructuraAlgebrica(const StructuraAlgebrica &stralg)
    {
        cardinal=stralg.cardinal;
        //elments=stralg.elements;
        monoid1=stralg.monoid1;
        monoid2=stralg.monoid2;
    }
    ~StructuraAlgebrica()
    {

    }
    virtual void printData()=0;

    string getNume() const {
        return nume;
    }
    virtual bool test
    {
        if(monoid1.testGroup(0)==0)
            return 0;
        return 1;
    }
    virtual void TestCast()
    {
        cout<<"Avem - structura\n";
    }
    void setNume(const string& newNume) {
        nume = newNume;
    }

    void getMonoid1(int card, int type, int **table)
    {
        monoid1.getTable(table);
    }

    void setMonoid1(const Monoid& newMonoid1) {
        monoid1 = newMonoid1;
    }

    void getMonoid2(int **table)
    {
        monoid2.getTable(table);
    }

    void setMonoid2(const Monoid& newMonoid2) {
        monoid2 = newMonoid2;
    }
    int getCardinal()
    {
        return cardinal;
    }
    void setCardinal(const int& newcard) {
        cardinal = newcard;
    }
    void setOpTable(int **table1,int **table2, int card)
    {
        monoid1.setTable(table1, card);
        monoid2.setTable(table2, card);
    }
    void getElements(int &card, string *arrayElements)
    {
        monoid1.getElements(arrayElements);
    }
    void setElements(string *elements, int card)
    {
        monoid1.setElements(card,elements);
        monoid2.setElements(card,elements);
    }

    void setType(int tip){type=tip;}
    int getType(){return type;}

    friend istream& operator>>(istream& in, StructuraAlgebrica& ring)
    {
		in >> ring.nume;
		if(ring.nume.substr(0,2)=="Z/")
        {
            cout<<"Ajungi aici";
            ring.setCardinal(extractNumber(ring.nume));
            ring.setType(0);
            cout<<ring.type<<" "<<ring.cardinal;
            ring.monoid1.setCardinal(ring.cardinal);
            ring.monoid2.setCardinal(ring.cardinal);

            /*int n=ring.cardinal;
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
            ring.monoid1.setTable(table1,ring.cardinal);
            ring.monoid2.setTable(table2,ring.cardinal);*/
        }
        else if(ring.nume=="Q")
        {
            ring.setCardinal(-1);
            ring.setType(1);
        }
        else if(ring.nume=="R" || ring.nume=="C")
        {
            ring.setCardinal(-1);
            ring.setType(2);
        }
        else
        {
            in >> ring.cardinal;
            ring.monoid1.setCardinal(ring.cardinal);
            ring.monoid2.setCardinal(ring.cardinal);
            in >> ring.monoid1;
            in >> ring.monoid2;
        }
	}

};

#endif // STRUCTURAALGEBRIC_H_

