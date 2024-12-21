#include<stdio.h>
#include "type.h"
#include "view.h"
#include<string.h>
operation_type check_operation(char *argv[]){
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

Status read_validate(char *argv[],tag_view *view1){
        
        if(strcmp(strstr(argv[2],"."),".mp3")!=0){
            printf("Error : it is no mp3");
            return e_failure;
        }
        else{
            strcpy(view1->src_fname,argv[2]);
            return e_success;
        }
}

Status file_open(tag_view *tag){
    tag->fptr_src=fopen(tag->src_fname,"r");
    if(tag->fptr_src==NULL){
        printf("can't open the file");
        return e_failure;
    }
    return e_success;


}

Status check_ID3(tag_view *id3 ){
    int i;
    int size;
    char buffer[3];
    fread(buffer,3,1,id3->fptr_src);
   // printf("checking ID3 found .....%s\n",buffer);
    if(strcmp(buffer,"ID3")==0){
        return e_success;
    }
     else{
        return e_failure;
    }
    

   
}
Status reading_mp3(tag_view *tag){
    printf("--------------------------------------------------------------------\n");
    printf("                 MP3 TAG READER AND EDITOR FOR ID3v2                \n");
    printf("--------------------------------------------------------------------\n");
    printf("\n");
    reading_title(tag);
    reading_artist(tag);
    reading_album(tag);
    reading_year(tag);
    reading_content(tag);
    reading_composer(tag);
    printf("--------------------------------------------------------------------\n");
    return e_success;
}


Status reading_title(tag_view *tag){
    char buffer[4];
    int size;
    
    fseek(tag->fptr_src,10,SEEK_SET);
    fread(buffer,4,1,tag->fptr_src);
    buffer[4]='\0';
    //printf("%s\n",buffer);
    if(strcmp(buffer,"TIT2")==0){
        int x;
        fread(&x,4,1,tag->fptr_src);
        size=convert_to_lit(x);
    }
    fseek(tag->fptr_src,ftell(tag->fptr_src)+3,SEEK_SET);
    //printf("%d",size);
    char buffer1[size];
    fread(buffer1,size,1,tag->fptr_src);
    buffer1[size]='\0';
    printf("TITLE         :   %s\n",buffer1);
    
    
    }
    /*checking for name of artist */
Status reading_artist(tag_view *tag){
    int size1;
    char buffer3[4];
    fread(buffer3,4,1,tag->fptr_src);
    buffer3[4]='\0';
    //printf("%s\n",buffer3);
    if(strcmp(buffer3,"TPE1")==0){
        int x1;
        fread(&x1,4,1,tag->fptr_src);
        size1=convert_to_lit(x1);
        //printf("size1 %d\n",size1);
        fseek(tag->fptr_src,ftell(tag->fptr_src)+3,SEEK_SET);
        char buffer4[size1];
        fread(buffer4,size1,1,tag->fptr_src);
        buffer4[size1]='\0';
        printf("ARTIST        :   %s\n",buffer4);

    }
}
Status reading_album(tag_view *tag){
    int size2;
    char buffer4[4];
    fread(buffer4,4,1,tag->fptr_src);
    buffer4[4]='\0';
    //printf("%s\n",buffer4);
    if(strcmp(buffer4,"TALB")==0){
        int x2;
        fread(&x2,4,1,tag->fptr_src);
        size2=convert_to_lit(x2);
        //printf("size2 %d\n",size2);
        //printf("%ld",ftell(tag->fptr_src));
        fseek(tag->fptr_src,ftell(tag->fptr_src)+3,SEEK_SET);
       // printf("%ld",ftell(tag->fptr_src));
        char buffer5[size2];
        fread(buffer5,size2,1,tag->fptr_src);
        buffer5[size2]='\0';
        printf("ALBUM         :   %s\n",buffer5);

    }
}
Status reading_year(tag_view *tag){
    int size3;
    char buffer5[4];
    fread(buffer5,4,1,tag->fptr_src);
    buffer5[4]='\0';
    //printf("%s\n",buffer5);
        if(strcmp(buffer5,"TYER")==0){
        int x2;
        fread(&x2,4,1,tag->fptr_src);
        size3=convert_to_lit(x2);
        //printf("size2 %d\n",size3);
        //printf("%ld",ftell(tag->fptr_src));
        fseek(tag->fptr_src,ftell(tag->fptr_src)+3,SEEK_SET);
       // printf("%ld",ftell(tag->fptr_src));
        char buffer6[size3];
        fread(buffer6,size3,1,tag->fptr_src);
        buffer6[size3]='\0';
        printf("YEAR          :   %s\n",buffer6);
    }

}
Status reading_content(tag_view *tag){
    int size3;
    char buffer5[4];
    fread(buffer5,4,1,tag->fptr_src);
    buffer5[4]='\0';
    //printf("%s\n",buffer5);
        if(strcmp(buffer5,"TCON")==0){
        int x2;
        fread(&x2,4,1,tag->fptr_src);
        size3=convert_to_lit(x2);
        //printf("size2 %d\n",size3);
        //printf("%ld",ftell(tag->fptr_src));
        fseek(tag->fptr_src,ftell(tag->fptr_src)+3,SEEK_SET);
       // printf("%ld",ftell(tag->fptr_src));
        char buffer6[size3];
        fread(buffer6,size3,1,tag->fptr_src);
        buffer6[size3]='\0';
        printf("CONTENT       :   %s\n",buffer6);
    }
}
Status reading_composer(tag_view *tag){
    int size3;
    char buffer5[4];
    fread(buffer5,4,1,tag->fptr_src);
    buffer5[4]='\0';
    //printf("%s\n",buffer5);
        if(strcmp(buffer5,"COMM")==0){
        int x2;
        fread(&x2,4,1,tag->fptr_src);
        size3=convert_to_lit(x2);
        //printf("size2 %d\n",size3);
        //printf("%ld",ftell(tag->fptr_src));
        fseek(tag->fptr_src,ftell(tag->fptr_src)+3,SEEK_SET);
       // printf("%ld",ftell(tag->fptr_src));
        char buffer6[size3];
        fread(buffer6,size3,1,tag->fptr_src);
        buffer6[size3]='\0';
        printf("COMPOSER      :   ");
        for(int i=0;i<size3;i++){
            printf("%c",buffer6[i]);
        }
        printf("\n");
        printf("\n");
        
        
    }
}
Status convert_to_lit(int x){
    // char *ptr=(char *)&size;
    // int n=4;
    // for(int i=0;i<n/2;i++){
    //     char temp=ptr[i];
    //     ptr[i]=ptr[n-1-i];
    //     ptr[n-1-i]=temp;
    // }
    // return size-1;
    int size=((x >> 24) & 0x000000FF) | // Move byte 3 to byte 0
           ((x >> 8)  & 0x0000FF00) | // Move byte 2 to byte 1
           ((x << 8)  & 0x00FF0000) | // Move byte 1 to byte 2
           ((x << 24) & 0xFF000000);
    return size-1;
}
