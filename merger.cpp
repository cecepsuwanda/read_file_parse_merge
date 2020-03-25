#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define MAXCHAR 1000

typedef struct transaksi {
   char kd_barang[5];
   char nama_barang[3];
   int harga;
   int qty;
} Transaksi;

typedef char *ptr_str;
typedef char **arr_2d;

arr_2d parser(ptr_str str){
	arr_2d arr_tmp;
	ptr_str pch;
	int i;
	arr_tmp =(char **) malloc(sizeof(char*) * 4);
	
	pch = strtok (str," ");
	i=0;
		while (pch != NULL)
        {          
          arr_tmp[i] = (char *) malloc(sizeof(char*) * 10);
		  strcpy(arr_tmp[i],pch);
		  		  	
          pch = strtok (NULL, " ");          	  
		  i++;
        }
	return arr_tmp;
}

void isi_trans(arr_2d data,Transaksi *trans)
{
	strcpy((*trans).kd_barang, data[0]);
    strcpy((*trans).nama_barang,data[1]);
    (*trans).harga=atoi(data[2]);
    (*trans).qty=atoi(data[3]);
}

int main() 
{ 
   // Open two files to be merged 
   FILE *fp1 = fopen("obat.txt", "r"); 
   FILE *fp2 = fopen("obat1.txt", "r"); 
  
   // Open file to store the result 
   FILE *fp3 = fopen("Merge.txt", "w"); 
   char str[MAXCHAR];
   Transaksi trans[100];
   int i=0;
   arr_2d hsl_parser;

   printf("Isi file 1 : \n"); 
   	       
    while(fgets(str, MAXCHAR, fp1) != NULL)
    {
        hsl_parser=parser(str);
		isi_trans(hsl_parser,&trans[i]);
		printf("%s %s %d %d\n",trans[i].kd_barang,trans[i].nama_barang,trans[i].harga, trans[i].qty);
		i++;
    }   
       
    printf("Isi file 2 : \n");
    while(fgets(str, MAXCHAR, fp2) != NULL)
    {
        hsl_parser=parser(str);
		isi_trans(hsl_parser,&trans[i]);
		printf("%s %s %d %d\n",trans[i].kd_barang,trans[i].nama_barang,trans[i].harga, trans[i].qty);		
        i++;
    }	  
  
   printf("Merged file1.txt and file2.txt into file3.txt"); 
  
   fclose(fp1); 
   fclose(fp2); 
   fclose(fp3); 
   return 0; 
} 
