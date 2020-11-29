#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<time.h>
#include <windows.h>
#define MAX 100
typedef struct {
    int numeroCasa,cep,idFunc;
    char nomeFuncionario[50],setor[20],bairro[MAX], rua[MAX],cpfFuncionario[12],jornadaAlt[MAX],acesso,jornada;
    float horaEntrada,horaSaida,horaAlmoco,horaFimAlmoco;//pelo que eu pesquisei horario � armazenado em strings.

}dadosFuncionario;
int relatorios(){
    setlocale(LC_ALL,"Portuguese");
    char relatorio;
        printf("\t\t\t**************************************************\n");
        printf("\t\t\t\t\tEscolha uma das op��es:        \n");
        printf("\t\t\t\t\t1-Relat�rio de cadastro                           \n");
        printf("\t\t\t\t\t2-Relat�rio de funcion�rio (porID)                  \n");
        printf("\t\t\t**************************************************\n");
        printf("\t\t\t\t\t ");
        scanf(" %d",&relatorio);
            while((relatorio!=1)&&(relatorio!=2)){
                printf("\t\t\t\tOp��o inv�lida, digite novamente ");
                scanf(" %d",&relatorio);
            }

        if(relatorio==1)
            {
            printf("Em constru��o");
            return 0;
            }
        else if(relatorio==2)
            {
            printf("Em constru��o");
            return 0;
            }
    return 0;

}

