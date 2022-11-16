#include<iostream>
#include<fstream>
#include <direct.h>
#include<string>
#include<windows.h>
#include<cstdio>
std::string path_finder(void)
{
    int i;
    char strDir[129] = {0};
    std::string dir_path
    (_getcwd(strDir, 128));
    dir_path=strDir;
    for(i=0;i!=dir_path.length();i++)
    {
        if(dir_path[i]=='\\')
        {
            dir_path.replace(i,0,"\\");
            i++;
            dir_path.resize(dir_path.length()+1);
            dir_path.shrink_to_fit();
        }
    }
    dir_path.resize(dir_path.length()-1);
    dir_path.shrink_to_fit();
    dir_path=dir_path;
    dir_path+="\\\\";
    return dir_path;
}

int folder_check(std::string nic)
{

    std::string path=path_finder();
    int i;
    path+="Customer\\\\";
    path+=nic;
    const std::string path_c=path;
    i=mkdir(path_c.c_str());
    if(i==0)
    {
        std::cout<<std::endl<<"Welcome to our Community";
        return 1;
    }
    else{

        std::cout<<std::endl<<"Thank you! for coming again";
        return 0;


    }
}

template<class T>
void mutual_diet(T a)
{
	std::string c=a.get_gender();
	std::string b=a.get_level();
    std::string f_path=a.get_path();
        f_path+=c;
        f_path+="\\\\";
		f_path+=b;
		f_path+="_diet.txt";
    const std::string z=f_path;
	ShellExecute(NULL,"open",z.c_str(), NULL, NULL, SW_SHOWNORMAL);

}
template<class T>
void mutual_workout(T a)
{
    std::string c=a.get_gender();
	std::string b=a.get_level();
    std::string f_path=a.get_path(),v_path;
        f_path+=c;
        f_path+="\\\\";
		f_path+=b;
		v_path=f_path;
		v_path+=".mp4";
		f_path+="_workout.txt";
    const std::string z=f_path,v=v_path;
	ShellExecute(NULL,"open",z.c_str(), NULL, NULL, SW_SHOWNORMAL);
	int x;
	std::cout<<std::endl<<"Do you want to play the video for the Exersice?"<<std::endl<<"1.\tYes"<<std::endl<<"2.\tNo";
	std::cout<<std::endl<<"Enter your choice= ";
	std::cin>>x;
	if(x==1)
    {
        ShellExecute(NULL,"open",v.c_str(), NULL, NULL, SW_SHOWNORMAL);
    }
}


std::string string_finder(std::string nic,std::string find_w,std::string end_w)
{
    std::string path=path_finder(),str,str2;
    if(find_w=="Revenue"||find_w=="Plans")
    {
        path+="admin\\\\";
        path+="Revenue.txt";
    }
    else
    {
    path+="Customer\\\\";
    path+=nic;
    path+="\\\\";
    path+="Data.txt";
    }
    std::ifstream fin;
    fin.open(path);
    size_t found;
    int l_position,poss;
    while(!fin.eof())
   {
          getline(fin,str);
          found=str.find(find_w);
          if(found!=std::string::npos)
          {
            l_position=str.length();
            poss=str.find("=");
            poss+=2;
            l_position-=poss;
            str2=str.substr(poss,l_position);
            break;
          }
   }
    fin.close();
    return str2;

}

