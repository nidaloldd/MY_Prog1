#include "../../std_lib_facilities.h"


struct Person
{

	string first_name(){return fn;};
	string secund_name(){return sn;};
	int age(){return a;};

	Person(){};
	Person(string ff , string ss, int aa);

private:
	string fn;
	string sn;
	int a;
	
};

Person:: Person(string ff , string ss, int aa)
:fn(ff),sn(ss),a(aa){
		

		string name = ff+' '+ss;
		
		if(aa<0 or aa>150){error("age is wrong");}
		
		for (int i = 0; i < name.size(); ++i)
		{	

			switch(name[i])
			case ';': case ':':	case '"': case '[':case ']' :
			case '*': case '&': case '^': case '%' :case '$':
			case '#': case '@': case '!': error("wrong name");	
		
		}
	};


istream& operator>>(istream& is, Person& p)
{
	string fn;    //first name
	string sn;    // secund name
	int a;        // age

	is >> fn >> sn >> a;

	if(!is) error("input error...");

	p = Person(fn,sn,a);

	return is;
}

ostream& operator<<(ostream& os, Person& p)
{

	return os << p.first_name() << ' ' << p.secund_name() << ' ' << p.age() ;
}


int main()
{
	//Person p ("Goofy",15);
	//p.name = "Goofy";
	//p.age=63;

	vector<Person> vec ;


    cout << "write here a first name a secund name and an age" << endl 
    << "if you want to quit write '|' to first and secund name" << endl;
	for (Person p; cin >> p;)
	{
		if(p.first_name()=="|" and p.secund_name() == "|" ){break;}

		vec.push_back(p);
	}

	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << endl;
	}

	return 0;
}