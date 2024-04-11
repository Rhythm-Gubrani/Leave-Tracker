#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <regex>

using namespace std;
class leave
{
public:
  void control_panel();
  void add_user();
  void dis_user();
  void apply_leave();
  void check_leave();
  void update_user();
  void delete_user();
  void show_records();
};

// Function to show the menu
void leave ::control_panel()
{
  system("cls");
  cout << "\n\n\n\n\n\t\t\t\t\t\t*****************************************************" << endl;
  cout << "\t\t\t\t\t\t*****************************************************" << endl;
    cout << "\t\t\t\t\t\t*********INLAND WATERWAYS AUTHORITY OF INDIA*********" << endl;
    cout << "\t\t\t\t\t\t*****************************************************" << endl;
    cout << "\t\t\t\t\t\t*****************************************************\n\n" << endl;
  cout << "\n\n\t\t\t\t<-----CONTROL PANEL----->";
  cout << "\n\n1. ADD USER ";
  cout << "\n2. DISPLAY USER";
  cout << "\n3. APPLY FOR LEAVE";
  cout << "\n4. CHECK LEAVES";
  cout << "\n5. VIEW RECORDS";
  cout << "\n6. UPDATE USER";
  cout << "\n7. DELETE USER";
  cout << "\n8. EXIT ";
}

// Function to add user
void leave ::add_user()
{
  system("cls");
  fstream file;
  fstream file1;
  // open file in append or output mode
  file.open("record.txt", ios::out | ios::app);
  file1.open("record.txt",ios::in);
  string id, name, designation, departmnet;
  int days;
  string b_id, b_name, b_designation, b_departmnet;
  int b_days;
  cout << "\n\n\t\t\t\t ADD USER";
  cout << "\n\n   1. Enter name of user (use underscore for spaces ): ";
  cin >> name;
  cout << "\n\n   2. Enter unique id of user (3 digit only): ";
  cin >> id;
  file1>>b_name>>b_id>>b_departmnet>>b_designation>>b_days;
  while (!file1.eof())
  {
    if (id==b_id)
    {
      do
      {
       cout<<"\n    Id is Already Taken.....!!!"<<endl;
       cout<<"    Enter unique id of user : ";
       cin>>id;
      } while (id==b_id);
      
    }
    file1>>b_name>>b_id>>b_departmnet>>b_designation>>b_days;
  }
  
  cout << "\n\n   3.Enter Designation of the user : ";
  cin >> designation;
  cout << "\n\n   4.Enter Department of the user : ";
  cin >> departmnet;
  cout << "\n\n   5.Enter Total EL of the user : ";
  cin>>days;

  file << " " << name << "\t" << id << "\t" << designation << "\t" << departmnet << "\t" <<days<<"\n";
  file.close();
  file1.close();
}

// Function to display user details
void leave ::dis_user()
{
  system("cls");
  fstream file;
  string name, id, designation, department;
  int days;
  cout << "\n\n\t\t\t\t\tALL USERS";

  // open file in input mode
  file.open("record.txt", ios::in);
  if (!file)
    cout << "\n\nFile Opening Error!";
  else
  {

    cout << "\n\n\n Name\t\t\t        ID"
         << "\t\tDesignation\t\tDepartment\tTotal EL \n\n";
    file >> name >> id >> designation >> department>>days;

    // Till end of file is reached
    while (!file.eof())
    {

      cout<<setw(20);
      cout.setf(ios::left);
      cout << name << "\t\t" << id << "\t\t";
      cout<<setw(10);
      cout << designation << "\t\t" << department <<"\t\t"<<days<< "\n\n";
      file >> name >> id >> designation >> department>>days;
    }

    system("pause");

    // Close the file
    file.close();
  }
}

