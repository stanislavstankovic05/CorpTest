#include <bits/stdc++.h>
#include <string>
#include <conio.h>
#include <typeinfo>
#include <sstream>
#define upkey 72
#define downkey 80
#define enterkey 13
using namespace std;

//ofstream fout("output.out");
struct Ring
    {
        int tip;
        string Name;
        string *elements;
        int cardinal;
        int **addtiveTable;
        int **multiplicativeTable;

    };

struct Complex
    {
        double real_part;
        double imaginary_part;
    };

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

/*
Complex stringToComplex(string &str)
{
    Complex z;
    istringstream iss(str);
    char sign1, sign2;
    iss>>sign1>>z.real_part>>sign2;

    if (sign1=='-' && sign2=='-')
    {
        z.imaginary_part=-1.0;
    }
    else
    {
        if (sign2=='+')
        {
            iss >> z.imaginary_part;
        }
        else if (sign2=='-')
        {
            if (iss.peek()=='i')
            {
                z.imaginary_part=-1.0;
            }
            else
            {
                iss>>z.imaginary_part;
                z.imaginary_part*=-1.0;
            }
        }
    }
    return z;
}*/

string intToString(int n)
{
    string str;
    stringstream ss;
    ss<<n;
    str=ss.str();
    return str;

}
void redirection_Menu(int optionSelected);

void displayMenu(int selectOption)
{
    system("cls");

    cout << "===== Menu =====\n";
    if (selectOption==1)
        cout<<"> ";
    else
        cout<<" ";
    cout<<"1.Prin fiser\n";
    if (selectOption==2)
        cout<<"> ";
    else
        cout<<" ";
    cout<<"2.Prin consola\n";
    if (selectOption==3)
        cout<<"> ";
    else
        cout<<" ";
    cout<<"3.How to input\n";
    if (selectOption==4)
        cout<<"> ";
    else
        cout<<" ";
    cout<<"4.Exit\n";
    cout << "================\n";
}

void input_MenuChoice(int &optionSelected)
{
    int selectOption=1;

    while(optionSelected==0)
    {
        displayMenu(selectOption);
        int key_code = _getch(); // get the pressed key cod
        //cout<<key; get keycode
        switch (key_code) {
            case upkey: // Up arrow key
                if (selectOption - 1 < 1)
                {
                    selectOption = 4;
                }
                else
                    selectOption --;
                //selectOption = (selectOption - 1 < 1) ? 4 : selectOption - 1;
                break;

            case downkey: // Down arrow key
                if (selectOption + 1 > 4)
                {
                    selectOption = 1;
                }
                else
                    selectOption ++;
                //selectOption = (selectOption + 1 > 4) ? 1 : selectOption + 1;
                break;

            case enterkey: // Enter key
                switch (selectOption)
                {
                    case 1:
                        optionSelected=1;
                        break;

                    case 2:
                        optionSelected=2;
                        break;

                    case 3:
                        optionSelected=3;
                        break;

                    case 4:
                        cout << "Exiting the program." << "\n";
                        optionSelected=4;
                        break;
                }
                break;
        }
    }
    redirection_Menu(optionSelected);
}

void interogationMenu(int &operation,Ring corp[],int nr_sets);


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
        cout<<"exists";
        int nr_sets;

        fin>>nr_sets;
        cout<<nr_sets<<"\n";

        Ring *corp=new Ring[nr_sets+1];
        for(int i=1;i<=nr_sets;++i)
        {
            string set_name;
            fin>>set_name;
            cout<<set_name<<"\n";
            corp[i].Name=set_name;;
            bool continue_input=0;
            if (set_name=="R" || set_name=="Q" || set_name=="Z" || set_name=="C")
            {
                continue_input=0;
                corp[i].tip=2;
                corp[i].cardinal=-1;
                if(set_name=="Q")
                    corp[i].cardinal=-2;
            }
            else if (set_name.substr(0,2)=="Z/")
            {
                corp[i].tip=1;
                int n=extractNumber(set_name);
                if(prim(n)==1)
                    corp[i].tip=0;
                else
                    corp[i].tip=1;
                corp[i].cardinal=n;

                corp[i].elements= new string[n+1];
                for(int index=1;index<=n;++index)
                {
                    corp[i].elements[index]=intToString(index-1);
                }
                corp[i].multiplicativeTable=new int*[n+1];
                corp[i].addtiveTable=new int*[n+1];

                    for(int j=1;j<=n;++j)
                    {
                        corp[i].addtiveTable[j]=new int[n+1];
                        corp[i].multiplicativeTable[j]=new int[n+1];
                    }


                for(int index=1;index<=n;++index)
                {
                    for(int j=1;j<=n;++j)
                    {
                        //fout<<"cava\n";
                        //fout<<((i-1)+(j-1))%n+1<<" ";
                        corp[i].addtiveTable[index][j]=((index-1)+(j-1))%n+1;
                        corp[i].multiplicativeTable[index][j]=((index-1)*(j-1))%n+1;
                    }
                }
                ///de facut pentru Z/nZ
            }
            else if (set_name=="C")
            {
                continue_input=0;
                corp[i].tip=1;
                corp[i].cardinal=-1;
            }
            else
                continue_input=1;

            //fout<<corp[i].tip<<" ";
            if (continue_input==1)
            {
                int numberElements;
                fin>>numberElements;
                corp[i].tip=0;
                corp[i].cardinal=numberElements;
                string element;
                corp[i].elements=new string[corp[i].cardinal+1];
                for(int index=1;index<=numberElements;index++)
                {
                    fin>>element;
                    corp[i].elements[index]=element;
                }

                for(int index=1;index<=numberElements;index++)
                {
                    cout<<corp[i].elements[index]<<" ";
                }

                corp[i].addtiveTable=new int*[numberElements+1];
                cout<<numberElements<<"\n\n\n\n\n";
                for(int j=1;j<=numberElements;++j)
                {
                    cout<<"Indexii elementelor in relatie aditiva cu elementul"<<j<<"\n";
                    corp[i].addtiveTable[j]=new int[numberElements+1];
                    for(int index=1;index<=numberElements;index++)
                    {
                        int a;
                        bool validInput=false;
                        //while (validInput==false)
                        //{
                            fin>>a;
                            corp[i].addtiveTable[j][index]=a;
                        //}

                    }
                    cout<<"\n";
                }
                for(int j=1;j<=numberElements;++j)
                {
                    for(int index=1;index<=numberElements;index++)
                    {
                        cout<<corp[i].elements[corp[i].addtiveTable[j][index]]<<" ";

                    }
                    cout<<"\n";
                }

                corp[i].multiplicativeTable=new int*[numberElements+1];

                for(int j=1;j<=numberElements;++j)
                {
                    cout<<"Indexii elementelor in relatie multiplicativa cu elementul"<<j<<"\n";
                    corp[i].multiplicativeTable[j]=new int[numberElements+1];
                    for(int index=1;index<=numberElements;index++)
                    {
                        int a;
                        bool validInput=false;
                        //while (validInput==false)
                        //{
                            fin>>a;
                            int indexElement_a=0;
                            corp[i].multiplicativeTable[j][index]=a;
                        //}

                    }
                    cout<<"\n";
                }
                for(int j=1;j<=numberElements;++j)
                {
                    for(int index=1;index<=numberElements;index++)
                    {
                        cout<<corp[i].elements[corp[i].multiplicativeTable[j][index]]<<" ";

                    }
                    cout<<"\n";
                }
                /*for(int j=1; j<=numberElements; ++j)
                {
                    cout<<"Elementele in relatie aditiva cu elementul"<<j<<"\n";
                    for(int index=1;index<=numberElements;index++)
                    {
                        string a;
                        bool validInput=false;
                        //while (validInput==false)
                        //{
                            cin>>a;
                            int indexElement_a=0;
                            corp[i].addtiveTable[j][index]=indexElement_a;
                        //}
                    }
                    cout<<"\n";
                }*/

            }
        }
        int operation=0;
        interogationMenu(operation,corp,nr_sets);
    }
    else
    {
        cout<<"invalid_file";
        return;
    }
}
void ConsoleInput()
{
    int nr_sets;

        cin>>nr_sets;
        cout<<nr_sets<<"\n";

        Ring *corp=new Ring[nr_sets+1];
        for(int i=1;i<=nr_sets;++i)
        {
            string set_name;
            cin>>set_name;
            cout<<set_name<<"\n";
            corp[i].Name=set_name;;
            bool continue_input=0;
            if (set_name=="R" || set_name=="Q" || set_name=="Z" || set_name=="C")
            {
                continue_input=0;
                corp[i].tip=2;
                corp[i].cardinal=-1;
                if(set_name=="Q")
                    corp[i].cardinal=-2;
            }
            else if (set_name.substr(0,2)=="Z/")
            {
                corp[i].tip=1;
                int n=extractNumber(set_name);
                if(prim(n)==1)
                    corp[i].tip=0;
                else
                    corp[i].tip=1;
                corp[i].cardinal=n;

                corp[i].elements= new string[n+1];
                for(int index=1;index<=n;++index)
                {
                    corp[i].elements[index]=intToString(index-1);
                }
                corp[i].multiplicativeTable=new int*[n+1];
                corp[i].addtiveTable=new int*[n+1];

                    for(int j=1;j<=n;++j)
                    {
                        corp[i].addtiveTable[j]=new int[n+1];
                        corp[i].multiplicativeTable[j]=new int[n+1];
                    }
            }
            else
                continue_input=1;

            if (continue_input==1)
            {
                int numberElements;
                cin>>numberElements;
                corp[i].tip=0;
                corp[i].cardinal=numberElements;
                string element;
                corp[i].elements=new string[corp[i].cardinal+1];
                for(int index=1;index<=numberElements;index++)
                {
                    cin>>element;
                    corp[i].elements[index]=element;
                }

                for(int index=1;index<=numberElements;index++)
                {
                    cout<<corp[i].elements[index]<<" ";
                }

                corp[i].addtiveTable=new int*[numberElements+1];
                cout<<numberElements<<"\n\n\n\n\\n";
                for(int j=1;j<=numberElements;++j)
                {
                    cout<<"Indexii elementelor in relatie aditiva cu elementul"<<j<<"\n";
                    corp[i].addtiveTable[j]=new int[numberElements+1];
                    for(int index=1;index<=numberElements;index++)
                    {
                        int a;
                        bool validInput=false;
                        //while (validInput==false)
                        //{
                            cin>>a;
                            corp[i].addtiveTable[j][index]=a;
                        //}

                    }
                    cout<<"\n";
                }
                for(int j=1;j<=numberElements;++j)
                {
                    for(int index=1;index<=numberElements;index++)
                    {
                        cout<<corp[i].elements[corp[i].addtiveTable[j][index]]<<"("<<j<<" "<<index<<") ";

                    }
                    cout<<"\n";
                }

                corp[i].multiplicativeTable=new int*[numberElements+1];

                for(int j=1;j<=numberElements;++j)
                {
                    cout<<"Indexii elementelor in relatie multiplicativa cu elementul"<<j<<"\n";
                    corp[i].multiplicativeTable[j]=new int[numberElements+1];
                    for(int index=1;index<=numberElements;index++)
                    {
                        int a;
                        bool validInput=false;
                        //while (validInput==false)
                        //{
                            cin>>a;
                            int indexElement_a=0;
                            corp[i].multiplicativeTable[j][index]=a;
                        //}

                    }
                    cout<<"\n";
                }
                for(int j=1;j<=numberElements;++j)
                {
                    for(int index=1;index<=numberElements;index++)
                    {
                        cout<<corp[i].elements[corp[i].multiplicativeTable[j][index]]<<" ";

                    }
                    cout<<"\n";
                }
                /*for(int j=1; j<=numberElements; ++j)
                {
                    cout<<"Elementele in relatie aditiva cu elementul"<<j<<"\n";
                    for(int index=1;index<=numberElements;index++)
                    {
                        string a;
                        bool validInput=false;
                        //while (validInput==false)
                        //{
                            cin>>a;
                            int indexElement_a=0;
                            corp[i].addtiveTable[j][index]=indexElement_a;
                        //}
                    }
                    cout<<"\n";
                }*/

            }
        }
        int operation=0;
        interogationMenu(operation,corp,nr_sets);
}
void tutorialInput(int &optionSelected)
{
    cout<<"Inputul este de forma:\n";
    cout<<"nr_multimi\n";
    cout<<"Pentru fiecare multime se va specifica apoi:\n";
    cout<<"Numele sau litera multimii (R, Z, Z\nZ, Q si C sunt rezervate pentru cele implicite, iar in acest caz, interogarea se va finaliza)\n";
    cout<<"Nr de elemente\n";
    cout<<"elementele multimii\n";
    cout<<"relatiile specifice legii de compozitie '+'\n";
    cout<<"relatiile specifice legii de compozitie '*'\n";
    cout<<"----se va repeta aceleasi etape pana cand se vor fi citite toate structurile algebrice\n";
    cout<<"> Press Enter to return to menu\n";
    int key_code = _getch();
    if (key_code==enterkey)
    {
        optionSelected=0;
        input_MenuChoice(optionSelected);
    }

}

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

