Dim i As Integer

Private Sub UserForm_Click()
    If (i = 0) Then
       Eticheta.Caption = "Ati dat click odata!"
       i = i + 1
    Else
        If (i = 1) Then
            Eticheta.Caption = "Ati dat click a 2 oara!"
            i = i + 1
        Else
            If (i = 2) Then
            Eticheta.Caption = "Ati dat click tocmai de 3 ori!"
                i = 0
            End If
        End If
    End If
    
End Sub

Private Sub CommandButton2_Click()
    MsgBox "Doriti sa iesiti?"
    Unload UserForm1
End Sub

Private Sub CommandButton1_Click()
    If (OptionButton1.Value = True) Then
        Eticheta.Caption = "Ati ales prima optiune!"
        Label1.Visible = False
    Else
        If (OptionButton2.Value = True) Then
            Eticheta.Caption = "Ati ales a doua optiune!"
            Label1.Visible = False
        Else
            If (OptionButton3.Value = True) Then
                Eticheta.Caption = "Ati ales a treia optiune!"
                Label1.Visible = False
            End If
        End If
    End If
        
End Sub
