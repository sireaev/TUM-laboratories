.model small
.stack
.data
message1   db "A,B,C,D,E","$"
message2   db "1,2,3,4,5","$"
 
.code
 
main   proc
   mov   AX,seg message1
   mov   DS,AX
   mov   AX, seg message2
   mov   DS,AX
 
   mov   AH,09
   lea   DX,message1
   int   21h
   mov   AH,09
   lea   DX,message2
   int   21h
 
   mov   AX,4c00h
   int   21h
main   endp
end main