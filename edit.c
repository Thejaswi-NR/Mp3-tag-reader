#include<stdio.h>
#include "type.h"
#include "edit.h"
#include<string.h>
#include "view.h"

operation_type check_operation_edit(char *argv[]){
    if(strcmp(argv[1],"-v")==0){
        return mp3_view;
    }
    if(strcmp(argv[1],"-e")==0){
        return mp3_edit;
    }
    else{
        return unsupported;
    }
}
Status read_validate_edit(char *argv[],tag_edit *edit){
   
        if(strcmp(strstr(argv[4],"."),".mp3")==0){
            
            strcpy(edit->src_fname,argv[4]);
        }
        if(argv[3]!=NULL){
            strcpy(edit->duplicate,argv[3]);

        }
        if(argv[5]==NULL){
            strcpy(edit->temp_file,"temp.mp3");
        }
        return e_success;

}

Status file_open_edit(tag_edit *tag){
    tag->fptr_src=fopen(tag->src_fname,"r");
    tag->ftemp=fopen(tag->temp_file,"w");
    if(tag->fptr_src==NULL){
        printf("can't open the file");
        return e_failure;
    }
    if(tag->ftemp==NULL){
        printf("can't open the file");
        return e_failure;
    }

    return e_success;


}
Status copy_header(tag_edit *tag){
    fseek(tag->fptr_src,0,SEEK_SET);
    char str[10];
    fread(str,10,1,tag->fptr_src);
    fwrite(str,10,1,tag->ftemp);
    
}

Status check_ID3_edit(tag_edit *id3 ){
    int i;
    int size;
    char buffer[3];
    
    fread(buffer,3,1,id3->fptr_src);
    
   // printf("checking ID3 found .....%s\n",buffer);
    if(strcmp(buffer,"ID3")==0){
       // printf("ID3 found\n");
        return e_success;
    }
    else{
        return e_failure;
    }
}
 /*copy the remaining data*/
Status copy_remaining_data(tag_edit *tag){
        char ch;
        while(fread(&ch,1,1,tag->fptr_src)!=0){
            fwrite(&ch,1,1,tag->ftemp);
        }
    }