void displayInterogation(int &selectOption)
{
    system("cls");
    cout << "===== Interogation =====\n";
    if (selectOption==1)
        cout<<"> ";
    else
        cout<<" ";
    cout<<"1.Testeaza daca este corp\n";
    if (selectOption==2)
        cout<<"> ";
    else
        cout<<" ";
    cout<<"2.Realizeaza adunarea a 2 elemente\n";
    if (selectOption==3)
        cout<<"> ";
    else
        cout<<" ";
    cout<<"3.Realizeaza inmultirea a 2 elemente\n";
    if (selectOption==4)
        cout<<"> ";
    else
        cout<<" ";
    cout<<"4.Calculeaza elementele netru din corp\n";
    if (selectOption==5)
        cout<<"> ";
    else
        cout<<" ";
    cout<<"5.Calculeaza inversul si opusul unui element\n";
    if (selectOption==6)
        cout<<"> ";
    else
        cout<<" ";
    cout<<"6.Calculeaza ordinul unui element\n";
    if (selectOption==7)
        cout<<"> ";
    else
        cout<<" ";
    cout<<"7.Realizeaza scaderea a 2 elemente\n";
    if (selectOption==8)
        cout<<"> ";
    else
        cout<<" ";
    cout<<"8.Realizeaza impartirea a 2 elemente\n";
    if (selectOption==9)
        cout<<"> ";
    else
        cout<<" ";
    cout<<"9.Test izomorfism\n";
    if (selectOption==10)
        cout<<"> ";
    else
        cout<<" ";
    cout<<"10.Testare egalitate\n";
    if (selectOption==11)
        cout<<"> ";
    else
        cout<<" ";
    cout<<"11.Exit\n";
    cout << "================\n";

}

bool testCorp_associativity(Ring corp)
{
    //(a+b)+c=a+(b+c)
    for(int a=1;a<=corp.cardinal;++a)
    {
        for(int b=1;b<=corp.cardinal;++b)
        {
            for(int c=1;c<=corp.cardinal;++c)
            {
                if(corp.addtiveTable[corp.addtiveTable[a][b]][c]!=corp.addtiveTable[a][corp.addtiveTable[b][c]]
                    || corp.multiplicativeTable[corp.multiplicativeTable[a][b]][c]!=corp.multiplicativeTable[a][corp.multiplicativeTable[b][c]])
                    return 0;
            }
        }
    }
    return 1;
}
bool testCorp_comutative(Ring corp)
{
    for(int i=1;i<=corp.cardinal;++i)
    {
        for(int j=1;j<=i;++j)
        {
            if(corp.addtiveTable[i][j]!=corp.addtiveTable[j][i] || corp.multiplicativeTable[i][j]!=corp.multiplicativeTable[j][i])
                return 0;
        }
    }
    return 1;
}

bool testCorp_Neutral(Ring corp)
{
    int nrIndex_Neutral=0;
    for(int i=1;i<=corp.cardinal;++i)
    {
        bool neutral=1;
        for(int j=1;j<=corp.cardinal;++j)
        {
            //cout<<corp.addtiveTable[i][j]<<"| "<<i<<" "<<j<<"\n";
            if(corp.addtiveTable[i][j]!=j)
                neutral=0;
        }
        if(neutral==1)
            nrIndex_Neutral++;
    }
    int nrIndex_Neutral2=0;
    for(int i=1;i<=corp.cardinal;++i)
    {
        bool neutral=1;
        for(int j=1;j<=corp.cardinal;++j)
        {
            //cout<<corp.addtiveTable[i][j]<<"| "<<i<<" "<<j<<"\n";
            if(corp.multiplicativeTable[i][j]!=j)
                neutral=0;
        }
        if(neutral==1)
            nrIndex_Neutral2++;
    }
    //cout<<nrIndex_Neutral;
    if(nrIndex_Neutral!=1 || nrIndex_Neutral2!=1)
        return 0;
    else
        return 1;
}

