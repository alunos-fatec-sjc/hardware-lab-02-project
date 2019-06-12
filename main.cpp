#include <bitset>
#include <iostream>
#include <stdio.h>
#include <sys/io.h>
#include <unistd.h>

#define PORT 0x378

using namespace std;

unsigned char chooseLed();

int main()
{
	int opcao = 0;

	ioperm(PORT, 3, 1);
	outb(0x00, PORT);

	do {
		printf("\n=====Acendedor de Leds=====\n");
		printf(" 0. Sair\n");
		printf(" 1. increment|contador|loucura\n");
		printf(" 2. music padrão { 11110000, 00001111 }\n");
		printf(" 3. music padrão 2\n");
		printf(" 4. Escolher leds\n");
		printf(" Selecione uma opcao: ");

		scanf("%d", &opcao);

		if (opcao == 1) {
			for(unsigned char i = 0x00; i < 0xFF; i++) {
				outb(i, PORT);
				usleep(50000);
			}
			outb(0x00, PORT);
		}
		else if (opcao == 2) {
			int bpm;
			int count;

			printf("\n bpm: ");
			scanf("%d", &bpm);
			printf("\n repetições: ");
			scanf("%d", &count);
			printf("\n Aperte Ctrl-C para parar prematuramente e rode o programa novamente");

			int i = 0;
			int lenght = 2;
			int arr[] = { 1+2+4+8, 128+64+32+16 };

			while(count--) {
				if (count % 2) {
					outb(arr[i++], PORT);
				} else {
					outb(0x00, PORT);
				}

				if (i == lenght) i = 0;
				usleep((60000 / bpm) * 1000 / 2);
			}
		}
		else if (opcao == 3) {
			int bpm;
			int count;

			printf("\n bpm: ");
			scanf("%d", &bpm);
			printf("\n repetições: ");
			scanf("%d", &count);
			printf("\n Aperte Ctrl-C para parar prematuramente e rode o programa novamente");

			int arr[] = { 255, 2, 4, 8, 16, 32, 64, 255, 64, 32, 16, 8, 4, 2 };

			int i = 0;
			int lenght = sizeof(arr)/sizeof(*arr);

			while(count--) {
				outb(arr[i++], PORT);

				if (i == lenght) i = 0;
				usleep((60000 / bpm) * 1000 / lenght * 2);
			}

			outb(0x00, PORT);
		}
		else if (opcao == 4) {
			unsigned char secondOption;

			do {
				secondOption = chooseLed();

				outb(secondOption, PORT);
			} while (secondOption != 0x00);
		}
	} while (opcao != 0);

	outb(0x00, PORT);

	return 0;
}

unsigned char chooseLed()
{
	unsigned char opcao;

	do {
		printf("\n Escolha 0 para voltar ao menu.");
		printf("\n Selecione uma led [unsigned char]: ");

		scanf("%hhu", &opcao);

		std::cout << "\n [" << std::bitset<8>((int)opcao) << "]\n";
	} while (opcao < 0x00 || opcao > 0xFF);

	return opcao;
}
