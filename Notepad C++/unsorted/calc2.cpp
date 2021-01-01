#include <bits/stdc++.h>
using namespace std;

int main(){
	map<string, function<double(double,double)>> bins;
	map<string, function<double(double)>> unas;
	bins["+"] = plus<double>();
	bins["-"] = minus<double>();
	bins["*"] = multiplies<double>();
	bins["/"] = divides<double>();
}