void leave ::apply_leave()
{
  system("cls");
  fstream file;
  fstream file1;
  fstream file2;
  fstream file3;
  string name, id, designation, department;
  int choice, num, x;
  int count = 0;
  int total ,remaning,days;
  string b_name, b_id, type, FromDate, ToDate, DateOfApply, purpose;
  string d_name,d_id;
  cout << "\n\n\t\t\t\tApply "<< "For Leave";

  // file open in input mode
  file.open("record.txt", ios::in);

  // file open in append or output mode
  file2.open("Days.txt",ios::out|ios::app);
  file1.open("Leave.txt", ios::out | ios::app);

  file3.open("Days.txt", ios::in);

  if (!file)
    cout << "\n\nFile Opening Error!";
  else
  {

    cout << "\n Apply By ---> 1. By Name (Press 1) " << endl;
    cout << "               2. By Id (Press 2) : ";
    cin >> x;
    if (x == 1)
    {
      cout << "\n\n Enter the name of the user : ";
      cin >> b_name;
      file >> name >> id >> designation >> department >> days;
      file3 >>d_name >> d_id >> remaning;
      while (!file.eof())
      {
        if (b_name == name)
        {

          system("cls");
          cout << "\n\n\t\t\t\t"
               << "Apply For Leave";
          cout << "\n\n   Id of the  user " << id;
          total=days;
          cout << endl<< endl;
          while (!file3.eof())
          {
            if (b_name==d_name)
            {
              total=remaning;
            }
            file3 >>d_name >> d_id >> remaning;
          }
          
          count++;
          break;
        }
        file >> name >> id >> designation >> department>>days;
      }
      file1 << " " << b_name << "\t" << id << "\t";
      file2 << " " << b_name << "\t" << id << "\t";
      if (count == 0)
      {
        cout << "\n\nUser Not"<< " Found...";
        exit(0);
      }
    }
    if (x == 2)
    {
      cout << "\n\n   Enter the Id of the user : ";
      cin >> b_id;
      file >> name >> id >> designation >> department>>days;
      file3 >>d_name >> d_id >> remaning;
      while (!file.eof())
      {

        if (b_id == id)
        {

          system("cls");
          cout << "\n\n\t\t\t\t"
               << "Apply For Leave";
          cout << "\n\n   Name of the user : " << name;
          cout << endl<< endl;
          total=days;
          while (!file3.eof())
          {
            if (b_id==d_id)
            {
              total=remaning;
            }
            file3 >>d_name >> d_id >> remaning;
          }
          count++;
          break;
        }
        file >> name >> id >> designation >> department>>days;
      }
      file1 << " " << name << "\t" << b_id << "\t";
      file2 << " " << name << "\t" << b_id << "\t";
      // system("pause");

      file.close();
      if (count == 0)
      {
        cout << "\n\nUser ID Not"
             << " Found...";
             exit(0);
      }
    }
    else
    {
      while (x >= 3 || x <= 0)
      {
        cout << "\n  Wrong Input....." << endl;
        cout << "   Please Enter again : ";
        cin >> x;
      }
    }
  }
  cout << "   Enter 1 for CL type Leave " << endl;
  cout << "   Enter 2 for EL type Leave " << endl;
  cout << "   1. Enter your choice : ";
  cin >> choice;

  while (choice >= 3 || choice <= 0)
  {
    cout << "   Enter 1 for CL type Leave " << endl;
    cout << "   Enter 2 for EL type Leave " << endl;
    cout << "   Enter your choice : ";
    cin >> choice;
  }
  if (choice == 1)
  {
    type = "CL";
    cout << "   This Feature is not avavilbe now..... " << endl
         << endl;
    ;
  }
  while (choice >= 3 || choice <= 1)
  {
    cout << "   Enter 1 for CL type Leave " << endl;
    cout << "   Enter 2 for EL type Leave " << endl;
    cout << "   Enter your choice : ";
    cin >> choice;
  }
  if (choice == 2)
  {
    type = "EL";
    cout << "   Leave Type is : " << type << endl;
    file1 << type << "\t";
  }
  cout << endl;
  cout << "   2. Enter the no. of Days of Leave : ";
  cin >> num;
  file1 << num << "\t";
  file2 << total-num<<"\n";

  cout << endl;
  cout << "   3. From Date (mm/dd/yyyy) : ";
  cin >> FromDate;
  while (FromDate.length() != 10)
  {
    cout << endl;
    cout << "     Enter Date In Correct Format.....!!!! " << endl;
    cout << "      From Date (mm/dd/yyyy) : ";
    cin >> FromDate;
  }
  file1 << FromDate << "\t";

  cout << endl;
  cout << "   4. To Date (mm/dd/yyyy): ";
  cin >> ToDate;
  while (ToDate.length() != 10)
  {
    cout << endl;
    cout << "     Enter Date In Correct Format.....!!!! " << endl;
    cout << "      To Date (mm/dd/yyyy): ";
    cin >> ToDate;
  }
  file1 << ToDate << "\t";

  cout << endl;
  cout << "   5. Date of Apply (mm/dd/yyyy) : ";
  cin >> DateOfApply;
  while (DateOfApply.length() != 10)
  {
    cout << endl;
    cout << "     Enter Date In Correct Format.....!!!! " << endl;
    cout << "      Date of Apply (mm/dd/yyyy) : ";
    cin >> DateOfApply;
  }
  file1 << DateOfApply << "\t";
  cout << endl;
  cout << "   6. Enter the Purpose of the Leave (use Underscore instead of space) : ";
  cin >> purpose;
  file1 << purpose << "\t";
  file1 <<total-num<<"\n";
  file1.close();
  file3.close();
  file2.close();
  cout<<"\n\n   Leave added sucessfully......."<<endl;
  system("pause"); 
}



