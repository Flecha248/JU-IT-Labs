.MODEL SMALL
.STACK 100H
.DATA 
.CODE
MAIN PROC
MOV AX,@DATA
MOV DS,AX
MOV SI,1000H
MOV BX,2000H

MOV CL,02H
MOV CH, 03H

MOV [SI],CL
MOV [BX],CH

MOV CX,0H
MOV CL,[SI]
SUB CL,[BX]

 
NOT CL
ADD CL,01H


MOV DL,'-'
MOV AH, 02H
INT 21H

MOV DX,0H
MOV DL,CL
ADD DL,30H

MOV AH, 02H
INT 21H



MOV AH, 04H
INT 21H

MAIN ENDP
END MAIN
