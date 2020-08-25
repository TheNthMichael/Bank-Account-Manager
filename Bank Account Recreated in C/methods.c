#include "templates.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



int recursiveMultiply(int x, int y) {
  if(y == 0)
    return 0;
  return x + recursiveMultiply(x, y-1);
}

void insertion(struct List * arr, Account value) {
  if(arr -> index >= arr -> size) {
    Account * newArray = (Account*)malloc(arr->size * 2);
    arr->size = arr->size * 2;
    for(int i=0; i<arr->index; i++) {
      newArray[i] = arr->arr[i];
    }
    arr->index++;
    newArray[arr->index] = value;
    arr->arr = newArray;
    //puts("freed array");
    free(newArray);
  } else {
    arr->index++;
    arr->arr[arr->index] = value;
  }
}
void sort(struct List * arr) {
  for(int i=1; i<arr->index; i++) {
    for(int j=i; j>=0 && arr->arr[j-1].accNum > arr->arr[j].accNum; j--) {
      Account temp = arr->arr[j];
      arr->arr[j] = arr->arr[j-1];
      arr->arr[j-1] = temp;
    }
  }
}
//Must dereference result to access methods
Account* binarySearch(struct List * arr, int l, int r, int targetNum) {
  if(r >= l) {
    int mid = l + (r-l)/2;

    if(arr->arr[mid].accNum == targetNum) {
      Account* point = &(arr->arr[mid]);
      return point;
    }
    if(arr->arr[mid].accNum > targetNum)
      return binarySearch(arr, l, mid-1, targetNum);
    return binarySearch(arr, mid+1, r, targetNum);
  }
  
  return NULL;
}

void setRequests(struct Account * acc) {
  acc -> requests = 11;
}

void settings(Account * access) {
  printf("Welcome, %s\nYour account balance is %lf\nYour account number is %d\n", access->user, access->data_packet->balance, access->accNum);

  int user_ans = 1;
  do {
    puts("Please select the desired operation");
    printf("1). Withdraw\n2). Deposit\n3). View Balance\n4). Quit\n");
    scanf("%d",&user_ans);
    switch(user_ans) {
      case 1:
        puts("enter amount:");
        scanf("%d",&user_ans);
        if(user_ans <= access->data_packet->max_withdrawl && user_ans <= access->data_packet->balance) {
          access->data_packet->balance = access->data_packet->balance - user_ans;
          printf("You successfully withdrew $%d\n", user_ans);
        } else {
          printf("Withdrawl failed, ");
          printf(user_ans > access->data_packet->max_withdrawl? " requested amount is greater than the maximum allowed withdrawl...\n" : "insufficient funds\n");
        }
        break;
      case 2:
        puts("enter amount:");
        scanf("%d",&user_ans);
        if(user_ans >= 0) {
          access->data_packet->balance = access->data_packet->balance + user_ans;
          puts("Deposit successful");
        } else {
          puts("Deposit failed");
        }
        break;
      case 3:
        printf("Balance: %.2lf\n", access->data_packet->balance);
        break;
      case 4:
        break;
      default:
        break;
    }
  } while(user_ans != 4);
  puts("Logging you out");
}

void clearBuffer() {
  while(getchar() != '\n');
}