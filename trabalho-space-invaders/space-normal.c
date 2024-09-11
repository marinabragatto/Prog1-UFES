#include <stdio.h>
#include <stdlib.h>

#define QTD_MAX_DE_INIMIGOS 400
#define NAVE "M"
#define NaoHaMorte -1 
#define TIRO "o"
#define ATIVO 1
#define INATIVO 0

typedef struct{
	int col;
	int lin;
}tMapa;

typedef struct{
	int col;
	int lin;
}tJogador;

typedef struct{
	int col;
	int lin;
	int vivo;
	int fila;
	int ind;
	int IteMorte;
	int linMorte;
}tInimigo ;

typedef struct{
	int col;
	int lin;
}tTiro;

typedef struct{
	tMapa mapa;
	tTiro tiro;
	tJogador player;
	tInimigo ini[400];
	char imgIni[3][3][3];
	int QuantidadeInimigos;
	int linhaLimite;
	int pontos;
	int iter;
	int EsquerdaOuDireita;
	int TiroAtivo;
	int OcorreuMorte;
	int danca;
	int TirosEfetivos;
	int Mov;
	int Descidas;
	int TirosLixo;
	int InimigosMortos;
}tJogo;

//Declaração completa de todas as funções a seguir:

tJogo InicializaJogo(tJogo jogo, char * argv);
tJogo LeArquivoMapa(FILE * mapaArq, tJogo jogo);
tMapa AtribuiLinhaColunaMapa(int col, int lin);
tJogador PlayerRecebePosicaoXeY(int col, int lin, tJogador player);
tInimigo InimigoRecebeDadosDeInicializacao(int colIni, int linIni, int fila, int ind, tInimigo ini);
tInimigo InimigoRecebePosicaoXeY(int col, int lin, tInimigo ini);
tJogo InicializaVariaveis(tJogo jogo);
tJogo LeArquivoInimigo(FILE * inimigoArq, tJogo jogo);

void PrintaComoEstaOJogo(tJogo jogo, FILE * arquivo, int cod);
int EstaMorto(tInimigo ini);
int RetornaPosicaoDoJogador(tJogador player, int cod);
int RetornaTamanhoDoMapa(tMapa map, int cod);
int RetornaPosicaoDoTiro(tTiro tiro, int cod);
int EhParaPrintarOMais(tMapa map, int j, int i);
int EhParaPrintarDelimitacao(tJogador player, int j, int i, tMapa maps);
int EhParaPrintarNave(tJogador player, int j, int i);
int ExisteInimigoAqui(tJogo jogo, tInimigo ini, int i, int j);
void ImprimeOInimigo(int ret, tJogo jogo, FILE * arquivo, int danca);
tJogo DarVidaAosInimigos(tJogo jogo);
tInimigo MataOuAnimaInimigo(tInimigo ini, int cod);

tJogo RealizarJogo(tJogo jogo, char argv []);
int JogadorColidiuComLateral(tJogo jogo);
int ExisteInimigosVivos(tJogo jogo);
int InimigoCruzouLinha(tJogo jogo);
tJogo RealizaPartida(tJogo jogo, char comando, FILE * resumo);
tJogo RealizarMorte(tJogo jogo, int morto);
int RetornaPontosInimigo(tInimigo ini, tMapa mapa);
tJogo OcorreuMorte(tJogo jogo, FILE * resumo);
tJogo AdicionarTiroNaPartida(tJogo jogo);
tJogador AlteraPosicao(tJogador player, char comando);
int EhParaPrintarInimigo(tJogo jogo, int j , int i);
int RetornaTipo(int tipo);
int TrocaSentidoDeMovInimigos(int EsquerdaOuDireita);
tJogo MovimentaInimigos(tJogo jogo, FILE * resumo);
void InicializaHeatMap(int lin, int col, int HeatMap[lin][col]);
void GerarHeatMap(int lin, int col, int HeatMap[lin][col], FILE * heatmap);
void AtualizaHeatMap(int lin, int col, int HeatMap[lin][col], tJogo jogo);
void GerarRanking(tJogo jogo, FILE * ranking);
void GerarEstatisticas(tJogo jogo, FILE * estatisticas);
void OrdenaVetorCrescente(tInimigo * mortos, tJogo jogo);
int MenorValorEntreAeB(tInimigo * mortos, int a, int b);
int RetornaLinhaDoInimigo(tInimigo ini);
void ImprimeNoArquivo(tJogo jogo, tInimigo * mortos, FILE * ranking);
tTiro MovimentaTiro(tTiro tiro);
tInimigo AtribuiDadosSobreMorte(tInimigo ini, int iter, int mapsLin, int tiroLin);

int main (int argc, char * argv[]){
	// É necessario a passagem de um parâmetro para a função "int main()", que é o caminho do diretório.
	if(argc <= 1){
		 printf("ERRO: Informe o diretorio com os arquivos de configuracao.\n");
		return -1;
	}
	tJogo jogo;
	
	jogo = InicializaJogo(jogo, argv[1]);
	
	jogo = RealizarJogo(jogo, argv[1]);
	
	return 0;
}

