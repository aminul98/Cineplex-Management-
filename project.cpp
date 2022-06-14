#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cstring>
#include<string>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
class Movie
{
protected:
    string seat;
    string date;
    string timeslot;
    int ticketprice;
    string facility;
    int availableseats;
    int age;
    int totalprice;
    string seatnumbers;
    string tID;
    string name;
    int n;
    int k;
    public:
    string TimeSlot(int a)
    {
        if(a==1)
        {
            return this->timeslot="10:00AM";
        }
        else if(a==2)
            return this->timeslot="2:30PM";
        else if(a==3)
            return this->timeslot="6:00PM";

        else
        {
            cout << "Try again:" << endl;
            cin >> a;
            return TimeSlot(a);
        }

    }
    void getMovie()
    {
        cout << "Enter the seats : ";
        cin >> seat;
        cout << "Enter the date : ";
        cin >> date;
        cout<<"Enter the time:";
        cin>>timeslot;
        cout << "Enter the ticket price : ";
        cin >> ticketprice;
        cout << "Enter the facilites: ";
        cin >> facility;
        cout << "Enter the number of available seats : ";
        cin >> availableseats;
    }
    void display1()
    {
        system("pause");
        system("cls");
        cout << "The numbers of seats are : " << seat << endl;
        cout << "The date is : " << date << endl;
        cout << "The time is : " << timeslot << endl;
        cout << "The ticket price id : " << ticketprice << endl;
        cout << "The facilities are : " << facility << endl;
        cout << "The numbers of available seats are : " << availableseats << endl;
    }
    void sell()
    {
        cout << "Enter Your Age : ";
        cin >> age;
        cout << "How many seats do you want : ";
        cin >> n;
        cout << "Enter Seat Numbers : ";
        cin >> seatnumbers;
      // totalprice = ticketprice*n;
        cout << "Enter the ticket provider Id : ";
        cin >> tID;
        cout << "Enter The movie name ";
        cin >> name;
        cout << "Enter the time slot : 1.10:00AM 2.2:30PM 3.6:00PM ";
        cin >>k;
        TimeSlot(k);

    }
    void display2()
    {
        int price=180;
        system("pause");
        system("cls");
        cout<<"The age of the customer: "<<age<<endl;
        cout<<"Number of ticket buy: "<<n<<endl;
        cout<<"The seat numbers " << seatnumbers <<endl;
        cout<<"The total price of the ticket : "<<price*n<<endl;
        cout << "Ticket provider ID No: " <<tID<<endl;
        cout<<"The movie name: "<<name<<endl;
        cout<<"The time slot: "<<timeslot<<endl;
    }

};

class HallInformations:public Movie
{
    string id;
public:
    //get the variale
   // string id;
    void halldata()
    {
        Movie::getMovie();
    }

    void recordsell()
    {
        Movie::sell();
    }

    void display()//personal
    {
        Movie::display1();
         //show the hall information;
    }
    void displaysell()
    {
        Movie::display2();
    }
};

void saveHall();
void displayHall();
void recordsellinformation();
void showsellinformation();
//void modifyHall(string);
//void deleteSellinformation(string);

void saveHall()
{
    HallInformations hh;
    ofstream outFile;
    outFile.open("Hall.dat",ios::binary|ios::app);
    hh.halldata();

    outFile.write(reinterpret_cast<char *> (&hh), sizeof(HallInformations));
    outFile.close();
    cout<<"Hall information record Has Been Created ";
    cin.ignore();
    cin.get();
}

