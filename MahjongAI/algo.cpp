int ColorValue13[3];


void Algo_Initialize(){
	StatHand();
	for (int i=WAN;i<=TONG;i++)
		ColorValue13[i]=EvaluateFunc(i,0,0);
}

//decide which one to out or hu
void ActionAfterPick(tile T){
	StatHand();
	if (TestHu()){
		Hu();
		return ;
	}
	
	if (IsHonor(T.color)){
		if (HandCount[T.color][0]==1){
			Out(T);
			return;
		}
		if (HandCount[T.color][0]==2){
			DecideOut();
			return;
		}
		if (HandCount[T.color][0]==3){
			DecideOut();
			return;
		}
		if (HandCount[T.color][0]==4){
			AnGang(T);
			return;
		}
	}
	
	DecideOut(T);
}

// decide action to take after one giving out a tile
void ActionAfterMPick(tile T, bool canchi){
	Hand.push_back(T);
	StatHand();
	if (TestHu()){
		Hu();
		return ;
	}
	Hand.pop_back(); 
	
	if (IsHonor(T.color)){
		if (HandCount[T.color][0]==3){
			Peng();
			return;
		}
		if (HandCount[T.color][0]==4){
			Gang();
			return;
		}
	}

	int action=0;
	tile obj, nextt, temp;
	int md=0;
	int delta;
	if (CountTile(T)>=2){
		HandCount[T.color][T.number]-=3;
		MoveTile(T);MoveTile(T);
		delta=EvaluateFunc(WAN,0,0)+EvaluateFunc(SUO,0,0)+EvaluateFunc(TONG,0,0)+40-
			  (ColorValue13[0]+ColorValue13[1]+ColorValue13[2]);
		if (delta>0) {
			action=1;
			obj=T;
			md=delta;
		}
		AddTile(T);AddTile(T);
		HandCount[T.color][T.number]+=3;
	}
	
	if (CountTile(T)>=3){
		HandCount[T.color][T.number]-=4;
		MoveTile(T);MoveTile(T);MoveTile(T);
		delta=EvaluateFunc(T.color,0,-ColorValue13[T.color])+44;
		if (delta>md){
			action=2;
			obj=T;
			md=delta;
		}
		AddTile(T);AddTile(T);AddTile(T);
		HandCount[T.color][T.number]+=4;
	}
	
	if (canchi){
		if (CountTile(MakeTile(T.color,T.number+1))>=1 && 
			CountTile(MakeTile(T.color,T.number+2))>=1){
			HandCount[T.color][T.number]--;
			HandCount[T.color][T.number+1]--;
			HandCount[T.color][T.number+2]--;
			MoveTile(MakeTile(T.color,T.number+1));
			MoveTile(MakeTile(T.color,T.number+2));
			delta=EvaluateFunc(WAN,0,0)+EvaluateFunc(SUO,0,0)+EvaluateFunc(TONG,0,0)+36-
				  (ColorValue13[0]+ColorValue13[1]+ColorValue13[2]);
			if (delta>md) {
				action=3;
				obj=T;
				md=delta;
			}
			AddTile(MakeTile(T.color,T.number+1));
			AddTile(MakeTile(T.color,T.number+2));
			HandCount[T.color][T.number]++;
			HandCount[T.color][T.number+1]++;
			HandCount[T.color][T.number+2]++;
		}
		if (CountTile(MakeTile(T.color,T.number-1))>=1 && 
			CountTile(MakeTile(T.color,T.number+1))>=1){
			HandCount[T.color][T.number-1]--;
			HandCount[T.color][T.number]--;
			HandCount[T.color][T.number+1]--;
			MoveTile(MakeTile(T.color,T.number-1));
			MoveTile(MakeTile(T.color,T.number+1));
			delta=EvaluateFunc(WAN,0,0)+EvaluateFunc(SUO,0,0)+EvaluateFunc(TONG,0,0)+36-
				  (ColorValue13[0]+ColorValue13[1]+ColorValue13[2]);
			if (delta>md) {
				action=3;
				obj=MakeTile(T.color,T.number-1);
				md=delta;
			}
			AddTile(MakeTile(T.color,T.number+1));
			AddTile(MakeTile(T.color,T.number-1));
			HandCount[T.color][T.number-1]++;
			HandCount[T.color][T.number]++;
			HandCount[T.color][T.number+1]++;
		}
		if (CountTile(MakeTile(T.color,T.number-1))>=1 && 
			CountTile(MakeTile(T.color,T.number-2))>=1){
			HandCount[T.color][T.number-2]--;
			HandCount[T.color][T.number-1]--;
			HandCount[T.color][T.number]--;
			MoveTile(MakeTile(T.color,T.number-2));
			MoveTile(MakeTile(T.color,T.number-1));
			delta=EvaluateFunc(WAN,0,0)+EvaluateFunc(SUO,0,0)+EvaluateFunc(TONG,0,0)+36-
				  (ColorValue13[0]+ColorValue13[1]+ColorValue13[2]);
			if (delta>md) {
				action=3;
				obj=MakeTile(T.color,T.number-2);
				md=delta;
			}
			AddTile(MakeTile(T.color,T.number-1));
			AddTile(MakeTile(T.color,T.number-2));
			HandCount[T.color][T.number-2]++;
			HandCount[T.color][T.number-1]++;
			HandCount[T.color][T.number]++;
		}
	}
	
	if (action==1){
		AddTile(T);
		Peng();
	}  
	if (action==2){
		AddTile(T);
		Gang();
	}
	if (action==3){
		AddTile(T);
		LastAttemptChiAdd=T;
		Chi(obj);
		Algo_Initialize();
	}
	if (action !=1 && action !=2 && action!=3){
		Pass();
	}
	
}

