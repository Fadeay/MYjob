#include<iostream>
#include <cstdlib>
#include<string>
using namespace std;

class  chengji{
private:
	int KEY;
	string CH;
public:
	int getstr(){
		string ch;
		cout << "输入字符串:";
		cin >> ch;
		CH = ch;
	}

	int gcd(int a,int b) {
		    int t;
		        if (a < b) {
			        t = a;
			        a = b;
			        b = t;
			}
			while (t = a % b) {
			        a = b;
			        b = t;
			}
			return b;
	}

	int getkey(){
		int a;
		cout << "输入密钥:";
		cin >> a;
		if(gcd(a,26) != 1){
			cout << "此密钥无法使用！\n";
			exit(1);
		}
		KEY = a;		
	}

	int encrypt(){
		getkey();
		getstr();
		for(int i=0;i<CH.length();i++){
			CH[i] = int(CH[i]) - 97;
			CH[i] = KEY * CH[i] % 26;  
			CH[i] += 97; 
		}
		cout << "加密后的字符串为:" << CH << endl;
	}

	int decrypy(){
		getkey();
		getstr();
		for(int i=0;i<CH.length();i++){
			CH[i] = int(CH[i]) - 97;
			cout << int(CH[i]/KEY);
			CH[i] = CH[i] / KEY % 26;
			CH[i] += 97;
		}
		cout << "解密后的字符串为:" << CH << endl;
	}
};
int main(){
 	chengji a;
	int cho;
	cout << "加密：1\t解密：2\t:";
	cin >> cho;
	if(cho == 1){
		a.encrypt();
	} else {
		a.decrypy();
	}
	return 0;
}
