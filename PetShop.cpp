//This program is created for a pet shop that maintains the records of its employees and pets.
// Records contain clock in and clock out time of the employees, and the information on employees and pets.
//Employees can change their personal informtaion or information about pets from databse.
//Access to edit information about other employees is only given to the admin of the program/company. 

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;



//Prototype functions
string prompt(string); //ASks user for ID
int logIn(string); //Checks ID
void loadEmployee(); // Creates all the employees
void editEmployee(int); //given am ID number, it can edit employee data
void displayEmployee(); // displays employee data
void loadPet(); // creates all the pets
void editPet(); //edits pet data
void displayPet(); // displays all the pets

class Employee { //Employee Class
public:
    string ID;
    string name;
    long phoneNumber;
    string address;
    string city;
    string state;
    int zip;
    bool clockIn = false;
    bool admin = false;

};


//Date structure
struct date
{
    int Month;
    long Year;
    int Day;
};

//Pet structure
struct Pet
{
    int ID;
    date DOB;//YYYY-MM-DD
    int age;
    string name;
    string gender;
    bool sold = false;
    string type;
};

//Array creation
Employee employees[5];
Pet pets[10];


//main function
int main() {
    string ID;
    int index;
    int select;


    loadEmployee();
    loadPet();
    //LogIn
    do {
        ID = prompt(ID);
        index = logIn(ID);
    } while (index == -1);
    
    //Searching Menu
    do{
        cout << "Make your selection: " << endl;
        cout << "1 - Edit Employee Data" << endl;
        cout << "2 - Display Employee Data" << endl;
        cout << "3 - Edit Pet Data" << endl;
        cout << "4 - Display Pet Data" << endl;
        cout << "5 - Quit" << endl;
        cin >> select;
        
        if(select == 1){
            editEmployee(index);
        }
        else if(select == 2){
            displayEmployee();
        }
        else if(select == 3){
            editPet();
        }
        else if(select == 4){
            displayPet();
        }
    }
    while(select != 5);
    
    
    return 0;
}

string prompt(string ID) {
    cout << "Enter your ID:  ";
    cin >> ID;
    return ID;
}

int logIn(string ID) {
    for (int index = 0; index < 5; index++) {
        if (ID == employees[index].ID) {
            cout << "Logged in." << endl;
            if (employees[index].clockIn == false) {
                cout << "You have been clocked in." << endl;
                employees[index].clockIn = true;
            }
            return 0;
        }
    }
    return -1;
}


void loadEmployee(){
    // Hardcoded employees:
    employees[0].ID = "0001";
    employees[0].name = "Carter Codell";
    employees[0].phoneNumber = 9995554321;
    employees[0].address = "312 Grote-Thompson Hall";
    employees[0].city = "Morehead";
    employees[0].state = "Kentucky";
    employees[0].zip = 40351;
    employees[0].admin = true;
    
    employees[1].ID = "0002";
    employees[1].name = "Cassidy ‘Cas’ Bailey";
    employees[1].phoneNumber = 1223334444;
    employees[1].address = "212 Grote-Thompson Hall";
    employees[1].city = "Morehead";
    employees[1].state = "Kentucky";
    employees[1].zip = 40351;
    
    employees[2].ID = "0003";
    employees[2].name = "Binamrata Sharma";
    employees[2].phoneNumber = 2342342523;
    employees[2].address = "12B Baker Street";
    employees[2].city = "London";
    employees[2].state = "London";
    employees[2].zip = 72847;
    
    
    employees[3].ID = "0004";
    employees[3].name = "Kyle Thomas";
    employees[3].phoneNumber = 5059884420;
    employees[3].address = "242 Grote-Thompson Hall";
    employees[3].city = "Morehead";
    employees[3].state = "Kentucky";
    employees[3].zip = 40351;
    
    employees[4].ID = "0005";
    employees[4].name = "Tanner Coleman";
    employees[4].phoneNumber = 1118675309;
    employees[4].address = "319 Grote-Thompson Hall";
    employees[4].city = "Morehead";
    employees[4].state = "Kentucky";
    employees[4].zip = 40351;
}

// Cas's Code

//Prototyped Functions
void editmenuothers();
void editmenuown();
void editowndata(int);
void editotherdata(int);
void editName(int);
void editAddress(int);
void editPhoneNumber(int);
void editCity(int);
void editState(int);
void editZip(int);
void editAdmin(int);