// function to check user leaves
void leave ::check_leave()
{
  system("cls");
  fstream file;
  int count = 0;
  int x;
  int remaning;
  string name, id, type, num, FromDate, ToDate, DateOfApply, purpose;
  string b_name, b_id;

  // file open in input mode
  file.open("leave.txt", ios::in);
  if (!file)
    cout << "\n\nFile Opening Error!";
  else
  {

    cout << "\n Apply By ---> 1. By Name (Press 1) " << endl;
    cout << "               2. By Id (Press 2) : ";
    cin >> x;
    if (x == 1)
    {
      cout << "\n\n Enter the name of the user : ";
      cin >> b_name;
      file >> name >> id >> type >> num >> FromDate >> ToDate >> DateOfApply >> purpose>>remaning;
      system("cls");
      cout << "*****************************************************************************************************************************************" << endl;
      cout << "Name";
      cout << "\t\t\t        ID ";
      cout << "    LEAVE TYPE";
      cout << "   Total Days";
      cout << "     FROM DATE";
      cout << "   TO DATE";
      cout << "    DATE OF APPLY";
      cout << "      PURPOSE";
      cout << "          EL BALANCE "<<endl;
      cout << "*****************************************************************************************************************************************" << endl;
      while (!file.eof())
      {
        if (b_name == name)
        {
          cout << setw(20);
          cout.setf(ios::left);
          cout << b_name << "      \t";
          cout << id << "   \t";
          cout << type << "            ";
          cout << num << "            ";
          cout << FromDate << "  ";
          cout << ToDate << "    ";
          cout << DateOfApply << "       ";
          cout<<setw(19);
          cout << purpose << "    ";
          cout << remaning <<"\n";
          count++;
        }
        file >> name >> id >> type >> num >> FromDate >> ToDate >> DateOfApply >> purpose >>remaning;
      }
    }
    if (x == 2)
    {
      cout << "\n\n   Enter the Id of the user : ";
      cin >> b_id;
      file >> name >> id >> type >> num >> FromDate >> ToDate >> DateOfApply >> purpose>>remaning;
      system("cls");
      cout << "*****************************************************************************************************************************************" << endl;
      cout << "Name";
      cout << "\t\t\t        ID ";
      cout << "    LEAVE TYPE";
      cout << "   Total Days";
      cout << "     FROM DATE";
      cout << "   TO DATE";
      cout << "    DATE OF APPLY";
      cout << "      PURPOSE";
      cout << "          EL BALANCE "<<endl;
      cout << "*****************************************************************************************************************************************" << endl;
      while (!file.eof())
      {

        if (b_id == id)
        {
          cout << setw(20);
          cout.setf(ios::left);
          cout << name << "      \t";
          cout << b_id << "   \t";
          cout << type << "            ";
          cout << num << "            ";
          cout << FromDate << "  ";
          cout << ToDate << "    ";
          cout << DateOfApply << "       ";
          cout<<setw(19);
          cout << purpose << "    ";
          cout << remaning <<"\n";
          count++;
        }
        file >> name >> id >> type >> num >> FromDate >> ToDate >> DateOfApply >> purpose >>remaning;
      }
      file.close();
      if (count == 0)
      {
        cout << "\n\nUser ID Not"
             << " Found...";
      }
    }
    else
    {
      while (x >= 3 || x <= 0)
      {
        cout << "\n  Wrong Input....." << endl;
        cout << "   Please Enter again : ";
        cin >> x;
      }
    }
  }
  system("pause");
}

