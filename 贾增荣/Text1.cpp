#include <stdio.h>
int fun(int a,int b){
	int c=100*(b%10)+10*(a/10)+(b/10)+1000*(a%10);
	return c;
}
int main() {
	int a;
	int b;
	printf("�������һ����λ��a:");
	scanf("%d",&a);
	printf("������ڶ�����λ��b:");
	scanf("%d",&b);
	int c=fun(a,b);
	printf("���Ϊ:%d",c);
	return 0;
}