tJogo InicializaJogo(tJogo jogo, char * argv){
	FILE * mapaArq;
	char caminhoMapa [1020] = {'t', 'e', 's', 't', 'e'};
	
	FILE * inimigoArq;
	char caminhoIni [1020] = {'t', 'e', 's', 't', 'e'};
	
	FILE * inicializacao;
	char inic[1020] = {'t', 'e', 's', 't', 'e'};
	
	int i = 0, j = 0;
	
	//Processo de concanetenção do argv[1], caminho do diretório, com o restante do caminho do arquivo que se deseja abrir. 
	sprintf(caminhoMapa, "%s/mapa.txt", argv);
	sprintf(caminhoIni, "%s/inimigo.txt", argv);
	sprintf(inic, "%s/saida/inicializacao.txt", argv);

	mapaArq = fopen (caminhoMapa,"r");
	inimigoArq = fopen (caminhoIni, "r");
	
	//Analisa se os arquivos foram abertos corretamente.
	if(mapaArq == NULL){
		printf("ERRO: Nao foi possivel abrir o arquivo \"mapa.txt\"\nCaminho para o arquivo: 1/mapa.txt\n\n");
	}
	if(inimigoArq == NULL){
		printf("ERRO: Nao foi possivel abrir o arquivo \"inimigo.txt\"\nCaminho para o arquivo: 1/inimigo.txt\n");
	}
	if(inimigoArq == NULL || mapaArq == NULL){
		exit(1);
	}
	
	jogo = LeArquivoMapa(mapaArq, jogo);
	jogo = LeArquivoInimigo(inimigoArq, jogo);
	
	fclose(mapaArq);
	fclose(inimigoArq);

	//Gera o primeiro arquivo solicitado "inicializacao.txt".
	inicializacao = fopen(inic, "w");
	PrintaComoEstaOJogo(jogo, inicializacao, 1);
	fclose(inicializacao);

	return jogo;
}

tJogo LeArquivoMapa(FILE * mapaArq, tJogo jogo){
	int tamCol = 0, tamLin = 0, colPlayer = 0, linPlayer = 0, ret = 0, colIni = 0, linIni = 0, count = 0, i = 0, linArq = 0, fila = 0, ind = 0;
	char barra = 'a';
	//RECEBE DADOS SOBRE O MAPA.
	fscanf(mapaArq, "%d %d", &tamCol, &tamLin);
	jogo.mapa = AtribuiLinhaColunaMapa(tamCol, tamLin);
	//RECEBE DADOS SOBRE O JOGADOR.
	fscanf(mapaArq, "%*[^(]");
	fscanf(mapaArq, "(%d %d)", &colPlayer, &linPlayer);
	jogo.player = PlayerRecebePosicaoXeY(colPlayer, linPlayer, jogo.player);  
	//RECEBE INIMIGOS DADOS SOBRE O INIMIGO.
	fscanf(mapaArq, "%*[^\n]");
	while(!feof(mapaArq)){
		fscanf(mapaArq, "%c", &barra);
		//O \n define o começo de uma nova fileira, logo é necessário verificar a sua existência, a fim de contar corretamente os índices e filas. Com uma nova fila, temos que iniciar do zero a posição do índice. 
		if(barra == '\n'){
			fila++;
			ind = 0;
		}
		ret = fscanf(mapaArq, "(%d %d)", &colIni, &linIni);
		if(ret == 2){
			ind++;
			count++; // Conta a partir do retorno do scanf a quantidade de inimigos do jogo.
			jogo.ini[i] = InimigoRecebeDadosDeInicializacao(colIni, linIni, fila, ind, jogo.ini[i]);
			i++;
		}
	}
	
	jogo.QuantidadeInimigos = count; // Atribui a uma variável a quantidade de inimigos.
	jogo = InicializaVariaveis(jogo);
	return jogo;
}

tMapa AtribuiLinhaColunaMapa(int col, int lin){
	tMapa map;
	map.col = col;
	map.lin = lin;
	return map;
}

tJogador PlayerRecebePosicaoXeY(int col, int lin, tJogador player){
	player.col = col;
	player.lin = lin;
	return player;
}

tInimigo InimigoRecebeDadosDeInicializacao(int colIni, int linIni, int fila, int ind, tInimigo ini){
	ini = InimigoRecebePosicaoXeY(colIni, linIni, ini);
	ini.fila = fila;
	ini.ind = ind;
	return ini;
}

tInimigo InimigoRecebePosicaoXeY(int col, int lin, tInimigo ini){
	ini.col = col;
	ini.lin = lin;
	return ini;
} 

tJogo InicializaVariaveis(tJogo jogo){
	// Inicializa variáveis do jogo. 
	jogo.linhaLimite = jogo.player.lin - 2;
	jogo = DarVidaAosInimigos(jogo);
	jogo.iter = 0;
	jogo.pontos = 0; 
	jogo.EsquerdaOuDireita = 1;
	jogo.TiroAtivo = 0;
	jogo.OcorreuMorte = NaoHaMorte;
	jogo.InimigosMortos = 0;
	jogo.TirosLixo = 0;
	jogo.Descidas = 0;
	jogo.Mov = 0;
	jogo.TirosEfetivos = 0;
	jogo.tiro.col = -2;
	jogo.tiro.lin = -2;

	return jogo;
}