void displayHall()
{
    HallInformations hh;
    ifstream inFile;
    inFile.open("Hall.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"= DISPLAY ALL RECORD =" << endl;
    while(inFile.read(reinterpret_cast<char *> (&hh), sizeof(HallInformations)))
    {
        hh.display();
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void recordsellinformation()
{
    HallInformations hh;
    ofstream outFile;
    outFile.open("Sell.dat",ios::binary|ios::app);
    hh.recordsell();

    outFile.write(reinterpret_cast<char *> (&hh), sizeof(HallInformations));
    outFile.close();
    cout<<"Sell record Has Been Created ";
    cin.ignore();
    cin.get();
}

void showsellinformation()
{
    HallInformations hh;
    ifstream inFile;
    inFile.open("Sell.dat",ios::binary);
    if(!inFile)
    {
        cout<<"File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"= DISPLAY ALL RECORD =" << endl;
    while(inFile.read(reinterpret_cast<char *> (&hh), sizeof(HallInformations)))
    {
        hh.display2();
    }
    inFile.close();
    cin.ignore();
    cin.get();
}


class stuff
{
    private:
    int choice;
    bool Choose;
    string username,password,un,pwd;
    public:
        bool isloggedin()
    {
        cout<<"Enter Username: ";cin>>username;
        cout<<"Enter password: ";cin>>password;
        ifstream fileread;
        fileread.open("login.txt");

         while(getline(fileread,un))
         while(getline(fileread,pwd))

        if(un==username&&pwd==password)
        {
            return true;
        }
        else
            return false;
        }

         stuff()
    {
        this->choice = 0;
        this->Choose = true;
    }
    void MainMenu()
    {
        string app;
        while(1)
        {
           // string app;
            system("cls");
        cout << "= MAIN MENU =" << endl;
        cout << "0:Quit" << endl;
        cout << "1:Input Hall Information" << endl;
        cout << "2:Show Hall Information" << endl;
        cout << "3:Record Sell Information" << endl;
        cout << "4:Show Sell Information" << endl;
        //cout << "5:Modify Hall Information" << endl;
       // cout << "6:Delete Hall Information" << endl;
        cout << "Enter your choice:";
        cin >> choice;
        switch(choice)
        {
        case 0:
            Choose = false;
            break;
        case 1:
        {
            saveHall();
			system("pause");
			system("cls");
            break;
        }
        case 2:
        {
            displayHall();
			system("pause");
			system("cls");
            break;
        }
        case 3:
        {
            recordsellinformation();
			system("pause");
			system("cls");
            break;
        }
        case 4:
            {
            showsellinformation();
			system("pause");
			system("cls");
            break;
            }


        default:
            break;
        }
    }
    }

    inline bool getChoice() const
    {
        return this->Choose;
    }

};
class manager
{
    private:
    int choice;
    bool Choose;
    string username,password,un,pwd;
    public:
        bool isloggedin()
    {
        cout<<"Enter Username: ";cin>>username;
        cout<<"Enter password: ";cin>>password;
        ifstream fileread;
        fileread.open("systemuserlogin.txt");

         while(getline(fileread,un))
         while(getline(fileread,pwd))

        if(un==username&&pwd==password)
        {
            return true;
        }
        else
            return false;
        }

         manager()
    {
        this->choice = 0;
        this->Choose = true;
    }
    void MainMenu()
    {
        string app;
        while(1)
        {
            system("cls");
        cout << "= MAIN MENU =" << endl;
        cout << "0:Quit" << endl;
        cout << "1:Input Hall Information" << endl;
        cout << "2:Show Hall Information" << endl;
        cout << "3:Record Sell Information" << endl;
        cout << "4:Show Sell Information" << endl;
        cout << "5:Modify Hall Information" << endl;
        cout << "6:Delete Hall Information" << endl;
        cout << "Enter your choice:";
        cin >> choice;
        switch(choice)
        {
        case 0:
            Choose = false;
            break;
        case 1:
        {
            saveHall();
			system("pause");
			system("cls");
            break;
        }
        case 2:
        {
            displayHall();
			system("pause");
			system("cls");
            break;
        }
        case 3:
        {
            recordsellinformation();
			system("pause");
			system("cls");
            break;
        }
        case 4:
            {
            showsellinformation();
			system("pause");
			system("cls");
            break;
            }


        default:
            break;
        }
    }
    }

    inline bool getChoice() const
    {
        return this->Choose;
    }

};
int main()
{
    srand(time(NULL));
    stuff management;
    manager m;
    system("cls");
     system("cls");
        int n;
        cout<<"\n\n\n\t\t\t\t\t ----------------------------------";
        cout<<"\n\t\t\t\t\t\tCineplex the movie world";
        cout<<"\n\t\t\t\t\t----------------------------------";
        cout<<"\n\t\t\t\t\t\t1.Press <1> for Stuff login ";
        cout<<"\n\t\t\t\t\t\t2.Press <2> for Manager login";
        cout<<"\n\t\t\t\t\t\tEnter your Choice :";
        cin>>n;
        switch(n)
        {
        case 1:
        {


            int choice;
            cout<<"For stuff login you can follow the below rules";
            cout<<"\n1:Sign up\n2:Log in\nYour choice: ";
            cin>>choice;
            if(choice==1)
            {
                string username,password;
                cout<<"Select a username: ";
                cin>>username;
                cout<<"Select a password: ";
                cin>>password;
                ofstream file;
                file.open("login.txt");


                file<<username<<endl<<password;
                file.close();
                main();

            }
            else if(choice==2)
            {
                bool status=management.isloggedin();
                if(!status)
                {
                    cout<<"Login failed";
                    system("PAUSE");
                    return 0;
                }
                else
                {
                    cout<<"Login Successful !";
                     management.MainMenu();
                    system("PAUSE");
                    return 1;
                }
            }
        }
        case 2:
        {


            int choice;
            cout<<"For Manager login you can follow the below rules";
            cout<<"\n1:Sign up\n2:Log in\nYour choice: ";
            cin>>choice;
            if(choice==1)
            {
                string username,password;
                cout<<"Select a username: ";
                cin>>username;
                cout<<"Select a password: ";
                cin>>password;
                ofstream file;
                file.open("systemuserlogin.txt");
                file<<username<<endl<<password;
                file.close();
                main();

            }
            else if(choice==2)
            {
                bool status=m.isloggedin();
                if(!status)
                {
                    cout<<"Login failed";
                    system("PAUSE");
                    return 0;
                }
                else
                {
                    cout<<"Login Successful !";
                    m.MainMenu();
                    system("PAUSE");

                    return 0;
                }
            }
        }
        }

    while(management.getChoice())
    {
        management.MainMenu();
    }
     while(management.getChoice())
    {
        management.MainMenu();
    }
    return 0;
}
