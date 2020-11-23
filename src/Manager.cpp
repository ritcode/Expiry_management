bool loggedIn=false;

class Manager
{
	User user;
	vector<User> users;
	fstream data;

  public:
	void start();
	void loginPage();
	bool isUser(string uname);
	bool login();
	void createAccount();
	void showMenu();
	void close();
};

void Manager::start()
{
	data.open("data.dat", ios::in | ios::out | ios::binary);

	cout << "WELCOME TO EXPIRY MANAGEMENT SYSTEM\n\nPress any key to go to login page" << endl;
	getch();
	system("cls");
}

void Manager::loginPage()
{
	cout << "Hello User!!"
			"\n1.Login"
			"\n2.New User? Create Account"
			"\n\nChoose from above option : ";
	int ch;
	cin >> ch;
	switch (ch)
	{
		case 1:
		{
			loggedIn=login();
			break;
		}
		case 2:
		{
			createAccount();
			loggedIn=true;
			break;
		}
	}
}

bool Manager::isUser(string uname)
{
	
	for (int i=0; i<users.size();i++)
		if(users[i].getUsername()==uname)
			return true;
		
	return false;
}

bool Manager::login()
{
	string uname;
	string pass;
	cout << "Enter Username : "; cin >> uname;
	if (isUser(uname))
	{
		PasswordEnter:
		cout << "Enter password : "; cin >> pass;
		if (user.verifyPassword(pass))
		{
			system("cls");
			int i=0;
			for ( i=0; i<users.size();i++)
				if(users[i].getUsername()==uname)
					break;
			user=users[i];
			return true;
		}
		else
		{
			cout<<"Password didn't match!!! Please try again"<<endl;
			system("cls");
			goto PasswordEnter;
		}
	}
	else
	{
		cout<<"No such username found!!!"<<endl;
		return false;
	}
	
}

void Manager::createAccount()
{
	string uname;
	string pass,confirmPass;
	cout<<"Enter Username : "; cin>>uname;
	ReEnter:
	cout<<"Enter Password : "; cin>>pass;
	cout<<"Confirm Password : "; cin>>confirmPass;
	if(pass.compare(confirmPass)==0)
		cout<<"Account created successfully!!";
	else
	{
		cout<<"Password didn't match!!!\nPlease re-enter password"<<endl;
		goto ReEnter;
	}	
	user.putUsername(uname);
	user.putPass(pass);
	users.push_back(user);
	system("cls");
}

void Manager::showMenu()
{
	system("cls");
	cout<<"Hello "<<user.getUsername()<<endl<<endl;
	cout<<"1.Add new item"
	      "\n2.Show expired items"
	      "\n3.Show all items"
	      "\n4.Remove an item"
	      "\n5.Remove all expired items"
	      "\n6.Log out"<<endl<<endl;
	int ch;
	cout<<"What would you like to do : "; cin>>ch;
	
	switch (ch)
	{
		case 1 :
		{
			user.addItem();
			break;
		}
		case 2 :
		{
			user.showExpired();
			break;
		}
		case 3 :
		{
			user.showAll();
			break;
		}
		case 4 :
		{
			user.removeItem();
			break;
		}
		case 5 :
		{
			user.removeAllExpired();
			break;
		}
		case 6 :
		{
			close();
			break;
		 }
		 default :
		 cout<<"Invalid input!!! Please enter correct option";
	}
}

void Manager::close()
{
	auto itr=find(users.begin(), users.end(), user);
	users[itr-users.begin()]=user;
	data.seekg(ios::beg);
	data.write((char *)&users,sizeof(users));
	data.close();
	loggedIn=false;
}
