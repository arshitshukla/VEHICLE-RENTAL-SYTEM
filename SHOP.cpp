#include<iostream>
#include<iomanip>
#include<direct.h>
#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<fstream>
#include<process.h>
#include<string.h>
using namespace std;
void hline()
	{
	for(int i=0;i<80;i++)
		cout<<"-";
	cout<<"\n";
	}
void wel();
class buyer 	{
		char bname[20],address[60];
		int bno;
	public:
		void input()

			{
			system("CLS");
			int a;
			hline();
			cout<<"\t\t\t\tEnter new data\n";
			hline();
			cout<<"\nCustomer Number : ";
			cin>>bno;
			cout<<"Customer's First Name : ";
			cin>>bname;
			cout<<"Customer Address : ";
			cin>>address;
			}
		void update()
			{
			int com;
			char n[20],ad[30];
			cout<<"Enter customer number(0 for same) : ";
			cin>>com;
			if(com!=0)
				bno=com;
			cout<<"Enter customer name(0 for same) : ";
			cin>>n;
			if(n!=0)
				strcpy(bname,n);
			cout<<"Enter customer's address(0 for same) :";
			cin>>ad;
			if(ad!=0)
				strcpy(address,ad);
			}
		void view()
			{
			cout<<"\t"<<bno<<"\t"<<bname<<"\t"<<address<<"\t\n";
			hline();
			}
		int cno()
			{
			return bno;
			}
		void billview()
			{
			cout<<"\nPurchaser's name : "<<bname<<"   Address : "<<address;
			}
		}b;
void delay(int a)
{
	int add;
	int time=a*400000000;
	for(int i=0;i<time;i++)
	{
		add*=i;
		add++;
		add++;
	}
}
void shop()
	{
	char ch='n';
	float disc=0,pe=0,p=0,ma=0,wc=0,pc=0,e=0,s=0;
	int alpha,beta;
	mark4:
	do
	{
	system("CLS");
	cout<<"********************************************************************************\n";
	cout<<setw(50)<<"SHOPPING MENU ";
	cout<<"\n********************************************************************************\n";
	cout<<"\t\tITEM NO\t\tITEM\t\t\tPRICE\n";
	hline();
	cout<<"\t\t1\t\tPENCIL(per pkt)\t\t50 Rs\n"
	    <<"\t\t2\t\tERASERS(per pkt)\t50 Rs\n"
	    <<"\t\t3\t\tSHARPENER(per pkt)\t50 Rs\n"
	    <<"\t\t4\t\tPENCIL COLOR(per pkt)\t100 Rs\n"
	    <<"\t\t5\t\tWATER COLOR(per pkt)\t75 Rs\n"
	    <<"\t\t6\t\tPEN(per pcs)\t\t10 Rs\n"
	    <<"\t\t7\t\tMARKER(per pcs)\t\t20 Rs\n";
	cout<<"\n\n\tEnter what do you want to buy (1-7) : ";
	cin>>alpha;
	if(alpha>7||alpha<1)
		{
		cout<<"\t\tSorry such option does not exist.\n\t\tEnter again\n";
	    delay(1);
		goto mark4;
		}
	cout<<"\n\t\t\tHow many : ";
	cin>>beta;
	switch(alpha)
		{
		case 1:
			pe+=beta;
			break;
		case 2:
			e+=beta;
			break;
		case 3:
			s+=beta;
			break;
		case 4:
			pc+=beta;
			break;
		case 5:
			wc+=beta;
			break;
		case 6:
			p+=beta;
			break;
		case 7:
			ma+=beta;
			break;
		}
		cout<<"\n\tDo you want to purchase more (Y/N) : ";
		cin>>ch;
		if(toupper(ch)=='N')
			{
			cout<<"\n\tEnter discount offered in % (0 for null) : ";
			cin>>disc;
			}
	}while(toupper(ch)=='Y');
	int pec,ec,sc,pcc,wcc,pb,mac;
	pec=(50*pe)-((50*pe)*(disc/100));
	ec=(50*e)-((50*e)*(disc/100));
	sc=(50*s)-((50*s)*(disc/100));
	pcc=(100*pc)-((100*pc)*(disc/100));
	wcc=(75*wc)-((75*wc)*(disc/100));
	pb=(10*p)-((10*p)*(disc/100));
	mac=(20*ma)-((20*ma)*(disc/100));
	//billing starts here
	system("CLS");
	cout<<"********************************************************************************";
	cout<<"\n\t\t\t\t\tBILL\n********************************************************************************\n";
	cout<<"\nITEM NO\tITEM\t\tCOST\tITEM PURCHASED\tTOTAL COST\n";
	hline();
	if(pe!=0)
	   cout<<"1\tPENCIL\t\t50 Rs\t\t"<<pe<<"\t"<<50*pe<<" Rs\n";
	if(e!=0)
	   cout<<"2\tERASER\t\t50 Rs\t\t"<<e<<"\t"<<50*e<<" Rs\n";
	if(s!=0)
	   cout<<"3\tSHARPENER\t50 Rs\t\t"<<s<<"\t"<<50*s<<" Rs\n";
	if(pc!=0)
	    cout<<"4\tPENCIL COLOR\t100 Rs\t\t"<<pc<<"\t"<<100*pc<<" Rs\n";
	if(wc!=0)
	    cout<<"5\tWATER COLOR\t75 Rs\t\t"<<wc<<"\t"<<75*wc<<" Rs\n";
	if(p!=0)
	    cout<<"6\tPEN\t\t10 Rs\t\t"<<p<<"\t"<<10*p<<" Rs\n";
	if(ma!=0)
	    cout<<"7\tMARKER\t\t20 Rs\t\t"<<ma<<"\t"<<20*ma<<" Rs\n";
	hline();
	cout<<"\tDISCOUNT OFFERED : "<<disc<<" %\t\tGRAND TOTAL : "<<pec+ec+sc+pcc+wcc+pb+mac<<"\n";
	}
