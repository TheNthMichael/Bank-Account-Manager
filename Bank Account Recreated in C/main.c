#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "templates.h"


//Prototypes

/*
LEARN TO USE HEADER AND SOURCE FILES Please :^)
  ----What do we need?----
    Account[ *user *pass *accnum *data] (Struct)
    List of accounts - AutoGrow/Insertion function
    Sort function
    Binary search

    Manager functions:
      -Create()
      -Delete()
      -Settings()
      -Login();
*/

//MAIN IS HERE ----------!

int main(void) {
  srand(time(0)); 
  Data dp = {0, 100, 1};
  //Account temp = {"user", "pass", 1022321, &dp, 0, setRequests};

  //List of accounts
  Account * arr = (Account *)malloc(sizeof(Account) * 3);
  //arr[0] = temp;
  //Initialize the List of accounts with their respective methods.
  List account_array = {3,0,arr,insertion, sort, binarySearch};
  Account * access;
  int user_ans = 1;

  do {
    puts("What would you like to do?");
    printf("1). Create an Account\n2). Login\n3). Language\n4). Quit\n");
    scanf("%d",&user_ans);
    clearBuffer();
    switch(user_ans) {
      case 1:
        access = create(&account_array);
        if(access != NULL)
          settings(access);
        else
          puts("Account Creation failed");
        access = NULL;
        break;
      case 2:
        access = login(&account_array);
        if(access != NULL)
          settings(access);
        else
          puts("Login failed");
        access = NULL;
        break;
      case 3:
        puts("yes");
        break;
      default:
        break;
    }
  } while(user_ans != 4);
  puts("Program closing...");
  return 0;
}

//Start Creating Layout functions
//Create -> impliments insertion
Account *create(List* arr) {
  /*The maximum number of characters in a char* in c must include the end of string operator. So there would  max number of characters needed +1*/
  int range = MAX_RANGE - MIN_RANGE + 1;
  int accNum = rand()%range + MIN_RANGE;
  char* user = (char*)malloc(sizeof(char) * 19);
  Account* temp;
  do {
    accNum = rand()%range + MIN_RANGE;
    temp = binarySearch(arr, 0, arr->size, accNum);
  } while(temp != NULL);
  puts("Enter a username:");
  scanf("%11s", user);
  puts("Enter a password:");
  char* pass = (char*)malloc(sizeof(char) * 19);
  scanf("%11s", pass);
  Data dp = {0, 100, 1};
  Data * pdp = malloc(sizeof(Data) * 1);
  *pdp = dp;  //Changes the value stored at address pdp = dp; This is allowed as we have allocated enough space for a Data_Packet struct.

  Account temp2 = {user, pass, accNum, pdp, 0, setRequests};
  arr->insert(arr, temp2);
  Account* pAcc = &temp2;
  arr->sort(arr);
  return pAcc;
}
//Login -> implements binary search
Account* login(List* arr) {
  puts("Enter Account Number:");
  int accNum;
  scanf("%d",&accNum);
  Account* temp = binarySearch(arr, 0, arr->index, accNum);
  if(temp == NULL)
    return NULL;
  char* username = (char*)malloc(sizeof(char) * 19);
  char* password = (char*)malloc(sizeof(char) * 19);
  puts("Enter your username");
  scanf("%19s", username);
  puts("Enter your password");
  scanf("%19s", password);
  if(strcmp(username, temp->user) == 0 && strcmp(password, temp->pass) == 0)
    return temp;
  else
    return NULL;
}

//Settings -> implements delete() :: Create delete function()