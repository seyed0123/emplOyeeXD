#include <iostream>
#include <fstream>
#include<algorithm>
#include <windows.h>
#include <iomanip>

using namespace std;

struct User
{
    string username;
    string password;
    string firstname;
    string lastname;
    string email;
    int age;

};
struct Manager : User
{
    int managerID;
};

void resize(User* &arrUser, int &capacityUser)
{
    User* array2 = new User [2*capacityUser];
    for(int i = 0 ; i < capacityUser ; i++)
    {
    	array2[i]=arrUser[i];
	}
	arrUser = array2;
	delete [] array2;
	capacityUser *= 2;
	return;
}
void resize(Manager* &arrManager, int &capacityManager)
{
    Manager* array2 = new Manager [2*capacityManager];
    for(int i = 0 ; i < capacityManager ; i++)
    {
    	array2[i]=arrManager[i];
	}
	arrManager = array2;
	delete [] array2;
	capacityManager *= 2;
	return;
}
User appendUser()
{
	string username,password,firstname,lastname,email;
	int age;
	cout<<"enter username without space:\n";
	cin>>username;
	cout<<"enter password without space:\n";
	cin>>password;
	cout<<"enter firstname without space:\n";
	getline(cin,firstname);
	getline(cin,firstname);
	cout<<"enter lastname without space:\n";
	getline(cin,lastname);
	cout<<"enter email without space:\n";
	cin>>email;
	cout<<"enter age:\n";
	cin>>age;
	User ret;
	ret.username=username;
	ret.password=password;
	ret.firstname=firstname;
	ret.lastname=lastname;
	ret.email=email;
	ret.age=age;
	return ret;
}
Manager appendManager()
{
	string username,password,firstname,lastname,email;
	int age,managerID;
	cout<<"enter username without space:\n";
	cin>>username;
	cout<<"enter password without space:\n";
	cin>>password;
	cout<<"enter firstname without space:\n";
	getline(cin,firstname);
	getline(cin,firstname);
	cout<<"enter lastname without space:\n";
	getline(cin,lastname);
	cout<<"enter email without space:\n";
	cin>>email;
	cout<<"enter age:\n";
	cin>>age;
	cout<<"enter managerID:\n";
	cin>>managerID;
	Manager ret;
	ret.username=username;
	ret.password=password;
	ret.firstname=firstname;
	ret.lastname=lastname;
	ret.email=email;
	ret.age=age;
	ret.managerID=managerID;
	return ret;
}
struct DataBase
{
	void loadDataBase(User* &arrUser,int &capacityUser, int &sizeUser,Manager* &arrManager,int &capacityManager,int &sizeManager,string fileName)
	{
		string line;
		bool wh=0;
		fileName+=".HasanSite";
	  	ifstream myfile (fileName);
		if (myfile.is_open())
		{
			getline (myfile,line);
			if(line=="Managers:")
			{
				wh=1;
			}
			getline (myfile,line);
			while (wh==0 && getline(myfile,line))
			{
				if(line=="Managers:")
				{
					cout<<"Managers:\n";
					break;
				}
				cout<<line<<endl;

				sizeUser++;
				if(sizeUser==capacityUser)
				{
					resize(arrUser,capacityUser);
				}
				int index,iter=0;
				if(line[0]==' ')
				{
					iter++;
				}
				bool flag=0;
				for (int i = iter; i < line.size(); ++i)
				{
					
					if(line[i]==' ' && flag==0)
					{
						flag=1;
						index=stoi(line.substr(iter,i));
					}
					if(flag)
					{
						if(line[i]!=' ')
						{
							iter=i;
							break;
						}
					}
				}
				//cout<<index<<"*"<<iter<<endl;
				flag=0;
				for (int i = iter; i < line.size(); ++i)
				{
					//cout<<flag<<'-'<<iter<<'-'<<i<<'-'<<line[i]<<'-'<<endl;
					if(line[i]==' ' && flag==0)
					{
						flag=1;
						arrUser[index].username=line.substr(iter,i-iter);
					}
					if(flag)
					{
						if(line[i]!=' ')
						{
							iter=i;
							break;
						}
					}
				}
				//cout<<arrUser[index].name<<"*"<<iter<<endl;
				flag=0;
				for (int i = iter; i < line.size(); ++i)
				{
					if(line[i]== ' ' && flag==0)
					{
						flag=1;
						arrUser[index].password=(line.substr(iter,i-iter));
					}
					if(flag && line[i]!=' ')
					{
						iter=i;
						break;
					}
				}
				//cout<<arrUser[index].price<<"*"<<iter<<endl;
				flag=0;
				for (int i = iter; i < line.size(); ++i)
				{
					if(line[i]==' ' && flag==0)
					{
						flag=1;
						arrUser[index].firstname=line.substr(iter,i-iter);
					}
					if(flag && line[i]!=' ')
					{
						iter=i;
						break;
					}
				}
				//cout<<arrUser[index].brand<<"*"<<iter<<endl;
				flag=0;
				for (int i = iter; i < line.size(); ++i)
				{
					if((line[i]==' ' && flag==0))
					{
						flag=1;
						arrUser[index].lastname=(line.substr(iter,i-iter));
						break;
					}
					if(flag && line[i]!=' ')
					{
						iter=i;
						break;
					}
				}
				flag=0;
				for (int i = iter; i < line.size(); ++i)
				{
					if((line[i]==' ' && flag==0))
					{
						flag=1;
						arrUser[index].email=(line.substr(iter,i-iter));
						break;
					}
					if(flag && line[i]!=' ')
					{
						iter=i;
						break;
					}					
				}
				flag=0;
				for (int i = iter; i < line.size(); ++i)
				{
					if((line[i]==' ' && flag==0) || i==line.size()-1)
					{
						flag=1;
						arrUser[index].age=stoi(line.substr(iter,i-iter));
						break;
					}
					if(flag && line[i]!=' ')
					{
						iter=i;
						break;
					}
				}
				//cout<<arrUser[index].numbersInStock<<"*"<<iter<<endl;
			}
			getline (myfile,line);
			while (getline(myfile,line))
			{
				cout<<line<<endl;
				sizeManager++;
				if(sizeManager==capacityManager)
				{
					resize(arrManager,capacityManager);
				}
				int index,iter=0;
				if(line[0]==' ')
				{
					iter++;
				}
				bool flag=0;
				for (int i = iter; i < line.size(); ++i)
				{
					
					if(line[i]==' ' && flag==0)
					{
						flag=1;
						index=stoi(line.substr(iter,i));
					}
					if(flag)
					{
						if(line[i]!=' ')
						{
							iter=i;
							break;
						}
					}
				}
				//cout<<index<<"*"<<iter<<endl;
				flag=0;
				for (int i = iter; i < line.size(); ++i)
				{
					//cout<<flag<<'-'<<iter<<'-'<<i<<'-'<<line[i]<<'-'<<endl;
					if(line[i]==' ' && flag==0)
					{
						flag=1;
						arrManager[index].username=line.substr(iter,i-iter);
					}
					if(flag)
					{
						if(line[i]!=' ')
						{
							iter=i;
							break;
						}
					}
				}
				//cout<<arrManager[index].username<<"*"<<iter<<endl;
				flag=0;
				for (int i = iter; i < line.size(); ++i)
				{
					if(line[i]==' ' && flag==0)
					{
						flag=1;
						arrManager[index].password=(line.substr(iter,i-iter));
					}
					if(flag && line[i]!=' ')
					{
						iter=i;
						break;
					}
				}
				//cout<<arrManager[index].password<<"*"<<iter<<endl;
				flag=0;
				for (int i = iter; i < line.size(); ++i)
				{
					if(line[i]==' ' && flag==0)
					{
						flag=1;
						arrManager[index].firstname=line.substr(iter,i-iter);
					}
					if(flag && line[i]!=' ')
					{
						iter=i;
						break;
					}
				}
				//cout<<arrManager[index].firstname<<"*"<<iter<<endl;
				flag=0;
				for (int i = iter; i < line.size(); ++i)
				{
					//cout<<flag<<'-'<<iter<<'-'<<i<<'-'<<line[i]<<'-'<<endl;
					if((line[i]==' ' && flag==0))
					{
						flag=1;
						arrManager[index].lastname=(line.substr(iter,i-iter));
					}
					if(flag && line[i]!=' ')
					{
						iter=i;
						break;
					}
				}
				//cout<<arrManager[index].lastname<<"*"<<iter<<endl;
				flag=0;
				for (int i = iter; i < line.size(); ++i)
				{

					if((line[i]==' ' && flag==0))
					{
						flag=1;
						arrManager[index].email=(line.substr(iter,i-iter));
					}
					if(flag && line[i]!=' ')
					{
						iter=i;
						break;
					}					
				}
				//cout<<arrManager[index].email<<"*"<<iter<<endl;
				flag=0;
				for (int i = iter; i < line.size(); ++i)
				{

					if((line[i]==' ' && flag==0))
					{
						flag=1;
						//cout<<'*'<<line.substr(iter,i-iter)<<"*\n";
						arrManager[index].age=stoi(line.substr(iter,i-iter));
					}
					if(flag && line[i]!=' ')
					{
						iter=i;
						break;
					}
				}
				//cout<<arrManager[index].age<<"*"<<iter<<endl;
				flag=0;
				for (int i = iter; i < line.size(); ++i)
				{
					if((line[i]==' ' && flag==0) || i==line.size()-1)
					{
						flag=1;
						//cout<<'*'<<line.substr(iter,i-iter)<<"*\n";
						arrManager[index].managerID=stoi(line.substr(iter,i-iter));
						break;
					}
				}
				//cout<<arrManager[index].managerID<<"*"<<iter<<endl;
			}
			cout<<"load done.\n";
		myfile.close();
		}else
		{
			cout<<"something went wrong.\n";
		}
	}
    void createDataBase(User* &arrUser,int sizeUser,Manager* &arrManager,int sizeManager)
	{
		ofstream file;
		file.open("save.HasanSite");
		if(sizeUser!=0)
		{
			file<<"USERs:\n";
			 file << "Num"
		     << "----"
		     << "username"
		     << "- ";
		    file << "password"
		     << "--"
		     << "firstname"
		     << "-"
		     << "lastname-------email------age\n";
		    for (int i = 1; i <= sizeUser; i++) 
		    {
		        file << setw(2) <<i << "   ";
		        file << setw(8) << arrUser[i].username << "   ";
		        file << setw(8) << arrUser[i].password << "   " << setw(8)<<arrUser[i].firstname << "   "<< setw(8)<<arrUser[i].lastname << "       ";
		        file << setw(8) << arrUser[i].email << setw(3) << arrUser[i].age<< "\n";
		    }
		}
		if(sizeManager!=0)
		{
			file<<"Managers:\n";
			 file << "Num"
		     << "----"
		     << "username"
		     << "- ";
		    file << "password"
		     << "--"
		     << "firstname"
		     << "-"
		     << "lastname-------email------age----managerID\n";
		    for (int i = 1; i <= sizeManager; i++) 
		    {
		        file << setw(2) <<i << "   ";
		        file << setw(8) <<arrManager[i].username << "   ";
		        file << setw(8) << arrManager[i].password << "   " << setw(8)<<arrManager[i].firstname << "   "<< setw(8)<<arrManager[i].lastname << "       ";
		        file << setw(8) << arrManager[i].email << setw(3) << arrManager[i].age<< setw(7) << arrManager[i].managerID<<"\n";
		    }
		}
		file.close();
    }
    