tJogo LeArquivoInimigo(FILE * inimigoArq, tJogo jogo){
	int cod = 2, i = 0, j = 0, k = 0;
	
	//É necessário a análise de se o jogo possui o modo bônus ativado ou não. A variável que armazena essa informação é a "danca" (parte do struct tJogo), uma vez que a ativação permite a movimentação dos inimigos, durante um jogo.
	//jogo.danca == 1, bônus ativado.
	//jogo.danca == 0, bônus desativado.

	fscanf(inimigoArq, "%d", &jogo.danca);
	fscanf(inimigoArq, "%*c");
	
	//É armazenado cada desenho do inimigo em uma matriz tridimensional.

	for(k = 0; k < 3; k++){
		for (i = 0; i < 3; i++){
			for (j = 0; j < 3; j++){
				fscanf(inimigoArq, "%c", &jogo.imgIni[j][i][k]);
			}
			fscanf(inimigoArq, "%*c");
		}
	}
		
	return jogo;
}

void PrintaComoEstaOJogo(tJogo jogo, FILE * arquivo, int cod){
	//Essa função recebe um arquivo (esse arquivo pode ser qualquer um, uma vez que vem como parâmetro) e printa nesse arquivo o MAPA do jogo no momento em que a função foi chamada.
	//Nesse trabalho, temos que printar o mapa em dois arquivos diferentes, o "saida.txt" e o "inicializacao.txt".
	
	//O "int cod" serve para indicar de maneira rápida de qual arquivo se trata, uma vez que no arquivo "inicializacao.txt" temos que printar algo além do mapa.
	//cod == 1 -> inicializacao.txt.
	//cod == 2 -> saida.txt.
	

	int mapsCol = 0, mapsLin = 0, ret = 0, k = 0, tiroCol = 0, tiroLin = 0, colJog = 0, linJog = 0, i = 0, j = 0;

	mapsCol = RetornaTamanhoDoMapa(jogo.mapa, 1);
	mapsLin = RetornaTamanhoDoMapa(jogo.mapa, 2);
	
	tiroCol = RetornaPosicaoDoTiro(jogo.tiro, 1);
	tiroLin = RetornaPosicaoDoTiro(jogo.tiro, 2);
		
	
	// A partir disso, percorremos as posições x e y do mapa e vemos se em cada posição tem algum objeto (como uma nave, um inimigo, etc) e, se sim, esse objeto será printado.
	//Observe o incremento de "+2", isso é devido a necessidade da existência de bordas.

	for (i = 0; i < mapsLin + 2; i++){
		for(j = 0; j < mapsCol + 2; j++){
			if(EhParaPrintarOMais(jogo.mapa, j, i)){
				fprintf(arquivo, "+");
			}
			else if(i == 0 || i == mapsLin + 1){
				fprintf(arquivo, "-");
			}
			else if(EhParaPrintarDelimitacao(jogo.player, j, i, jogo.mapa)){
				fprintf(arquivo,"-");
			}
			else if(j == 0 || j == mapsCol + 1){
				fprintf(arquivo,"|");
			}
			else if(jogo.TiroAtivo == 1 && i == tiroLin && j == tiroCol){
				fprintf(arquivo, TIRO);
			}
			else if(jogo.QuantidadeInimigos > 0 && EhParaPrintarInimigo(jogo, j , i)){
				k = 0;
				for(k = 0; k < jogo.QuantidadeInimigos; k++){
					ret = ExisteInimigoAqui(jogo, jogo.ini[k], i, j);
					if(ret && !EstaMorto(jogo.ini[k])){
						ImprimeOInimigo(ret, jogo, arquivo, jogo.danca);
					}
				}
			}
			else if(EhParaPrintarNave(jogo.player, j, i)){
					fprintf(arquivo, NAVE);
			}
			else{
				fprintf(arquivo, " ");
			}
		}
		fprintf(arquivo,"\n"); //Próxima linha do mapa.
	}
	

	if(cod == 1){
		colJog = RetornaPosicaoDoJogador(jogo.player, 1);
		linJog = RetornaPosicaoDoJogador(jogo.player, 2);
		fprintf(arquivo, "A posicao central do jogador iniciara em (%d %d).", colJog, linJog);
	}
	
	return;
}

int EstaMorto(tInimigo ini){
	if(ini.vivo == 0){
		return 1;
	} 
	return 0;
}

int RetornaPosicaoDoJogador(tJogador player, int cod){
	// De acordo com o código, a coluna ou a linha é retornado.
	if(cod == 1){
		return player.col;
	}
	return player.lin;
}

int RetornaTamanhoDoMapa(tMapa map, int cod){
	// De acordo com o código, a coluna ou a linha é retornado.
	if(cod == 1){
		return map.col;
	}
	return map.lin;
}

int RetornaPosicaoDoTiro(tTiro tiro, int cod){
	// De acordo com o código, a coluna ou a linha é retornado.
	if(cod == 1){
		return tiro.col;
	}
	return tiro.lin;
}

int EhParaPrintarOMais(tMapa map, int j, int i){
	if((j == 0 && i == 0) || (j == 0 && i == map.lin + 1) || (j == map.col + 1  && i == map.lin + 1) || (j == map.col + 1  && i == 0)){
		return 1;
	}
	return 0;
}

int EhParaPrintarDelimitacao(tJogador player, int j, int i, tMapa maps){
	int jogCol = 0, jogLin = 0;
	if((i == player.lin - 2 && j == 0) || (i == player.lin - 2 && j == maps.col + 1)){
		return 1;
	}
	return 0;
}

