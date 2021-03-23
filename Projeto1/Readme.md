# Projeto 1 - Sistema Controlador de Temperatura
### Aluno: Matheus de Cristo Doreia Estanislau
### Matricula: 15/0141220

## Enunciado:
  ### O Enunciado do projeto pode ser acessado em:
  [Projeto 1 - 2020.2](https://gitlab.com/fse_fga/projetos_2020_2/projeto-1-2020.2)
  
## Objetivos:
O Projeto tem como objetivo a implementação do controle de temperatura de um sistema 
por meio de sispositivos embarcados, utilizando para seu controle o conceito do **Controle PID**[(Controlador proporcional integral derivativo)](https://pt.wikipedia.org/wiki/Controlador_proporcional_integral_derivativo)

## Execução do Projeto

Para realizar a execução do projeto os seguintes passos devem ser realizados:
1. Clonar o Repositório: ```git clone  https://github.com/MatheusEstanislau/FSE.git```
2. Entrar na pasta do projeto: ```cd FSE/Projeto1/```
3. Executar o Makefile: ```make```
4. Executar o Binário: ```./output```

Apos a execução do binário output o sistema de controle é iniciado:

![image](https://user-images.githubusercontent.com/44438591/112172528-8d4e2080-8bd3-11eb-948a-93777dc93849.png)

Se o usuário desejar mudar a temperatura de referência, deve digitar ctrl + z, após digitar este comando um menu
será aberto perguntando qual modo de operação deseja inserir, 0 para potenciômetro, 1 para usuário

![image](https://user-images.githubusercontent.com/44438591/112172740-bbcbfb80-8bd3-11eb-98f5-1565d1fe560b.png)

Caso usuário queira entrar com uma determinada temperatura, deverá escolher uma temperatura válida maior que 
a temperatura ambiente e menor que 90ºC

![image](https://user-images.githubusercontent.com/44438591/112172812-c9818100-8bd3-11eb-9929-b2f7597d5e1a.png)

Se o usuário entrar com uma temperatua válida, o sistema efeturará a mudança para modo de referência do usuário

![image](https://user-images.githubusercontent.com/44438591/112174068-dfdc0c80-8bd4-11eb-8f21-52ebe476c153.png)

Se o usuário entrar com temperatura inválida, o sistema retornará para o modo potenciômetro

![image](https://user-images.githubusercontent.com/44438591/112173184-1bc2a200-8bd4-11eb-91b7-b54204bda063.png)

Ao digitar ctrl+c o sistema será desligado

![image](https://user-images.githubusercontent.com/44438591/112173309-339a2600-8bd4-11eb-92df-690798f6b2fd.png)





## Resultados Obtidos
Os resultados obtidos foram armazenados em um csv e a partir de seus dados foram gerados gráficos com a biblioteca Plotly em Python.
Dados foram colhidos a cada 2 segundos, para melhor exibição do gráfico o intervalo foi alterado.

### Temperaturas
  ![gráfico1](https://raw.githubusercontent.com/MatheusEstanislau/FSE/master/Projeto1/graph1.png)
  
### Utilização da Ventoinha e Resistor
  ![gráfico2](https://raw.githubusercontent.com/MatheusEstanislau/FSE/master/Projeto1/graph2.png)
  
  
