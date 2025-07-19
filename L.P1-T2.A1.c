
#include <stdio.h>
#include <math.h>

double calculaIAC(double circunferenciaIAC, double  alturaIAC);
int resultado(double IACRes, char sexoRes);

int main()
{
	char sexo = 'i';
	double  altura, circunferencia, IAC;
	char Classificacao[6][25] = {"Excesso de gordura", "Moderada", "Ideal", "Baixa", "Excepcionalmente baixa", "inválido"};
	
	while(sexo !='X') {
		printf("Qual o sexo(M/F),circunferencia  e  altura : \n");
		scanf(" %c",&sexo);
		if (sexo!='X') {
    		scanf(" %lf %lf",&circunferencia,&altura);
    		
    		IAC =  calculaIAC(circunferencia, altura);
            //printf ("%d \n",IAC);
    		printf(" %s\n", Classificacao[resultado(IAC, sexo)]);
		}
	}
	return 0;
}

double calculaIAC(double circunferenciaIAC, double alturaIAC) {
    
   return (circunferenciaIAC / (alturaIAC * sqrt(alturaIAC))) - 18;

}
int resultado(double IACRes, char sexoRes) {
    if (sexoRes == 'M') {
        if (IACRes > 25) return 0;
        else if (IACRes >= 19) return 1;
        else if (IACRes >= 15) return 2;
        else if (IACRes >= 11) return 3;
        else if (IACRes >= 6) return 4;
        else return 5;
    }
    if (sexoRes == 'F') {
        if (IACRes > 30) return 0;
        else if (IACRes >= 26) return 1;
        else if (IACRes >= 20) return 2;
        else if (IACRes >= 16) return 3;
        else if (IACRes >= 10) return 4;
        else return 5;
    }
    return 5;
}