void save()
	{
	system("CLS");
	char ch;
	fstream f;
	b.input();
	f.open("CUSTINFO.dat",ios::app|ios::binary);
	cout<<"\n\n\nAre you sure to save this record (Y/N) : ";
	cin>>ch;
	if(toupper(ch)=='Y')
		f.write((char*)&b,sizeof(b));
	else
		{
		cout<<"Please enter the record again";
		delay(1);
		save();
		}
	cout<<"\n\n\n\t\t\t\nPress any key to continue.............";
	getch();
	f.close();
	wel();
	}

void disp()
	{
	system("CLS");
	fstream f;
	cout<<setw(54)<<"RECORDS DISPLAY\n";
	hline();

	cout<<"\n\n\n\tNumber\tName\t\tAddress\t\n";
	hline();
	f.open("CUSTINFO.dat",ios::in);
	while(f.read((char*)&b,sizeof(b)))
		{
		b.view();
		}
	f.close();
	cout<<"Press any key to continue.............";
	getch();
	wel();
	}

void search(int no)
	{
	system("CLS");
	int flag=0;
	ifstream f("CUSTINFO.dat",ios::in);
	cout<<setw(57)<<"CUSTOMER SEARCHING MENU \n";
	hline();

	while(f.read((char*)&b,sizeof(b)))
		{
		if(no==b.cno())
			{
			hline();
			cout<<"\n\n\tNumber\tName\t\tAddress\t\n";
			hline();
			b.view();
			flag=1;
			}
		 }
	if(flag==0)
		{
			cout<<"\nRECORD NOT FOUND!!!!";
			delay(5000);
		}
	f.close();
	cout<<"Press any key to continue.............\n";
	getch();
	wel();
	}
void sh()
	{
	int no,found=0;
	ifstream f("CUSTINFO.dat",ios::in);
	cout<<"\n\t\t\tEnter customer number of shopper\n\t\t\t(If customer's information is not saved press 0) : ";
	cin>>no;
	if(no==0)
		{
		cout<<"\n\t\t\tSave the customer's record first ";
	    delay(1);
		save();
		}
	else
	{
	while(!f.eof())
		{
		f.read((char*)&b,sizeof(b));
		if(no==b.cno())
			{
			shop();
			hline();
			b.billview();
			cout<<"\n\nThanks for shopping. Please pay the bill at counter \n\n";
			found=1;
			cout<<"Press any key to continue .............";
			getch();
			wel();
			break;
			}
		}
	 if(found==0)
		{
		cout<<"\nRECORD NOT FOUND!!!!";
		delay(1);
        sh();
		}
	f.close();
	}
	}
void upd()
	{
	system("CLS");
	int n,found=0;
	cout<<"\n Enter customer's number whose data you want to modify : ";
	cin>>n;
	fstream f;
	f.open("CUSTINFO.dat",ios::in|ios::out);
	while(!f.eof())
		{
		f.read((char*)&b,sizeof(b));
		if(b.cno()==n)
			{
			hline();
			cout<<"\n\n\tNumber\tName\t\tAddress\t\n";
			hline();
			b.view();
			hline();
			b.update();
			int pos
			pos=(-1*)sizeof(b);
			f.seekp(pos,ios::cur);
			f.write((char*)&b,sizeof(b));
			cout<<"\n\n\n\t\t\tRecord Updated.";
			found=1;
			break;
			}
		}
	f.close();
	if(found==0)
		cout<<"\n\n\n\t\t\tRecord not found !!! ";

	cout<<"\nPress any key to continue.............";
	getch();
	wel();
	}
