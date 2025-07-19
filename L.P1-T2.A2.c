#include <stdio.h>
#include <stdbool.h>

int ValidacaoAno(int ano);
int ValidacaoMes(int mes);  
int ValidacaoDia(int dia, int mes);
int ValidacaoBissextos(int dia, int ano);
int ValidacaoExiste( int dia, int mes);
int DiaSemana(int dia, int mes, int ano);

int main()
{
    struct regData {int dia, mes, ano;}; 
    typedef struct regData TData; 
    TData data;
    int invalidaAno, invalidaMes, invalidaDia, invalidaBissextos, invalidaExiste ;
    int Semana;
    bool  invalida;
    char resultados [7][15] = {"Domingo", "Segunda-Feira", "Terça-Feira", "Quarta-Feira", "Quinta-Feira", "Sexta-Feira", "Sábado"}; 
    do{
		printf(" Data: ");
        scanf("%d %d %d", &data.dia, &data.mes, &data.ano);
        
        invalidaAno =  ValidacaoAno(data.ano);
        invalidaMes =  ValidacaoMes(data.mes); 
        invalidaDia =  ValidacaoDia(data.dia,data.mes);
        invalidaBissextos = 2 == data.mes ? ValidacaoBissextos(data.dia,data.ano) : 0;
        invalidaExiste = 1582 == data.ano ? ValidacaoExiste(data.dia,data.mes) : 0;
        
        invalida =(invalidaAno + invalidaMes + invalidaDia + invalidaBissextos + invalidaExiste)== 0 ? true : false;
    
		if(data.dia != 0 && data.mes != 0 && data.ano != 0  && invalida ){
		    Semana = DiaSemana(data.dia,data.mes,data.ano);
		    
            printf("%02d/%02d/%04d : %s \n", data.dia, data.mes, data.ano, resultados [Semana]);
		}
	}while(data.dia != 0 && data.mes != 0 && data.ano != 0);
	return 0;
}
int ValidacaoAno(int ano){
    if( ano > 0  && ano < 10000)
        return 0;
    else
        return 1;
}
int ValidacaoMes(int mes){
    if(mes > 0 && mes < 13)
        return 0;
    else
        return 1;
} 

int ValidacaoDia(int dia, int mes){
    if( dia <=30 && dia > 0){
            return 0;
    }else{ if( dia <= 31 && dia > 0 && (mes != 4 && mes != 6 && mes != 9 && mes != 11))
            return 0;
    return 1;
    }
}

int ValidacaoBissextos(int dia,int ano){
       if(dia <= 28 && dia > 0)
        return 0;
    
    if(dia == 29){
        
        if((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
            return 0;
        else
            return 1;
    }
    
    return 1; 
}
int ValidacaoExiste( int dia, int mes){
    if(mes == 10 && dia >= 5 && dia <= 14){
        return 1;
    }
    return 0;
}
int DiaSemana(int dia, int mes, int ano){
    int  M, D, A, S;
    if(mes <= 2){
        M = mes + 10;  
        ano--;         
    } else {
        M = mes - 2;  
    }
    D = dia;
    A = ano %100;
    S = ano / 100;
    
    int soma = (int)(2.6 * M - 0.1) + D + A + (A/4) + (S/4) - 2 * S;

     return soma % 7; 

}
