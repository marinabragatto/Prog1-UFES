#include <stdio.h>

typedef struct{
	int mes;
	int dia;
	int ano;
	
}tData;

tData LeData();
tData RetornaVal (tData data);
void ImprimeData(tData data);
int EhBissexto(tData d);

int main(){
	int qtd = 1, q = 1;
	tData data;
	
	scanf("%d",&qtd);
	
	for(q = 1; q<= qtd; q++){
		data = LeData();
		ImprimeData(data);
		
	}
	
}
tData LeData(){
	tData data;
	scanf("%d %d %d", &data.dia, &data.mes, &data.ano);
	data = RetornaVal (data);
	return data;
}

tData RetornaVal (tData data){
	if(EhBissexto(data)){
		if(data.mes == 2){
			if(data.dia > 29){
				data.dia = 29;
			}
			return data;
		}
	} else {
		if(data.mes == 2){
			if(data.dia > 28){
				data.dia = 28;
			}
			return data;
		}
	}
	if(data.mes == 0){
		data.mes = 1;
		if(data.dia > 31){
			data.dia = 31;
		}
		return data;
	}
	
	if(data.mes == 1 ||data.mes == 3 || data.mes == 5 || data.mes == 7 || 
		data.mes == 8 || data.mes == 10 || data.mes == 12){
		if(data.dia > 31){			
			data.dia = 31;
		}
		return data;
	} else if (data.mes == 4 ||data.mes == 6 || data.mes == 9 || data.mes == 11) {
		if(data.dia > 30){
			data.dia = 30;
		}
		return data;
	} else {
		if(data.mes > 12){
			data.mes = 12;
		}
		if(data.dia > 31){
			data.dia = 31;
		}
		return data;
	}
	
}

void ImprimeData(tData data){
	if(EhBissexto(data)){
		printf("'%02d/%02d/%d':Bisexto\n",data.dia,data.mes,data.ano);
		
	} else {
		printf("'%02d/%02d/%d':Normal\n",data.dia,data.mes,data.ano);
	}
}
int EhBissexto(tData d){
	int resto = 0, resto1 = 0;
	resto = d.ano%100;
	if(resto == 0){
		resto1 = d.ano%400;
		if(resto1 == 0){
			return 1;
		}
		else{
			return 0;
		}
	} 
	else {
		resto1 = d.ano%4;
		if(resto1 == 0){
			return 1;
		}
		else {
			return 0;
		}
	}
}
