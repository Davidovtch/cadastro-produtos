#include <stdio.h>

int code = 0; // controls the number of registred products
int maxNumberOfProducts = 3;
int keepRunning = 1;

struct Product
{
    char productName[20];
    float price;
} products[3];

int clean()
{
    printf("\e[1;1H\e[2J");
}

void search(){
    int codeNumber;
    int doWhile=1;
    int stayRunning;

    if(code==0){
        printf("Não há nenhum produto cadastrado\n");
    }
    else{
        do{
    printf("Diga o código do produto que deseja buscar: ");
    scanf("%d",&codeNumber);

    codeNumber=codeNumber-1;//corrects the diference between real numbers and array numbers

    if(codeNumber>=maxNumberOfProducts){
        printf("Código inválido\n");
    }

    else{
    printf("%s\n",products[codeNumber].productName);
    printf("%.2f\n",products[codeNumber].price);
    printf("Digite 1 se deseja procurar outro produto\nDigite 2 se deseja sair\n");
    scanf("%d",&stayRunning);
    clean();
    if (stayRunning==2)
    {
        doWhile=0;
    }
    }
        }while(doWhile==1);
    }
}

void registration()
{
    if (code < maxNumberOfProducts)
    {
        printf("Digite o nome do produto: ");
        scanf("%s", &products[code].productName);
        printf("Digite o preço do produto: ");
        scanf("%f", &products[code].price);
        code++;
    }
    else
    {
        printf("O sistema já está cheio\n");
    }
}

void intermediary(int chosenNumber)
{
    switch (chosenNumber)
    {
    case 1:
        clean();
        registration();
        break;
    case 2:
        clean();
        search();
        break;
    case 3:
        clean();
        keepRunning = 0;
        break;

    default:
        clean();
        printf("Número inválido\n");
        break;
    }
}
void main()
{
    int choice;
    printf("Olá,bem vindo ao nosso sistema!\n");

    do
    {
        printf("\nO que você gostaria de fazer?\n");
        printf("1-Cadastrar um produto\n");
        printf("2-Procurar um produto\n");
        printf("3-Sair do sistema\n");
        scanf("%d", &choice);
        intermediary(choice);
    } while (keepRunning == 1);
}