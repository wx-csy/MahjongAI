#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cctype>
#include <cassert> 
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

#include "head.h" 
#include "util.cpp"
#include "global.cpp"
#include "role.cpp"
#include "balgo.cpp"
#include "algo.cpp"


int main(){
	freopen("csy_12.log","w",stderr);
	cerr<<"Player:  Shaoyuan CHEN"<<endl;
	cerr<<"Version: V 1.2 alpha"<<endl;
	cerr<<"Author:  wx-csy"<<endl;
	cerr<<endl;
	
	Initialize();
	Starting();
	Gaming();
	
	return 0;
}



