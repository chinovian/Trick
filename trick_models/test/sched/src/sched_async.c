/********************************* TRICK HEADER *******************************
PURPOSE:                     ( Test scheduling )
REFERENCE:                   ( None ) 
ASSUMPTIONS AND LIMITATIONS: ( None )
CLASS:                       ( asynchronous )
LIBRARY DEPENDENCY:          ( sched_async.o )
PROGRAMMERS:                 ( (Keith Vetter) (Titan) (8-20-2002) )
*******************************************************************************/

/*
 * $Log: sched_async.c,v $
 * Revision 5.1  2004-08-05 13:06:58-05  lin
 * Bump
 *
 * Revision 4.1  2003/10/21 21:49:13  lin
 * Bump version number for 04
 *
 * Revision 1.4  2002/10/07 15:16:30  lin
 * Add rcs version info to all trick_models files
 *
 */
 
#include "../include/sched.h"

int sched_async (
                  /* RETURN: -- Always return zero */
  SCHEDULE *S )   /* INOUT:  -- Schedule struct */
{

   while ( 1 ) {
      /* Try and hang the sim... */
      usleep(1000000) ;
   }

   return( 0 );
}
