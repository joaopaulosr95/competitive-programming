#include <iostream>
#include <math.h> 

//Por Tales Barreto

using namespace std;

int quadrado_distancia2pontos( int x1, int y1, int x2, int y2)
{
	return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1); 
}


bool ehretangulo(int x1, int y1, int x2, int y2, int x3,int y3)
{
	int a,b,c;

	if(	//Garantir que é um trangulo válido
		x1==x2 && y1 == y2 ||
		x2==x3 && y2 == y3 ||
		x3==x1 && y3 == y1
	)return false;
	
	a=quadrado_distancia2pontos(x1,y1,x2,y2);
	b=quadrado_distancia2pontos(x2,y2,x3,y3);
	c=quadrado_distancia2pontos(x3,y3,x1,y1);
	//Por teorema de Pitágoras:
	if(b+c == a)return true;
	if(a+c == b)return true;
	if(a+b == c)return true;
	return false;
}

bool ehquase(int x1, int y1, int x2, int y2, int x3,int y3)
{//Porco mas muito eficiente ^^
	x1++;
	if(ehretangulo(x1, y1, x2, y2, x3, y3))return true;
	x1-=2;
	if(ehretangulo(x1, y1, x2, y2, x3, y3))return true;
	x1++;//
	x2++;
	if(ehretangulo(x1, y1, x2, y2, x3, y3))return true;
	x2-=2;
	if(ehretangulo(x1, y1, x2, y2, x3, y3))return true;
	x2++;//
	x3++;
	if(ehretangulo(x1, y1, x2, y2, x3, y3))return true;
	x3-=2;
	if(ehretangulo(x1, y1, x2, y2, x3, y3))return true;
	x3++;//
	y1++;
	if(ehretangulo(x1, y1, x2, y2, x3, y3))return true;
	y1-=2;
	if(ehretangulo(x1, y1, x2, y2, x3, y3))return true;
	y1++;//
	y2++;
	if(ehretangulo(x1, y1, x2, y2, x3, y3))return true;
	y2-=2;
	if(ehretangulo(x1, y1, x2, y2, x3, y3))return true;
	y2++;//
	y3++;
	if(ehretangulo(x1, y1, x2, y2, x3, y3))return true;
	y3-=2;
	if(ehretangulo(x1, y1, x2, y2, x3, y3))return true;
	return false;
}

int main()
{
	int x1,y1,x2,y2,x3,y3;
	
	for(;;)
	{
		if(!(
			cin>>x1 && x1<101 &&
			cin>>y1 && y1<101 &&
			cin>>x2 && x2<101 &&
			cin>>y2 && y2<101 &&
			cin>>x3 && x3<101 &&
			cin>>y3 && y3<101
		))return 0;
		if(ehretangulo(x1, y1, x2, y2, x3,y3))
		{
			cout << "RIGHT" << endl;
			continue;
		}
		if(ehquase(x1, y1, x2, y2, x3,y3))
			cout << "ALMOST" << endl;
		else
			cout << "NEITHER" << endl;
		
	}
}
