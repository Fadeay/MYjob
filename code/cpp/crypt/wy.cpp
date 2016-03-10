#include<iostream>
#include<string>
using namespace std;

class weiyi{
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

	int getkey(){
		int a;
		cout << "输入密钥:";
		cin >> a;
		KEY = a;		
	}

	int encrypt(){
		getkey();
		getstr();
		for(int i=0;i<CH.length();i++){
			CH[i] = int(CH[i]) - 97;
			CH[i] = (CH[i] + KEY) % 26;  
			CH[i] += 97; 
		}
		cout << "加密后的字符串为:" << CH << endl;
	}

	int decrypy(){
		getkey();
		getstr();
		for(int i=0;i<CH.length();i++){
			CH[i] = int(CH[i]) - 97;
			CH[i] = (CH[i] - KEY) % 26;
			CH[i] += 97;
		}
		cout << "解密后的字符串为:" << CH << endl;
	}
};
int main(){
	weiyi a;
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
