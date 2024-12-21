
#ifndef VIEW_H
#define VIEW_H
#include "type.h"

typedef struct  mp3
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
    FILE *fptr_src;
}tag_view;


/*check operation*/
operation_type check_operation(char *argv[]);

/*read and validation */
Status read_validate(char *argv[],tag_view *view1);

/*open the file*/
Status file_open(tag_view *tag);

/*check for ID3*/
Status check_ID3(tag_view *id3);

/*for converting big endian to little endian*/
Status convert_to_lit(int x);

/*view the mp3 */
Status reading_mp3(tag_view *tag);

/*reading tag name*/
int reading_tag(tag_view *tag,char *data);

/*reading the title */
Status reading_title(tag_view *tag);

/*reading  data of artist*/
Status reading_artist(tag_view *tag);

/*reading data of album*/
Status reading_album(tag_view *tag);

/*reading data of year*/
Status reading_year(tag_view *tag);

/*reading data of content*/
Status reading_content(tag_view *tag);

/*reading data of composer*/
Status reading_composer(tag_view *tag);



#endif