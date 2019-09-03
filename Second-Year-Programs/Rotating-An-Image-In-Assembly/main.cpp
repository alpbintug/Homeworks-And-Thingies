#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include "image_processing.cpp"


using namespace std;

void sagaDondur(short n, int resim);
void solaDondur(short n, int resim);

int main(void) {
	int M, N, Q, i, j, k;
	bool type;
	int efile, islem;
	char resimadi[100], sonek[10];
	printf("17011066\nAlp Bintug Uzun\n");
	do {
		printf("Islem yapilacak resmin yolunu (path) giriniz:\n-> ");
		scanf("%s", &resimadi);
		system("CLS");
		efile = readImageHeader(resimadi, N, M, Q, type);
	} while (efile > 1);
	printf("%s\n", resimadi);
	int** resim = resimOku(resimadi);

	short *resimdizi;
	resimdizi = (short*) malloc(N*M * sizeof(short));

	for (i = 0; i < N; i++) 
		for (j = 0; j < M; j++) 
			resimdizi[i*N + j] = (short) resim[i][j];

	int resimadres = (int) resimdizi;

	do {
		system("CLS");
		printf("\t     ISLEMLER\n");
		printf("------------------------------------\n");
		printf("1)  Resmi saga dondur\n");
		printf("2)  Resmi sola dondur\n");
		printf("0)  Cikis\n\n");
		printf("\"%s\" yolundaki resim icin yapilacak islemi seciniz\n-> ", resimadi);
		scanf("%d", &islem);
	} while (islem > 2 || islem < 0);

	switch (islem) {
		case 0:
			exit(0);
		case 1:
			sagaDondur(N, resimadres);
			strcpy(sonek, "_sag.pgm");
			break;
		case 2:
			solaDondur(N , resimadres);
			strcpy(sonek, "_sol.pgm");
			break;
		default:
			strcpy(sonek, "_orj.pgm");
			break;
	}

	for (k = 0; k < N * M; k++) {
		j = k % N;
		i = k / N;
		resim[i][j] = (int)resimdizi[k];
	}
	
	string::size_type pos = string(resimadi).find_last_of(".");
	resimadi[pos] = '\0';
	strcat(resimadi, sonek);
	resimYaz(resimadi, resim, N, M, Q);
	printf("\nIslem basariyla tamamlandi :)\n\"%s\" yolunda resim olusturuldu.\n\n", resimadi);
	system("PAUSE");
	return 0;
}

void sagaDondur(short n, int resim) {
	//KODUNUZU BURADAN BASLAYARAK YAZINIZ
	__asm {
		//TRANSPOZE ALMA
		XOR EDI,EDI
		XOR EBX,EBX
		MOV ESI,resim
		MOV CX,n
		SHL CX,1
	J1:	MOV BX,DI
	J2:	MOV AX,n
		XOR DX,DX
		PUSH AX
		PUSH EBX
		MUL BX
		PUSH DX
		PUSH AX
		POP EBX
		ADD EBX,EDI
		ADD EBX,ESI
		MOV DX,WORD PTR[EBX]
		POP EBX
		POP AX

		PUSH AX
		PUSH EDI
		PUSH DX
		MUL DI
		PUSH DX
		PUSH AX
		POP EDI
		ADD EDI,EBX
		ADD EDI,ESI
		POP DX
		XCHG DX,WORD PTR[EDI]
		POP EDI
		POP AX

		PUSH AX
		PUSH EBX
		PUSH DX
		MUL BX
		PUSH DX
		PUSH AX
		POP EBX
		ADD EBX,EDI
		ADD EBX,ESI
		POP DX
		MOV WORD PTR[EBX],DX
		POP EBX
		POP AX

		ADD BX,2
		CMP BX,CX
		JNE J2

		ADD DI,2
		CMP DI,CX
		JNE J1

		//TRANSPOZE ALMA SONU

		XOR EDI,EDI
	J3:	XOR EBX,EBX
	J4:	MOV AX,n
		XOR DX,DX
		PUSH AX
		PUSH EDI
		MUL DI
		PUSH DX
		PUSH AX
		POP EDI
		ADD EDI,EBX
		ADD EDI,ESI
		MOV DX,WORD PTR[EDI]
		POP EDI
		POP AX

		PUSH AX
		PUSH EDI
		PUSH DX
		ADD DI,2
		MUL DI
		PUSH DX
		PUSH AX
		POP EDI
		SUB EDI,EBX
		SUB EDI,2
		ADD EDI,ESI
		POP DX
		XCHG DX,WORD PTR[EDI]
		POP EDI
		POP AX

		PUSH AX
		PUSH EDI
		PUSH DX
		MUL DI
		PUSH DX
		PUSH AX
		POP EDI
		ADD EDI, EBX
		ADD EDI, ESI
		POP DX
		MOV WORD PTR[EDI], DX
		POP EDI
		POP AX

		ADD BX,2
		CMP BX,AX
		JNE J4

		ADD DI,2
		CMP DI,CX
		JNE J3

	}
	//KODUNUZU YAZMAYI BURADA BITIRINIZ
}