int EhParaPrintarNave(tJogador player, int j, int i){
	if((i == player.lin && j == player.col) || (i == player.lin - 1 && j == player.col + 1) || (i == player.lin + 1 && j == player.col - 1) || (i == player.lin - 1 && j == player.col - 1) || (i == player.lin && j == player.col - 1) || (i == player.lin + 1 && j == player.col) || (i == player.lin && j == player.col + 1) || (i == player.lin + 1 && j == player.col + 1)){
		return 1;
	}
	return 0;
}

int ExisteInimigoAqui(tJogo jogo, tInimigo ini, int i, int j){
	int ret = 0, k = 0, iniCol = 0, iniLin = 0;
	
	// A partir de uma posição do mapa (x,y) é verificado se o inimigo passado como parâmetro está ocupando, também, essa posição (x,y). 
	//É muito relevante qual número é retornado, uma vez que ele indica qual caractere do inimigo é esse que ocupa a posição (x,y), relevante na função "PrintaComoEstaOJogo(tJogo jogo, FILE * arquivo, int cod)".

	if(i == ini.lin && j == ini.col){
		return 5;	
	}
	if(i == ini.lin - 1 && j == ini.col + 1){
		return 3;
	}
	if(i == ini.lin + 1 && j == ini.col - 1){
		return 7;
	}
	if(i == ini.lin - 1 && j == ini.col - 1){
		return 1;
	}
	if(i == ini.lin && j == ini.col - 1){
		return 4;
	}
	if(i == ini.lin + 1 && j == ini.col){
		return 8;
	}
	if (i == ini.lin && j == ini.col + 1){
		return 6;
	} 
	if(i == ini.lin + 1 && j == ini.col + 1){
		return 9;
	}
	if(i == ini.lin - 1 && j == ini.col){
		return 2;
	}
	
	return 0;
}

void ImprimeOInimigo(int ret, tJogo jogo, FILE * arquivo, int danca){
	int tipo = 0;

	// Se a dança for ativada no jogo, a variável dança varia de 1 a 3, ficando pressa nesse ciclo.
	// Variável dança == 0, primeiro desenho de inimigo.
	// Variável dança == 1, primeiro desenho de inimigo.
	// Variável dança == 2, segundo desenho de inimigo.
	// Variável dança == 1, terceiro desenho de inimigo.
	if(jogo.danca != 0){
		tipo = danca - 1;
	}
	else {
		tipo = danca;
	}
	
	// Printa certa parte do inimigo.

	if(ret == 1){
		fprintf(arquivo,"%c", jogo.imgIni[0][0][tipo]);
	}
	else if (ret == 2){
		fprintf(arquivo,"%c", jogo.imgIni[1][0][tipo]);
	}
	else if (ret == 3){
		fprintf(arquivo,"%c", jogo.imgIni[2][0][tipo]);
	}
	else if(ret == 4){
		fprintf(arquivo,"%c", jogo.imgIni[0][1][tipo]);
	}
	else if(ret == 5){
		fprintf(arquivo,"%c", jogo.imgIni[1][1][tipo]);
	}
	else if(ret == 6){
		fprintf(arquivo,"%c", jogo.imgIni[2][1][tipo]);
	}
	else if(ret == 7){
		fprintf(arquivo,"%c", jogo.imgIni[0][2][tipo]);
	}
	else if(ret == 8){
		fprintf(arquivo,"%c", jogo.imgIni[1][2][tipo]);
	}
	else if(ret == 9){
		fprintf(arquivo,"%c", jogo.imgIni[2][2][tipo]);
	}
	return;
}

tJogo DarVidaAosInimigos(tJogo jogo){
	int i = 0;
	
	for(i = 0; i < jogo.QuantidadeInimigos; i++){
		jogo.ini[i] = MataOuAnimaInimigo(jogo.ini[i], 1);
		jogo.ini[i].IteMorte = -2;
		jogo.ini[i].linMorte = -2;
	}
	return jogo;
}

tInimigo MataOuAnimaInimigo(tInimigo ini, int cod){
	// Mata inimigo ou anima um inimigo, dependendo do código.
	if(cod == 1){
		ini.vivo = 1;
	}
	else if(cod == 2){
		ini.vivo = 0;
	}
	return ini;
}

