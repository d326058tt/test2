#include<iostream>
#include<string>
#include<list>
#include<map>
#include<vector>
#include<algorithm>
#include <sstream>
#include <regex>
#include "md5.h"
#include "account.h"
extern "C"{
//#include "wildcard.h"//
#include "wildcard_nonre.h"
};

//typedef unsigned long long int MONEY;
//When you compile the file , make sure you include md5.cpp and -std=c++11
// in you command line.
string last_successful_login_ID;
using namespace std;
vector <vector <string> > IDs(101);
int recommand,max_recommand;
long long nID;

//function for merge two records
bool compare (Record first, Record second)
{ return ( first.timestamp < second.timestamp ); }

//function for match wildcard
bool match(string wilcard_input,string target){

	for(int i=0;i<wilcard_input.length();i++){
		if(wilcard_input[i]=='?')
			wilcard_input[i]='.';
		if(wilcard_input[i] == '*'){
			wilcard_input[i] = '.';
			wilcard_input.insert(i+1,"*");
			i++;
		}
	}
	regex e(wilcard_input);
	return regex_match(target,e);
}

//functions for recommend ID
typedef struct
{
	string ID;
	int score;
}IDscore;
bool cmp(IDscore c,IDscore d)
{
	if(c.score>d.score) return false;
	else if(c.score==d.score)
	{
		if(c.ID>d.ID) return false;
		else return true;
	}
	else return true;
}
bool found(string s)
{
	int m=s.length();
	bool ans=false;
	vector<string>:: iterator it;
	for(it=IDs[m].begin();it!=IDs[m].end();it++)
	{
		if(*it==s)
		{
			ans=true;
			break;
		}
	}
	return ans;
}
int score_compute(string s,string t,int minlength)
{
	int ans=0;
	if(s.length()>minlength)
	{
		int n=s.length()-minlength;
		ans+=n*(n+1)/2;
	}
	if(t.length()>minlength)
	{
		int n=t.length()-minlength;
		ans+=n*(n+1)/2;
	}
	for(int i=0;i<minlength;i++)
	{
		if(s[i]!=t[i]) ans+=(minlength-i);
	}
	return ans;
}
void ExhaustiveAttack(string s,int score,int* changed,int* recommand,int x,int dlen,int y)
{
	if(*recommand==max_recommand) return;
	if(score==0)
	{
		if(y==1)
		{
			if(!found(s))
			{
				cout<<s;
				(*recommand)++;
				if((*recommand)<max_recommand) cout<<",";
			}
		}
		else
		{
			if(found(s))
			{
				cout<<s;
				(*recommand)++;
				if((*recommand)<max_recommand) cout<<",";
			}
		}

		return;
	}
	string t=s;
	int m=s.length();
	if(x==0)
	{
		//cout<<t<<" "<<dlen;
		if(dlen==0)
		{
			//cout<<s;
			if(y==1)
			{
				if(!found(s))
				{
					cout<<s;
					(*recommand)++;
					if((*recommand)<max_recommand) cout<<",";
				}
			}
			else
			{
				if(found(s))
				{
					cout<<s;
					(*recommand)++;
					if((*recommand)<max_recommand) cout<<",";
				}
			}
			return;
		}
		if(m==1) return;
		t.pop_back();
		//cout<<t<<endl;
		//cout<<t<<endl;
		ExhaustiveAttack(t,score,changed,recommand,0,dlen-1,y);
		t.push_back(s[m-1]);
		//cout<<t<<endl;
	}
	if(x==1)
	{
		int n=sqrt(score*2);
		if(score*2==n*(n+1)) ExhaustiveAttack(t,score,changed,recommand,0,n,y);
		for(int i=m-score;i<m;i++)
		{
			if(changed[i]==1) continue;
			int j;
			for(j='0';j<='9';j++)
			{
				if(j>=s[i]) break;
				t[i]=j;
				changed[i]=1;
				//cout<<t<<endl;
				ExhaustiveAttack(t,score-(m-i),changed,recommand,1,0,y);
				t[i]=s[i];
				changed[i]=0;
			}
			for(j='A';j<s[i],j<='Z';j++)
			{
				if(j>=s[i]) break;
				t[i]=j;
				changed[i]=1;
				//cout<<t<<endl;
				ExhaustiveAttack(t,score-(m-i),changed,recommand,1,0,y);
				t[i]=s[i];
				changed[i]=0;
			}
			for(j='a';j<s[i],j<='z';j++)
			{
				if(j>=s[i]) break;
				t[i]=j;
				changed[i]=1;
				//cout<<t<<endl;
				ExhaustiveAttack(t,score-(m-i),changed,recommand,1,0,y);
				t[i]=s[i];
				changed[i]=0;
			}
		}
		n=sqrt(score*2);
		//cout<<"n*(n+1)="<<2*score<<endl;
		//cout<<n<<" "<<score<<endl;
		if(score*2==n*(n+1)) ExhaustiveAttack(t,score,changed,recommand,2,n,y);
		for(int i=m-score;i<m;i++)
		{
			int j;
			for(j=s[i]+1;j<='9';j++)
			{
				t[i]=j;
				changed[i]=1;
				//cout<<t<<endl;
				ExhaustiveAttack(t,score-(m-i),changed,recommand,1,0,y);
				t[i]=s[i];
				changed[i]=0;
			}
			for(j=s[i]+1;j<='Z';j++)
			{
				t[i]=j;
				changed[i]=1;
				//cout<<t<<endl;
				ExhaustiveAttack(t,score-(m-i),changed,recommand,1,0,y);
				t[i]=s[i];
				changed[i]=0;
			}
			for(j=s[i]+1;j<='z';j++)
			{
				t[i]=j;
				changed[i]=1;
				//cout<<t<<endl;
				ExhaustiveAttack(t,score-(m-i),changed,recommand,1,0,y);
				t[i]=s[i];
				changed[i]=0;
			}
		}
	}
	if(x==2)
	{
		//cout<<t<<endl;
		if(dlen==0)
		{
			if(y==1)
			{
				if(!found(s))
				{
					cout<<s;
					(*recommand)++;
					if((*recommand)<max_recommand) cout<<",";
				}
			}
			else
			{
				if(found(s))
				{
					cout<<s;
					(*recommand)++;
					if((*recommand)<max_recommand) cout<<",";
				}
			}
			return;
		}
		int j;
		for(j='0';j<='9';j++)
		{
			t.push_back(j);
			//cout<<t<<endl;
			//cout<<t<<endl;
			ExhaustiveAttack(t,score,changed,recommand,2,dlen-1,y);
			t.pop_back();
			//cout<<t<<endl;
		}
		for(j='A';j<='Z';j++)
		{
			t.push_back(j);
			//cout<<t<<endl;
			ExhaustiveAttack(t,score,changed,recommand,2,dlen-1,y);
			t.pop_back();
			//cout<<t<<endl;
		}
		for(j='a';j<='z';j++)
		{

			t.push_back(j);
			//cout<<t<<endl;
			//cout<<t<<endl;
			ExhaustiveAttack(t,score,changed,recommand,2,dlen-1,y);
			t.pop_back();
			//cout<<t<<endl;
		}
	}
}

