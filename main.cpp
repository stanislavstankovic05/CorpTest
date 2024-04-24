#include <bits/stdc++.h>
#include <string>
#include <conio.h>
#include <typeinfo>
#include <sstream>
#include "ring.h"
#include "display.h"
#include "Corp.h"
#include "ZnCorp.h"
#include "RealCorp.h"
#include "RationalGroup.h"
#include "ComplexGroup.h"

#define upkey 72
#define downkey 80
#define enterkey 13
#define NMAX 101
using namespace std;

//ofstream fout("output.out");



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

void openFileInput();
void ConsoleInput();
void tutorialInput(int optionSelected);
void redirection_Menu(int optionSelected)
{
    switch (optionSelected)
    {
        case 1:
            openFileInput();
            break;

        case 2:
            ConsoleInput();
            break;

        case 3:
            tutorialInput(optionSelected);
            break;

        case 4:
            exit(0);
            break;
    }
}

void testCorp(Ring ring[],int nr_ring, Corp corp[], int nr_corp)
{
    if (nr_corp==0)
    {
        cout<<"Multimile cu legile de compozitie date nu formeaza o structura de corp \n";
        //return;
    }
    else
    {
        cout<<"Selecteaza inelul pe care vrei sa il testati:\n";
        //cout<<nr_corp<<"\n";
        for(int i=1;i<=nr_ring;++i)
        {
            cout<<ring[i].getNume()<<" ";
        }
        /*for(int i=1;i<=nr_corp;++i)
        {
            cout<<corp[i].getNume()<<" ";
        }*/
        cout<<"\n";
        string choice;
        cin>>choice;
        int index=0;
        for(int i=1;i<=nr_ring;++i)
        {
            if(ring[i].getNume()==choice)
            {
                index=i;
                break;
            }
        }
        if(index==0)
        {
            cout<<"Invalid input";
            return;
        }
        else
        {
            bool found=0;
            for(int i=1;i<=nr_corp;++i)
            {
                if(corp[i].getNume()==ring[index].getNume())
                {
                    found=1;
                    break;
                }
            }
            /*if(ring[index].testCorp()==1)
                cout<<"Este corp";
            else
                cout<<"Nu este corp";*/
            if(found==1)
                cout<<"Este corp";
            else
                cout<<"Nu este corp";
        }

    }
}
void addition(Ring ring[],int nr_ring, Corp corp[], int nr_corp, RationalGroup rationalCorp, ComplexCorp complexCorp, RealGroup realCorp, ZnCorp znCorp[],int nr_Zn)
{
    cout<<"Selecteaza inelul pe care vrei sa il testati:\n";
    //cout<<nr_corp<<"\n";
    for(int i=1;i<=nr_corp;++i)
    {
        cout<<corp[i].getNume()<<" ";
    }
    cout<<"\n";
    string choice;
    cin>>choice;
    int index=0;
    for(int i=1;i<=nr_corp;++i)
    {
        if(corp[i].getNume()==choice)
            index=i;
    }
    if(index==0)
    {
        cout<<"Invalid input";
    }
    else
    {
        //cout<<corp[index].getType()<<" ";
        if(corp[index].getNume()=="Q")
        {
            double a,b;
            cin>>a>>b;
            rationalCorp.additionOperation(a,b);
        }
        if(corp[index].getNume()=="R")
        {
                double a,b;
                cin>>a>>b;
                realCorp.additionOperation(a,b);
        }
        else if(corp[index].getNume()=="C")
        {
            Nrcomplex a,b;
            cin>>a>>b;
            complexCorp.additionOperation(a,b);
        }
        else if(corp[index].getNume().substr(0,2)=="Z/")
        {
            int indexZ=0;
            for(int i=1;i<=nr_Zn;++i)
            {
                if(znCorp[i].getNume()==corp[index].getNume())
                {
                    indexZ=i;
                    break;
                }
            }
            int a,b;
            cin>>a>>b;
            znCorp[indexZ].additionOperation(a,b);
        }
        else if(corp[index].getType()==0)
        {
            cout<<"Selecteaza elementele pentru operatia de adunare:\n";
            int card=corp[index].getCardinal();
            string *elements=new string[card+1];

            corp[index].getElements(card,elements);

            for(int i=1;i<=card;++i)
                cout<<elements[i]<<" ";
            cout<<"\n";
            string a,b;
            cin>>a>>b;
            cout<<corp[index].additionOperation(a,b)<<"\n";
        }
    }
}
void multiply(Ring ring[],int nr_ring, Corp corp[], int nr_corp, RationalGroup rationalCorp, ComplexCorp complexCorp, RealGroup realCorp, ZnCorp znCorp[],int nr_Zn)
{
    cout<<"Selecteaza inelul pe care vrei sa il testati:\n";
    //cout<<nr_corp<<"\n";
    for(int i=1;i<=nr_corp;++i)
    {
        cout<<corp[i].getNume()<<" ";
    }
    cout<<"\n";
    string choice;
    cin>>choice;
    int index=0;
    for(int i=1;i<=nr_corp;++i)
    {
        if(corp[i].getNume()==choice)
            index=i;
    }
    if(index==0)
    {
        cout<<"Invalid input";
    }
    else
    {
        if(corp[index].getNume()=="Q")
        {
            double a,b;
            cin>>a>>b;
            rationalCorp.multiplyOperation(a,b);
        }
        if(corp[index].getNume()=="R")
        {
                double a,b;
                cin>>a>>b;
                realCorp.multiplyOperation(a,b);
        }
        else if(corp[index].getNume()=="C")
        {
            Nrcomplex a,b;
            cin>>a>>b;
            complexCorp.multiplyOperation(a,b);
        }
        else if(corp[index].getNume().substr(0,2)=="Z/")
        {
            int indexZ=0;
            for(int i=1;i<=nr_Zn;++i)
            {
                if(znCorp[i].getNume()==corp[index].getNume())
                {
                    indexZ=i;
                    break;
                }
            }
            int a,b;
            cin>>a>>b;
            znCorp[indexZ].multiplyOperation(a,b);
        }
        else if(corp[index].getType()==0)
        {
            cout<<"Selecteaza elementele pentru operatia de inmultire:\n";
            int card=corp[index].getCardinal();
            string *elements=new string[card+1];

            corp[index].getElements(card,elements);

            for(int i=1;i<=card;++i)
                cout<<elements[i]<<" ";
            cout<<"\n";
            string a,b;
            cin>>a>>b;
            cout<<a<<" * "<<b<<" = "<<corp[index].multiplyOperation(a,b)<<"\n";
            delete[] elements;
        }
    }
}
void findNeutrals(Ring ring[],int nr_ring, Corp corp[], int nr_corp, RationalGroup rationalCorp, ComplexCorp complexCorp, RealGroup realCorp, ZnCorp znCorp[],int nr_Zn)
{
    cout<<"Selecteaza inelul pe care vrei sa il testati:\n";
    //cout<<nr_corp<<"\n";
    for(int i=1;i<=nr_corp;++i)
    {
        cout<<corp[i].getNume()<<" ";
    }
    cout<<"\n";
    string choice;
    cin>>choice;
    int index=0;
    for(int i=1;i<=nr_corp;++i)
    {
        if(corp[i].getNume()==choice)
            index=i;
    }
    if(index==0)
    {
        cout<<"Invalid input";
    }
    else
    {
        if(corp[index].getNume()=="Q")
        {
            rationalCorp.neutralsElements();
        }
        if(corp[index].getNume()=="R")
        {
            realCorp.neutralsElements();
        }
        else if(corp[index].getNume()=="C")
        {
            complexCorp.neutralsElements();
        }
        else if(corp[index].getNume().substr(0,2)=="Z/")
        {
            int indexZ=0;
            for(int i=1;i<=nr_Zn;++i)
            {
                if(znCorp[i].getNume()==corp[index].getNume())
                {
                    indexZ=i;
                    break;
                }
            }
            znCorp[indexZ].neutralsElements();
        }
        else if(corp[index].getType()==0)
        {
            corp[index].neutralsElements();
        }
    }
}
void inverse(Ring ring[],int nr_ring, Corp corp[], int nr_corp, RationalGroup rationalCorp, ComplexCorp complexCorp, RealGroup realCorp, ZnCorp znCorp[],int nr_Zn)
{
    cout<<"Selecteaza inelul pe care vrei sa il testati:\n";
    //cout<<nr_corp<<"\n";
    for(int i=1;i<=nr_corp;++i)
    {
        cout<<corp[i].getNume()<<" ";
    }
    cout<<"\n";
    string choice;
    cin>>choice;
    int index=0;
    for(int i=1;i<=nr_corp;++i)
    {
        if(corp[i].getNume()==choice)
            index=i;
    }
    if(index==0)
    {
        cout<<"Invalid input";
    }
    else
    {
        if(corp[index].getNume()=="Q")
        {
            double a,b;
            cin>>a;
            rationalCorp.inverseElement(a);
        }
        if(corp[index].getNume()=="R")
        {
                double a,b;
                cin>>a;
                realCorp.inverseElement(a);
        }
        else if(corp[index].getNume()=="C")
        {
            Nrcomplex a;
            cin>>a;
            complexCorp.inverseElement(a);
        }
        else if(corp[index].getNume().substr(0,2)=="Z/")
        {
            int indexZ=0;
            for(int i=1;i<=nr_Zn;++i)
            {
                if(znCorp[i].getNume()==corp[index].getNume())
                {
                    indexZ=i;
                    break;
                }
            }
            int a;
            cin>>a;
            znCorp[indexZ].inverseElement(a);
        }
        else if(corp[index].getType()==0)
        {
            cout<<"Selecteaza elementul:\n";
            int card=corp[index].getCardinal();
            string *elements=new string[card+1];

            corp[index].getElements(card,elements);

            for(int i=1;i<=card;++i)
                cout<<elements[i]<<" ";
            cout<<"\n";
            string a;
            cin>>a;
            corp[index].inverseElement(a);
            delete[] elements;
        }
    }
}
void ordin(Ring ring[],int nr_ring, Corp corp[], int nr_corp, RationalGroup rationalCorp, ComplexCorp complexCorp, RealGroup realCorp, ZnCorp znCorp[],int nr_Zn)
{
    cout<<"Selecteaza inelul pe care vrei sa il testati:\n";
    //cout<<nr_corp<<"\n";
    for(int i=1;i<=nr_corp;++i)
    {
        cout<<corp[i].getNume()<<" ";
    }
    cout<<"\n";
    string choice;
    cin>>choice;
    int index=0;
    for(int i=1;i<=nr_corp;++i)
    {
        if(corp[i].getNume()==choice)
            index=i;
    }
    if(index==0)
    {
        cout<<"Invalid input";
    }
    else
    {
        if(corp[index].getNume()=="Q")
        {
            double a;
            cin>>a;
            rationalCorp.orderElement(a);
        }
        if(corp[index].getNume()=="R")
        {
            double a;
            cin>>a;
            realCorp.orderElement(a);
        }
        else if(corp[index].getNume()=="C")
        {
            Nrcomplex a;
            complexCorp.orderElement(a);
        }
        else if(corp[index].getNume().substr(0,2)=="Z/")
        {
            int indexZ=0;
            for(int i=1;i<=nr_Zn;++i)
            {
                if(znCorp[i].getNume()==corp[index].getNume())
                {
                    indexZ=i;
                    break;
                }
            }
            int a;
            cin>>a;
            znCorp[indexZ].orderElement(a);
        }
        else if(corp[index].getType()==0)
        {
            cout<<"Selecteaza elementul:\n";
            int card=corp[index].getCardinal();
            string *elements=new string[card+1];

            corp[index].getElements(card,elements);

            for(int i=1;i<=card;++i)
                cout<<elements[i]<<" ";
            cout<<"\n";
            string a;
            cin>>a;
            corp[index].orderElement(a);
            delete[] elements;
        }
    }
}
void deduction(Ring ring[],int nr_ring, Corp corp[], int nr_corp, RationalGroup rationalCorp, ComplexCorp complexCorp, RealGroup realCorp, ZnCorp znCorp[],int nr_Zn)
{
    cout<<"Selecteaza inelul pe care vrei sa il testati:\n";
    //cout<<nr_corp<<"\n";
    for(int i=1;i<=nr_corp;++i)
    {
        cout<<corp[i].getNume()<<" ";
    }
    cout<<"\n";
    string choice;
    cin>>choice;
    int index=0;
    for(int i=1;i<=nr_corp;++i)
    {
        if(corp[i].getNume()==choice)
            index=i;
    }
    if(index==0)
    {
        cout<<"Invalid input";
    }
    else
    {
        if(corp[index].getNume()=="Q")
        {
            double a,b;
            cin>>a>>b;
            rationalCorp.substractionOperation(a,b);
        }
        if(corp[index].getNume()=="R")
        {
                double a,b;
                cin>>a>>b;
                realCorp.substractionOperation(a,b);
        }
        else if(corp[index].getNume()=="C")
        {
            Nrcomplex a,b;
            cin>>a>>b;
            complexCorp.substractionOperation(a,b);
        }
        else if(corp[index].getNume().substr(0,2)=="Z/")
        {
            int indexZ=0;
            for(int i=1;i<=nr_Zn;++i)
            {
                if(znCorp[i].getNume()==corp[index].getNume())
                {
                    indexZ=i;
                    break;
                }
            }
            int a,b;
            cin>>a>>b;
            znCorp[indexZ].multiplyOperation(a,b);
        }
        else if(corp[index].getType()==0)
        {
            cout<<"Selecteaza elementele pentru operatia de scadere:\n";
            int card=corp[index].getCardinal();
            string *elements=new string[card+1];

            corp[index].getElements(card,elements);

            for(int i=1;i<=card;++i)
                cout<<elements[i]<<" ";
            cout<<"\n";
            string a,b;
            cin>>a>>b;
            cout<<a<<" - "<<b<<" = "<<corp[index].substractionOperation(a,b)<<"\n";
            delete[] elements;
        }
    }
}
void division(Ring ring[],int nr_ring, Corp corp[], int nr_corp, RationalGroup rationalCorp, ComplexCorp complexCorp, RealGroup realCorp, ZnCorp znCorp[],int nr_Zn)
{
    cout<<"Selecteaza inelul pe care vrei sa il testati:\n";
    //cout<<nr_corp<<"\n";
    for(int i=1;i<=nr_corp;++i)
    {
        cout<<corp[i].getNume()<<" ";
    }
    cout<<"\n";
    string choice;
    cin>>choice;
    int index=0;
    for(int i=1;i<=nr_corp;++i)
    {
        if(corp[i].getNume()==choice)
            index=i;
    }
    if(index==0)
    {
        cout<<"Invalid input";
    }
    else
    {
        if(corp[index].getNume()=="Q")
        {
            double a,b;
            cin>>a>>b;
            rationalCorp.divideOperation(a,b);
        }
        if(corp[index].getNume()=="R")
        {
                double a,b;
                cin>>a>>b;
                realCorp.divideOperation(a,b);
        }
        else if(corp[index].getNume()=="C")
        {
            Nrcomplex a,b;
            cin>>a>>b;
            complexCorp.divideOperation(a,b);
        }
        else if(corp[index].getNume().substr(0,2)=="Z/")
        {
            int indexZ=0;
            for(int i=1;i<=nr_Zn;++i)
            {
                if(znCorp[i].getNume()==corp[index].getNume())
                {
                    indexZ=i;
                    break;
                }
            }
            int a,b;
            cin>>a>>b;
            znCorp[indexZ].divideOperation(a,b);
        }
        else if(corp[index].getType()==0)
        {
            cout<<"Selecteaza elementele pentru operatia de impartire:\n";
            int card=corp[index].getCardinal();
            string *elements=new string[card+1];

            corp[index].getElements(card,elements);

            for(int i=1;i<=card;++i)
                cout<<elements[i]<<" ";
            cout<<"\n";
            string a,b;
            cin>>a>>b;
            cout<<a<<" / "<<b<<" = "<<corp[index].divideOperation(a,b)<<"\n";
            delete[] elements;
        }
    }
}
void testIzomorfism(Ring ring[], int nr_ring, Corp corp[], int nr_corp)
{
    if (nr_corp==0)
    {
        cout<<"Multimile cu legile de compozitie date nu formeaza o structura de corp \n";
        //return;
    }
    else
    {
        cout<<"Selecteaza inelul pe care vrei sa il testati:\n";
        //cout<<nr_corp<<"\n";
        for(int i=1;i<=nr_corp;++i)
        {
            cout<<corp[i].getNume()<<" ";
        }
        cout<<"\n";
        string choice1,choice2;
        cin>>choice1>>choice2;
        int index1=0;
        int index2=0;
        for(int i=1;i<=nr_corp;++i)
        {
            if(corp[i].getNume()==choice1)
            {
                index1=i;
            }
            else if(corp[i].getNume()==choice2)
                index2=i;
        }
        if(index1==0 || index2==0)
        {
            cout<<"Invalid input";
        }
        else
        {
            cout<<"Corpurile ";
            cout<<corp[index1].getType()<<" "<<corp[index2].getType()<<"\n";
            if(corp[index1]==corp[index2])
            {
                cout<<"Sunt izomorfe";
            }
            else
            {
                cout<<"Nu sunt izomorfe";
            }
        }

    }
}
void testEgalitate(Ring ring[],int nr_ring, Corp corp[], int nr_corp, RationalGroup rationalCorp, ComplexCorp complexCorp, RealGroup realCorp, ZnCorp znCorp[],int nr_Zn)
{
    cout<<"Selecteaza inelul pe care vrei sa il testati:\n";
    //cout<<nr_corp<<"\n";
    for(int i=1;i<=nr_corp;++i)
    {
        cout<<corp[i].getNume()<<" ";
    }
    cout<<"\n";
    string choice;
    cin>>choice;
    int index=0;
    for(int i=1;i<=nr_corp;++i)
    {
        if(corp[i].getNume()==choice)
            index=i;
    }
    if(index==0)
    {
        cout<<"Invalid input";
    }
    else
    {
        if(corp[index].getNume()=="Q")
        {
            double a,b;
            cin>>a>>b;
            rationalCorp.testIsEqual(a,b);
        }
        if(corp[index].getNume()=="R")
        {
                double a,b;
                cin>>a>>b;
                realCorp.testIsEqual(a,b);
        }
        else if(corp[index].getNume()=="C")
        {
            Nrcomplex a,b;
            cin>>a>>b;
            complexCorp.testIsEqual(a,b);
        }
        else if(corp[index].getNume().substr(0,2)=="Z/")
        {
            int indexZ=0;
            for(int i=1;i<=nr_Zn;++i)
            {
                if(znCorp[i].getNume()==corp[index].getNume())
                {
                    indexZ=i;
                    break;
                }
            }
            int a,b;
            cin>>a>>b;
            znCorp[indexZ].testIsEqual(a,b);
        }
        else if(corp[index].getType()==0)
        {
            cout<<"Selecteaza elementele pentru operatia de inmultire:\n";
            int card=corp[index].getCardinal();
            string *elements=new string[card+1];

            corp[index].getElements(card,elements);

            for(int i=1;i<=card;++i)
                cout<<elements[i]<<" ";
            cout<<"\n";
            string a,b;
            cin>>a>>b;
            corp[index].testIsEqual(a,b);
            delete[] elements;
        }
    }
}
void interogationMenu(int option,Ring ring[],int nr_ring, Corp corp[], int nr_corp, RationalGroup rationalCorp, ComplexCorp complexCorp, RealGroup realCorp, ZnCorp znCorp[],int nr_zn)
{
    Menu interogationOperation;
    string operations[]={"Testeaza daca este corp","Realizeaza adunarea a 2 elemente","Realizeaza inmultirea a 2 elemente"
                        ,"Calculeaza elementele netru din corp","Calculeaza inversul si opusul unui element","Calculeaza ordinul unui element"
                        ,"Realizeaza scaderea a 2 elemente","Realizeaza impartirea a 2 elemente","Test izomorfism","Testare egalitate"
                        };
    interogationOperation.getOptions(operations,10);
    interogationOperation.showMenuChoice(option);

    switch (option)
            {
                case 1: // Up arrow key
                    testCorp(ring,nr_ring,corp,nr_corp);
                    //option=0;
                    //interogationMenu(option,ring,nr_ring,corp,nr_corp,rationalCorp,complexCorp,realCorp,znCorp,nr_zn);
                    break;

                case 2:
                    addition(ring,nr_ring,corp,nr_corp,rationalCorp,complexCorp,realCorp,znCorp,nr_zn);
                    break;

                case 3:
                    multiply(ring,nr_ring,corp,nr_corp,rationalCorp,complexCorp,realCorp,znCorp,nr_zn);
                    break;

                case 4:
                    findNeutrals(ring,nr_ring,corp,nr_corp,rationalCorp,complexCorp,realCorp,znCorp,nr_zn);
                    break;

                case 5:
                    inverse(ring,nr_ring,corp,nr_corp,rationalCorp,complexCorp,realCorp,znCorp,nr_zn);
                    break;

                case 6:
                    ordin(ring,nr_ring,corp,nr_corp,rationalCorp,complexCorp,realCorp,znCorp,nr_zn);
                    break;

                case 7:
                    deduction(ring,nr_ring,corp,nr_corp,rationalCorp,complexCorp,realCorp,znCorp,nr_zn);
                    break;

                case 8:
                    division(ring,nr_ring,corp,nr_corp,rationalCorp,complexCorp,realCorp,znCorp,nr_zn);
                    break;

                case 9:
                    testIzomorfism(ring,nr_ring,corp,nr_corp);
                    break;

                case 10:
                    testEgalitate(ring,nr_ring,corp,nr_corp,rationalCorp,complexCorp,realCorp,znCorp,nr_zn);
                    break;

                case 11:
                    exit(0);
                    break;
            }
}