void solaDondur(short n, int resim) {
	//KODUNUZU BURADAN BASLAYARAK YAZINIZ
	__asm {
		//TRANSPOZE ALMA
		XOR EDI, EDI
		XOR EBX, EBX
		MOV ESI, resim
		MOV CX, n
		SHL CX, 1
		J1:	MOV BX, DI
			J2 : MOV AX, n
				 XOR DX, DX
				 PUSH AX
				 PUSH EBX
				 MUL BX
				 PUSH DX
				 PUSH AX
				 POP EBX
				 ADD EBX, EDI
				 ADD EBX, ESI
				 MOV DX, WORD PTR[EBX]
				 POP EBX
				 POP AX

				 PUSH AX
				 PUSH EDI
				 PUSH DX
				 MUL DI
				 PUSH DX
				 PUSH AX
				 POP EDI
				 ADD EDI, EBX
				 ADD EDI, ESI
				 POP DX
				 XCHG DX, WORD PTR[EDI]
				 POP EDI
				 POP AX

				 PUSH AX
				 PUSH EBX
				 PUSH DX
				 MUL BX
				 PUSH DX
				 PUSH AX
				 POP EBX
				 ADD EBX, EDI
				 ADD EBX, ESI
				 POP DX
				 MOV WORD PTR[EBX], DX
				 POP EBX
				 POP AX

				 ADD BX, 2
				 CMP BX, CX
				 JNE J2

				 ADD DI, 2
				 CMP DI, CX
				 JNE J1

				 //TRANSPOZE ALMA SONU

				 XOR EDI, EDI
				 J3 : XOR EBX, EBX
					  J4 : MOV AX, n
						   XOR DX, DX
						   PUSH AX
						   PUSH EDI
						   MUL DI
						   PUSH DX
						   PUSH AX
						   POP EDI
						   ADD EDI, EBX
						   ADD EDI, ESI
						   MOV DX, WORD PTR[EDI]
						   POP EDI
						   POP AX

						   PUSH AX
						   PUSH EDI
						   PUSH DX
						   ADD DI, 2
						   PUSH AX
						   SHL AX,1
						   SUB AX,DI
						   MOV DI,AX
						   POP AX
						   MUL DI
						   PUSH DX
						   PUSH AX
						   POP EDI
						   ADD EDI, EBX
						   ADD EDI, ESI
						   POP DX
						   XCHG DX, WORD PTR[EDI]
						   POP EDI
						   POP AX

						   PUSH AX
						   PUSH EDI
						   PUSH DX
						   MUL DI
						   PUSH DX
						   PUSH AX
						   POP EDI
						   ADD EDI, EBX
						   ADD EDI, ESI
						   POP DX
						   MOV WORD PTR[EDI], DX
						   POP EDI
						   POP AX

						   ADD BX, 2
						   CMP BX, CX
						   JNE J4

						   ADD DI, 2
						   CMP DI, AX
						   JNE J3

	}
	//KODUNUZU YAZMAYI BURADA BITIRINIZ
}