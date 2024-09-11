#include <stdio.h>
int VerificaGotaChuvaAcida(float pH){
    if(pH<5.70){
        return 1;
    }else{
        return 0;
    }
}
float Modulo(float num){
    if (num>=0){
        num=num;
    }else{
        num=-num;
    }
    return num;
}
int VerificaPh(float pH){
    if (pH==7){
        return 0;
    }else if(pH>7){
        return 2;
    }else{
        return 1;
    }
}
float Porcentagem(float total,float valor){
    return ((valor/total)*100);
}
void ImprimeResultadosAnalise(float porcentagemGotasChuvaAcida,float porcentagemGotasChuvaNormal){
    char c='%';
    if (porcentagemGotasChuvaAcida>=75.00){
        printf("Chuva Acida %.2f%c %.2f%c",porcentagemGotasChuvaAcida,c,porcentagemGotasChuvaNormal,c);
    }
    else if (porcentagemGotasChuvaNormal>=75.00){
        printf("Chuva Normal %.2f%c %.2f%c",porcentagemGotasChuvaAcida,c,porcentagemGotasChuvaNormal,c);
    }else{
        printf("Chuva com indicios de chuva acida %.2f%c %.2f%c",porcentagemGotasChuvaAcida,c,porcentagemGotasChuvaNormal,c);
    }
}
int main(){
    int A=0,D=0,T=0,countNum=0,retorno=0,countAcido=0,countNeutro=0,countBasico=0,countAcidoGotas=0,count=0;
    float maisAcido=0,maisNeutro=0,maisBasico=0,p=0,pH=0,porcetagemAcida=0,porcentagemNormal=0,total=0;
    scanf("%d %d %d",&A,&D,&T);
    while (1){
        retorno=scanf("%f",&p);
        if (retorno==0||retorno==-1){
            break;
        }
        pH=VerificaPh(p);
        if(countAcido==0&&countBasico==0&&countNeutro==0){
            maisNeutro=p;
            maisAcido=p;
            maisBasico=p;
        }else{
            //conferencia de proximidade ao 7
            maisNeutro=(Modulo(1-(p/7.00)))<(Modulo(1-(maisNeutro/7.00)))?p:maisNeutro;
        }
        if(pH==1){
            maisAcido=maisAcido<p?maisAcido:p;
            countAcido++;
        }else if(pH==2){
            maisBasico=maisBasico>p?maisBasico:p;
            countBasico++;
        }else{
            countNeutro++;
        }
        if(VerificaGotaChuvaAcida(p)){
            countAcidoGotas++;
        }
        count++;
    }
    if (count==0){
        printf("Nenhuma gota foi avaliada");
        return 0;
    }
    total=countAcido+countBasico+countNeutro;
    printf("%d %d %d %.2f %.2f %.2f\n",countAcido,countBasico,countNeutro,maisAcido,maisBasico,maisNeutro);
    porcetagemAcida=Porcentagem(total,countAcidoGotas);
    porcentagemNormal=100-porcetagemAcida;
    ImprimeResultadosAnalise(porcetagemAcida,porcentagemNormal);
    return 0;
}