void openFileInput()
{
    system("cls");
    cout<<"Specificati numele fisierului care se afla in fisierul cu aplicatia:";
    string file_name;
    cin>>file_name;
    cout<<file_name<<"\n";


    ifstream fin(file_name.c_str());

    if(fin.is_open())
    {
        cout<<"exists \n";
        int nr_ring;
        fin>>nr_ring;
        Ring *ring=new Ring[nr_ring+1];
        Corp *corp=new Corp[nr_ring+1];
        RealGroup realCorp;
        RationalGroup rationalCorp;
        ComplexCorp complexCorp;
        ZnCorp *znCorp=new ZnCorp[nr_ring+1];
        int nr_corp=0;
        int nr_zn=0;
        for(int i=1;i<=nr_ring;++i)
        {
            fin>>ring[i];
            if(ring[i].getType()!=0)
            {
                cout<<"Inelul "<<i<<"|"<<ring[i].getNume()<<"\n";
                corp[++nr_corp].setCardinal(-1);
                corp[nr_corp].setType(ring[i].getType());
                corp[nr_corp].setNume(ring[i].getNume());
                if(ring[i].getNume()=="Q")
                {
                    rationalCorp.setCardinal(-1);
                    rationalCorp.setType(1);
                    rationalCorp.setNume(ring[i].getNume());
                }
                else
                {
                    if(ring[i].getNume()=="R")
                    {
                        realCorp.setCardinal(-1);
                        realCorp.setType(2);
                        realCorp.setNume(ring[i].getNume());
                    }
                    else
                    {
                        complexCorp.setCardinal(-1);
                        complexCorp.setType(2);
                        complexCorp.setNume(ring[i].getNume());
                    }
                }

            }
            else if(ring[i].getType()==0 and ring[i].getNume().substr(0,2)=="Z/")
            {
                cout<<"Inelul "<<i<<"|"<<ring[i].getNume()<<"\n";
                int **table1;
                int card=ring[i].getCardinal();
                table1 = new int*[card+1];
                for(int i=1;i<=card;++i)
                {
                    table1[i]=new int[card+1];
                    for(int j=1;j<=card;++j)
                    {
                        table1[i][j]=((i-1)+(j-1))%card+1;
                    }
                }
                int **table2;
                table2 = new int*[card+1];
                for(int i=1;i<=card;++i)
                {
                    table2[i]=new int[card+1];
                    for(int j=1;j<=card;++j)
                    {
                        table2[i][j]=((i-1)*(j-1))%card+1;
                    }
                }
                if(prim(ring[i].getCardinal())==1)
                {
                    corp[++nr_corp].setNume(ring[i].getNume());
                    corp[nr_corp].setCardinal(card);
                    corp[nr_corp].setOpTable(table1,table2,card);
                    znCorp[++nr_zn].setNume(ring[i].getNume());
                    znCorp[nr_zn].setCardinal(card);
                    znCorp[nr_zn].setOpTable(table1,table2,card);
                }
            }
            else if(ring[i].getType()==0 and ring[i].getNume().substr(0,2)!="Z/")
            {
                ring[i].setType(0);
                cout<<"Corp "<<ring[i].getNume();
                //ring[i].printData();
                if(ring[i].testCorp()==1)
                {
                    cout<<"\n Da \n\n\n\n";
                    int card,type;
                    card=ring[i].getCardinal();
                    int **table1;
                    table1 = new int*[card+1];
                    for(int i=1;i<=card;++i)
                    {
                        table1[i]=new int[card+1];
                    }
                    ring[i].getMonoid1(card,type,table1);
                    int **table2;
                    table2 = new int*[card+1];
                    for(int i=1;i<=card;++i)
                    {
                        table2[i]=new int[card+1];
                    }
                    ring[i].getMonoid2(table2);

                    string *elements=new string[card+1];

                    ring[i].getElements(card,elements);

                    for(int i=1;i<=card;++i)
                        cout<<elements[i]<<" ";
                    cout<<"\n";

                    /*for(int i=1;i<=card;++i)
                    {
                        for(int j=1;j<=card;++j)
                            cout<<table1[i][j];
                        cout<<"\n";
                    }*/
                    corp[++nr_corp].setCardinal(card);
                    corp[nr_corp].setNume(ring[i].getNume());
                    corp[nr_corp].setElements(elements,card);
                    corp[nr_corp].setOpTable(table1,table2,card);
                    corp[nr_corp].setType(0);

                    corp[nr_corp].printData();
                    /*corp[nr_corp].getElements(card,elements2);

                    for(int i=1;i<=card;++i)
                        cout<<elements2[i]<<" "<<i<<"| |";
                    cout<<"\n\naaa\n";

                    corp[nr_corp].printData();*/

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
            }
        }
        for(int i=1;i<=nr_corp;++i)
        {
            cout<<corp[i].getNume()<<" "<<corp[i].getCardinal()<<"\n";
        }
        int operation=0;
        interogationMenu(operation,ring,nr_ring,corp,nr_corp,rationalCorp,complexCorp,realCorp,znCorp,nr_zn);
        delete[] corp;
        delete[] ring;
        delete[] znCorp;
    }
    else
    {
        cout<<"invalid_file";
        return;
    }
}



void ConsoleInput()
{
    system("cls");
    /*cout<<"Specificati numele fisierului care se afla in fisierul cu aplicatia:";
    string file_name;
    cin>>file_name;
    cout<<file_name<<"\n";
    */

    //ifstream fin(file_name.c_str());

    //if(fin.is_open())
    //{
        //cout<<"exists \n";
        int nr_ring;
        cin>>nr_ring;
        Ring *ring=new Ring[nr_ring+1];
        Corp *corp=new Corp[nr_ring+1];
        RealGroup realCorp;
        RationalGroup rationalCorp;
        ComplexCorp complexCorp;
        ZnCorp *znCorp=new ZnCorp[nr_ring+1];
        int nr_corp=0;
        int nr_zn=0;
        for(int i=1;i<=nr_ring;++i)
        {
            cin>>ring[i];
            if(ring[i].getType()!=0)
            {
                cout<<"Inelul "<<i<<"|"<<ring[i].getNume()<<"\n";
                corp[++nr_corp].setCardinal(-1);
                corp[nr_corp].setType(ring[i].getType());
                corp[nr_corp].setNume(ring[i].getNume());
                if(ring[i].getNume()=="Q")
                {
                    rationalCorp.setCardinal(-1);
                    rationalCorp.setType(1);
                    rationalCorp.setNume(ring[i].getNume());
                }
                else
                {
                    if(ring[i].getNume()=="R")
                    {
                        realCorp.setCardinal(-1);
                        realCorp.setType(2);
                        realCorp.setNume(ring[i].getNume());
                    }
                    else
                    {
                        complexCorp.setCardinal(-1);
                        complexCorp.setType(2);
                        complexCorp.setNume(ring[i].getNume());
                    }
                }

            }
            else if(ring[i].getType()==0 and ring[i].getNume().substr(0,2)=="Z/")
            {
                cout<<"Inelul "<<i<<"|"<<ring[i].getNume()<<"\n";
                int **table1;
                int card=ring[i].getCardinal();
                table1 = new int*[card+1];
                for(int i=1;i<=card;++i)
                {
                    table1[i]=new int[card+1];
                    for(int j=1;j<=card;++j)
                    {
                        table1[i][j]=((i-1)+(j-1))%card+1;
                    }
                }
                int **table2;
                table2 = new int*[card+1];
                for(int i=1;i<=card;++i)
                {
                    table2[i]=new int[card+1];
                    for(int j=1;j<=card;++j)
                    {
                        table2[i][j]=((i-1)*(j-1))%card+1;
                    }
                }
                if(prim(ring[i].getCardinal())==1)
                {
                    corp[++nr_corp].setNume(ring[i].getNume());
                    corp[nr_corp].setCardinal(card);
                    corp[nr_corp].setOpTable(table1,table2,card);
                    znCorp[++nr_zn].setNume(ring[i].getNume());
                    znCorp[nr_zn].setCardinal(card);
                    znCorp[nr_zn].setOpTable(table1,table2,card);
                }
            }
            else if(ring[i].getType()==0 and ring[i].getNume().substr(0,2)!="Z/")
            {
                ring[i].setType(0);
                cout<<"Corp "<<ring[i].getNume();
                //ring[i].printData();
                if(ring[i].testCorp()==1)
                {
                    cout<<"\n Da \n\n\n\n";
                    int card,type;
                    card=ring[i].getCardinal();
                    int **table1;
                    table1 = new int*[card+1];
                    for(int i=1;i<=card;++i)
                    {
                        table1[i]=new int[card+1];
                    }
                    ring[i].getMonoid1(card,type,table1);
                    int **table2;
                    table2 = new int*[card+1];
                    for(int i=1;i<=card;++i)
                    {
                        table2[i]=new int[card+1];
                    }
                    ring[i].getMonoid2(table2);

                    string *elements=new string[card+1];

                    ring[i].getElements(card,elements);

                    for(int i=1;i<=card;++i)
                        cout<<elements[i]<<" ";
                    cout<<"\n";

                    /*for(int i=1;i<=card;++i)
                    {
                        for(int j=1;j<=card;++j)
                            cout<<table1[i][j];
                        cout<<"\n";
                    }*/
                    corp[++nr_corp].setCardinal(card);
                    corp[nr_corp].setNume(ring[i].getNume());
                    corp[nr_corp].setElements(elements,card);
                    corp[nr_corp].setOpTable(table1,table2,card);
                    corp[nr_corp].setType(0);

                    corp[nr_corp].printData();
                    /*corp[nr_corp].getElements(card,elements2);

                    for(int i=1;i<=card;++i)
                        cout<<elements2[i]<<" "<<i<<"| |";
                    cout<<"\n\naaa\n";

                    corp[nr_corp].printData();*/

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
            }
        }
        for(int i=1;i<=nr_corp;++i)
        {
            cout<<corp[i].getNume()<<" "<<corp[i].getCardinal()<<"\n";
        }
        int operation=0;
        interogationMenu(operation,ring,nr_ring,corp,nr_corp,rationalCorp,complexCorp,realCorp,znCorp,nr_zn);
    /*}
    else
    {
        cout<<"invalid_file";
        return;
    }*/
}
void tutorialInput(int optionSelected)
{
    cout<<"Inputul este de forma:\n";
    cout<<"nr_multimi\n";
    cout<<"Pentru fiecare multime se va specifica apoi:\n";
    cout<<"Numele sau litera multimii (R, Z, Z\nZ, Q si C sunt rezervate pentru cele implicite, iar in acest caz, interogarea se va finaliza)\n";
    cout<<"Nr de elemente\n";
    cout<<"elementele multimii\n";
    cout<<"relatiile specifice legii de compozitie '+'\n";
    cout<<"elementele multimii\n";
    cout<<"relatiile specifice legii de compozitie '*'\n";
    cout<<"----se va repeta aceleasi etape pana cand se vor fi citite toate structurile algebrice\n";
    //cout<<"> Press Enter to return to menu\n";
    int key_code = _getch();
    if (key_code==enterkey)
    {
        optionSelected=0;
        redirection_Menu(optionSelected);
    }
}


int main()
{
    int optionSelected=0;
    //input_MenuChoice(optionSelected);
    /*int operation=0;
    interogationMenu(operation);
    */

    /*verificare daca e in inel;
    ring.element[i]->a
    ring.element[j]->b

    corp1, corp2

    corp1==corp2 si != izomorfism*/

    Menu inputMenu;
    string optiuni[]={"Prin fisier","Prin consola","How to input"};
    inputMenu.getOptions(optiuni,3);
    int selectedOption=0;
    inputMenu.showMenuChoice(selectedOption);

    switch (selectedOption)
            {
                case 1: // Up arrow key
                    openFileInput();
                    break;

                case 2: // Down arrow key
                    ConsoleInput();
                    break;

                case 3: // Enter key
                    tutorialInput(optionSelected);
                    break;
                case 4:
                    exit(0);
                    break;
            }
    return 0;
}
