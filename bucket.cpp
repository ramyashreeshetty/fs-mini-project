#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <regex>
#include <stdio.h>
using namespace std;


//---------------->class

class wish
{
private:
    string name, description, category, targetdate, status,myname,goalno;

public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
   
};


//----------------->MAIn-menu

void wish::menu()
{
    char ans;

    cout<<"\t\t\t HeyA! iS It yOUr FIRst TimE? (Y/N):";
    cin>>ans;
    if(ans =='y' || ans =='Y')
    {
        cout<<"\t\t\t What is your name?:";
        cin>>myname;
    }

menustart:
    int choice;
    char x;
    system("cls");

    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << "\n---------------------------------------- BEFORE YOU DIE ---------------------------------------------";
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout<<endl;
    cout << "\t\t\t\t    ~kick out bucket- or die~" << endl;
    cout<<endl;
    cout << "\t Hey "+ myname +"! \"Make a bucket list and fill it with dreams that have no boundaries.\" " << endl;
    cout<<endl;
    
    cout << "\t\t\t\t 1. Enter Your BYD-GOAL" << endl;
    cout << "\t\t\t\t 2. Display my BEFORE YOU DIE[list]" << endl;
    cout << "\t\t\t\t 3. Modify BYD-GOAL" << endl;
    cout << "\t\t\t\t 4. Search BYD-GOAL" << endl;
    cout << "\t\t\t\t 5. Delete BYD-GOAL" << endl;
    cout << "\t\t\t\t 6. GIVE UP THE GHOSTS" << endl;

    cout << "\t\t\t\t---------------------------" << endl;
    cout << "\t\t\t\tChoose Option:[1/2/3/4/5/6]" << endl;
    cout << "\t\t\t\t---------------------------" << endl;
    cout << "\t\t\t\tEnter Your Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\t\t\t\tAdd Another BYD-GOAL (Y/N): ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        deleted();
        break;
    case 6:
        exit(0);
    default:
        cout << "\n\t\t\t\t Uh-oh......invalid choice! Try Again >_<";
    }
    getch();
    goto menustart;
}


//------------------------>ADD GOALS

void wish::insert()
{
    system("cls");
    fstream file;
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << "\n------------------------------------- Add Your BYD-GOAL ---------------------------------------------" << endl;
    

    cout << "\t\t\t\tEnter Goal No: ";
    cin >> goalno;
    cout << "\t\t\t\tEnter Name: ";
    cin >> name;
    cout << "\t\t\t\tEnter Description: ";
    cin >> description;
    cout << "\t\t\t\tEnter Category: ";
    cin >> category;
    cout << "\t\t\t\tEnter Target-date(dd-mm-yyyy): ";
    cin >> targetdate;
    cout << "\t\t\t\tEnter Status(Active/Achieve): ";
    cin >> status;
    

    file.open("wishRecord.txt", ios::app | ios::out);
    file << " " << goalno << " " << name << " " << description << " " << category << " " << targetdate << " " << status << "\n";
    file.close();
}


//--------------------------->Displaying wish

void wish::display()
{
    system("cls");
    fstream file;
    int total = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- BEFORE YOU DIE[list] --------------------------------------------" << endl;
    file.open("wishRecord.txt", ios::in);
    if (!file)
    {
        /* code */
        cout << "\n\t\t\t\tNo Data Is Present...";
        file.close();
    }
    else
    {
        file>> goalno >> name >> description >> category >> targetdate >> status;

        //table headings

        cout<<setw(10)<<"Goal No."<<setw(20)<<"Name of the Goal"<<setw(25)<<"Description"<<setw(15)<<"Category"
        <<setw(15)<<"Target Date"<<setw(15)<<"Status"<<endl;
        cout<<endl;


        while (!file.eof())
        {
            //Creating table format for data
        cout<<setw(10)<<goalno<<setw(20)<<name<<setw(25)<<description<<setw(15)<<category
        <<setw(15)<<targetdate<<setw(15)<<status<<endl;

        cout<<endl;

        file>> goalno >> name >> description >> category >> targetdate >> status;

        total++;

        }
        if (total == 0)
        {
            cout << "\n\t\t\tNo Data Is Present...";
        }
    }
    file.close();
}


