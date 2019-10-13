Dim vect As Range
Private Sub CommandButton1_Click()
Dim sum As Double
    sum = SumaVector(vect)
    Label10.Caption = "Suma este: " & sum
End Sub
Private Sub CommandButton2_Click()
    Dim min As Double
    Dim max As Double
    min = MinVector(vect)
    max = MaxVector(vect)
    Label8.Caption = "Minimul este: " & min
    Label9.Caption = "Maximul este: " & max
End Sub
Private Sub CommandButton3_Click()
    Dim c As Double
    Dim n As Integer
    Dim col As Integer
    n = vect.Rows.Count
    c = TextBox1.Value
    ReDim scal(1 To n) As Double
    scal = ScaleVector(vect, c)
    col = TextBox2.Value
    Cells(1, col).Value = "Scaled"
    For i = 1 To n
        Cells(i + 1, col).Value = scal(i)
    Next i
End Sub
Private Sub CommandButton4_Click()
    Dim vect1 As Range
    Dim vect2 As Range
    Dim rez As Variant
    Dim col As Integer
    Set vect1 = Range(TextBox3.Value)
    Set vect2 = Range(TextBox4.Value)
    rez = Suma2Vec(vect1, vect2)
       If (VarType(rez) = vbString) Then
        MsgBox rez
    Else
        col = TextBox5.Value
        Cells(1, col).Value = "Suma 2 vectori"
            For i = 1 To vect1.Rows.Count
            Cells(i + 1, col).Value = rez(i)
        Next i
    End If
End Sub
Private Sub CommandButton5_Click()
    Dim col As Integer
    ReDim rez(1 To vect.Rows.Count) As Double
    rez = sortbul(vect)
    col = TextBox6.Value
        Cells(1, col).Value = "Sorted"
    For i = 1 To vect.Rows.Count
        Cells(i + 1, col).Value = rez(i)
    Next i
End Sub
Private Sub CommandButton6_Click()
    UserForm1.Hide
    Unload UserForm1
End Sub
Private Sub UserForm_Activate()
   Set vect = Worksheets("sheet1").Range(ActiveWindow.RangeSelection.Address)
End Sub
Public Function SumaVector(rng As Range) As Double
    Dim i As Integer
    Dim n As Integer
    Dim Suma As Double
        n = rng.Rows.Count
    For i = 1 To n
        Suma = Suma + rng(i)
    Next i
    SumaVector = Suma
End Function
Public Function MaxVector(rng As Range) As Double
    Dim i As Integer
    Dim n As Integer
    Dim max As Double
    ' Preluarea plajei de celule
    n = rng.Rows.Count
    max = rng(1)
    For i = 2 To n
        If (rng(i) > max) Then
            max = rng(i)
        End If
    Next i
    MaxVector = max
End Function
Public Function MinVector(rng As Range) As Double
    Dim i As Integer
    Dim n As Integer
    Dim min As Double
    ' Preluarea plajei de celule
    n = rng.Rows.Count
    min = rng(1)
    For i = 2 To n
        If (rng(i) < min) Then
            min = rng(i)
        End If
    Next i
    MinVector = min
End Function
Public Function ScaleVector(rng As Range, sc As Double) As Double()
    Dim i As Integer
    Dim n As Integer
    ' Preluarea plajei de celule
    n = rng.Rows.Count
    ReDim scaled(1 To n) As Double
    For i = 1 To n
        scaled(i) = sc * rng(i)
    Next i
    ScaleVector = scaled
End Function
Public Function Suma2Vec(rng1 As Range, rng2 As Range) As _
Variant
    Dim i As Integer
    Dim n1 As Integer
    Dim n2 As Integer
    ' Preluarea plajei de celule
    n1 = rng1.Rows.Count
    n2 = rng2.Rows.Count
    If (n1 <> n2) Then
        Suma2Vec = "Dimensiuni inegale."
        Exit Function
    End If
    ReDim vector(1 To n1) As Double
    For i = 1 To n1
        vector(i) = rng1(i) + rng2(i)
    Next i
    Suma2Vec = vector
End Function
Public Function sortbul(rng As Range) As Double()
    Dim temp As Double
    Dim i As Integer, j As Integer
    Dim n As Integer
    n = rng.Rows.Count
    ReDim A(1 To n) As Double
    For i = 1 To n
        A(i) = rng(i)
    Next i
    For i = 1 To n - 1
        For j = 1 To n - i
            If (A(j) > A(j + 1)) Then
                temp = A(j)
                A(j) = A(j + 1)
                A(j + 1) = temp
            End If
        Next j
    Next i
    sortbul = A
End Function
Private Sub UserForm_Click()
Set vect = Worksheets("sheet1").Range(ActiveWindow.RangeSelection.Address)
End Sub
