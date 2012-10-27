/** file mystring.c
 * @author Mike Ciaraldi
 * @author Nathaniel Miller
 *
 * Custom versions of some of the C-style string functions
 */

#include <string.h>
#include <stdlib.h>
#include "mystring.h"

char* mystrdup(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen(src) + 1;  // Leave space for null char, using  mystrlen
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  mystrcpy(newstr, src); /* uses mystrcpy to copy the string */

  return newstr; /* pointer to newly duplicated string */
} /* end function mystrdup */


/** Determines the length of the string, not counting
 * the '\0' terminating character at the end.
 *
 * @param *in_string The string (char array) whose length will be calculated.
 *
 * @return j The length of the string.
 */

int mystrlen( const char *in_string ) {

  int j = 0; /* loop counter */
  char* s = (char*) in_string; /* pointer to base of the character array */

  /* loop until the value of the array is the terminating character */
  for ( j = 0; *s != '\0'; j++) {
    s++; /* advance to next element */
  } /* end for */

  return j; /* return the length of the string */
} /* end function mystrlen */


/** Copies a string from a given source to a given destination.
 *
 * @param *end The destination location of the string being copied.
 * @param *origin The source location of the string being copied.
 */

char *mystrcpy( char *end, const char *origin ) {
  
  char *x = end; /* pointer to base ele of the destination string */

  /* loop until terminating character in source string is reached */
  for ( ; *origin != '\0'; ) {
    *(x++) = *(origin++); /* replace destination with source */
  } /* end for */

  *x = '\0'; /* add the terminating character to the end */
} /* end function mystrcpy */
  

/** Appends a string from a given source to a given destination,
 * and writes over the terminating character on the end of the destination
 * string.
 *
 * @param *end The destination location of the string to be added to.
 * @param *orig The source location of the string to be appended onto the dest.
 *
 * @return end The pointer to the destination string.
 */

char *mystrcat( char *end, const char *orig ) {
  
  int end_len = strlen(end); /* length of the destination string */
  int a; /* loop counter */

  /* loop until null terminating character is reached in the source string */
  for( a = 0; orig[a] != '\0'; a++ ) {
    end[end_len + a] = orig[a]; /* append src string to end of dest string */
  } /* end for */

  end[end_len + a] = '\0'; /* add the null terminating character */

  return end; /* return a pointer to the destination string */
} /* end function mystrcat */

    
/** Appends a string from a give source to a given destination,
 * using only at most c characters from the souce. Ends with the
 * terminating character.
 *
 * @param *end The destination array to be added to.
 * @param *orig The source char array to be appended to the destination string.
 * @param s The amount of characters to be used from the source string.
 *
 * @return end The pointer to the destination string.
 */

char *mystrncat( char *end, const char *orig, size_t c ) {
  
  int end_len = mystrlen(end); /* length of the destination string */
  int i; /* loop counter */
  
  /* loop until the amount of characters to be used is reached */
  for( i = 0; i < c && orig[i] != '\0'; i++ ) {
    end[end_len + i] = orig[i]; /* append s characters of source to dest */
  } /* end for */

  end[end_len + i] = '\0'; /* add the null terminating character */

  return end; /* return a pointer to the destination string */
} /* end function mystrncat */


/** Copies b bytes of the string inside the source array
 * to the destination character array. Does not null terminate
 * if null byte exists in b bytes of the source string.
 * Pads destination with null bytes if len of source is less than b bytes.
 *
 * @param *end The destination char array to be copied to.
 * @param *orig The source char array of which b bytes will be copied.
 * @param b The number of bytes to copied from the source.
 *
 * @return x The pointer to the destination string.
 */

char *mystrncpy( char *end, const char *orig, size_t b ) {
  
  char *x = end; /* pointer to base ele of the destination string */
  int i; /* loop counter */

  /* loop until the number of bytes to be copied is reached */
  for( i = 0; orig[i] != '\0' && orig[i] > b; ) {
    *(x++) = *(orig++); /* replace destination with source */
    i++; /* advance to next element */
  } /* end while */

  /* pad unfilled dest with null characters */
  while( i < mystrlen(end) ) {
    *(x++) = '\0'; /* add the terminating character to the end */
    i++; /* advance to next element */
  } /* end while */
  *x = '\0';

  return (char *) x; /* return a pointer to the dest string */
} /* end function mystrncpy */


/** Duplicates the source string, but only c characters
 * of the source string are duplicated. Memory for new string
 * is allocated using malloc. Null terminated if source string
 * is longer than c.
 *
 * @param *src The source char array to be duplicated.
 * @param c The number of characters to be duplicated from the source string.
 *
 * @return dupstr The pointer to the duplicated string.
 */

char *mystrndup(const char *src, size_t c) {
  size_t length; /* length of source string */
  char *dupstr; /* pointer to memory to hold duplicated string */

  length = mystrlen(src);  /* set length as lenth of source string */
  
  /* set length to the number of chars to be duplicated if length is longer than c */
  if( c < length) {
    length = c;
  } /* end if */
  dupstr = (char*) malloc(length + 1); /* allocate mem for dupstr w/ malloc +1 for null char */

  /* check if no memory is available, if so, return right away */
  if (dupstr == 0) {
    return (char *) 0;
  } /* end if */

  mystrncpy(dupstr, src, c); /* use mystrncpy to copy the string */
  dupstr[length] = '\0'; /* add the null terminating character to end */

  return (char *) dupstr; /* return pointer to the duplicated new string */
} /* end function mystrndup */
