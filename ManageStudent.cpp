#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
const int MAX_STUDENT = 1000;
char **nameArr;
int choice, numberOfStudent = 0;
void printMenu(){
	printf("Menu: \n");
	printf("1: Add \n");
	printf("2: Sort \n");
	printf("3: Print \n");
}
void printArr(){
	printf("*** The list name *** \n");
	for(int i=0; i<numberOfStudent;i++){
		printf("Name[%d]: %s",i,nameArr[i]);
	}
	printf("-------------------------");
}
void add(){
	printf("***** ADD ***** \n");
	while(numberOfStudent<MAX_STUDENT ){
		fflush(stdin);
		nameArr[numberOfStudent]=(char*)calloc(31,sizeof(char));//cap them bo nho a[i] khi them 1 ten
		printf("Input name number %d :",numberOfStudent);
		gets(nameArr[numberOfStudent]);
		nameArr[numberOfStudent][strlen(nameArr[numberOfStudent])]='\n'; //them ki tu xuong dong
		nameArr[numberOfStudent][strlen(nameArr[numberOfStudent])+1]='\0';//ket thuc chuoi sau khi them

		if(nameArr[numberOfStudent][0] == '\n' ) break;
		numberOfStudent++;
	}
}
void swap(char *s1, char *s2){
	char *temp= (char *)malloc((strlen(s1)+1)*sizeof(char));
	strcpy(temp,s1);
	strcpy(s1,s2);
	strcpy(s2,temp);
	free(temp);
}
void sort(){
	int indexMin;
	printf("***** SORT ***** \n");
	for(int i=0; i< numberOfStudent; i++){
		indexMin = i;
		for(int j=i; j< numberOfStudent; j++) if(strcmp(nameArr[j],nameArr[indexMin])<0) indexMin = j;
		swap(nameArr[i],nameArr[indexMin]);
	}
	getch();
}
void print(){
	printf("***** PRINT ***** \n");
	printArr();
	getch();
}
void readN(FILE *f){
	f = fopen("listName.txt","r");
	fscanf(f,"%d",&numberOfStudent);
	fscanf(f,"%d"); //xuong dong
	fclose(f);
}
void readFile(FILE *f){
	int i=0;
	f = fopen("listName.txt","r");
	fscanf(f,"%d",&numberOfStudent);
	fscanf(f,"%d"); //xuong dong
	
	for(i = 0; i<numberOfStudent; i++){
		fgets(nameArr[i],31,f);
	}
	fclose(f);	
}
void writeFile(FILE *f){
	f = fopen("listName.txt","w");
	fprintf(f,"%d \n",numberOfStudent);
	for(int i=0; i<numberOfStudent; i++){
		fputs(nameArr[i],f);
	}
	fclose(f);
}
void arr2DFree(char **a, int m){
	int i;
	if(a=='\0' || m<=0) return;
	for(i = 0; i<m; i++){
		if(a[i]!='\0') free(a[i]);
	}
	free(a);
}
char** arr2D_alloc(int m, int n){
	int i, success = 1; char **a;
	a = (char**)calloc(m,sizeof(char*));
//	if(m<=0 || n<=0) return '\0';
	if(a=='\0') return '\0';
	for(i=0; i<m; i++){
		a[i] = (char*)calloc(n, sizeof(char));
		if(a[i]=='\0') {
			success = 0;
			break;
		}
	}
	if(success == 0){
		arr2DFree(a,m);
		a='\0';
	}
	return a;
	
}
int main(){
	FILE *f;
	readN(f);
//	if(numberOfStudent == '\0') numberOfStudent = 0;
	nameArr = arr2D_alloc(numberOfStudent,31);
	if(nameArr=='\0'){
		arr2DFree(nameArr,numberOfStudent);
	}
	readFile(f);
	while(1){
		system("cls");
		fflush(stdin);
		printMenu();
		char ch = getchar();
		if(ch == '1'){
			add();
		}
		else if(ch == '2'){
			sort();
		}
		else if(ch == '3'){
			print();
		}
		else{
			printf("Do you want to exit?");
			fflush(stdin);
			char exit = getch();
			if(exit == 'Y' || exit == 'y') break;
		} 
	}
	writeFile(f);
	arr2DFree(nameArr,numberOfStudent);
	
}
