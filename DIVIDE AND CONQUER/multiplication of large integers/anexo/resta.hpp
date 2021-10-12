#include <bits/stdc++.h>
#include <sstream>
using namespace std;

string normalizar(string x){
	reverse(x.begin(),x.end());
	while(int(x.size())>0 && x[int(x.size())-1]=='0')
		x.pop_back();
	reverse(x.begin(),x.end());
	return x;
}

string dif(string str1, string str2){
	str1=normalizar(str1);
	str2=normalizar(str2);
    if (str1.length() < str2.length())
        swap(str1, str2);
 
    string str = "";

    int n1 = str1.length(), n2 = str2.length();
 
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
 
    for (int i = 0; i < n2; i++) {
 
        int sub
            = ((str1[i] - '0') - (str2[i] - '0') - carry);

        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
     for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);
         if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
        str.push_back(sub + '0');
    }
 
    reverse(str.begin(), str.end());
 
    return str;
}
