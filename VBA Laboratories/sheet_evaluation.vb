Public Sub Numere()
Dim I As Integer
Randomize Timer
For I = 1 To 20
Sheets("Numere").Cells(I, 1) = _
Int(Rnd * 100) - 50
Next I
End Sub
Public Sub clean()
Dim I As Integer
Randomize Timer
For I = 1 To 20
Sheets("Numere").Cells(I, 1) = ""
Next I
End Sub
Public Sub Mutare()
Rem Declararea variabilelor
Dim I As Integer, IndPol As Integer, IndOtr As Integer
Rem Variabil?-indice pentru crearea adresei celulei elementelor pozitive
IndPol = 2
Rem Variabil?-indice pentru crearea adresei celulei elementelor negative
IndOtr = 4
Rem Introduce?i ?n celula B1 cuv?ntul "Pozitive"
Sheets("Pozitive").Range("B1") = "Pozitive"
Rem Introducerea ?n celula B1 cuv?ntul "Negative"
Sheets("Negative").Range("C1") = "Negative"
For I = 1 To 20
If Sheets("Numere").Cells(I, 1) > 0 Then
Sheets("Pozitive").Cells(IndPol, 2) = _
Sheets("Numere").Cells(I, 1)
IndPol = IndPol + 1
ElseIf Sheets("Numere").Cells(I, 1) < 0 Then
Sheets("Negative").Cells(1, IndOtr) = _
Sheets("Numere").Cells(I, 1)
IndOtr = IndOtr + 1
End If
Next I
End Sub
Public Sub CantPozNeg()
Rem Declararea variabilelor Pol,Otr,Nul
Rem- pentru calcularea cant. numerelor pozitive,negative,nule
Dim I As Integer, Pol As Integer, Otr As Integer, Nul As Integer
Rem Ini?ializarea variabilelor
Pol = 0
Otr = 0
Nul = 0
Rem Deschiderea ciclului pentru num?rarea numerelor
For I = 1 To 20
If Sheets("Numere").Cells(I, 1) > 0 Then
Pol = Pol + 1
ElseIf Sheets("Numere").Cells(I, 1) < 0 Then
Otr = Otr + 1
Else
Nul = Nul + 1
End If
Next I
Rem ?nscrierea pe pagina "Numere" rezultatul calculelor
With Sheets("Numere")
.Range("C1") = "Cantitatea +"
.Range("D1") = Pol
.Range("C2") = "Cantitatea -"
.Range("D2") = Otr
.Range("C3") = "Cantitatea 0"
.Range("D3") = Nul
End With
End Sub
Public Sub cleanmut()
Dim I As Integer, IndPol As Integer, IndOtr As Integer
IndPol = 1
IndOtr = 3
For I = 1 To 20
Sheets("Pozitive").Cells(IndPol, 2) = ""
IndPol = IndPol + 1
Sheets("Negative").Cells(1, IndOtr) = ""
IndOtr = IndOtr + 1
Next I
End Sub
Public Sub cleancant()
With Sheets("Numere")
.Range("C1") = ""
.Range("D1") = ""
.Range("C2") = ""
.Range("D2") = ""
.Range("C3") = ""
.Range("D3") = ""
End With
End Sub
Public Sub deseneaza()
        Dim j As Integer, I As Integer
        j = 0
        For I = 1 To 20
            For j = 5 To 9
            Sheets("Figura").Cells(5, j).Interior.ColorIndex = 37
            Sheets("Figura").Cells(5, j) = _
            Sheets("Numere").Cells(I, 1)
            I = I + 1
            Next j
            For j = 6 To 10
            Sheets("Figura").Cells(j, 9).Interior.ColorIndex = 37
            Sheets("Figura").Cells(j, 9) = _
            Sheets("Numere").Cells(I, 1)
            I = I + 1
            Next j
            j = 9
            Do While j >= 5
            Sheets("Figura").Cells(10, j).Interior.ColorIndex = 37
            Sheets("Figura").Cells(10, j) = _
            Sheets("Numere").Cells(I, 1)
            I = I + 1
            j = j - 1
            Loop
            j = 9
            Do While j >= 5
            Sheets("Figura").Cells(j, 5).Interior.ColorIndex = 37
            Sheets("Figura").Cells(j, 5) = _
            Sheets("Numere").Cells(I, 1)
            I = I + 1
            j = j - 1
            Loop
        Next I
End Sub
Public Sub cleanp()
     Dim j As Integer, I As Integer
        j = 0
        For I = 1 To 20
            For j = 5 To 9
            Sheets("Figura").Cells(5, j).Interior.ColorIndex = 0
            Sheets("Figura").Cells(5, j) = ""
            I = I + 1
            Next j
            For j = 6 To 10
            Sheets("Figura").Cells(j, 9).Interior.ColorIndex = 0
            Sheets("Figura").Cells(j, 9) = ""
            I = I + 1
            Next j
            j = 9
            Do While j >= 5
            Sheets("Figura").Cells(10, j).Interior.ColorIndex = 0
            Sheets("Figura").Cells(10, j) = ""
            I = I + 1
            j = j - 1
            Loop
            j = 9
            Do While j >= 5
            Sheets("Figura").Cells(j, 5).Interior.ColorIndex = 0
            Sheets("Figura").Cells(j, 5) = ""
            I = I + 1
            j = j - 1
            Loop
        Next I
End Sub
Public Sub mmmsp()
Dim max As Integer, min As Integer
Dim sum As Integer
Dim I As Integer
Dim produs As Double
Dim med As Double
Dim t As Integer
max = 0
produs = 1
min = Sheets("Numere").Cells(1, 1)
For I = 1 To 20
If Sheets("Numere").Cells(I, 1) > max Then
max = Sheets("Numere").Cells(I, 1)
End If
If Sheets("Numere").Cells(I, 1) < min Then
min = Sheets("Numere").Cells(I, 1)
End If
produs = produs * Sheets("Numere").Cells(I, 1)
sum = sum + Sheets("Numere").Cells(I, 1)
Next I
t = Worksheets("Numere").Range("A1:A20").Count
med = sum
med = med / t
With Sheets("Numere")
.Range("C4") = "Max"
.Range("C5") = "Min"
.Range("C6") = "Media"
.Range("C7") = "Suma"
.Range("C8") = "Produs"
.Range("D4") = max
.Range("D5") = min
.Range("D6") = med
.Range("D7") = sum
.Range("D8") = produs
End With
If max = 0 Then
MsgBox "Maximul nu a putut fi gasit"
End If
End Sub
Public Sub cleanmmmsp()
With Sheets("Numere")
.Range("C4") = ""
.Range("C5") = ""
.Range("C6") = ""
.Range("C7") = ""
.Range("C8") = ""
.Range("D4") = ""
.Range("D5") = ""
.Range("D6") = ""
.Range("D7") = ""
.Range("D8") = ""
End With
End Sub
