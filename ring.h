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
string intToString(int n)
{
    string str;
    stringstream ss;
    ss<<n;
    str=ss.str();
    return str;

}
class Ring
{
    string nume;
    int cardinal;
    int type=0;
    Monoid monoid1;
    Monoid monoid2;
public:

    Ring()
    {
        nume="";
        cardinal=0;
        type=0;
    }

    Ring(const Ring &ring)
    {
        cardinal=ring.cardinal;
        monoid1=ring.monoid1;
        monoid2=ring.monoid2;
    }
    ~Ring()
    {
        //cout<<"destruct";
    }
    void printData()
    {
        cout<<nume<<"\n";
        monoid1.printData();
        cout<<"\n";
        monoid2.printData();
        cout<<"\n";
    }

	/*
	friend ostream& operator<<(ostream& out, vehicul& v) {
		return out << v.vx;
	}*/
    bool testCorp()
    {
        if(monoid1.testGroup(0)==1 and monoid2.testGroup(1)==1)
            return 1;
        else
            return 0;
    }
    string getNume() const {
        return nume;
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
    virtual string additionOperation(string a,string b)
    {
        return monoid1.operation(a,b);
    }
    virtual string substractionOperation(string a,string b)
    {
        return monoid1.inverseOperation(a,b);
    }
    virtual string multiplyOperation(string a,string b)
    {
        return monoid2.operation(a,b);
    }
    virtual string divideOperation(string a,string b)
    {
        return monoid2.inverseOperation(a,b);
    }
    virtual void neutralsElements()
    {
        cout<<monoid1.getNeutral()<<" and ";

        cout<<monoid2.getNeutral();
    }
    virtual void inverseElement(string a)
    {
        cout<<monoid1.getInverse(a)<<" and ";
        if(a!=monoid1.getNeutral())
            cout<<monoid2.getInverse(a);
        else
            cout<<"nu exista";
    }
    virtual void orderElement(string a)
    {
        cout<<monoid1.orderElement(a)<<" and "<<monoid2.orderElement(a);
    }
    virtual void testIsEqual(string a, string b)
    {
        if(a!=b)
        {
            cout<<"Nu sunt egale";
        }
        else
            cout<<"Sunt egale";
    }
    void setType(int tip){type=tip;}
    int getType(){return type;}

    friend istream& operator>>(istream& in, Ring& ring)
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