// decide which tile to cut
void DecideOut(tile T){
	// decide honor to cut;
	int minx=10,id;
	for (int i=DONG;i<=BAI;i++){
		if (HandCount[i][0]==1){
			if (minx>RTiles[i][0]){
				minx=RTiles[i][0];
				id=i;
			}
		}
	}
	if (minx<10){
		Out(MakeTile(id,0));
		return;
	}
	//
	
	Algo_Initialize();
	int maxdelta=-1000, delta;
	tile temp, maxtile;
	for (vit it=Hand.begin();it!=Hand.end();it++){
		temp=*it;
		if (IsHonor(temp.color)) continue;
		HandCount[temp.color][temp.number]-=1;
		delta=EvaluateFunc(temp.color,0,-ColorValue13[temp.color]);
		HandCount[temp.color][temp.number]+=1;
		if (delta>maxdelta){
			maxtile=temp;
			maxdelta=delta;
		}
	}
	if (maxdelta<=-1000) maxtile=T;
	
	int d1;
	if (CountTile(T)==4){
		HandCount[temp.color][temp.number]-=4;
		d1=EvaluateFunc(temp.color,0,44-ColorValue13[temp.color]);
		HandCount[temp.color][temp.number]+=4;
		if (d1>maxdelta) {
			AnGang(T);
			return;
		}
	}
	if (HasTriplet(T)){
		HandCount[temp.color][temp.number]--;
		d1=EvaluateFunc(temp.color,0,4-ColorValue13[temp.color]);
		HandCount[temp.color][temp.number]++;
		if (d1>maxdelta){
			JiaGang(T);
			return;
		}
	}

	Out(maxtile);
}

// decide which tile to cut
void DecideOut(){
	// decide honor to cut;
	int minx=10,id;
	for (int i=DONG;i<=BAI;i++){
		if (HandCount[i][0]==1){
			if (minx>RTiles[i][0]){
				minx=RTiles[i][0];
				id=i;
			}
		}
	}
	if (minx<10){
		Out(MakeTile(id,0));
		return;
	}
	//
	
	Algo_Initialize();
	int maxdelta=0, delta;
	tile temp, maxtile;
	for (vit it=Hand.begin();it!=Hand.end();it++){
		temp=*it;
		if (IsHonor(temp.color)) continue;
		HandCount[temp.color][temp.number]-=1;
		delta=EvaluateFunc(temp.color,0,-ColorValue13[temp.color]);
		HandCount[temp.color][temp.number]+=1;
		if (delta>maxdelta){
			maxtile=temp;
			maxdelta=delta;
		}
	}
	if (maxdelta<=0) maxtile=*Hand.begin();

	Out(maxtile);
}


// decide whether to qianggang
void TestQiangGang(tile T){
	Hand.push_back(T);
	StatHand();
	if (TestHu()){
		QiangGang();
		return ;
	} else{
		Pass();
	} 
	Hand.pop_back(); 
}


int maxv;
int EvaluateFunc(int color, int ptr, int _init=0){
	if (ptr==0) maxv=_init;
	if (ptr==10) {
		if (_init>maxv)	maxv=_init;
		return 0;
	} 
	if (HandCount[color][ptr]<0) return 0;
	if (HandCount[color][ptr]==0) EvaluateFunc(color, ptr+1, _init);
	else{
		// triplet
		HandCount[color][ptr]-=3;
		EvaluateFunc(color, ptr, _init+40);
		HandCount[color][ptr]+=3;
	
		// sequence
		if (ptr<8){
			HandCount[color][ptr]--;HandCount[color][ptr+1]--;HandCount[color][ptr+2]--;
			EvaluateFunc(color, ptr, _init+36);
			HandCount[color][ptr]++;HandCount[color][ptr+1]++;HandCount[color][ptr+2]++;
		}
	
		// pair
		HandCount[color][ptr]-=2;
		EvaluateFunc(color, ptr, _init+6+RTiles[color][ptr]);
		HandCount[color][ptr]+=2;
	
		// semi-seq
		if (ptr<9){
			HandCount[color][ptr]--;HandCount[color][ptr+1]--;
			EvaluateFunc(color, ptr, _init+2+RTiles[color][ptr-1]*2+RTiles[color][ptr+2]*2);
			HandCount[color][ptr]++;HandCount[color][ptr+1]++;
		}
	
		// ridge-seq
		if (ptr<8){
			HandCount[color][ptr]--;HandCount[color][ptr+2]--;
			EvaluateFunc(color, ptr, _init+2+RTiles[color][ptr+1]*2);
			HandCount[color][ptr]++;HandCount[color][ptr+2]++;
		}
	
		// single
		HandCount[color][ptr]--;
		EvaluateFunc(color, ptr, _init+RTiles[color][ptr+1]-6);
		HandCount[color][ptr]++;
	}
	return maxv;
}


