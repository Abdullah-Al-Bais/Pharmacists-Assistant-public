#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>
#include <cstring>

using namespace std;

class file                      //to create a general file
{
public:
   file(){
        ofstream fout;                  //Default class by <fstream> header
        fout.open("abdullah.txt");
        fout<<"abdullah";
        fout.close();
   }
};
class income
{                   //class to show/read from profit file
        public:
        double profit=0;
        void show()
		{
		ifstream x("Profit.txt");
        if(!x)
        cout<<"PROFIT = 0 ";
        else{
        x>>profit;
        cout<<"\nTOTAL STARTING PROFIT:  "<<profit<<endl;
        x.close();
        }
        }
};


class medicine:public virtual income
{
public:
           int quan;
           char name[20];
           char id[20];
           char exdate[10];
           double percost;
           double persell;
           double cost;
           double sell;
           void cal()
		   {
		    cost=percost*quan;
        	sell=persell*quan;
            profit=profit +(sell-cost);
			}
            void get();                               //function to take entries for Medicine
            void file();                               // function to write the medicine entries in file
};
void medicine::get()                          // call get() function from class: medicine to take entries for medicine
{
 int s;
cout<<"\nnumber of medicine arrived?\n";
cin>>s;
for(int i=0;i<s;i++)
{
  cout<<"\ninput medicine name: \n";
  cin>>name;
  cout<<"\ninput medicine id: \n";
  cin>>id;
  cout<<"\ninput cost price of medicine: \n";
  cin>>percost;
  cout<<"\ninput selling price of medicine: \n";
  cin>>persell;
  cout<<"\ntotal medicine quantity: \n";
  cin>>quan;
  cout<<"\nExpire Date: \n";
  cin>>exdate;
    cal();                                 //declare in class : medicine to calculate profit
    file();                                // declare in class : file to create a file
  }

}
void medicine::file()              // call file() function from class: medicine to write in file
{
char file[20];
strcpy(file,id);
strcat(file,".txt");
ofstream f(file);
f<< "\nmedicine name: "<<name<< "\nmedicine id: "<<id<<"\nExpire Date: "<<exdate<<"\ncost price of medicine: " <<percost<<"\nselling price of medicine: "<<persell<<"\nquantity: "<<quan<<"\n total cost: "<<cost<<"\nsell: "<<sell;
f.close();
}


class buyer                         //to declare 2 function getbuyer(), file()
{
         protected:
         char bname[20];
         char buyingdate[10];
          int phone;
         void getbuyer();
         void file();
};
void buyer::getbuyer()           //call from class: buyer to take details for buyers
{

  	cout<<"input buyer name\n";
  	cin>>bname;
  	cout<<"\ninput phone number \n";
     cin>>phone;
  cout<<"\ninput date \n";
  cin>>buyingdate;

  file();                                   //call file class to create file

}
 void buyer::file()                      // call file function to write details of buyer in file
{
    char file[20];
strcpy(file,bname);
strcat(file,".txt");
ofstream f(file);
f<< "Buyer name :"<<bname<<"\nPhone number: "<<phone<<"\nBuyer date: "<<buyingdate;
f.close();
}


class amount:public buyer, public medicine       //class to declare 3 function add(), updateitem(),entrybuyer() for Menu
{

 public:
    void add();
    void update_item();
    void entrybuyer();
};
void amount::entrybuyer()                       //declaration of entrybuyer()
{
    while(1)
{
    int f;
    cout<<"\n1.Input for buyer:\n2. Exit!"<<endl;
    cout<<"\nEnter choice :";
    cin>>f;
    if(f==1)
    getbuyer();                                  //call getbuyer() from class buyer
    else
         break;
}

    /*ofstream x("Profit.txt");
    x<<profit;
    x.close();*/
}
void amount::add()                          // declaration  of add()
{
	int ch;
	char name[20];
	while(1)
	{
		cout<<"\n1.Input for medicine\n2.Exit\n";
		cout<<"Enter choice\n";
		cin>>ch;
		if(ch==1){
				get();                                          //call get() function from class medicine
				ofstream x("Profit.txt");
 				x<<profit;
 				x.close();
			}

			else if(ch==2)
				break;
			else
				cout<<"Invaid Option. Please re-enter\n";
			}
		}
