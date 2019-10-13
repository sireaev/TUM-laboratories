evenNumbers([],[]).
evenNumbers([H|T],L):- integer(H), 0 is H mod 2,
    append([H],L,L); evenNumbers(T,L).

%corect
listaPara([],[]).
listaPara([H|T],L1):- integer(H),
    (H mod 2 =:=0 -> L1=[H|T1],listaPara(T,T1); listaPara(T,L1) ).

%rotire la dreapta
rotate(List, N, RotatedList) :-
    length(Back, N),           % create a list of variables of length N
    append(Front, Back, List), % split L
    append(Back, Front, RotatedList).

%rotire la stinga
shift(L1, N, L2) :-
    append(Lx, Ly, L1), % L1 is Lx || Ly
    append(Ly, Lx, L2), % L2 is Ly || Lx
    length(Lx, N).      % The length of Lx is N

%rotirea necesara
rotire(L1,Directia,Nr,Rez) :- (Directia = dr,
    (length(Back, Nr), append(Front, Back, L1),
     append(Back, Front, Rez))),!;
(Directia = stg,( append(Lx, Ly, L1),
 append(Ly, Lx, Rez), length(Lx, Nr) )),!.