void del()
	{
	int no;
	char found='n',sure='n';
	system("CLS");
	ifstream fin("CUSTINFO.dat",ios::in);
	ofstream fout("temp.dat",ios::out);
	cout<<setw(48)<<"DELETION MENU\n";
	hline();
	cout<<"\n\n\n\n\nEnter customer's number whoose record is to be deleted : ";
	cin>>no;
	while(fin.read((char*)&b,sizeof(b)))
		{
		if(b.cno()==no)
			{
			found='y';
			cout<<"\nAre you sure to delete this record (y/n) : ";
			cin>>sure;
			if(tolower(sure)=='n')
				fout.write((char*)&b,sizeof(b));
			}
		else
			fout.write((char*)&b,sizeof(b));
		}
		if(found=='n')
			cout<<"\n\n\t\t\tRecord not found!!\n";
		else
			cout<<"\n\n\t\t\t\tRecord deleted\n";
	fin.close();
	fout.close();
	remove("CUSTINFO.dat");
	rename("temp.dat","CUSTINFO.dat");
	cout<<"Press any key to continue ...........";
	getch();
	wel();
	}
int main();
void wel()
	{
	int a,b,con,no;
	marka:
	system("CLS");
	cout<<"********************************************************************************\n"<<setw(53)<<"WELCOME TO THE SHOP\n"<<"********************************************************************************\n";
	cout<<setw(45)<<"MENU\n";
	hline();
	cout<<"\n";
	cout<<"\t\t\t1.SHOP\n\n\t\t\t2.EDIT RECORDS\n\n\t\t\t3.SHOW ALL RECORDS\n\n\t\t\t4.LOGOUT\n\n\t\t\t5.EXIT\n\n";
	cout<<setw(55)<<"Enter what you wanna do (1-5): ";
	cin>>con;
	switch(con)
	{
	case 1:
		sh();
		break;
	case 2:
	system("CLS");
	cout<<"\n\n\n"<<setw(49)<<"ENTER WHAT TO DO\n";
	cout<<"********************************************************************************\n";
	cout<<"\n\n\n\t\t1.CREATE NEW RECORD\n\n\t\t2.UPDATE CUSTOMER'S INFORMATION\n\n\t\t3.SEARCH ANY CUSTOMER'S INFORMATION\n\n\t\t4.DELETE A RECORD\n\n\t\t5.BACK TO PREVIOUS MENU\n\n\n\t\tPLEASE SELECT FROM 1 TO 5 : ";
	cin>>b;
	switch(b)
		{
		case 1:
			save();
			break;
		case 2:
			upd();
			break;
		case 3:
			cout<<"\n\n\n\nEnter customer's number whose record you want to search : ";
			cin>>no;
			search(no);
			break;
		case 4:
			del();
			break;
		case 5:
			goto marka;
		default:
			cout<<"\n\nOPTION CHOOSEN DOESN'T MATCHES WITH GIVEN ONES\n";
			delay(1000);
			cout<<"PLEASE ENTER AGAIN";
			delay(1000);
			goto marka;
		}
	case 3:
		disp();
		break;
	case 5:
		exit(0);
		break;
	case 4:
		main();
		exit(0);
	default:
		cout<<"\n\n\t\tOption choosen doesn't matches with give ones\n\n ";
	    delay(1);
		cout<<"\t\t\tPlease enter Again ";
	    delay(1);
		goto marka;

	}
	}
int main()
	{
	int f=0;
	char pass[9];
    system("CLS");
	pas:
	system("CLS");
	cout<<"\n################################################################################\n";
	cout<<setw(60)<<"WELCOME TO THE SHOP'S SERVER\n";
	hline();
	cout<<"\n\n\n\tSIR PLEASE ENTER YOUR PASSWORD (PRESS SPACE-BAR TO EXIT) : ";
	pass[0]=getch();
	if(pass[0]==' ')
		{
		cout<<"\n\n\n\t\t\t\tTHANK YOU\n\n\t\t\t\tBYE BYE ";
		delay(1);
		exit(0);
		}
	else
	{
	cout<<"*";
	pass[1]=getch();
	cout<<"*";
	pass[2]=getch();
	cout<<"*";
	pass[3]=getch();
	cout<<"*";
	pass[4]=getch();
	cout<<"*";
	pass[5]='\0';
	if(strcmp(pass,"ronit")==0)
	{
	cout<<"\n\n\t\t\tWelcome Sir";
	delay(1);
	wel();
	}
	else
	{
	cout<<"\n\n\t\t\tTHE PASSWORD IS WRONG !";
	 f+=1;
	 cout<<"\n\n\t\t\tCHANCE REMAINING : "<<3-f;
	 delay(1);
	 if(f>=3)
	 {
	 cout<<"\n\n\n\t\t\tBYE-BYE";
	 delay(1);
	 exit(0);
	 }
	 else
		{
		cout<<"\n\n\t\tPLEASE ENTER THE PASSWORD AGAIN ";
		delay(1);
		goto pas;
		}
	 }
      }
      }