int login_funcionario(){
    //Essa e a parte de Login do Funcionario.
    int id,cronometroAlmoco,cronometroHorasTrab;
    int horaEnt, horaAlmoco1, horaAlmoco2, horaSaida;
    int horaAtual,minutoAtual,segundoAtual,diaSemana,dia,mes,ano;
    char entrada,almoco1, saida, almoco2,fimProg,loadHora;
    setlocale(LC_ALL,"Portuguese");

    printf("\t\t\t**************************************************\n");
    printf("\t\t\t\t\tBem-vindo!\n");
    printf("\t\t\t\tPara realizar o login, digite seu ID\n");
    printf("\t\t\t\tOu digite 'S' para sair\n");
    printf("\t\t\t\t\t");
    scanf("%i",&id);

    if((id<=10)&&(id>=0))
        {
        printf("%d logado!",id);
        printf("\t\t\t**************************************************\n");
        }
    else
        {
         while((id>10)&&(id<0))
            {
            printf(" \nID inv�lido!");
            printf("\nDigite seu ID novamente: ");
            scanf(" %d",&id);
            }
        }
        FILE *arqHora;

        arqHora = fopen("horas totais.csv", "a");
        //fclose(arqId[cont]);

        if (arqHora==NULL)
            {
            printf("N�o conseguiu abrir o arquivo\n");
            }
        else
            {
            printf("Arquivo criado com sucesso\n");
            }

        //ponteiro para struct que armazena data e hora
          do{

            struct tm *data_hora_atual;

              //vari�vel do tipo time_t para armazenar o tempo em segundos
              time_t segundos;

              //obtendo o tempo em segundos
              time(&segundos);

              //para converter de segundos para o tempo local
              //utilizamos a fun��o localtime
              data_hora_atual = localtime(&segundos);

              //para acessar os membros de uma struct usando o ponteiro
              //utilizamos o operador -> no nosso caso temos:
              //data_hora_atual->membro_da_struct

              //Acessando dados convertidos para a struct data_hora_atual

              diaSemana=data_hora_atual->tm_wday;

          /*Obtendo os valores da struct data_hora_atual
            e formatando a sa�da de dados no formato
            hora: minuto: segundo
          */
          printf("\nHora ........: %d:",data_hora_atual->tm_hour);//hora
          horaAtual=data_hora_atual->tm_hour;

          printf("%d:",data_hora_atual->tm_min);//minuto
          minutoAtual==data_hora_atual->tm_hour;

          printf("%d\n",data_hora_atual->tm_sec);//segundo
          segundoAtual==data_hora_atual->tm_hour;

          /* Obtendo os valores da struct data_hora_atual
             e formatando a sa�da de dados no formato dia/mes/ano
          */
          //dia do m�s
          printf("\nData ........: %d/", data_hora_atual->tm_mday);//dia
          printf("%d/",data_hora_atual->tm_mon+1); //m�s
          printf("%d\n\n",data_hora_atual->tm_year+1900); //ano
            dia=data_hora_atual->tm_mday;
            mes=data_hora_atual->tm_mon+1;
            ano=data_hora_atual->tm_year+1900;



        if((diaSemana>0)&&(diaSemana<6))
        {
            if((horaAtual==8)&&(minutoAtual<=15)&&(entrada!='s'))
                {
                printf("\t\t\t**************************************************\n");
                printf("Entrada Marcada com sucesso!\n");
                entrada='s';
                fprintf(arqHora,"Entrada de %d em %d/%d/%d: %d:%d",id,dia,mes,ano,horaAtual,minutoAtual);

                printf("Digite 'r' para fazer o recarregar a hora ou qualquer outra letra para aguardar");
                scanf(" %c",&loadHora);
                while(loadHora!='r')
                    {
                        system("pause");
                        printf("Digite 'r' para fazer o recarregar a hora ou qualquer outra letra para aguardar");
                        scanf(" %c",&loadHora);
                    }
                //fprintf(arq,);
                }
            else if((entrada=='s')&&(horaAtual<10)&&(horaAtual<15))
                {
                printf("\t\t\t**************************************************\n");
                printf("\nMarcar a sa�da para Almo�o?S(sim) e N(n�o): ");
                scanf(" %c",&almoco1);
                fprintf(arqHora,"Sa�da de %d para almo�o em %d/%d/%d: %d:%d",id,dia,mes,ano,horaAtual,minutoAtual);

                //vari�veis
                int sec=0;
                int min=0;
                int hr=0;

                    do
                    {
                        system("cls");//limpa a tela

                        printf("Cron�metro\n\n");

                        printf("\n\t\t\t\t%dh:%dm:%ds\n\n", hr,min,sec);

                        if(sec==60){
                            sec=0;
                            min++;
                        }

                        if(min==60){
                            min=0;
                            hr++;

                        }

                        if(hr==24){
                            hr=0;
                        }

                        Sleep(1000);//tem a fun��o de pausar a execu��o por um determinado tempo
                        sec++;

                    }while (hr==1);

                system("pause");

                printf("\t\t\t**************************************************\n");
                printf("\nFinal do hor�rio de almo�o!");
                printf("\nMarcar hor�rio de volta do almo�o? S(sim) e N(n�o): ");
                scanf(" %c",&almoco2);
                fprintf(arqHora,"Volta do almo�o de %d em %d/%d/%d: %d:%d",id,dia,mes,ano,horaAtual,minutoAtual);
                almoco2='s';
                printf("Digite 'r' para fazer o recarregar a hora ou qualquer outra letra para aguardar");
                scanf(" %c",&loadHora);
                while(loadHora!='r')
                    {
                        system("pause");
                        printf("Digite 'r' para fazer o recarregar a hora ou qualquer outra letra para aguardar");
                        scanf(" %c",&loadHora);
                    }

            }
            else if((horaAtual==18)&&(minutoAtual>=0)&&(minutoAtual<=15)&&(almoco2='s'))
            {
                printf("\t\t\t**************************************************\n");
                printf("\t\t\t\tTermino do dia!\n");
                fprintf(arqHora,"Hor�rio de Sa�da de %d em %d/%d/%d: %d:%d",id,dia,mes,ano,horaAtual,minutoAtual);
                printf("\t\t\t\tDeseja sair?S(sim) e N(n�o)");
                printf("\t\t\t\t\t ");
                scanf(" %c",&saida);

               if((saida!='s')&&(saida!='S'))
                {
                    system("pause");
                    printf("\nPara deslogar a qualquer momento digite 'S' para sair: ");
                    scanf(" %c",&saida);

                }
                else{

                    printf("\nDeslogado com sucesso!");
                    printf("\nBom descanso!");
                    printf(" \n****************************************************** \n");
                    fclose(arqHora);
                    return 0;
                }
            }
            else
                {
            printf("\nN�o � poss�vel marcar o ponto fora do hor�rio de trabalho, \n em caso de hor�rio especial entre em contato com o RH\n");
            system("pause");
            printf("\nDigite 'S' para sair: ");
            scanf(" %c",&saida);
                }
        }
    else
    {
        printf("\nN�o � poss�vel marcar o ponto durante o final de semana, \n em caso de hor�rio especial entre em contato com o RH\n");
        system("pause");
        printf("\nDigite 'S' para sair: ");
        scanf(" %c",&saida);
    }


    }while(loadHora!='r');
     return 0;
}