void amount::update_item()           //declaration of updateitem()
{
	char id[20];
	char pid[20];
    char c;
    cout<<"\nINPUT medicine ID to modify\n";
    cin>>id;
    char file[20];
    char file2[20];
    strcpy(file,id);
    strcat(file,".txt");
    fstream fout(file, ios::in|ios::out);             //searching for existing file for medicine
    if(!fout)
    {
    	cout<<"File couldn't be opened. medicine ID not found. \n";
	}
	else {
	cout<<"file found! \n";

    cout<<"\nupdate medicine name: \n";
  	cin>>name;
 	cout<<"\nupdate percost of medicine: \n";
  	cin>>percost;
 	cout<<"\nupdate persell of medicine: \n";
  	cin>>persell;
 	cout<<"\nupdate total medicine quantity: \n";
 	cin>>quan;
 	  cout<<"\n Update Expire Date: \n";
     cin>>exdate;

 	entrybuyer();                                             // call to entry buyer details

    cost=percost*quan;
    sell=persell*quan;
	profit=profit +(sell-cost);

  	fout<<"\nmedicine name: "<<name<< "\nmedicine id: "<<id<<"\nExpire Date :"<<exdate<<"\npercost of medicine: " <<percost<<"\npersell of medicine: "<<persell<<"\nquantity: "<<quan<<"\n total cost: "<<cost<<"\nsell: "<<sell;
	fout.close();
    ofstream x("Profit.txt");                        //update in profit file
    x<<profit;
    x.close();
}
}


void admin()            // function for Menu //all functions for menu called from here
{
  while(1)
  {
 	cout<<"\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout<<"\n\t\t\t     WELCOME TO AAB PHARMA!  \n";
	cout<<"\n\t\t\tvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n\n";
	cout<<"\n\t\t\t===========================\n";
 	cout<<"\n\t\t\t1. Add Medicine Entries\n\n\t\t\t2. Search Medicines Details\n\n\t\t\t3. Modify Medicine Details & Entry Buyers\n\n\t\t\t4. Search Buyer Details \n\n\t\t\t5. Show Profit \n\n\t\t\t6. Exit\n";
    cout<<"\n\n\t\t\tSelect your choice\n";
  int u;
  cin>>u;
if(u==1)
  {
  amount a;                 //object of class:amount which inherited buyer and medicine
  a.add();                     // call from  class:amount ,,function amount:add()
  a.show();                  //call from class:income inherited by medicine
 }
  else if(u==2)
  {
   char id[20];
   char c;
    cout<<"\nINPUT ID to search\n";
    cin>>id;
    char file[20];
    strcpy(file,id);
    strcat(file,".txt");
    ifstream x(file);
    if(!x)
    {
    	cout<<"File couldn't be opened. Medicine ID not found. \n";
	}
    while(x.get(c))
    {
                                   //copy everything from x file to c then show
       cout<<c;
    }

    x.close();
}
else if(u==3)
{
	amount u;                                  //object of class:amount which inherited buyer and medicine
	u.update_item();                        //call from class amount,, function amount:update_item
}
 else if(u==4)
 {
 	char bid[20];
   	char d;
   	cout<<"\nINPUT buyer name to search\n";
    cin>>bid;
   	char file[20];
   	strcpy(file,bid);
   	strcat(file,".txt");
   	ifstream y(file);
   	 if(!y)
    {
    	cout<<"file couldn't be opened. Buyers ID not found. \n";
	}
   	while(y.get(d))
   	{
   	cout<<d;
   }

   y.close();
 }
   else if(u==5)
  {
  amount d;
  d.show();
}
  else if(u==6)
  {
  break;
}
  else cout<<"Invalid option. Please select one of the available options\n";
 }

}

int main(){
    int ch,pass=1803032,demo;
    //char  username[20];
    //char password[20];
    //char pwd[20];
    while(1){
        cout<<"\n \t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
        cout<<"\n\t\t\tWELCOME TO PHARMACIST'S ASSISTANT!  \n";
        cout<<"\n \t\t\t&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n\n";
        cout<<"\n \t\t\t=================";
        cout<<"\n\t\t\t  1. ENTER SYSTEM";
        cout<<"\n\t\t\t  2. EXIT";
        cout<<"\n\t\t\t==================\n";
        cout<<"\n\t\t\t Enter Your Choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter Password!!:   ";
                cin>>demo;
                if(pass==demo)
                admin();                       //call function:admin
                else
                {
                    cout<<"Wrong Password!!!"<<endl;
                break;
                }
            case 2:
                exit(0);
                break;
            default:
                cout<<"Enter valid choice!\n";
                break;
        }
    }
    return 0;
}
