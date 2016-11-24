#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdlib.h>

using namespace std;

class employee
{
string firstName,lastName,dob,nic,address;
double salary=20000,days;
int pnum;

public:

    void editall();
    void searchall();
    void deletefile();
    void input();
    void displayall();
    void searchnic();
    void searchfname();
    void searchlname();
    void quit();
    void editfname();
    void editlname();
    void editdob();
    void choiceone();

};


class management : public employee
{
public:
   void mainpanel();
   void validation();
   void emppanel();

};

//////////////////--------------------INPUT-------------------------///////////////////////
void employee :: input()
{  system("CLS");
    string choice5;
    ofstream empfile;
   empfile.open("emp.txt",ios :: app);
   cout << "Enter the National Identity Card Number of the Employer \n";
   cin >>nic;
   cout << "Enter the first name of the Employer \n";
   cin >>firstName;
   cout <<"Enter the last name of the Employer \n";
   cin >>lastName;
   cout << "Enter the date of birth [date/month/year] \n";
   cin >> dob;
   cout <<"Enter your Telephone Number \n";
   cin>> pnum;
   cout <<"Enter your address \n";
   cin >> address;
   cout <<"Your daily basic Salary is Rs20000 \n";
   cout << "How many days did she/he haven't reported to the Factory? \n";
   cin >>days;

    if(days=1)
    {
      salary=salary-1000;
    }
    else if(days<3 && days>1)
    {
        salary=salary+2000;
    }
    else if(days>=3)
    {
       salary=salary-3000;
    }
    else
    {
        cout << "Please enter a valid number of days \n";
    }
   empfile << nic << ' ' <<firstName << ' '<< lastName << ' '<< dob << ' '<<pnum<<' '<<address <<' '<<salary<< endl;
   empfile.close();
    cout << "Want to go back to the main menu [y][n]";
    cin>> choice5;
    if(choice5 == "y")
    {
        choiceone();
    }
    else if(choice5 =="n")
    {
        quit();
    }

}

//////////////////////////////-------SEARCH BY ID-----------------///////////////////////////
void employee ::searchnic()
{   system("CLS");
    string choice7;
    string id;
    ifstream empfile;
    empfile.open("emp.txt");
    cout <<"Enter the  ID of the employee \n";
    cin >>id;

    while(empfile >> nic >> firstName >> lastName >> dob >> pnum >> address >>salary){
        if(id==nic)
        {
            cout <<"Employee found"<<endl;
            cout << "NIC"<< ' '<< "FirstName" << ' '<< "LastName" <<' '<< "DOB" <<' '<< "T/P"<<' '<<"address"<<' '<<"Salary"<< endl;
            cout << nic << ' '<< firstName << ' '<< lastName << ' '<< dob <<' '<<pnum << ' '<<address<<' '<< salary << endl;
        }
        else if(id != nic){
            cout << "No employee(s) found" << endl;
        }
    searchall();
}
}

///////////////////////-------SEARCH BY FIRST NAME----------------//////////////////////////////
void employee :: searchfname()
{    system("CLS");

    string fname;
    ifstream empfile;
    empfile.open("emp.txt");
    cout <<"Enter the first name of the employee \n";
    cin >>fname;

    while(empfile >> nic >> firstName >> lastName >> dob >> pnum >> address >>salary){
        if(fname==firstName)
        {
            cout <<"Employee found"<<endl;
           cout << "NIC"<< ' '<< "FirstName" << ' '<< "LastName" <<' '<< "DOB" <<' '<< "T/P"<<' '<<"address"<<' '<<"salary"<< endl;
           cout <<"---------------------------------------------------------------------------"<<endl;
            cout << nic << ' '<< firstName << ' '<< lastName << ' '<< dob <<' '<<pnum << ' '<<address<<' '<< salary << endl;
        }
    }

            if (fname != firstName)
            {
               cout << "No employee(s) found" << endl;
            }
            system("pause");
            searchall();

}

//////////////////////--------SEARCH BY LAST NAME----------------////////////////////////////
void employee :: searchlname()
{   system("CLS");
    string lname;
    string choice9;
    ifstream empfile;
    empfile.open("emp.txt");
    cout <<"Enter the last name of the employee \n";
    cin >>lname;

    while(empfile >> nic >> firstName >> lastName >> dob >> pnum >> address >>salary){
        if(lname==lastName)
        {
            cout <<"Employee found"<<endl;
           cout << "NIC"<< ' '<< "FirstName" << ' '<< "LastName" <<' '<< "DOB" <<' '<< "Salary"<<' '<<"T/P"<<' '<<"address"<< endl;
            cout <<"---------------------------------------------------------------------------"<<endl;
            cout << nic << ' '<< firstName << ' '<< lastName << ' '<< dob <<' '<<pnum << ' '<<address<<' '<< salary << endl;
        }
        }
if (lname != lastName)
            {
               cout << "No  other employee(s) found \n" << endl;
            }

system("pause");
searchall();
}

