#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include"Header.h"
#include <windows.h>
#include<mmsystem.h>
using namespace std;

class PersonalInformation{
	private:
        string name;
        static string s_path;
        int age;
        float height,weight;
        string contact,NIC;
        string f_path2;
    protected:
        string gender;
        string level;
		string f_path;
	public:
        float BMI;
        static long int plan_price,revenue,count_customers;


	public:
		void virtual customer_details()=0;

		PersonalInformation();
		PersonalInformation(string a,int aa,string gen,float h,float w,string c,string N,string lvl,string path):name(a),age(aa),gender(gen),height(h),weight(w),contact(c),NIC(N),level(lvl),f_path(path)
		{
		    f_path=path;
		    f_path2=path;
            f_path2+="admin\\";
			f_path2+="\\Customers History.txt";
			s_path=f_path2;
		    path+="Customer\\\\";
		    ofstream out(f_path2,ios::app);
		    out<<"Name= "<<name<<endl<<"NIC= "<<NIC<<endl<<"Contact= "<<contact<<endl<<"BMI= "<<BMI<<endl<<"level= "<<level<<endl;
		    out.close();

			path+=NIC;
			path+="\\\\Data.txt";
			height=height/100;
			BMI=(weight)/(height*height);
			cout<<endl<<endl<<"Your BMI= "<<BMI;
			ofstream fout;
			fout.open(path);
			if(!fout)
			{
				cout<<endl<<"File not Found";
			}
			else{
			fout<<"Name= "<<name<<endl<<"Age= "<<age<<endl<<"Gender= "<<gender<<endl<<"Height= "<<height<<endl<<"Weight= "<<weight<<"kg"<<endl<<"BMI= "<<BMI<<endl<<"Contact= "<<contact<<endl<<"NIC= "<<NIC<<endl<<"level= "<<level<<endl;
			fout.close();

			}

		}
		void showdata()
		{
		    cout<<name<<endl<<age<<endl<<gender<<endl<<height<<endl<<weight<<endl<<"BMI= "<<BMI;
		}
		string get_level(void)
	{
		return level;
	}
	string get_path(void)
	{
		return f_path;
	}
		string get_gender(void)
	{
		return gender;
	}
	virtual void display()const{
	    system("cls");
            cout<<"\t\t\t\t\t DISPLAY "<<endl;
            cout<<endl<<"Name: "<<name;
            cout<<endl<<"NIC: "<<NIC;
            cout<<endl<<"Age: "<<age;
            cout<<endl<<"Gender: "<<gender;
            cout<<endl<<"Contact Number: "<<contact;
            cout<<endl<<"Height: "<<height;
            cout<<endl<<"Weight: "<<weight;
             cout<<endl<<"BMI: "<<BMI;

	}
	static void price(void)
	{
        ofstream of(s_path,ios::app);
        if(!of)
            {
                cout<<endl<<"File not Found";
            }
        else{


            of<<"Plan bill= Rs."<<plan_price<<endl<<endl;
            of.close();
            }
                revenue+=plan_price;
                plan_price=0;
                count_customers++;
	}


};
long int PersonalInformation::revenue=0,PersonalInformation::plan_price=0,PersonalInformation::count_customers=0;
string PersonalInformation::s_path;
class beginner:public PersonalInformation{
	private:
	string lvl,gen;

	public:
	float freeHours;
    beginner(string a,int aa,string gen,float h,float w,string c,string N,string lvl,string p):PersonalInformation(a,aa,gen,h,w,c,N,lvl,p)
	{
            this->lvl=lvl;
            this->gen=gen;
	}

	void cal_f_hours(void)
	{
		float free_mins;
		int xy;
		float potential_hrs,potential_mins;
		cout<<endl<<"Enter your free hours: ";
		cin>> freeHours;
		if(freeHours>1.25&&freeHours<=7)
		{
			potential_hrs=1;
			potential_mins=15;
			freeHours-=1.25;
			xy=freeHours;
			free_mins=(freeHours-xy)*60;
			cout<<"You have to workout for "<<potential_hrs<<" hours"<<" and "<<potential_mins<<" minutes";
			cout<<endl<<"You have "<<xy<<" hours and "<<free_mins<<" minutes leisure time after workout";

		}
		else if(freeHours>7)
		{
			potential_hrs=1;
			potential_mins=45;
			freeHours-=1.75;
			xy=freeHours;
			free_mins=(freeHours-xy)*60;
			cout<<"You have to workout for "<<potential_hrs<<" hours"<<" and "<<potential_mins<<" minutes";
			cout<<endl<<"You have "<<xy<<" hours and "<<free_mins<<" minutes leisure time after workout";

		}
		else
        {
            potential_hrs=freeHours;
            cout<<endl<<"Increase workout time!Give all your free time to workout";
            cout<<endl<<"You have to workout for "<<potential_hrs<<" hours";
        }

	}
		void virtual customer_details(){}
       void display()const
       {
       PersonalInformation::display();
       cout<<endl<<"Level: "<<lvl;
       }

};

