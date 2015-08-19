int FirstPlayerID;
int RTiles[10][10];

void Initialize(){
	for (int i=WAN; i<=TONG; i++)
		for (int j=1;j<10;j++)
		RTiles[i][j]=4;
	
	for (int i=DONG; i<=BAI; i++)
		RTiles[i][0]=4;
}

void AppearTile(tile T){
	RTiles[T.color][T.number]--;
}

