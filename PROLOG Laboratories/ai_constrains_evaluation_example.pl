:- discontiguous regula/2.
regula(1,[boxer(_,_),boxer(_,_),boxer(_,_),boxer(_,_)]).
regula(2,Boxeri):-member(boxer(stefan,_),Boxeri),
    member(boxer(marin,_),Boxeri),
    member(boxer(maxim,_),Boxeri),
    member(boxer(radu,_),Boxeri).
regula(11,Boxeri) :- member(boxer(_,slab),Boxeri),
    member(boxer(_,puternic),Boxeri),
    member(boxer(_,maiputernic),Boxeri),
    member(boxer(_,foarteputernic),Boxeri).
maiputernic(P1,P2,[P1,P2,_,_]).
maiputernic(P1,P3,[P1,_,P3,_]).
maiputernic(P1,P4,[P1,_,_,P4]).
maiputernic(P2,P3,[_,P2,P3,_]).
maiputernic(P2,P4,[_,P2,_,P4]).
maiputernic(P3,P4,[_,_,P3,P4]).
regula(3,Boxeri):-maiputernic(Boxer1,Boxer2,Boxeri), Boxer1 = boxer(stefan,_), Boxer2 = boxer(marin,_).
regula(4,Boxeri):-maiputernic(Boxer1,Boxer2,Boxeri), Boxer1 = boxer(stefan,_), Boxer2 = boxer(maxim,_).
regula(44,Boxeri):-maiputernic(Boxer1,Boxer2,Boxeri),Boxer1 = boxer(marin,_),  Boxer2 = boxer(maxim,_).
regula(5,Boxeri):- maiputernic(Boxer1,Boxer2,Boxeri), Boxer1 = boxer(marin,_), Boxer2 = boxer(radu,_).
regula(55,Boxeri):-maiputernic(Boxer1,Boxer2,Boxeri),Boxer1 = boxer(marin,_), Boxer2 = boxer(maxim,_).
% intrebare: in ce mod trebuie amplasati boxerii de la cel mai slab la
% cel mai slab la cel mai puternic
intrebare(Nume,Boxeri):-member(boxer(Nume,_),Boxeri).
solutie(Nume,Boxeri):-regula(1,Boxeri),
    regula(2,Boxeri),
    regula(11,Boxeri),
    regula(3,Boxeri),
    regula(4,Boxeri),
    regula(44,Boxeri),
    regula(5,Boxeri),
    regula(55,Boxeri),
    intrebare(Nume,Boxeri),!.
%maxim
%radu
%marin
%stefan
