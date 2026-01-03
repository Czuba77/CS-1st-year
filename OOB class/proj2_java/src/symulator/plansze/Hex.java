package symulator.plansze;

import symulator.Okno;
import symulator.Swiat;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Hex extends Swiat {

    public Hex(int HEIGHT1, int WIDTH1) {
        super(HEIGHT1, WIDTH1);
        czyHex = true;
    }

    public Hex(Okno okno) {
        super(okno);
        czyHex = true;
    }

    @Override
    protected void zapiszTypPlanszy() {
        try {
            FileWriter zapis = new FileWriter("zapisT.txt");
            zapis.write("Hex");
            zapis.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }

    @Override
    protected void wczytajPlansze() {
        int ii=1,jj=-1, kk=0, ll=0;
        try {
            File zapis = new File("zapisP.txt");
            Scanner s = new Scanner(zapis);
            s.useDelimiter("");
            while (true) {
                while(ii>kk) {
                    ii--;
                    jj++;
                    plansza[ii][jj]=s.next().charAt(0);
                    s.next().charAt(0);
                }
                s.next().charAt(0);
                if(ll< HEIGHT-1) {
                    ll++;
                }
                else if(kk< HEIGHT-1) {
                    kk++;
                }
                else {
                    break;
                }
                ii=ll+1;
                jj=kk-1;
            }
            s.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }


    @Override
    public void zapiszPlansze(){
        int ii=1,jj=-1, kk=0, ll=0;
        try {
            FileWriter zapis = new FileWriter("zapisP.txt");

        while (true) {
            while(ii>kk) {
                ii--;
                jj++;
                zapis.write(plansza[ii][jj] + " ");
            }
            zapis.write( "\n");
            if(ll< HEIGHT-1) {
                ll++;
            }
            else if(kk< HEIGHT-1) {
                kk++;
            }
            else {
                break;
            }
            ii=ll+1;
            jj=kk-1;
        }
        zapis.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