// Function for view all entries
void leave ::show_records()
{
  system("cls");
  fstream file;
  int count = 0;
  int remaning;
  string name, id, type, num, FromDate, ToDate, DateOfApply, purpose;

  // file open in input mode
  file.open("leave.txt", ios::in);
  if (!file)
    cout << "\n\nFile Opening Error!";
  else
  {
    file >> name >> id >> type >> num >> FromDate >> ToDate >> DateOfApply >> purpose>>remaning;
    system("cls");
   cout << "*****************************************************************************************************************************************" << endl;
      cout << "Name";
      cout << "\t\t\t        ID ";
      cout << "    LEAVE TYPE";
      cout << "   Total Days";
      cout << "     FROM DATE";
      cout << "   TO DATE";
      cout << "    DATE OF APPLY";
      cout << "      PURPOSE";
      cout << "          EL BALANCE "<<endl;
      cout << "*****************************************************************************************************************************************" << endl;
    while (file.eof() == 0)
    {
      cout << setw(20);
          cout.setf(ios::left);
          cout << name << "      \t";
          cout << id << "   \t";
          cout << type << "            ";
          cout << num << "            ";
          cout << FromDate << "  ";
          cout << ToDate << "    ";
          cout << DateOfApply << "       ";
          cout<<setw(19);
          cout << purpose << "    ";
          cout << remaning <<"\n";
      count++;
      file >> name >> id >> type >> num >> FromDate >> ToDate >> DateOfApply >> purpose>>remaning;
    }
  }

  // closing the file
  file.close();
  system("pause");
  if (count == 0)
  {
    cout << "\n\nRecords Not"
         << " Found...";
  }
}

// Function to update the user information
void leave::update_user()
{
  system("cls");
  fstream file, file1;
  int x, count = 0;
  string name, id, designation, department;
  int days,b_days;
  string b_name, b_id, b_designation, b_department;

  cout << "\n\n\t\t\t\tUpdate User Record";

  // File open in Append and output mode

  file1.open("record1.txt", ios::app | ios::out);
  file.open("record.txt", ios::in);

  if (!file)
    cout << "\n\nFile Opening Error!";
  else
  {
    cout << "\n Apply By ---> 1. By Name (Press 1) " << endl;
    cout << "               2. By Id (Press 2) : ";
    cin >> x;
    if (x == 1)
    {
      cout << "\n\n Enter the name of the user : ";
      cin >> b_name;
      file >> name >> id >> designation >> department>>days;
      while (!file.eof())
      {
        if (b_name == name)
        {

          system("cls");
          cout<<"  Name of the user : "<<name; 
          cout<<"\n  OLD ID  : "<<id; 
          cout<<"\n  OLD Department : "<<department; 
          cout<<"\n  OLD Designation  : "<<designation; 
          cout<<"\n  Total EL : "<<days;
          cout << "\n\n\t\t\t\t"<< "Update User Record";
          cout << "\n\n New User Id : ";
          cin >> b_id;
          cout << "\n New Designation : ";
          cin >> b_designation;
          cout << "\n New Department: ";
          cin >> b_department;
          cout << "\n New Total EL : ";
          cin>>b_days;
          cout << "\n\nUser is Updated Successfully...\n\n";

          file1 << " " << b_name << "\t" << b_id << "\t" << b_designation << "\t" << b_department <<"\t"<<b_days<< "\n";
          count++;
        }
        else
        {
          file1 << " " << name << "\t" << id << "\t" << designation << "\t" << department <<"\t"<<days<< "\n";
        }
        file >> name >> id >> designation >> department>>days;
      }
    }
    if (x == 2)
    {
      cout << "\n\n   Enter the Id of the user : ";
      cin >> b_id;
      file >> name >> id >> designation >> department>>days;
      while (!file.eof())
      {

        if (b_id == id)
        {

          system("cls");
          cout<<"  ID  : "<<id; 
          cout<<"\n  OLD Name of the user : "<<name; 
          cout<<"\n  OLD Designation : "<<designation; 
          cout<<"\n  OLD Department  : "<<department; 
          cout<<"\n  Total EL : "<<days;
          cout << "\n\n\t\t\t\t"<< "Update User Record";
          cout << "\n\n New User Id : ";
          cin >> b_name;
          cout << "\n New Designation : ";
          cin >> b_designation;
          cout << "\n New Department: ";
          cin >> b_department;
          cout << "\n New Total EL : ";
          cin>>b_days;
          cout << "\n\nUser is Updated Successfully...\n\n";

          file1 << " " << name << "\t" << b_id << "\t" << b_designation << "\t" << b_department <<"\t"<<b_days<< "\n";
          count++;
        }
        else
        {
          file1 << " " << name << "\t" << id << "\t" << designation << "\t" << department <<"\t"<<days<< "\n";
        }
        file >> name >> id >> designation >> department>>days;
      }
      if (count == 0)
      {
        cout << "\n\n User ID  Not"
             << " Found...";
      }

      else
      {
        while (x >= 3 || x <= 0)
        {
          cout << "\n  Wrong Input....." << endl;
          cout << "   Please Enter again : ";
          cin >> x;
        }
      }
    }
    cout << endl;
    system("pause");

    // Close the files
    file.close();
    file1.close();
    remove("record.txt");
    rename("record1.txt", "record.txt");
  }
}

