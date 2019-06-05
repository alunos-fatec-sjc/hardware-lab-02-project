#include <stdio.h>
#include <sys/io.h>

#define PORT 0x378

int main()
{
	int opcao = 0;

	ioperm(PORT, 3, 1);
	outb(0x00, PORT);

	do {
		printf("\n=====Acendedor de Leds=====\n");
		printf(" 1. Acender Leds\n");
		printf(" 2. Apagar Leds\n");
		printf(" 3. Escolher leds\n");
		printf(" 4. Sair\n");
		printf(" Selecione uma opcao: ");

		scanf("%d", &opcao);

		if (opcao == 1) {
			// caso a opcao seja 1, acende todos os leds pq ce ta
			// mandand um 0xFF que é 0b111111111 onde cada 1 representa
			// um led ligado
			outb(0xFF, PORT);
		}
		else if (opcao == 2) {
			// caso a opcao seja 2, apaga todos os leds pq ce ta
			// mandand um 0x00 que é 0b000000000 onde cada 0 representa
			// um led desligado
			outb(0x00, PORT);
		}
		else if (opcao == 3) {
			outb(chooseLed(), PORT);
		}
	} while (opcao != 4);

	outb(0x00, PORT);

	return 0;
}

unsigned char chooseLed()
{
	unsigned char opcao = 1;
	printf(" Selecione uma led [unsigned char]: ");
	scanf("%d", &opcao);

	if (opcao < 0x00 || opcao > 0xFF) {
		return 0x00;
	}

	return opcao;
}