bool testCorp_Inverse(Ring corp)
{
    int index_elementNeutral=0;
    for(int i=1;i<=corp.cardinal;++i)
    {
        bool neutral=1;
        for(int j=1;j<=corp.cardinal;++j)
        {
            if(corp.addtiveTable[i][j]!=j)
                neutral=0;
        }
        if(neutral==1)
        {
            index_elementNeutral=i;
            break;
        }
    }
    for(int i=1;i<=corp.cardinal;++i)
    {
        int nr_neutral=0;
        for (int j=1;j<=corp.cardinal;++j)
        {
            if(corp.addtiveTable[i][j]==index_elementNeutral)
            {
                nr_neutral++;
            }
        }
        if (nr_neutral!=1)
            return 0;
    }
    ///
    int index_elementNeutral2=0;
    for(int i=1;i<=corp.cardinal;++i)
    {
        bool neutral=1;
        for(int j=1;j<=corp.cardinal;++j)
        {
            if(corp.multiplicativeTable[i][j]!=j)
                neutral=0;
        }
        if(neutral==1)
        {
            index_elementNeutral2=i;
            break;
        }
    }
    //cout<<index_elementNeutral2;
    for(int i=1;i<=corp.cardinal;++i)
    {
        int nr_neutral=0;
        if(i!=index_elementNeutral)
        {
            for (int j=1;j<=corp.cardinal;++j)
            {
                if(corp.multiplicativeTable[i][j]==index_elementNeutral2)
                {
                    nr_neutral++;
                }
            }
            if (nr_neutral!=1)
                return 0;
        }
    }
    return 1;
}
bool testCorp(Ring corp)
{

    if (corp.tip==2 && corp.Name!="Z")
        return 1;
    else if (corp.tip==1)
        return 0;
    else if (testCorp_associativity(corp) and testCorp_Inverse(corp) and testCorp_Neutral(corp))
    {
        //cout<<testCorp_associativity(corp)<<" "<<testCorp_comutative(corp)<<" "<<testCorp_Neutral(corp)<<" "<<testCorp_Inverse(corp);
        return 1;
    }
    else
        return 0;
}
int index_Element(Ring corp, string a)
{
    for (int i=1;i<=corp.cardinal;++i)
    {
        if (corp.elements[i]==a)
            return i;
    }
    return -1;
}
int index_Element(Ring corp[], string a,int nr_sets)
{
    for (int i=1;i<=nr_sets;++i)
    {
        if (corp[i].Name==a and testCorp(corp[i])==1)
            return i;
    }
    return -1;
}
void addElements(Ring corp[],int nr_sets)
{
    if (nr_sets==1)
    {
        if (corp[nr_sets].tip==2)
            {
                if(corp[nr_sets].Name=="C")
                {
                    double a,b;
                    Complex z1;
                    Complex z2;
                    cout<<"Tastati partea reala si apoi partea imaginara a numarului dorit";
                    cin>>a>>b;
                    z1.real_part=a;
                    z1.imaginary_part=b;
                    cout<<"Tastati partea reala si apoi partea imaginara a numarului dorit";
                    cin>>a>>b;
                    z2.real_part=a;
                    z2.imaginary_part=b;
                    //cout<<z1.real_part-z2.real_part<<" "<<z1.imaginary_part-z2.imaginary_part<<"\n";
                    cout<<"Re"<<z1.real_part+z2.real_part<<" Im:"<<z1.imaginary_part+z2.imaginary_part<<"\n";
                }
                else
                {
                    double a,b;
                    cin>>a>>b;
                    cout<<a+b;
                }
            }
        else
        {

            for(int i=1;i<=corp[nr_sets].cardinal;++i)
                cout<<corp[nr_sets].elements[i]<<" ";
            cout<<"\n";
            cout<<"Selecteaza elementele pe care vrei sa le aduni \n";
            string a,b;
            cin>>a>>b;
            int index_A=index_Element(corp[nr_sets],a);
            int index_B=index_Element(corp[nr_sets],b);

            cout<<index_A<<" "<<index_B<<"\n\n";
            if(index_A==-1 || index_B==-1)
                cout<<"Invalid elements";
            else
                cout<<a<<" + "<<b<<" = "<<corp[nr_sets].elements[corp[nr_sets].addtiveTable[index_A][index_B]];
        }
    }
    else
    {
        int nr_corpuri=0;
        int indexCorpuri[nr_sets+1];
        for (int i=1;i<=nr_sets;++i)
        {
            if(testCorp(corp[i])==1)
            {
                nr_corpuri++;
                indexCorpuri[nr_corpuri]=i;
            }
        }
        if (nr_corpuri==0)
            cout<<"Multimile cu legile de compozitie date nu formeaza o structura de corp \n";
        else
        {
            cout<<"Tastati corpul in care se realizati operatia de adunare din lista urmatoare \n";
            for(int i=1;i<=nr_corpuri;++i)
            {
                cout<<corp[indexCorpuri[i]].Name<<" ";
            }
            cout<<"\n";
            string name;
            cin>>name;
            int indexName=index_Element(corp,name,nr_sets);
            if (indexName==-1)
                cout<<"Invalid input\n";
            else if (corp[indexName].tip==2)
            {
                cout<<corp[indexName].Name<<" "<<corp[indexName].tip<<"\n\n\n";
                if(corp[indexName].Name=="C")
                {
                    double a,b;
                    Complex z1;
                    Complex z2;
                    cout<<"Tastati partea reala si apoi partea imaginara a numarului dorit\n";
                    cin>>a>>b;
                    z1.real_part=a;
                    z1.imaginary_part=b;
                    cout<<"Tastati partea reala si apoi partea imaginara la al doilea numar dorit\n";
                    cin>>a>>b;
                    z2.real_part=a;
                    z2.imaginary_part=b;
                    cout<<"Re"<<z1.real_part-z2.real_part<<" Im:"<<z1.imaginary_part-z2.imaginary_part<<"\n";
                }
                else
                {
                    double a,b;
                    cin>>a>>b;
                    cout<<a+b;
                }
            }
            else
            {
                for(int i=1;i<=corp[indexName].cardinal;++i)
                    cout<<corp[indexName].elements[i]<<" ";
                cout<<"\n";
                cout<<"Selecteaza elementele pe care vrei sa le aduni \n";
                string a,b;
                cin>>a>>b;
                int index_A=index_Element(corp[indexName],a);
                int index_B=index_Element(corp[indexName],b);

                cout<<index_A<<" "<<index_B<<"\n\n";
                if(index_A==-1 || index_B==-1)
                    cout<<"Invalid elements";
                else
                    cout<<a<<" + "<<b<<" = "<<corp[indexName].elements[corp[indexName].addtiveTable[index_A][index_B]];
            }
        }
    }
}
void multiplyElements(Ring corp[],int nr_sets)
{
    if (nr_sets==1)
    {
            if (corp[nr_sets].tip==2)
            {
                    if(corp[nr_sets].Name=="C")
                    {
                        double a,b;
                        Complex z1;
                        Complex z2;
                        cout<<"Tastati partea reala si apoi partea imaginara a numarului dorit";
                        cin>>a>>b;
                        z1.real_part=a;
                        z1.imaginary_part=b;
                        cout<<"Tastati partea reala si apoi partea imaginara a numarului dorit";
                        cin>>a>>b;
                        z2.real_part=a;
                        z2.imaginary_part=b;
                        //cout<<z1.real_part-z2.real_part<<" "<<z1.imaginary_part-z2.imaginary_part<<"\n";
                        cout<<"Re"<<z1.real_part*z2.real_part-z1.imaginary_part*z2.imaginary_part<<" Im:"<<z1.imaginary_part*z2.real_part+z1.real_part*z2.imaginary_part<<"\n";
                    }
                    else
                    {
                        double a,b;
                        cin>>a>>b;
                        cout<<a*b;
                    }
            }
            else
            {
                for(int i=1;i<=corp[nr_sets].cardinal;++i)
                    cout<<corp[nr_sets].elements[i]<<" ";
                cout<<"\n";
                cout<<"Selecteaza elementele pe care vrei sa le aduni \n";
                string a,b;
                cin>>a>>b;
                int index_A=index_Element(corp[nr_sets],a);
                int index_B=index_Element(corp[nr_sets],b);

                cout<<index_A<<" "<<index_B<<"\n\n";
                if(index_A==-1 || index_B==-1)
                    cout<<"Invalid elements";
                else
                    cout<<a<<" * "<<b<<" = "<<corp[nr_sets].elements[corp[nr_sets].multiplicativeTable[index_A][index_B]];
            }
    }
    else
    {
        int nr_corpuri=0;
        int indexCorpuri[nr_sets+1];
        for (int i=1;i<=nr_sets;++i)
        {
            if(testCorp(corp[i])==1)
            {
                nr_corpuri++;
                indexCorpuri[nr_corpuri]=i;
            }
        }
        if (nr_corpuri==0)
            cout<<"Multimile cu legile de compozitie date nu formeaza o structura de corp \n";
        else
        {
            cout<<"Tastati corpul in care se realizati operatia de adunare din lista urmatoare \n";
            for(int i=1;i<=nr_corpuri;++i)
            {
                cout<<corp[indexCorpuri[i]].Name<<" ";
            }
            cout<<"\n";
            string name;
            cin>>name;
            int indexName=index_Element(corp,name,nr_sets);
            if (indexName==-1)
                cout<<"Invalid input\n";
            else if (corp[indexName].tip==2)
            {
                if(corp[indexName].Name=="C")
                {
                    double a,b;
                    Complex z1;
                    Complex z2;
                    cout<<"Tastati partea reala si apoi partea imaginara a numarului dorit\n";
                    cin>>a>>b;
                    z1.real_part=a;
                    z1.imaginary_part=b;
                    cout<<"Tastati partea reala si apoi partea imaginara la al doilea numar dorit\n";
                    cin>>a>>b;
                    z2.real_part=a;
                    z2.imaginary_part=b;
                    cout<<"Re"<<z1.real_part*z2.real_part-z1.imaginary_part*z2.imaginary_part<<" Im:"<<z1.imaginary_part*z2.real_part+z1.real_part*z2.imaginary_part<<"\n";
                }
                else
                {
                    double a,b;
                    cin>>a>>b;
                    cout<<a*b;
                }
            }
            else
            {
                for(int i=1;i<=corp[indexName].cardinal;++i)
                    cout<<corp[indexName].elements[i]<<" ";
                cout<<"\n";
                cout<<"Selecteaza elementele pe care vrei sa le inmultesti \n";
                string a,b;
                cin>>a>>b;
                int index_A=index_Element(corp[indexName],a);
                int index_B=index_Element(corp[indexName],b);

                cout<<index_A<<" "<<index_B<<"\n\n";
                if(index_A==-1 || index_B==-1)
                    cout<<"Invalid elements";
                else
                    cout<<a<<" * "<<b<<" = "<<corp[indexName].elements[corp[indexName].multiplicativeTable[index_A][index_B]];
            }
        }
    }
}
void findNeutralElement(Ring corp[],int nr_sets)
{
    if (nr_sets==1)
    {
        //else
        //{
                if(corp[nr_sets].tip==2)
                {
                    cout<<"Elementul neutru la adunare este: "<<0<<" iar la inmultire: "<<1;
                }
                else
                {
                    int indexName=nr_sets;
                    int Index_Neutral=0;
                    for(int i=1;i<=corp[indexName].cardinal;++i)
                    {
                        bool neutral=1;
                        for(int j=1;j<=corp[indexName].cardinal;++j)
                        {
                            if(corp[indexName].addtiveTable[i][j]!=j)
                                neutral=0;
                        }
                        if(neutral==1)
                        {
                            Index_Neutral=i;
                            break;
                        }
                    }
                    int Index_Neutral2=0;
                    for(int i=1;i<=corp[indexName].cardinal;++i)
                    {
                        bool neutral=1;
                        for(int j=1;j<=corp[indexName].cardinal;++j)
                        {
                            if(corp[indexName].multiplicativeTable[i][j]!=j)
                                neutral=0;
                        }
                        if(neutral==1)
                        {
                            Index_Neutral2=i;
                            break;
                        }
                    }
                    cout<<"Elementul neutru la adunare este: "<<corp[indexName].elements[Index_Neutral]<<" iar la inmultire: "<<corp[indexName].elements[Index_Neutral2];

            }
    }
    else
    {
        int nr_corpuri=0;
        int indexCorpuri[nr_sets+1];
        for (int i=1;i<=nr_sets;++i)
        {
            if(testCorp(corp[i])==1)
            {
                nr_corpuri++;
                indexCorpuri[nr_corpuri]=i;
            }
        }
        if (nr_corpuri==0)
            cout<<"Multimile cu legile de compozitie date nu formeaza o structura de corp \n";
        else
        {
            cout<<"Tastati corpul in care se realizati operatia de adunare din lista urmatoare \n";
            for(int i=1;i<=nr_corpuri;++i)
            {
                cout<<corp[indexCorpuri[i]].Name<<" ";
            }
            cout<<"\n";
            string name;
            cin>>name;
            int indexName=index_Element(corp,name,nr_sets);
            if (indexName==-1)
                cout<<"Invalid input\n";
            else if(corp[indexName].tip==2)
                {
                    cout<<"Elementul neutru la adunare este: "<<0<<" iar la inmultire: "<<1;
                }
            else
            {
                    int Index_Neutral=0;
                    for(int i=1;i<=corp[indexName].cardinal;++i)
                    {
                        bool neutral=1;
                        for(int j=1;j<=corp[indexName].cardinal;++j)
                        {
                            if(corp[indexName].addtiveTable[i][j]!=j)
                                neutral=0;
                        }
                        if(neutral==1)
                        {
                            Index_Neutral=i;
                            break;
                        }
                    }
                    int Index_Neutral2=0;
                    for(int i=1;i<=corp[indexName].cardinal;++i)
                    {
                        bool neutral=1;
                        for(int j=1;j<=corp[indexName].cardinal;++j)
                        {
                            if(corp[indexName].multiplicativeTable[i][j]!=j)
                                neutral=0;
                        }
                        if(neutral==1)
                        {
                            Index_Neutral2=i;
                            break;
                        }
                    }
                    cout<<"Elementul neutru la adunare este: "<<corp[indexName].elements[Index_Neutral]<<" iar la inmultire: "<<corp[indexName].elements[Index_Neutral2];


            }
        }
    }
}
void inverseElement(Ring corp[],int nr_sets)
{
    if (nr_sets==1)
    {
        if(corp[nr_sets].tip==2)
        {
            if(corp[nr_sets].Name=="C")
            {
                    double a,b;
                    Complex z1;
                    Complex z2;
                    cout<<"Tastati partea reala si apoi partea imaginara a numarului dorit\n";
                    cin>>a>>b;
                    z1.real_part=a;
                    z1.imaginary_part=b;

                    cout<<"Opus: Re"<<0-z1.real_part<<" Im:"<<0-z1.imaginary_part<<"\n";
                    cout<<"Invers: Re"<<1.0/z1.real_part<<" Im:"<<1.0/z1.imaginary_part<<"\n";
            }
            else
            {
                double a;
                cin>>a;
                cout<<"Opus "<<(-1)*a<<"\n";
                cout<<"Invers "<<1.0/a<<"\n";
            }
        }
        else
        {
            for(int i=1;i<=corp[nr_sets].cardinal;++i)
                cout<<corp[nr_sets].elements[i]<<" ";
            cout<<"\n";
            cout<<"Selecteaza elementul la care vrei sa calculezi inversul si opusul \n";
            string a;
            cin>>a;
            int index_A=index_Element(corp[nr_sets],a);
            if(index_A==-1)
                cout<<"Invalid elements";
            else
            {
                int index_elementNeutral=0;
                for(int i=1;i<=corp[nr_sets].cardinal;++i)
                {
                    bool neutral=1;
                    for(int j=1;j<=corp[nr_sets].cardinal;++j)
                    {
                        if(corp[nr_sets].addtiveTable[i][j]!=j)
                            neutral=0;
                    }
                    if(neutral==1)
                    {
                        index_elementNeutral=i;
                        break;
                    }
                }
                int index_elementNeutral2=0;
                for(int i=1;i<=corp[nr_sets].cardinal;++i)
                {
                    bool neutral=1;
                    for(int j=1;j<=corp[nr_sets].cardinal;++j)
                    {
                        if(corp[nr_sets].multiplicativeTable[i][j]!=j)
                            neutral=0;
                    }
                    if(neutral==1)
                    {
                        index_elementNeutral2=i;
                        break;
                    }
                }
                cout<<"\n\n";
                int indexInverse=0;
                for (int i=1;i<=corp[nr_sets].cardinal;++i)
                {
                    bool found=0;
                    if(corp[nr_sets].addtiveTable[index_A][i]==index_elementNeutral)
                    {
                        indexInverse=i;
                        found=1;
                    }
                    if (found==1)
                        break;
                }
                //cout<<corp[nr_sets].elements[indexInverse]<<"\n";
                if (index_elementNeutral!=index_A)
                {
                    int indexInverse2=0;
                    for (int i=1;i<=corp[nr_sets].cardinal;++i)
                    {
                        bool found=0;
                        //cout<<index_A<<" "<<i<<"->"<<corp[nr_sets].multiplicativeTable[index_A][i]<<"\n";
                        if(corp[nr_sets].multiplicativeTable[index_A][i]==index_elementNeutral2)
                        {
                            indexInverse2=i;
                            found=1;
                        }
                        if (found==1)
                            break;
                    }
                    //cout<<corp[nr_sets].elements[indexInverse2]<<"\n";
                    cout<<"Opusul este: "<<corp[nr_sets].elements[indexInverse]<<" ,iar inversul este: "<<corp[nr_sets].elements[indexInverse2];
                }
                else
                {
                    cout<<"Opusul este: "<<corp[nr_sets].elements[indexInverse]<<" ,si nu are invers";
                }
            }
        }
    }
    else
    {
        int nr_corpuri=0;
        int indexCorpuri[nr_sets+1];
        for (int i=1;i<=nr_sets;++i)
        {
            if(testCorp(corp[i])==1)
            {
                nr_corpuri++;
                indexCorpuri[nr_corpuri]=i;
            }
        }
        if (nr_corpuri==0)
            cout<<"Multimile cu legile de compozitie date nu formeaza o structura de corp \n";
        else
        {
            cout<<"Tastati corpul in care se realizati interogatia din lista urmatoare \n";
            for(int i=1;i<=nr_corpuri;++i)
            {
                cout<<corp[indexCorpuri[i]].Name<<" ";
            }
            cout<<"\n";
            string name;
            cin>>name;
            int indexName=index_Element(corp,name,nr_sets);
            if (indexName==-1)
                cout<<"Invalid input\n";
            else if(corp[indexName].tip==2)
            {
                if(corp[indexName].Name=="C")
                {
                        double a,b;
                        Complex z1;
                        Complex z2;
                        cout<<"Tastati partea reala si apoi partea imaginara a numarului dorit\n";
                        cin>>a>>b;
                        z1.real_part=a;
                        z1.imaginary_part=b;

                        cout<<"Opus: Re"<<0-z1.real_part<<" Im:"<<0-z1.imaginary_part<<"\n";
                        cout<<"Invers: Re"<<1.0/z1.real_part<<" Im:"<<1.0/z1.imaginary_part<<"\n";
                }
                else
                {
                    double a;
                    cin>>a;
                    cout<<"Opus "<<(-1)*a<<"\n";
                    cout<<"Invers "<<1.0/a<<"\n";
                }
            }

            else
            {
                for(int i=1;i<=corp[indexName].cardinal;++i)
                    cout<<corp[indexName].elements[i]<<" ";
                cout<<"\n";
                cout<<"Selecteaza elementul la care vrei sa calculezi inversul si opusul \n";
                string a;
                cin>>a;
                int index_A=index_Element(corp[indexName],a);
                if(index_A==-1)
                    cout<<"Invalid elements";
                else
                {
                    int index_elementNeutral=0;
                    for(int i=1;i<=corp[indexName].cardinal;++i)
                    {
                        bool neutral=1;
                        for(int j=1;j<=corp[indexName].cardinal;++j)
                        {
                            if(corp[indexName].addtiveTable[i][j]!=j)
                                neutral=0;
                        }
                        if(neutral==1)
                        {
                            index_elementNeutral=i;
                            break;
                        }
                    }
                    int index_elementNeutral2=0;
                    for(int i=1;i<=corp[indexName].cardinal;++i)
                    {
                        bool neutral=1;
                        for(int j=1;j<=corp[indexName].cardinal;++j)
                        {
                            if(corp[indexName].multiplicativeTable[i][j]!=j)
                                neutral=0;
                        }
                        if(neutral==1)
                        {
                            index_elementNeutral2=i;
                            break;
                        }
                    }
                    cout<<"\n\n";
                    int indexInverse=0;
                    for (int i=1;i<=corp[indexName].cardinal;++i)
                    {
                        bool found=0;
                        if(corp[indexName].addtiveTable[index_A][i]==index_elementNeutral)
                        {
                            indexInverse=i;
                            found=1;
                        }
                        if (found==1)
                            break;
                    }
                    //cout<<corp[nr_sets].elements[indexInverse]<<"\n";
                    if (index_elementNeutral!=index_A)
                    {
                        int indexInverse2=0;
                        for (int i=1;i<=corp[indexName].cardinal;++i)
                        {
                            bool found=0;
                            //cout<<index_A<<" "<<i<<"->"<<corp[nr_sets].multiplicativeTable[index_A][i]<<"\n";
                            if(corp[indexName].multiplicativeTable[index_A][i]==index_elementNeutral2)
                            {
                                indexInverse2=i;
                                found=1;
                            }
                            if (found==1)
                                break;
                        }
                        //cout<<corp[nr_sets].elements[indexInverse2]<<"\n";
                        cout<<"Opusul este: "<<corp[indexName].elements[indexInverse]<<" ,iar inversul este: "<<corp[indexName].elements[indexInverse2];
                    }
                    else
                    {
                        cout<<"Opusul este: "<<corp[indexName].elements[indexInverse]<<" ,si nu are invers";
                    }

                }
            }
        }
    }
}
void ordinElement(Ring corp[], int nr_sets)
{
    if (nr_sets==1)
    {
        if(corp[nr_sets].tip==2)
        {
            cout<<"Nu exista\n";
        }
        else
        {
            for(int i=1;i<=corp[nr_sets].cardinal;++i)
                cout<<corp[nr_sets].elements[i]<<" ";
            cout<<"\n";
            cout<<"Selecteaza elementul la care vrei sa calculezi ordinele \n";
            string a;
            cin>>a;
            int index_A=index_Element(corp[nr_sets],a);
            if(index_A==-1)
                cout<<"Invalid elements";
            else
            {
                int index_elementNeutral=0;
                for(int i=1;i<=corp[nr_sets].cardinal;++i)
                {
                    bool neutral=1;
                    for(int j=1;j<=corp[nr_sets].cardinal;++j)
                    {
                        if(corp[nr_sets].addtiveTable[i][j]!=j)
                            neutral=0;
                    }
                    if(neutral==1)
                    {
                        index_elementNeutral=i;
                        break;
                    }
                }
                int index_elementNeutral2=0;
                for(int i=1;i<=corp[nr_sets].cardinal;++i)
                {
                    bool neutral=1;
                    for(int j=1;j<=corp[nr_sets].cardinal;++j)
                    {
                        if(corp[nr_sets].multiplicativeTable[i][j]!=j)
                            neutral=0;
                    }
                    if(neutral==1)
                    {
                        index_elementNeutral2=i;
                        break;
                    }
                }
                cout<<"\n\n";
                int auxiliar=index_elementNeutral;
                int ordAdunare=1;
                while (corp[nr_sets].addtiveTable[auxiliar][index_A]!=index_elementNeutral)
                {
                    auxiliar=corp[nr_sets].addtiveTable[auxiliar][index_A];
                    ordAdunare++;
                }

                auxiliar=index_elementNeutral2;
                int ordMult=1;
                while (corp[nr_sets].multiplicativeTable[auxiliar][index_A]!=index_elementNeutral2)
                {
                    auxiliar=corp[nr_sets].multiplicativeTable[auxiliar][index_A];
                    ordMult++;
                }
                cout<<"Ordinele sunt: "<<ordAdunare<<" "<<ordMult;
            }
        }
    }
    else
    {
        int nr_corpuri=0;
        int indexCorpuri[nr_sets+1];
        for (int i=1;i<=nr_sets;++i)
        {
            if(testCorp(corp[i])==1)
            {
                nr_corpuri++;
                indexCorpuri[nr_corpuri]=i;
            }
        }
        if (nr_corpuri==0)
            cout<<"Multimile cu legile de compozitie date nu formeaza o structura de corp \n";
        else
        {
            cout<<"Tastati corpul in care se realizati interogatia din lista urmatoare \n";
            for(int i=1;i<=nr_corpuri;++i)
            {
                cout<<corp[indexCorpuri[i]].Name<<" ";
            }
            cout<<"\n";
            string name;
            cin>>name;
            int indexName=index_Element(corp,name,nr_sets);
            if (indexName==-1)
                cout<<"Invalid input\n";
            else if(corp[indexName].tip==2)
            {
                cout<<"Nu exista\n";
            }
            else if(corp[indexName].Name=="R")
            {
                double a;
                cin>>a;
                cout<<"Opus "<<(-1)*a<<"\n";
                cout<<"Invers "<<1.0/a<<"\n";
            }
            else
            {
                for(int i=1;i<=corp[indexName].cardinal;++i)
                    cout<<corp[indexName].elements[i]<<" ";
                cout<<"\n";
                cout<<"Selecteaza elementul la care vrei sa calculezi inversul si opusul \n";
                string a;
                cin>>a;
                int index_A=index_Element(corp[indexName],a);
                if(index_A==-1)
                    cout<<"Invalid elements";
                else
                {
                    int index_elementNeutral=0;
                    for(int i=1;i<=corp[indexName].cardinal;++i)
                    {
                        bool neutral=1;
                        for(int j=1;j<=corp[indexName].cardinal;++j)
                        {
                            if(corp[indexName].addtiveTable[i][j]!=j)
                                neutral=0;
                        }
                        if(neutral==1)
                        {
                            index_elementNeutral=i;
                            break;
                        }
                    }
                    int index_elementNeutral2=0;
                    for(int i=1;i<=corp[indexName].cardinal;++i)
                    {
                        bool neutral=1;
                        for(int j=1;j<=corp[indexName].cardinal;++j)
                        {
                            if(corp[indexName].multiplicativeTable[i][j]!=j)
                                neutral=0;
                        }
                        if(neutral==1)
                        {
                            index_elementNeutral2=i;
                            break;
                        }
                    }
                    cout<<"\n\n";
                    int auxiliar=index_elementNeutral;
                    int ordAdunare=1;
                    while (corp[indexName].addtiveTable[auxiliar][index_A]!=index_elementNeutral)
                    {
                        auxiliar=corp[indexName].addtiveTable[auxiliar][index_A];
                        ordAdunare++;
                    }

                    auxiliar=index_elementNeutral2;
                    int ordMult=1;
                    while (corp[indexName].multiplicativeTable[auxiliar][index_A]!=index_elementNeutral2)
                    {
                        auxiliar=corp[indexName].multiplicativeTable[auxiliar][index_A];
                        ordMult++;
                    }
                    cout<<"Ordinele sunt: "<<ordAdunare<<" "<<ordMult;
                }
            }
        }
    }
}
void izomorfism(Ring corp[], int nr_sets)
{
        int nr_corpuri=0;
        int indexCorpuri[nr_sets+1];
        for (int i=1;i<=nr_sets;++i)
        {
            if(testCorp(corp[i])==1)
            {
                nr_corpuri++;
                indexCorpuri[nr_corpuri]=i;
            }
        }
        if (nr_corpuri==0)
            cout<<"Multimile cu legile de compozitie date nu formeaza o structura de corp \n";
        else if (nr_corpuri==1)
            cout<<"Insuficiente corpuri.Va rugam sa introduceti macar 2 corpuri";
        else
        {
            cout<<"Tastati corpurile la care sa verificati izomorfia\n";
            for(int i=1;i<=nr_corpuri;++i)
            {
                cout<<corp[indexCorpuri[i]].Name<<" ";
            }
            cout<<"\n";
            string name1,name2;
            cin>>name1>>name2;
            int indexName1=index_Element(corp,name1,nr_sets);
            int indexName2=index_Element(corp,name2,nr_sets);
            if (indexName1==-1 || indexName2==-1)
                cout<<"Invalid input\n";
            else
            {
                if(corp[indexName1].tip==2 and corp[indexName2].tip==2)
                {
                    if(corp[indexName1].cardinal==corp[indexName2].cardinal)
                        cout<<"Sunt izomorfe";
                    else
                        cout<<"Nu sunt izomorfe";
                    return;
                }
                else if(corp[indexName1].tip==0 and corp[indexName2].tip==0)
                {
                    if(corp[indexName1].cardinal!=corp[indexName2].cardinal)
                    {
                        cout<<"Corpurile nu sunt izomorfe";
                        return;
                    }
                    int line_found=0;
                    bool test1=0;
                    for(int i=1;i<=corp[indexName1].cardinal;++i)
                    {
                        bool gasit=1;
                        for (int j=1;j<=corp[indexName2].cardinal;++j)
                        {
                            gasit=1;
                            for(int k=1;k<=corp[indexName2].cardinal;++k)
                            {
                                if(corp[indexName1].addtiveTable[i][k]!=corp[indexName2].addtiveTable[j][k]
                                   || corp[indexName1].multiplicativeTable[i][k]!=corp[indexName2].multiplicativeTable[j][k])
                                   gasit=0;
                            }
                            if(gasit=1)
                            {
                                line_found++;
                                break;
                            }
                        }
                    }
                    if (line_found!=corp[indexName1].cardinal)
                        cout<<"Corpurile date nu sunt izomorfe";
                    else
                        cout<<"Corpurile sunt izomorfe";
                }
                else if(corp[indexName1].tip!=2 || corp[indexName2].tip!=2 and corp[indexName1].cardinal!=corp[indexName2].cardinal)
                {
                    cout<<"Nu sunt izomorfe";
                    return;
                }
            }
        }
}
int index_Element_Opus(Ring corp,string a)
{
    int index_A=index_Element(corp,a);
    int index_elementNeutral=0;
    for(int i=1;i<=corp.cardinal;++i)
    {
        bool neutral=1;
        for(int j=1;j<=corp.cardinal;++j)
        {
            if(corp.addtiveTable[i][j]!=j)
                neutral=0;
        }
        if(neutral==1)
        {
            index_elementNeutral=i;
            break;
        }
    }
    int indexInverse=0;
    for (int i=1;i<=corp.cardinal;++i)
    {
        bool found=0;
        if(corp.addtiveTable[index_A][i]==index_elementNeutral)
        {
            indexInverse=i;
            found=1;
        }
        if (found==1)
            break;
    }
    return indexInverse;
}