tJogo RealizarJogo(tJogo jogo, char argv []){
	//Essa função é iniciada quando o jogo realmente começa e é finalizada apenas quando o jogo estiver acabado, ou seja, o programa ao sair dessa função, já terá realizado todas as tarefas que o trabalho requisitou (todos os arquivos completos e finalizados).


	// Essas variáveis de ganhar e perder são essenciais, já que são elas que ditam se o jogaodor perdeu ou ganhou.
	//O jogador ganha se e somente se ganhou == 1.
	//O jogador perde se e somemte se perdeu == 1.
	//A lógica do algoritmo abaixo permite que APENAS uma das variaveis acima tenham valor 1, logo se uma tem valor 1 a outra OBRIGATORIAMENTE tem valor 0.
	int  ganhou = 0, perdeu = 0, ret = 0;

	char  comando = 'a';
	//ARQUIVO ENTRADA PARA LEITURA.
	FILE * entradaArq;
	char caminhoArqEntra[1020] = {'t', 'e', 's', 't', 'e'};

	//ARQUIVO DE SAÍDA PARA ESCRITA.
	FILE * saidaArq;
	char caminhoArqSaida[1020] = {'t', 'e', 's', 't', 'e'}; 

	//ARQUIVO DE MAPA DE CALOR PARA ESCRITA.
	FILE * heatmapArq;
	char caminhoArqHeat[1020] = {'t', 'e', 's', 't', 'e'}; 

	//ARQUIVO DE ESTATÍSTICAS PARA ESCRITA.
	FILE * estatisticasArq;
	char caminhoArqEsta[1020] = {'t', 'e', 's', 't', 'e'}; 

	//ARQUIVO DE RESUMO PARA ESCRITA.
	FILE * resumoArq;
	char caminhoArqResu[1020] = {'t', 'e', 's', 't', 'e'};

	//ARQUIVO RANKING PARA ESCRITA.
	FILE * rankingArq;
	char caminhoArqRanking[1020] = {'t', 'e', 's', 't', 'e'};
	
	sprintf(caminhoArqEntra, "%s/entrada.txt", argv);
	sprintf(caminhoArqEsta, "%s/saida/estatisticas.txt", argv);
	sprintf(caminhoArqSaida, "%s/saida/saida.txt", argv);
	sprintf(caminhoArqHeat, "%s/saida/heatmap.txt", argv);
	sprintf(caminhoArqResu, "%s/saida/resumo.txt", argv);
	sprintf(caminhoArqRanking, "%s/saida/ranking.txt", argv);

	entradaArq = fopen (caminhoArqEntra, "r");
	heatmapArq =  fopen(caminhoArqHeat, "w");
	saidaArq = fopen (caminhoArqSaida, "w");
	estatisticasArq = fopen (caminhoArqEsta, "w");
	resumoArq = fopen (caminhoArqResu, "w");
	rankingArq = fopen(caminhoArqRanking, "w");

	// Matriz que armazena os dados sobre o mapa de calor.
	//São inicializadas todas as variáveis da matriz com o valor 0, e conforme o game passa, essas variáveis são incrementadas.
	int mapsCol = 0, mapsLin = 0;
	mapsCol = RetornaTamanhoDoMapa(jogo.mapa, 1);
	mapsLin = RetornaTamanhoDoMapa(jogo.mapa, 2);
	int calor[mapsLin][mapsCol];
	InicializaHeatMap(mapsLin, mapsCol, calor);

	//Printa no arquivo saída o jogo inicializado.
	fprintf(saidaArq,"Pontos: %d | Iteracoes: %d\n", jogo.pontos ,jogo.iter);
	PrintaComoEstaOJogo(jogo, saidaArq , 2);

	
	while(1){	
		AtualizaHeatMap(mapsLin,  mapsCol, calor, jogo);
		if(!ExisteInimigosVivos(jogo)){
			ganhou = 1;
			break;
		}
		else if(InimigoCruzouLinha(jogo)){
			perdeu = 1;
			break;
		}
		jogo.iter++;
		fscanf(entradaArq, "%c", &comando);
		ret = fscanf(entradaArq, "%*c");
		
		if(feof(entradaArq)){
			if(jogo.iter > 200){
				printf("passei aqui, terceiro if");
			}
			break;
		}
		jogo = RealizaPartida(jogo, comando, resumoArq);
		fprintf(saidaArq,"Pontos: %d | Iteracoes: %d\n", jogo.pontos ,jogo.iter);
		PrintaComoEstaOJogo(jogo, saidaArq , 2);
	}
	
	if (ganhou == 1){
		fprintf(saidaArq,"Parabéns, você ganhou!\n");
	}
	
	if (perdeu == 1){
		fprintf(saidaArq,"Você perdeu, tente novamente!\n");
	}
	
	GerarRanking(jogo, rankingArq);
	GerarEstatisticas(jogo, estatisticasArq);
	GerarHeatMap(mapsLin, mapsCol, calor, heatmapArq);

	fclose(heatmapArq);
	fclose (estatisticasArq);
	fclose(rankingArq);
	fclose(entradaArq);
	fclose(saidaArq);
	fclose(resumoArq);

	return jogo;
}

int JogadorColidiuComLateral(tJogo jogo){
	int colJog = 0, mapsCol = 0;
	mapsCol =	RetornaTamanhoDoMapa(jogo.mapa, 1);
	colJog = RetornaPosicaoDoJogador(jogo.player, 1);
	
	if(colJog == mapsCol - 1){
		return 1;
	}
	else if(colJog > 2){
		return 2;
	}
	else {
		return 0;
	}
}

int ExisteInimigosVivos(tJogo jogo){
	// Assumimos que todos estão mortos.
	// Retorno == 0, não existe inimigos vivos.
	// Retorno == 1, existe inimigos vivos.
	
	int ret = 0, i = 0;
	
	for (i = 0; i < jogo.QuantidadeInimigos; i++){
		if(!EstaMorto(jogo.ini[i])){
			ret = 1;
			break;
		}
	}
	return ret;
}

int InimigoCruzouLinha(tJogo jogo){
	// Analisa se algum inimigo cruzou a linha limite, ou seja, aquela que se cruzada o jogador perde o game.
	int i = 0;
	
	for (i = 0; i < jogo.QuantidadeInimigos; i++){
		if(!EstaMorto(jogo.ini[i]) && RetornaLinhaDoInimigo(jogo.ini[i]) == jogo.linhaLimite){
			return 1;
		}
	}
	
	return 0;
}

