#include <iostream>
#include <string>
using namespace std;

/*map<string,Ring>M;
Ring Ring_Z;
M["Z"]=Ring_Z;

string s;
cin>>s;
Ring crt=M[s];*/
//operatiile sa fie aici definite
class Monoid
{
    int tip;
    string *elements;
    int cardinal;
    int **operationTable;

public:
    Monoid() : tip(0), elements(0), cardinal(0), operationTable(0) {}

    Monoid(const Monoid &monoid)
    {
        cardinal=monoid.cardinal;
        elements=new string[monoid.cardinal];
        for(int i=1;i<=monoid.cardinal;++i)
        {
            elements[i]=monoid.elements[i];
        }

        operationTable=new int*[monoid.cardinal];
        for(int i=1;i<=monoid.cardinal;++i)
        {
            operationTable[i]=new int[monoid.cardinal];
            for(int j=1;j<=monoid.cardinal;++j)
            {
                operationTable[i][j]=monoid.operationTable[i][j];
            }
        }
    }

    ~Monoid()
    {
        delete[] elements;
        if (operationTable != 0)
        {
            for (int i = 0; i < cardinal; ++i)
            {
                delete[] operationTable[i];
            }
            delete[] operationTable;
        }
    }

    int findNeutral()
    {
        int nrIndex_Neutral=-1;
        int indexNeutralElement;
        for(int i=1;i<=cardinal;++i)
        {
            bool neutral=1;
            for(int j=1;j<=cardinal;++j)
            {
                //cout<<corp.addtiveTable[i][j]<<"| "<<i<<" "<<j<<"\n";
                if(operationTable[i][j]!=j)
                    neutral=0;
            }
            if(neutral==1)
            {
                nrIndex_Neutral++;
                indexNeutralElement=i;
            }
        }
        return indexNeutralElement;
    }
    bool testAsociativity()
    {
        for(int a=1;a<=cardinal;++a)
        {
            for(int b=1;b<=cardinal;++b)
            {
                for(int c=1;c<=cardinal;++c)
                {
                    if(operationTable[operationTable[a][b]][c]!=operationTable[a][operationTable[b][c]])
                    {
                        cout<<"nu avem soc\n";
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
    bool existNeutral()
    {
        if(findNeutral()==-1)
            return 0;
        else
        {
            string neutralElement=elements[findNeutral()];
            int occurence=0;
            for(int i=1;i<=cardinal;++i)
            {
                if(elements[i]==neutralElement)
                    occurence++;
            }
            if(occurence>1)
            {
                cout<<"neutru";
                return 0;
            }
            else
                return 1;
        }
    }
    bool testInverseAdditive()
    {
        int index_elementNeutral=findNeutral();
        for(int i=1;i<=cardinal;++i)
        {
            int nr_neutral=0;
            for (int j=1;j<=cardinal;++j)
            {
                if(operationTable[i][j]==index_elementNeutral)
                {
                    cout<<elements[i]<<"+"<<elements[j]<<"="<<elements[operationTable[i][j]]<<"\n";
                    nr_neutral++;
                }
            }
            if (nr_neutral!=1)
            {
                cout<<"nu avem invers\n";
                return 0;
            }
        }
        return 1;
    }
    bool testInverseMultiplicative()
    {
        int k=1;
        int exclus;
        for(int i=1;i<=cardinal;++i)
        {
            for(int j=1;j<cardinal;++j)
            {
                if(operationTable[i][j]==operationTable[i][j+1])
                {
                    k++;
                }
            }
            if(k==cardinal)
            {
                exclus=i;
                break;
            }
        }
        int index_elementNeutral=findNeutral();

        cout<<exclus<<" "<<index_elementNeutral;
        for(int i=1;i<=cardinal;++i)
        {
            int nr_neutral=0;
            if(i!=exclus)
            {
                for (int j=1;j<=cardinal;++j)
                {
                    if(operationTable[i][j]==index_elementNeutral)
                    {
                        //cout<<elements[i]<<"+"<<elements[j]<<"="<<elements[operationTable[i][j]]<<"\n";
                        nr_neutral++;
                    }
                }
                if (nr_neutral!=1)
                {
                    cout<<"nu avem invers\n";
                    return 0;
                }
            }
        }
        return 1;
    }
    bool testGroup(int ordin)
    {
        if(ordin==0)
        {
            if(testAsociativity()==1 && existNeutral()==1 && testInverseAdditive()==1)
                return 1;
            else
                return 0;
        }
        else
        {
            if(testAsociativity()==1 && existNeutral()==1 && testInverseMultiplicative()==1)
                return 1;
            else
                return 0;
        }
    }

    friend istream& operator>>(istream& in, Monoid& monoid)
    {
        monoid.elements=new string[monoid.cardinal+1];
        for(int i=1;i<=monoid.cardinal;++i)
            in>>monoid.elements[i];

        monoid.operationTable=new int*[monoid.cardinal+1];

        for(int i=1;i<=monoid.cardinal;++i)
        {
            monoid.operationTable[i]=new int[monoid.cardinal+1];
            for(int j=1;j<=monoid.cardinal;++j)
            {
                in>>monoid.operationTable[i][j];
            }
        }
		//return in >> monoid.Name >> monoid.elements;
	}


    int getCardinal()
    {
        return cardinal;
    }

    void setCardinal(int nr)
    {
        cardinal=nr;
    }
	void printData()
	{
	    cout<<cardinal<<"\n";
	    for(int i=1;i<=cardinal;++i)
            cout<<elements[i]<<" ";

        cout<<"\n\n tabel \n";

        for(int i=1;i<=cardinal;++i)
        {
            for(int j=1;j<=cardinal;++j)
            {
                cout<<operationTable[i][j]<<" ";
            }
            cout<<"\n";
        }
	}
	int findIndex(string element)
	{
	    for(int i=1;i<=cardinal;++i)
        {
            if(element==elements[i])
                return i;
        }
        return -1;
	}

    string getNeutral()
    {
        if(existNeutral()==1)
        {
            return elements[findNeutral()];
        }
        else
            return 0;
    }
	int findIndexInverse(string element1)
	{
	    int index=findIndex(element1);
	    int neutral=findNeutral();
	    for(int i=1;i<=cardinal;++i)
        {
            if(operationTable[index][i]==neutral)
            {
                return i;
            }
        }
        return -1;
	}
	string operation(string element1, string element2)
	{
	    int index1=findIndex(element1);
	    int index2=findIndex(element2);
	    if(index1==-1 || index2==-1)
        {
            cout<<"Invalid input";
            return 0;
        }
        else
        {
            return elements[operationTable[index1][index2]];
        }
	}
	string inverseOperation(string element1,string element2)
	{
	    int index1=findIndex(element1);
	    int index2=findIndexInverse(element2);
	    if(index1==-1 || index2==-1)
        {
            cout<<"Invalid input";
            return 0;
        }
        else
        {
            return elements[operationTable[index1][index2]];
        }
	}
	int orderElement(string element)
	{
	    int index=findIndex(element);
	    int indexNeutral=findNeutral();
	    int ordAdunare=1;
	    int auxiliar=indexNeutral;
        while (operationTable[auxiliar][index]!=indexNeutral)
        {
            auxiliar=operationTable[auxiliar][index];
            ordAdunare++;
        }
        return ordAdunare;
	}
    int getType()
    {
        return tip;
    }

    string getInverse(string a)
    {
        return elements[findIndexInverse(a)];
    }





















	void getTable(int **table)
	{
	    for(int i=1;i<=cardinal;++i)
        {
            for(int j=1;j<=cardinal;++j)
            {
                table[i][j]=operationTable[i][j];
            }
        }

	}
	void setTable(int **table,int card)
	{
        for(int i=1;i<=cardinal;++i)
        {
            delete[] operationTable[i];
        }
        delete[] operationTable;
	    cardinal=card;
	    operationTable=new int*[card+1];
        for(int i=1;i<=card;++i)
        {
            operationTable[i]=new int[card+1];
            for(int j=1;j<=card;++j)
            {
                operationTable[i][j]=table[i][j];
                //cout<<operationTable[i][j]<<" ";
            }
            //cout<<"\n";
        }

	    /*for(int i=1;i<=card;++i)
        {
            for(int j=1;j<=card;++j)
            {
                operationTable[i][j]=table[i][j];
                cout<<"s";
            }
        }*/
	}
    void getElements(string *arrayElements)
	{
	    for(int i=1;i<=cardinal;++i)
        {
            arrayElements[i]=elements[i];
        }
        //arrayElements=elements;

	}
    void setElements(int card, string *arrayElements)
    {
        delete[] elements;
        //cout<<"AVEM\n";
        elements = new string[card+1];
        //elements=arrayElements;
        for(int i=1;i<=card;++i)
        {
            elements[i]=arrayElements[i];
            //cout<<elements[i]<<" si ";
        }
        //cout<<"\n";

    }
};



