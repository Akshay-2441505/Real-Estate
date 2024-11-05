#include<iostream>
using namespace std;
struct item{
	string p_name, p_loc, p_type;
	long int p_value, p_dimension;
};
class real_estate{
	public:
	real_estate()
	{
	cout<<"\t\t\t\t\t\t|Real estate domain|"<<endl;
	cout<<"Choose from the below options to perform operations of your choice"<<endl;
    }
};
class properties{
	public:
		item list[16]={
		{"Columbia Groups", "Electronic City", "Apartments", 8000000, 1200},
		{"Sobha Pristine", "Jakkuru", "Apartments", 30000000, 2500},
		{"Prestige Meridian Park", "Sarjapura", "Apartments", 8000000, 1800},
		{"Mahindra Eden", "Kanakpura Road", "Apartments", 7500000, 1500},
		{"Casagrand Properties", "Chikkanagamangala", "Villas", 20000000, 2000},
		{"Embassy Boulevard", "Yelahanka", "Villas", 25000000, 2000},
		{"Prestige Golfshire", "Devanahalli", "Villas", 18000000, 1200},
		{"Raffles Park", "Whitefield", "Villas", 30000000, 2500},
		{"Mana Tropicale", "Sarjapura", "Duplex", 6000000, 1200},
		{"Shriram Signiaa", "Electronic City", "Duplex", 40000000, 2000},
		{"Sobha Galera", "Hoskote", "Duplex", 26000000, 3000},
		{"Daddys Daaliya", "Hebbagodi", "Duplex", 12500000, 2500},
		{"Umiya Suntech", "Whitefield", "Commercial", 55000000, 5000},
		{"Shivaji Nagar Office Space", "Shivajinagar", "Commercial", 37500000, 1275},
		{"Kormangala Office Space", "Kormangala", "Commercial", 35000000, 2000},
		{"Bedarahalli Office Space", "Bedarahalli", "Commercial", 25000000, 4500}	
		};
		int listsize=16;
	void listing()
	{
        cout << "Listing all properties:" << endl;
        for (int i = 0; i < listsize; i++)
		{
            cout<<"-"<<list[i].p_name<<",Location:"<<list[i].p_loc<<",Type:"<<list[i].p_type<<",Price:"<<list[i].p_value<<",Dimension:"<<list[i].p_dimension<<"sqft"<<endl;
        }
    }
    int getlistsize() {
        return listsize;
    }

    item* getlist() {
        return list;
    }
};
class in_budget : public virtual properties{
	public:
		long int budget;
		int listsize;
		void condition()
		{
			cout<<"Enter the budget of the buyer:";
			cin>>budget;
			int count=0;
			cout<<"The budget of the buyer is:"<<budget<<endl;
			cout<<"The properties available within are:"<<endl;
			for(int i=0;i<getlistsize();i++){
			if(getlist()[i].p_value<=budget){
				count++;
				cout<<"-"<<getlist()[i].p_name<<",Location:"<<getlist()[i].p_loc<<",Type:"<<getlist()[i].p_type<<",Price:"<<getlist()[i].p_value<<",Dimension:"<<getlist()[i].p_dimension<<"\n";
		    }
		}
		if(count==0){
		 	cout<<"No properties are available within the buyer's budget"<<endl;
		}
}
};
class property_input{
	public:
		string prop_name, prop_loc; 
		long int current_val, prop_dimension;
		void getdata()
		{
			cout<<"Enter the property name:";
			cin>>prop_name;
			cout<<"Enter the property location:";
			cin>>prop_loc;
			cout<<"Enter the on going price in that location(per SQFT):";
			cin>>current_val;
			cout<<"Enter the dimension of the property(in SQFT):";
			cin>>prop_dimension;
		}
		
};
class property_output : public virtual property_input{
	public:
		long int prop_total_value;
		void prop_cal()
		{
			prop_total_value=current_val*prop_dimension;
		}
		void display()
		{
			cout<<"Name of the property:"<<prop_name<<endl;
			cout<<"Location of the property:"<<prop_loc<<endl;
			cout<<"Dimension of the property(in SQFT):"<<prop_dimension<<endl;
			cout<<"On going price in that location(per SQFT):"<<current_val<<endl;
			cout<<"Total value of the property(current price X dimension):"<<prop_total_value<<endl;
		}		
};
class rent{
	public:
		long brv, maintenance, w_bill, e_bill;
		void getdata1()
		{
		cout<<"Enter the basic rent value:";
		cin>>brv;
		cout<<"Enter the maintenance amount:";
		cin>>maintenance;
		cout<<"Enter the water bill amount:";
	    cin>>w_bill;
		cout<<"Enter the electricity bill amount:";
		cin>>e_bill;	
		}
};
class rent_cal : public virtual rent{
	public:
		long int TRV;
		void total_rent()
		{
			TRV=brv+maintenance+w_bill+e_bill;		
		}
		void display1()
		{
			cout<<"Basic Rent Amount:"<<brv<<endl;
			cout<<"Maintenance Amount:"<<maintenance<<endl;
			cout<<"Water Bill Amount:"<<w_bill<<endl;
			cout<<"Electricity Bill Amount:"<<e_bill<<endl;
			cout<<"Total Rent Value:"<<TRV<<endl;	
		}
};
class rent_app : public virtual rent{
	public:
		long int app_total;
		void appreciation()
		{
			brv+=1000;
			maintenance+=500;
			app_total=brv+maintenance+w_bill+e_bill;
			cout<<"Total rent value after Rent appreciation:"<<app_total<<endl;
		}	
};
int main()
{
	int ch=1;
	while(ch==1)
	{
		int option;
		real_estate r;
		cout<<"1-View all properties"<<"\n"<<"2-View properties within the budget"<<"\n"<<"3-Calculate Property value"<<"\n"<<"4-Calculate Toal Rent Amount"<<"\n"<<"5-Calculate Rent Appreciation";
		cin>>option;
		switch(option)
		{
		case 1:
		{
			properties p1;
			p1.listing();
			cout<<"Enter 1 to use the program again"<<"\n"<<"Enter 0 to exit the program:";
			cin>>ch;
			break;
		}
		case 2:
		{
			in_budget p2;
			p2.condition();
		    cout<<"Enter 1 to use the program again"<<"\n"<<"Enter 0 to exit the program:";
		    cin>>ch;
		    break;
		}
		case 3:
		{
			property_output p3;
		    p3.getdata();
			p3.prop_cal();
			p3.display();	
			cout<<"Enter 1 to use the program again"<<"\n"<<"Enter 0 to exit the program:";
		    cin>>ch;
		    break;
		}
		case 4:
		{
			rent_cal r1;
			r1.getdata1();
			r1.total_rent();
			r1.display1();
			cout<<"Enter 1 to use the program again"<<"\n"<<"Enter 0 to exit the program:";
		    cin>>ch;
		    break;
		}
		case 5:
		{
			rent_app r2;
			r2.getdata1();
			r2.appreciation();
		    cout<<"Enter 1 to use the program again"<<"\n"<<"Enter 0 to exit the program:";
		    cin>>ch;
		    break;
	    }
	    default:
	    	{
	    		cout<<"Invalid Choice";
	    		ch=0;
			}
        }
cout<<"End of the program"<<endl;
    }
return 0;
}
	
