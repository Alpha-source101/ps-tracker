#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void addexpense(){
		ofstream out("Expenses.txt",ios::app);
	string item,c,d;double p;
	    if (!out.is_open()) 
		{
		 cout << "Error opening file\n";
		  return;
		}
		cout<<"What did you buy : "<<endl;
		cin.ignore();
		getline(cin,item);
		cout<<"From which catagory it Belong (Food,Cloth,Transport etc) : "<<endl;
		cin.ignore();
		getline(cin,c);
		cout<<"How much its cost : "<<endl;
		cin>>p;
		cout<<"Enter Date of Buy (DD/MM/YYYY Format) : "<<endl;
		cin.ignore();
		getline(cin,d);
			out << item << " " << c << " " << p << " " << d << endl;
}

void showexpense(){
	string item,c,d;double p;
		ifstream in("Expenses.txt");
    	if (!in.is_open()) 
		{ 
		cout << "No expenses yet\n"; 
		return; 
		}
	while(in>>item>>c>>p>>d){
		cout << item << "   ,   " << c << "   ,   " << p << "   ,   " <<d<< endl;
	}
}

void totalexpense(){
	string item,c,d; double p; double total =0;
		double ex=50000;
	ifstream in("Expenses.txt");
	while(in >> item >> c >> p >> d){
		total += p;
	}
	cout<<endl<<"Total Expense till now : "<<total<<endl;
	in.close(); 
    in.open("Expenses.txt");
	if(total>ex){
			cout<<"					Allert!	Expense Limit 50000 Breakable  "<<endl<<endl;
			cout<<"			No Limit to add more expense now ? your giving limit is completed ";
			cout<<endl<<" 		you must delete your one high expense !"<<endl<<endl;
	
}
}

void Graph(){
	string item,c,d; double p; double t = 0;
		double per=0;
	ifstream in("Expenses.txt");
		while(in >> item >> c >> p >> d){
		t += p;
	}
	double total = t;
	in.close(); 
    in.open("Expenses.txt");
	while(in >> item >> c >> p >> d){
		per = (p/total)*100;
		cout<<endl<<item<<" :           ";
		for(int i=0.100;i<per;i++){
		cout<<"*";
	    }
		cout<<" ("<<per<<"%"<<")"<<endl;
		}
	cout<<endl;
}


void highest(){
	string item,c,d; double p;
	double max=0;
	ifstream in("Expenses.txt");
	while(in >> item >> c >> p >>d){
		if (p>max) max=p;
	}
	cout<<"\n Highest Expense till now is :  "<<max<<endl;
}


void lowest(){
	string item,c,d; double p;
	double min=50000;
	ifstream in("Expenses.txt");
	while(in >> item >> c >> p >>d){
		if (p<min) min=p;
	}
	cout<<"\n Lowest Expense till now is :  "<<min<<endl;
}


int main(){
	string itemname;
	string catagory;
	double price;
	string date;
	int choice;


	do{
		cout<<"                     -------------------          MAIN MENU          -------------------                   "<<endl;
		cout<<" 1- Add New Expense "<<endl;
		cout<<" 2- Show All Expense "<<endl;
		cout<<" 3- Veiw Total Expense "<<endl;
		cout<<" 4- Veiw Highest Expense "<<endl;
		cout<<" 5- Veiw Lowest Expense "<<endl;
		cout<<" 6- Graph Overview "<<endl;
		cout<<" 7- Exit"<<endl;
		cout<<endl<<"Enter Your Choice : ";
		cin>>choice;

	switch(choice){
		case 1:
			{
				addexpense();
				break;
			}
		case 2:
			{
				showexpense();
				break;
			}
		case 3:
			{
				totalexpense();
				break;
			}
		case 4:{
			highest();
			break;
		}
		case 5:{
			lowest();
			break;
		}
		case 6:{
			Graph();
			break;
		}
		case 7:{
			cout<<" Program Exited sucessfully ....."<<endl;
			break;
		}
			default:
				cout<<" Invalid Choice ... "<<endl;
				break;
		}
		}  
	while(choice!=7);
	
	return 0;
}