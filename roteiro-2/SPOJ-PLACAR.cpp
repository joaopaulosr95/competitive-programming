#include <iostream>
#include <string>

using namespace std;

class Aluno
{
public:
	string nome;
	int nota;

	bool ehpiorqeu(Aluno a)
	{
		if (nota > a.nota)return true;
		if (nota < a.nota)return false;
		if (nome.compare(a.nome) < 0)
			return  true;
		else
			return false;
	}
	bool ler_dados()
	{
		if( cin >> nome && cin >> nota)
			return false;
		else
			return true;
	}
};

int main()
{
	int n, i, ins;
	Aluno novo, reprovado;

	for (ins = 1; cin >> n && n>0 && n<101; ins++)
	{
		if(reprovado.ler_dados())return 0;
		for (i = 1; i<n; i++)
		{
			if(novo.ler_dados())return 0;
			if (reprovado.ehpiorqeu(novo))
			{
				reprovado = novo;
			}
		}
		cout << "Instancia " << ins << endl << reprovado.nome << endl;
	}
}
