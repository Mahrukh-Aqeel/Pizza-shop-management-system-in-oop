#include<iostream>
using namespace std;

/////////////////////////////////SP22-BSSE-0031 SHEZA RAFIQ/////////////////////////////////////////////

/////////////////////////////////SP22-BSSE-0025 MAHRUKH AQEEL /////////////////////////////////////////////

float total_price=0;
float large_pizza=1000 ;
  float regular_pizza=500 ;
  float small_pizza=250 ;
  float chicken_burger=300 ;
  float  beef_burger=250 ;
  float  soft_drink=50;

void working();

menu(){
	cout<<"\t\t\t\t>>>>>>>>>>WELCOME TO MENU<<<<<<<<<<"<<endl<<endl;;
	cout<<"\t\t\t\t--------------------------------------------"<<endl;
	
	cout<<"\t\t\t\tPress 1 for large pizza 1000"<<endl;
	cout<<"\t\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t\tPress 2 for regular pizza 500"<<endl;
	cout<<"\t\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t\tPress 3 for small pizza 250 "<<endl;
	cout<<"\t\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t\tPress 4 for chicken burger 300 "<<endl;
	cout<<"\t\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t\tpress 5 for beef burger 250"<<endl;
	cout<<"\t\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t\tPress 6 for soft drinks 50"<<endl;
	cout<<"\t\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t\tPress 0 to exit the program"<<endl;
	cout<<"\t\t\t\t--------------------------------------------"<<endl;
	
}

class customer_order{
	protected:
		
		string order_id;
		string name;
		float bill;
		string review;
	
	public:
		static int customer_count;
		
		void ID_gen(){
			order_id="ord_"+(to_string(customer_count));
		}
		
		void display(){
			cout<<"\t\t\t\t--------------------------------------------"<<endl<<endl<<endl;
			cout<<"\n\t\t\t\tThe order_ID of customer is "<<order_id<<endl;
			cout<<"\t\t\t\t--------------------------------------------"<<endl;
			cout<<"\t\t\t\tThe name of the customer is "<<name<<endl;
			cout<<"\t\t\t\t--------------------------------------------"<<endl;
			cout<<"\t\t\t\tThe total bill of the customer is "<<bill<<endl<<endl;
			cout<<"\t\t\t\t--------------------------------------------"<<endl<<endl<<endl<<endl;
		}
		
		void place_order(){
			customer_count++;
			ID_gen();
			cout<<"\t\t\t\tEnter customer name "<<endl;
			cin>> name;
			cout<<endl;
			menu();
			int a;
			while(true){
				if(4==5){
					here:
						break;
				}
				
				cin>> a;
				
				switch(a){
					case 1:{
						bill+=large_pizza;
						break;
					}
					
					case 2:{
						bill+=regular_pizza;
						break;
					}
					
					case 3:{
						bill+=small_pizza;
						break;
					}
					
					case 4:{
						bill+=chicken_burger;
						break;
					}
					
					case 5:{
						bill+=beef_burger;
						break;
					}
					
					case 6:{
						bill+=soft_drink;
						break;
					}
					
					case 0:{
						goto here;
						break;
					}
					
					default:{
						cout<<"\t\t\t\tInvalid Input !!!\nPlease try again..."<<endl;
						break;
					}
				}
			}
			
			display();
		}
		
		friend void display_all();
		friend void cancelling();
		
}
obj[100];

void display_all(){
	for (int i=0; i<customer_order::customer_count; i++){
		obj[i].display();
	}
}

void cancelling(){
	string str;
	cout<<"\t\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t\tEnter the id of customer whose order needs to be cancel"<<endl;
	cout<<"\t\t\t\t--------------------------------------------"<<endl;
	cin>>str;
	
	int i;
	for(i=0; i<customer_order::customer_count; i++){
		if(str==obj[i].order_id){
			cout<<"\t\t\t\t--------------------------------------------"<<endl;
			cout<<"\t\t\t\tThe order you want to cancel is"<<endl;
		    cout<<"\t\t\t\t--------------------------------------------"<<endl;
			obj[i].display();
			cout<<"\t\t\t\tPress 1 for cancelling and 0 for not"<<endl;
			cin>>str;
			if(str=="1"){
				for(int j=i; j<customer_order::customer_count; j++){
					obj[j]=obj[j+1];
				}
				break;
			}
			else if(str=="0"){
				break;
			}
		}
		else if(i==(customer_order::customer_count-1)){
			cout<<"\t\t\t\tInvalid order ID"<<endl;
			cout<<"\t\t\t\t--------------------------------------------"<<endl;
		}
	}
}

