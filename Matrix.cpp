#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int** a;
int** b;
int** c;
int** d;
int mA,nA,mB,nB;
int MultiplyMatrix(int**a, int** b, int**c, int mA, int nA, int mB, int nB){
	int i,j,k;
	if(nA!=mB){
		printf("\n   Can't Multiply");
		printf("\n   nA == mB");
		return 0;
	}
	for(i = 0; i< mA; i++){
		for(int j=0; j< nB; j++){
			for(int k = 0; k< nA; k++){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	return 1;
}
int addMatrix(int **a, int** b, int** c, int mA, int nA, int mB, int nB){
	if(mA != mB || nA != nB) {
		printf("\n   Can't add");
		printf("\n   mA == mB, nA == nB");
		return 0;
	}
	int i,j;
	for(i = 0; i<mA; i++){
		for(j =0 ; j<nA; j++){
			c[i][j]= a[i][j]+b[i][j];
		}
	}
	return 1;
}
void inputMN(int* m, int *n){
	printf("\nM: ");
	fflush(stdin);
	scanf("%d",m);
	
	printf("\nN: ");
	fflush(stdin);
	scanf("%d",n);
}
void printMatrix(int **a, int m, int n){
	int i,j;
	printf("\n");
	for(i = 0; i<m ; i++){
		printf("\n");
		for(j =0 ; j< n; j++){
			printf("%4d",a[i][j]);
		}
	}
}
void creatMatrix(int **a,int m, int n){
	int i, j;
	for(i = 0; i<m; i++){
		for(int j=0 ; j<n; j++){
			a[i][j] = rand()%5;
		}
	}

}
void freeMatrix(int** a, int m){
	int i;
	if(a!='\0'){
		for(i = 0; i< m; i++){
			if(a[i]=='\0')free(a[i]);
		}
		
		free(a);
		a = '\0';
	}
}
int** matrix_alloc(int m, int n){
	int **a;
	int i;
	int success =1;
	if(m<=0 || n<= 0) return '\0';
	
	a = (int**)calloc(m, sizeof(int*));
	if(a=='\0') return '\0';
	
	for(i=0; i<m; i++){
		a[i] = (int*)calloc(n, sizeof(int));
		if(a[i]=='\0'){
			success = 0;
			break;
		}
	}
	if(!success){
		freeMatrix(a,m);
	}
	return a;
}
int main(){
	srand(time('\0'));
	//instial A
	printf("\nInput mA, nA:");
	inputMN(&mA,&nA);
	a = matrix_alloc(mA,nA);
	if(!a){
		printf("Stack over flow");
		return 1;	
	}
	//instial B
	printf("\nInput mB, nB:");
	inputMN(&mB,&nB);
	b = matrix_alloc(mB,nB);
	if(!b){
		printf("Stack over flow");
		return 1;
	}
	//instial C
	c = matrix_alloc(mA,nB);
	if(!c){
		printf("Stack over flow C");
		return 1;
	}
	d = matrix_alloc(mA,nB);
	if(!d){
		printf("Stack over flow D");
		return 1;
	}
	
	creatMatrix(a,mA,nA);
	printf("\n===Random Matrix A:===");
	printMatrix(a,mA,nA);
	
	creatMatrix(b,mB,nB);
	printf("\n===Random Matrix B:===");
	printMatrix(b,mB,nB);
	
	printf("\n---ADD MATRIX---");
	if(addMatrix(a,b,c,mA,nA,mB,nB))printMatrix(c,mA,nB);
	
	printf("\n---MULTIPLY MATRIX---");
	if(MultiplyMatrix(a,b,d,mA,nA,mB,nB))printMatrix(d,mA,nB);
	
	freeMatrix(a,mA);
	freeMatrix(b,mB);
	freeMatrix(c,mA);
	freeMatrix(d,mA);
}
