//***************************************************
//*****************COMPUTER PROJECT******************
//********************ONLINE QUIZ********************
//***************************************************

//Note: This project is  submitted as a work sample

//***************************************************
//*******************Header Files********************
//***************************************************

#include<conio.h>
#include<process.h>
#include<string.h>
#include<io.h>
#include<iostream.h>
#include<stdio.h>
#include<fstream.h>
#include<stdlib.h>


char id[30] , pass[10] ;

//***************************************************
//**********************Classes**********************
//********MENU - Controls the Different Menus********
//***************************************************

class menu
{
	public:
		void m_main ();
		int acc_sign_in (int type);
	private:
		void start1 ();
		void start2 ();
		void user_files (int type);
		void quiz_files ();
		void take_quiz ();
};




//***************************************************
//***********USER - Controls User Funcions***********
//***************************************************

class user
{
	public:
		user ()
		{
			strcpy ( name , "Name" );
			strcpy ( age , "00" );
			strcpy ( number , "0000000000" );
			strcpy ( password , "Password" );
			strcpy ( email_id , "Email id" );
			grade = '-';
		}
		~user ()
		{}
		void input ();
		void output ();
		int compare_pass (char sample[10]);
		void upgrade (int marks);
		int return_no ();
		char name[30];
	private:
		char age[4];
		char email_id[50];
		char number[22];
		char password[10];
		char grade;
}user1;



//****************************************************
//***********QUIZ - Controls Quiz Functions***********
//****************************************************

class quiz
{
	public:
		quiz ()
		{
			option_no = '-';
			strcpy ( question , "Question" );
			strcpy ( option1, "option number 1" );
			strcpy ( option2, "option number 2" );
			strcpy ( option3, "option number 3" );
		}
		~quiz ()
		{}
		void input ();
		void output ();
		void output1 ();
		char return_opno ();
	private:
		char option_no;
		char question[1000];
		char option1[50];
		char option2[50];
		char option3[50];
};






//****************************************************
//*********************Functions**********************
//********************CLASS menu**********************
//*******************void start1 ()*******************
//****************************************************

void menu :: start1 ()
{
	int count = 0;
	do
	{
		clrscr ();
		int ch1_1;
		cout<<"\n\n\t\t\t1. MANAGE USER FILE"<<endl;
		cout<<"\t\t\t2. MANAGE QUIZ FILE"<<endl;
		cout<<"\t\t\t3. EXIT"<<endl;
		cout<<"\t\t\t4. BACK"<<endl;
		cout<<"Enter Your Choice : ";
		cin>>ch1_1;
		switch (ch1_1)
		{
			case 1: {
					user_files (1);
					count = 1;
					break;
				}
			case 2: {
					quiz_files ();
					count = 1;
					break;
				}
			case 3: exit (0);
			case 4: m_main ();
			default:{
					cout<<"\n\nEnter a valid choice!";
					getch ();
					break;
				}
		}
	} while (count == 0);
}


//****************************************************
//********************void start2 ()******************
//****************************************************

void menu :: start2 ()
{
	int count = 0;
	do
	{
		clrscr ();
		int ch2_1;
		cout<<"\n\n\t\t\t1. TAKE QUIZ"<<endl;
		cout<<"\t\t\t2. MY USER PROFILE"<<endl;
		cout<<"\t\t\t3. EXIT"<<endl;
		cout<<"\t\t\t4. BACK"<<endl;
		cout<<"Enter your choice : ";
		cin>>ch2_1;
		switch (ch2_1)
		{
			case 1: {
					take_quiz ();
					count = 1;
					break;
				}
			case 2: {
					user_files (2);
					count = 1;
					break;
				}
			case 3: exit (0);
			case 4: m_main ();
			default:{
					cout<<"\n\nEnter a valid choice!";
					getch ();
					count = 0;
					break;
				}
		}
	} while(count == 0);
}

