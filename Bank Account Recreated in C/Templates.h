#define MAX_RANGE 100
#define MIN_RANGE 0

//Structs
typedef struct DataPacket {
  double balance;
  double max_withdrawl;
  int numOfAccounts;
} Data;
typedef struct Account {
  char* user;
  char* pass;
  int accNum;
  Data * data_packet;
  //data - expand to have more complicated data stored as a struct.
  int requests;
  
  void (*fpoint) (struct Account * acc);
} Account;

typedef struct List {
  int size, index;
  Account * arr;
  void (*insert) (struct List * arr, Account value);
  void (*sort) (struct List * arr);
  Account* (*binarySearch) (struct List * arr, int l, int r, int targetNum);
} List;


//Function Prototypes
int recursiveMultiply(int x, int y);
Account* create(List* arr);
Account* login(List* arr);
void insertion(struct List * arr, Account value);
void sort(struct List * arr);
Account* binarySearch(struct List * arr, int l, int r, int targetNum);
void setRequests(struct Account * acc);
void settings(Account * access);
void clearBuffer();