    void initialisManager(Manager* & arrManager,int & sizeManager)
	{
		
		if(sizeManager==0)
		{
			sizeManager++;
			arrManager[sizeManager].managerID=123456;
			arrManager[sizeManager].username="admin";
			arrManager[sizeManager].password="admin";
			arrManager[sizeManager].firstname="firstname";
			arrManager[sizeManager].lastname="lastname";
			arrManager[sizeManager].email="email";
			arrManager[sizeManager].age=0;
		}
		return;
		
    }
    
    bool isUserExists(string username,User* &arrUser,int sizeUser)
	{
		for(int i= 1 ; i <= sizeUser ; i++)
		{
			if(arrUser[i].username==username)
			{
				return 1;
			}
		}
        return 0;
    }

    bool isManagerExists(int managerID,Manager* & arrManager,int sizeManager)
	{
		bool ret=0;
		for(int i= 1 ; i <= sizeManager ; i++)
		{
			if(arrManager[i].managerID==managerID)
			{
				return 1;
			}
		}
        return 0;
    }

    bool loginUser(string username ,string password,int sizeUser,User* & arrUser)
	{
		for(int i = 1 ; i <= sizeUser ; i++ )
		{
			if(arrUser[i].username==username && arrUser[i].password==password)
			{
				return 1;
			}
		}
		return 0;
    }
    bool loginManager(string username ,string password,int sizeManager,Manager* & arrManager , int managerID)
    {
		for(int i = 1 ; i <= sizeManager ; i++ )
		{
			if(arrManager[i].username==username && arrManager[i].password==password && arrManager[i].managerID==managerID)
			{
				return 1;
			}
		}
		return 0;
    }
    User* findUser(string username,User* & arrUser,int sizeUser)
	{
		DataBase data;
		bool FuncAns=data.isUserExists(username , arrUser , sizeUser );
        if(FuncAns)
        {
        	for(int i = 1 ; i <= sizeUser ; i++)
        	{
        		if(arrUser[i].username==username)
        		{
        			return &arrUser[i];
        		}
        	}
        }
        return &arrUser[0];
    }
    Manager* findManager(int managerID,Manager* & arrManager,int sizeManager)
	{
		DataBase data;
		bool FuncAns=data.isManagerExists(managerID , arrManager , sizeManager );
        if(FuncAns)
        {
        	for(int i = 1 ; i <= sizeManager ; i++)
        	{
        		if(arrManager[i].managerID==managerID)
        		{
        			return &arrManager[i];
        		}
        	}
        }
        return &arrManager[0];
    }
    bool addUser(User * &arrUser,User user,int &sizeUser,int& capacityUser)
	{	
		DataBase data;
		bool FuncAns=data.isUserExists(user.username,arrUser,sizeUser);
		if(FuncAns)
		{
			return 0;
		}else
		{
			sizeUser++;
			if(sizeUser==capacityUser)
			{
				resize(arrUser,capacityUser);
			}
			arrUser[sizeUser]=user;
			return 1;
		}
    }

