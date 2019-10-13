Private Sub execute_Click() 
Dim t As Integer
Dim i As Integer
Dim p As Integer
Dim a As Integer
p = 0
t = 0
a = 0
i = 3
Do While Cells(i, 4) <> Empty
     If Cells(i, 4).Value = "a" Then
   a = a + 1
   t = t + 1
   i = i + 1
   ElseIf Cells(i, 4).Value = "p" Then
    p = p + 1
    t = t + 1
    i = i + 1
    End If
Loop
total.Text = t
txtprez.Text = p
txtabs.Text = a
If prezent.Value Then
   i = 3
   Do While Cells(i, 4) <> Empty
     If Cells(i, 4).Value = "p" Then
   Sheets("Sheet1").Cells(i, 3).Font.Color = vbGreen
    Sheets("Sheet1").Cells(i, 4).Font.Color = vbGreen
    i = i + 1
   Else
   Sheets("Sheet1").Cells(i, 3).Font.Color = vbBlack
   Sheets("Sheet1").Cells(i, 4).Font.Color = vbBlack
   i = i + 1
    End If
  Loop
End If
If absent.Value Then
   i = 3
   Do While Cells(i, 4) <> Empty
     If Cells(i, 4).Value = "a" Then
   Sheets("Sheet1").Cells(i, 3).Font.Color = vbRed
    Sheets("Sheet1").Cells(i, 4).Font.Color = vbRed
    i = i + 1
   Else
   Sheets("Sheet1").Cells(i, 3).Font.Color = vbBlack
    Sheets("Sheet1").Cells(i, 4).Font.Color = vbBlack
    i = i + 1
    End If
 Loop
End If
If anulate.Value Then
   i = 3
   Do While Cells(i, 4) <> Empty
   Sheets("Sheet1").Cells(i, 3).Font.Color = vbBlack
   Sheets("Sheet1").Cells(i, 4).Font.Color = vbBlack
   i = i + 1
   Loop
total.Text = " "
txtprez.Text = " "
txtabs.Text = " "
End If
End Sub
Private Sub exitn_Click()
Unload form
End Sub
Private Sub CommandButton2_Click()
Label8.Caption = Date
End Sub
