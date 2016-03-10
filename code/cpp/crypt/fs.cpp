#include<iostream>
#include <cstdlib>
#include<string>
using namespace std;

class fangse{
private:
	int KEYA,KEYB;
	string CH;
public:
	int x, y;
	int getstr(){
		string ch;
		cout << "输入字符串:";
		cin >> ch;
		CH = ch;
	}

	int gcd(int a, int b) {
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

	int extend_eulid(int a, int b) {  
		if(b == 0) {  
			x = 1;  
			y = 0;  
		} else {  
			extend_eulid(b, a%b);  
			int temp = x;  
			x = y;  
			y = temp - a / b * y;  
		}  
	}  

	int get_inv(int a,int b) { //求A的乘法逆元  
		extend_eulid(a,b);  
		int inv = x;  
		if(inv < 0) inv += b;  
		return inv;  
	}  
	int getkey(){
		int a,b;
		cout << "输入密钥A:";
		cin >> a;
		cout << "输入密钥B:";
		cin >> b;
		if(gcd(a,b) != 1){
			cout << "密钥最大公约数应为1！\n";
			exit(1);
		}
		KEYA = a;		
		KEYB = b;		
	}

	int encrypt(){
		getkey();
		getstr();
		for(int i=0;i<CH.length();i++){
			CH[i] = int(CH[i]) - 97;
			CH[i] = (KEYA * CH[i] + KEYB) % 26;  
			CH[i] += 97; 
		}
		cout << "加密后的字符串为:" << CH << endl;
	}

	int decrypy(){
		getkey();
		getstr();
		KEYA = get_inv(KEYA,26);
		cout << KEYA;
		for(int i=0;i<CH.length();i++){
			CH[i] = int(CH[i]) - 97;
			cout << int(CH[i]) << endl;
			CH[i] = ((CH[i] - KEYB) * KEYA) % 26;
			cout << int(CH[i]) << endl;
			CH[i] += 97;
			cout << CH[i] << endl;
		}
		cout << "解密后的字符串为:" << CH << endl;
	}
};
int main(){
	fangse a;
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