void editEmployee(int emparraynum){
    if(employees[emparraynum].admin==true){
        int runloop=1;
        do{
            cout<<"\nWould you like to edit your own data[1] or someone else's[2]? ";
            int inputindex;
            cin>>inputindex;
            while(inputindex<1||inputindex>2){
                cout<<"\nThat is not a valid input.";
                cout<<"\nWould you like to edit your own data[1] or someone else's[2]? ";
                cin>>inputindex;
            }
            if(inputindex==1){
                editowndata(emparraynum);
            }
            else{
                editotherdata(emparraynum);
            }
        cout<<"\nWould you like to continue editing data [1 for yes 2 for no]? ";
        int selection;
        cin>>selection;
        while(selection<1||selection>2){
                cout<<"\nThat is not a valid input.";
                cout<<"\nWould you like to continue editing data [1 for yes 2 for no]? ";
                cin>>selection;
            }
            if(selection==2){
                runloop=-1;
            }
        }while(runloop!=-1);
        }
    else{
        int runloop2=1;
        do{
            editowndata(emparraynum);
            cout<<"\nWould you like to continue editing your data [1 for yes 2 for no]? ";
            int selection;
            cin>>selection;
            while(selection<1||selection>2){
                cout<<"\nThat is not a valid input.";
                cout<<"\nWould you like to continue editing your data [1 for yes 2 for no]? ";
                cin>>selection;
            }
            if(selection==2){
                runloop2=-1;
            }
        }while(runloop2!=-1);
    }
}

void editmenuothers(){
    cout<<"\nEdit Menu:"<<endl;
    cout<<setw(20)<<"Name [1]";
    cout<<setw(20)<<"Address [2]";
    cout<<setw(20)<<"Phone Number [3]"<<endl;
    cout<<setw(20)<<"City [4]";
    cout<<setw(20)<<"State [5]";
    cout<<setw(20)<<"Zip [6]"<<endl;
    cout<<setw(20)<<"Admin [7]"<<endl;
}
void editmenuown(){
    cout<<"\nEdit Menu:"<<endl;
    cout<<setw(20)<<"Name [1]";
    cout<<setw(20)<<"Address [2]";
    cout<<setw(20)<<"Phone Number [3]"<<endl;
    cout<<setw(20)<<"City [4]";
    cout<<setw(20)<<"State [5]";
    cout<<setw(20)<<"Zip [6]"<<endl;
}
void editowndata(int emparraynum){
    editmenuown();
    cout<<"What would you like to edit? ";
    int selection;
    cin>>selection;
    while(selection<1||selection>6){
        cout<<"\nThat is not a valid input.";
        cout<<"\nWould you like to edit? ";
        cin>>selection;
    }
    switch (selection){
        case 1:
            editName(emparraynum);
            break;
        case 2:
            editAddress(emparraynum);
            break;
        case 3:
            editPhoneNumber(emparraynum);
            break;
        case 4:
            editCity(emparraynum);
            break;
        case 5:
            editState(emparraynum);
            break;
        case 6:
            editZip(emparraynum);
            break;
    }
}
void editotherdata(int emparraynum){
    cout<<"\nEnter the employee number of the person whose data you would like to change:"<<endl;
    cin.ignore();
    string ID;
    getline(cin, ID);
    for (int index = 0; index < 5; index++) {
        if (ID == employees[index].ID) {
            emparraynum=index;
        }
    }
    editmenuothers();
    cout<<"\nYou have chose to edit the data of ";
    cout<<employees[emparraynum].name<<endl;
    cout<<"What would you like to edit? ";
    int selection;
    cin>>selection;
    while(selection<1||selection>6){
        cout<<"\nThat is not a valid input.";
        cout<<"\nWhat would you like to edit? ";
        cin>>selection;
    }
    switch (selection){
        case 1:
            editName(emparraynum);
            break;
        case 2:
            editAddress(emparraynum);
            break;
        case 3:
            editPhoneNumber(emparraynum);
            break;
        case 4:
            editCity(emparraynum);
            break;
        case 5:
            editState(emparraynum);
            break;
        case 6:
            editZip(emparraynum);
            break;
        case 7:
            editAdmin(emparraynum);
            break;
    }
}
void editName(int emparraynum){
    cout<<"\nWhat would you like to change their/your name to? ";
    cin.ignore();
    getline(cin,employees[emparraynum].name);
    cout<<"\nTheir/your name is now: "<<employees[emparraynum].name;
}
void editAddress(int emparraynum){
    cout<<"\nWhat would you like to change their/your address to? ";
    cin.ignore();
    getline(cin,employees[emparraynum].address);
    cout<<"\nTheir/your address is now: "<<employees[emparraynum].address;
}
void editPhoneNumber(int emparraynum){
    cout<<"\nWhat would you like to change their/your phone number to? ";
    cin>>employees[emparraynum].phoneNumber;
    cout<<"\nTheir/your phone number is now: "<<employees[emparraynum].phoneNumber;
}
void editCity(int emparraynum){
    cout<<"\nWhat would you like to change their/your city to? ";
    cin.ignore();
    getline(cin,employees[emparraynum].city);
    cout<<"\nTheir/your city is now: "<<employees[emparraynum].city;

}
void editState(int emparraynum){
    cout<<"\nWhat would you like to change their/your state to? ";
    cin.ignore();
    getline(cin,employees[emparraynum].state);
    cout<<"\nTheir/your state is now: "<<employees[emparraynum].state;
}
void editZip(int emparraynum){
    cout<<"\nWhat would you like to change their/your zip to? ";
    cin>>employees[emparraynum].zip;
    cout<<"\nTheir/your zip is now: "<<employees[emparraynum].zip;
}
void editAdmin(int emparraynum){
    if(employees[emparraynum].admin==true){
        cout<<"\nWould you like to remove administrator privileges from this employee?";
        cout<<"\nYes[1]     No[2]"<<endl;
        int selection;
        cin>> selection;
        if(selection==1){
            cout<<"\nAre you sure?";
            cout<<"\nYes[1]     No[2]"<<endl;
            int selection2;
            cin>> selection2;
            if(selection2==1){
                employees[emparraynum].admin=true;
            }
            else{

            }
        }
        else{

        }
    }
    else{
        cout<<"\nWould you like to give administrator privileges to this employee?";
        cout<<"\nYes[1]     No[2]"<<endl;
        int selection;
        cin>> selection;
        if(selection==1){
            cout<<"\nAre you sure?";
            cout<<"\nYes[1]     No[2]"<<endl;
            int selection2;
            cin>> selection2;
            if(selection2==1){
                employees[emparraynum].admin=true;
            }
            else{

            }
        }
        else{

        }
    }
}

