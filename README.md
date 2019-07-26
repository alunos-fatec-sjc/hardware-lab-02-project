# LED Lighter

Programa feito para o terceiro projeto do laboratório de hardware da fatec sjc ministrada pelo professor Egydio. Sendo o segundo projeto a documentação de uma fonte de computador; e o primeiro a construção de um transformador com ponte de diodo completa.

Esse projeto do laboratório de hardware consistiu em montar um circuito com 8 leds na protoboard, montar um computador, formatar o computador, e fazer um programa que permitisse o controle do circuito com 8 leds através da porta paralela. Esse programa deveria ter controle individual de cada um dos leds, e era possível inventar mais qualquer coisa para isso.

Quando a apresentação terminou, o professor comentou com a sala que ele tinha ficado desapontado porque ninguém tinha pensado em fazer algum diferencial, que o objetivo desse projeto era montar um produto e a gente estaria vendendo para ele, então mantenha isso em sua mente.

Outra dica que posso dar é: faça um manual para tudo que o grupo desenvolver, quanto mais material, mais destaque o grupo ganha.

# Como usar esse repositório

Requisitos do programa:
- um sistema linux para rodar o programa
- `g++` (o CLI para compilar o programa)

Para baixar e instalar o software, abra um terminal e rode os seguintes comandos:

```bash
git clone https://github.com/vhoyer/led-lighter

cd led-lighter

make

sudo ./program
```

Para usar o programa, siga as instruções descritas na tela, no caso da
opção 2 e 3, as musicas, para parar a instrução aperte Ctrl-C e rode o
programa novamente.
