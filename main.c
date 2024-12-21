#include<stdio.h>
#include<string.h>
#include "type.h"
#include "view.h"
#include "edit.h"
int main(int argc, char *argv[]){
    if(argc==1)
    {
        printf("ERROR: ./a.out: INVALID ARGUMENTS\n");
        printf("USAGE:\n");
        printf("To view please pass like: ./a.out v mp3filename\n");
        printf("To edit please pass like:./a.out -e -t/-ar/-al/-y/-c/-cm changing_text mp3file\n");
        printf("To get help pass like: ./a.out --help\n");
        return 0;
    }
    if(argc==4){
        printf("To edit please pass like:./a.out -e -t/-ar/-al/-y/-c/-cm changing_text mp3file\n");
        return 0;
    }
    if(argc==3 && (strcmp(argv[1],"-e")==0)){
        if(  (strcmp(argv[2],"-t")!=0) || (strcmp(argv[2],"-al")!=0) || (strcmp(argv[2],"-ar")!=0) || (strcmp(argv[2],"-y")!=0) 
        || (strcmp(argv[2],"-c")!=0) || (strcmp(argv[2],"-cm")!=0)){
            printf("To edit please pass like:./a.out -e -t/-ar/-al/-y/-c/-cm changing_text mp3file\n");
            return 0;
        }
    }
    if(argc<3){
        if( argc>1 && strcmp(argv[1],"-v")==0){
            printf("To view please pass like: ./a.out v mp3filename\n");
        }
        else{
            printf("To edit please pass like:./a.out -e -t/-ar/-al/-y/-c/-cm changing_text mp3file\n");
        }
        return 0;
    }
    if(strcmp(argv[1],"-v")==0){
    if(strstr(argv[2], ".") == NULL || strcmp(strrchr(argv[2], '.'), ".mp3") != 0)
    {
              printf("To view please pass like: ./a.out v mp3filename\n");
              printf("To edit please pass like:./a.out -e -t/-ar/-al/-y/-c/-cm changing_text mp3file\n");
              
               return 0;
    }
    }
    if(argc==5)
    {
        if(strstr(argv[4], ".") == NULL || strcmp(strrchr(argv[4], '.'), ".mp3") != 0)
        {
             
              printf("To edit please pass like:./a.out -e -t/-ar/-al/-y/-c/-cm changing_text mp3file\n");
              return 0;
        }
    }
   
    if(strcmp(argv[1],"--help")==0)
    {
        printf("-------------------------------HELP MENU------------------------------\n");
        printf("\n");
        printf("1. -v -> to view mp3 file contents\n");
        printf("2. -e -> to edit mp3 file contents\n");
        printf("\t");        printf("2.1. -t  -> to edit song title\n");
        printf("\t");        printf("2.2. -ar -> to edit artist name\n");
        printf("\t");        printf("2.3. -al -> to edit album name\n");
        printf("\t");        printf("2.4. -y  -> to edit year\n");
        printf("\t");        printf("2.5. -c  -> to edit content\n");
        printf("\t");        printf("2.6. -cm -> to edit comment\n");
        printf("\n");
        printf("-------------------------------------------------------------------------\n");
        return 0;
    }
    
    tag_view view1;
    tag_edit edit1;

    if(check_operation(argv)== mp3_view){
        printf("-----------------------SELECTED VIEW DETAILS------------------------\n");
        
        if(read_validate(argv,&view1)==e_success){
            if(file_open(&view1)==e_success){
                if(check_ID3(&view1)==e_success){
                   if(reading_mp3(&view1)==e_success){
                    printf("-------------------DETAILS DISPLAYED SUCCESSFULLY-------------------\n");
                    printf("\n");
                   }
                }
                else{
                  printf("ID3 not found\n");
                return e_failure;
                }
            }
            else{
                printf("can't open the file\n");
                return e_failure;
            } 
           
        }
        else{
            printf("failed");
            return e_failure;
        }
    }
    
    else if(check_operation_edit(argv)==mp3_edit){
        if(read_validate_edit(argv,&edit1)==e_success){
            if(file_open_edit(&edit1)==e_success){
                if(check_ID3_edit(&edit1)==e_success){
                   check_for_edit(argv,&edit1);
                    file_close(&edit1);
                     file_open_to_transfer(&edit1);
                    
                }
                else{
                    printf("ID3 not found\n");
                    return e_failure;
                }

            }
            else{
              printf("read and validate failed\n");
              return e_failure;
            }
        }
        else{
            printf("read and validate failed\n");
            return e_failure;
        }
    }
    else{
        printf("Invalid input");
        return e_failure;
    }
    return  0; 
}