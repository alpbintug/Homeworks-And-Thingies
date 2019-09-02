;Most of the variable names are in Turkish, I'll try to explaing each one

data SEGMENT PARA 'veri'
    dbg db 'Dizinin boyutunu giriniz.',0; String means "Enter the size of the array", dbg is the initials of that string
    deg db 'Dizinin elemanlarini giriniz.',0; String means "Enter the elements of the array", deg is the initials of that string
    kbc db 'Kod basari ile calistirildi.',0; String means "Code ran without errors", kbc is the initials of that string
    dyb db 'Siralamadan sonra diziniz:',0; String means "Your string after sorting:"
    dizi db 100 dup(?); Defining the array
    n db ? ;Defining the size of array
    CR EQU 13
    LF EQU 10
    HATA db 'YANLIS VERI GIRISI!!!',0
data ends

stack SEGMENT PARA STACK 'yigin'
    dw   128  dup(0) ;Defining the size of the stack
stack ends

code SEGMENT PARA 'kod'
    ASSUME SS:stack, DS:data, CS:code
ANA PROC FAR ; "ANA" means "MAIN"
    PUSH DS;Storing the necessary information and setting up the enviroment
    XOR AX,AX
    PUSH AX
    MOV AX,data
    MOV DS,AX     
    XOR SI,SI

    
    MOV AX,OFFSET dbg
    CALL PUT_STR
    CALL GETN 
    MOV n,AL
    CALL NEWLINE
    XOR CX,CX
    MOV  CL,n
    MOV AX,OFFSET deg
    CALL PUT_STR
 L1:   
 J1:
    CALL NEWLINE
    XOR AX,AX
    CALL GETN   
    CMP AX,128; If size of AX is more than 8 bits, we jump to the error (If control)
    JG HATAVAR
    CMP AX,-127
    JL HATAVAR
    MOV dizi[SI],AL;If there is no error, we continue the code as usual (Else branch of the If statement)
    INC SI
    CMP SI,CX
    JNE L1
    CMP SI,CX
    JE HATAYOK
    
HATAVAR:MOV AX,OFFSET HATA
        CALL PUT_STR
        CALL NEWLINE
        JMP J1       
        
     
HATAYOK:
    PUSH CX   
    XOR CX,CX
    PUSH DX
    MOV DL,n
    DEC DL
    
    CALL QUICKSORT

    POP DX
    POP CX



;DIZI YAZDIRMA ISLEMI (Printing the array)
    XOR SI,SI 
    PUSH CX
    XOR CX,CX
    MOV CL,n  
    CALL NEWLINE
    XOR AX,AX
    MOV AX, OFFSET dyb
    CALL PUT_STR
    
J3: XOR AX,AX
    CALL NEWLINE
    MOV AL,dizi[SI]
    CMP AL,127
    JB ND        ;NEGATIF OLUP OLMADIGINI KONTROL ETME (Checking if the number is negative or not)
    PUSH AX
    MOV AL, '-' ;If the number is negative we put '-' symbol, find the absolute value of that number and print both
    CALL PUTC
    POP AX
    NEG AX 
    ADD AX,256 

ND:
    CALL PUTN
    INC SI
    CMP SI,CX
    JNE J3
    POP CX 
    
    CALL NEWLINE
    MOV AX,OFFSET kbc
    CALL PUT_STR  
    
    RETF
ANA ENDP      

NEWLINE PROC NEAR
    PUSH AX
    PUSH DX
    MOV DL, 10
    MOV AH, 2
    INT 21H
    MOV DL, 13
    MOV AH, 2
    INT 21H
    POP DX
    POP AX
    RET
NEWLINE ENDP

GETC PROC NEAR   ; AL'YE DEGER ALIR
    MOV AH,1h
    INT 21H
    RET
GETC ENDP

PUTC PROC NEAR   ; AL'YI EKRANA YAZAR
    PUSH AX
    PUSH DX
    MOV DL,AL
    MOV AH,2
    INT 21H
    POP DX
    POP AX
    RET
PUTC ENDP

GETN PROC NEAR   ; AX'E DEGER ATAR
    PUSH BX
    PUSH CX
    PUSH DX
GETN_START:
    MOV DX,1
    XOR BX,BX
    XOR CX,CX
NEW:
    CALL GETC
    CMP AL,CR
    JE FIN_READ
    CMP AL, '-'
    JNE CTRL_NUM
NEGATIVE:
    MOV DX,-1
    JMP NEW
CTRL_NUM:
    CMP AL,'0'
    JB ERROR
    CMP AL, '9'
    JA ERROR
    SUB AL, '0'
    MOV BL,AL
    MOV AX,10
    PUSH DX
    MUL CX
    POP DX
    MOV CX,AX
    ADD CX,BX
    JMP NEW
ERROR:
    MOV AX, OFFSET HATA
    CALL PUT_STR
    JMP GETN_START
FIN_READ:
    MOV AX,CX
    CMP DX,1
    JE FIN_GETN
    NEG AX
FIN_GETN:   
    POP DX
    POP CX
    POP DX
    RET
GETN ENDP

PUT_STR PROC NEAR     ;AXDE ADRESI OLAN SONUNDA 0 OLAN DIZGIYI EKRANA YAZAR
    PUSH BX
    MOV BX,AX
    MOV AL, BYTE PTR[BX]
PUT_LOOP:
    CMP AL,0
    JE PUT_FIN
    CALL PUTC
    INC BX
    MOV AL, BYTE PTR[BX]
    JMP PUT_LOOP
PUT_FIN:
    POP BX
    RET
PUT_STR ENDP  

PUTN PROC NEAR   ;AX'I 10LUK TABANDA EKRANA YAZDIRIR
    PUSH CX
    PUSH DX
    XOR DX,DX
    PUSH DX
    MOV CX,10
    CMP AX,0
    JGE CALC_DIGITS
    NEG AX
    PUSH AX
    MOV AL, '-'
    CALL PUTC
    POP AX
CALC_DIGITS:
    DIV CX
    ADD DX, '0'
    PUSH DX
    XOR DX,DX
    CMP AX,0
    JNE CALC_DIGITS
    
DISP_LOOP:
    POP AX
    CMP AX,0
    JE END_DISP_LOOP
    CALL PUTC
    JMP DISP_LOOP
END_DISP_LOOP:
    POP DX
    POP CX
    RET
PUTN ENDP

QUICKSORT PROC NEAR ; DIZIYI SIRALAMA ISLEMI YAPILIYOR
    CMP CX,DX
    JGE QSB
    MOV BX,CX
    MOV SI,CX
    MOV DI,DX
AW:    
W1B:MOV AL,dizi[SI]
    CMP AL,dizi[BX]
    JG W1S
    CMP SI,DI
    JGE W1S
    INC SI
    JMP W1B
W1S:
W2B:XOR AX,AX
    MOV AL,dizi[DI]
    CMP AL,dizi[BX]
    JLE W2S
    DEC DI
    JMP W2B
W2S: 
   
    CMP SI,DI
    JGE IKC
    MOV AL,dizi[SI]
    XCHG AL,dizi[DI]
    MOV dizi[SI],AL 
    CMP SI,DI
    JL AW
    
IKC:
    XOR AX,AX
    MOV AL, dizi[BX]
    XCHG AL,dizi[DI]
    MOV dizi[BX],AL
    
    PUSH DX
    MOV DX,DI
    DEC DX
    
    CALL QUICKSORT
    
    POP DX
    MOV CX,DI
    INC CX
    
    CALL QUICKSORT
                       
                   
QSB:
    RET
QUICKSORT ENDP    
code ENDS
    END ANA