int customer_order::customer_count=0;

void customer_managment(){
	while(true){
		cout<<"\t\t\t\t--------------------------------------------"<<endl;
		cout<<"\t\t\t\tPress 1 for placing the order"<<endl;
		cout<<"\t\t\t\t--------------------------------------------"<<endl;
		cout<<"\t\t\t\tPress 2 for displaying all placed orders"<<endl;
		cout<<"\t\t\t\t--------------------------------------------"<<endl;
		cout<<"\t\t\t\tPress 3 for cancelling an order"<<endl;
		cout<<"\t\t\t\t--------------------------------------------"<<endl;
		cout<<"\t\t\t\tPress 4 for goinh back to previous page"<<endl;
		cout<<"\t\t\t\t--------------------------------------------"<<endl;
		int choice;
		cin>>choice;
	
	
		switch(choice){
			case 1:{
				obj[customer_order::customer_count].place_order();
				break;
			}
			
			case 2:{
				display_all();
				break;
			}
			
			case 3:{
				cancelling();
				break;
			}
			
			case 4:{
				working();
				break;
			}
		}
	}
	
}
//////////////////////// abstract class //////////////////////

class person{
	
	//// protected ta k directly access na hoon aur inherit bhi ho jaeen ////
	
	protected:
		string name;
		int age;
		string address;
		
	//// pure virtual functions ////
	
	public:
		virtual void display()=0;
		virtual void setdata()=0;
};

/////////////////////// inheritance time ////////////////////


class employee : public person{
	protected:
		string emp_id="emp_";
		string designation;
		//int basic_salary;
		
		int net_salary;
		string experience;
		//int bonuses;
	
	public:
		
		//// static variable for employees counting and looping purpose ////
		static int employee_count;
		
		void setdata(){
			employee_count++;
			
			cout<<"\t\t\t\tenter id "<<endl;
			cin>>emp_id;
			cout<<"\t\t\t\tEnter name "<<endl;
			cin>>name;
			
			cout<<"\t\t\t\tEnter age "<<endl;
			cin>>age;
			
			cout<<"\t\t\t\tEnter address"<<endl;
			cin>>address;
			
			cout<<"\t\t\t\tEnter designation"<<endl;
			cin>>designation;
			
			cout<<"\t\t\t\tEnter experience"<<endl;
			cin>>experience;
			
			//cout<<"Enter basic salary"<<endl;
			//cin>>basic_salary;
		}
		/// calculate salary function and add bonus 
		void salarycalc(){
			int a;
			int b;
			int c;
			cout<<"\t\t\t\t--------------------------------------------"<<endl;
			cout<<"\t\t\t\tEnter any bonus to be awarded to employee "<<endl;
			cin>>b;
			cout<<"\t\t\t\t--------------------------------------------"<<endl;
			cout<<"\t\t\t\tEnter basic salary"<<endl<<endl;
			cin>>c;
			a=c+b;
			cout<<"\t\t\t\t--------------------------------------------"<<endl;
			//net_salary=gross_salary-(gross_salary*0.08);
			cout<<"\t\t\t\tThe after bonus salary "<<a<<endl;
			cout<<"\t\t\t\t--------------------------------------------"<<endl<<endl<<endl;
		}
		////display all information of emp
		void display(){
			cout<<"\t\t\t\tThe ID of the employee is "<<emp_id<<endl;
			cout<<"\t\t\t\t--------------------------------------------"<<endl;
			cout<<"\t\t\t\tThe name of the employee is "<<name<<endl;
			cout<<"\t\t\t\t--------------------------------------------"<<endl;
			cout<<"\t\t\t\tThe age of the employee is "<<age<<endl;
			cout<<"\t\t\t\t--------------------------------------------"<<endl;
			cout<<"\t\t\t\tThe adress of the employee is "<<address<<endl;
			cout<<"\t\t\t\t--------------------------------------------"<<endl;
			cout<<"\t\t\t\tThe designation of the employee is "<<designation<<endl;
			cout<<"\t\t\t\t--------------------------------------------"<<endl;
			cout<<"\t\t\t\tThe experience of the employee is "<<experience<<endl;
			cout<<"\t\t\t\t--------------------------------------------"<<endl<<endl<<endl<<endl;
			//cout<<"The basic salary of the employee is "<<c<<endl;
		
		}
		/////////use  friend function
		friend void e_search();
		friend void e_del();
};
//emp arr
employee e1[100];
int employee::employee_count=0;

