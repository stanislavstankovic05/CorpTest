#include <bits/stdc++.h>
#include <string>
#include <conio.h>
#include <typeinfo>
#include <sstream>
#include "ring.h"
#include "Interface.h"
#include "Corp.h"
#include "ZnCorp.h"
#include "RealCorp.h"
#include "RationalGroup.h"
#include "ComplexGroup.h"
#include "StructuraAlgebrica.h"
#define upkey 72
#define downkey 80
#define enterkey 13
#define NMAX 101
using namespace std;

//ofstream fout("output.out");



void interogationMenu(int option, Ring **ring,int nr_ring);
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

void testCorp(Ring **ring,int nr_ring)
{
    cout<<"Selecteaza inelul pe care vrei sa il testati:\n";
        //cout<<nr_corp<<"\n";
        for(int i=1;i<=nr_ring;++i)
        {
            cout<<ring[i]->getNume()<<" ";
        }
        /*for(int i=1;i<=nr_corp;++i)
        {
            cout<<corp[i].getNume()<<" ";
        }*/
        cout<<"\n";
        string choice;
        cin>>choice;
        int index=0;
        try
        {
            for(int i=1;i<=nr_ring;++i)
            {
                if(ring[i]->getNume()==choice)
                {
                    index=i;
                    break;
                }
            }
            if(index==0)
            {
                throw 0;
            }
        }catch(int num)
        {
            cout<<"Invalid input";
            interogationMenu(0,ring,nr_ring);
        }
        if(ring[index]->getNume().substr(0,2)=="Z/")
        {
            cout<<ring[index]->getCardinal()<<"\n";
            string nume=ring[index]->getNume();
            int card=ring[index]->getCardinal();
            int **table=new int*[card+1];
            for(int i=1;i<=card;++i)
            {
                table[i]=new int[card+1];
            }
            ring[index]->getMonoid1(0,card,table);
            for(int i=1;i<=card;++i)
            {
                for(int j=1;j<=card;++j)
                    cout<<table[i][j];
                cout<<"\n";
            }
            if(prim(ring[index]->getCardinal())==1)
            {
                //cout<<"aici";
                int card=ring[index]->getCardinal();
                ring[index]=new ZnCorp;
                ZnCorp *z=new ZnCorp;
                z=dynamic_cast<ZnCorp*>(ring[index]);
                z->setCardinal(card);
                z->setNume(nume);
                z->TestCast();
            }
        }
        else if(ring[index]->test()==1)
        {
            Ring *r=ring[index];
            ring[index]=new Corp;
            //ring[i]=r;
            //ring[i]->printData();
            //r->printData();
            //ring[i]->printData();
            Corp *c;
            c=dynamic_cast<Corp*>(ring[index]);
            c->setNume(r->getNume());
        }
        ring[index]->TestCast();
    /*for(int i=1;i<=nr_ring;++i)
    {
        ring[i]->TestCast();
    }*/
}
void addition(Ring **ring,int nr_ring)
{
    cout<<"Selecteaza inelul pe care vrei sa il testati:\n";
        //cout<<nr_corp<<"\n";
        for(int i=1;i<=nr_ring;++i)
        {
            cout<<ring[i]->getNume()<<" ";
        }
        /*for(int i=1;i<=nr_corp;++i)
        {
            cout<<corp[i].getNume()<<" ";
        }*/
        cout<<"\n";
        string choice;
        cin>>choice;
        int index=0;
        try
        {
            for(int i=1;i<=nr_ring;++i)
            {
                if(ring[i]->getNume()==choice)
                {
                    index=i;
                    break;
                }
            }
            if(index==0 || ring[index]->test()==0)
            {
                throw 0;
            }
        }catch(int num)
        {
            cout<<"Invalid input";
            interogationMenu(0,ring,nr_ring);
        }
    if(ring[index]->getNume()=="Q")
        {
            double a,b;
            cin>>a>>b;

            Ring *r=ring[index];
            ring[index]=new RationalGroup;
            RationalGroup *rationalCorp;
            rationalCorp=dynamic_cast<RationalGroup*>(ring[index]);

            rationalCorp->additionOperation(a,b);
            ring[index]->TestCast();
        }
        if(ring[index]->getNume()=="R")
        {
                double a,b;
                cin>>a>>b;

                Ring *r=ring[index];
                ring[index]=new RealGroup;
                RealGroup *realCorp;
                realCorp=dynamic_cast<RealGroup*>(ring[index]);

                realCorp->additionOperation(a,b);
                //ring[index]->TestCast();
                //ring[index]->additionOperation(a,b)
        }
        else if(ring[index]->getNume()=="C")
        {
            Nrcomplex a,b;
            cin>>a>>b;

            Ring *r=ring[index];
                ring[index]=new ComplexCorp;
                ComplexCorp *complexCorp;
                complexCorp=dynamic_cast<ComplexCorp*>(ring[index]);

            complexCorp->additionOperation(a,b);
            //ring[index]->additionOperation(a,b)
        }
        else if(ring[index]->getNume().substr(0,2)=="Z/")
        {
            int a,b;
            cin>>a>>b;
            int card=ring[index]->getCardinal();
            if(prim(card)==1)
            {
                ZnCorp zn;
                zn.setCardinal(card);
                zn.additionOperation(a,b);
            }
        }
        else if(ring[index]->getType()==0)
        {
            cout<<"Selecteaza elementele pentru operatia de adunare:\n";
            int card=ring[index]->getCardinal();
            string *elements=new string[card+1];

            ring[index]->getElements(card,elements);

            for(int i=1;i<=card;++i)
                cout<<elements[i]<<" ";
            cout<<"\n";
            string a,b;
            cin>>a>>b;
            cout<<ring[index]->additionOperation(a,b)<<"\n";
        }

}
void multiply(Ring **ring,int nr_ring)
{
    cout<<"Selecteaza inelul pe care vrei sa il testati:\n";
        //cout<<nr_corp<<"\n";
        for(int i=1;i<=nr_ring;++i)
        {
            cout<<ring[i]->getNume()<<" ";
        }
        /*for(int i=1;i<=nr_corp;++i)
        {
            cout<<corp[i].getNume()<<" ";
        }*/
        cout<<"\n";
        string choice;
        cin>>choice;
        int index=0;
        try
        {
            for(int i=1;i<=nr_ring;++i)
            {
                if(ring[i]->getNume()==choice)
                {
                    index=i;
                    break;
                }
            }
            if(index==0)
            {
                throw 0;
            }
        }catch(int num)
        {
            cout<<"Invalid input";
            interogationMenu(0,ring,nr_ring);
        }
    if(ring[index]->getNume()=="Q")
        {
            double a,b;
            cin>>a>>b;

            Ring *r=ring[index];
            ring[index]=new RationalGroup;
            RationalGroup *rationalCorp;
            rationalCorp=dynamic_cast<RationalGroup*>(ring[index]);

            rationalCorp->multiplyOperation(a,b);
            ring[index]->TestCast();
        }
        if(ring[index]->getNume()=="R")
        {
                double a,b;
                cin>>a>>b;

                Ring *r=ring[index];
                ring[index]=new RealGroup;
                RealGroup *realCorp;
                realCorp=dynamic_cast<RealGroup*>(ring[index]);

                realCorp->multiplyOperation(a,b);
                //ring[index]->TestCast();
                //ring[index]->multiplyOperation(a,b)
        }
        else if(ring[index]->getNume()=="C")
        {
            Nrcomplex a,b;
            cin>>a>>b;

            Ring *r=ring[index];
                ring[index]=new ComplexCorp;
                ComplexCorp *complexCorp;
                complexCorp=dynamic_cast<ComplexCorp*>(ring[index]);

            complexCorp->multiplyOperation(a,b);
            //ring[index]->multiplyOperation(a,b)
        }
        else if(ring[index]->getNume().substr(0,2)=="Z/")
        {
            int a,b;
            cin>>a>>b;
            int card=ring[index]->getCardinal();
            if(prim(card)==1)
            {
                ZnCorp zn;
                zn.setCardinal(card);
                zn.multiplyOperation(a,b);
            }
        }
        else if(ring[index]->getType()==0)
        {
            cout<<"Selecteaza elementele pentru operatia de adunare:\n";
            int card=ring[index]->getCardinal();
            string *elements=new string[card+1];

            ring[index]->getElements(card,elements);

            for(int i=1;i<=card;++i)
                cout<<elements[i]<<" ";
            cout<<"\n";
            string a,b;
            cin>>a>>b;
            cout<<ring[index]->multiplyOperation(a,b)<<"\n";
        }
}
void findNeutrals(Ring **ring,int nr_ring)
{
    cout<<"Selecteaza inelul pe care vrei sa il testati:\n";
        //cout<<nr_corp<<"\n";
        for(int i=1;i<=nr_ring;++i)
        {
            cout<<ring[i]->getNume()<<" ";
        }
        /*for(int i=1;i<=nr_corp;++i)
        {
            cout<<corp[i].getNume()<<" ";
        }*/
        cout<<"\n";
        string choice;
        cin>>choice;
        int index=0;
        try
        {
            for(int i=1;i<=nr_ring;++i)
            {
                if(ring[i]->getNume()==choice)
                {
                    index=i;
                    break;
                }
            }
            if(index==0)
            {
                throw 0;
            }
        }catch(int num)
        {
            cout<<"Invalid input";
            interogationMenu(0,ring,nr_ring);
        }
    if(ring[index]->getNume()=="Q")
        {
            Ring *r=ring[index];
            ring[index]=new RationalGroup;
            RationalGroup *rationalCorp;
            rationalCorp=dynamic_cast<RationalGroup*>(ring[index]);

            rationalCorp->neutralsElements();
            ring[index]->TestCast();
        }
        if(ring[index]->getNume()=="R")
        {
                Ring *r=ring[index];
                ring[index]=new RealGroup;
                RealGroup *realCorp;
                realCorp=dynamic_cast<RealGroup*>(ring[index]);

                realCorp->neutralsElements();
                //ring[index]->TestCast();
                //ring[index]->multiplyOperation(a,b)
        }
        else if(ring[index]->getNume()=="C")
        {

            Ring *r=ring[index];
                ring[index]=new ComplexCorp;
                ComplexCorp *complexCorp;
                complexCorp=dynamic_cast<ComplexCorp*>(ring[index]);

            complexCorp->neutralsElements();
            //ring[index]->multiplyOperation(a,b)
        }
        else if(ring[index]->getNume().substr(0,2)=="Z/")
        {
            cout<<0<<" "<<1;
        }
        else if(ring[index]->getType()==0)
        {
            cout<<"Selecteaza elementele pentru operatia de adunare:\n";
            int card=ring[index]->getCardinal();
            string *elements=new string[card+1];

            ring[index]->getElements(card,elements);

            ring[index]->neutralsElements();
        }
}
void ordin(Ring **ring,int nr_ring)
{
    cout<<"Selecteaza inelul pe care vrei sa il testati:\n";
        //cout<<nr_corp<<"\n";
        for(int i=1;i<=nr_ring;++i)
        {
            cout<<ring[i]->getNume()<<" ";
        }
        /*for(int i=1;i<=nr_corp;++i)
        {
            cout<<corp[i].getNume()<<" ";
        }*/
        cout<<"\n";
        string choice;
        cin>>choice;
        int index=0;
        try
        {
            for(int i=1;i<=nr_ring;++i)
            {
                if(ring[i]->getNume()==choice)
                {
                    index=i;
                    break;
                }
            }
            if(index==0)
            {
                throw 0;
            }
        }catch(int num)
        {
            cout<<"Invalid input";
            interogationMenu(0,ring,nr_ring);
        }
    if(ring[index]->getNume()=="Q")
        {
            Ring *r=ring[index];
            ring[index]=new RationalGroup;
            RationalGroup *rationalCorp;
            rationalCorp=dynamic_cast<RationalGroup*>(ring[index]);

            double a;
            cin>>a;
            rationalCorp->orderElement(a);
            ring[index]->TestCast();
        }
        if(ring[index]->getNume()=="R")
        {
                Ring *r=ring[index];
                ring[index]=new RealGroup;
                RealGroup *realCorp;
                realCorp=dynamic_cast<RealGroup*>(ring[index]);

                double a;
                cin>>a;
                realCorp->orderElement(a);
                //ring[index]->TestCast();
                //ring[index]->multiplyOperation(a,b)
        }
        else if(ring[index]->getNume()=="C")
        {

            Ring *r=ring[index];
                ring[index]=new ComplexCorp;
                ComplexCorp *complexCorp;
                complexCorp=dynamic_cast<ComplexCorp*>(ring[index]);

            Nrcomplex a;
            cin>>a;
            complexCorp->orderElement(a);
            //ring[index]->multiplyOperation(a,b)
        }
        else if(ring[index]->getNume().substr(0,2)=="Z/")
        {
            int a;
            cin>>a;
            int card=ring[index]->getCardinal();
            if(prim(card)==1)
            {
                ZnCorp zn;
                zn.setCardinal(card);
                zn.orderElement(a);
            }
            else
                cout<<"nu e corp";
        }
        else if(ring[index]->getType()==0)
        {
            cout<<"Selecteaza elementele pentru operatia de adunare:\n";
            int card=ring[index]->getCardinal();
            string *elements=new string[card+1];

            ring[index]->getElements(card,elements);
            string a;
            cin>>a;
            ring[index]->orderElement(a);
        }
}
void inverse(Ring **ring,int nr_ring)
{
    cout<<"Selecteaza inelul pe care vrei sa il testati:\n";
        //cout<<nr_corp<<"\n";
        for(int i=1;i<=nr_ring;++i)
        {
            cout<<ring[i]->getNume()<<" ";
        }
        /*for(int i=1;i<=nr_corp;++i)
        {
            cout<<corp[i].getNume()<<" ";
        }*/
        cout<<"\n";
        string choice;
        cin>>choice;
        int index=0;
        try
        {
            for(int i=1;i<=nr_ring;++i)
            {
                if(ring[i]->getNume()==choice)
                {
                    index=i;
                    break;
                }
            }
            if(index==0)
            {
                throw 0;
            }
        }catch(int num)
        {
            cout<<"Invalid input";
            interogationMenu(0,ring,nr_ring);
        }
    if(ring[index]->getNume()=="Q")
        {
            Ring *r=ring[index];
            ring[index]=new RationalGroup;
            RationalGroup *rationalCorp;
            rationalCorp=dynamic_cast<RationalGroup*>(ring[index]);

            double a;
            cin>>a;
            rationalCorp->inverseElement(a);
            ring[index]->TestCast();
        }
        if(ring[index]->getNume()=="R")
        {
                Ring *r=ring[index];
                ring[index]=new RealGroup;
                RealGroup *realCorp;
                realCorp=dynamic_cast<RealGroup*>(ring[index]);

                double a;
                cin>>a;
                realCorp->inverseElement(a);
                //ring[index]->TestCast();
                //ring[index]->multiplyOperation(a,b)
        }
        else if(ring[index]->getNume()=="C")
        {

            Ring *r=ring[index];
                ring[index]=new ComplexCorp;
                ComplexCorp *complexCorp;
                complexCorp=dynamic_cast<ComplexCorp*>(ring[index]);

            Nrcomplex a;
            cin>>a;
            complexCorp->inverseElement(a);
            //ring[index]->multiplyOperation(a,b)
        }
        else if(ring[index]->getNume().substr(0,2)=="Z/")
        {
            int a;
            cin>>a;
            int card=ring[index]->getCardinal();
            if(prim(card)==1)
            {
                ZnCorp zn;
                zn.setCardinal(card);
                zn.inverseElement(a);
            }
            else
                cout<<"nu e corp";
        }
        else if(ring[index]->getType()==0)
        {
            cout<<"Selecteaza elementele pentru operatia de adunare:\n";
            int card=ring[index]->getCardinal();
            string *elements=new string[card+1];

            ring[index]->getElements(card,elements);
            string a;
            cin>>a;
            ring[index]->inverseElement(a);
        }
}
void deduction(Ring **ring,int nr_ring)
{
    cout<<"Selecteaza inelul pe care vrei sa il testati:\n";
        //cout<<nr_corp<<"\n";
        for(int i=1;i<=nr_ring;++i)
        {
            cout<<ring[i]->getNume()<<" ";
        }
        /*for(int i=1;i<=nr_corp;++i)
        {
            cout<<corp[i].getNume()<<" ";
        }*/
        cout<<"\n";
        string choice;
        cin>>choice;
        int index=0;
        try
        {
            for(int i=1;i<=nr_ring;++i)
            {
                if(ring[i]->getNume()==choice)
                {
                    index=i;
                    break;
                }
            }
            if(index==0)
            {
                throw 0;
            }
        }catch(int num)
        {
            cout<<"Invalid input";
            interogationMenu(0,ring,nr_ring);
        }
    if(ring[index]->getNume()=="Q")
        {
            double a,b;
            cin>>a>>b;

            Ring *r=ring[index];
            ring[index]=new RationalGroup;
            RationalGroup *rationalCorp;
            rationalCorp=dynamic_cast<RationalGroup*>(ring[index]);

            rationalCorp->substractionOperation(a,b);
            ring[index]->TestCast();
        }
        if(ring[index]->getNume()=="R")
        {
                double a,b;
                cin>>a>>b;

                Ring *r=ring[index];
                ring[index]=new RealGroup;
                RealGroup *realCorp;
                realCorp=dynamic_cast<RealGroup*>(ring[index]);

                realCorp->substractionOperation(a,b);
                //ring[index]->TestCast();
                //ring[index]->additionOperation(a,b)
        }
        else if(ring[index]->getNume()=="C")
        {
            Nrcomplex a,b;
            cin>>a>>b;

            Ring *r=ring[index];
                ring[index]=new ComplexCorp;
                ComplexCorp *complexCorp;
                complexCorp=dynamic_cast<ComplexCorp*>(ring[index]);

            complexCorp->substractionOperation(a,b);
            //ring[index]->additionOperation(a,b)
        }
        else if(ring[index]->getNume().substr(0,2)=="Z/")
        {
            int a,b;
            cin>>a>>b;
            int card=ring[index]->getCardinal();
            cout<<(a-b)%card;
        }
        else if(ring[index]->getType()==0)
        {
            cout<<"Selecteaza elementele pentru operatia de adunare:\n";
            int card=ring[index]->getCardinal();
            string *elements=new string[card+1];

            ring[index]->getElements(card,elements);

            for(int i=1;i<=card;++i)
                cout<<elements[i]<<" ";
            cout<<"\n";
            string a,b;
            cin>>a>>b;
            cout<<ring[index]->substractionOperation(a,b)<<"\n";
        }
}
void division(Ring **ring,int nr_ring)
{
    cout<<"Selecteaza inelul pe care vrei sa il testati:\n";
        //cout<<nr_corp<<"\n";
        for(int i=1;i<=nr_ring;++i)
        {
            cout<<ring[i]->getNume()<<" ";
        }
        /*for(int i=1;i<=nr_corp;++i)
        {
            cout<<corp[i].getNume()<<" ";
        }*/
        cout<<"\n";
        string choice;
        cin>>choice;
        int index=0;
        try
        {
            for(int i=1;i<=nr_ring;++i)
            {
                if(ring[i]->getNume()==choice)
                {
                    index=i;
                    break;
                }
            }
            if(index==0)
            {
                throw 0;
            }
        }catch(int num)
        {
            cout<<"Invalid input";
            interogationMenu(0,ring,nr_ring);
        }
    if(ring[index]->getNume()=="Q")
        {
            double a,b;
            cin>>a>>b;

            Ring *r=ring[index];
            ring[index]=new RationalGroup;
            RationalGroup *rationalCorp;
            rationalCorp=dynamic_cast<RationalGroup*>(ring[index]);

            rationalCorp->divideOperation(a,b);
            ring[index]->TestCast();
        }
        if(ring[index]->getNume()=="R")
        {
                double a,b;
                cin>>a>>b;

                Ring *r=ring[index];
                ring[index]=new RealGroup;
                RealGroup *realCorp;
                realCorp=dynamic_cast<RealGroup*>(ring[index]);

                realCorp->divideOperation(a,b);
                //ring[index]->TestCast();
                //ring[index]->additionOperation(a,b)
        }
        else if(ring[index]->getNume()=="C")
        {
            Nrcomplex a,b;
            cin>>a>>b;

            Ring *r=ring[index];
                ring[index]=new ComplexCorp;
                ComplexCorp *complexCorp;
                complexCorp=dynamic_cast<ComplexCorp*>(ring[index]);

            complexCorp->divideOperation(a,b);
            //ring[index]->additionOperation(a,b)
        }
        else if(ring[index]->getNume().substr(0,2)=="Z/")
        {
            int a,b;
            cin>>a>>b;
            int card=ring[index]->getCardinal();
            cout<<(a/b)%card;
        }
        else if(ring[index]->getType()==0)
        {
            cout<<"Selecteaza elementele pentru operatia de adunare:\n";
            int card=ring[index]->getCardinal();
            string *elements=new string[card+1];

            ring[index]->getElements(card,elements);

            for(int i=1;i<=card;++i)
                cout<<elements[i]<<" ";
            cout<<"\n";
            string a,b;
            cin>>a>>b;
            cout<<ring[index]->divideOperation(a,b)<<"\n";
        }
}
void testIzomorfism(Ring **ring,int nr_ring)
{
    cout<<"Selecteaza inelul pe care vrei sa il testati:\n";
        //cout<<nr_corp<<"\n";
        for(int i=1;i<=nr_ring;++i)
        {
            cout<<ring[i]->getNume()<<" ";
        }
        cout<<"\n";
        string choice1,choice2;
        cin>>choice1>>choice2;
        int index1=0;
            int index2=0;
        try
        {
            for(int i=1;i<=nr_ring;++i)
            {
                if(ring[i]->getNume()==choice1)
                {
                    index1=i;
                }
                else if(ring[i]->getNume()==choice2)
                    index2=i;
            }
            if(index1==0 || index2==0)
                throw 0;
        }
        catch(int num)
        {
            cout<<"Invalid input";
            interogationMenu(0,ring,nr_ring);
        }
        cout<<"\n";
            cout<<"Corpurile ";
            cout<<ring[index1]->getType()<<" "<<ring[index2]->getType()<<"\n";
            Corp c1(*ring[index1]);
            Corp c2(*ring[index2]);
            cout<<"_________________________";
            c1.printData();
            c2.printData();
            cout<<"_________________________";
            //else
            //{
                if(c1==c2)//conversie de tip
                {
                    cout<<"Sunt izomorfe";
                }
                else
                {
                    cout<<"Nu sunt izomorfe";
                }
            //}

}
void testEgalitate(Ring **ring,int nr_ring)
{
    cout<<"Selecteaza inelul pe care vrei sa il testati:\n";
        //cout<<nr_corp<<"\n";
        for(int i=1;i<=nr_ring;++i)
        {
            cout<<ring[i]->getNume()<<" ";
        }
        /*for(int i=1;i<=nr_corp;++i)
        {
            cout<<corp[i].getNume()<<" ";
        }*/
        cout<<"\n";
        string choice;
        cin>>choice;
        int index=0;
        try
        {
            for(int i=1;i<=nr_ring;++i)
            {
                if(ring[i]->getNume()==choice)
                {
                    index=i;
                    break;
                }
            }
            if(index==0 || ring[index]->test()==0)
            {
                throw 0;
            }
        }catch(int num)
        {
            cout<<"Invalid input";
            interogationMenu(0,ring,nr_ring);
        }
    if(ring[index]->getNume()=="Q")
        {
            double a,b;
            cin>>a>>b;

            Ring *r=ring[index];
            ring[index]=new RationalGroup;
            RationalGroup *rationalCorp;
            rationalCorp=dynamic_cast<RationalGroup*>(ring[index]);

            rationalCorp->divideOperation(a,b);
            ring[index]->TestCast();
        }
        if(ring[index]->getNume()=="R")
        {
                double a,b;
                cin>>a>>b;

                Ring *r=ring[index];
                ring[index]=new RealGroup;
                RealGroup *realCorp;
                realCorp=dynamic_cast<RealGroup*>(ring[index]);

                realCorp->testIsEqual(a,b);
                //ring[index]->TestCast();
                //ring[index]->additionOperation(a,b)
        }
        else if(ring[index]->getNume()=="C")
        {
            Nrcomplex a,b;
            cin>>a>>b;

            Ring *r=ring[index];
                ring[index]=new ComplexCorp;
                ComplexCorp *complexCorp;
                complexCorp=dynamic_cast<ComplexCorp*>(ring[index]);

            complexCorp->testIsEqual(a,b);
            //ring[index]->additionOperation(a,b)
        }
        else if(ring[index]->getNume().substr(0,2)=="Z/")
        {
            int indexZ=0;
            /*for(int i=1;i<=nr_Zn;++i)
            {
                if(znCorp[i].getNume()==corp[index].getNume())
                {
                    indexZ=i;
                    break;
                }
            }*/
            int a,b;
            cin>>a>>b;
            int card=ring[index]->getCardinal();
            if(a%card==b%card)
                cout<<"egal";
            else
                cout<<"nu sunt egale";
        }
        else if(ring[index]->getType()==0)
        {
            cout<<"Selecteaza elementele pentru operatia de adunare:\n";
            int card=ring[index]->getCardinal();
            string *elements=new string[card+1];

            ring[index]->getElements(card,elements);

            for(int i=1;i<=card;++i)
                cout<<elements[i]<<" ";
            cout<<"\n";
            string a,b;
            cin>>a>>b;
            ring[index]->testIsEqual(a,b);
        }
}
void interogationMenu(int option, Ring **ring,int nr_ring)
{
    Interface *interface=Interface::getInstance();
    string operations[]={"Testeaza daca este corp","Realizeaza adunarea a 2 elemente","Realizeaza inmultirea a 2 elemente"
                        ,"Calculeaza elementele netru din corp","Calculeaza inversul si opusul unui element","Calculeaza ordinul unui element"
                        ,"Realizeaza scaderea a 2 elemente","Realizeaza impartirea a 2 elemente","Test izomorfism","Testare egalitate"
                        };
    interface->getOptions(operations,10);
    interface->showInterfaceChoice(option);
    //cout<<interface<<"\n";
    switch (option)
            {
                case 1: // Up arrow key
                    testCorp(ring,nr_ring);
                    //option=0;
                    //interogationMenu(option,ring,nr_ring,corp,nr_corp,rationalCorp,complexCorp,realCorp,znCorp,nr_zn);
                    break;

                case 2:
                    addition(ring,nr_ring);
                    break;

                case 3:
                    multiply(ring,nr_ring);
                    break;

                case 4:
                    findNeutrals(ring,nr_ring);
                    break;

                case 5:
                    inverse(ring,nr_ring);
                    break;

                case 6:
                    ordin(ring,nr_ring);
                    break;

                case 7:
                    deduction(ring,nr_ring);
                    break;

                case 8:
                    division(ring,nr_ring);
                    break;

                case 9:
                    testIzomorfism(ring,nr_ring);
                    break;

                case 10:
                    testEgalitate(ring,nr_ring);
                    break;

                case 11:
                    exit(0);
                    break;
            }
}

