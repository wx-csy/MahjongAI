
bool IsNumber(int color){
	return color>=0 && color<=2;
} 

bool IsHonor(int color){
	return color>=3 && color<=9;
}

tile MakeTile(int color, int value){
	return make_pair<int,int>(color,value);
}

tile MakeTile(string str){
	return MakeTile(str.c_str());
}

tile MakeTile(const char* str){
	tile new_tile;
	if (str[0]=='E'){
		new_tile.color=DONG;
		new_tile.number=0;
	} else if (str[0]=='S'){
		new_tile.color=NAN;
		new_tile.number=0;
	} else if (str[0]=='W'){
		new_tile.color=XI;
		new_tile.number=0;
	} else if (str[0]=='N'){
		new_tile.color=BEI;
		new_tile.number=0;
	} else if (str[0]=='Z'){
		new_tile.color=ZHONG;
		new_tile.number=0;
	} else if (str[0]=='F'){
		new_tile.color=FA;
		new_tile.number=0;
	} else if (str[0]=='B'){
		new_tile.color=BAI;
		new_tile.number=0;
	} else {
		if (str[1]=='M') new_tile.color=WAN;
		if (str[1]=='S') new_tile.color=SUO;
		if (str[1]=='T') new_tile.color=TONG;
		new_tile.number=str[0]-'0';
	}
	return new_tile;
}

string Tile2Str(tile T){
	string newstr;
	char s[3]={0,0,0};
	if (T.color==DONG)   s[0]='E';
	if (T.color==NAN)    s[0]='S';
	if (T.color==XI)     s[0]='W';
	if (T.color==BEI)    s[0]='N';
	if (T.color==ZHONG)  s[0]='Z';
	if (T.color==FA)     s[0]='F';
	if (T.color==BAI)    s[0]='B';
	if (T.color==WAN){
		s[1]='M';
		s[0]='0'+T.number;
	}
	if (T.color==SUO){
		s[1]='S';
		s[0]='0'+T.number;
	}
	if (T.color==TONG){
		s[1]='T';
		s[0]='0'+T.number;
	}
	newstr=s;
	return newstr;
}

