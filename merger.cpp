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

int main() 
{ 
   // Open two files to be merged 
   FILE *fp1 = fopen("obat.txt", "r"); 
   FILE *fp2 = fopen("obat1.txt", "r"); 
  
   // Open file to store the result 
   FILE *fp3 = fopen("Merge.txt", "w"); 
   char * pch; 
   char str[MAXCHAR];
   Transaksi trans[100];
   int i=0,j=0;

   printf("Isi file 1 : \n"); 
   	       
    while(fgets(str, MAXCHAR, fp1) != NULL)
    {
        //printf("%s",str);
        pch = strtok (str," ");
        j=1;
		while (pch != NULL)
        {
          //printf ("%s\n",pch);
          switch(j){
          	case 1 : strcpy(trans[i].kd_barang, pch);break;
          	case 2 : strcpy(trans[i].nama_barang, pch);break;
          	case 3 : trans[i].harga=atoi(pch);break;
          	case 4 : trans[i].qty=atoi(pch);break;
		  }	
          pch = strtok (NULL, " ");          	  
		  j++;
        }
		printf("%s %s %d %d\n",trans[i].kd_barang,trans[i].nama_barang,trans[i].harga, trans[i].qty);
        i++;
    }   
       
    printf("Isi file 2 : \n");
    while(fgets(str, MAXCHAR, fp2) != NULL)
    {
        //printf("%s",str);
        pch = strtok (str," ");
        j=1;
		while (pch != NULL)
        {
          //printf ("%s\n",pch);
          switch(j){
          	case 1 : strcpy(trans[i].kd_barang, pch);break;
          	case 2 : strcpy(trans[i].nama_barang, pch);break;
          	case 3 : trans[i].harga=atoi(pch);break;
          	case 4 : trans[i].qty=atoi(pch);break;
		  }	
          pch = strtok (NULL, " ");          	  
		  j++;
        }
		printf("%s %s %d %d\n",trans[i].kd_barang,trans[i].nama_barang,trans[i].harga, trans[i].qty);
        i++;
    }	  
  
   printf("Merged file1.txt and file2.txt into file3.txt"); 
  
   fclose(fp1); 
   fclose(fp2); 
   fclose(fp3); 
   return 0; 
} 
