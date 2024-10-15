//Code bu Kokate Rushik

#include<iostream>
using namespace std;

class Publication {
	protected:
		string title;
		float price;
	
	public:
		Publication() : title(""), price(0.0) {}
		void setpub(string t, float p) {
			title=t;
			price=p;
		}
		void displaypub() {
			cout<<"\nTitle:- "<<title<<"\tPrice:- "<<price;
		}
};

class Book : public Publication {
	protected:
		int pages;
	
	public:
		Book() : pages(0) {}
		void setbook() {
			string t;
			float p;
			int pg;
			cout<<"\nEnter book details."<<endl;
			cout<<"Title:- "; cin>>t;
			cout<<"Price:- "; cin>>p;
			cout<<"Page Count:- "; cin>>pg;
			if (p<0.0 || pg<0) {
				p=0.0; pg=0;
			}
			Publication::setpub(t,p);
			pages=pg;
		}
		void displaybook() {
			cout<<"\nBook Details";
			Publication::displaypub();
			cout<<"\tPage count:- "<<pages<<endl;
		}
};

class Tape : public Publication {
	protected:
		float playtime;
	
	public:
		Tape() : playtime(0.0) {}
		void settape() {
			string t;
			float p, pt;
			cout<<"\nEnter tape details."<<endl;
			cout<<"Title:- "; cin>>t;
			cout<<"Price:- "; cin>>p;
			cout<<"Playing time:- "; cin>>pt;
			if (p<0.0 || pt<0.0) {
				p=0.0; pt=0.0;
			}
			Publication::setpub(t,p);
			playtime=pt;
		}
		void displaytape() {
			cout<<"\nTape Details";
			Publication::displaypub();
			cout<<"\tPlaytime:- "<<playtime<<endl;
		}
};

int main() {
	Book book;
	Tape tape;
	int ch1, ch2;
	
	do {
		cout<<"\nWhat do want to do?\n1. Enter details\n2. Display details\n3. Exit\nChoice:- ";
		cin>>ch1;
		
		if (ch1==1) {
			do {
				cout<<"\nSelect type of media\n1. Book\n2. Tape\n3. Exit\nSelect:- "; cin>>ch2;
				if (ch2==1) {
					book.setbook();
				} else if (ch2==2) {
					tape.settape();
				} else if (ch2==3) {
					cout<<"Exiting..."<<endl;
					continue;
				} else {
					cout<<"Invalid Input"<<endl;
					continue;
				}
			} while (ch2!=3);
		}
		
		else if (ch1==2) {
			do {
				cout<<"\nSelect type of media\n1. Book\n2. Tape\n3. Exit\nSelect:- "; cin>>ch2;
				if (ch2==1) {
					book.displaybook();
				} else if (ch2==2) {
					tape.displaytape();
				} else if (ch2==3) {
					cout<<"Exiting..."<<endl;
					continue;					
				} else {
					cout<<"Invalid Input"<<endl;
					continue;
				}
			} while (ch2!=3);
		}
		
		else if (ch1==3) {
			cout<<"Exiting..."<<endl;
			continue;
		}
		
		else {
			cout<<"Invalid option"<<endl;
		}
	} while (ch1!=3);

	cout<<"End of the Program"<<endl;

	return 0;
}