/////////////////////-------SEARCH SELECTION---------------------////////////////////////////
void employee :: searchall()
{
     int choice2;
     system ("CLS");

     cout << "1.Search by First name" << endl;
     cout << "2.Search by Last name" << endl;
     cout << "3.Search by National Identity Card number" << endl;
     cout << "4.Display all employees" << endl;
     cout << "5.Back" << endl;
     cout << "6.Exit program" << endl;
     cin >> choice2;

     switch (choice2){
            case 1:
                 searchfname();
                 break;
            case 2:
                 searchlname();
                 break;
            case 3:
                 searchnic();
                 break;
            case 4:
                 displayall();
                 break;
           case 5:
                searchall();
                 break;
            case 6:
                 quit();
                 break;
                 }
}

////////////////////---------DISPLAY ALL--------------------------///////////////////////////
void employee :: displayall()
{    system("CLS");
    ifstream empfile;
    empfile.open("emp.txt");
    cout <<"ALL MEMBERS OF DILSHAN TEX"<<endl;
     cout << "************************************************************* \n";
     cout << "NIC"<< ' '<< "FirstName" << ' '<< "LastName" <<' '<< "DOB" <<' '<< "Salary"<<' '<<"T/P"<<' '<<"address"<< endl;
       while(empfile >> nic >> firstName >> lastName >> dob >> pnum >> address >> salary)
       {       cout <<"---------------------------------------------------------------------------"<<endl;
              cout << nic << ' '<< firstName << ' '<< lastName << ' '<< dob <<' '<< pnum << ' '<< address <<' '<< salary << endl;
       }
    system("pause");
    searchall();

}

////////////////////-------------QUIT----------------------/////////////////////////////
void employee :: quit()
{system ("CLS");
 cout << "Thank you for using the PAYROLL SYSTEM of DILSHAN TEX " << endl;
 system ("pause");
}

///////////////////---------------DELETE FILE-----------//////////////////////////////
void employee :: deletefile()
{   system("CLS");
     string decision;
     cout << "Are you sure?[Y]es[N]o" << endl;
     cin >> decision;
     if (decision == "y"){
     ofstream empfile("emp.txt");
     system("cls");
     cout << "Successfully Completed!" << endl;
     system("pause");
     empfile.close();

      int main();
     }
     else{
         int main();
          }
     }

//////////////////////-------------EDIT FILE----------------/////////////////////////
void employee :: editall()
{    int choice3;
    system("CLS");
     cout << "1.Edit First Name \n";
     cout <<"2.Edit Last Name \n";
     cout <<"3.Edit Date of Birth \n";
     cout <<"4.Display all employees \n";
     cout << "5.Back \n" ;
     cout << "6.Exit program \n";

     cin >> choice3;

      switch(choice3)
      {
      case 1:
        editfname();
        break;

      case 2:
        editlname();
        break;

        case 3:
        editdob();
        break;

        case 4:
         displayall();
        break;

        case 5:
       int main();
        break;

        case 6:
         quit();
        break;
      }
}

//////////////////////--------------EDIT FISRT NAME -------------/////////////////////////////
void employee :: editfname()
{
    string num,decision,newfname;
    ifstream empfile;
    empfile.open("emp.txt");
    if(!empfile.eof()){
        empfile >> nic >>firstName >> lastName >>dob>> pnum >> address >>salary;
    }
    system("CLS");
    cout << "Enter the National Identity Card number of the employee \n";
    cin >> num;
      if(num==nic){
        cout << nic << ' '<< firstName << ' '<< lastName << ' '<< dob <<' '<< pnum <<' '<< address << ' '<<salary << endl;
        cout << "Is this the Employee are you looking at [y][n] ?";
        cin >> decision;

        if (decision=="y")
        {
            cout <<"Enter the new first name \n";
            cin >>newfname;
            firstName=newfname;
        }
        empfile.close();
      }
      ofstream empfile2("emp.txt", ios::app);
     empfile2 << nic <<' '<< firstName <<' ' << lastName << ' ' << dob << ' '<<pnum <<' '<<address <<' '<< salary << endl;
     empfile2.close();
 system("pause");
  searchall();
}