    bool addManager(Manager * &arrManager , Manager manager, int &sizeManager,int &capacityManager)
	{
		DataBase data;
		bool FuncAns=data.isManagerExists(manager.managerID , arrManager , sizeManager);
		if(FuncAns)
		{
			return 0;
		}
		else
		{
			sizeManager++;
			if(sizeManager==capacityManager)
			{
				resize(arrManager,capacityManager);
			}
			arrManager[sizeManager]=manager;
			return 1;
		}
    }

    bool updateUser(User userInitial,User userFinal,User* & arrUser,int sizeUser)
	{
		DataBase data;
		bool FuncAns=(data.findUser(userInitial.username,arrUser,sizeUser)==&arrUser[0]);
		if(FuncAns)
		{
			return 0;
		}else
		{
			*data.findUser(userInitial.username,arrUser,sizeUser)=userFinal;
			return 1;
		}


    }

    bool updateManager(Manager managerInitial,Manager managerFinal,Manager* & arrManager,int sizeManager)
	{
		DataBase data;
		bool FuncAns=(data.findManager(managerInitial.managerID,arrManager,sizeManager)==&arrManager[0]);
  		if(FuncAns)
		{
			return 0;
		}else
		{
			*data.findManager(managerInitial.managerID,arrManager,sizeManager)=managerFinal;
			return 1;
		}

    }

