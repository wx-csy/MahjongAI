int ID;

tiles Hand;
tiles Triplets;

void Starting(){
	string str;
	
	cout<<"join"<<endl;
	
	cin>>str>>ID;
	assert(str=="id"); 
	cerr<<"id="<<ID<<"; ";
	
	cin>>str>>FirstPlayerID;
	assert(str=="first");
	cerr<<"first="<<FirstPlayerID<<endl;
	
	cin>>str;
	assert(str=="init");
	for (int i=0;i<13;i++){
		cin>>str;
		cerr<<str<<" ";
		Hand.push_back(MakeTile(str));
		AppearTile(MakeTile(str));
	}
	cerr<<endl;
	
	Algo_Initialize();
	cerr<<"Start OK!"<<endl; 
}

void Gaming(){
	string str;
	string ntile;
	tile T;
	int a,b,c;
	while(true){
		cin>>str;
		if (str=="pick"){
			cin>>ntile;
			T=MakeTile(ntile);
			AppearTile(T);
			Hand.push_back(T);
			ActionAfterPick(T);
		}
		if (str=="mpick"){
			cin>>a;
		}
		if (str=="mout"){
			cin>>a>>ntile;
			AppearTile(MakeTile(ntile));
			ActionAfterMPick(MakeTile(ntile),(ID-a+100)%4==1);
		}
		if (str=="mchi"){
			cin>>a>>ntile;
			T=MakeTile(ntile);
			if (a==ID) MoveTile(T); else AppearTile(T);
			T.number++;
			if (a==ID) MoveTile(T); else AppearTile(T);
			T.number++;
			if (a==ID) MoveTile(T); else AppearTile(T);
			if (a==ID) DecideOut();
		}
		if (str=="mpeng"){
			cin>>a>>ntile;
			T=MakeTile(ntile);
			if (a==ID) {
				MoveTile(T);MoveTile(T);MoveTile(T);
				Triplets.push_back(T);
				DecideOut();
			} else {
				AppearTile(T);AppearTile(T);AppearTile(T);
			}
		}
		if (str=="mgang"){
			cin>>a>>ntile;
			T=MakeTile(ntile);
			if (a==ID) {
				MoveTile(T);MoveTile(T);MoveTile(T);MoveTile(T);
				Triplets.push_back(T);
			} else {
				AppearTile(T);AppearTile(T);AppearTile(T);AppearTile(T);
			}
		}
		if (str=="magang"){
			cin>>a;
			if (a==ID){
				MoveTile(T);MoveTile(T);MoveTile(T);MoveTile(T);
				Triplets.push_back(T);
			}
		}
		if (str=="mjgang"){
			cin>>a>>ntile;
			if (a==ID){
				MoveTile(MakeTile(ntile));
			} else {
				AppearTile(MakeTile(ntile));
			}
			TestQiangGang(MakeTile(ntile));
		}
		if (str=="mhu"){
			cin>>a>>b>>c;
			cerr<<"Winner="<<a<<"; Loser="<<b<<"; Score="<<c<<endl;
			break;
		}
		if (str=="mfail"){
			MoveTile(LastAttemptChiAdd);
		}
		sort(Hand.begin(),Hand.end());
		for (vit it=Hand.begin();it!=Hand.end();it++){
			cerr<<Tile2Str(*it)<<" ";
		}
		cerr<<endl;
	}
}

int CountTile(tile T){
	int result=0;
	for (vit it=Hand.begin();it!=Hand.end();it++){
		if (*it==T) result++;
	}
	return result;
}

bool HasTriplet(tile T){
	for (vit it=Triplets.begin();it!=Triplets.end();it++)
		if (*it==T) return true;
	return false;
}

void AddTile(tile T){
	Hand.push_back(T);
}

void MoveTile(tile T){
	for (vit it=Hand.begin();it!=Hand.end();it++)
		if (*it==T) {
			Hand.erase(it);
			return;
		}
}

void Out(tile T){
	cout<<"out "<<Tile2Str(T)<<endl;
	MoveTile(T);
}

void Chi(tile T){
	cout<<"chi "<<Tile2Str(T)<<endl;
} 

void Peng(){
	cout<<"peng"<<endl;
} 

void Gang(){
	cout<<"gang"<<endl;
}

void JiaGang(tile T){
	cout<<"jgang "<<Tile2Str(T)<<endl;
}

void AnGang(tile T){
	cout<<"agang "<<Tile2Str(T)<<endl;
}

void Pass(){
	cout<<"pass"<<endl;
}

void QiangGang(){
	cout<<"qgang"<<endl;
}

void Hu(){
	cout<<"hu"<<endl;
}