// Kyle's Code

void displayEmployee(){
	cout << "Employee Database" << endl;
    for(int index = 0; index < 5; index ++)
    {
        cout << "ID #: " << employees[index].ID << endl;
        cout << "Name: " << employees[index].name << endl;
        cout << "Phone Number: " << employees[index].phoneNumber << endl;
        cout << "Address: " << employees[index].address << endl;
        cout << "City: " << employees[index].city << endl;
        cout << "State: " << employees[index].state << endl;
        cout << "Zip Code: " << employees[index].zip << endl;
        cout << endl;
	}
}

// Binam's Code

void loadPet(){ //hardcoded pet data
    pets[0].ID = 1130;
    pets[0].name= "Rex";
    pets[0].DOB.Year = 2013;
    pets[0].DOB.Month = 04;
    pets[0].DOB.Day = 29;
    pets[0].age = 4;
    pets[0].gender = "Male";
    pets[0].sold = false;
    pets[0].type = "Labrador";

    pets[1].ID = 14342;
    pets[1].name= "Maxwell";
    pets[1].DOB.Year= 1999;
    pets[1].DOB.Month=4;
    pets[1].DOB.Day=19;
    pets[1].age= 9;
    pets[1].gender= "Male";
    pets[1].sold=false;
    pets[1].type= "Beagle";
 

    pets[2].ID= 12524;
    pets[2].name= "Ronda";
    pets[2].DOB.Year= 2012;
    pets[2].DOB.Month= 3;
    pets[2].DOB.Day= 30;
    pets[2].age = 4;
    pets[2].gender= "Female";
    pets[2].sold=false;
    pets[2].type = "Boxer";
 
    pets[3].ID= 12312;
    pets[3].name= "Pugsly";
    pets[3].DOB.Year= 2003;
    pets[3].DOB.Month=3;
    pets[3].DOB.Day=18;
    pets[3].age= 5;
    pets[3].gender= "Male";
    pets[3].sold=false;
    pets[3].type= "Pug";
 
    pets[4].ID=4234;
    pets[4].name= "Nikki";
    pets[4].DOB.Year= 2005;
    pets[4].DOB.Month= 4;
    pets[4].DOB.Day=30;
    pets[4].age= 5;
    pets[4].gender= "Female";
    pets[4].sold= false;
    pets[4].type= "Green Anaconda";
 
    pets[5].ID = 1232;
    pets[5].name= "Roman";
    pets[5].DOB.Year= 2011;
    pets[5].DOB.Month= 04;
    pets[5].DOB.Day= 02;
    pets[5].age= 5;
    pets[5].gender= "Male";
    pets[5].sold=false;
    pets[5].type= "Corgi";
 
    pets[6].ID=2313;
    pets[5].name= "Clarice";
    pets[6].DOB.Year= 2012;
    pets[6].DOB.Month= 03;
    pets[6].DOB.Day= 14;
    pets[6].age= 4;
    pets[6].gender= "Female";
    pets[6].sold= false;
    pets[6].type= "Borzoi";
 
    pets[7].ID=3343;
    pets[7].name= "Iagan";
    pets[7].DOB.Year= 2014;
    pets[7].DOB.Month= 04;
    pets[7].DOB.Day= 06;
    pets[7].age= 2;
    pets[7].gender= "Male";
    pets[7].sold= false;
    pets[7].type= "Samoyed";
 
    pets[8].ID= 4132;
    pets[8].name= "Aspargo"; //Iagan’s cat boyfriend haha
    pets[8].DOB.Year= 2014;
    pets[8].DOB.Month= 02;
    pets[8].DOB.Day= 18;
    pets[8].age= 2;
    pets[8].gender= "Male";
    pets[8].sold= false;
    pets[8].type= "Bombay";

    pets[9].ID=1332;
    pets[9].name= "Amelia";
    pets[9].DOB.Year= 2009;
    pets[9].DOB.Month= 11;
    pets[9].DOB.Day= 29;
    pets[9].age= 4;
    pets[9].gender= "Female";
    pets[9].sold= false;
    pets[9].type= "Sugar Glider";

}