    bool deleteUser(User user,User* & arrUser,int &sizeUser,int & capacityUser)
	{
		DataBase data;
		bool FuncAns=(data.findUser(user.username,arrUser,sizeUser)==&arrUser[0]);
		if(FuncAns)
		{
			return 0;
		}else
		{
			User* arrUserint=new User [capacityUser];
			for(int i = 1 ; i <= sizeUser ;  i++)
			{
				if(arrUser[i].username!=user.username)
				{
					arrUserint[i]=arrUser[i];

				}
			}
			sizeUser--;
			arrUser=arrUserint;
			return 1;
		}

    }

    bool deleteManager(Manager manager,Manager* & arrManager,int &sizeManager,int &capacityManager)
	{
		DataBase data;
		bool FuncAns=(data.findManager(manager.managerID,arrManager,sizeManager)==&arrManager[0]);
		if(FuncAns)
		{
			return 0;
		}else
		{
			Manager* arrManagerint=new Manager [capacityManager];
			for(int i = 1 ; i <= sizeManager ;  i++)
			{
				if(arrManager[i].username==manager.username)
				{
					arrManagerint[i]=arrManager[i];
					
				}
			}
			sizeManager--;
			arrManager=arrManagerint;
			return 1;
		}
  

    }

};
void showMenuUser(User* &arrUser,int & sizeUser)
{
	while(1)
	{
		DataBase data;
		string username,password;
		cout<<"do you want to exit?   no(0)  /   yes(1)\n";
		int n;
		cin>>n;
		system("cls");
		if(n==1)
		{
			return;
			
		}
		while(1)
		{
			cout<<"enter back if you want\n";
			cout<<"username:\n";
			cin>>username;
			if(username=="back")
			{
				return;
			}
			cout<<"password:\n";
			cin>>password;
			bool FuncAns=data.loginUser(username,password,sizeUser,arrUser);
			if(FuncAns)
			{
				break;
			}
			system("cls");
			cout<<"username or password is wrong\n";
			
		}
		User* initalUser;
		initalUser = data.findUser(username,arrUser,sizeUser);
		while(1)
		{
			bool falg=0;
			cout<<"**********whatsup "<<(*initalUser).firstname<<"**********\n";
			cout<<"1-change username\n";
			cout<<"2-change password\n";
			cout<<"3-change firstname\n";
			cout<<"4-change lastname\n";
			cout<<"5-logout\n";
			int input;
			cin>>input;
			system("cls");
			if(input == 1)
			{	cout<<"enter new username\n";
				string username;
				cin>>username;
				bool flag=data.isUserExists(username,arrUser,sizeUser);
				if(flag==0)
				{
					(*initalUser).username=username;
				}else
				{
					cout<<"username already used.\n";
				}
			}
			else if(input == 2)
			{
				cout<<"enter new password\n";
				string password;
				cin>>password;
				(*initalUser).password=password;
			}
			else if(input == 3)
			{
				cout<<"enter new firstname\n";
				string firstname;
				getline(cin,firstname);
				getline(cin,firstname);
				(*initalUser).firstname=firstname;
			}
			else if(input == 4)
			{
				cout<<"enter new lastname\n";
				string lastname;
				getline(cin,lastname);
				getline(cin,lastname);
				(*initalUser).lastname=lastname;
			}
			else if(input == 5)
				break;
			else
				cout<<"input isn't valid\n";
		}
	}

}
void showMenuManager(Manager* & arrManager,int &sizeManager,int &capacityManager,User* &arrUser,int & sizeUser,int& capacityUser)
{
	while(1)
	{
		DataBase data;
		string username,password;
		cout<<"do you want to exit?   on(0)   yes(1)\n";
		int n,managerID;
		cin>>n;
		system("cls");
		if(n==1)
		{
			return;
		}
		while(1)
		{
			cout<<"enter back if you want.\n";
			cout<<"username:\n";
			cin>>username;
			if(username=="back")
			{
				return;
			}
			cout<<"password:\n";
			cin>>password;
			cout<<"managerID:\n";
			cin>>managerID;
			bool FuncAns=data.loginManager(username,password,sizeManager,arrManager,managerID);
			if(FuncAns)
			{
				break;
			}
			system("cls");
			cout<<"username or password is wrong\n";
			
		}
		Manager* initialManager;
		initialManager = data.findManager(managerID,arrManager,sizeManager);
		while(1)
		{
			bool falg=0;
			cout<<"**********whatsup "<<(*initialManager).firstname<<"**********\n";
			cout<<"----"<<(*initialManager).managerID<<"-----\n\n";
			cout<<"1-add user\n";
			cout<<"2-update user\n";
			cout<<"3-delete user\n";
			cout<<"4-add manager\n";
			cout<<"5-update manager\n";
			cout<<"6-delete manager\n";
			cout<<"7-logout\n";
			cout<<"for each one you must enter entire user/manager information\n";
			int input;
			cin>>input;
			system("cls");
			if(input == 1)
			{	
				User user=appendUser();
				if(!data.addUser(arrUser , user , sizeUser , capacityUser) )
				{
					cout<<"this username already used\ntry another one";
				}else
				{
					cout<<"*********Done**********\n";
				}

			}
			else if(input == 2)
			{
				cout<<"first enter the old user information then enter the new one.\n";
				cout<<"enter  user old info\n";
				User userInitial=appendUser();
				system("cls");
				cout<<"enter  user new info\n";
				User userFinal=appendUser();
				if(!data.updateUser(userInitial , userFinal , arrUser , sizeUser) )
				{
					cout<<"this username already used\ntry another one";
				}else
				{
					cout<<"**********Done**********\n\n";
				}
			}
			else if(input == 3)
			{
				User user=appendUser();
				if(!data.deleteUser( user, arrUser , sizeUser , capacityUser) )
				{
					cout<<"this username doesn't exist \n try another one";
				}else
				{
					cout<<"**********Done**********\n\n";
				}
			}
			else if(input == 4)
			{	
				Manager Manager=appendManager();
				if(!data.addManager(arrManager , Manager , sizeManager , capacityManager) )
				{
					cout<<"this userrname or managerID already used\ntry another one";
				}else
				{
					cout<<"*********Done**********\n";
				}

			}
			else if(input == 5)
			{
				cout<<"first enter the old Manager information then enter the new one.\n";
				cout<<"enter  manager old info\n";
				Manager managerInitial=appendManager();
				system("cls");
				cout<<"enter  manager new info\n";
				Manager managerFinal=appendManager();
				if(!data.updateManager(managerInitial , managerFinal , arrManager , sizeManager) )
				{
					cout<<"this username already used\ntry another one";
				}else
				{
					cout<<"**********Done**********\n\n";
				}
			}
			else if(input == 6)
			{
				Manager Manager=appendManager();
				if(!data.deleteManager( Manager, arrManager , sizeManager , capacityManager) )
				{
					cout<<"this username doesn't exist \n try another one";
				}else
				{
					cout<<"**********Done**********\n\n";
				}
			}
			else if(input == 7)
				break;
			else
				cout<<"input isn't valid\n";
		}
	}

}
int main()
{
	DataBase data;
	int capacityUser=2,sizeUser=0;
	User* arrUser=new User [2];
	int capacityManager=2,sizeManager=0;
	Manager* arrManager=new Manager [2];
	cout<<"do you have save file?  1 / 0 \n ";
	int n;
	cin>>n;
	if(n==1)
	{
		string fileName;
		cout<<"enter your file name:\n";
		cin>>fileName;
		data.loadDataBase(arrUser , capacityUser , sizeUser , arrManager , capacityManager , sizeManager , fileName);
	}
	data.initialisManager(arrManager,sizeManager);
	while(1)
	{
		int input;
		cout<<"do you want login as manager(1)? or user(0) except(0,1) to exit?\n";
		cin>>input;
		if(input==0)
			showMenuUser(arrUser,sizeUser);
		else if(input==1)
			showMenuManager(arrManager , sizeManager , capacityManager , arrUser , sizeUser , capacityUser);
		else
		{
			data.createDataBase(arrUser , sizeUser , arrManager , sizeManager);
			exit(0);
		}
	}
}