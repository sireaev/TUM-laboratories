Private Sub CommandButton1_Click()
    Dim oContr As Document
    Dim c As Integer
    c = 0
    ' In acest caz e folosit discul C:\ dar el poate fi inlocuit dupa preferintele dvs.
    Set oContr = Application.Documents.Add("C:\contract.dot")
    oContr.Bookmarks("cnume").Range.Text = cnume.Value
    oContr.Bookmarks("cpnume").Range.Text = cpnume.Value
    If IsNumeric(cidnp.Value) = False Then
    MsgBox "Ati introdus IDNP-ul gresit!"
    Exit Sub
    Else
    oContr.Bookmarks("cidnp1").Range.Text = cidnp.Value
    oContr.Bookmarks("cidnp2").Range.Text = cidnp.Value
    End If
    oContr.Bookmarks("coras").Range.Text = coras.Value
    oContr.Bookmarks("cadresa").Range.Text = cadresa.Value
    If IsNumeric(cnr.Value) = False Then
    MsgBox "Ati introdus numarul de adresa gresit!"
    Else
    oContr.Bookmarks("cnr").Range.Text = cnr.Value
    End If
    If IsNumeric(ctelefon.Value) = False Then
    MsgBox "Ati introdus telefonul gresit!"
    Else
    oContr.Bookmarks("ctelefon").Range.Text = ctelefon.Value
    End If
    oContr.Bookmarks("amarca").Range.Text = amarca.Value
    oContr.Bookmarks("amodel").Range.Text = amodel.Value
    If IsNumeric(aanul.Value) = False Then
    MsgBox "Ati introdus anul gresit!"
    Else
    oContr.Bookmarks("aanul").Range.Text = aanul.Value
    End If
    oContr.Bookmarks("anrmatriculare").Range.Text = anrmatriculare.Value
    oContr.Bookmarks("acolor").Range.Text = acolor.Value
    If IsNumeric(duratl.Value) = False Then
    MsgBox "Ati introdus durata gresita!"
    Else
    oContr.Bookmarks("duratl").Range.Text = duratl.Value
    End If
    oContr.Bookmarks("fromd").Range.Text = fromd.Value
    oContr.Bookmarks("fromh").Range.Text = fromh.Value
    oContr.Bookmarks("tod").Range.Text = tod.Value
    oContr.Bookmarks("toh").Range.Text = toh.Value
    If IsNumeric(gajl.Value) = False Then
    MsgBox "Ati introdus gaj gresit!"
    Else
    oContr.Bookmarks("gajl").Range.Text = gajl.Value
    End If
    If IsNumeric(cuant.Value) = False Then
    MsgBox "Ati introdus cuantul gresit!"
    Else
    oContr.Bookmarks("cuant").Range.Text = cuant.Value
    End If
    If IsNumeric(tcost.Value) = False Then
    MsgBox "Ati introdus suma totala gresit!"
    Else
    oContr.Bookmarks("tcost").Range.Text = tcost.Value
    End If
    If fuel.Value = True Then
        oContr.Bookmarks("tipp").Range.Text = fuel.Caption
    ElseIf diesel.Value = True Then
        oContr.Bookmarks("tipp").Range.Text = diesel.Caption
    ElseIf gas.Value = True Then
        oContr.Bookmarks("tipp").Range.Text = gas.Caption
    ElseIf hybrid.Value = True Then
        oContr.Bookmarks("tipp").Range.Text = hybrid.Caption
    End If
    oContr.Bookmarks("currentd").Range.Text = Format(Date, "dd.mm.yyyy")
    UserForm1.Hide
    oContr.Activate
End Sub
Private Sub CommandButton2_Click()
UserForm1.Hide
End Sub
Private Sub UserForm_Click()
End Sub