int cadastro(){
    setlocale(LC_ALL,"Portuguese");
    FILE*arqFunc;


    int menu,cont;


    dadosFuncionario c[10]; /*a letra "c" serve como variavel para representar a struct e conseguir
    usar as variaveis da struct.*/



    printf("\t\t\t**************************************************\n");
    printf("\t\t\t             Aqui voc� cadastra todos os funcion�rios da empresa  \n");
    printf("\t\t\t        A seguir preencha os dados solicitados atentamente!\n");
    printf("\t\t\t**************************************************\n");



   arqFunc=fopen("cadastro_todos_funcion�rios.csv","w");//a pois � a escrita inicial, que pode ter adendos.
    if (arqFunc==NULL)
        {
        printf("N�o conseguiu abrir o arquivo\n");
        }
    else
        {
        printf("Arquivo aberto com sucesso\n");
        }

    fprintf(arqFunc,"ID;Nome;CPF;Setor;Rua;N�mero;Bairro;CEP;Jornada\n;");//aqui precisa quebrar a linha mas nao vaiiiiiii sos
    for(cont=0; cont<10; cont++){
    /*Aqui � o cadastro dos funcion�rios, feito previamente.
    Itens de cadastro: CPF, nome do funcion�rio, setor, endere�o(rua,bairro,numero), jornada*/



        printf("Cadastro do funcion�rio ID:e%d:\n",cont);
        c[cont].idFunc=cont;

        printf("Informe o nome completo: \n");
        scanf(" %49[^\n]",c[cont].nomeFuncionario);
        setbuf(stdin,NULL);

        printf("Informe o CPF: \n");
        scanf(" %11[^\n]",c[cont].cpfFuncionario);//valida��o do CPF vendo a soma
        //fun��o que valida o CPF
        setbuf(stdin,NULL);

        printf("Informe o setor : \n");
        scanf(" %19[^\n]",c[cont].setor);//Aqui � possivel escrever o setor de trabalho: produ��o, RH, Administrativo etc
        setbuf(stdin,NULL);

        printf("Informe a Rua: \n");
        scanf(" %99[^\n]",c[cont].rua);


        setbuf(stdin,NULL);

        printf("Informe o Numero: \n");
        scanf(" %d",&c[cont].numeroCasa);
        setbuf(stdin,NULL);

        printf("Informe o Bairro: \n");
        scanf(" %99[^\n]",c[cont].bairro);
        setbuf(stdin,NULL);

        printf("Informe o CEP: \n");
        scanf(" %d",&c[cont].cep);


        printf("\nA jornada deste funcion�rio � a padr�o? (segunda � sexta das 08:00 �s 18:00 com uma hora de almo�o)\n digite S para SIM e N para N�O ");
        scanf(" %c",&c[cont].jornada);//Aqui � praxe, mas teremos apenas a jornada padr�o.
        while((c[cont].jornada!='S')&&(c[cont].jornada!='s')&&(c[cont].jornada!='n')&&(c[cont].jornada!='N')){
            printf("Resposta inv�lida, digite 'S' para jornada padr�o ou 'n' para jornada alternativa");
            scanf(" %c",&c[cont].jornada);
        }
            if((c[cont].jornada=='s')||(c[cont].jornada=='S')){
            fprintf(arqFunc,"%d;%s;%s;%s;%s;%d;%s;%d;%c\n;",c[cont].idFunc,c[cont].nomeFuncionario,c[cont].cpfFuncionario,c[cont].setor,c[cont].rua,c[cont].numeroCasa,c[cont].bairro,c[cont].cep,c[cont].jornada);
            //fprintf(arqId[cont],"Dados do funcion�rio: ID:%d,Nome: %s,CPF: %s,Setor: %s,Rua: %s,N�mero: %d,Bairro: %s,CEP: %d,Jornada Padr�o:%c\n;",c[cont].idFunc,c[cont].nomeFuncionario,c[cont].cpfFuncionario,c[cont].setor,c[cont].rua,c[cont].numeroCasa,c[cont].bairro,c[cont].cep,c[cont].jornada);
        }
        else{
            printf("Informe a jornada do Funcion�rio: \n");
            scanf(" %100[^\n]",&c[cont].jornadaAlt);
            fprintf(arqFunc,"%d;%s;%s;%s;%s;%d;%s;%d;%s\n;",c[cont].idFunc,c[cont].nomeFuncionario,c[cont].cpfFuncionario,c[cont].setor,c[cont].rua,c[cont].numeroCasa,c[cont].bairro,c[cont].cep,c[cont].jornadaAlt);
            //fprintf(arqId[cont],"Dados do funcion�rio: ID:%d,Nome: %s,CPF: %s,Setor: %s,Rua: %s,N�mero: %d,Bairro: %s,CEP: %d,Jornada Alternativa:%s\n;",c[cont].idFunc,c[cont].nomeFuncionario,c[cont].cpfFuncionario,c[cont].setor,c[cont].rua,c[cont].numeroCasa,c[cont].bairro,c[cont].cep,c[cont].jornadaAlt);
            }




 }

        fclose(arqFunc);
        printf("\n");
        printf("\n");
        printf("\n");
        printf("Arquivo fechado com sucesso\n");
        system("pause");
    }
