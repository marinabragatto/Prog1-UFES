#include <stdio.h>

int verificapH(float pH);
void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal);
float porcentagem(float total, float valor);
int verificaGotaChuvaAcida(float pH);
float ModuloDistSete (float pH);

int main(){
	int area = 0, dens = 0, time = 0, resPh = 0, acido = 0 , basico = 0, neutro = 0, i = 1, chAci = 0, gotaAc = 0, gotaNor = 0, gotaTotal = 0, b = 1, a = 1, ret = 1, nenhuma = 0, control = 1;
	float pH = 25.0, porcentagemGotasChuvaAcida = 0, porcentagemGotasChuvaNormal = 0, finish = 0, maiorBas = 0, menorAci = 0, proximo = 7.00, modulo = 0, modprox = 0;
	char space = 'a';
	
	scanf("%d %d %d\n",&area, &dens, &time);

	
	if((area >= 0 && area <= 50) && (dens >= 0 && dens <= 50) && (time >= 0 & time <= 12)){
		while (i){
			ret = scanf("%f%c", &pH, &space);
			
			
			
				if(pH >= 0.00 && pH <= 14.00){

					resPh = verificapH(pH);
					if(resPh == 1){
						acido++;
					}
					else if(resPh == 2){
						basico++;
					}
					else if(resPh == 0){
						neutro++;
					}
				
					chAci = verificaGotaChuvaAcida(pH);
				
					if(chAci == 1){
						gotaAc++;
					}
				
					if (chAci == 0){
						gotaNor++;
					}
				
				
				
					if(maiorBas < pH || b == 1){
						maiorBas = pH;
						b++;
					}
				
					if(menorAci > pH || a == 1){
						menorAci = pH;
						a++;
					}
					
					modulo = ModuloDistSete (pH);
					
					if(modulo < modprox || control == 1){
						proximo = pH;
						modprox = modulo;
						control++;
					}
				
					
					gotaTotal++;
			
				}	
		
		
				if (space != ' '){
					break;
				}
				
			
		}
		
		porcentagemGotasChuvaAcida = porcentagem(gotaTotal, gotaAc);
		porcentagemGotasChuvaNormal = porcentagem(gotaTotal, gotaNor);
		
	
		
	}
	
		if(gotaTotal == 0){
			pH = 0;
			proximo = 0;
			printf("Nenhuma gota foi avaliada");
			return 0;
			
		}
		else {
			printf("%d %d %d %.2f %.2f %.2f\n", acido, basico, neutro, menorAci, maiorBas, proximo);
			imprimeResultadosAnalise(porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
		
		}
		
	return 0;	
	
}

int verificapH(float pH){
	int result = 0;
	
	if (pH<7.00){
		result = 1;
	}
	else if(pH>7.00){
		result = 2;
	}
	else if(pH == 7.00){
		result = 0;
	}
	
	return result;
	
}

int verificaGotaChuvaAcida(float pH){
	
	if(pH >= 5.70){
		return 0;
	}
	else if(pH < 5.70){
		return 1;
	}
	
}

float porcentagem(float total, float valor){
	float result = 1.0;
	
	result = valor/total;
	
	return result;
	
}
void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal){
	
	porcentagemGotasChuvaAcida = porcentagemGotasChuvaAcida*100;
	porcentagemGotasChuvaNormal = porcentagemGotasChuvaNormal*100;
	
	if(porcentagemGotasChuvaAcida >= 75.00){
		printf("Chuva Acida %.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
	}
	else if (porcentagemGotasChuvaNormal >= 75.00){
		printf("Chuva Normal %.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
	} else {
		printf("Chuva com indicios de chuva acida %.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
	}
		
	
}

float ModuloDistSete (float pH){
	float result = 0;
	
	if(pH > 7.00){
		result = pH - 7.00;
	}
	else if(pH <= 7.00){
		result = 7.00 - pH;
	}
	
	return result;
	
}
