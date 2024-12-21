#ifndef EDIT_H
#define EDIT_H
#include "type.h"

typedef struct  mp3_edit
{
    char title[50];
    char album[50];
    char year[8];
    char tag[3];
    char artist[50];
    char comment[50];
    unsigned char genre;

    /*source file*/
     
    char src_fname[30];
    char duplicate[30];
    FILE *fptr_src;
    char temp_file[50];
    FILE *ftemp;
}tag_edit;

/*checking for edit*/
operation_type check_operation_edit(char *argv[]);

/*read and validation */
Status read_validate_edit(char *argv[],tag_edit *tag);

/*open the file*/
Status file_open_edit(tag_edit *tag);

/*check for ID3*/
Status check_ID3_edit(tag_edit *tag);

/*check for edit*/
Status check_for_edit(char *argv[],tag_edit *tag);

/*check for type*/
Status edit_mp3(char *argv[],tag_edit *tag);

/*copy the header*/
Status copy_header(tag_edit *tag);

/*copy the remaining data*/
Status copy_remaining_data(tag_edit *tag);

/*covert to big endian*/
Status convert_to_big(int size);

/*to check the size of original file*/
Status size_of_original(tag_edit *tag);

/*covert to lit to big endian*/
Status convert_to_lit1(int size);

/*copy all type of data*/
Status copy_all_type(tag_edit *tag);

/*to make the temp as the original  */
Status file_open_to_transfer(tag_edit *tag);

/*to close the file */
Status file_close(tag_edit * tag);


#endif