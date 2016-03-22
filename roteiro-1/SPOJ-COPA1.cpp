#include <stdio.h>
#include <stdlib.h>

int compara (int x, int y){
	//A função compara os placares informados e retorna o vencedor da partida
	if (x>y)
		return 0;
	else
		return 1;
	}

int main ()	{
	int p11, p12, p21, p22, p31, p32, p41, p42, p51, p52, p61, p62, p71, p72, p81, p82, p91, p92, p101, p102, p111, p112, p121, p122, p131, p132, p141, p142, p151, p152; //Armazenagem dos placares
	int temp=0;

	//As variáveis abaixo armazenarão o identificador (de A a P) do time vencedor do confronto
	char j1, j2, j3, j4, j5, j6, j7, j8;
	char q1, q2, q3, q4;
	char s1, s2;
	char f;

	//Armazenagem e teste dos placares das oitavas de final
	scanf("%d %d", &p11, &p12);
	temp=compara(p11, p12);
		if(temp==0)
			j1='A';
		else
			j1='B';

	scanf("%d %d", &p21, &p22);
	temp=compara(p21, p22);
		if(temp==0)
			j2='C';
		else
			j2='D';

	scanf("%d %d", &p31, &p32);
	temp=compara(p31, p32);
		if(temp==0)
			j3='E';
		else
			j3='F';

	scanf("%d %d", &p41, &p42);
	temp=compara(p41, p42);
		if(temp==0)
			j4='G';
		else
			j4='H';

	scanf("%d %d", &p51, &p52);
	temp=compara(p51, p52);
		if(temp==0)
			j5='I';
		else
			j5='J';

	scanf("%d %d", &p61, &p62);
	temp=compara(p61, p62);
		if(temp==0)
			j6='K';
		else
			j6='L';

	scanf("%d %d", &p71, &p72);
	temp=compara(p71, p72);
		if(temp==0)
			j7='M';
		else
			j7='N';

	scanf("%d %d", &p81, &p82);
	temp=compara(p81, p82);
		if(temp==0)
			j8='O';
		else
			j8='P';

	//Armazenagem e teste dos placares das quartas de final
	scanf("%d %d", &p91, &p92);
	temp=compara(p91, p92);
		if(temp==0){ //Verifica paralelamente o placar das quartas e o placar as oitavas. Neste exemplo, o time A venceu ambos os confrontos, e avançou para as quartas de final.
			if (j1=='A')
				q1='A';
			else
				q1='B';
		}
		else {
			if (j2=='C')
				q1='C';
			else
				q1='D';
        }

	scanf("%d %d", &p101, &p102);
	temp=compara(p101, p102);
		if(temp==0){
			if (j3=='E')
				q2='E';
			else
				q2='F';
		}
		else {
			if (j4=='G')
				q2='G';
			else
				q2='H';
		}

	scanf("%d %d", &p111, &p112);
	temp=compara(p111, p112);
		if(temp==0){
			if (j5=='I')
				q3='I';
			else
				q3='J';
		}
		else {
			if (j6=='K')
				q3='K';
			else
				q3='L';
		}

	scanf("%d %d", &p121, &p122);
	temp=compara(p121, p122);
		if(temp==0){
			if (j7=='M')
				q4='M';
			else
				q4='N';
		}
		else {
			if (j8=='O')
				q4='O';
			else
				q4='P';
		}
	//Armazenagem e teste dos placares das semi finais
	scanf("%d %d", &p131, &p132);
	temp=compara(p131, p132);
		if(temp==0)
			s1=q1;
		else
			s1=q2;

	scanf("%d %d", &p141, &p142);
	temp=compara(p141, p142);
		if(temp==0)
			s2=q3;
		else
			s2=q4;

	//Armazenagem e teste do placar da final
	scanf("%d %d", &p151, &p152);
	temp=compara(p151, p152);
		if(temp==0)
			f=s1;
		else
			f=s2;
	printf("\n%c", f);
	return 0;
	}