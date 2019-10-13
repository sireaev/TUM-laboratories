.model small
.286
.stack 100h
.data
        a db 5
        b db 25
 
        e db ?
.code
        mov AX,@data
        mov DS,AX
 
        mov AL,a
        add AL,b
        mov e,AL
 
        mov AX,4c00h
        int 21h
end