// function for delete user details

void leave ::delete_user()
{
  system("cls");
  fstream file, file1;
  int x, count = 0;
  string name, id, designation, department;
  int days;
  string b_name, b_id;
  cout << "\n\n\t\t\t\tUpdate User Record";

  // File open in Append and output mode

  file1.open("record1.txt", ios::app | ios::out);
  file.open("record.txt", ios::in);

  if (!file)
    cout << "\n\nFile Opening Error!";
  else
  {
    cout << "\n Apply By ---> 1. By Name (Press 1) " << endl;
    cout << "               2. By Id (Press 2) : ";
    cin >> x;
    if (x == 1)
    {
      cout << "\n\n Enter the name of the user : ";
      cin >> b_name;
      file >> name >> id >> designation >> department>>days;
      while (!file.eof())
      {
        if (b_name == name)
        {

          system("cls");
          cout << "\n\n\t\t\t\t"
               << "Delete a User";
          cout << "\n\nUser is Deleted Successfully...\n\n";
          count++;
        }
        else
        {
          file1 << " " << name << "\t" << id << "\t" << designation << "\t" << department << "\t"<<days<<"\n";
        }
        file >> name >> id >> designation >> department>>days;
      }
    }
    if (x == 2)
    {
      cout << "\n\n   Enter the Id of the user : ";
      cin >> b_id;
      file >> name >> id >> designation >> department>>days;
      while (!file.eof())
      {

        if (b_id == id)
        {
          system("cls");
          cout << "\n\n\t\t\t\t"<< "Delete a User";
          cout << "\n\nUser is Deleted Successfully...\n\n";
          count++;
        }
        else
        {
          file1 << " " << name << "\t" << id << "\t" << designation << "\t" << department <<"\t"<<days<< "\n";
        }
        file >> name >> id >> designation >> department>>days;
      }
      if (count == 0)
      {
        cout << "\n\n User ID  Not"
             << " Found...";
      }
      else
      {
        while (x >= 3 || x <= 0)
        {
          cout << "\n  Wrong Input....." << endl;
          cout << "   Please Enter again : ";
          cin >> x;
        }
      }
    }
  }
  cout << endl;
  system("pause");

  // Close the files
  file.close();
  file1.close();
  remove("record.txt");
  rename("record1.txt", "record.txt");
}

// function for Leave Record
void call()
{
  int choice;
  char x;
  leave b;

  while (1)
  {
    b.control_panel();
    cout<<"\n\n Enter your choice : ";
    cin>>choice;
    switch(choice)
    {
      case 1:
      do{
        b.add_user();
        cout << "\n\nWant to add"<< " another user? ""(y/n) : ";
        cin>>x;
      }while (x=='y');
      break;
      
      case 2:
      b.dis_user();
      break;

      case 3:
      b.apply_leave();
      break;

      case 4 :
      b.check_leave();
      break;

      case 5 :
      b.show_records();
      break;

      case 6:
      b.update_user();
      break;

      case 7:
      b.delete_user();
      break;

      case 8:
      system("cls");
      cout<<"\n\n\t\t\t<------THANKS FOR USING------>";
    
      exit(0);
      break;

      default:
      
      cout<<"\n\n Inavalid choice\n ";
    }
  }
}

// main Driver Function 
int main()
{
  leave a;
  int password;
    cout << "\n\n\n\n\n\t\t\t\t\t\t*****************************************************" << endl;
    cout << "\t\t\t\t\t\t*****************************************************" << endl;
    cout << "\t\t\t\t\t\t*********INLAND WATERWAYS AUTHORITY OF INDIA*********" << endl;
    cout << "\t\t\t\t\t\t*****************************************************" << endl;
    cout << "\t\t\t\t\t\t*****************************************************\n\n" << endl;
    cout<<"\t\tEnter password to Login : ";
    cin>>password;
    if(password!=123)
    {
        while(password!=123)
        {
            cout<<"\n\t\tWrong Password..!!!!"<<endl;
            cout<<"\t\tEnter password to Login : ";
            cin>>password;
        }
    }
    else
    {
        cout<<"\n\t\tLOGGED IN SUCESSFULLY...... \n\n"<<endl;
    }
    system("pause");
    system("cls");
    call();
    // a.check_leave();
  
  return 0;
}
