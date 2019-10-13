from PIL import Image, ImageDraw
def imagine():
    gridcolor="white"
    im = Image.new('RGBA', (900, 900), (0,0, 0, 0))
    draw = ImageDraw.Draw(im)   
    draw.rectangle((0,0,899,899), fill=1,outline=gridcolor)
    draw.rectangle((1,1,898,898), fill=1,outline=gridcolor)    
    draw.line((0,300,900,300), gridcolor, width=2)
    draw.line((0,600,900,600), gridcolor, width=2)
    draw.line((300,0,300,900), gridcolor, width=2)
    draw.line((600,0,600,900), gridcolor, width=2)
    #1 Patrat (TRIUNGHI COLORAT) 0,0/300,300
    x=150
    y=100
    draw.polygon(( (x,y),(x-100,y+100),(x+100,y+100)  ), fill="blue")
    #2 Patrat (POLIGON 16)  0,300/600,300
    x=425
    y=50
    draw.polygon( ((x,y),(x+50,y+0),(x+85,y+15),(x+115,y+45),(x+125,y+85),(x+125,y+115),(x+115,y+150),(x+90,y+180),(x+50,y+195),(x+0,y+195),
                   (x-35,y+180),(x-65,y+150),(x-75,y+115),(x-75,y+80),(x-65,y+45),(x-35,y+15)), outline="white")
    #3 Patrat (CERC COLORAT) 600,0/900,300
    x=675
    y=75
    draw.ellipse((x,y,x+150,y+150),fill="blue")
    #4 Patrat (SECTOR DE CERC COLORAT) 0,300/300,600
    x=50
    y=350
    draw.ellipse((x,y,x+150,y+150),fill="blue")
    draw.pieslice((x,y,x+150,y+150),270,0, fill="black", outline=None)
    #5 Patrat (LINIE) 300,300/600,600
    x=350
    y=550
    draw.line((x,y,x+200,y-200), fill="blue", width=4)
    #6 Patrat (DREPTUNGHI COLORAT) 600,300/900,600
    x=650
    y=400
    #draw.ellipse((x,y,x+150,y+150),fill="cyan")
    draw.rectangle((x,y,x+200,y+100), fill="blue")    
    #7 Patrat (PARALELIPIPED COLORAT) 0,600/300,900
    x=50
    y=700
    draw.rectangle((x,y,x+175,y+100), fill="white")
    draw.polygon( ((x,y),(x+25,y-25),(x+200,y-25),(x+175,y+0) ), fill="darkblue")
    draw.polygon( ((x+200,y-25),(x+175,y+0),(x+175,y+100),(x+200,y+75) ), fill="blue")
    #8 Patrat (ELIPSA) 300,600/600,900
    x=375
    y=700
    draw.ellipse((x,y,x+150,y+100),outline=gridcolor)
    #9 Patrat (SECTOR DE ELIPSA COLORAT) 600,900/900,900
    x=675
    y=700
    draw.ellipse((x,y,x+150,y+100),fill="blue")
    draw.polygon(( (x+75,y+50),(x+75,y-30),(x+180,y+50)  ), fill="black")
    im.save("img.bmp")
    print("Imaginea a fost salvata cu succes")
    ask = input ("Doresti sa vizualizezi imaginea din RAM? (da/nu)")
    if (ask.upper() == "DA"):
        im.show()
    ask = input ("Doresti sa vizualizezi imaginea din fisier? (da/nu)")
    if (ask.upper() == "DA"):
        img = Image.open('img.bmp')
        img.show()
imagine()
