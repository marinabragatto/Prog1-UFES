#include <stdio.h>



int main(){
	int qntdele = 0, nmrdele = 0, atleta = 0, cltd = 0, ct = 0, maiornotaf = 0, pioratletaf = 0, melhoratletaf = 0, x = 1, y = 1, nota1m = 0, nota2m = 0, nota3m = 0, nota1f = 0, nota2f = 0, nota3f = 0, maiornotam = 0, pioratletam = 0, melhoratletam = 0, z = 1, atlf1 = 0, atlf2 = 0, atlf3 = 0, atlm1 = 0, atlm2 = 0, atlm3 = 0, k = 1,i = 1, aux = 0, aux1 = 0, somatm = 0, somatf = 0, maiorsomatm = 0, maiorsomatf = 0, melhordelm = 0, melhordelf = 0, atlmp1 = 0, atlmp2 = 0, atlmp3 = 0, atlfp1 = 0, atlfp2 = 0, atlfp3 = 0, piornotam = 0, piornotaf = 0;
	char genero = 'a', lixo = 'a';
	scanf("%d",&qntdele);
	
	for(cltd = 1; qntdele>=cltd ; cltd ++){
		while(i){
			scanf("%d", &atleta);
			if(atleta == -1){
				x = 1;
				y = 1;
				break;
			}
			scanf("%c%c",&lixo, &genero);
			
			
			
			if (genero == 'F'){
				scanf("%d %d %d\n",&nota1f, &nota2f, &nota3f);
				//Ordena AS NOTAS
				
					if (nota1f>=nota2f && nota2f>=nota3f){
						nota1f = nota1f;
						nota2f = nota2f;
						nota3f = nota3f;
					} else if(nota1f<=nota2f && nota2f<=nota3f){
						aux = nota1f;
						nota1f = nota3f;
						nota2f = nota2f;
						nota3f = aux;
					} else if(nota1f>=nota3f && nota2f<=nota3f){
						aux = nota2f;
						nota1f = nota1f;
						nota2f = nota3f;
						nota3f = aux;
					} else if (nota1f<=nota3f && nota2f>=nota3f){
						aux = nota1f;
						nota1f = nota2f;
						nota2f = nota3f;
						nota3f = aux;
					} else if (nota1f>=nota2f && nota1f<=nota3f){
						aux = nota1f;
						aux1 = nota2f;
						nota1f = nota3f;
						nota2f = aux;
						nota3f = aux1;
					} else if (nota1f<=nota2f && nota1f>=nota3f){
						aux = nota1f;
						nota1f = nota2f;
						nota2f = aux;
						nota3f = nota3f;
					}
					//printf("\nordem descresnete %d %d %d\n", nota1f, nota2f, nota3f);
					
					somatf = somatf + nota1f;
					
					//maior nota geral
					if(nota1f>maiornotaf || y == 1){
						y++;
						maiornotaf = nota1f;
						melhoratletaf = atleta;
						atlf1 = nota1f;
						atlf2 = nota2f;
						atlf3 = nota3f;
					} else if (nota1f==maiornotaf){
						if (nota2f>atlf2){
							melhoratletaf = atleta;
							atlf1 = nota1f;
							atlf2 = nota2f;
							atlf3 = nota3f;
						} else if (nota2f==atlf2 && nota3f>atlf3){
							melhoratletaf = atleta;
							atlf1 = nota1f;
							atlf2 = nota2f;
							atlf3 = nota3f;
						} else if (nota3f==atlf3 && nota2f==atlf2 && nota1f==atlf1){
							if(atleta < melhoratletaf){
								melhoratletaf = atleta;
								atlf1 = nota1f;
								atlf2 = nota2f;
								atlf3 = nota3f;
							}
						}	
					}
					
					if(nota1f < piornotaf || y == 2){
						y++;
						piornotaf = nota1f;
						pioratletaf = atleta;
						atlfp1 = nota1f;
						atlfp2 = nota2f;
						atlfp3 = nota3f;
					} else if (nota1f==piornotaf){
						if (nota2f<atlfp2){
							pioratletaf = atleta;
							atlfp1 = nota1f;
							atlfp2 = nota2f;
							atlfp3 = nota3f;
						} else if (nota2f==atlfp2 && nota3f<atlfp3){
							pioratletaf = atleta;
							atlfp1 = nota1f;
							atlfp2 = nota2f;
							atlfp3 = nota3f;
						} else if (nota3f==atlfp3 && nota2f==atlfp2 && nota1f==atlfp1){
							if(atleta>pioratletaf){
								pioratletaf = atleta;
								atlfp1 = nota1f;
								atlfp2 = nota2f;
								atlfp3 = nota3f;
							}
						}
							
					}
					
					
				
			} else if (genero == 'M'){
				scanf("%d %d %d\n",&nota1m, &nota2m, &nota3m);
				
					if (nota1m>=nota2m && nota2m>=nota3m){
						nota1m = nota1m;
						nota2m = nota2m;
						nota3m = nota3m;
					} else if(nota1m<=nota2m && nota2m<=nota3m){
						aux = nota1m;
						nota1m = nota3m;
						nota2m = nota2m;
						nota3m = aux;
					} else if(nota1m>=nota3m && nota2m<=nota3m){
						aux = nota2m;
						nota1m = nota1m;
						nota2m = nota3m;
						nota3m = aux;
					} else if (nota1m<=nota3m && nota2m>=nota3m){
						aux = nota1m;
						nota1m = nota2m;
						nota2m = nota3m;
						nota3m = aux;
					} else if (nota1m>=nota2m && nota1m<=nota3m){
						aux = nota1m;
						aux1 = nota2m;
						nota1m = nota3m;
						nota2m = aux;
						nota3m = aux1;
					} else if (nota1m<=nota2m && nota1m>=nota3m){
						aux = nota1m;
						nota1m = nota2m;
						nota2m = aux;
						nota3m = nota3m;
					}
			
					somatm = somatm + nota1m;
		
						//maior nota geral
						
					if(nota1m>maiornotam || x == 1){
						x++;
						maiornotam = nota1m;
						melhoratletam = atleta;
						atlm1 = nota1m;
						atlm2 = nota2m;
						atlm3 = nota3m;
					} else if (nota1m==maiornotam){
						if (nota2m>atlm2){
							melhoratletam = atleta;
							atlm1 = nota1m;
							atlm2 = nota2m;
							atlm3 = nota3m;
						} else if (nota2m==atlm2 && nota3m>atlm3){
							melhoratletam = atleta;
							atlm1 = nota1m;
							atlm2 = nota2m;
							atlm3 = nota3m;
						} else if (nota3m==atlm3 && nota2m==atlm2 && nota1m==atlm1){
							if(atleta<melhoratletam){
								melhoratletam = atleta;
								atlm1 = nota1m;
								atlm2 = nota2m;
								atlm3 = nota3m;
							}
						}
							
					}
					
					// pior nota geral
					
					if(nota1m < piornotam || x == 2){
						x++;
						piornotam = nota1m;
						pioratletam = atleta;
						atlmp1 = nota1m;
						atlmp2 = nota2m;
						atlmp3 = nota3m;
					} else if (nota1m==piornotam){
						if (nota2m<atlmp2){
							pioratletam = atleta;
							atlmp1 = nota1m;
							atlmp2 = nota2m;
							atlmp3 = nota3m;
						} else if (nota2m==atlmp2 && nota3m<atlmp3){
							pioratletam = atleta;
							atlmp1 = nota1m;
							atlmp2 = nota2m;
							atlmp3 = nota3m;
						} else if (nota3m==atlmp3 && nota2m==atlmp2 && nota1m==atlmp1){
							if(atleta>pioratletam){
								pioratletam = atleta;
								atlmp1 = nota1m;
								atlmp2 = nota2m;
								atlmp3 = nota3m;
							}
						}
							
					}
						
					
					
			}
			
	
					
		
		
		}
		if(maiorsomatm < somatm || z == 1){
			z++;
			maiorsomatm = somatm;
			melhordelm = cltd;
		}
		if(maiorsomatf < somatf || k == 1){
			k++;
			maiorsomatf = somatf;
			melhordelf = cltd;
		}
		
		somatm = 0;
		somatf = 0;
		
		printf("MELHORES ATLETAS DA DELEGACAO %d\nMASCULINO: %d FEMININO: %d\nPIORES ATLETAS DA DELEGACAO %d\nMASCULINO: %d FEMININO: %d\n\n", cltd, melhoratletam, melhoratletaf, cltd, pioratletam, pioratletaf);	
		maiornotam = 0;
		maiornotaf = 0;
		piornotam = 0;
		piornotaf = 0;
	
	}
	
	printf("DELEGACAO CAMPEA:\nMASCULINO: %d FEMININO: %d", melhordelm, melhordelf);
	
	return 0;
}