class intermediate:public PersonalInformation{
private:
	string lvl,gen;
	public:
	float freeHours;
    intermediate(string a,int aa,string gen,float h,float w,string c,string N,string lvl,string p):PersonalInformation(a,aa,gen,h,w,c,N,lvl,p)
    {this->lvl=lvl;
     this->gen=gen;
    }


	void cal_f_hours(void)
	{
		float free_mins;
		int xy;
		float potential_hrs,potential_mins;
		cout<<endl<<"Enter your free hours: ";
		cin>> freeHours;
		if(freeHours>1.60&&freeHours<=7)
		{
			potential_hrs=1;
			potential_mins=36;
			freeHours-=1.60;
			xy=freeHours;
			free_mins=(freeHours-xy)*60;
			cout<<"You have to workout for "<<potential_hrs<<" hours"<<" and "<<potential_mins<<" minutes";
			cout<<endl<<"You have "<<xy<<" hours and "<<free_mins<<" minutes leisure time after workout";

		}
		else if(freeHours>7)
		{
			potential_hrs=2;
			potential_mins=00;
			freeHours-=2;
			xy=freeHours;
			free_mins=(freeHours-xy)*60;
			cout<<"You have to workout for "<<potential_hrs<<" hours"<<" and "<<potential_mins<<" minutes";
			cout<<endl<<"You have "<<xy<<" hours and "<<free_mins<<" minutes liesure time after workout";

		}
		else
        {
            potential_hrs=freeHours;
            cout<<endl<<"Increase workout time!Give all your free time to workout";
            cout<<endl<<"You have to workout for "<<potential_hrs<<" hours";
        }

	}
		void virtual customer_details(){}
		       void display()const
       {
       PersonalInformation::display();
       cout<<endl<<"Level: "<<level;
       }


};

class professional:public PersonalInformation{

	private:
	string lvl,gen;

	public:
	float freeHours;
    professional(string a,int aa,string gen,float h,float w,string c,string N,string lvl,string p):PersonalInformation(a,aa,gen,h,w,c,N,lvl,p)
    {this->lvl=lvl;
     this->gen=gen;
    }
	void cal_f_hours(void)
	{
		float free_mins;
		int xy;
		float potential_hrs,potential_mins;
		cout<<endl<<"Enter your free hours: ";
		cin>> freeHours;
		if(freeHours>2&&freeHours<=7)
		{
			potential_hrs=2;
			potential_mins=00;
			freeHours-=2.00;
			xy=freeHours;
			free_mins=(freeHours-xy)*60;
			cout<<"You have to workout for "<<potential_hrs<<" hours"<<" and "<<potential_mins<<" minutes";
			cout<<endl<<"You have "<<xy<<" hours and "<<free_mins<<" minutes leisure time after workout";

		}
		else if(freeHours>6)
		{
			potential_hrs=2;
			potential_mins=30;
			freeHours-=2;
			xy=freeHours;
			free_mins=(freeHours-xy)*60;
			cout<<"You have to workout for "<<potential_hrs<<" hours"<<" and "<<potential_mins<<" minutes";
			cout<<endl<<"You have "<<xy<<" hours and "<<free_mins<<" minutes liesure time after workout";

		}
		else
        {
            potential_hrs=freeHours;
            cout<<endl<<"Increase workout time!Give all your free time to workout";
            cout<<endl<<"You have to workout for "<<potential_hrs<<" hours";
        }

	}
		void virtual customer_details(){}