Interface *Interface::instancePtr=NULL;
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
        Ring *ring[nr_ring+1];
        for(int i=1;i<=nr_ring;++i)
            ring[i]=new Ring;
        Corp *corp=new Corp[nr_ring+1];
        RealGroup realCorp;
        RationalGroup rationalCorp;
        ComplexCorp complexCorp;
        ZnCorp *znCorp=new ZnCorp[nr_ring+1];
        int nr_corp=0;
        int nr_zn=0;
        for(int i=1;i<=nr_ring;++i)
        {
            fin>>*ring[i];
            if(ring[i]->getType()!=0)
            {
                cout<<"Inelul "<<i<<"|"<<ring[i]->getNume()<<"\n";
                corp[++nr_corp].setCardinal(-1);
                corp[nr_corp].setType(ring[i]->getType());
                corp[nr_corp].setNume(ring[i]->getNume());
                if(ring[i]->getNume()=="Q")
                {
                    rationalCorp.setCardinal(-1);
                    rationalCorp.setType(1);
                    rationalCorp.setNume(ring[i]->getNume());
                }
                else
                {
                    if(ring[i]->getNume()=="R")
                    {
                        realCorp.setCardinal(-1);
                        realCorp.setType(2);
                        realCorp.setNume(ring[i]->getNume());
                    }
                    else
                    {
                        complexCorp.setCardinal(-1);
                        complexCorp.setType(2);
                        complexCorp.setNume(ring[i]->getNume());
                    }
                }

            }
            else if(ring[i]->getType()==0 and ring[i]->getNume().substr(0,2)=="Z/")
            {
                cout<<"Inelul "<<i<<"|"<<ring[i]->getNume()<<"\n";
                int **table1;
                int card=ring[i]->getCardinal();
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
                ring[i]->setCardinal(card);
                ring[i]->setOpTable(table1,table2,card);
                /*if(prim(ring[i]->getCardinal())==1)
                {
                    corp[++nr_corp].setNume(ring[i]->getNume());
                    corp[nr_corp].setCardinal(card);
                    corp[nr_corp].setOpTable(table1,table2,card);
                    znCorp[++nr_zn].setNume(ring[i]->getNume());
                    znCorp[nr_zn].setCardinal(card);
                    znCorp[nr_zn].setOpTable(table1,table2,card);
                }*/
            }
            else if(ring[i]->getType()==0 and ring[i]->getNume().substr(0,2)!="Z/")
            {
                ring[i]->setType(0);
                cout<<"Corp "<<ring[i]->getNume();
                //ring[i]->printData();
                if(ring[i]->testCorp()==1)
                {
                    cout<<"\n Da \n\n\n\n";
                    int card,type;
                    card=ring[i]->getCardinal();
                    int **table1;
                    table1 = new int*[card+1];
                    for(int i=1;i<=card;++i)
                    {
                        table1[i]=new int[card+1];
                    }
                    ring[i]->getMonoid1(card,type,table1);
                    int **table2;
                    table2 = new int*[card+1];
                    for(int i=1;i<=card;++i)
                    {
                        table2[i]=new int[card+1];
                    }
                    ring[i]->getMonoid2(table2);

                    string *elements=new string[card+1];

                    ring[i]->getElements(card,elements);

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
                    corp[nr_corp].setNume(ring[i]->getNume());
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
        interogationMenu(operation,ring,nr_ring);
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
        Ring *ring[nr_ring+1];
        for(int i=1;i<=nr_ring;++i)
            ring[i]=new Ring;


        Corp *corp=new Corp[nr_ring+1];
        RealGroup realCorp;
        RationalGroup rationalCorp;
        ComplexCorp complexCorp;
        ZnCorp *znCorp=new ZnCorp[nr_ring+1];
        int nr_corp=0;
        int nr_zn=0;
        for(int i=1;i<=nr_ring;++i)
        {
            cin>>*ring[i];
            if(ring[i]->getType()!=0)
            {
                cout<<"Inelul "<<i<<"|"<<ring[i]->getNume()<<"\n";
                corp[++nr_corp].setCardinal(-1);
                corp[nr_corp].setType(ring[i]->getType());
                corp[nr_corp].setNume(ring[i]->getNume());
                if(ring[i]->getNume()=="Q")
                {
                    rationalCorp.setCardinal(-1);
                    rationalCorp.setType(1);
                    rationalCorp.setNume(ring[i]->getNume());
                }
                else
                {
                    if(ring[i]->getNume()=="R")
                    {
                        realCorp.setCardinal(-1);
                        realCorp.setType(2);
                        realCorp.setNume(ring[i]->getNume());
                    }
                    else
                    {
                        complexCorp.setCardinal(-1);
                        complexCorp.setType(2);
                        complexCorp.setNume(ring[i]->getNume());
                    }
                }

            }
            else if(ring[i]->getType()==0 and ring[i]->getNume().substr(0,2)=="Z/")
            {
                cout<<"Inelul "<<i<<"|"<<ring[i]->getNume()<<"\n";
                int **table1;
                int card=ring[i]->getCardinal();
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
                if(prim(ring[i]->getCardinal())==1)
                {
                    corp[++nr_corp].setNume(ring[i]->getNume());
                    corp[nr_corp].setCardinal(card);
                    corp[nr_corp].setOpTable(table1,table2,card);
                    znCorp[++nr_zn].setNume(ring[i]->getNume());
                    znCorp[nr_zn].setCardinal(card);
                    znCorp[nr_zn].setOpTable(table1,table2,card);
                }
            }
            else if(ring[i]->getType()==0 and ring[i]->getNume().substr(0,2)!="Z/")
            {
                ring[i]->setType(0);
                cout<<"Corp "<<ring[i]->getNume();
                //ring[i]->printData();
                if(ring[i]->testCorp()==1)
                {
                    cout<<"\n Da \n\n\n\n";
                    int card,type;
                    card=ring[i]->getCardinal();
                    int **table1;
                    table1 = new int*[card+1];
                    for(int i=1;i<=card;++i)
                    {
                        table1[i]=new int[card+1];
                    }
                    ring[i]->getMonoid1(card,type,table1);
                    int **table2;
                    table2 = new int*[card+1];
                    for(int i=1;i<=card;++i)
                    {
                        table2[i]=new int[card+1];
                    }
                    ring[i]->getMonoid2(table2);

                    string *elements=new string[card+1];

                    ring[i]->getElements(card,elements);

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
                    corp[nr_corp].setNume(ring[i]->getNume());
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
        interogationMenu(operation,ring,nr_ring);
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
    //input_MenuChoice(optionSelected);
    /*int operation=0;
    interogationMenu(operation);
    */

    /*verificare daca e in inel;
    ring.element[i]->a
    ring.element[j]->b

    corp1, corp2

    corp1==corp2 si != izomorfism*/

    int optionSelected=0;
    Interface *interface=Interface::getInstance();
    string optiuni[]={"Prin fisier","Prin consola","How to input"};
    interface->getOptions(optiuni,3);
    int selectedOption=0;
    interface->showInterfaceChoice(selectedOption);
    //amen
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
