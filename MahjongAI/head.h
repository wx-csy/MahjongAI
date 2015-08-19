typedef pair<int,int> tile;
#define color first
#define number second

typedef vector<tile> tiles;
typedef vector<tile>::iterator vit;

#define WAN    0
#define SUO    1
#define TONG   2
#define DONG   3
#define NAN    4
#define XI     5
#define BEI    6
#define ZHONG  7
#define FA     8
#define BAI    9


tile LastAttemptChiAdd;

// util.cpp

bool IsNumber(int color);
bool IsHonor(int color);
tile MakeTile(int color, int value);
tile MakeTile(string str);
tile MakeTile(const char* str);
string Tile2Str(tile T);


// global.cpp

void Initialize(); 
void AppearTile(tile T);


// role.cpp

void Starting();
void Gaming();
int CountTile(tile T);
bool HasTriplet(tile T);
void AddTile(tile T);
void MoveTile(tile T);
void Out(tile T);
void Chi(tile T);
void Peng();
void Gang();
void JiaGang(tile T);
void AnGang(tile T);
void Pass();
void QiangGang();
void Hu();


// balgo.cpp

void StatHand();
bool TestHu();
bool TestColor(int color, int ptr, bool pair);


// algo.cpp

void Algo_Initialize();
void ActionAfterPick(tile T);
void ActionAfterMPick(tile T, bool canchi);
void DecideOut(tile T);
void DecideOut();
void TestQiangGang(tile T);
int EvaluateFunc(int color, int ptr, int _init);



