#include<iostream>
#include <vector>
#include <fstream>
#include<conio.h>
using namespace std;
#include "user.cpp"
#include "Manager.cpp"


int main()
{
	Manager mg;
	mg.start();
	while(!loggedIn)
		mg.loginPage();
	while(loggedIn)
		mg.showMenu();
	
	cout<<"Thank You!!"<<endl;
	return 0;
}
