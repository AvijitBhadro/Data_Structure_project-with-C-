#include <iostream>
#include <fstream>
#include <string>
#include<cstdlib>
#include<conio.h>
#include<time.h>
#include<iomanip>

using namespace std;

struct Patient
{
    string name;
    string disease;
    int cabin;
    int phone;
    int age;
    Patient* next;
};

Patient* head = nullptr;

void welcome_screen();
void Title();
void addPatient();
void updatePatient();
void deletePatient();
void viewPatients();
void endthis();
void login();
void  viewSpecificPatient();

int main()
{



    welcome_screen();
    login();
    int choice;

    while (1)
    {
        Title();
        cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  HOSPITAL MANAGEMENT SYSTEM \n\n";
        cout << "\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
        cout << "\t\t\t\t\t\t _________________________________________________________________ \n";
        cout << "\t\t\t\t\t\t|                                           	                  |\n";
        cout << "\t\t\t\t\t\t|             1  >> Add New Patient Record                        |\n";
        cout << "\t\t\t\t\t\t|             2  >> Update Patient Information                    |\n";
        cout << "\t\t\t\t\t\t|             3  >> Delete Patient Information                    |\n";
        cout << "\t\t\t\t\t\t|             4  >> View Patient Information                      |\n";
        cout << "\t\t\t\t\t\t|             5  >> View Specific Patient Information             |\n";
        cout << "\t\t\t\t\t\t|             6  >> Exit the Program                              |\n";
        cout << "\t\t\t\t\t\t|_________________________________________________________________|\n\n";
        cout << "\t\t\t\t\t\tEnter your choice: ";
        cin >> choice;

        if (choice > 6 || choice < 1)
        {
            cout << "\n\n\t\t\t\t\t\tInvalid Choice\n";
            cout << "\t\t\t\t\t\tTry again...........\n\n";
            continue;
        }

        system("cls");
        switch (choice)
        {
        case 1:
            addPatient();
            break;
        case 2:
            updatePatient();
            break;
        case 3:
            deletePatient();
            break;
        case 4:
            viewPatients();
            break;
        case 5:
            viewSpecificPatient();
            break;

        case 6:
            endthis();

            return 0;
        }
    }

    return 0;
}

void welcome_screen()
{
    Title();
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout<<"\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                  WELCOME TO                                           |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                           HOSPITAL MANAGEMENT SYSTEM                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                 - By Avijit Bhadro                    |@@\n";
    cout<<"\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
    cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";
    system("pause");
    system("cls");
}

void Title()
{
    cout << "\n\n\t\t\t\t\t---------------------------------------------------------------------------------------\n";
    cout << "\n\t\t\t\t                                          LIFE CURE HOSPITAL               ";
    cout << "\n\n\t\t\t\t\t----------------------------------------------------------------------------------------";

}

void addPatient()
{
    Title();
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    cout<<"\n\n\t\t\t\t\t\t\t\t\t"<< asctime (timeinfo);

    Patient* newPatient = new Patient;
    if (newPatient == nullptr)
    {
        cout << "Memory allocation error.\n";
        system("pause");
        system("cls");
        return;
    }
    cout<<"\n\n**********************************************************\n";
    cout << "\nEnter patient's Name: ";
    cin.ignore();
    getline(cin, newPatient->name);

    cout << "\nEnter disease: ";
    getline(cin, newPatient->disease);

    cout << "\nEnter the age: ";
    cin >> newPatient->age;

    cout << "\nEnter cabin no: ";
    cin >> newPatient->cabin;

    cout << "\nEnter phone number: ";
    cin >> newPatient->phone;

    newPatient->next = head;
    head = newPatient;

    ofstream file("patients.txt", ios::app);
    if (!file.is_open())
    {
        cout << "Failed to open file for writing.\n";
        delete newPatient;
        system("pause");
        system("cls");
        return;
    }

    file << newPatient->name << ' ' << newPatient->disease << ' ' << newPatient->cabin << ' ' << newPatient->phone << ' ' << newPatient->age << '\n';

    file.close(); // Close the file before returning

    cout << "\n**********************************************************\n";
    cout << "\nPatient added successfully.\n\n";

    system("pause");
    system("cls");
}