int index_Element_Inverse(Ring corp,string a)
{
    int index_A=index_Element(corp,a);
    int index_elementNeutral2=0;
    for(int i=1;i<=corp.cardinal;++i)
    {
        bool neutral=1;
        for(int j=1;j<=corp.cardinal;++j)
        {
            if(corp.multiplicativeTable[i][j]!=j)
                neutral=0;
        }
        if(neutral==1)
        {
            index_elementNeutral2=i;
            break;
        }

    }
    int indexInverse2=0;
    for (int i=1;i<=corp.cardinal;++i)
    {
        bool found=0;
        //cout<<index_A<<" "<<i<<"->"<<corp[nr_sets].multiplicativeTable[index_A][i]<<"\n";
        if(corp.multiplicativeTable[index_A][i]==index_elementNeutral2)
        {
            indexInverse2=i;
            found=1;
        }
        if (found==1)
            break;
    }
    return indexInverse2;
}
void scadere(Ring corp[],int nr_sets)
{
    if (nr_sets==1)
    {
        if (corp[nr_sets].tip==2)
            {
                if(corp[nr_sets].Name=="C")
                {
                    double a,b;
                    Complex z1;
                    Complex z2;
                    cout<<"Tastati partea reala si apoi partea imaginara a numarului dorit";
                    cin>>a>>b;
                    z1.real_part=a;
                    z1.imaginary_part=b;
                    cout<<"Tastati partea reala si apoi partea imaginara a numarului dorit";
                    cin>>a>>b;
                    z2.real_part=a;
                    z2.imaginary_part=b;
                    //cout<<z1.real_part-z2.real_part<<" "<<z1.imaginary_part-z2.imaginary_part<<"\n";
                    cout<<"Re"<<z1.real_part-z2.real_part<<" Im:"<<z1.imaginary_part-z2.imaginary_part<<"\n";
                }
                else if(corp[nr_sets].Name=="Q" and corp[nr_sets].Name=="R")
                {
                    double a,b;
                    cin>>a>>b;
                    cout<<a-b;
                }
                else
                {
                    int a,b;
                    cin>>a>>b;
                    int n=extractNumber(corp[nr_sets].Name);
                    cout<<(a-b)%n;
                }
            }
        else
        {
        for(int i=1;i<=corp[nr_sets].cardinal;++i)
            cout<<corp[nr_sets].elements[i]<<" ";
        cout<<"\n";
        cout<<"Selecteaza elementele pe care vrei sa le scazi \n";
        string a,b;
        cin>>a>>b;
        int index_A=index_Element(corp[nr_sets],a);
        int index_B=index_Element_Opus(corp[nr_sets],b);

        cout<<index_A<<" "<<index_B<<"\n\n";
        if(index_A==-1 || index_B==-1)
            cout<<"Invalid elements";

        else
            cout<<a<<" - "<<b<<" = "<<corp[nr_sets].elements[corp[nr_sets].addtiveTable[index_A][index_B]];
        }
    }
    else
    {
        int nr_corpuri=0;
        int indexCorpuri[nr_sets+1];
        for (int i=1;i<=nr_sets;++i)
        {
            if(testCorp(corp[i])==1)
            {
                nr_corpuri++;
                indexCorpuri[nr_corpuri]=i;
            }
        }
        if (nr_corpuri==0)
            cout<<"Multimile cu legile de compozitie date nu formeaza o structura de corp \n";
        else
        {
            cout<<"Tastati corpul in care se realizati operatia de scadere din lista urmatoare \n";
            for(int i=1;i<=nr_corpuri;++i)
            {
                cout<<corp[indexCorpuri[i]].Name<<" ";
            }
            cout<<"\n";
            string name;
            cin>>name;
            int indexName=index_Element(corp,name,nr_sets);
            if (indexName==-1)
                cout<<"Invalid input\n";
            if (corp[indexName].tip==2)
            {
                if(corp[indexName].Name=="C")
                {
                    double a,b;
                    Complex z1;
                    Complex z2;
                    cout<<"Tastati partea reala si apoi partea imaginara a numarului dorit";
                    cin>>a>>b;
                    z1.real_part=a;
                    z1.imaginary_part=b;
                    cout<<"Tastati partea reala si apoi partea imaginara a numarului dorit";
                    cin>>a>>b;
                    z2.real_part=a;
                    z2.imaginary_part=b;
                    //cout<<z1.real_part-z2.real_part<<" "<<z1.imaginary_part-z2.imaginary_part<<"\n";
                    cout<<"Re"<<z1.real_part-z2.real_part<<" Im:"<<z1.imaginary_part-z2.imaginary_part<<"\n";
                }
                else if(corp[indexName].Name=="Q" and corp[indexName].Name=="R")
                {
                    double a,b;
                    cin>>a>>b;
                    cout<<a-b;
                }
                else
                {
                    int a,b;
                    cin>>a>>b;
                    int n=extractNumber(corp[indexName].Name);
                    cout<<(a-b)%n;
                }
            }

            else
            {
                for(int i=1;i<=corp[indexName].cardinal;++i)
                    cout<<corp[indexName].elements[i]<<" ";
                cout<<"\n";
                cout<<"Selecteaza elementele pe care vrei sa le scazi \n";
                string a,b;
                cin>>a>>b;
                int index_A=index_Element(corp[indexName],a);
                int index_B=index_Element_Opus(corp[indexName],b);

                cout<<index_A<<" "<<index_B<<"\n\n";
                if(index_A==-1 || index_B==-1)
                    cout<<"Invalid elements";
                else
                    cout<<a<<" - "<<b<<" = "<<corp[indexName].elements[corp[indexName].addtiveTable[index_A][index_B]];
            }
        }
    }
}
void impartire(Ring corp[],int nr_sets)
{
    if (nr_sets==1)
    {
        if (corp[nr_sets].tip==2)
            {
                if(corp[nr_sets].Name=="C")
                {
                    double a,b;
                    Complex z1;
                    Complex z2;
                    cout<<"Tastati partea reala si apoi partea imaginara a numarului dorit";
                    cin>>a>>b;
                    z1.real_part=a;
                    z1.imaginary_part=b;
                    cout<<"Tastati partea reala si apoi partea imaginara a numarului dorit";
                    cin>>a>>b;
                    z2.real_part=a;
                    z2.imaginary_part=b;
                    //cout<<z1.real_part-z2.real_part<<" "<<z1.imaginary_part-z2.imaginary_part<<"\n";
                    cout<<"Re"<<(z1.real_part*z2.real_part-z1.imaginary_part*z2.imaginary_part)/(z2.real_part*z2.real_part-z2.imaginary_part*z2.imaginary_part)<<" Im:"<<(z1.imaginary_part*z2.real_part+z1.real_part*z2.imaginary_part)/(z2.real_part*z2.real_part-z2.imaginary_part*z2.imaginary_part)<<"\n";
                }
                else
                {
                    double a,b;
                    cin>>a>>b;
                    cout<<a/b;
                }
            }
        else
        {
            for(int i=1;i<=corp[nr_sets].cardinal;++i)
                cout<<corp[nr_sets].elements[i]<<" ";
            cout<<"\n";
            cout<<"Selecteaza elementele pe care vrei sa le imparti \n";
            string a,b;
            cin>>a>>b;
            int index_A=index_Element(corp[nr_sets],a);
            int index_B=index_Element_Inverse(corp[nr_sets],b);

            cout<<index_A<<" "<<index_B<<"\n\n";
            if(index_A==-1 || index_B==-1)
                cout<<"Invalid elements";
            else
                cout<<a<<" / "<<b<<" = "<<corp[nr_sets].elements[corp[nr_sets].multiplicativeTable[index_A][index_B]];
        }
    }
    else
    {
        int nr_corpuri=0;
        int indexCorpuri[nr_sets+1];
        for (int i=1;i<=nr_sets;++i)
        {
            if(testCorp(corp[i])==1)
            {
                nr_corpuri++;
                indexCorpuri[nr_corpuri]=i;
            }
        }
        if (nr_corpuri==0)
            cout<<"Multimile cu legile de compozitie date nu formeaza o structura de corp \n";
        else
        {
            cout<<"Tastati corpul in care se realizati operatia de impartire din lista urmatoare \n";
            for(int i=1;i<=nr_corpuri;++i)
            {
                cout<<corp[indexCorpuri[i]].Name<<" ";
            }
            cout<<"\n";
            string name;
            cin>>name;
            int indexName=index_Element(corp,name,nr_sets);
            if (indexName==-1)
                cout<<"Invalid input\n";
            else if(corp[indexName].tip==2)
            {
                if(corp[indexName].Name=="C")
                {
                    double a,b;
                    Complex z1;
                    Complex z2;
                    cout<<"Tastati partea reala si apoi partea imaginara a numarului dorit \n";
                    cin>>a>>b;
                    z1.real_part=a;
                    z1.imaginary_part=b;
                    cout<<"Tastati partea reala si apoi partea imaginara a numarului dorit \n";
                    cin>>a>>b;
                    z2.real_part=a;
                    z2.imaginary_part=b;
                    //cout<<z1.real_part-z2.real_part<<" "<<z1.imaginary_part-z2.imaginary_part<<"\n";
                    cout<<"Re"<<(z1.real_part*z2.real_part-z1.imaginary_part*z2.imaginary_part)/(z2.real_part*z2.real_part-z2.imaginary_part*z2.imaginary_part)<<" Im:"<<(z1.imaginary_part*z2.real_part+z1.real_part*z2.imaginary_part)/(z2.real_part*z2.real_part-z2.imaginary_part*z2.imaginary_part)<<"\n";
                }
                else
                {
                    double a,b;
                    cin>>a>>b;
                    cout<<a/b;
                }
            }
            else
            {
                for(int i=1;i<=corp[indexName].cardinal;++i)
                    cout<<corp[indexName].elements[i]<<" ";
                cout<<"\n";
                cout<<"Selecteaza elementele pe care vrei sa le scazi \n";
                string a,b;
                cin>>a>>b;
                int index_A=index_Element(corp[indexName],a);
                int index_B=index_Element_Inverse(corp[indexName],b);

                cout<<index_A<<" "<<index_B<<"\n\n";
                if(index_A==-1 || index_B==-1)
                    cout<<"Invalid elements";
                else
                    cout<<a<<" / "<<b<<" = "<<corp[indexName].elements[corp[indexName].multiplicativeTable[index_A][index_B]];
            }
        }
    }
}
void egalitate(Ring corp[], int nr_sets)
{
    if (nr_sets==1)
    {
        if(corp[nr_sets].tip==0)
        {
            if (corp[nr_sets].Name.substr(0,2)=="Z/")
                    {
                        cout<<"Selecteaza elementele pe care vrei sa le compari \n";
                        int n=extractNumber(corp[nr_sets].Name);
                        cout<<n<<"\n\n\n";
                        int a,b;
                        cin>>a>>b;
                        if (a%n < b%n)
                            cout<<a<<" < "<<b;
                        else if (a%n > b%n)
                            cout<<a<<" > "<<b;
                        else
                            cout<<a<<" = "<<b;
                    }
            else
            {
                for(int i=1;i<=corp[nr_sets].cardinal;++i)
                    cout<<corp[nr_sets].elements[i]<<" ";
                cout<<"\n";
                cout<<"Selecteaza elementele pe care vrei sa le compari \n";
                string a,b;
                cin>>a>>b;
                int index_A=index_Element(corp[nr_sets],a);
                int index_B=index_Element(corp[nr_sets],b);

                cout<<index_A<<" "<<index_B<<"\n\n";
                if(index_A==-1 || index_B==-1)
                    cout<<"Invalid elements";
                else
                    if(a!=b)
                        cout<<a<< "!= " <<b;
                    else
                        cout<<a<<" == " <<b;
            }
        }
        else
        {
            if(corp[nr_sets].tip==2)
                {
                    if (corp[nr_sets].Name=="R" || corp[nr_sets].Name=="Q" || corp[nr_sets].Name=="C")
                    {
                        if(corp[nr_sets].Name=="C")
                        {
                            double a,b;
                            Complex z1;
                            Complex z2;
                            cout<<"Tastati partea reala si apoi partea imaginara a numarului dorit";
                            cin>>a>>b;
                            z1.real_part=a;
                            z1.imaginary_part=b;
                            cout<<"Tastati partea reala si apoi partea imaginara a numarului dorit";
                            cin>>a>>b;
                            z2.real_part=a;
                            z2.imaginary_part=b;

                            if(z1.real_part==z2.real_part and z1.imaginary_part==z2.imaginary_part)
                                cout<<"Numerele sunt egale";
                            else if(z1.real_part*z1.real_part+z1.imaginary_part*z1.imaginary_part<z2.real_part*z2.real_part+z2.imaginary_part*z2.imaginary_part)
                                cout<<"Primul numar e mai mic\n";
                            else
                                cout<<"Al doilea numar e mai mic \n";
                        }
                        else
                        {
                            cout<<"Selecteaza elementele pe care vrei sa le compari \n";
                            double a,b;
                            cin>>a>>b;
                            if(a<b)
                                cout<<a<<" < "<<b;
                            else if( a>b)
                                cout<<a<<" > "<<b;
                            else
                                cout<<a<<" = "<<b;
                        }

                    }
                }
        }
    }
    else
    {
        int nr_corpuri=0;
        int indexCorpuri[nr_sets+1];
        for (int i=1;i<=nr_sets;++i)
        {
            if(testCorp(corp[i])==1)
            {
                nr_corpuri++;
                indexCorpuri[nr_corpuri]=i;
            }
        }
        if (nr_corpuri==0)
            cout<<"Multimile cu legile de compozitie date nu formeaza o structura de corp \n";
        else
        {
            cout<<"Tastati corpul in care se sa comparati elementele din lista urmatoare \n";
            for(int i=1;i<=nr_corpuri;++i)
            {
                cout<<corp[indexCorpuri[i]].Name<<" ";
            }
            cout<<"\n";
            string name;
            cin>>name;
            int indexName=index_Element(corp,name,nr_sets);
            if (indexName==-1)
                cout<<"Invalid input\n";
            else if(corp[indexName].tip==2)
            {
                if (corp[indexName].Name=="R" || corp[indexName].Name=="Q" || corp[indexName].Name=="C")
                    {
                        if(corp[indexName].Name=="C")
                        {
                            double a,b;
                            Complex z1;
                            Complex z2;
                            cout<<"Tastati partea reala si apoi partea imaginara a numarului dorit";
                            cin>>a>>b;
                            z1.real_part=a;
                            z1.imaginary_part=b;
                            cout<<"Tastati partea reala si apoi partea imaginara a numarului dorit";
                            cin>>a>>b;
                            z2.real_part=a;
                            z2.imaginary_part=b;

                            if(z1.real_part==z2.real_part and z1.imaginary_part==z2.imaginary_part)
                                cout<<"Numerele sunt egale";
                            else if(z1.real_part*z1.real_part+z1.imaginary_part*z1.imaginary_part<z2.real_part*z2.real_part+z2.imaginary_part*z2.imaginary_part)
                                cout<<"Primul numar e mai mic\n";
                            else
                                cout<<"Al doilea numar e mai mic \n";
                        }
                        else
                        {
                            cout<<"Selecteaza elementele pe care vrei sa le compari \n";
                            double a,b;
                            cin>>a>>b;
                            if(a<b)
                                cout<<a<<" < "<<b;
                            else if( a>b)
                                cout<<a<<" > "<<b;
                            else
                                cout<<a<<" = "<<b;
                        }

                    }
            }
            else
            {
                if(corp[indexName].Name.substr(0,2)=="Z/")
                {
                     cout<<"Selecteaza elementele pe care vrei sa le compari \n";
                        int n=extractNumber(corp[indexName].Name);
                        cout<<n<<"\n\n\n";
                        int a,b;
                        cin>>a>>b;
                        if (a%n < b%n)
                            cout<<a<<" < "<<b;
                        else if (a%n > b%n)
                            cout<<a<<" > "<<b;
                        else
                            cout<<a<<" = "<<b;
                }
                else
                {
                    for(int i=1;i<=corp[indexName].cardinal;++i)
                        cout<<corp[indexName].elements[i]<<" ";
                    cout<<"\n";
                    cout<<"Selecteaza elementele pe care vrei sa le compari \n";
                    string a,b;
                    cin>>a>>b;
                    int index_A=index_Element(corp[indexName],a);
                    int index_B=index_Element(corp[indexName],b);

                    cout<<index_A<<" "<<index_B<<"\n\n";
                    if(index_A==-1 || index_B==-1)
                        cout<<"Invalid elements";
                    else
                        if(a!=b)
                            cout<<a<< "!= " <<b;
                        else
                            cout<<a<<" == " <<b;
                }
            }

        }
    }


}


