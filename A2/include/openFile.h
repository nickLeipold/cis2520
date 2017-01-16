#ifndef __NLEIPOLD_OPENFILE_H__
#define __NLEIPOLD_OPENFILE_H__

/* getFile
 * gets the location of a file
 * IN: nothing
 * OUT: a character array containing the file path
 * ERROR: no known errors
 * LIMITATIONS: filePath must be less than 256
 */
//not used in this program(created for later) void getFile(char * filePath);

/* openStream
 * opens a file stream and checks if it is created
 * IN: a character array path to a file
 * OUT: a file pointer for the file stream
 * ERROR: no known errors
 */
FILE * openStream(char * path);

/* closeStream
 * closes the file stream passed in if it exists
 * IN: file pointer to a stream
 * OUT: nothing
 * ERROR: no known errors
 */

void closeStream(FILE * streamPtr);

#endif
