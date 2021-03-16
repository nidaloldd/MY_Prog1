%{
#include <stdio.h>	
int maganhangzok_szama = 0;
int massalhangzok_szama=0;
%}
maganh [A,a,E,e,I,i,O,o,U,u]
massalh [B,b,C,c,D,d,F,f,G,g,H,h,J,j,K,k,L,l,M,m,N,n,O,o,P,p,Q,q,R,r,S,s,T,t,V,v,W,w,X,x,Y,y,Z,z]
%%
{maganh} {maganhangzok_szama++;}
{massalh} {massalhangzok_szama++;}
%%
int main(){
	yylex();
	printf("Magánhongzók száma: %d\n", maganhangzok_szama);
	printf("Mássalhangzók száma: %d\n", massalhangzok_szama);
	printf("Összesen: %d\n", maganhangzok_szama+massalhangzok_szama);
	return 0;
}