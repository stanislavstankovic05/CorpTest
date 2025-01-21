#include <conio.h>
#define upkey 72
#define downkey 80
#define enterkey 13

using namespace std;
class Interface
{
    string *options;
    int numberOptions;
    static Interface *instancePtr;
public:
    Interface()
    {
        numberOptions=0;
    }
    Interface(const Interface& interface)=delete;
    ~Interface()
    {
        delete[] options;
    }
    static Interface* getInstance()
    {
        if(instancePtr==NULL)
        {
            instancePtr=new Interface();
            return instancePtr;
        }
        else
        {
            return instancePtr;
        }
    }
    void getOptions(string optionsMenu[],int lenght)
    {
        options=new string[lenght+1];
        numberOptions=lenght;
        for (int i=1;i<=lenght;++i)
        {
            options[i]=optionsMenu[i-1];
        }
    }
    void displayInterface(int selectedOption,int nrOptions,string options[])
    {
        system("cls");
        cout << "===== Menu =====\n";
        for (int i=1;i<=nrOptions;++i)
        {
            if(selectedOption==i)
            {
                cout<<"> ";
            }
            else
                cout<<" ";
            cout<<i<<"."<<options[i]<<"\n";
        }
        if (selectedOption==nrOptions+1)
        {
            cout<<"> ";
        }
        else
            cout<<" ";
        cout<<nrOptions+1<<"."<<"Exit \n";
        cout << "================\n";
    }

    void showInterfaceChoice(int &optionSelected)
    {
        int selectOption=1;

        while(optionSelected==0)
        {
            displayInterface(selectOption, numberOptions, options);
            int key_code = _getch(); // get the pressed key cod
            //cout<<key; get keycode
            switch (key_code)
            {
                case upkey: // Up arrow key
                    if (selectOption - 1 < 1)
                    {
                        selectOption = numberOptions+1;
                    }
                    else
                        selectOption --;
                    //selectOption = (selectOption - 1 < 1) ? 4 : selectOption - 1;
                    break;

                case downkey: // Down arrow key
                    if (selectOption + 1 > numberOptions+1)
                    {
                        selectOption = 1;
                    }
                    else
                        selectOption ++;
                    //selectOption = (selectOption + 1 > 4) ? 1 : selectOption + 1;
                    break;

                case enterkey: // Enter key

                    if(selectOption==numberOptions+1)
                    {
                        //cout<<selectOption<<" ";
                        cout << "Exiting the program." << "\n";
                        optionSelected=numberOptions+1;
                    }
                    else
                    {
                        //cout<< "optiunea"<< selectOption<< "\n";
                        optionSelected=selectOption;
                    }
                    break;
            }
        }
    }
    /*void print()
    {
        for(int i=1;i<=numberOptions;++i)
        {
            cout<<options[i]<<" ||| ";
        }
    }*/

};