//void m_main ()
void menu :: m_main ()
{
	start:
	{
		int ch = 0;
		clrscr ();
		cout<<"\n\n\t\t\t1. ADMINISTRATOR SIGN IN"<<endl;
		cout<<"\t\t\t2. USER SIGN IN"<<endl;
		cout<<"\t\t\t3. EXIT"<<endl;
		cout<<"Enter your choice : ";
		cin>>ch;
		switch (ch)
		{
			case 1:
				{
					int check1 = acc_sign_in (ch);
					if (check1 == 0)
					{
						cout<<"Invalid username or password!";
						getch();
						goto start;
					}
					start1 ();
					break;
				}
			case 2: {
					int check2 = acc_sign_in (ch);
					if (check2 == 0)
					{
						cout<<"Invalid username or password!";
						getch ();
						goto start;
					}
					start2 ();
					break;
				}

			case 3: {
					exit (0);
					break;
				}
			default:{
					cout<<"\n\nEnter a valid choice!";
					getch ();
					goto start;
				}
		}
	}
}

//int acc_sign_in ();
int menu :: acc_sign_in (int type)
{
	start:
	{
		user u1;
		int ch2_2 , count = 0;
		if (type == 1)
		{
			clrscr ();
			cout<<"\nLOGIN PAGE";
			cout<<"\n\nID : ";
			gets (id);
			cout<<"PASSWORD : ";
			gets (pass);
			if ( (strcmp ( id , "ADMINISTRATOR" ) == 0) && (strcmp ( pass , "adminlogin" ) == 0) )
				count = 1;
		}
		else
		if (type == 2)
		{
			cout<<"Press 1 for old user and 2 for new user...  ";
			cin>>ch2_2;
			if (ch2_2 == 1)
			start1:
			{
				clrscr ();
				cout<<"\n\n\nLOGIN PAGE";
				cout<<"\n\nID : ";
				gets(id);
				cout<<"PASSWORD : ";
				gets (pass);
				ifstream login;
				login.open ( "PROFILE.DAT" , ios::in | ios::binary );
				login.seekg(0);
				while (!login.eof())
				{
					login.read((char*) & u1 , sizeof (u1));
					while ( (strcmp ( id , u1.name ) == 0) )
					{
						if (u1.compare_pass(pass) == 0)
						{
							user1 = u1;
							count = 1;
							break;
						}
						else
							continue;
					}
				}
				login.close ();
			}
			else
			{
				user u2;
				cout<<endl<<endl<<endl;
				u2.input ();
				ofstream insert;
				insert.open ( "PROFILE.DAT" , ios::in | ios::app | ios::binary );
				insert.write ( (char*) &u2 , sizeof(user) );
				insert.close ();
				cout<<"\n\n\nYou are successfully registered!";
				getch ();
				goto start1;
			}
		}
		return count;
	}
}


