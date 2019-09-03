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