int cadastroUnit(){
    int qtdFunc;
    int menu,cont;
    setlocale(LC_ALL,"Portuguese");
    FILE*arqFunc;
    printf("Quantos funcion�rios deseja cadastrar?");
    scanf("%d",qtdFunc);



    dadosFuncionario c[qtdFunc]; /*a letra "c" serve como variavel para representar a struct e conseguir
    usar as variaveis da struct.*/



    printf("\t\t\t**************************************************\n");
    printf("\t\t\t        A seguir preencha os dados solicitados atentamente!\n");
    printf("\t\t\t**************************************************\n");



   arqFunc=fopen("cadastro_todos_funcion�rios.csv","a");//a pois � a escrita inicial, que pode ter adendos.
    if (arqFunc==NULL)
        {
        printf("N�o conseguiu abrir o arquivo\n");
        }
    else
        {
        printf("Arquivo aberto com sucesso\n");
        }

    for(cont=0; cont<qtdFunc; cont++)
    {

        printf("Cadastro do funcion�rio ID:e%d:\n",cont);
        c[cont].idFunc=cont;

        printf("Informe o nome completo: \n");
        scanf(" %49[^\n]",c[cont].nomeFuncionario);
        setbuf(stdin,NULL);

        printf("Informe o CPF: \n");
        scanf(" %11[^\n]",c[cont].cpfFuncionario);//N�o deu tempo de validar
        setbuf(stdin,NULL);

        printf("Informe o setor : \n");
        scanf(" %19[^\n]",c[cont].setor);//Aqui � possivel escrever o setor de trabalho: produ��o, RH, Administrativo etc
        setbuf(stdin,NULL);

        printf("Informe a Rua: \n");
        scanf(" %99[^\n]",c[cont].rua);


        setbuf(stdin,NULL);

        printf("Informe o Numero: \n");
        scanf(" %d",&c[cont].numeroCasa);
        setbuf(stdin,NULL);

        printf("Informe o Bairro: \n");
        scanf(" %99[^\n]",c[cont].bairro);
        setbuf(stdin,NULL);

        printf("Informe o CEP: \n");
        scanf(" %d",&c[cont].cep);


        printf("\nA jornada deste funcion�rio � a padr�o? (segunda � sexta das 08:00 �s 18:00 com uma hora de almo�o)\n digite S para SIM e N para N�O ");
        scanf(" %c",&c[cont].jornada);//Aqui � praxe, mas teremos apenas a jornada padr�o.

        while((c[cont].jornada!='S')&&(c[cont].jornada!='s')&&(c[cont].jornada!='n')&&(c[cont].jornada!='N'))
                {
                printf("Resposta inv�lida, digite 'S' para jornada padr�o ou 'n' para jornada alternativa");
                scanf(" %c",&c[cont].jornada);
                }
                if((c[cont].jornada=='s')||(c[cont].jornada=='S'))
                    {
                fprintf(arqFunc,"%d;%s;%s;%s;%s;%d;%s;%d;%c\n;",c[cont].idFunc,c[cont].nomeFuncionario,c[cont].cpfFuncionario,c[cont].setor,c[cont].rua,c[cont].numeroCasa,c[cont].bairro,c[cont].cep,c[cont].jornada);

                    }
        else
            {
            printf("Informe a jornada do Funcion�rio: \n");
            scanf(" %100[^\n]",&c[cont].jornadaAlt);
            fprintf(arqFunc,"%d;%s;%s;%s;%s;%d;%s;%d;%s\n;",c[cont].idFunc,c[cont].nomeFuncionario,c[cont].cpfFuncionario,c[cont].setor,c[cont].rua,c[cont].numeroCasa,c[cont].bairro,c[cont].cep,c[cont].jornadaAlt);
            }




    }

        fclose(arqFunc);
        printf("\n");
        printf("\n");
        printf("\n");
        printf("Arquivo fechado com sucesso\n");
        system("pause");
}


