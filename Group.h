#ifndef GROUP_H_
#define GROUP_H_
#include <iostream>
#include <string>
#include "monoid.h"
using namespace std;

/*map<string,Ring>M;
Ring Ring_Z;
M["Z"]=Ring_Z;

string s;
cin>>s;
Ring crt=M[s];*/
//operatiile sa fie aici definite
class Group: public Monoid
{


public:
    //Group() : tip(0), elements(0), cardinal(0), operationTable(0) {}
    Group()
    {

    }
    Group(Monoid &monoid)
    {
        monoid.printData();
        cout<<"start";
        //cardinal=monoid.getCardinal();
        setCardinal(monoid.getCardinal());
        /*elements=new string[monoid.getCardinal()];
        for(int i=1;i<=monoid.getCardinal()l;++i)
        {
            elements[i]=monoid.elements[i];
        }*/
        string addElements[monoid.getCardinal()+1];
        monoid.getElements(addElements);
        cout<<getCardinal();
        for(int i=1;i<=getCardinal();++i)
        {
            cout<<addElements[i]<<" ";
        }

        setElements(monoid.getCardinal(), addElements);

        cout<<"aici";
        //operationTable=new int*[monoid.getCardinal()];
        int card=monoid.getCardinal();
        int **table;
        table=new int*[card+1];
        for(int i=1;i<=card;++i)
        {
            table[i]=new int[card+1];
            //cout<<"\n";
        }
        monoid.getTable(table);

        setTable(table, monoid.getCardinal());
        cout<<"aici";
        /*for(int i=1;i<=monoid.getCardinal();++i)
        {
            operationTable[i]=new int[monoid.getCardinal()];
            for(int j=1;j<=monoid.getCardinal();++j)
            {
                operationTable[i][j]=monoid.operationTable[i][j];
            }
        }*/
    }

    ~Group()
    {
        /*delete[] elements;
        if (operationTable != 0)
        {
            for (int i = 0; i < cardinal; ++i)
            {
                delete[] operationTable[i];
            }
            delete[] operationTable;
        }*/
        //this.~Monoid();
    }

    int findIndexInverse(string element1)
	{
	    string *addElements=new string[getCardinal()];
        int card=getCardinal();
        getElements(addElements);

        //operationTable=new int*[monoid.getCardinal()];

        int **table;
        table=new int*[card+1];
        for(int i=1;i<=card;++i)
        {
            table[i]=new int[card+1];
            //cout<<"\n";
        }
        getTable(table);

	    int index=findIndex(element1);
	    int neutral=findNeutral();
	    for(int i=1;i<=getCardinal();++i)
        {
            if(table[index][i]==neutral)
            {
                return i;
            }
        }
        return -1;
	}
    void printDataG()
	{
	    cout<<"grupul: ";
	    printData();
	}

};
#endif // GROUP_H_




