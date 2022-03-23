#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
#include<conio.h>
#include<cstdio>
#include<string.h>
#include<cstdlib>
using namespace std;
static int p=0;
class booking{
	int room_no;
	string host,start_time,end_time,from,to;
	string arr[32];
	public:
		void install();
		void reservation();
		void show();
		void rooms_available();
		void chair_status();
	}rooms[10];
	void design(char ch){
		for(int i=0;i<100;i++)
		cout<<ch;
	}
	void booking::install(){
		cout<<"Enter room number:      ";
		cin>>rooms[p].room_no;
		cout<<"Host Name:              ";
		cin.ignore();
		getline(cin,rooms[p].host);
		cout<<"Start time:             ";
		getline(cin,rooms[p].start_time);
		cout<<"End time:               ";
		getline(cin,rooms[p].end_time);
		cout<<"from:                   ";
		getline(cin,rooms[p].from);
		cout<<"to:                     ";
		getline(cin,rooms[p].to);
	}
	void booking::reservation(){
		int num,chair;
		bool flag=false;
		cout<<"\nEnter room number:          ";
		again1:
		cin>>num;
		for(int i=0;i<p;i++){
			if(rooms[i].room_no==num){
				again:
				cout<<"\nchair number:     ";
				cin>>chair;
				if(chair>32){
					cout<<"\nThere are only 32 chairs available in the room, starting from chair no. 1";
					goto again;
				}
				if(rooms[i].arr[chair-1] != "Empty"){
				    cout<<"\nchair is already reserved";
			        goto again;
				}
				else{
					cout<<"\nTraveller Name:          ";
					cin.ignore();
					getline(cin,rooms[i].arr[chair-1]);
				}
				flag=true;
				break;
			}
		}
		if(!flag){
			cout<<"\ncorrect room number: ";
  			goto again1;
  		}
  }
  void booking::show(){
  	int num,empty=0;
  	bool flag=false;
  	again:
  	cout<<"\nEnter room no:";
  	cin>>num;
  	for(int i=0;i<p;i++){
  		if(rooms[i].room_no==num){
  			design('*');
  			cout<<endl<<"Room No.   "<<rooms[i].room_no<<"        "<<"Host:   "<<rooms[i].host<<"        "<<"start time:   "<<rooms[i].start_time<<"        "<<"End time:   "<<rooms[i].end_time<<endl;
  			cout<<"From:   "<<rooms[i].from<<"        "<<"To:   "<<rooms[i].to<<endl;
  			design('*');
  			cout<<endl;
  			for(int j=0;j<32;j++){
			    cout<<j+1<<".         "<<rooms[i].arr[j]<<"        ";
  			    if((j+1)%4==0) cout<<endl;
  				if(rooms[i].arr[j]=="Empty") empty++;
			  }
			cout<<"\nThere are "<<empty<<" chairs empty in Room No: "<<rooms[i].room_no;
			for(int j=0;j<32;j++){
				if(rooms[i].arr[j]!="Empty"){
					cout<<"\nThe chair no "<<j+1<<" is reserved for "<<rooms[i].arr[j];
				}
			}
  			flag=true;
  			break;
		  }
	  }
	  if(!flag){
	  	cout<<"\nEnter valid correct room no.";
	  	goto again;
	  }
	}
	void booking::rooms_available(){
		for(int i=0;i<p;i++){
			design('*');
			cout<<endl<<"Room No.   "<<rooms[i].room_no<<"        "<<"Host:   "<<rooms[i].host<<"        "<<"start time:   "<<rooms[i].start_time<<"        "<<"End time:   "<<rooms[i].end_time<<endl;
		    cout<<"From:   "<<rooms[i].from<<"        "<<"To:   "<<rooms[i].to<<endl;
		    design('_');
		    cout<<endl;
		}
	}
	void booking::chair_status(){
		for(int i=0;i<32;i++)
		    rooms[p].arr[i]="Empty";
		p++;
	}
int main(){
	system("cls");
	while(1){
		int opt;
		cout<<"\n\n\n\n\n\n                      1.install\n";
		cout<<"                      2.Reservation\n";
		cout<<"                      3.show\n";
		cout<<"                      4.rooms available\n";
		cout<<"                      5.exit\n";
		cout<<"                      Enter your input: ";
		cin>>opt;
		switch(opt){
			case 1:
				rooms[p].install();
				rooms[p].chair_status();
				break;
			case 2:
				rooms[p].reservation();
				break;
			case 3:
				rooms[p].show();
				break;
			case 4:
				rooms[p].rooms_available();
				break;
			case 5:
				exit(1);
			default:
				cout<<"Invalid input,try again\n\n";
		}
	}
	return 0;
}