//Function that are not bound to last successful login


void login(string ID,string password,vector <string>& ID_vector,vector <string>& Password_vector){
	string encoded = md5(password);
	bool checkID = false,checkPassword = false;
	vector <string>:: iterator it;
	for(it = ID_vector.begin(); it != ID_vector.end(); ++it){
			if(*it == ID){
					checkID = true;
					break;
			}
	}
	
	for(it=Password_vector.begin(); it != Password_vector.end(); ++it){
			if(*it == encoded){
					checkPassword = true;
					break;
			}
	}
	
	if(checkID == false){
		cout << "ID " << ID << " not found" << endl;
		return;
	}

	else if(checkPassword == false){
		cout << "wrong password" << endl;
		return;
	}
	
	else{
		cout << "success" << endl;
		last_successful_login_ID = ID;
		return;
	}
}

void create(string ID,string password,vector <string>& ID_vector,vector <string>& Password_vector,vector <account>& Account_vector){

	string encoded = md5(password);
	bool checkID = false;
	vector <string>:: iterator it;
	for(it = ID_vector.begin(); it != ID_vector.end(); ++it){
			if(*it == ID){
					checkID = true;
					break;
			}
	}
	if(checkID == false){
		cout << "success" << endl;
		account tmp(ID,encoded);
		int m=ID.length();
		ID_vector.push_back(ID);
		Password_vector.push_back(encoded);
		Account_vector.push_back(tmp);
		IDs[m].push_back(ID);
		nID++;
		return;
	}
	else{
		cout << "ID "<<  ID << " exists, ";
		recommand=0;
		max_recommand=10;
		int score=1;
		while(1)
		{
			if(recommand==max_recommand) break;
			int l=ID.length();
			int changed[l];
			memset(changed,0,sizeof(changed));
			ExhaustiveAttack(ID,score,changed,&recommand,1,0,1);
			score++;
		}
		cout<<endl;
	}
	return ;
}

