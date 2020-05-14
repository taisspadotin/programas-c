#include <stdio.h>
#include <string.h>
#include <stdlib.h>
FILE *arquivo;
typedef struct numero{
   char dado[40];
}NUM;
typedef struct nodo{
   NUM e;
   struct nodo *esq;
   struct nodo *dir;
} NO;
typedef NO *ARV;
ARV nova_arv()
{
    return NULL;
}
int EMPTY (ARV a)
{ return (a == NULL);}

ARV insere (ARV a, NUM b)
{ ARV nova;
  if (EMPTY(a))
    {
      nova = (ARV) malloc (sizeof(NO));
      nova->esq = NULL;
      nova->dir = NULL;
      nova->e = b;
      return nova;
    }
  else
    { if ( strcmp(a->e.dado,b.dado) < 0 )
        a->dir = insere(a->dir, b);
      else
        a->esq = insere(a->esq, b);
      return a;
    }
}
ARV procura (ARV a , char *b)
{
  NUM c;
  if (EMPTY(a))          return NULL;
  else
    if ( strcmp(a->e.dado,b) == 0 )  return a;
    else
      if ( strcmp(a->e.dado,b) < 0 )
                      return procura (a->dir, b);
      else            return procura (a->esq, b);
}
void inOrder (ARV a)//percorrendo a arvore em ordem
{
  if (! EMPTY(a) )
    { inOrder(a->esq);
      printf("\n%s", a->e.dado);
      inOrder(a->dir);
    }
}

ARV busca (char termo[], ARV a)
{
  ARV b;
  b = a;
  while (!EMPTY(b)){
     if (strcmp(b->e.dado, termo) == 0)
          return b;
     else
         if (strcmp(b->e.dado,termo) > 0)
             b = b->esq;
         else b = b->dir;
  }
  return NULL;
}

void inserirContrib(){
NUM e;
int i=0;
    system("cls");
    printf("\n\n Insira 1 novo numero: ");
    i=1;
    //scanf("%d",&i);
    arquivo = fopen("G:/EPO/arqtex.txt","ab");  // ab: opção de abertura do arquivo (append binary)
    while(i>0){
      printf("\n\nNovo numero:  ");
     scanf("%s",e.dado);
      fflush(stdin);
      fwrite(&e,sizeof(e),1,arquivo);
      i--;
   }
   fclose(arquivo);
}

ARV gerarArv(ARV a){
NUM e;
    arquivo = fopen("G:/EPO/arqtex.txt","rb");
    do{
    if (fread(&e,sizeof(e),1, arquivo) == 1)
        a=insere(a,e);
    }while (!feof(arquivo));

    fclose(arquivo);
    return a;
}

ARV dele(ARV a,  NUM b)
{
    ARV nova;

   if (EMPTY(a))
    {nova = (ARV) malloc (sizeof(NO));
     // nova->e = NULL;
      return nova;
    }
  else
    { if ( strcmp(a->e.dado,b.dado) < 0 )
        a->dir = dele(a->dir, b);
      else
        a->esq = dele(a->esq, b);
      return a;
    }
}

int main(){

    char termo[50];
    ARV a;
    ARV b;
    int opcao=0;
// char busc[50];
    while (opcao != 5){
        system("cls");
        printf("\n\n----------------MENU PRINCIPAL----------------");
        printf("\n\n  1 - Inserir Novo Numero (no arquivo)");
        printf("\n  2 - Exibir Todos os numeros(Ler do Arquivo, Gerar Arvore, Percorrer Arvore) ");
        printf("\n  3 - Procurar Numero (Ler do Arquivo, Gerar Arvore, Buscar Palavra)");
        printf("\n  4 - Remover Numero");
        printf("\n  5 - Finalizar");
        printf("\n\n  Opcao Escolhida: ");
        scanf("%d",&opcao);
        switch(opcao){
            case 1: inserirContrib();
            a=NULL;
            a=gerarArv(a);
            break;
            case 2: system("cls");
                    a=NULL;
                    a=gerarArv(a);
                    inOrder(a);
                    system("pause>>null");
                    break;
            case 3: system("cls");
                    printf("Digite o termo a ser procurado");
                    scanf("%s",&termo);
                    a=NULL;
                    a=gerarArv(a);  // Le do arquivo, gera a arvore
                    b=busca(termo,a);
                    if (b!=NULL) printf("\nTermo Encontrado: %s -> %s", b->e.dado);
                    system("pause>>null");
                    break;
            case 4:system("cls");
                    a=NULL;
                    a=gerarArv(a);
                    NUM busc;
                    printf("Numero a ser deletado");
                    scanf("%s",&busc);
                    b=dele(a, busc);
                    system("pause>>null");
                    break;

        }
    }
    return 0;

    }
