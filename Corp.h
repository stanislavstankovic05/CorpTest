#include <string>

class Corp:public Ring
{
public:
    Corp()
    {
        setCardinal(0);
        setType(0);
        setNume("");
    }
    ~Corp()
    {
        //cout<<"destruct";
    }
    Ring operator=(Ring &b)
    {
        int card,type;
        card=b.getCardinal();
        int **table1;
        table1 = new int*[card+1];
        for(int i=1;i<=card;++i)
        {
            table1[i]=new int[card+1];
        }
        b.getMonoid1(card,type,table1);
        int **table2;
        table2 = new int*[card+1];
        for(int i=1;i<=card;++i)
        {
            table2[i]=new int[card+1];
        }
        b.getMonoid2(table2);

        string *elements=new string[card+1];

        b.getElements(card,elements);
        setCardinal(card);
        setNume(b.getNume());
        setElements(elements,card);
        setOpTable(table1,table2,card);
        setType(0);
        for (int i = 0; i <=card; ++i)
                    {
                        delete[] table1[i];
                        delete[] table2[i];
                    }
                    delete[] table1;
                    delete[] table2;

                    table1 = 0;
                    table2 = 0;
    }

    bool operator==(Corp &b)
    {
        int card=getCardinal();
        int tip=getType();
        cout<<"Tipuri :"<<tip<<" | "<<b.getType()<<"\n\\";
        cout<<"Nume :"<<getNume()<<" | "<<b.getNume()<<"\n\\";
        /*for(int i=1;i<=card;++i)
        {
            for (int j=1;j<=b.getCardinal();++j)
            {
                cout<<tableA1[i][j]<<" ";
            }
            cout<<"\n";
        }*/
        if(tip!=b.getType())
        {
            return 0;
        }
        else if(tip==2 and b.getType()==2)
        {
            if(card==b.getCardinal())
            {
                return 1;
                cout<<"Sunt izomorfe1";
            }
            else
            {
                cout<<"Nu sunt izomorfe1";
                return 0;
            }
        }
        else if(tip==0 and b.getType()==0)
        {
            int **tableA1,**tableB1;
            int **tableA2,**tableB2;
            tableA1 = new int*[card+1];
            tableA2 = new int*[card+1];
            tableB1 = new int*[card+1];
            tableB2 = new int*[card+1];
            for(int i=1;i<=card;++i)
            {
                tableA1[i]=new int[card+1];
                tableA2[i]=new int[card+1];
                tableB1[i]=new int[card+1];
                tableB2[i]=new int[card+1];
            }
            int tip=getType();
            getMonoid1(card,tip,tableA1);
            getMonoid2(tableA2);
            b.getMonoid1(card,tip,tableB1);
            b.getMonoid2(tableB2);

            if(card!=b.getCardinal())
            {
                cout<<"Corpurile nu sunt izomorfe2";
                return 0;
            }
            int line_found=0;
            bool test1=0;
            bool gasit=0;
            for(int i=1;i<=card;++i)
            {
                gasit=1;
                for (int j=1;j<=b.getCardinal();++j)
                {
                    gasit=1;
                    for(int k=1;k<=b.getCardinal();++k)
                    {
                        if(tableA1[i][k]!=tableB1[j][k]
                                       || tableA2[i][k]!=tableB2[j][k])
                                       gasit=0;
                    }
                    if(gasit=1)
                    {
                        line_found++;
                        break;
                    }
                }
            }
            if (tableA1 != 0)
            {
                for (int i = 0; i <= b.getCardinal(); ++i)
                {
                    delete[] tableA1[i];
                }
                delete[] tableA1;
            }
            if (tableA2 != 0)
            {
                for (int i = 0; i <= b.getCardinal(); ++i)
                {
                    delete[] tableA2[i];
                }
                delete[] tableA1;
            }
            if (tableB1 != 0)
            {
                for (int i = 0; i <= b.getCardinal(); ++i)
                {
                    delete[] tableB1[i];
                }
                delete[] tableB1;
            }
            if (tableB2!= 0)
            {
                for (int i = 0; i <= b.getCardinal(); ++i)
                {
                    delete[] tableB2[i];
                }
                delete[] tableB2;
            }
                if (line_found!=card)
            {
                cout<<"Corpurile date nu sunt izomorfe2";
                return 0;
            }
            else
            {
                cout<<"Corpurile sunt izomorfe2";
                return 1;
            }
        }
        /*else if(tip!=2 || b.getType()!=2 and card!=b.getCardinal())
        {
                    cout<<"Nu sunt izomorfe3";
                    return 0;
        }*/
        else
            return 0;
        return 1;
    }
    bool operator!=(Corp &b)
    {
        if(*this==b)
        {
            return 0;
        }
        else
            return 1;
    }
};