void _delete(string& ID,string password, vector <string>& ID_vector,vector <string>& Password_vector,vector <account>& Account_vector){
	string encoded = md5(password);
	bool checkID = false,checkPassword = false;
	int count=0,pos;
	vector <string>:: iterator it;
	vector <string>:: iterator it2;
	for(it = ID_vector.begin(); it != ID_vector.end(); ++it){
			if(*it == ID){
					checkID = true;
					pos = count;
					break;
			}
			count++;
	}
	
	
	for(it2 =Password_vector.begin(); it2 != Password_vector.end(); ++it2){
			if(*it2 == encoded){
					checkPassword = true;
					break;
			}
	}
	
	if(checkID == false){
		cout << "ID " << ID << " not found" << endl;
		return;
	}

	else if(checkPassword == false){
		cout << "wrong password" << endl;
		return;
	}
	
	else{
		int m=ID.length();
		ID_vector[pos].erase();
		Password_vector[pos].erase();
		Account_vector.erase(Account_vector.begin()+pos-1);
		vector <string>:: iterator it3;
		for(it3=IDs[m].begin();it3!=IDs[m].end();++it3)
		{
			if(*it3==ID)
			{
				IDs[m].erase(it3);
				break;
			}
		}
		cout << "success" << endl;
		nID--;
		return;
	}
}
void merge(const string& ID1,const string& password1,const string& ID2,const string& password2, vector <string>& ID_vector,vector <string>& Password_vector,vector <account>& Account_vector){
	bool checkID1 = false,checkPassword1 = false,checkID2 = false,checkPassword2 = false,checkChangedID = false;;
	string encoded1 = md5(password1);
	string encoded2 = md5(password2);
	int i,j,countID=0,countID1=0,countPassword=0,pos1,pos2,posChangedID,count=0,count1=0;
	vector <string>:: iterator it;
	vector <string>:: iterator it2;
	for(it=ID_vector.begin();it != ID_vector.end();++it){
			if(*it == ID1){
					checkID1 = true;
					pos1 = count;
					countID++;
			}
			if(*it == ID2){
					checkID2 = true;
					pos2 = count;
					countID++;
			}
			if(countID == 2){
				break;
				}
			count++;
	}
	for(it2=Password_vector.begin();it2 != Password_vector.end();++it2){
			if(*it2 == encoded1){
					checkPassword1 = true;
					countID1++;
			}
			if(*it2 == encoded2){
					checkPassword2 = true;
					countID1++;
			}
			if(countID1 == 2){
				break;
				}
	}
	if(checkID1 == false){
		cout << "ID " << ID1 << " not found" << endl;
		return;
	}
	else if(checkID2 == false){
		cout << "ID " << ID2 << " not found" << endl;
		return;
	}
	else if(checkPassword1 == false){
		cout << "wrong password1" << endl;
		return;
	}
	else if(checkPassword2 == false){
		cout << "wrong password2" << endl;
		return;
	}
	// add the money of ID2 to ID1
	Account_vector[pos1].balance += Account_vector[pos2].balance;

	//change others' transfer record about ID2
	list <Record>:: iterator its;
	list <Record>:: iterator its2;

	for(its=Account_vector[pos2].transfer_record.begin();its!=Account_vector[pos2].transfer_record.end();++its)
		{
			auto changeID = its->target_ID;
			
			vector <string>:: iterator it3;
			for(it3 = ID_vector.begin(); it3 != ID_vector.end(); ++it3){
			if(*it3 == changeID){
					checkChangedID = true;
					posChangedID = count1;
					break;
			}
				count1++;
			}
	}
			
			if(checkChangedID == true)
				for(its2=Account_vector[posChangedID].transfer_record.begin();its2!=Account_vector[posChangedID].transfer_record.end();++its2){
				
				if((*its2).timestamp == (*its).timestamp){
				
					(*its2).target_ID = ID1;
					break;
					}
				}
			

	//merge ID2's transfer record into ID1
	Account_vector[pos1].transfer_record.merge(Account_vector[pos2].transfer_record,compare);

	// delete ID2
	int m=ID2.length();
		ID_vector[pos2].erase();
		Password_vector[pos2].erase();
		Account_vector.erase(Account_vector.begin()+pos2-1);
		vector <string>:: iterator it4;
		for(it4=IDs[m].begin();it4!=IDs[m].end();++it4)
		{
			if(*it4==ID2)
			{
				IDs[m].erase(it4);
				break;
			}
		}
	

	cout << "success, " << ID1 <<" has " << Account_vector[pos1].balance <<" dollars" << endl;
	nID--;

	return;
}
//Function that are bound to last successful login
void transfer(const string& ID, unsigned long long int num , vector <string>& ID_vector,vector <account>& Account_vector , long long int timestamp){
	bool checkID = false;
	int pos1,pos2,countID=0,count=0;
	vector <string>:: iterator it;
	for(it=ID_vector.begin();it != ID_vector.end();++it){
			if(*it == ID){
					checkID = true;
					pos1 = count;
					countID++;
			}
			if(*it == last_successful_login_ID){
					pos2 = count;
					countID++;
			}
			count++;
			if(countID == 2){
				break;
			}
			
	}
	
	if(checkID == false){
		cout << "ID " << ID << " not found, " ;
		IDscore scores[nID];
		int x=0;
		for(int i=0;i<=100;i++)
		{
			vector <string> :: iterator it2;
			for(it2=IDs[i].begin();it2!=IDs[i].end();++it2)
			{
				string t=*it2;
				int mins=ID.length()<t.length()?ID.length():t.length();
				scores[x].ID=t;
				scores[x++].score=score_compute(ID,t,mins);
			}
		}
		sort(scores,scores+nID,cmp);
		max_recommand=nID>10?10:nID;
		for(int i=0;i<max_recommand;i++)
		{
			cout<<scores[i].ID;
			if(i!=max_recommand-1)cout<<",";
		}
		cout<<endl;
		return;
	}
	else if( Account_vector[pos2].balance < num ){
		cout << "fail, " << Account_vector[pos2].balance  << " dollars only in current account" << endl;
		return;
	}
	else{
		Account_vector[pos2].add_record(timestamp,false,ID,num);
		Account_vector[pos2].balance -= num;
		Account_vector[pos1].add_record(timestamp,true,last_successful_login_ID,num);
		Account_vector[pos1].balance += num;
		cout << "success, " << Account_vector[pos2].balance << " dollars left in current account" << endl;
		return;
	}


}