void editPet(){
    int ID_input;
    cout<<"Type the ID of pet whose information you want to change. "<<endl;
    cin>>ID_input;

    cout<<"The former information on the pet is below. Make changes if necessary."<<endl;
    cout<<" ID :"<< pets[ID_input].ID<<endl;
    cout<<" Name :" <<pets[ID_input].name<<endl;
    cout<<" Date-Of-Birth :"<< pets[ID_input].DOB.Year<<"-"<<pets[ID_input].DOB.Month<<"-"<<pets[ID_input].DOB.Day<<endl;
    cout<<" Age :"<< pets[ID_input].age<<endl;
    cout<<" Gender :"<< pets[ID_input].gender<<endl;
    cout<<" Status :"<<pets[ID_input].sold<<endl;


    cout<<"You can now make changes to information on the pet. "<<endl;
    cout<<"ID :";
    cin>>pets[ID_input].ID;
    cout<<"Name :";
    cin>>pets[ID_input].name;
    cout<<"Year of birth :";
    cin>>pets[ID_input].DOB.Year;
    cout<<"Month of birth :";
    cin>>pets[ID_input].DOB.Month;
    cout<<"Day of birth :";
    cin>>pets[ID_input].DOB.Day;
    cout<<"Age :";
    cin>>pets[ID_input].age;
    cout<<"Gender :";
    cin>>pets[ID_input].gender;
    cout<<"Sold : (Type 'true' if sold, 'false' if unsold.) :";
    cin>>pets[ID_input].sold;
    cout<<"Type :";
    cin>>pets[ID_input].type;


    cout<<"The information on the pet "<<ID_input<<" now looks like following: "<<endl;

    cout<<" ID :"<< pets[ID_input].ID<<endl;
    cout<<" Name :" << pets[ID_input].name<<endl;
    cout<<" Date-Of-Birth :"<< pets[ID_input].DOB.Year<<"-"<<pets[ID_input].DOB.Month<<"-"<<pets[ID_input].DOB.Day<<endl;

    cout<<" Age :"<< pets[ID_input].age<<endl;
    cout<<" Gender :"<< pets[ID_input].gender<<endl;
    cout<<" Status :"<<pets[ID_input].sold<<endl;
}


//Tanner's Code
void displayPet(){
    cout << endl << "Pet Information: " << endl;
    for(int i=0;i<10;++i)
    {
        cout << endl << "Info for pet number " << i+1;
        cout << endl << "Type: " << pets[i].type;
        cout << endl << "Name: " << pets[i].name;
        cout << endl << "Date of Birth: " << pets[i].DOB.Year << "-" << pets[i].DOB.Month << "-" << pets[i].DOB.Day;
        cout << endl << "Age: " << pets[i].age;
        cout << endl << "Sold: " << pets[i].sold;
        cout << endl << "Gender: " << pets[i].gender;
        cout << endl << "ID: " << pets[i].ID << endl;
    }
}
 