///////////////////-------EDIT LAST NAME------//////////////////
void employee :: editlname()
{   string choice13;
     string num,decision,newlname;
    ifstream empfile;
    empfile.open("emp.txt");
    if(!empfile.eof()){
        empfile >> nic >>firstName >> lastName >>dob>> salary;
    }
    system("CLS");
    cout << "Enter the National Identity Card number of the employee \n";
    cin >> num;
      if(num==nic){
        cout << nic << ' '<< firstName << ' '<< lastName << ' '<< dob <<' '<<pnum <<' '<< address <<' '<< salary << endl;
        cout << "Is this the Employee are you looking doe [y][n] ?";
        cin >> decision;

        if (decision=="y")
        {
            cout <<"Enter the new last name \n";
            cin >>newlname;
            lastName=newlname;
        }
        empfile.close();
      }
      ofstream empfile3("emp.txt", ios::app);
     empfile3 << nic <<' '<< firstName <<' ' << lastName << ' ' << dob << ' '<<pnum << ' '<< address <<' '<< salary << endl;
     empfile3.close();
 system("pause");
searchall();
}

//////////////////----------EDIT DOB-------------////////////////////
void employee :: editdob()
{    system("CLS");
string choice11;
    string num,decision,newdob;
    ifstream empfile;
    empfile.open("emp.txt");
    if(!empfile.eof()){
        empfile >> nic >>firstName >> lastName >>dob>> pnum >> address >>salary;
    }
    system("CLS");
    cout << "Enter the National Identity Card number of the employee \n";
    cin >> num;
      if(num==nic){
        cout << nic << ' '<< firstName << ' '<< lastName << ' '<< dob <<' '<<pnum <<' '<<address <<' '<< salary << endl;
        cout << "Is this the Employee are you looking at [y]es[n]o ?";
        cin >> decision;

        if (decision=="y")
        {
            cout <<"Enter the new date of birth \n";
            cin >>newdob;
            dob=newdob;
        }
        empfile.close();
      }
      ofstream empfile4("emp.txt", ios::app);
     empfile4 << nic <<' '<< firstName <<' ' << lastName << ' ' << dob << ' '<<pnum <<' '<<address<<' '<< salary << endl;
     empfile4.close();
 system("pause");
searchall();
}

void employee :: choiceone()
{system("CLS");
int choice;
cout<< "Welcome to the Management Panel of the PayRoll System of DILSHAN TEX \n" ;
 cout << "************************************************************* \n";
cout << "1.Enter a new Employee \n";
cout << "2.Search for an existing Employee \n";
cout <<"3.Edit details about an existing Employee \n";
cout <<"4.Display all the Employees who are currently working with us \n";
cout <<"5.Delete all the details about the Employees \n";
cout <<"6.Do you want to quit from the program ? \n";
cin >> choice;
switch(choice)
{
case 1:
input();
    break;

case 2:
    searchall();
    break;

case 3:
    editall();
    break;

case 4:
   displayall();
    break;

case 5:
    deletefile();
    break;

case 6:
    quit();
    break;

default:
    cout<< "You entered a wrong command try again \n \n";
    break;
}
}

void management :: mainpanel()
{   system("CLS");
    cout << "WELCOME TO MAIN PANEL OF THE DILSHAN TEX \n";
    string choice;
    cout << "************************************************************* \n";
    cout <<"Choose which panel do you use : Management[m] or Employee[e] \n";
    cin >>choice;

    if(choice == "m")
    {
        validation();
    }
    else if(choice =="e")
    {
        emppanel();
    }
    else{
        cout <<"You entered a wrong command try again \n\n";

    }
}

void management :: validation()
{   system("CLS");

    cout << "Sorry for the inconvenience, you have to go through this \n\n";
     cout << "************************************************************* \n";
string pass="dilshan123";

cout << "Enter the password \n";
cin >>pass;

if (pass=="dilshan123")
{
    cout <<"Your Password is correct \n";
    choiceone();
}
else
{
    cout <<"Your Password is incorrect \n Back to main program \n";
    mainpanel();
}
}


void management :: emppanel()
{   int choose;
system("CLS");
    cout <<"Welcome to Employee panel of Dilshan Tex \n";
     cout << "************************************************************* \n";
    cout << "1.Search for an existing Employee \n";
    cout <<"2.Display all the Employees who are currently working with us \n";
    cout << "3.Back to Main Panel ? \n";
    cout <<"4.Do you want to quit from the program ? \n";
    cin >>choose;


    switch(choose)
    {
    case 1:
    searchall();
    break;

    case 2:
    displayall();
    break;

    case 3:
    mainpanel();
    break;

    case 4:
    quit();
    break;
    }
}

int main()
{
system ("title PAYROLL SYSTEM OF DILSHAN TEX ");
system ("cls");
system ("color E9");


management man;
man.mainpanel();
}