void e_search(){
	string name1;
	cout<<"\t\t\t\tEnter the name of employee you want to search ";
	cin>>name1;
	
	for (int i=0; i<employee::employee_count; i++){
		if (name1==e1[i].name){
			e1[i].display();
		}
	}
}
void e_del(){
	string de;
	cout<<"\t\t\t\tEnter an ID of employee that you want to delete";
	cin>>de;
	
	for(int i=0; i<employee::employee_count; i++){
		if(de==e1[i].emp_id){
			for(int j=i; j<employee::employee_count; j++){
				e1[j]=e1[j+1];
			}
			employee::employee_count--;
		}
	}
}

void employee_info(){
	
	cout<<"\t\t\t\t>>>>>>>>>>welcome to employee managment system<<<<<<<<<<"<<endl<<endl;;
	cout<<"\t\t\t\t--------------------------------------------"<<endl;

	while(true){
		
		cout<<"\t\t\t\tPress 1 to add data of employee"<<endl;
		cout<<"\t\t\t\t--------------------------------------------"<<endl;
		cout<<"\t\t\t\tPress 2 to show data of employee"<<endl;
		cout<<"\t\t\t\t--------------------------------------------"<<endl;
		cout<<"\t\t\t\tPress 3 to search data of employee"<<endl;
		cout<<"\t\t\t\t--------------------------------------------"<<endl;
//		cout<<"\t\t\t\tPress 4 to delete data of employee"<<endl;
//		cout<<"\t\t\t\t--------------------------------------------"<<endl;
		cout<<"\t\t\t\tpress 4 to exist"<<endl;
		cout<<"\t\t\t\t--------------------------------------------"<<endl<<endl<<endl<<endl;
		cout<<"\t\t\t\t"; int ee; cin>>ee;
		
		switch(ee){
			case 1 :{
				e1[employee::employee_count].setdata();
				e1[employee::employee_count].salarycalc();
				break;
				
			}
			
			case 2:{
				for (int i=0; i<employee::employee_count; i++){
					e1[i].display();
				}
				break;
			}
			
			case 3:{
				e_search();
				break;
			}
			
//			case 4:{
//				e_del();
//				break;
//			}
//			
			case 4:{
			exit(0);
				break;
			}
		}
	}
}

void working(){
	cout<<"\t\t\t\t>>>>>>>>>>welcome to Broadway managment system<<<<<<<<<<"<<endl<<endl;;
	cout<<"\t\t\t\tPress 1 for customer managment"<<endl;
	cout<<"\t\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t\tPress 2 for employee managment"<<endl;
	cout<<"\t\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t\tPress 0 for exiting the program"<<endl;
	cout<<"\t\t\t\t--------------------------------------------"<<endl;
	int a;
	cin>>a;
	
	while(true){
		switch(a){
			case 1:{
				customer_managment();
				break;
			}
			
			case 2:{
		       employee_info();
				break;
			}
			
			case 3:{
				exit(0);
				break;
			}
			
			default:{
				cout<<"\t\t\t\tInvalid input !!!\nPlease try again"<<endl;;
				break;
			}
		}
	}
}

int main(){
	    cout<<endl<<endl<<endl;
		cout<<"\t\t\t\t>>>>>>>>>>OPP PROJECT <<<<<<<<<<"<<endl<<endl;;
		cout<<"\t\t\t\t>>>>>>>>>>MAHRUKH AQEEL <<<<<<<<<<"<<endl<<endl;;
	    cout<<"\t\t\t\t>>>>>>>>>>SHEZA RAFIQ <<<<<<<<<<"<<endl<<endl<<endl<<endl<<endl;;
	working();
}