std::string c_level(void)
                {   std::cout<<"\n1-Beginner "<<std::endl<<"2-intermediate "<<std::endl<<"3-professional";
                    std::cout<<std::endl<<std::endl<<"Enter your desired choice= ";
                    std::string level;
                    int lvl;
                    std::cin>>lvl;
                    switch(lvl){
					case 1:
						{
							level="beginner";
							break;
						}
					case 2:
						{
							level="intermediate";
							break;
						}
					case 3:
						{
							level="professional";
							break;
						}
					default:
					{
						std::cout<<std::endl<<"Incorrect choice, please choose the correct option from the choices: "<<std::endl;
						c_level();
					}
                    }
                    return level;
                }

           std::string c_gen(void)
            {
                std::cout<<std::endl<<"1.\t Male ";
				std::cout<<std::endl<<"2.\t Female ";
                std::cout<<std::endl<<std::endl<<"Enter your desired choice= ";
                int gen;
                std::string gender;
                std::cin>>gen;
                switch(gen){
					case 1:
						{
							gender="male";
							break;
						}
					case 2:
						{
							gender="female";
							break;
						}
					default:
					      {std::cout<<std::endl<<"Incorrect Gender, Enter again: ";
					      c_gen();
					      break;
                          }
				}
				return gender;
            }
        int c_menu(std::string level,std::string gender,std::string nic)
        {
            std::string path=path_finder(),d_path,c_path=path_finder(),str,d2_path,c2_path,price[6];
            int i;
		    path+="admin\\";
			path+="\\Customers History.txt";

			c_path+="Customer\\\\";
			c_path+=nic;
			c_path+="\\\\";
			c_path+=level;
			c2_path=c_path;

			d_path=path_finder();
			d_path+=gender;
			d_path+="\\\\";
			d_path+=level;
			d2_path=d_path;
            price[0]="(Rs.8000)";
            price[1]="(Rs.13000)";
            price[2]="(Rs.12000)";
            price[3]="(Rs.18000)";
            price[4]="(Rs.15000)";
            price[5]="(Rs.24000)";
            if(level=="beginner"){
                i=0;
            }
            else if(level=="intermediate"){
            i=2;
            }
            else{
            i=4;
            }

            int x;
            std::cout<<std::endl<<"Select from the choices below "<<std::endl<<"1-\tDiet Plan "<<price[i]<<std::endl<<"2-\tWorkout Plan "<<price[i]<<std::endl<<"3-\tBoth "<<price[i+1]<<std::endl<<"Enter your choice= ";
            std::cin>>x;
            std::ofstream fout;
			fout.open(path,std::ios::app);
            if(!fout)
			{
				std::cout<<std::endl<<"File not Found";
			}
			else{
                if(x==1){
                fout<<"Plan= "<<level<<"-->"<<"Diet Plan Only"<<std::endl;
                fout.close();
                d_path+="_diet.txt";
                c_path+="_diet.txt";
                std::ifstream fin(d_path);
                std::ofstream out(c_path);
                 if(fin && out){
                while(getline(fin,str))
                {
                    out<<str<<std::endl;
                }
                }
                out.close();
                fin.close();
                return 1;
                }
                else if(x==2){
                    fout<<"Plan= "<<level<<"-->"<<"Workout Plan Only"<<std::endl;
                    fout.close();
                    d_path+="_workout.txt";
                    c_path+="_workout.txt";
                    std::ifstream fin(d_path);
                    std::ofstream out(c_path);
                    if(fin && out){
                    while(getline(fin,str))
                    {
                        out<<str<<std::endl;
                    }
                    }
                    out.close();
                    fin.close();
                return 2;
                }
                else if(x==3){
                    fout<<"Plan= "<<level<<"-->"<<"Diet Plan and Workout Plan"<<std::endl;
                    fout.close();
                    d_path+="_diet.txt";
                    c_path+="_diet.txt";
                    std::ifstream fin(d_path);
                    std::ofstream out(c_path);
                    if(fin && out){
                    while(getline(fin,str))
                    {
                        out<<str<<std::endl;
                    }
                    }
                    out.close();
                    fin.close();
                    d2_path+="_workout.txt";
                    c2_path+="_workout.txt";
                    std::ifstream finn(d2_path);

                    std::ofstream outn(c2_path);
                     if(finn && outn){
                    while(getline(finn,str))
                    {
                    outn<<str<<std::endl;
                    }
                    }
                    outn.close();
                    finn.close();
                    return 3;
                }
                else
                {
                std::cout<<"\n Wrong choice !! Please select again from the choices only ";
                c_menu(level,gender,nic);
                return 4;

                }

			}
			return 5;
        }
        void console_sleep(void){
         char z=219;
            system("cls");
	 	system("color 04");
	 	std::cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\tPlease wait ";
	 	for(int i=0;i<=40;i++){
	 		Sleep(40);
	 		std::cout<<z;
		 }
		 system("color 7");
		 system("cls");

        }
