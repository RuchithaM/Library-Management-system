#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<fstream>
using namespace std;
struct Student
{
	string id,name;
}stu;
struct Book
{
	string id,bname,aname;
}book;

int ch;

void append_user_details(string username, string time)
{
    fstream myfile;
	myfile.open ("user.txt",ios::app);
	myfile<<setw(20)<<username;
	myfile<<setw(75);
	myfile<<time<<endl;
	myfile.close();
}

void greating()
{	system("CLS");
	int ch;
	string username;
	cout<<std::endl;
	cout<<"                        Sri Library                      "<<endl;
	cout<<"             No.11, 'B' Block ,J P Nagar Mysuru          "<<endl;
	cout<<"                   Contact No. 0821-42428		"<<endl;
	cout<<"	              	Pin code:570008              "<<endl;
    
    
}

void bye()
{
cout<<"Thank you"<<endl;
system("CLS");
exit(0);
}

void Admin_password()
{	
    string ps,username; //password
    int a; //attemts
	cout<<"Login as Admin"<<endl;
	cout<<setw(30)<<"Enter username : ";
	cin>>username;
    time_t currenttime;
	time(&currenttime);
    string time=ctime(&currenttime);
    for (int i =3;i>0;i--)
	{	a=i-1;  //decrement the attemt
		cout<<setw(30)<<"Enter password :";
		cin>>ps;
		if(ps == "password")
		{	
            cout<<"Welcome"<<endl;
            append_user_details(username,time);

			break;
		}
		else
		{	if (a!=0)
			{	cout<<"User name or password is incorrect"<<std::endl<<endl;
				cout<<"You are left with "<<a<<" ATTEMPTs "<<std::endl<<endl;	
			}
			else
			{	cout<<"Wrong password"<<std::endl<<endl;
				abort();
			}
		}
	}	

}

bool verify_id(fstream& f,string id)
{
	string line;
    
	int flag=0;
	while(!f.eof())
    {	
		getline(f, line);
        if (line.find(id) != string::npos) //equal
        {   
            return 1;
            break;
        }

    }
return 0;
}


void add_student()
{	int n;
	fstream f;
    f.open("Student.txt");
			 
	cout<<"Enter the number of student details to be added"<<endl;
	cin>>n; 	  	
	for (int i=0;i<n;i++)
	{	cout<<"Enter student_id : ";
		cin>>stu.id;
		
    	int flag= verify_id(f,stu.id);
		if (flag==0)
		{
		cout<<"Enter student_name : ";
		cin>>stu.name;	
		fstream myfile;
        myfile.open ("Student.txt",ios::app);
        myfile<<setw(15)<<stu.id<<setw(30)<<stu.name<<endl;
        myfile.close();
		}
		else
		{
			cout<<"Student Id already exist "<<endl;
			i--;
		}
	}
cout<<"Student data is added successfully"<<endl;
}

void add_book()
{	int n;	 
	cout<<"Enter the number of books to be added : "<<endl;
	cin>>n; 	  	
	for (int i=0;i<n;i++)
	{	cout<<"Enter book_id : ";
		cin>>book.id;
		fstream f;
    	f.open("books.txt");
		int flag= verify_id(f,book.id);
		if (flag==0)
		{
		cout<<"Enter book_name : ";
		cin>>book.bname;	
		cout<<"Enter auother name : ";
		cin>>book.aname;
        fstream myfile;
        myfile.open ("books.txt",ios::app);
        myfile<<setw(30)<<book.id<<setw(30)<<book.bname<<setw(30)<<book.aname<<endl;
        myfile.close();
		}
		else
		{
			cout<<"Book Id already exist "<<endl;
			i--;
		}
	}
cout<<"Books are added successfully"<<endl;
}

void sdisplay()
{
    cout<<setw(15)<<"Student ID" <<setw(30) << "Student Name"<<endl;
    string details;
    ifstream myfile("Student.txt");
    getline(myfile,details);
    while(getline(myfile,details))
        cout<<details<<endl;
}

void bdisplay()
{   
	cout<<setw(30)<<"BOOK ID" <<setw(30) << "BOOK Name" << setw(30) <<"AUOTHER NAME" <<endl;
    string details;
    ifstream myfile("books.txt");
    getline(myfile,details);
    while(getline(myfile,details))
    cout<<details<<endl;
}

void issue()
{
	int  book_id,n;
	string  stu_name,book_name,stu_id;
	cout<<"Enter the details"<<endl;
	cout<<"Enter the Student-ID : ";
	cin>>stu.id;
	fstream f;
	f.open("Student.txt");
	int flag= verify_id(f,stu.id);
	if (flag==1)
		{	
			cout<<"Enter number of book to be issued : ";
			cin>>n;
			if (n>=1 and n<4)
			{	
				fstream myfile;
				myfile.open ("Book_issue.txt",ios::app);
				myfile<<setw(15)<<stu.id;
				for (int i=1;i<=n;i++)
				{	
					cout<<"Enter the Book_ID : ";
					cin>>book.id;
					myfile<<setw(30)<<book.id<<setw(30);
				}
				cout<<"Books are issued"<<endl;
				myfile<<endl;
				myfile.close();
			
			}
			else
				cout<<"Maximam books for a signle member is 3"<<endl; 
	}
	else
	cout<<"Student id doesn't exist"<<endl;
}

