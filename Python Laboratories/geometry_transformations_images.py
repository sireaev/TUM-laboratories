import tkinter
import time
import math
root = tkinter.Tk()
xw=0
tx=0
yw=0
ty=0
def patrat(x,y,culoare,t,s):
    canvas.create_rectangle((x+0)*s,(y+0)*s,(x+50)*s,(y+50)*s, fill=culoare, tag=t)
def triunghi(x,y,culoare):
    canvas.create_polygon((x+25),(y+0), (x+50),(y+50), (x+0),(y+50), fill=culoare )

def f_rot(x,y,xf,yf,a):
    a=math.radians(a)
    print(a)
    sin=math.sin(a)
    cos=math.cos(a)
    x1= x*cos - y*sin +xf- xf*cos +yf*sin
    y1= x*sin + y*cos +yf- xf*sin -yf*cos
    return (x1,y1)
    """
    Notam:
    x'=(x-xf)-(y-yf) * sin(alfa) + xf
    y'=(x-xf)* sin(alfa) + (y-yf) cos(alfa) + yf
    """
def rotatia():
    """
    ROTATIA CU UNGHIUL u=100
    """
    u=100
    a=[100,150]
    b=[150,150]
    c=[150,200]
    d=[100,200]
    #punctul de referinta
    xf=100
    yf=250
    a1=f_rot(a[0],a[1],xf,yf,u)
    a2=f_rot(b[0],b[1],xf,yf,u)
    a3=f_rot(c[0],c[1],xf,yf,u)
    a4=f_rot(d[0],d[1],xf,yf,u)
    print(a1)
    print(a2)
    print(a3)
    print(a4)
    print("rotat cu 100 grade ")
    canvas.create_rectangle(xf-2,yf-2,xf+2,yf+2, fill= "green")
    canvas.create_polygon((a1[0],a1[1] , a2[0],a2[1] , a3[0],a3[1] , a4[0],a4[1]  ),fill="green", outline="black" )

def scal(x,y):
    s=1.85
    #punctul de referinta
    xf=75
    yf=100
    canvas.create_rectangle(73,98,77,102,fill="red")
    x1=(x-xf)*s+xf
    y1=(y-yf)*s+yf
    print (x,y,"\n",x1,y1)
    return (x1,y1)

def scalare():
    'COEFICIENTUL DE SCALARE'
    a=[100,150]
    b=[150,200]
    a1=scal(a[0],a[1])
    a2=scal(b[0],b[1])
    canvas.create_rectangle(a1[0],a2[0],a1[1], a2[1], fill="green", tag="doi")
    print("scalat cu 2.2")
    
def t():
    'TRANSLATIA - DEPLASAREA X SI Y'
    xi=100
    yi=10
    """
    TRANSLATIA
    """
    x11=xw+tx
    y11=yw+ty
    canvas.create_rectangle(100+xi,150+yi,150+xi,200+yi, fill="green", tag=t)
    
    
        
canvas = tkinter.Canvas(root,width=400,height=400)
canvas.pack()

for i in range(10):
    canvas.create_line(50 * i, 1, 50 * i, 800)
    canvas.create_line(1, 50 * i, 800, 50 * i)
patrat(100,150,"red","unu",1)
triunghi(50,100,"green")

t()
scalare()
rotatia()

root.mainloop()
