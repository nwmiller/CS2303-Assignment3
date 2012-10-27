/** file ctest.c
 * Program to demonstrate character arrays,
 * dynamically-allocated memory, structs,
 * and arrays of pointers to structs.
 *
 * @author Mike Ciaraldi
 * @author Nathaniel Miller
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "mystring.h"
#include "user.h"
#include "rand_funcs.h"

#define MAX_CHARS 20
#define ARR_CHAR 20
#define SIZE 20

int main()
{
  char a1[MAX_CHARS + 1]; // Character array--initially empty
  char a2[] = "Hello"; // Character array--unsized but initialized
  char a3[MAX_CHARS + 1]; // Character array--we will underfill it
  char* p1 = "Hello"; // Pointer to constant string
  char* p2;           // Will be a pointer to dynamically-allocated string

  /* character arrays for demonstration of rewritten functions */
  char a4[] = " Works!"; /* unsized char array, initialized */
  char a5[ARR_CHAR + 1] = { '\0' }; /* char array initialized empty */
  char a6[] = "Willkommen"; /* unsized char array, initialized */
  char a7[] = "Sir"; /* unsized char array, initialized */
  char a8[ARR_CHAR + 1] = { '\0' }; /* char array, empty */
  char a9[] = "Eleventh"; /* unsized char array, initialized */ 
  char a10[] = "Yes"; /* unsized char array, initialized */ 
  char* p3;

  srand(time(NULL)); /* call to srand() to seed random int/char generators */

  int copy_limit;     // Maximum characters to copy.

  strcpy(a3, "Hello, also"); // Initialize uinderfilled character array

  /* Print the pointers.
     Note: this example prints
     the values of the pointers themselves, not the targets.
  */
  printf("\nPointers: a1 = %p, a2 = %p, a3 = %p\n", a1, a2, a3);
  printf("          p1 = %p p2 = %p\n", p1, p2);
  
  printf("a1 = %s\n", a1);
  strcpy(a1, "Hi"); // Initialize character array

  printf("a1 = %s\n", a1);
  printf("a2 = %s\n", a2);
  printf("a3 = %s\n", a3);

  // Concatenate two character arrays, then print.
  strcat(a1, a2);
  printf("a1 = %s\n", a1);

  // Concatenate two character arrays safely, then print.
  copy_limit = MAX_CHARS - strlen(a1); // How much space is left?
  if (copy_limit > 0) strncat(a1, a2, copy_limit);
  printf("a1 = %s\n", a1);

  // Concatenate two character arrays safely, then print.
  copy_limit = MAX_CHARS - strlen(a1); // How much space is left?
  if (copy_limit > 0) strncat(a1, a3, copy_limit);
  printf("a1 = %s\n", a1);

  // Duplicate a string, using my function, then print
  printf("Before dup, pointer a2 = %p, contents = %s\n", a2, a2);
  p2 = mystrdup(a2);
  printf("Pointer p2 = %p, contents = %s\n", p2, p2);


  /* Demonstration section for rewritten standard string functions */
  
  printf("\nRewritten String Function Demonstrations:\n");

  /* demonstrate mystrlen, and print results to check if working properly */
  printf("\nMystrlen examples:");
  printf("\na2 = %s", a2);
  printf("\nThe length of the string a2 is: %d.", mystrlen(a2));

  printf("\na4 = %s", a4);
  printf("\nThe length of the string a4 is: %d.", mystrlen(a4));

  printf("\na6 = %s", a6);
  printf("\nThe length of the string a6 is: %d.\n", mystrlen(a6));

  /* demonstrate mystrcpy, and print results to check if func works */
  printf("\nMystrcpy example:");
  printf("\nBefore: a5 = %s\n", a5);
  mystrcpy(a5, "It");
  printf("Now: a5 = %s\n", a5);

  /* demonstrate mystrcat, print results to validate proper implementation */
  printf("\nMystrcat example:");
  printf("\nBefore: a5 = %s", a5);
  mystrcat(a5, a4);
  printf("\nNow: a5 = %s\n", a5);

  /* demonstrate mystrncat, print results to validate proper implementation */
  printf("\nMystrncat example:");
  printf("\nBefore: a7 = %s", a7);
  mystrncat(a7, a6, 5);
  printf("\nNow: a7 = %s\n", a7);

  /* demonstrate mystrncpy, print results to ensure working properly */
  printf("\nMystrncpy example:");
  printf("\nBefore: a8 = %s", a8);
  mystrncpy(a8, a9, 4);
  printf("\nNow: a8 = %s\n", a8);

  /* demonstrate mystrndup, print results to check if func works */
  printf("\nMystrndup example:");
  printf("\nBefore dup, pointer a10 = %p, contents = %s\n", a10, a10);
  p3 = mystrndup(a10, 2);
  printf("Pointer p3 = %p, contents = %s\n", p3, p3);

  
  /* struct tests & demonstrations */
  printf("\nStruct Creation & Function Demonstrations:\n");

  /*demonstrate make_user and print_stuct w/ defined vars are params */
  char un1[] = "John91";
  int j = 2010;
  int p = 1000;
  User* nu1; 
  nu1 = make_user( un1, j, p );
  printf("\nExample User Struct 1:\n");
  print_struct( nu1 );
 
  /* demonstrate make_user and print_struct w/o defined vars as params */
  printf("\nExample User Struct 2:\n");
  User* nu2;
  nu2 = make_user("Fedexico", 2009, 1359);
  print_struct( nu2 );

  /* demonstrate make_user/print_struct functions concisely */
  printf("\nExample User Struct 3:\n");
  print_struct(make_user("Anjunabeats", 2000, 9000));

  /* test random string and integer generator functions */
  //printf("\nRandom String & Integer Generation Tests:\n");
  //printf("String: %s\n", randFill());
  //printf("Integer: %d\n", randInt());
  
  /* call to generate and print a randomly generated User struct */
  printf("\nRandomly generated User struct:\n");
  print_struct(rand_struct());

  /* demonstrate count_array and print_array */
  printf("\nPointer Array & Array Printing Demonstrations:\n");

  /* test with separate calls, first generate array of ptrs to struct,
     then print the structs pointed to in the array */
  printf("Array of points to struct Test 1 (count = 4):\n");
  User** n1;
  n1 = count_array(4);
  print_array(n1, 4);
  
  /* test 2, more concise */
  printf("\nArray of pointers to struct Test 2 (count = 2):\n");
  print_array( count_array(2), 2 );

  /* demonstrate array duplication function */
  printf("\nPointer Array Duplication Test:\n");

  printf("\nOriginal Pointer Array, created with count_array:\n");
  User** n2;
  n2 = count_array(1);
  printf("Pointer n2 = %p\n", n2);
  printf("Pointer pointed to by n2 = %p\n", *n2);

  User** n3;
  n3 = dup_array( n2, 1 );
  printf("\nDuplicated Pointer Array, duplicated with dup_array:\n");
  printf("Pointer n3 = %p\n", n3);
  /*show the address of the pointer pointed to by n3 is the same as the
    address of the pointer pointed to by n2 */
  printf("Pointer pointed to by n3 = %p\n\n", *n3);

  /* demonstrate/use free_array function to free structs the arr points to */
  User** f1;
  f1 = count_array(2);
  free_array(f1, 2);
  
  return 0;
} /* end function main */
