# Projeto 2 - Sistema de automação e monitoramento residencial
### Aluno: Matheus de Cristo Doreia Estanislau
### Matricula: 15/0141220

## Enunciado:
  ### O Enunciado do projeto pode ser acessado em:
  [Projeto 2 - 2020.2](https://gitlab.com/fse_fga/projetos_2020_2/projeto-2-2020.2)

![Imagem ilustrando o projeto](https://gitlab.com/fse_fga/projetos_2020_2/projeto-2-2020.2/-/raw/master/figuras/arquitetura.png)

## Execução do Projeto

Para realizar a execução do projeto os seguintes passos devem ser realizados:

1. Clonar o Repositório: ```https://github.com/MatheusEstanislau/FSE.git```
2. Entrar na pasta do projeto: ```cd projeto2/```
3. No servidor distribuido, entrar na pasta dedicada: ```cd distribuido/```
4. Executar o makefile: ```make```
5. No servidor central, entrar na pasta dedicada: ```cd central/```
6. Executar o makefile: ```make```
7. No servidor distribuido, executar o comando ```./bin/dist.o```
8. Após iniciar o servidor distribuido, no servidor central executar o comando ```./bin/app```
9. Ao executar será exibida, no servidor central, a mensagem de abertura do menu e amostragem da temperatura e humidade:
![mostrar menu](https://raw.githubusercontent.com/MatheusEstanislau/FSE/master/projeto2/prints/p1.png)


10. Ao inserir 1 o menu será exibido:

![menu](https://raw.githubusercontent.com/MatheusEstanislau/FSE/master/projeto2/prints/p2.png)


11. Ao pressionar as opções do 1 ao 12, serão modificado os estados das 4 lampadas e os dois ares-condicionados, como por exemplo:

![exemplo lampada 1](https://raw.githubusercontent.com/MatheusEstanislau/FSE/master/projeto2/prints/p3.png)


12. Ao pressionar a opção 15, é possivel visualizar o estado atual de todos os sensores (É necessário iniciar o servidor distribuido com lampadas e ares-condicionados desligados):

![exemplo estados](https://raw.githubusercontent.com/MatheusEstanislau/FSE/master/projeto2/prints/p4.png)

13. Também é possível realizar a ativação do alarme pressionando a opção 13 e desligá-lo com a opção 14.

![exemplo alaerme ligado](https://raw.githubusercontent.com/MatheusEstanislau/FSE/master/projeto2/prints/p6.png)
![exemplo alarme desligado](https://raw.githubusercontent.com/MatheusEstanislau/FSE/master/projeto2/prints/p7.png)

14. Com o alarme ativado, se ocorrer alguma interrupção em algum sendor de presença, portas ou janelas, o alarme será acionado:

![exemplo estados](https://raw.githubusercontent.com/MatheusEstanislau/FSE/master/projeto2/prints/p8.png)

15. Para desativar o alarme o usuário deverá pressionar 1, para abrir o menu e entrar com a opção 14, para desativar o alarme, e será exibida a mensagem que o alarme foi desativado:

![exemplo estados](https://raw.githubusercontent.com/MatheusEstanislau/FSE/master/projeto2/prints/p9.png)

16. No servidor distribuido, cada requisição é exibida com informação da operação incluindo data e hora, exemplo:

![exemplo estados](https://raw.githubusercontent.com/MatheusEstanislau/FSE/master/projeto2/prints/p12.png)

17.Ao finalizar com ctrl+c, ambos sistemas irão exibir mensagens de termino de execução:
![exemplo estados](https://raw.githubusercontent.com/MatheusEstanislau/FSE/master/projeto2/prints/p11.png)
