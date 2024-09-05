#include <stdio.h>

typedef struct{
	int dia;
	int mes;
	int ano;
	
}tData;

tData LeData();
int EhBissexto(tData d);
tData RetornaVal(tData d);
tData AvancaData(tData inicio);
void ImprimeData (tData data);
int EhIgual(tData result, tData fim);



int main(){
	int i = 1;
	tData inicio, fim, result;
	
	inicio = LeData();
	fim = LeData();
	ImprimeData (inicio);
//	ImprimeData (fim);
	result = inicio;
	if(EhIgual(result, fim)){
			return 0;
	}
	
	while (i){
		result = AvancaData(inicio);
		if(EhIgual(result, fim)){
			break;
		}
		ImprimeData (result);
		inicio = result;
	}
	return 0;	
	
}

tData LeData(){
	tData data;
	scanf("%d %d %d", &data.dia, &data.mes, &data.ano);
	data = RetornaVal(data);
//	ImprimeData (data);
	return data;
	
}

tData RetornaVal(tData d){

	
	if(EhBissexto(d)){
		if(d.mes == 2){
			if(d.dia > 29){
				d.dia = 29;
			}
			return d;
		}
	} else {
		if(d.mes == 2){
			if(d.dia > 28){
				d.dia = 28;
			}
			return d;
		}
	}
	
	if(d.mes == 1 ||d.mes == 3 ||d.mes == 5 || d.mes == 7 || 
		d.mes == 8 || d.mes == 10 || d.mes == 12){
			if(d.dia > 31){
				d.dia = 31;
			}
			return d;
	} else if (d.mes == 4 ||d.mes == 6 ||d.mes == 9 || d.mes == 11) {
			if(d.dia > 30){
				d.dia = 30;
			}
		
			return d;
	} else {
			if(d.mes > 12){
				d.mes = 12;
			}
			if(d.dia > 31){
				d.dia = 31;
			}
			return d;
	}
	

}

int EhBissexto(tData d){
	int resto = 0, resto1 = 0;
	
	resto = d.ano%100;
	
	if(resto == 0){
		resto1 = d.ano%400;
		if(resto == 0){
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

tData AvancaData(tData inicio){
	
	if(EhBissexto(inicio)){
		if(inicio.mes == 2){
			if(inicio.dia == 29){
				inicio.dia = 1;
				inicio.mes++; 
			} else {
				inicio.dia++;
			}
			
			return inicio;
		}
	}  else {
		if(inicio.mes == 2){
			if(inicio.dia == 28){
				inicio.dia = 1;
				inicio.mes++; 
			} else {
				inicio.dia++;
			}
			
			return inicio;
		}	
	}
	
	if((inicio.mes == 1 ||inicio.mes == 3 ||inicio.mes == 5 || inicio.mes == 7 || 
		inicio.mes == 8 || inicio.mes == 10)){
		if(inicio.dia == 31){
			inicio.dia = 1;
			inicio.mes++;
		} else {
			inicio.dia++;
		}
		return inicio;
	} else 	if (inicio.mes == 4 || inicio.mes == 6 || inicio.mes == 9 || inicio.mes == 11){
		if(inicio.dia == 30){
			inicio.dia = 1;
			inicio.mes++;
		//	ImprimeData(inicio);
		} else {
			inicio.dia++;
		}
		return inicio;
	} else if(inicio.mes == 12){
		if(inicio.dia == 31){
			inicio.dia = 1;
			inicio.mes = 1;
			inicio.ano++;
		} else {
			inicio.dia++;
		}
		return inicio;
	}

}

void ImprimeData (tData data){
	
	printf("'%02d/%02d/%d'\n", data.dia, data.mes, data.ano);
}

int EhIgual(tData result, tData fim){
	if (result.ano == fim.ano && result.mes == fim.mes && result.dia == fim.dia){
		return 1;
	} else{
		return 0;
	}
}