Ring destroyRing(Ring corp)
{
        delete[] corp.elements;

        // Deallocate additiveTable
        if (corp.addtiveTable != 0) {
            for (int i = 0; i < corp.cardinal; ++i)
                delete[] corp.addtiveTable[i];
            delete[] corp.addtiveTable;
        }

        // Deallocate multiplicativeTable
        if (corp.multiplicativeTable != 0) {
            for (int i = 0; i < corp.cardinal; ++i)
                delete[] corp.multiplicativeTable[i];
            delete[] corp.multiplicativeTable;
        }
    }

void destroy(Ring corp[],int nr_sets)
{
    for (int i=1;i<=nr_sets;++i)
    {
        destroyRing(corp[i]);
    }
    delete[] corp;
}
void answerInterogation(int &selectedOption, Ring corp[], int nr_sets)
{
    //system("cls");
    while (selectedOption!=0)
    {
        switch (selectedOption)
        {
            case 1:
                for (int i=1;i<=nr_sets;++i)
                {
                    if(corp[i].Name.substr(0,2)=="Z/")
                        cout<<extractNumber(corp[i].Name)<<"\n\n\n";
                    if (testCorp(corp[i])==1)
                        cout<<"Inelul "<<corp[i].Name<<" este corp \n";
                    else
                        cout<<"Inelul "<<corp[i].Name<<" nu este corp \n";
                }
                selectedOption=0;
                break;
            case 2:
                addElements(corp,nr_sets);
                selectedOption=0;
                break;
            case 3:
                multiplyElements(corp,nr_sets);
                selectedOption=0;
                break;
            case 4:
                findNeutralElement(corp,nr_sets);
                selectedOption=0;
                break;
            case 5:
                inverseElement(corp,nr_sets);
                selectedOption=0;
                break;
            case 6:
                ordinElement(corp,nr_sets);
                selectedOption=0;
                break;
            case 7:
                scadere(corp,nr_sets);
                selectedOption=0;
                break;
            case 8:
                impartire(corp,nr_sets);
                selectedOption=0;
                break;
            case 9:
                izomorfism(corp,nr_sets);
                selectedOption=0;
                break;
            case 10:
                egalitate(corp,nr_sets);
                selectedOption=0;
                break;
            case 11:
                destroy(corp,nr_sets);
                selectedOption=0;
                break;
        }
    }
    int key_code = _getch();
    if (key_code==enterkey)
    {
        selectedOption=0;
        return;
    }
}
void interogationMenu(int &optionSelected, Ring corp[],int nr_sets)
{
    int selectOption=1;

    while(optionSelected==0)
    {
        displayInterogation(selectOption);
        int key_code = _getch();

        switch (key_code)
        {
            case upkey: // Up arrow key
                if (selectOption - 1 < 1)
                {
                    selectOption = 11;
                }
                else
                    selectOption --;
                break;

            case downkey:
                if (selectOption + 1 > 11)
                {
                    selectOption = 1;
                }
                else
                    selectOption ++;

                break;

            case enterkey:
                switch (selectOption)
                {
                    case 1:
                        cout << "Testare daca multimea/multimile date sunt corpuri" << "\n";
                        optionSelected=1;
                        answerInterogation(optionSelected,corp,nr_sets);
                        break;

                    case 2:
                        cout << "Realizeaza adunarea a doua elemente" << "\n";
                        optionSelected=2;
                        answerInterogation(optionSelected,corp,nr_sets);
                        break;

                    case 3:
                        cout << "Realizeaza inmultirea a doua elemente" << "\n";
                        optionSelected=3;
                        answerInterogation(optionSelected,corp,nr_sets);
                        break;
                    case 4:
                        cout << "Elementele neutru din corp" << "\n";
                        optionSelected=4;
                        answerInterogation(optionSelected,corp,nr_sets);
                        break;
                    case 5:
                        cout << "Inversul si opusul unui element" << "\n";
                        optionSelected=5;
                        answerInterogation(optionSelected,corp,nr_sets);
                        break;
                    case 6:
                        cout << "Ordinul unui element" << "\n";
                        optionSelected=6;
                        answerInterogation(optionSelected,corp,nr_sets);
                        break;
                    case 7:
                        cout << "Realizeaza scaderea a doua elemente" << "\n";
                        optionSelected=7;
                        answerInterogation(optionSelected,corp,nr_sets);
                        break;
                    case 8:
                        cout << "Realizeaza impartirea a doua elemente" << "\n";
                        optionSelected=8;
                        answerInterogation(optionSelected,corp,nr_sets);
                        break;
                    case 9:
                        cout << "Test izomorfism"<< "\n";
                        optionSelected=9;
                        answerInterogation(optionSelected,corp,nr_sets);
                        break;
                    case 10:
                        cout << "Testare egalitate in corp" << "\n";
                        optionSelected=10;
                        answerInterogation(optionSelected,corp,nr_sets);
                        break;
                    case 11:
                        cout<<"Exist program";
                        optionSelected=11;
                        destroy(corp,nr_sets);
                        delete corp;///trebuie sa dau delete la fiecare element alocat dinamic in parte
                        break;
                }

        }
    }
}

int main()
{
    int optionSelected=0;
    input_MenuChoice(optionSelected);
    /*int operation=0;
    interogationMenu(operation);
    */

    return 0;
}