void display_issue()
{
	cout<<setw(15)<<"Student ID" <<setw(30);
	for(int i=1;i<4;i++)
	{	
		cout<<"Book ID" <<setw(30);}
		cout<<endl<<setw(15);
		string details;
		ifstream myfile("issue.txt");
		getline(myfile,details);
		while(getline(myfile,details))
			cout<<details<<endl;	
}

void display_user()
{    
    string details;
	ifstream myfile("user.txt");
	getline(myfile,details);
	cout<<setw(18)<<"Name"<<setw(70)<<"Date & Time"<<endl;
	cout<<setfill('-');
	while(getline(myfile,details))
		cout<<details<<endl;
}

void clear_user()
{	string password;
    cout<<"Conform the password"<<endl;
	  	cin>>password;
	  	if (password=="password")
	  	{	
			fstream f("user.txt",ios::out | ios::trunc);
			f.close();  		   
  		 	cout<<"Data is cleared sucssfully ! "<<endl;
	  	 	
	  	}
	  	else
	  		cout<<"wrong password!, ";

}

void stu_remove() 
{

	string line;
	cout<<"Enter the stu-id to be removed from database : ";
	cin>>stu.id;
	fstream f;
    f.open("Student.txt");
    int i= verify_id(f,stu.id);
	if (i==1)
	{
		while(!f.eof())
			{
				getline(f, line);
				if (line.find(stu.id) != string::npos)
				{
					cout<<"Stu-id "<<stu.id<<" is removed from database....";
				}
				else
				{ 
					fstream t;
					t.open ("tem.txt",ios::app);
					t<<line<<endl;
					t.close();

				}
			}
	
	
	remove("Student.txt");
	rename("tem.txt","Student.txt");
	cout<<"Removed successfully"<<endl;
	}
	else cout<<"Student id does't exist !"<<endl;
		f.close();
}


void search_stu() 
{int flag=1;
string line,data;
cout<<"Enter the stu-id to search : ";
cin>>stu.id;
  fstream f;
  f.open("Student.txt");
  while(!f.eof())
    {getline(f, line);
        if (line.find(stu.id) != string::npos)
        {
            data=line;
			flag=0;
        }
        
    }
if(flag==0) cout<<data<<endl;
else  cout<<"Stu-id "<<stu.id<<" doesn't exist "<<endl;
f.close();
}

void book_remove() 
{

string line;
cout<<"Enter the book-id to be removed from database : ";
cin>>stu.id;
  fstream f;
  
  f.open("books.txt");
  while(!f.eof())
    {getline(f, line);
        if (line.find(stu.id) != string::npos)
        {
            cout<<"Book-id "<<book.id<<" is removed from database...."<<endl;
        }
        else
        { 
            fstream t;
            t.open ("tem.txt",ios::app);
            t<<line<<endl;
            t.close();

        }
    }
f.close();
remove("books.txt");
rename("tem.txt","books.txt");
}

int choice()
{int ch;
cout<<"------------------------------------------------------------"<<endl;
cout<<"1.  Add a new book"<<endl;
cout<<"2.  Add a new student"<<endl;
cout<<"3.  Remove book"<<endl;
cout<<"4.  Remove student"<<endl;
cout<<"5.  Issue a book"<<endl;
cout<<"6.  View stack"<<endl;
cout<<"7.  View student account"<<endl;
cout<<"8.  List of book issued"<<endl;
cout<<"9.  User details"<<endl;
cout<<"10. Exit"<<endl;
cout<<"-------------------------------------------------------------"<<endl;
cout<<"Enter your choice"<<endl;
cin>>ch;
return(ch);
}

int main()
{greating();
Admin_password();
while(1)
{	system("CLS");
	greating();
	
	int c=choice();
switch(c)
{
	case(1):
			{add_book();
			system("pause");
			}
			break;
	case(2):
			{add_student();
			system("pause");}
			break;

	case(3):{book_remove();
			 system("pause");}
			break;
	case(4):{stu_remove();
			 system("pause");}
			break;
	case(5):{issue();
			system("pause");
			}break;
	case(6):{bdisplay();
			system("pause");}break;
	case(7):{//sdisplay();
			//system("pause");
			

			system("CLS");
			greating();
			int ch;
			cout<<"1. Search student by stu-id "<<endl;
			cout<<"2. View all students "<<endl;
			
			cout<<"Enter your choice"<<endl;
			cin>>ch;
			switch(ch)
			{
				case(1):{	
							search_stu();
							system("pause");

						}break;
				case(2):{
							sdisplay();
							system("pause");

						}break;
				default:cout<<"invalid"<<endl;


			}


			
			}break;
	case(8):{display_issue();
			system("pause");}break;
	case(9):{
			system("CLS");
			greating();
			int ch;
			cout<<"1. Display user login details"<<endl;
			cout<<"2. clear user login data"<<endl;
			
			cout<<"Enter your choice"<<endl;
			cin>>ch;
			switch(ch)
			{
				case(1):{
							display_user();
							system("pause");

						}break;
				case(2):{
							clear_user();
							system("pause");

						}break;
				default:cout<<"invalid"<<endl;


			}}break;
	case(10):bye();
			break;
	default:cout<<"Invalid option"<<endl;
}	
}return 0;
}