tJogo RealizaPartida(tJogo jogo, char comando, FILE * resumo){
	//Essa função é utilizada para realizar as partidas do jogo, ou seja, cada iteração. Nela fazemos as devidas movimentações dentro do mapa, de acordo com a entrada dada pelo jogador (nesse caso, o por meio do arquivo, entrada.txt).
	int colJog = 0, linJog = 0, mapsCol = 0, mapsLin = 0, j = 0, i = 0, tiroCol = 0, tiroLin = 0;

	tiroCol = RetornaPosicaoDoTiro(jogo.tiro, 1);

	mapsCol =	RetornaTamanhoDoMapa(jogo.mapa, 1);
	mapsLin =	RetornaTamanhoDoMapa(jogo.mapa, 2);
	
	colJog = RetornaPosicaoDoJogador(jogo.player, 1);
	linJog = RetornaPosicaoDoJogador(jogo.player, 2);


	//Verifica a ocorrencia de morte na iteração anterior e, se ocorreu, realiza efetivamente a morte. 
	if(jogo.OcorreuMorte != NaoHaMorte){
		jogo = RealizarMorte(jogo, jogo.OcorreuMorte);
	}
	
	//Movimenta um tiro ativo.
	if(jogo.TiroAtivo == ATIVO){
		jogo.tiro = MovimentaTiro(jogo.tiro);
		tiroLin = RetornaPosicaoDoTiro(jogo.tiro, 2);
		if(tiroLin == 0){
			jogo.TirosLixo++;
			jogo.TiroAtivo = INATIVO;
			//Quando chega na posição 0, significa que o tiro foi para a borda, tendo assim a necessidade de que o tiro seja desativado.
		}
	}
	
	jogo = MovimentaInimigos(jogo, resumo);
	
	if(comando == 'd'){
		if(colJog < mapsCol - 1){
			jogo.player = AlteraPosicao(jogo.player, comando);
			jogo.Mov++;
		}
		else {
			// Passa a vez, colisão.
			fprintf(resumo,"[%d] Jogador colidiu na lateral direita.\n", jogo.iter);
		}
	}

	
	if(comando == 'a'){
		if(colJog > 2){
			jogo.player = AlteraPosicao(jogo.player, comando);
			jogo.Mov++;
		}
		else {
			// Passa vez, colisão.
			fprintf(resumo,"[%d] Jogador colidiu na lateral esquerda.\n", jogo.iter);
		}
	}

	if(comando == ' '){
		if(jogo.TiroAtivo == 0){
			jogo = AdicionarTiroNaPartida(jogo);
			jogo.TirosEfetivos++;
		}
		// Passa vez.
	}

	jogo = OcorreuMorte(jogo, resumo);


	return jogo;
}

tJogo RealizarMorte(tJogo jogo, int morto){
	// Função que realiza todos os processos que validam a morte de um inimigo.
	int pntAtual = 0;
	jogo.ini[morto] =  MataOuAnimaInimigo(jogo.ini[morto] , 2); // Mata inimigo.
	pntAtual = RetornaPontosInimigo(jogo.ini[morto], jogo.mapa);
	jogo.pontos = jogo.pontos + pntAtual;
	jogo.OcorreuMorte = NaoHaMorte;
	jogo.TiroAtivo = INATIVO;
	
	return jogo;
}

int RetornaPontosInimigo(tInimigo ini, tMapa mapa){
	// Faz a contagem dos pontos de uma morte de inimigo.
	int pontos = 0;
	pontos = (ini.col)*(mapa.lin - ini.lin);
	return pontos;
}

tJogo OcorreuMorte(tJogo jogo, FILE * resumo){
	int i = 0, tiroCol, tiroLin = 0, mapsCol = 0, mapsLin = 0;
	
	// Analisa a sobreposição entre um tiro e um inimigo, se ocorrer, o inimigo morre.

	tiroCol = RetornaPosicaoDoTiro(jogo.tiro, 1);
	tiroLin = RetornaPosicaoDoTiro(jogo.tiro, 2);

	mapsCol = RetornaTamanhoDoMapa(jogo.mapa, 1);
	mapsLin = RetornaTamanhoDoMapa(jogo.mapa, 2);

	
	if(jogo.TiroAtivo == ATIVO){
		for (i = 0; i < jogo.QuantidadeInimigos; i++){
			if(ExisteInimigoAqui(jogo, jogo.ini[i], tiroLin, tiroCol) && !EstaMorto(jogo.ini[i]) && !InimigoCruzouLinha(jogo)){

				jogo.OcorreuMorte = i; // Carrega a informacão de qual inimigo morreu, a fim de realizar a morte no início da partida seguinte.

				fprintf(resumo,"[%d] Inimigo de indice %d da fileira %d foi atingido na posicao (%d %d).\n", jogo.iter, jogo.ini[i].ind, jogo.ini[i].fila, tiroCol, tiroLin);
				
				jogo.ini[i] = AtribuiDadosSobreMorte(jogo.ini[i], jogo.iter, mapsLin, tiroLin);
				jogo.InimigosMortos++;
			}
		}
	}
	
	return jogo;
}

tJogo AdicionarTiroNaPartida(tJogo jogo){
	jogo.TiroAtivo = ATIVO;
	jogo.tiro.col = jogo.player.col;
	jogo.tiro.lin = jogo.player.lin - 2;
	return jogo;
}