//void user_files (int type);
void menu :: user_files (int type)
{
	int ch1 , count = 0 , count1 = 0;
	char nam[30];
	if (type == 1)
	{
		do
		{
			clrscr ();
			cout<<"\n\n\t\t\t1. VIEW FILE"<<endl;
			cout<<"\t\t\t2. DELETE USER"<<endl;
			cout<<"\t\t\t3. EXIT"<<endl;
			cout<<"\t\t\t4. BACK"<<endl;
			cout<<"Enter your choice : ";
			cin>>ch1;
			if ( ch1 == 1 || ch1 == 2)
			{	cout<<"Enter the User Name : ";
				gets (nam);
			}
			switch (ch1)
			{
				case 1: {
						user u3;
						int j = 0;
						ifstream display;
						display.open ( "PROFILE.DAT", ios::in | ios::binary );
						clrscr ();
						display.seekg (0);
						while (!display.eof())
						{
							display.read ( (char*)&u3, sizeof(u3) );
							if (strcmp(u3.name , nam) == 0)
							{
								u3.output ();
								j++;
							}
						}
						if (j == 0)
							cout<<"\n\nUser not found!";
						else
							cout<<"\n\n\n\n\n  Press any key to continue...";
						getch ();
						display.close ();
						count = 0;
						break;
					}
				case 2: {
						user u3;
						ifstream old;
						old.open ( "PROFILE.DAT", ios::in | ios::binary );
						clrscr ();
						int j = 0 ;
						char conform;
						ofstream temp;
						temp.open ( "NEW_P.DAT" , ios::out | ios::binary );
						while (!old.eof())
						{
							old.read ( (char*)&u3 , sizeof(u3));
							if (strcmp(u3.name , nam) == 0)
							{
								u3.output ();
								j++;
								cout<<"\n\n\nAre you sure you want to delete this user? (y / n) : ";
								cin>>conform;
								if (conform == 'n' || conform =='N')
									temp.write ( (char*)&u3 , sizeof(u3) );
							}
							else
								temp.write ( (char*)&u3 , sizeof(u3) );
						}
						if (j == 0)
							cout<<"\n\nUser not found!";
						else
							cout<<"\n\nUser deleted successfully!";
						getch ();
						old.close ();
						temp.close ();
						remove ( "PROFILE.DAT" );
						rename ( "NEW_P.DAT" , "PROFILE.DAT" );
						count  = 0;
						break;
					}
				case 3: exit (0);
				case 4: start1 ();
				default:{
						cout<<"\nEnter a valid choice!";
						getch ();
						count = 0;
						break;
					}
			}
		} while ( count == 0);
	}
	else
	{
		do
		{
			clrscr ();
			cout<<"\n\n\t\t\t1. VIEW MY PROFILE"<<endl;
			cout<<"\t\t\t2. UPDATE MY PROFILE"<<endl;
			cout<<"\t\t\t3. EXIT"<<endl;
			cout<<"\t\t\t4. BACK"<<endl;
			cout<<"Enter your choice : ";
			cin>>ch1;
			switch (ch1)
			{
				case 1: {
						clrscr ();
						user1.output ();
						cout<<"\n\n\n\n\n\nPress any key to continue....";
						getch ();
						count1 = 0;
						break;
					}
				case 2: {
						user u3;
						cout<<endl<<endl<<endl;
						user1.input ();
						user1.output ();//ofstream edit;
						cout<<"\n\n\n\n\n\nEditing Successful! Press any key to continue....";
						getch ();
						count1 = 0;
						break;
					}
				case 3: exit (0);
				case 4: start2 ();
				default:{
						cout<<"\nEnter a valid choice!";
						getch ();
						count1 = 0;
						break;
					}
			}
		} while (count1  == 0);
	}
}


