%algoritmi_de_sortare(nume, timp_mediu, timp_limita, memorie, stabilitate)

:-dynamic algoritmi_de_sortare/5.
algoritmi_de_sortare(bubble_sort, 15, 25, 200.0, stabil).
algoritmi_de_sortare(selection_sort, 15, 25, 200.0, stabil).
algoritmi_de_sortare(insertion_sort, 15, 25, 200.0, stabil).
algoritmi_de_sortare(merge_sort, 10, 25, 100.0, stabil).
algoritmi_de_sortare(quick_sort, 5, 15, 59.0, instabil).

menu :- nl, nl, tab(15), 
    write('*********** Alegeti o optiune ***********'), nl, nl, tab(15),
    write('1. Deschide baza de cunostinte.'), nl, tab(15),
    write('2. Adaugare algoritm la inceput.'), nl, tab(15),
    write('3. Adaugare algoritm la sfirsit.'), nl, tab(15),
    write('4. Eliminare unui algoritm din baza.'),nl, tab(15),
    write('5. Eliminare mai multor algoritmi din baza.'),nl, tab(15),
    write('6. Eliminare tuturor algoritmilor din baza.'),nl, tab(15),
    write('7. Gasirea algoritmilor dupa nume. (Findall)'),nl, tab(15),
    write('8. Gasirea algoritmilor dupa memorie. (Bagof)'),nl, tab(15),
    write('9. Gasirea algoritmilor dupa stabilitate. (Setof)'),nl, tab(15),
    write('10. Salvarea bazei de cunostinte intr-un fisier.'),nl, tab(15),
    write('11. Memorare inregistrari.'),nl, tab(15),
    write('12. Deschidere fisier.'),nl, nl, tab(15),
    write('*****************************************'),nl, tab(15),
    write('13. Iesire!'),nl,nl.

root :- repeat, menu, read(Optiune),
executa(Optiune), nl, Optiune == 13, !.
executa(1) :- algoritmi_de_sortare(Nume, TimpMediu, TimpLimita, Memorie, Stabilitate),
    write(Nume), write(' are timpul mediu de executie  '), write(TimpMediu),
    write(', timp limita de '), write(TimpLimita),
    write(', are nevoie de memorie de '), write(Memorie), 
    write(' si este '), write(Stabilitate) ,nl, fail.
executa(1).
executa(2):- introdu_inceput.
executa(3):- introdu_sfirsit.
executa(4):- sterge_nume.
executa(5):- sterge_stabilitate.
executa(6):- sterge_toate.
executa(7):- cauta_denumire.
executa(8):- cauta_memorie.
executa(9):- cauta_stabilitate.
executa(10):- write("Introdu denumirea fisierului: "),
    read(Fisier), stocare(Fisier),
    write('Fisier salvat!').
executa(11):- write('Introdu denumirea fisierului in care se vor inregistra modificarile'), read(Fisier),create_file(Fisier).
executa(12):- open_file.
executa(13).

introdu_inceput:- (write("Introdu un nou algoritm la inceputul listei.\nIntrodu numele algoritmului "),read(N),
    write("Introdu timpul mediu "),read(T),
    write("Introdu timpul limita  "),read(L),
    write("Introdu memoria "),read(M)),
    write("Introdu stabilitatea "),read(S),
    asserta(algoritmi_de_sortare(N,T,L,M,S)),
    write("Noul algoritm de sortare a fost introdus cu succes"),fail.

introdu_sfirsit:- (write("Introdu un nou algoritm la sfirsitul listei.\nIntrodu numele algoritmului "),read(N),
    write("Introdu timpul mediu "),read(T),
    write("Introdu timpul limita  "),read(L),
    write("Introdu memoria "),read(M)),
    write("Introdu stabilitatea "),read(S),
    assertz(algoritmi_de_sortare(N,T,L,M,S)),
    write("Noul algoritm a fost introdus cu succes"),fail.

introdu(N,T,L,M,S):-asserta(algoritmi_de_sortare(N,T,L,M,S)).

sterge(N,T,L,M,S):-retin(sterge(N,T,L,M,S)),
    retract(algoritmi_de_sortare(N,T,L,M,S)).

sterge_nume :- write("Numele algoritmului ce va fi sters: "),
    read(N), algoritmi_de_sortare(N,_,_,_,_), retract(algoritmi_de_sortare(N,_,_,_,_)),
    write(N), write(" fost sters!").

sterge_stabilitate :- write("Stabilitatea algoritmului ce va fi stearsa: "),
    read(C), algoritmi_de_sortare(_,_,_,_,C), retractall(algoritmi_de_sortare(_,_,_,_,C)),
    write(C), write(" fost sters!").

sterge_toate :- retractall(algoritmi_de_sortare(_,_,_,_,_)),
    write("toti algoritmii din baza au fost eliminati!").

cauta_denumire :- write("Denumirile algoritmilor sunt: "),
    findall(X,algoritmi_de_sortare(X,_,_,_,_),L),write(L),fail.

cauta_memorie :- write("Memoriile algoritmilor sunt: "),nl,
    bagof(X, algoritmi_de_sortare(N, _, _, X, _), Lista),
    write(N), write(' are memoria '),write(Lista),write(' KB'),
    write(","),nl,fail.

cauta_stabilitate :- write("Stabilitatea algoritmilor sunt: "),nl,
    setof(X, algoritmi_de_sortare(Z,_,_,_,X),List),
    write(Z),write(" este "),write(List),nl,fail.

stocare(Fisier) :-  tell(Fisier), stocare, told.
stocare :- algoritmi_de_sortare(Nume, TimpMediu, TimpLimita, Memorie, Stabilitate),
    write('algoritmi_de_sortare('), write(Nume), write(','),
    write(TimpMediu), write(','), write(TimpLimita), write(','),
    write(Memorie), write(','), write(Stabilitate), write(').'), nl, fail.
stocare.

create_file(Fisier):-telling(Old),tell(Fisier),listing,told,tell(Old), write('Fisier salvat!').

open_file :- write("Introdu denumire fisierului de deschis"),
    read(Fisier), consult(Fisier), nl,
    write('Fisierul '), write(Fisier), write(' a fost incarcat.'), nl.