//---------------------------->Modify

void wish::modify()
{
    system("cls");
    fstream file, file1;
    string goalno1;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Modify Your BYD-GOAL ------------------------------------------" << endl;
    file.open("wishRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t\tNo Data is Present..";
    }
    else
    {
        cout << "\nEnter Goal No. which you want to Modify: ";
        cin >> goalno1;
        file1.open("record.txt", ios::app | ios::out);
        file>> goalno >> name >> description >> category >> targetdate >> status;
        while (!file.eof())
        {
            if (goalno != goalno1)
                file1 << " " << goalno << " " << name << " " << description << " " << category << " " << targetdate << " " << status << "\n";
            
            else
            {
                cout << "\t\t\t\tEnter Goal No: ";
                cin >> goalno;
                cout << "\t\t\t\tEnter Name: ";
                cin >> name;
                cout << "\t\t\t\tEnter Description: ";
                cin >> description;
                cout << "\t\t\t\tEnter Category: ";
                cin >> category;
                cout << "\t\t\t\tEnter Target-date(dd-mm-yyyy): ";
                cin >> targetdate;
                cout << "\t\t\t\tEnter Status(Active/Achieve): ";
                cin >> status;
                file1 << " " << goalno << " " << name << " " << description << " " << category << " " << targetdate << " " << status << "\n";
                found++;
            }
            file>> goalno >> name >> description >> category >> targetdate >> status;
            // if (found == 0)
            // {
            //     cout << "\n\n\t\t\t\t Goal No. Not Found >_<";
            // }
        }
        file1.close();
        file.close();
        remove("wishRecord.txt");
        rename("record.txt", "wishRecord.txt");
    }

}


//------------------>Search

void wish::search() 
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("wishRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Search YOUR BYD-GOAL ------------------------------------------" << endl;
        cout << "\n\t\t\t\t No Data Is Present...";
    }
    else
    {
        string goalno1;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- SEARCH YOUR BYD-GOAL ------------------------------------------" << endl;
        cout << "\n Enter Goal No. Which You Want to Search: ";
        cin >> goalno1;
        file>> goalno >> name >> description >> category >> targetdate >> status;
        while (!file.eof())
        {
            if (goalno1 == goalno)
            {
                cout<<setw(10)<<"Goal No."<<setw(20)<<"Name of the Goal"<<setw(25)<<"Description"<<setw(15)<<"Category"
                <<setw(15)<<"Target Date"<<setw(15)<<"Status"<<endl;

                cout<<endl;

                cout<<setw(10)<<goalno<<setw(20)<<name<<setw(25)<<description<<setw(15)<<category
                <<setw(15)<<targetdate<<setw(15)<<status<<endl;

                found++;
            }
            file>> goalno >> name >> description >> category >> targetdate >> status;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t\tGoal No. Not Found...";
        }
        file.close();
    }
}

//--------------------------->Deleting

void wish::deleted()
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string goal;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Student Details ------------------------------------------" << endl;
    file.open("wishRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\n\t\t\t\tEnter the Goal No to delete: ";
        cin >> goal;
        file1.open("record.txt", ios::app | ios::out);
         file>> goalno >> name >> description >> category >> targetdate >> status;
        while (!file.eof())
        {
            if (goal != goalno)
            {
                file1 << " " << goalno << " " << name << " " << description << " " << category << " " << targetdate << " " << status << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\t\tDeletion Successful";
            }
             file>> goalno >> name >> description >> category >> targetdate >> status;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t\t Goal No. Not Found....";
        }
        file1.close();
        file.close();
        remove("wishRecord.txt");
        rename("record.txt", "wishRecord.txt");
    }
}

//main

main()
{
    wish project;
    project.menu();
    return 0;
}    
