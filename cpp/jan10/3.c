/*
 * Parsing a structure from a file
 *
 */

#include <stdio.h>
#include <string.h>

struct level1_data_t{
	char name[30];
	
};

int main()
{
	FILE *f1,*f2;
	char *temp;
	struct level1_data_t var1,var2;
	f1 = fopen("data1","wb");
	if(f1!=NULL){
		printf("Enter the name :");
		fflush(stdout);
		fgets(var1.name,sizeof(var1.name),stdin);
		temp = strchr(var1.name,'\n');
		if(temp){
			*temp = '\0';
		}
		fwrite(var1.name,sizeof(var1.name),1,f1);
	}
	fclose(f1);
	f2 = fopen("data1","rb");
	if(f1!=NULL){
		while(fread(&var2,sizeof(var2),1,f1)>0){
			printf("%s\n",var2.name);
		}
	}
	fclose(f2);
	return 0;
}
