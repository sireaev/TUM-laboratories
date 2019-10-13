# Poligonul de repartitie
> x=c(-3.75,-0.75,0.25,1.25,3.25,5.25,7.25,9.25,10.25,12.25,14.25,16.25,18.25,21.25,24.25)
> p=c(0.04,0.06,0.07,0.07,0.06,0.10,0.15,0.12,0.10,0.08,0.06,0.03,0.03,0.02,0.01)
> plot(x,p,col="red",lwd=2,xlim=c(-4,25),ylim=c(0,0.15))
> lines(x,p,col="green",lwd=3)
> title("Poligonul de repartitie")

# Functia de repartitie
> Fp=c(rep(0,15))
> for(i in 1:14) Fp[i+1]=Fp[i]+p[i+1]
> plot(x,Fp,col="red",xlim=c(-4,25),ylim=c(0,1))
> for(i in 1:14)segments(x[i],Fp[i],x[i+1],Fp[i])
> title("Functia de repartitie")

# Valoarea medie si dispersia
> m=0
> for (i in 1:14) m=m+x[i]*p[i]
> m
> d=0
> for (i in 1:14) d=d+(x[i]-m)^2*p[i]
> d

# Repartitia binomiala (Prob=0.45)
> m=seq(0,25,by=1)
> prob=dbinom(0:25,prob=0.45,size=26)
> plot(m,prob,col=5)
> lines(m,prob,col="green",lwd=1)
> for(i in 1:25)segments(m[i],0,m[i],prob[i])
> title("Repartitia binomiala")