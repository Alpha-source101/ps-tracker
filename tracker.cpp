#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void addexpense(ofstream &out,string &item,string &c,double &p,string &d){
	cout<<"What did you buy : "<<endl;
	cin.ignore();
	getline(cin,item);
	cout<<"From which catagory it Belong (Food,Cloth,Transport etc) : "<<endl;
	getline(cin,c);
	cout<<"How much its cost : "<<endl;
	cin>>p;
	cout<<"Enter Date of Buy (DD/MM/YYYY Format) : "<<endl;
	cin>>d;
	out<<item<<" , "<<c<<" , "<<p<<" , "<<d<<endl;
}
void showexpense(ifstream in,string item,string c,double p,string d){
	while(getline(in, item, ',')){
		cout << item << " , " << c << " , " << p << " , " <<d<<" , "<< endl<<"|";
	}
}
int main(){
	string itemname;
	string catagory;
	double price;
	string date;
	int choice;
	ofstream out("Expenses.txt" , ios::app);
	ifstream in("Expenses.txt");
	jumphere:

	do{
		cout<<"                     -------------------          MAIN MENU          -------------------                   "<<endl;
		cout<<" 1- Add New Expense "<<endl;
		cout<<" 2- Show All Expense "<<endl;
		cout<<" 3- Veiw Total Expense "<<endl;
		cout<<" 4- Exit"<<endl;
		cout<<endl<<"Enter Your Choice : ";
		cin>>choice;
	}while(!(choice==1||choice==2||choice==3||choice==4|| (choice>=4 || choice<=0) ));{
	switch(choice){
		case 1:
			{
				addexpense(out,itemname,catagory,price,date);
				goto jumphere;
				break;
			}
		case 2:
			{
				showexpense(in,itemname,catagory,price,date);
				goto jumphere;
				break;
			}
		case 3:
			{
				goto jumphere;
				break;
			}
		case 4:{
			cout<<" Program Exited sucessfully ....."<<endl;
			break;
		}
			default:
				cout<<" Invalid Choice ... "<<endl;
	}}
//	if(out.is_open()){
//		cout<<"..File opened";
//	}
	
}