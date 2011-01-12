/*
 * Parsing a structure from a file
 *
 * finding the difference b/n storage of short, double,long
 *
 */

#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

struct level1_data_t{
	char name[30];
	uint16_t age;
	uint32_t tax_num;
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
		var1.age = htons(0x2211);
		var1.tax_num =htonl(0x23ff11);
		fwrite(&var1,sizeof(var1),1,f1);
	}
	fclose(f1);
	f2 = fopen("data1","rb");
	if(f1!=NULL){
		while(fread(&var2,sizeof(var2),1,f1)>0){
			printf("%s\n",var2.name);
			printf("%x\n",var2.age);
			printf("%x\n",ntohs(var2.age));
			printf("%x\n",var2.tax_num);
			printf("%x\n",ntohl(var2.tax_num));
		}
	}
	fclose(f2);
	return 0;
}
