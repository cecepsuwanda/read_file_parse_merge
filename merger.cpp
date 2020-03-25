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

void baca_file(ptr_str nm_file,Transaksi *trans,int *jml_data){	
	FILE *fp = fopen(nm_file, "r");
	char str[MAXCHAR];
	
    arr_2d hsl_parser;
   
	printf("Isi file %s : \n",nm_file);
	while(fgets(str, MAXCHAR, fp) != NULL)
    {
        hsl_parser=parser(str);        
		isi_trans(hsl_parser,&trans[*jml_data]);
		printf("%s %s %d %d\n",trans[*jml_data].kd_barang,trans[*jml_data].nama_barang,trans[*jml_data].harga, trans[*jml_data].qty);
		(*jml_data)++;
    }
    fclose(fp); 
}

void tulis_file(ptr_str nm_file,Transaksi *trans,int *jml_data){	
  FILE *fp = fopen(nm_file, "w"); 
  int i=0; 
  
  printf("Tulis ke file %s : \n",nm_file);
  for(i=0;i<(*jml_data);i++){
  	  fprintf(fp,"%s %s %d %d\n",trans[i].kd_barang,trans[i].nama_barang,trans[i].harga, trans[i].qty);
	  printf("%s %s %d %d\n",trans[i].kd_barang,trans[i].nama_barang,trans[i].harga, trans[i].qty);
  	
  } 
  
  fclose(fp);
}

int main() 
{    
   Transaksi *trans;
   int jml_data=0;
      
   ptr_str nm_file;
   nm_file = (ptr_str) malloc(sizeof(ptr_str));
   strcpy(nm_file,"obat.txt");
   
   trans=(Transaksi *) malloc(sizeof(Transaksi *)*50);
   baca_file(nm_file,trans,&jml_data);
   
   strcpy(nm_file,"obat1.txt");
   baca_file(nm_file,trans,&jml_data);
   
   strcpy(nm_file,"Merge.txt");
   tulis_file(nm_file,trans,&jml_data);
   
   return 0; 
} 