tJogador AlteraPosicao(tJogador player, char comando){
	if(comando == 'd'){
		player.col++;
	}
	if(comando == 'a'){
		player.col--;
	}
	return player;
}

int EhParaPrintarInimigo(tJogo jogo, int j , int i){
	int ret = 0, k = 0, iniCol = 0, iniLin = 0;
	
	for(k = 0; k < jogo.QuantidadeInimigos; k++){
		if(!EstaMorto(jogo.ini[k])){
			ret = ExisteInimigoAqui(jogo, jogo.ini[k], i, j);
		}
		if(ret && !EstaMorto(jogo.ini[k])){
			return ret;
		}
		ret = 0;
	}
	return 0;
}

int RetornaTipo(int tipo){
	if(tipo == 1 || tipo == 2){
		tipo++;
	}
	else if(tipo == 3){
		tipo = 1;
	}
	return tipo;
}

int TrocaSentidoDeMovInimigos(int EsquerdaOuDireita){
	if(EsquerdaOuDireita == 1){
		EsquerdaOuDireita = -1;
	}
	else if(EsquerdaOuDireita == -1){
		EsquerdaOuDireita = 1;
	}
	return EsquerdaOuDireita;
}	

tJogo MovimentaInimigos(tJogo jogo, FILE * resumo){
	//Essa função movimenta os inimigos, alterando suas posições.
	int ok = 1, i = 0, col = 0, aux = 0, bordas = 0, direita = 0, esquerda = 0, j = 0;
	
	if(jogo.danca != 0){
		jogo.danca = RetornaTipo(jogo.danca);
	}

	//A movimentação dos inimigos pode ser para a esquerda ou para a direita, isso depende de cada iteração.
	//Usei 1 para identificar a direção direita e -1 para a direção esquerda.
	if(jogo.EsquerdaOuDireita == 1){
		//Movimentação geral para todos inimigos.
		for (i = 0; i < jogo.QuantidadeInimigos; i++){
			if(!EstaMorto(jogo.ini[i])){
				jogo.ini[i].col++;
			}
      	}
		
		//Esse segundo loop verifica se algum inimigo foi para a borda. Se sim, esse inimigo é inclusive printado no resumo. A variavel borda, inicializada com 0, é incrementada quando ocorre a colisão com a borda.
		for (i = 0; i < jogo.QuantidadeInimigos;i++){
			if(!EstaMorto(jogo.ini[i])){
				if(jogo.ini[i].col > jogo.mapa.col - 1){
					bordas++;
					fprintf(resumo, "[%d] Inimigo de indice %d da fileira %d colidiu na lateral direita.\n",jogo.iter - 1, jogo.ini[i].ind, jogo.ini[i].fila);
				}
			}
		}

		//Se algum inimigo colidiu, também é necessario movimentar todos os inimigos para baixo e mudar a direção do jogo (de esquerda para direita ou de direita para esquerda). 
		if(bordas >= 1){
			jogo.EsquerdaOuDireita = TrocaSentidoDeMovInimigos(jogo.EsquerdaOuDireita);	
			for (j = 0; j < jogo.QuantidadeInimigos; j++){
            	jogo.ini[j].lin++;
				jogo.ini[j].col--;
      		}
			jogo.Descidas++;
		}
	
	}
	else if(jogo.EsquerdaOuDireita == -1){
		//Movimentação geral para todos inimigos.
		for (i = 0; i < jogo.QuantidadeInimigos; i++){
			if(!EstaMorto(jogo.ini[i])){
				jogo.ini[i].col--;
			}
      	}

		//Esse segundo loop verifica se algum inimigo foi para a borda. Se sim, esse inimigo é inclusive printado no resumo. A variavel borda, inicializada com 0, é incrementada quando ocorre a colisão com a borda.
		for (i = 0; i < jogo.QuantidadeInimigos;i++){
			if(!EstaMorto(jogo.ini[i])){
				if(jogo.ini[i].col < 2){	
					bordas++;
					fprintf(resumo, "[%d] Inimigo de indice %d da fileira %d colidiu na lateral esquerda.\n",jogo.iter - 1, jogo.ini[i].ind, jogo.ini[i].fila);
				}
			}			
		}

		//Se algum inimgo colidiu, também é necessario movimentar todos os inimigos para baixo e mudar a direção do jogo(de esquerda para direita ou de direita para esquerda). 
		if(bordas >= 1){
			for (j = 0; j < jogo.QuantidadeInimigos; j++){
    			jogo.ini[j].lin++;
				jogo.ini[j].col++;
			}			
			jogo.EsquerdaOuDireita = TrocaSentidoDeMovInimigos(jogo.EsquerdaOuDireita);	
			jogo.Descidas++;
		}
	}
	
	return jogo;
}

void InicializaHeatMap(int lin, int col, int HeatMap[lin][col]){
	int i = 0, j = 0;
	// Inicializa o mapa de calor com todos os pontos do mapa zerados, o que indica nenhuma passagem inicial. Além disso, conforme o game procede, os locais nos quais o tiro e jogador passam, são marcados com um contador +1;
	for (i = 0; i < lin; i++){
		for (j = 0; j < col; j++){
			HeatMap[i][j] = 0;
		}
	}
	return;
}

