/*#####################################################################
 #					Sireaev Vladislav								 #
 #					Sentiment Analysis							 	 #
 #				UTM, FCIM IA-151									 #
 #		Analiza Deterministico-Statistica a Datelor					 #
 #		         PLEASE DO NOT REMOVE THIS							 #
 #####################################################################*/

#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
class Vocabular{
    string voc[10000];
    string term[100000];
    string word, sentiment;
    int counter, angercount, disgustcount, fearcount, joycount, sadnesscount, surprisecount;
    fstream streamin;
    ifstream vocin;
    int i, j;
public:
    
    void citire(){
        static string docs[]={
            "/Users/admin/Documents/Semestru4/ASDS/var12/10Aug2000politica.txt",
            "/Users/admin/Documents/Semestru4/ASDS/var12/10Aug2001politica.txt",
            "/Users/admin/Documents/Semestru4/ASDS/var12/10Dec2000politica.txt",
            "/Users/admin/Documents/Semestru4/ASDS/var12/10Feb2001politica.txt",
            "/Users/admin/Documents/Semestru4/ASDS/var12/10Jan2001politica.txt",
            "/Users/admin/Documents/Semestru4/ASDS/var12/10Jul2000politica.txt",
            "/Users/admin/Documents/Semestru4/ASDS/var12/10Jul2001politica.txt",
            "/Users/admin/Documents/Semestru4/ASDS/var12/10Mar2001politica.txt",
            "/Users/admin/Documents/Semestru4/ASDS/var12/10May2001politica.txt",
            "/Users/admin/Documents/Semestru4/ASDS/var12/10Nov2000politica.txt"
							 };
        
        i=j=angercount=disgustcount=fearcount=joycount=sadnesscount=surprisecount=0;
        int input;
        cout<<"Alegeti articolul de la 1 la 10:";cin>>input;
        try{
            if(cin.fail()){
                throw "Eroare! Nu este cifra!";
            }else{
                input-=1;
            }
        }catch(char* error){
            cout<<error<<endl;
        }
        streamin.open(docs[input].c_str());
        if (streamin){
            while ( streamin >> word )
            { 	counter++;
                
                char chars[] = "#_[];.,()-?!\"";
                for (unsigned int i = 0; i < strlen(chars); ++i)
                {
                    word.erase (std::remove(word.begin(), word.end(), chars[i]), word.end());
                }
                voc[j++]=word;
            }
            streamin.close();
        }else{
            cout<<"\nFile unable to open, please check for correction or check path location!";
        }
        cout<<"\n\nNr total de cuvinte:"<<counter<<"\n";
        static string sentimente[]={
            "/Users/admin/Documents/Semestru4/ASDS/feelings/anger.txt",
            "/Users/admin/Documents/Semestru4/ASDS/feelings/disgust.txt",
            "/Users/admin/Documents/Semestru4/ASDS/feelings/fear.txt",
            "/Users/admin/Documents/Semestru4/ASDS/feelings/joy.txt",
            "/Users/admin/Documents/Semestru4/ASDS/feelings/sadness.txt",
            "/Users/admin/Documents/Semestru4/ASDS/feelings/surprise.txt"
        };
        for(j=0, i = 0; i<6; i++){
            switch(i){
                case 0: {
                    vocin.open(sentimente[0].c_str());
                    if(vocin.good()){
                        while(vocin >> sentiment){if(sentiment!=""){
                            char chars[] = "#_[];.,()-?!\"";
                            for (unsigned int z = 0; z < strlen(chars); ++z)
                            {
                                sentiment.erase (std::remove(sentiment.begin(), sentiment.end(), chars[z]), sentiment.end());
                            }
                            for(int n=0;n<counter;n++)if(voc[n].length() > 2 && voc[n]!="in"&& voc[n]!="unei"&& voc[n]!="sau"&& voc[n]!="din"&& voc[n]!="unui"&& voc[n]!="este"&& voc[n]!="spre"&& voc[n]!="ceea"&& voc[n]!="urma" && voc[n]!="care"&& voc[n]!="avea"&& voc[n]!="acest"&& voc[n]!="prin"&&voc[n]!="face"&&voc[n]!="ceva"&&voc[n]!="pentru" && voc[n]==sentiment){angercount++;}
                        }
                        }
                    }else{cout<<"Unable to open!";}
                    vocin.close();
                }
                case 1:{
                    vocin.open(sentimente[1].c_str());
                    if(vocin.good()){
                        while(vocin >> sentiment){if(sentiment!=""){
                            char chars[] = "#_[];.,()-?!\"";
                            for (unsigned int z = 0; z < strlen(chars); ++z)
                            {
                                sentiment.erase (std::remove(sentiment.begin(), sentiment.end(), chars[z]), sentiment.end());
                            }
                            for(int n=0;n<counter;n++)if(voc[n].length() > 3 && voc[n]!="in" && voc[n]!="unei"&& voc[n]!="sau"&& voc[n]!="din"&& voc[n]!="unui"&& voc[n]!="este"&& voc[n]!="spre"&& voc[n]!="ceea"&& voc[n]!="urma" &&  voc[n]!="care"&& voc[n]!="avea"&& voc[n]!="acest"&& voc[n]!="prin"&&voc[n]!="face"&&voc[n]!="ceva"&&voc[n]!="pentru" && voc[n]==sentiment){disgustcount++;}
                        }
                        }
                    }else{cout<<"Unable to open!";}
                    vocin.close();
                }
                case 2:{
                    vocin.open(sentimente[2].c_str());
                    if(vocin.good()){
                        while(vocin >> sentiment){if(sentiment!=""){
                            char chars[] = "#_[];.,()-?!\"";
                            for (unsigned int z = 0; z < strlen(chars); ++z)
                            {
                                sentiment.erase (std::remove(sentiment.begin(), sentiment.end(), chars[z]), sentiment.end());
                            }
                            for(int n=0;n<counter;n++)if(voc[n].length() > 3 && voc[n]!="in" && voc[n]!="unei"&& voc[n]!="sau"&& voc[n]!="din"&& voc[n]!="unui"&& voc[n]!="este"&& voc[n]!="spre"&& voc[n]!="ceea"&& voc[n]!="urma" &&  voc[n]!="care"&& voc[n]!="avea"&& voc[n]!="acest"&& voc[n]!="prin"&&voc[n]!="face"&&voc[n]!="ceva"&&voc[n]!="pentru" && voc[n]==sentiment){fearcount++;}
                        }
                        }
                    }else{cout<<"Unable to open!";}
                    vocin.close();
                }
                case 3:{
                    vocin.open(sentimente[3].c_str());
                    if(vocin.good()){
                        while(vocin >> sentiment){if(sentiment!=""){
                            char chars[] = "#_[];.,()-?!\"";
                            for (unsigned int z = 0; z < strlen(chars); ++z)
                            {
                                sentiment.erase (std::remove(sentiment.begin(), sentiment.end(), chars[z]), sentiment.end());
                            }
                            for(int n=0;n<counter;n++)if(voc[n].length() > 3 && voc[n]!="in" && voc[n]!="unei"&& voc[n]!="sau"&& voc[n]!="din"&& voc[n]!="unui"&& voc[n]!="este"&& voc[n]!="spre"&& voc[n]!="ceea"&& voc[n]!="urma" &&  voc[n]!="care"&& voc[n]!="avea"&& voc[n]!="acest"&& voc[n]!="prin"&&voc[n]!="face"&&voc[n]!="ceva"&&voc[n]!="pentru" && voc[n]==sentiment){joycount++;}
                        }
                        }
                    }else{cout<<"Unable to open!";}
                    vocin.close();
                }
                case 4:{
                    vocin.open(sentimente[4].c_str());
                    if(vocin.good()){
                        while(vocin >> sentiment){if(sentiment!=""){
                            char chars[] = "#_[];.,()-?!\"";
                            for (unsigned int z = 0; z < strlen(chars); ++z)
                            {
                                sentiment.erase (std::remove(sentiment.begin(), sentiment.end(), chars[z]), sentiment.end());
                            }
                            for(int n=0;n<counter;n++)if(voc[n].length() > 3 && voc[n]!="in" && voc[n]!="unei"&& voc[n]!="sau"&& voc[n]!="din"&& voc[n]!="unui"&& voc[n]!="este"&& voc[n]!="spre"&& voc[n]!="ceea"&& voc[n]!="urma" &&  voc[n]!="care"&& voc[n]!="avea"&& voc[n]!="acest"&& voc[n]!="prin"&&voc[n]!="face"&&voc[n]!="ceva"&&voc[n]!="pentru" && voc[n]==sentiment){sadnesscount++;}
                        }
                        }
                    }else{cout<<"Unable to open!";}
                    vocin.close();
                }
                case 5:{
                    vocin.open(sentimente[5].c_str());
                    if(vocin.good()){
                        while(vocin >> sentiment){if(sentiment!=""){
                            char chars[] = "#_[];.,()-?!\"";
                            for (unsigned int z = 0; z < strlen(chars); ++z)
                            {
                                sentiment.erase (std::remove(sentiment.begin(), sentiment.end(), chars[z]), sentiment.end());
                            }
                            for(int n=0;n<counter;n++)if(voc[n].length() > 3 && voc[n]!="in" && voc[n]!="unei"&& voc[n]!="sau"&& voc[n]!="din"&& voc[n]!="unui"&& voc[n]!="este"&& voc[n]!="spre"&& voc[n]!="ceea"&& voc[n]!="urma" &&  voc[n]!="care"&& voc[n]!="avea"&& voc[n]!="acest"&& voc[n]!="prin"&&voc[n]!="face"&&voc[n]!="ceva"&&voc[n]!="pentru" && voc[n]==sentiment){surprisecount++;}	
                        }
                        }
                    }else{cout<<"Unable to open!";}
                    vocin.close();
                }
                default: {cout<<"Ati ales cifra inafara diapazonului!";break;}
            }
        }
        cout<<"\nNumarul de anger: "<<angercount<<" points.";
        cout<<"\nNumarul de disgust: "<<disgustcount<<" points.";
        cout<<"\nNumarul de fear: "<<fearcount<<" points.";
        cout<<"\nNumarul de joy: "<<joycount<<" points.";
        cout<<"\nNumarul de sadness: "<<sadnesscount<<" points.";
        cout<<"\nNumarul de surprise: "<<surprisecount<<" points.";
        float positive =joycount+surprisecount/2;
        float negative = angercount+disgustcount+fearcount+sadnesscount/4;
        cout<<"\nPozitiv: "<<positive<<" points.";
        cout<<"\nNegativ: "<<negative<<" points.";
        if(positive>negative) cout<<"\n\nArticolul selectat este pozitiv! :D"; else cout<<"\n\nArticolul dat este negativ! :(";
    };
};

int main() {
    Vocabular obiect1;
    obiect1.citire();
    return 0;
}

/*####################################################################
 #					Sireaev Vladislav								 #
 #					Sentiment Analysis							 	 #
 #				UTM, FCIM IA-151									 #
 #		Analiza Deterministico-Statistica a Datelor					 #
 #		         PLEASE DO NOT REMOVE THIS							 #
 #####################################################################*/