void viewSpecificPatient()
{
    Title();
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    cout << "\n\n\t\t\t\t\t\t\t\t\t" << asctime (timeinfo);

    string patientName;
    cout << "\n\nEnter the name of the patient: ";
    cin.ignore();
    getline(cin, patientName);


    Patient* current = head;
    bool found = false;

    while (current != nullptr)
    {
        if (current->name == patientName)
        {
            found = true;
            cout<<"\n**********************************************************\n";
            cout << "\nName: " << current->name << '\n';
            cout << "Disease: " << current->disease << '\n';
            cout << "Cabin no: " << current->cabin << "\nPhone number: " << current->phone << "\nAge: " << current->age << "\n\n";
            cout<<"\n**********************************************************\n";
            break;  // Stop searching once the patient is found
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "\nPatient not found.\n\n";
    }

    system("pause");
    system("cls");
}

void updatePatient()
{
    Title();
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    cout<<"\n\n\t\t\t\t\t\t\t\t\t"<< asctime (timeinfo);

    int patientIndex;
    cout << "\n\nEnter patient's index to update: ";
    cin >> patientIndex;

    Patient* current = head;
    for (int i = 1; i < patientIndex && current != nullptr; i++)
    {
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "Invalid patient index.\n";
        system("pause");
        system("cls");
        return;
    }
    cout<<"\n\n**********************************************************\n";
    cout << "Enter patient's updated Name: ";
    cin.ignore();
    getline(cin, current->name);

    cout << "\nEnter updated disease: ";
    getline(cin, current->disease);

    cout << "\nEnter the updated age: ";
    cin >> current->age;

    cout << "\nEnter updated cabin no: ";
    cin >> current->cabin;

    cout << "\nEnter updated phone number: ";
    cin >> current->phone;

    ofstream file("patients.txt");
    if (!file.is_open())
    {
        cout << "Failed to open file for writing.\n\n";
        system("pause");
        system("cls");
        return;
    }

    Patient* temp = head;
    while (temp != nullptr)
    {
        file << temp->name << ' ' << temp->disease << ' ' << temp->cabin << ' ' << temp->phone << ' ' << temp->age << '\n';
        temp = temp->next;
    }

    file.close();
    cout<<"\n**********************************************************\n";
    cout << "\nPatient updated successfully.\n\n";
    system("pause");
    system("cls");
}

void deletePatient()
{
    Title();
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    cout<<"\n\n\t\t\t\t\t\t\t\t\t"<< asctime (timeinfo);

    int patientIndex;

    cout << "\n\nEnter patient's index to delete: ";
    cin >> patientIndex;

    if (patientIndex < 1)
    {
        cout << "\nInvalid patient index.\n\n";
        system("pause");
        system("cls");
        return;
    }

    Patient* current = head;
    Patient* prev = nullptr;

    for (int i = 1; i < patientIndex && current != nullptr; i++)
    {
        prev = current;
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "Invalid patient index.\n\n";
        system("pause");
        system("cls");
        return;
    }

    if (prev == nullptr)
    {

        head = current->next;
    }
    else
    {
        prev->next = current->next;
    }

    delete current;

    ofstream file("patients.txt");
    if (!file.is_open())
    {
        cout << "Failed to open file for writing.\n\n";
        system("pause");
        system("cls");
        return;
    }

    Patient* temp = head;
    while (temp != nullptr)
    {
        file << temp->name << ' ' << temp->disease << ' ' << temp->cabin << ' ' << temp->phone << ' ' << temp->age << '\n';
        temp = temp->next;
    }

    file.close(); // Close the file after writing patient information

    cout << "\n\nPatient deleted successfully.\n\n";

    system("pause");
    system("cls");
}


void viewPatients()
{
    Title();
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    cout<<"\n\n\t\t\t\t\t\t\t\t\t"<< asctime (timeinfo);

    if (head == nullptr)
    {
        cout << "\n\nNo patient records found.\n";
        return;
    }
    cout<<"\n";
    cout<<"\n\n**********************************************************\n";
    Patient* current = head;
    while (current != nullptr)
    {
        cout << "Name: " << current->name << '\n';
        cout << "Disease: " << current->disease << '\n';
        cout << "Cabin no: " << current->cabin << "\nPhone number: " << current->phone << "\nAge: " << current->age << "\n\n";
        current = current->next;
    }
    cout<<"**********************************************************\n";
    system("pause");
    system("cls");
}

void endthis()
{

    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout<<"\t\t\t\t\t@@ _______________________________________________________________________________________ @@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                                           		                                  |@@\n";
    cout<<"\t\t\t\t\t@@|                               THANK YOU FOR USING                                     |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                            HOSPITAL MANAGEMENT SYSTEM                                 |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                                                       |@@\n";
    cout<<"\t\t\t\t\t@@|                                                             - By Avijit Bhadro        |@@\n";
    cout<<"\t\t\t\t\t@@|_______________________________________________________________________________________|@@\n";
    cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n\t\t\t\t\t";

}
void login()
{
    Title();
    string pass ="";
    char ch;
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  HOSPITAL MANAGEMENT SYSTEM \n\n";
    cout<<"\t\t\t\t\t\t\t\t------------------------------";
    cout<<"\n\t\t\t\t\t\t\t\t\t     LOGIN \n";
    cout<<"\t\t\t\t\t\t\t\t------------------------------\n\n";
    cout << "\t\t\t\t\t\t\t\tEnter Password: ";
    ch = _getch();
    while(ch != 13)
    {
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    if(pass == "1234")
    {
        cout << "\n\n\t\t\t\t\t\t\t\tAccess Granted! \n";
        system("PAUSE");
        system ("CLS");
    }
    else
    {
        cout << "\n\n\t\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\t\tPlease Try Again\n\n";
        system("PAUSE");
        system("CLS");
        login();
    }
}