//void quiz_files ();
void menu :: quiz_files ()
{
	start:
	{
		clrscr ();
		int ch1_2 , ch1_3  , q_no;
		cout<<"\n\n\t\t\t1. VIEW FILES"<<endl;
		cout<<"\t\t\t2. UPDATE FILES"<<endl;
		cout<<"\t\t\t3. EXIT"<<endl;
		cout<<"\t\t\t4. BACK"<<endl;
		cout<<"Enter your choice : ";
		cin>>ch1_2;
		clrscr ();
		switch (ch1_2)
		{
			case 1:{
					clrscr ();
					quiz q1;
					int i = 1 ;
					ifstream display;
					display.open ( "QUIZ.DAT", ios::in | ios::binary );
					display.seekg (0);
					while (!display.eof() && i == 1)
					{
						display.read ( (char*)&q1, sizeof(q1) );
						q1.output ();
						cout<<"\n\n\n\n\n\nPress 0 to go back...\n\nPress 1 to continue....";
						cin>>i;
					}
					display.close ();
					goto start;
				}
			case 2: {
					start1:
					{
						clrscr ();
						cout<<"\n\n\t\t\t1. ADD QUESTIONS"<<endl;
						cout<<"\t\t\t2. EDIT QUESTIONs"<<endl;
						cout<<"\t\t\t3. DELETE QUESTIONS"<<endl;
						cout<<"\t\t\t4. EXIT"<<endl;
						cout<<"\t\t\t5. BACK"<<endl;
						cout<<"Enter your choice : ";
						cin>>ch1_3;
						if (ch1_3 == 2 || ch1_3 == 3)
						{
							cout<<"\n\nEnter question number : ";
							cin>>q_no;
						}
						switch (ch1_3)
						{
							case 1: {
									clrscr ();
									quiz q1;
									do
									{
										q1.input ();
										ofstream insert;
										insert.open ( "QUIZ.DAT" , ios::in | ios::app | ios::binary );
										insert.write ( (char*) &q1 , sizeof(q1) );
										insert.close ();
										cout<<"\n\nWant to add more questions? (y / n) : ";
									}while (getchar () == 'y' || getchar () == 'Y');
									goto start1;
								}
							case 2: {
									clrscr ();
									quiz q1;
									char ch1;
									fstream edit;
									edit.open ( "QUIZ.DAT", ios::in | ios::out | ios::binary );
									edit.seekp (q_no*sizeof(quiz) , ios::beg);
									edit.read ( (char*)&q1 , sizeof(q1) );
									q1.output ();
									cout<<"Do you want to edit this question? ( Y / N) : ";
									cin>>ch1;
									if (ch1 == 'y' || ch1 == 'Y')
									{
										q1.input ();
										edit.seekp (q_no*sizeof(quiz) , ios::beg);
										edit.write ( (char*)&q1 , sizeof(q1) );
										cout<<"\n\n\n\n\n\nEditing Successful! Press any key to continue....";
										getch ();
									}
									edit.close ();
									goto start1;
								}
							case 3:	{
									quiz q1;
									ifstream old;
									old.open ( "QUIZ.DAT", ios::in | ios::binary );
									clrscr ();
									long pos;
									int j = 0 ;
									char conform;
									ofstream temp;
									old.seekg(0);
									temp.open ( "NEW_Q.DAT" , ios::out | ios::binary );
									while (!old.eof())
									{
										pos = old.tellg();
										cout<<endl<<pos;
										old.read ( (char*)&q1 , sizeof(q1));
										if (pos == q_no*sizeof(quiz))
										{
											q1.output ();
											j++;
											cout<<"\n\n\nAre you sure you want to delete this user? (y / n) : ";
											cin>>conform;
											if (conform == 'n' || conform =='N')
												temp.write ( (char*)&q1 , sizeof(q1) );
										}
										else
											temp.write ( (char*)&q1 , sizeof(q1) );
									}
									if (j == 0)
										cout<<"\n\nQuestion not found!";
									else
										cout<<"\n\nQuestion deleted successfully!";
									getch ();
									old.close ();
									temp.close ();
									remove ( "QUIZ.DAT" );
									rename ( "NEW_Q.DAT" , "QUIZ.DAT" );
									goto start1;
								}
							case 4: exit (0);
							case 5: goto start;
							default:{
									cout<<"\nEnter a valid choice!";
									getch ();
									goto start1;
								}
						}
					}
				}
			case 3:	exit (0);
			case 4: start1();
			default:{
					cout<<"\nEnter a valid choice!";
					getch ();
					goto start;
				}
		}
	}
}

//void take_quiz ();
void menu :: take_quiz ()
{
	int i = 0;
	char ans;
	int numb[20] , opt;
	{
		int i ,j ;
		int n;
		quiz q;
		for ( i = 0 ; i < 20 ; i++)
		{
			start:
			{
				n = random (30) + 1;
				if (i == 0)
					numb[i] = n;
				else
				{
					for ( j = 0 ; j < i ; j++ )
					{
						if (n == numb[j])
							goto start;
						else
							numb[i] = n;
					}
				}
			}
		}
	}
	int tempmks = 0;
	quiz q2;
	i = 0;
	ifstream fin;
	fin.open ( "QUIZ.DAT",ios::in | ios::binary );
	do
	{
		fin.seekg (numb[i]* sizeof(quiz) , ios::beg);
		fin.read ( (char*) &q2,sizeof(q2) );
		q2.output1 ();
		cout<<"\n\nYOUR ANSWER\nENTER THE OPTION NUMBER :";
		cin>>ans;
		if (ans == q2.return_opno())
		{
			tempmks = tempmks + 2;
			cout<<"\n\nRESULT : Correct answer!";
		}
		else
			cout<<"\n\n\RESULT : Incorrect answer!";
		cout<<"\n\n\nSCORE : "<<tempmks;
		i++;
		cout<<endl<<"\n\n\n\n\T Press 1 for Next Question and 2 for Exit....  ";
		cin>>opt;
	}while (opt == 1 && i < 20);
	fin.close();
	if (i == 20)
	{
		cout<<"\n\n\nQuiz completed!!";
		cout<<"\n\nYour score : "<<tempmks<<" / 40 ";
		user1.upgrade(tempmks);
		fstream up;
		long pos;
		user u1;
		up.open ("PROFILE.DAT" , ios::in | ios::out | ios::binary);
		up.seekg (0);
		while (!up.eof())
		{
			cout<<"!";pos = up.tellg ();
			up.read((char*) & u1 , sizeof (u1));
			while ( (strcmp ( id , u1.name ) == 0) )
			{
				if (u1.compare_pass(pass) == 0)
				{
					up.seekp (pos);
					up.write((char*)&user1 , sizeof(user));
					break;
				}
			}
		}
		up.close ();
		start2 ();
	}
	else
	{
		cout<<"Quiz incomplete. Exiting without saving details...";
		getch ();
		start2 ();
	}
}

