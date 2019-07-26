# LED Lighter

Programa feito para o terceiro projeto do laboratório de hardware da fatec sjc ministrada pelo professor Egydio. Sendo o segundo projeto a documentação de uma fonte de computador; e o primeiro a construção de um transformador com ponte de diodo completa.

Esse projeto do laboratório de hardware consistiu em montar um circuito com 8 leds na protoboard, montar um computador, formatar o computador, e fazer um programa que permitisse o controle do circuito com 8 leds através da porta paralela. Esse programa deveria ter controle individual de cada um dos leds, e era possível inventar mais qualquer coisa para isso.

Requisitos do programa:
- um sistema linux para rodar o programa
- `g++` (o CLI para compilar o programa)

Para baixar e instalar o software:

```bash
git clone https://github.com/vhoyer/led-lighter

cd led-lighter

make

sudo ./program
```

Para usar o programa, siga as instruções descritas na tela, no caso da
opção 2 e 3, as musicas, para parar a instrução aperte Ctrl-C e rode o
programa novamente.