        void display()const
       {
       PersonalInformation::display();
       cout<<endl<<"Level: "<<lvl;
       }

};
int main()
{

	string name;
	string h_path=path_finder();
	int age,gen,lvl,choice;
    string gender,level;
	float height,weight;
	string contact,NIC;
                cout<<"\t\t\t\tThe Three Amigos Fitness Program"<<endl<<endl;
                cout<<endl<<"Enter your NIC number: ";
				cin>>NIC;
				choice=folder_check(NIC);
				if(choice==1)
                {

				cout<<endl<<"Enter your Name: ";
				fflush(stdin);
				getline(cin,name);
				cout<<endl<<"Enter your Age: ";
				cin>>age;
				cout<<endl<<"Enter your Gender: ";
				gender=c_gen();
                cout<<endl<<"Enter your Weight in Kgs: ";
                cin>>weight;
                cout<<endl<<"Enter your Height in cm: ";
                cin>>height;
                cout<<endl<<"Enter your Contact number: ";
                cin>>contact;

                }
            else if(choice==0)
                {
                    name=string_finder(NIC,"Name","end");
                    gender=string_finder(NIC,"Gender","end");
                    string new_weight=string_finder(NIC,"Weight","end");
                    cout<<endl<<endl<<"Your Previous Weight= "<<new_weight;
                    cout<<endl<<"Enter your new Weight in Kgs: ";
                    cin>>weight;
                    cout<<endl<<"Enter your new Height in cm: ";
                    cin>>height;
                    cout<<endl<<"Enter your Contact Number: ";
                    cin>>contact;
                    cout<<endl<<"Enter your Age: ";
                    cin>>age;

                }

				cout<<endl<<"Enter your Level: "<<endl;
				cout<<endl<<"Select from the choices below ";
                level=c_level();



if(level=="beginner"){
       system("cls");
	beginner object(name,age,gender,height,weight,contact,NIC,level,h_path);
	int choice_plan;
	choice_plan=c_menu(level,gender,NIC);
	 if(choice_plan==1){
             console_sleep();
            mutual_diet(object);

		 system("cls");
            PersonalInformation::plan_price+=8000;
            PersonalInformation::price();

        }
        else if(choice_plan==2){
                console_sleep();
        mutual_workout(object);
        object.cal_f_hours();
        PersonalInformation::plan_price+=8000;
        PersonalInformation::price();
        }
        else if(choice_plan==3){
            console_sleep();
            mutual_diet(object);
            mutual_workout(object);
            object.cal_f_hours();
            PersonalInformation::plan_price+=13000;
            PersonalInformation::price();
        }
        cout<<endl<<endl<<"Press Any Key To Get Display........... ";
        getch();
        object.display();

}

else if(level=="intermediate")
{
	system("cls");
	intermediate object(name,age,gender,height,weight,contact,NIC,level,h_path);
	int choice_plan;
	choice_plan=c_menu(level,gender,NIC);
	 if(choice_plan==1){
            console_sleep();
           mutual_diet(object);
            PersonalInformation::plan_price+=12000;
            PersonalInformation::price();
        }
        else if(choice_plan==2){
            console_sleep();
       mutual_workout(object);
       object.cal_f_hours();
        PersonalInformation::plan_price+=12000;
        PersonalInformation::price();
        }
        else if(choice_plan==3){
            console_sleep();
           mutual_diet(object);
           mutual_workout(object);
           object.cal_f_hours();
            PersonalInformation::plan_price+=18000;
            PersonalInformation::price();
        }
        cout<<endl<<endl<<"Press Any Key To Get Display........... ";
        getch();
            object.display();
}

else {
	system("cls");
    professional object(name,age,gender,height,weight,contact,NIC,level,h_path);
	int choice_plan;
	choice_plan=c_menu(level,gender,NIC);
	 if(choice_plan==1){
            console_sleep();
         mutual_diet(object);
            PersonalInformation::plan_price+=15000;
            PersonalInformation::price();
        }
        else if(choice_plan==2){
            console_sleep();
        mutual_workout(object);
        object.cal_f_hours();
        PersonalInformation::plan_price+=15000;
        PersonalInformation::price();
        }
        else if(choice_plan==3){
            console_sleep();
            mutual_diet(object);
            mutual_workout(object);
            object.cal_f_hours();
            PersonalInformation::plan_price+=24000;
            PersonalInformation::price();
        }
        cout<<endl<<endl<<"Press Any Key To Get Display........... ";
        getch();
        object.display();
}
	int y;
	cout<<endl<<endl<<"Do you want to end program?"<<endl<<"1-yes "<<endl<<"2-No ";
	cin>>y;
	switch(y)
	{
		case 1:
		    {
		        //int item,rev;
		        string ab;
		        ab=string_finder(NIC,"Plans","end");
                int item=stoi(ab);;
		        ab=string_finder(NIC,"Revenue","end");
		        int rev=stoi(ab);
		        item+=PersonalInformation::count_customers;
		        rev+=PersonalInformation::revenue;
		        string str2=path_finder();
		        str2+="admin\\\\Revenue.txt";
                ofstream out(str2);
                out<<"Total Plans Sold= "<<item<<endl<<"Revenue= "<<rev;
                out.close();
                break;
		    }
        case 2:
            {
                system("cls");
                main();
                break;
            }

    return 0;
    }
}
//    //ShellExecute(NULL,"open","received_1763125183762574.jpeg", NULL, NULL, SW_SHOWNORMAL);




