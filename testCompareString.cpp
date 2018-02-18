#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char name[1000][31];
void pr(){
	for(int i=0; i<3; i++){
			printf("%d %s \n",i,name[i]);
	}
}
void add(){
		gets(name[0]);
		gets(name[1]);
}
void swap(char *str1, char *str2){
	char *tmp = (char *)malloc((strlen(str1)+1)*sizeof(char));
	strcpy(tmp, str1);
	strcpy(str1, str2);
	strcpy(str2, tmp);
	free(tmp);
	}
int main(){
	add();
	printf("%s \n",name[0]);
	printf("%s \n",name[1]);
	swap(name[0],name[1]);
	printf("%s \n",name[0]);
	printf("%s \n",name[1]);
//	printf("%d",strcmp(name[0],name[1]));
//	char tmp[31];
//	tmp = name[0];
//	name[0] = name[1];
//	name[1] = tmp;

}
