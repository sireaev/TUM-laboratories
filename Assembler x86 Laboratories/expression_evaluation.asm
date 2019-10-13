.model small
.stack 100h
.data
m db 1
e db 2
n db 3
o db 4
k db ?
.code
  mov ax,@data
  mov ds,ax
  mov al,[e]
  mul [o]
  mov bl,al
  mov al,[e]
  div [n]
  sub al,bl
  add al,[m]
  add al,30h
  mov [k],al
   xor dx,dx
  mov ah,09h
  lea dx, [k]
   int 21h
  mov ax,4c00h
  int 21h
end