int main()
{
        int opcao;
        int rhOpcao;
        char login;
        int inicio;//variavel de chamamento de fun��o;
        setlocale(LC_ALL, "Portuguese");

        printf("\t\t\t**************************************************\n");
        printf("\t\t\t\t\tEscolha uma das op��es:        \n");
        printf("\t\t\t\t\t1-RH                           \n");
        printf("\t\t\t\t\t2-Funcionario                  \n");
        printf("\t\t\t**************************************************\n");
        printf("\t\t\t\t\t ");
        scanf(" %d",&opcao);
         while((opcao!=1)&&(opcao!=2))
            {
                printf("\t\t\t\tOp��o inv�lida, digite novamente ");
                scanf(" %d",&opcao);
            }
        if(opcao==1)
            {
            printf("\t\t\t**************************************************\n");
            printf("\t\t\t\tBem vindo ao acesso para RH!         \n");
            printf("\t\t\t\tSelecione qual a op��o desejada:     \n");
            printf("\t\t\t\t1-Acrescentar cadastro funcion�rio \n");
            printf("\t\t\t\t2-Cadastrar novamente os funcion�rios \n");
            printf("\t\t\t\t3-Visualizar Relat�rios              \n");
            printf("\t\t\t\t4-Retornar ao menu              \n");
            printf("\t\t\t**************************************************\n");
            printf("\t\t\t\t\t ");
            scanf(" %d",&rhOpcao);

            while((rhOpcao!=1)&&(rhOpcao!=2)&&(rhOpcao!=3)&&(rhOpcao!=4))
                {
                printf("\t\t\t\tOp��o inv�lida, digite novamente ");
                scanf("%d",&rhOpcao);
                }
            if(rhOpcao==2)
                {
                inicio=cadastro();
                }
            else if(rhOpcao==1)
                {
                inicio=cadastroUnit();
                }
            else if(rhOpcao==3)
                {
                inicio=relatorios();
                }
            else if (rhOpcao==4)
                {
                inicio=main();
                }
            }

        if(opcao==2)
            {
                printf("\t\t\t**************************************************\n");
                printf("\t\t\t\tBem vindo ao acesso para Funcion�rios!\n");
                printf("\t\t\t\tDigite qualquer tecla para realizar o login.\n");
                printf("\t\t\t\tPara retornar ao menu de acesso, tecle 'n' \n");
                printf("\t\t\t**************************************************\n");
                printf("\t\t\t\t\t ");
                scanf(" %c",&login);

                if((login!='N')&&(login!='n'))
                    {
                    inicio=login_funcionario();
                    }
                else
                    {
                    inicio=main();
                    }

            }

return 0;
}

