#include <bits/stdc++.h>
#include <sstream>
#include "anexo/suma.hpp"
#include "anexo/resta.hpp"
using namespace std;
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
#define raya do {cerr << "===========================" << endl; } while (false)
#define convertToString(x) #x

string IntToString(int a)
{
    ostringstream temp;
    temp << a;
    return temp.str();
}

int convertir(char s){
	int i = s - 48; // i es ahora igual a 1, no '1'
	return i;
}

string s1,s2;
pair<string,string> particion(string x,int mid){
	int l=x.size();
	s1=x.substr(0,mid);
	s2=x.substr(mid,l-mid);
	return {s1,s2};
}

string producto(string n1,string n2){
	int num1=convertir(n1[0]);
	int num2=convertir(n2[0]);
	int num=num1*num2;
	string s = IntToString(num);
	return s;
}

string desplazar(string n,int move){
	string ret=n;
	for(int i=0;i<move;i++)
		ret+="0";
	return ret;	
}

string merge(string n1,string n2){
	int l1=n1.size();
	int l2=n2.size();
	if(l1==0 || l2==0)return "";
	if((l1==1 && n1[0]=='0') || (l2==1 && n2[0]=='0'))
		return "";

	if(l1==1 && l2==1)
		return producto(n1,n2);
	
	if(l2>l1)swap(n1,n2),swap(l1,l2);
	
	int mi=l1/2;
	pair<string,string>ret1,ret2;

	ret1=particion(n1,mi);
	
	int back = l1-mi;
	int front = l2-back;
	
	if(front<=0){
		ret2.first="";
		ret2.second=n2;
	}
	else ret2=particion(n2,front);
	
	string A=merge(ret1.first,ret2.first);
	string B=merge(ret1.second,ret2.second);
	string C=merge(sum(ret1.first,ret1.second),sum(ret2.first,ret2.second));

	string a=desplazar(A,back*2);
	string b=desplazar(dif(dif(C,A),B),back);
	string c=B;
	
	return sum(sum(a,b),c);
}

int main(){
	string num1,num2;
	cout<<"Digite primer numero : ";cin>>num1;
	cout<<"DIgite segundo numero : ";cin>>num2;
	string producto=merge(num1,num2);
	dbg(producto);
}
