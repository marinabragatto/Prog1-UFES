#include <stdio.h>

typedef struct {
	int codigo;
	float preco;
	int qtdEstq;
	
} tProduto;

tProduto LeProduto();
int EhProduto1MaiorQ2(tProduto p1, tProduto p2);
int EhProduto1MenorQ2(tProduto p1, tProduto p2); 
int TemProdutoEmEstoque(tProduto p); 
void ImprimeProduto(tProduto p);



int main(){
	int total = 0, c = 1, d = 1, t = 1, si = 1, si1 = 1;
	tProduto produto, maior, menor;
	
	scanf("%d", &total);
	
	for(t = 1; t <= total; t++){
		produto = LeProduto();
		
		if(c == 1){
			maior = produto;
			c++;
		} 
		else{
			si = EhProduto1MaiorQ2(maior, produto);
			if(si == 1){
				maior = produto;
			}
		}
		
		if(d == 1){
			menor = produto;
			d++;
		} 
		else{
			si1 = EhProduto1MenorQ2(menor, produto);
			if(si1 == 1){
				menor = produto;
			}
		}
		
		ImprimeProduto(produto);
		
	}
	
	printf("MAIOR:COD %d, PRE %.2f, QTD %d\nMENOR:COD %d, PRE %.2f, QTD %d\n", maior.codigo,
	maior.preco, maior.qtdEstq, menor.codigo, menor.preco, menor.qtdEstq);
	
}

tProduto LeProduto(){
	tProduto produto;
	
	scanf("%d;%f;%d",&produto.codigo, &produto.preco, &produto.qtdEstq);
	
	return produto;
}
int EhProduto1MaiorQ2(tProduto p1, tProduto p2){
	if(p1.preco >= p2.preco){
		return 0;
	} 
	else if(p1.preco < p2.preco){
		return 1;
	}
}
int EhProduto1MenorQ2(tProduto p1, tProduto p2){
	if(p1.preco <= p2.preco){
		return 0;
	} 
	else if(p1.preco > p2.preco){
		return 1;
	}
}
int TemProdutoEmEstoque(tProduto p){
	if(p.qtdEstq >= 1){
		return 1;
	}
	else {
		return 0;
	}
} 
void ImprimeProduto(tProduto p){
	if(!(TemProdutoEmEstoque(p))){
		printf("FALTA:COD %d, PRE %.2f, QTD %d\n",p.codigo, p.preco, p.qtdEstq);
	}
}