void GerarHeatMap(int lin, int col, int HeatMap[lin][col], FILE * heatmap){
	int i = 0, j = 0;

	for (i = 0; i < lin; i++){
		for (j = 0; j < col; j++){
			if(HeatMap[i][j] >= 999){
				fprintf(heatmap,"999 ");
			}
			else{
				fprintf(heatmap,"%3d ", HeatMap[i][j]);
			}
			
		}
		fprintf(heatmap,"\n");
	}
	return;
}

void AtualizaHeatMap(int lin, int col, int HeatMap[lin][col], tJogo jogo){
	//Essa função analisa a posição do player e do tiro e incrementa o valor do Heatmap, no local onde está esses, indicando que o tal objeto esteve ali.
	int i = 0, j = 0, colJog = 0, linJog = 0, tiroCol = 0, tiroLin = 0;

	colJog = RetornaPosicaoDoJogador(jogo.player, 1);
	linJog = RetornaPosicaoDoJogador(jogo.player, 2);

	tiroCol = RetornaPosicaoDoTiro(jogo.tiro, 1);
	tiroLin = RetornaPosicaoDoTiro(jogo.tiro, 2);

	i = linJog - 1;
	j = colJog - 1;

	//Temos que fazer esse incremento em varias direções a partir da posição central do player, uma vez que a nave ocupa mais de local no mapa, pois é feita a partir de 9 caracteres.
	HeatMap[i][j]++;
	HeatMap[i+1][j]++;
	HeatMap[i+1][j+1]++;
	HeatMap[i+1][j-1]++;
	HeatMap[i-1][j+1]++;
	HeatMap[i-1][j]++;
	HeatMap[i-1][j-1]++;
	HeatMap[i][j+1]++;
	HeatMap[i][j-1]++;
	if(jogo.TiroAtivo == ATIVO){
		HeatMap[tiroLin-1][tiroCol-1]++;
	}
	return;
}

void GerarRanking(tJogo jogo, FILE * ranking){
	int i = 0, j = 0;
	tInimigo mortos[jogo.InimigosMortos];
	
	// Passa todos os inimigos mortos para um novo vetor tInimigos que contém apenas os inimigos mortos.
	for(i = 0; i < jogo.QuantidadeInimigos;i++){
		if(EstaMorto(jogo.ini[i])){
			mortos[j] = jogo.ini[i];
			j++;
		}
	}
	
	OrdenaVetorCrescente(mortos, jogo);
	ImprimeNoArquivo(jogo, mortos, ranking);
	return;
}

void GerarEstatisticas(tJogo jogo, FILE * estatisticas){

	fprintf(estatisticas, "Numero total de movimentos (A ou D): %d;\nNumero de tiros efetivos: %d;\nNumero de tiros que nao acertaram: %d;\nNumero de descidas dos inimigos: %d;\n", jogo.Mov, jogo.TirosEfetivos, jogo.TirosLixo, jogo.Descidas);
	
	return;
}

void OrdenaVetorCrescente(tInimigo * mortos, tJogo jogo){
	int idx = 0, i = 0;
	

	// Ordena, de acordo com os críterios solicitados do trabalho, o vetor tInimigos.
	for(i = 0; i < jogo.InimigosMortos - 1; i++){
		idx = MenorValorEntreAeB(mortos, i + 1, jogo.InimigosMortos);
		if(mortos[i].linMorte > mortos[idx].linMorte){
			tInimigo aux;
			aux = mortos[i];
			mortos[i] = mortos[idx];
			mortos[idx] = aux;
		}
		else if(mortos[i].linMorte == mortos[idx].linMorte) {
			if(mortos[i].IteMorte > mortos[idx].IteMorte){
				tInimigo aux;
				aux = mortos[i];
				mortos[i] = mortos[idx];
				mortos[idx] = aux;
			}
		}
	}
	return;
}

int MenorValorEntreAeB(tInimigo * mortos, int a, int b){
	// Busca o menor valor entre dois limites de índices, "a" e "b".
	tInimigo menor;
	int i = 0, idx = 0;
	
	menor = mortos[a];
	idx = a;

	for (i = a+1 ; i < b; i++){
		if(menor.linMorte > mortos[i].linMorte){
			menor = mortos[i];
			idx = i;
		}
		else if(menor.linMorte == mortos[i].linMorte){
			if(menor.IteMorte > mortos[i].IteMorte){
				menor = mortos[i];
				idx = i;
			}
		}
	}
	return idx;
}

void ImprimeNoArquivo(tJogo jogo, tInimigo * mortos, FILE * ranking){
	// Escreve oficialmente no arquivo "ranking.txt".
	int i = 0;
	
	fprintf(ranking,"indice,fileira,linha,iteracao\n");

	for (i = 0; i < jogo.InimigosMortos;i++){
		fprintf(ranking,"%d,%d,%d,%d\n", mortos[i].ind, mortos[i].fila, mortos[i].linMorte, mortos[i].IteMorte);
	}
	return;
}

int RetornaLinhaDoInimigo(tInimigo ini){
	return ini.lin;
}

tTiro MovimentaTiro(tTiro tiro){
	tiro.lin--;
	return tiro;
}

tInimigo AtribuiDadosSobreMorte(tInimigo ini, int iter, int mapsLin, int tiroLin){
	ini.IteMorte = iter;
	ini.linMorte = mapsLin - tiroLin + 1;
	return ini;
}

