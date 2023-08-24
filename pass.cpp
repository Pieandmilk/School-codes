#include <iostream>
using namespace std;

int main(){
	int a=1;
	string pass;
	
	do {
		cout<< "Enter Password: ";
		cin>>pass;
		
	}
	while(pass!="PASSWORD");
	cout<< "Access Granted!"<< endl;
		
	
	for(int i=1;i<=10;i++){
		cout<<i<<" Squared is equal to "<< i*i<<endl;
		
		
		}
		
	cout<<"\n";
	while (a<=10){
		cout<<a<<" Squared is equal to "<< a*a<<endl;
		a+=1;
	}
}
