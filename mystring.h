/** file mystring.h
 * @author Mike Ciaraldi
 * @author Nathaniel Miller
 *
 * My own versions of some of the C-style string functions
*/

#ifndef MYSTRING_H
#define MYSTRING_H

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup(const char* src);


/* function prototypes: rewritten standard string functions */

int mystrlen( const char *in_string );

char *mystrcpy( char *end, const char *origin );

char *mystrcat( char *end, const char *orig );

char *mystrncat( char *end, const char *orig, size_t s );

char *mystrncpy( char *end, const char *orig, size_t b );

char *mystrndup(const char *src, size_t c);

#endif