void find(string& s_wildcard,vector <string>& ID_vector){
	vector<string> tmp;
	vector <string>:: iterator it;
	for(it=ID_vector.begin();it != ID_vector.end();++it){
			if( match(s_wildcard.c_str(), (*it).c_str() ) )
			tmp.push_back(*it);
	}
	sort(tmp.begin(),tmp.end());

	stringstream ss;

	for(auto it2 = tmp.begin() ; it2!=tmp.end() ; it2++){ //	for(auto it = tmp.begin()+1 ; it!=tmp.end() ; ++it){
														 //	~~~~~~~~~~~~~~~~~~~~~~~~~~↑ ?
		if(*it2 != last_successful_login_ID)
			ss  << *it2 << "," ;
	}
	string ans;
	ss >> ans;
	ans[ans.length()-1] = '\0';
	cout << ans << endl;
	return;
}

void search(const string& ID,vector <string>& ID_vector,vector <account>& Account_vector){
	bool checkID = false;
	int i,pos2,countID=0,count=0;
	vector <string>:: iterator it;
	for(it=ID_vector.begin();it != ID_vector.end();++it){
			if(*it == ID){
					checkID = true;
					countID++;
			}
			if(*it == last_successful_login_ID){
					pos2 = count;
					countID++;
			}
			count++;
			if(countID == 2){
				break;
			}
	}
	if(checkID == false){
		cout << "no record" << endl;
		return;
		}
	if (Account_vector[pos2].transfer_record.empty() ){
		cout << "no record" << endl;
	  }
	else{
		Account_vector[pos2].printRecord(ID);
	}
	return;
}

