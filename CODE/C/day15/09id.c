#include <stdio.h>
typedef struct{
	int id;
	float salary;
	char name[9];

}person;

int main(){
	person prn = {0};
	int choice = 0;
	FILE *p_file = fopen("person.bin","ab");
	if (p_file){
		while(1){
			printf("plz input id :");
			scanf("%d",&(prn.id));
	
			printf("plz input salary:");
			scanf("%g",&(prn.salary));
			scanf("%*[^\n]"); 
			scanf("%*c");	  //清理
	
			printf("plz input name:");
			fgets(prn.name,9,stdin);
		
			fwrite(&prn,sizeof(person),1,p_file);	//将信息写如文件中
			printf("1 is continue 0 is do not:");
			scanf("%d",&choice);
			if (!choice) {
				break;
			}
		}	
		fclose(p_file);
		p_file = NULL;
	}
	return 0;	
}







