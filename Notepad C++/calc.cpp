#include <bits/stdc++.h>
using namespace std;

struct BinaryFunctor {
	virtual double operator()(double a, double b){
		return 0;
	}
};

class Ops {
public:
	struct Mul : BinaryFunctor {
		double operator()(double a, double b){
			return a * b;
		}
	};
	
	struct Add : BinaryFunctor {
		double operator()(double a, double b){
			return a + b;
		}
	};
	
	struct Sub : BinaryFunctor {
		double operator()(double a, double b){
			return a - b;
		}
	};
	
	struct Div : BinaryFunctor {
		double operator()(double a, double b){
			return a / b;
		}
	};
	
	struct Exp : BinaryFunctor {
		double operator()(double a, double b){
			return pow(a,b);
		}
	};
};


int main() {
	map<char,unique_ptr<BinaryFunctor>> mp;
	mp['+'] = unique_ptr<BinaryFunctor>(new Ops::Add());
	mp['-'] = unique_ptr<BinaryFunctor>(new Ops::Sub());
	mp['*'] = unique_ptr<BinaryFunctor>(new Ops::Mul());
	mp['/'] = unique_ptr<BinaryFunctor>(new Ops::Div());
	mp['^'] = unique_ptr<BinaryFunctor>(new Ops::Exp());
	
	string s;
	cin >> s;
	
	string pattern = "[\\+\\-\\*\\^\\/]";
	regex rgx(pattern);
	smatch m;
	regex_search(s, m, rgx);
	
	int pos = m.position();
	
	// input satination is not the main focus of this example, so this just handles the case of the first number being negative. adding other unexpected operators will result in an error.
	if(pos == 0){
		string t = s.substr(1);
		regex_search(t, m, rgx); 
		pos = m.position()+1;
	}
	
	if(pos < s.length() && pos < s.length()-1){
		double x = stod(s.substr(0, pos));
		double y = stod(s.substr(pos+1));
		char op = s[pos];
		
		cout << (*(mp[op]))(x,y) << endl;
	}else{
		cout << "invalid, no operator/operands" << endl;
	}
}