Status check_for_edit(char *argv[],tag_edit *tag){
    copy_header(tag);
    
    if(strcmp(argv[2],"-t")==0){
        
        char buffer[4];
        int size;
        fseek(tag->fptr_src,10,SEEK_SET);
        //printf("before %ld\n",ftell(tag->ftemp));
        fread(buffer,4,1,tag->fptr_src);
        buffer[4]='\0';
        fwrite(buffer,4,1,tag->ftemp);
        //printf("%s",buffer);
        if(strcmp(buffer,"TIT2")==0)
        {
            copy_all_type(tag);
        }
            fseek(tag->fptr_src,67,SEEK_SET);
            copy_remaining_data(tag);
        
        
    }
   

    else if(strcmp(argv[2],"-ar")==0){
        char buffer1[57];
        fread(buffer1,57,1,tag->fptr_src);
        fwrite(buffer1,57,1,tag->ftemp);
       
        char buffer[4];
        int size;
        fseek(tag->fptr_src,67,SEEK_SET);
        fread(buffer,4,1,tag->fptr_src);
        //printf("%ld",ftell(tag->fptr_src));
        buffer[4]='\0';
        //printf("%s\n",buffer);
        fwrite(buffer,4,1,tag->ftemp);
        if(strcmp(buffer,"TPE1")==0)
        {
            copy_all_type(tag);
        }
            fseek(tag->fptr_src,110,SEEK_SET);
            copy_remaining_data(tag);
        
    }

    else if(strcmp(argv[2],"-al")==0){
        
        char buffer1[100];
        fread(buffer1,100,1,tag->fptr_src);
        fwrite(buffer1,100,1,tag->ftemp);
        char buffer[4];
        int size;
        fseek(tag->fptr_src,110,SEEK_SET);
        fread(buffer,4,1,tag->fptr_src);
        //printf("%ld\n",ftell(tag->fptr_src));
        buffer[4]='\0';
        //printf("%s\n",buffer);
        fwrite(buffer,4,1,tag->ftemp);
        if(strcmp(buffer,"TALB")==0)
        {
            copy_all_type(tag);
        }
            fseek(tag->fptr_src,129,SEEK_SET);
            copy_remaining_data(tag);
        
    }
    else if(strcmp(argv[2],"-y")==0){
        
        char buffer1[119];
        fread(buffer1,119,1,tag->fptr_src);
        fwrite(buffer1,119,1,tag->ftemp);
        char buffer[4];
        int size;
        fseek(tag->fptr_src,129,SEEK_SET);
        fread(buffer,4,1,tag->fptr_src);
        //printf("%ld\n",ftell(tag->fptr_src));
        buffer[4]='\0';
        //printf("%s\n",buffer);
        fwrite(buffer,4,1,tag->ftemp);
        if(strcmp(buffer,"TYER")==0)
        {
            copy_all_type(tag);
        }
            fseek(tag->fptr_src,144,SEEK_SET);
            copy_remaining_data(tag);
        
    }
    else if(strcmp(argv[2],"-c")==0){
        
        char buffer1[134];
        fread(buffer1,134,1,tag->fptr_src);
        fwrite(buffer1,134,1,tag->ftemp);
        char buffer[4];
        int size;
        fseek(tag->fptr_src,144,SEEK_SET);
        fread(buffer,4,1,tag->fptr_src);
        //printf("%ld\n",ftell(tag->fptr_src));
        buffer[4]='\0';
        //printf("%s\n",buffer);
        fwrite(buffer,4,1,tag->ftemp);
        if(strcmp(buffer,"TCON")==0)
        {
            copy_all_type(tag);
        }
            fseek(tag->fptr_src,185,SEEK_SET);
            copy_remaining_data(tag);
        
    }
    else if(strcmp(argv[2],"-cm")==0){
        
        char buffer1[175];
        fread(buffer1,175,1,tag->fptr_src);
        fwrite(buffer1,175,1,tag->ftemp);
        char buffer[4];
        int size;
        fseek(tag->fptr_src,185,SEEK_SET);
        fread(buffer,4,1,tag->fptr_src);
        //printf("%ld\n",ftell(tag->fptr_src));
        buffer[4]='\0';
        //printf("%s\n",buffer);
        fwrite(buffer,4,1,tag->ftemp);
        if(strcmp(buffer,"COMM")==0)
        {
            copy_all_type(tag);
        }
            copy_remaining_data(tag);
        
    }
    else{
        printf("To edit please pass like:./a.out -e -t/-ar/-al/-y/-c/-cm changing_text mp3file\n");
        return 0;
    }
    
    return e_success;
}


/*copy content of all type*/
Status copy_all_type(tag_edit *tag){
        int size;
        int x=strlen(tag->duplicate);
        size=convert_to_big(x+1);
        fwrite(&size,4,1,tag->ftemp);
        char buffer[3];
        fwrite(buffer,3,1,tag->ftemp);
        fwrite(tag->duplicate,strlen(tag->duplicate),1,tag->ftemp);
        printf("added sucessfully\n");
}


Status convert_to_big(int x){

    int size=((x >> 24) & 0x000000FF) | // Move byte 3 to byte 0
           ((x >> 8)  & 0x0000FF00) | // Move byte 2 to byte 1
           ((x << 8)  & 0x00FF0000) | // Move byte 1 to byte 2
           ((x << 24) & 0xFF000000);
    return size;
}
Status file_close(tag_edit * tag){
    fclose(tag->ftemp);
     fclose(tag->fptr_src);
}
Status file_open_to_transfer(tag_edit *tag){
    tag->fptr_src=fopen(tag->src_fname,"w");   /*to make the temp as*/
    tag->ftemp=fopen(tag->temp_file,"r");
    char ch;
        while(fread(&ch,1,1,tag->ftemp)!=0){
            fwrite(&ch,1,1,tag->fptr_src);
        }
    fclose(tag->ftemp);
    fclose(tag->fptr_src);
    return e_success;
}



