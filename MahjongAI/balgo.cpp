int HandCount[10][10]; 
int ColorCount[10];

void StatHand(){
	memset(HandCount,0,sizeof(int)*10*10);
	memset(ColorCount,0,sizeof(int)*10);
	for (vit it=Hand.begin();it!=Hand.end();it++){
		HandCount[it->color][it->number]++;
		ColorCount[it->color]++;
	}
}

bool TestHu(){
	bool haspair=false;
	if (TestSevenPairs() || TestThirteenHonors()) return true;
	for (int i=DONG;i<=BAI;i++){
		if (ColorCount[i]==1) return false;
		if (ColorCount[i]==2){
			if (haspair) return false;
			haspair=true;
		}
		if (ColorCount[i]==4) return false;
	}
	if (ColorCount[WAN]%3==2 && ColorCount[SUO]%3==0 && ColorCount[TONG]%3==0 && !haspair){
		return TestColor(WAN,1,1) && TestColor(SUO,1,0) && TestColor(TONG,1,0);
	}
	if (ColorCount[WAN]%3==0 && ColorCount[SUO]%3==2 && ColorCount[TONG]%3==0 && !haspair){
		return TestColor(WAN,1,0) && TestColor(SUO,1,1) && TestColor(TONG,1,0);
	}
	if (ColorCount[WAN]%3==0 && ColorCount[SUO]%3==0 && ColorCount[TONG]%3==2 && !haspair){
		return TestColor(WAN,1,0) && TestColor(SUO,1,0) && TestColor(TONG,1,1);
	}
	if (ColorCount[WAN]%3==0 && ColorCount[SUO]%3==0 && ColorCount[TONG]%3==0 && haspair){
		return TestColor(WAN,1,0) && TestColor(SUO,1,0) && TestColor(TONG,1,0);
	}
	return false;
}

bool TestSevenPairs(){
	int n=0;
	for (int i=DONG;i<BAI;i++){
		if (HandCount[i][0]%2==1) return false;
		n+=HandCount[i][0]/2;
	}
	for (int i=WAN;i<=TONG;i++){
		for (int j=1;j<=9;j++){
			if (HandCount[i][j]%2==1) return false;
			n+=HandCount[i][j]/2;
		}
	}
	return n==7;
} 

bool TestThirteenHonors(){
	if (HandCount[DONG][0]>=1 && HandCount[NAN][0]>=1 && HandCount[XI][0]>=1 && HandCount[BEI][0]>=1 && 
		HandCount[ZHONG][0]>=1 && HandCount[FA][0]>=1 && HandCount[BAI][0]>=1 &&
		HandCount[WAN][1]>=1 && HandCount[SUO][1]>=1 && HandCount[TONG][1]>=1 &&
		HandCount[WAN][9]>=1 && HandCount[SUO][9]>=1 && HandCount[TONG][9]>=1)
		return true;
	return false;
}

bool TestColor(int color, int ptr, bool pair){
	static bool flag;
	if (ptr==1) flag=false;
	if (flag) return false;
	if (ptr==10) {
		flag=true;
		return true;
	}
	if (flag) return true;
	if (HandCount[color][ptr]<0) return false;
	if (HandCount[color][ptr]==0) return TestColor(color,ptr+1,pair);
	bool ans=false;
	if (ptr<8){
		HandCount[color][ptr]--;HandCount[color][ptr+1]--;HandCount[color][ptr+2]--;
		ans = ans || TestColor(color,ptr,pair);
		HandCount[color][ptr]++;HandCount[color][ptr+1]++;HandCount[color][ptr+2]++;
	}
	HandCount[color][ptr]-=3;
	ans = ans || TestColor(color,ptr,pair);
	HandCount[color][ptr]+=3;
	if (pair){
		HandCount[color][ptr]-=2;
		ans = ans || TestColor(color,ptr,false);
		HandCount[color][ptr]+=2;
	}
	return ans;
}