//extend operation
void print_all_account(vector <string>& ID_vector){
	vector <string>:: iterator it;
	for(it = ID_vector.begin();it != ID_vector.end();++it){
		cout  << *it << endl;
	return;
	}
}

int main(){
	freopen("test_in_small.txt","r",stdin);
	long long int timestamp = 1;
	last_successful_login_ID.clear();
	IDs.clear();
	nID=0;
	vector <string>:: iterator it;
	vector <string>:: iterator it2;
	vector <string> ID_vector;
	ID_vector.clear();
	vector <string> Password_vector;
	Password_vector.clear();
	vector <account> Account_vector;
	Account_vector.clear();
	string cmd;
	while(cin >> cmd){
		//Operation that are not bound to last successful login
		if(cmd == "login"){
			string ID ,password;
			cin >> ID >> password;
			login(ID ,password,ID_vector,Password_vector);
		}
		if(cmd == "create"){
			string ID,password;
			cin >> ID >> password;
			create(ID,password,ID_vector,Password_vector,Account_vector);
		}
		if(cmd == "delete"){
			string ID,password;
			cin >> ID >> password;
			_delete(ID,password,ID_vector,Password_vector,Account_vector);
		}
		if(cmd == "merge"){
			string ID1,password1,ID2,password2;
			cin >> ID1 >> password1 >> ID2 >> password2;
			merge(ID1,password1,ID2,password2,ID_vector,Password_vector,Account_vector);
		}


		//Operation that are bound to last successful login

		//notice : maybe we can use iterator (while "login") than the global last_successful_login_ID
		// it may reduce the time cost in the finding
		if(cmd == "deposit" ){
			unsigned long long int num;
			cin >> num;
			int count = 0;
			for(it = ID_vector.begin();it != ID_vector.end();++it){
				if(*it == last_successful_login_ID){
					Account_vector[count].deposit(num);
					break;
			}
			count++;
			}
		}
		if(cmd == "withdraw"){
			unsigned long long int num;
			cin >> num;
			int count = 0;
			for(it2 = ID_vector.begin();it2 != ID_vector.end();++it2){
				if(*it2 == last_successful_login_ID){
					Account_vector[count].withdraw(num);
					break;
			}
			count++;
		}
		}
		if(cmd == "transfer"){
			string target_ID;
			unsigned long long int num;
			cin >> target_ID >> num;
			transfer( target_ID , num ,ID_vector,Account_vector,timestamp);
		}
		if(cmd == "find"){
			string s_wildcard;
			cin >> s_wildcard;
			find(s_wildcard,ID_vector);
		}
		if(cmd == "search"){
			string ID;
			cin >> ID;
			search(ID,ID_vector,Account_vector);
		}
		//extend option
		if(cmd == "print")
			print_all_account(ID_vector);
		if(cmd == "exit")
			break;

		//notice : that might have problem , because the time might be increase in transfer function
		//the time passby
		timestamp++;
	}
	return 0;

}