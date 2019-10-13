Private Sub CommandButton1_Click()
    'Initial curatim toata foaia Excel de datele precedente
    Cells.Select
    Selection.Clear
    'Cream si setam obiectul Connection
    Dim cn As New ADODB.Connection
    cn.ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0;" _
    & "Data Source=C:\Students.mdb"
    cn.Open
    'Cream interogarea
    Dim cmdCommand As New ADODB.Command
    With cmdCommand
        .ActiveConnection = cn
        .CommandText = "SELECT * FROM Students;"
        .CommandType = adCmdText
    End With
    'Cream obiectul recordset
    Dim rs As New ADODB.Recordset
    With rs
        .CursorType = adOpenStatic
        .CursorLocation = adUseClient
        .LockType = adLockOptimistic
        .Open cmdCommand
    End With
    'Pe baza la Recordset cream obiectul QueryTable si
    ' il inseram pe foaie, incepind cu a 4-lea rind
    Dim QT1 As QueryTable
    Set QT1 = ActiveSheet.QueryTables.Add(rs, Range("E4"))
    QT1.Refresh
    'Aflam cantitatea de inregistrari in QueryTable
    Dim nRowCount As Integer
    Dim oRange As Range
    Set oRange = QT1.ResultRange
    nRowCount = oRange.Rows.Count
End Sub
Private Sub CommandButton2_Click()
'PURPOSE: Copy/Paste An Excel Table Into a New Word Document
'NOTE: Must have Word Object Library Active in Order to Run _
  (VBE > Tools > References > Microsoft Word 12.0 Object Library)
'SOURCE: www.TheSpreadsheetGuru.com
Dim tbl As Excel.Range
Dim tbl2 As Excel.Range
Dim WordApp As Word.Application
Dim myDoc As Word.Document
Dim WordTable As Word.Table
'Optimize Code
  Application.ScreenUpdating = False
  Application.EnableEvents = False
'Copy Range from Excel
   If Cells.Range("E4") <> Empty Then
   Set tbl = ThisWorkbook.Worksheets(Sheet1.Name).Range("E4:J24")
   Else
   MsgBox "Nu sunt date!"
   Exit Sub
   End If
'Create an Instance of MS Word
  On Error Resume Next
    'Is MS Word already opened?
      Set WordApp = GetObject(class:="Word.Application")
    'Clear the error between errors
      Err.Clear
    'If MS Word is not already open then open MS Word
      If WordApp Is Nothing Then Set WordApp = CreateObject(class:="Word.Application")
    'Handle if the Word Application is not found
      If Err.Number = 429 Then
        MsgBox "Microsoft Word could not be found, aborting."
        GoTo EndRoutine
      End If
  On Error GoTo 0
'Make MS Word Visible and Active
  WordApp.Visible = True
  WordApp.Activate
'Create a New Document
  Set myDoc = WordApp.Documents.Add
'Copy Excel Table Range
  tbl.Copy
'Paste Table into MS Word
  myDoc.Paragraphs(1).Range.PasteExcelTable _
    LinkedToExcel:=False, _
    WordFormatting:=True, _
    RTF:=False
'Autofit Table so it fits inside Word Document
  Set WordTable = myDoc.Tables(1)
  WordTable.AutoFitBehavior (wdAutoFitWindow)
EndRoutine:
'Optimize Code
  Application.ScreenUpdating = True
  Application.EnableEvents = True
'Clear The Clipboard
  Application.CutCopyMode = False
End Sub
'Caluleaza media valorilor din Excel
Private Sub CommandButton3_Click()
Dim i As Integer, j As Integer, l
Dim nrcell As Integer, buget As Integer, contr As Integer
i = 5 'pentru parcurgerea elementelor pe rinduri
j = 9 'pentru calculul mediei
l = 10 'pentru calculul de bugetari si contractari
buget = 0
contr = 0
If Cells(i, j) <> Empty Then
Do While Cells(i, j) <> Empty
nrcell = nrcell + 1
media = media + Cells(i, j).Value
If Cells(i, l) = "C" Then
contr = contr + 1
Else
buget = buget + 1
End If
i = i + 1
Loop
Else
MsgBox "Nu sunt date de calculat!"
Exit Sub
End If
media = media / nrcell
With ActiveSheet
.Range("K4") = "Media Totala:"
.Range("K4").Font.Bold = True
.Range("K5") = media
.Range("L4") = "Total bugetari:"
.Range("L4").Font.Bold = True
.Range("L5") = buget
.Range("M4") = "Total contract:"
.Range("M4").Font.Bold = True
.Range("M5") = contr
End With
End Sub
'Sterge continutul in Excel
Private Sub CommandButton4_Click()
If Cells.Range("E4") <> Empty Then
Cells.Select
Selection.Clear
Else
MsgBox "Nu sunt date de sters!"
Exit Sub
End If
End Sub