//CLASS user
//void input ();
void user :: input ()
{
	cout<<"\n\n\nNAME : ";
	gets (name);
	cout<<"\n\nAGE : ";
	cin>>age;
	cout<<"\n\nCONTACT INFORMATION";
	cout<<"\nEMAIL ID : ";
	gets (email_id);
	cout<<"\nMOBILE / LANDLINE NUMBER : ";
	cin>>number;
	cout<<"\n\nENTER PASSWORD FOR YOUR ACCOUNT ( max 10 CHARACTERS ) : ";
	gets (password);
	cout<<"\n\n\nPRESS ENTER TO CONTINUE...";
	getch ();
}

//void output ();
void user :: output ()
{
	clrscr ();
	cout<<"NAME : ";
	puts (name);
	cout<<"\nAGE : "<<age;
	cout<<"\n\nCONTACT INFORMATION";
	cout<<"\nEMAIL ID : ";
	puts (email_id);
	cout<<"MOBILE / LANDLINE NUMBER : "<<number;
	cout<<"\n\n\nQUIZ RESULTS";
	cout<<"\nPREVIOUS QUIZ GRADE : "<<grade;
	getch ();
}

//int compare_pass (pass)
int user :: compare_pass (char sample[10])
{
	return strcmp ( sample , password );
}

//void upgrade ()
void user :: upgrade (int marks)
{
	if (marks >= 34)
		grade = 'A';
	else
	if (marks >=24 && marks < 34)
		grade = 'B';
	else
	if (marks >=14 && marks < 24)
		grade = 'C';
	else
	if (marks < 14)
		grade = 'D';
}

//CLASS quiz
//void input ()
void quiz :: input ()
{
	cout<<"\n\nQUESTION : ";
	gets (question);
	cout<<"\n\nOPTIONS : \n";
	gets (option1);
	gets (option2);
	gets (option3);
	cout<<"\n\n\nANSWER";
	cout<<"\nENTER OPTION NUMBER : ";
	cin>>option_no;
}

//void output ()
void quiz :: output ()
{
	clrscr ();
	cout<<"QUESTION : ";
	puts (question);
	cout<<"\nOPTIONS :\n";
	cout<<"\t\t";
	puts (option1);
	cout<<"\t\t";
	puts (option2);
	cout<<"\t\t";
	puts (option3);
	cout<<"\n\n\nANSWER";
	cout<<"\nOPTION NUMBER : "<<option_no;
}

void quiz :: output1 ()
{
	clrscr ();
	cout<<"QUESTION : ";
	puts (question);
	cout<<"\nOPTIONS :\n";
	cout<<"\t\t";
	puts (option1);
	cout<<"\t\t";
	puts (option2);
	cout<<"\t\t";
	puts (option3);
}

char quiz :: return_opno ()
{
	return option_no;
}



int main ()
{
	clrscr ();
	cout<<"\t\t\t    ONLINE QUIZ SYSTEM";
	cout<<"\n\n\n\n\t\tThis facility helps conduct an online quiz.";
	cout<<"\n\n\t\tThe subject covered is computer science.";
	cout<<"\n\n\n\n\n\n    Press any key to continue...";
	getch ();
	menu m;
	m.m_main ();
	getch ();
	return 0;
}
