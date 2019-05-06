/* Anastasiya Chaplianskaya
prowadzacy: Wiktor Kusmirek
projekt2 - Korporacja taksowkarska
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>
#include <algorithm>

#include "shell.hpp"
#include "autos.hpp"
#include "clients.hpp"
#include "drivers.hpp"

using namespace std;

#define MAX_LENGTH 50
#define MAX_L_COM 20 //maximal length of command

void Shell:: start ()
{
    cout << setw(20) << "Hello! You are in the program for managing your taxi corporation" << endl;
    cout << "@@@ If you want to see a full list of commands with short description enter help" << endl;
    cout << "@@@ If you want to see a full instruction of one of the commands enter help name_of_command" << endl;
    cout << "@@@ If you want to finish the program enter exit" << endl;
    cout << "@@@ Enter a command:" << endl;
}

void Shell:: help()
{
    cout << "AddAuto (it adds a car to the list)" << endl;
    cout << "DeleteAuto (it deletes a given car from a base)" << endl;
    cout << "ShowAutos (it shows all current cars)" << endl;
    cout << endl;
    cout << "AddDriver (it adds a new driver to the list)" << endl;
    cout << "DeleteDriver (it deletes a given driver from a base)" << endl;
    cout << "ShowDrivers (it shows all current drivers with their surnames)" << endl;
    cout << endl;
    cout << "AddClient (it adds a new client to the list)" << endl;
    cout << "DisChange (it changes a discount that one of the current clients has)" << endl;
    cout << "ShowClients (it shows all clients with their names)" << endl;
}

void Shell:: processing ()
{
      char command[MAX_L_COM];
      while (true)
      {
        cin.getline (command, MAX_L_COM);
        if (!strcmp (command,"exit"))
        {
          cout << "@@@ Goodbye!";
          return;
        }

        else if (!strcmp (command,"AddAuto"))
        {
           AddAuto ();
           cout << "The auto has been added" << endl;
        }

        else if (!strcmp (command,"DeleteAuto"))
        {
            if (!vCar.empty())
            {
              string name;
                cout << "Enter the name of the car: " << endl;
                cin >> name;
                DeleteAuto (name);
            }
            else cout << "Error! The base of autos is empty" << endl;
        }

        else if (!strcmp (command,"ShowAutos"))
        {
            ShowAutos();
        }

        else if (!strcmp (command,"AddDriver"))
        {
            AddDriver();
            cout << "The driver has been added" << endl;
        }

        else if (!strcmp (command,"DeleteDriver"))
        {
            if (!vDriver.empty())
            {
                string code;
                cout << "Enter the code of the driver: " << endl;
                cin >> code;
                DeleteDriver (code);
            }
            else cout << "Error! The base of drivers is empty" << endl;
        }

        else if (!strcmp (command,"ShowDrivers"))
        {
            ShowDrivers();
        }

        else if (!strcmp (command,"AddClient"))
        {
            AddClient();
            cout << "The client has been added" << endl;
        }

        else if (!strcmp (command,"DisChange"))
        {
            if (!vClient.empty())
            {
                string surname;
                cout << "Enter the surname of a client:" << endl;
                cin >> surname;

                double discount2;
                cout << "Enter a new discount of a client:" << endl;
                cin >> discount2;

                DisChange (surname, discount2);
            }
            else cout << "Error! The base of clients is empty" << endl;
        }

        else if (!strcmp (command,"ShowClients"))
        {
            ShowClients();
        }

        else if (!strcmp (command,"help"))
        {
            help();
        }

        else if (!strcmp (command,"help AddAuto"))
        {
            cout << "This command lets you to add a new auto to the list. Enter a name, a colour and a year of a car." << endl;
            cout << "For example -  name: now45dodx;   colour: violet;   year: 2011" << endl;
        }

        else if (!strcmp (command,"help DeleteAuto"))
            {cout << "This command deletes a auto from a base. You should only give a name of the car" << endl;}

        else if (!strcmp (command,"help ShowAutos"))
            {cout << "You can look on the whole list of the taxis that were added earlier" << endl;}

        else if (!strcmp (command,"help AddDriver"))
        {
            cout << "This command lets you to add a new driver to the list. Enter a surname, a code and points of experience (from 1 to 20)." << endl;
            cout << "For example -  surname: Torv;   code: 2569c;   points of experience: 11" << endl;
        }

        else if (!strcmp (command,"help DeleteDriver"))
            {cout << "This command deletes a driver from a base. You should only give a unique code of the driver" << endl;}

        else if (!strcmp (command,"help ShowDrivers"))
            {cout << "You can look on the whole list of the drivers that were added earlier" << endl;}

        else if (!strcmp (command,"help AddClient"))
        {
            cout << "This command lets you to add a new client to the list. Enter a name, a surname and  a discount (from 0 to 50; without sign of '%')." << endl;
            cout << "For example -  name: Anna;   surname: Kreg;   discount: 20" << endl;
        }

        else if (!strcmp (command,"help DisChange"))
            {cout << "This command changes a discount of the client in a base. You should only give the client surname and a new value of it (from 0 to 50; without sign of '%')" << endl;}

        else if (!strcmp (command,"help ShowClients"))
            {cout << "You can look on the whole list of the clients that were added earlier" << endl;}

        else
            {cout << "Check your command and try again" << endl;}
      }
}

void Shell:: AddAuto ()
{
   string name;
   cout << "Enter the name:" << endl;
   cin >> name;

   string colour;
   cout << "Enter the colour:" << endl;
   cin >> colour;

   short int year;
   cout << "Enter the year:" << endl;
   cin >> year;
   while (cin.fail() || (year < 1886 || year > 2030))
   {
       if (cin.fail())
       {
        cout << "The year of a car must be a digital number. Try to enter it again: " << endl;
        cin.clear();
       }
       else
       {
         cout << "Provide valid car production year(from 1886 to 2030): " << endl;
       }
       cin.ignore(100, '\n');
       cin >> year;
   }
   vCar.push_back(Autos<short int>(name, colour, year));
   cin.ignore(100, '\n');
}

void Shell:: DeleteAuto (string name)
{
        bool del=false;
        for (vector<Autos<short int>>::iterator i=vCar.begin(); i!=vCar.end(); ++i)
        {
            if ((*i).returnName()==name)
            {
                vCar.erase(i);
                cout << "The car with the name " << name << " was deleted" << endl;
                del=true;
                break;
            }
        }
        if (!del)  cout << "No auto with this name is in a base. Check your input data" << endl;
        cin.ignore(100, '\n');
}

void Shell:: ShowAutos ()
{
      if (!vCar.empty())
      {
        for (vector<Autos<short int>>::iterator i=vCar.begin(); i!=vCar.end(); ++i)
            {
                cout << "name - " << (*i).returnName() << ",  colour - "
                << (*i).returnColour () << ",  year - " << (*i).returnYear() << endl;
            }
      }
      else cout << "The base of autos is empty" << endl;
}

void Shell:: AddDriver ()
{
    string* surname= new string[MAX_LENGTH]; //проверка
    if (surname==nullptr)
    {
        cout << "You don't have enough memory" << endl;
        exit(1);
    }

    cout << "Enter the surname:" << endl;
    cin >> *surname;


    string code;
    cout << "Enter the code:" << endl;
    cin >> code;

    short int exp;
    cout << "Enter the points of experience:" << endl;
    cin >> exp;
    while (cin.fail() || (exp<1 || exp>20))
    {
       if (cin.fail())
       {
        cout << "The points of experience must be a digital number. Try to enter it again: " << endl;
        cin.clear();
       }
       else
       {
         cout << "Provide valid points of experience(from 1 to 20): " << endl;
       }
       cin.ignore(100, '\n');
       cin >> exp;
    }
   vDriver.push_back(Drivers (*surname, code, exp));
   delete [] surname;
   cin.ignore(100, '\n');
}

template <typename K> void Shell:: DeleteDriver (K code)
{
    bool del=false;
    for (vector<Drivers>::iterator i=vDriver.begin(); i!=vDriver.end(); ++i)
    {
        if ((*i)==code)
        {
            vDriver.erase(i);
            cout << "The driver with the code " << code << " was deleted" << endl;
            del=true;
            break;
        }
    }
    if (!del)  cout << "No driver with this code is in a base. Check your input data" << endl;
    cin.ignore(100, '\n');
}

void Shell:: ShowDrivers ()
{
    if (!vDriver.empty())
    {
    for (vector<Drivers>::iterator i=vDriver.begin(); i!=vDriver.end(); ++i)
      {
            cout << "surname - " << (*i).returnDSur() << ",  code - "
            << (*i).returnCode() << ",  points of experience - " << (*i).returnExp() << endl;
      }
    }
    else cout << "The base of drivers is empty" << endl;
}

void Shell::AddClient()
{
    string surname;
    cout << "Enter the surname:" << endl;
    cin >> surname;

    string name;
    cout << "Enter the name:" << endl;
    cin >> name;

    double *discount=new double;
    if (discount==nullptr)
    {
        cout << "You don't have enough memory" << endl;
        exit(1);
    }
    cout << "Enter the discount:" << endl;
    cin >> *discount;

    while (cin.fail() || (*discount <0 || *discount>50))
    {
       if (cin.fail())
       {
        cout << "The number of discount must be a digital number. Try to enter it again: " << endl;
        cin.clear();
       }
       else
       {
         cout << "Provide valid number of discount(from 0 to 50): " << endl;
       }
       cin.ignore(100, '\n');
       cin >> *discount;
    }
    vClient.push_back(Clients (surname, name, *discount));
    delete discount;
    cin.ignore(100, '\n');
}

void Shell:: DisChange (string surname, double discount2)
{
        bool ch=false;
        for (vector<Clients>::iterator i=vClient.begin(); i!=vClient.end(); ++i)
        {
            if ((*i).returnCSur()==surname)
            {
                (*i).returnDis(discount2);
                ch=true;
                cout << "The discount has been changed " << endl;
            }
        }
        if (!ch)  cout << "No client with this surname is in a base. Check your input data" << endl;
        cin.ignore(100, '\n');
}

void Shell:: ShowClients ()
{
      if (!vClient.empty())
      {
        for (vector<Clients>::iterator i=vClient.begin(); i!=vClient.end(); ++i)
            {
                cout << "name - " << (*i).returnCName() << ",  surname - "
                << (*i).returnCSur() << ",  discount - " << (*i).returnDis() << endl;
            }
        }
      else cout << "The base of clients is empty" << endl;
}
