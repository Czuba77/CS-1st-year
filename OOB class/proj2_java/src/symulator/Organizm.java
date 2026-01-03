package symulator;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

@SuppressWarnings("DuplicatedCode")
public abstract class Organizm {
    protected final Swiat swiat;
    final static protected int OX=0;
    final static protected int OY=1;
    final static protected int WIN=1;
    final static protected int LOOSE=2;
    final static protected int SPECIAL_CASE=3;
    final static protected int POISON=4;
    final static protected int POLNOC = 0;
    final static protected int  POLUDNIE = 1;
    final static protected int WSCHOD = 2;
    final static protected int ZACHOD = 3;

    final static protected int LEWO = 0;
    final static protected int  PRAWO = 1;
    final static protected int LEWOG = 2;
    final static protected int LEWOD = 3;
    final static protected int PRAWOG = 4;
    final static protected int PRAWOD = 5;

    protected final int BOARD_WIDTH;
    protected final int BOARD_HEIGHT;
    final protected int  EXPAND_CHANCE = 14;

    protected String nazwa;
    private final int wiek;
    protected int sila;
    protected int inicjatywa;
    protected final int[] polozenie =new int[2];
    protected char znak;

    abstract void akcja();
    abstract void setCooldownPorodowy();
    public abstract int GetOy_poprz();
    public abstract int GetOx_poprz();
    abstract int  GetCooldownPorodowy();
    abstract void wykonanie_akcji(int kierunek);
    abstract void rozmnazanie(Organizm napotkany_org);

    Organizm(Swiat swiat, int ox, int oy, int wiek, int BOARD_WIDTH, int BOARD_HEIGHT) {
        this.wiek = wiek;
        this.polozenie[OX] = ox;
        this.polozenie[OY] = oy;
        this.swiat = swiat;
        this.BOARD_WIDTH = BOARD_WIDTH;
        this.BOARD_HEIGHT = BOARD_HEIGHT;
    }

    public final int GetOx() {
        return polozenie[OX];
    }

    public final int GetOy() {
        return polozenie[OY];
    }

    public final char GetZnak() {
        return znak;
    }

    public final String GetNazwa() {
        return nazwa;
    }

    final int GetInicjatywa() {
        return inicjatywa;
    }

    final int GetWiek() {
        return wiek;
    }

    public final int GetSila() {
        return sila;
    }

    public final Swiat GetWorld() {
        return swiat;
    }

    public void SetOx(int polozeniex) {
        polozenie[OX]=polozeniex;
    }

    public void SetOy(int polozeniey) {
        polozenie[OY] = polozeniey;
    }

    public void zwiekszSile(int howmuch) {
        sila += howmuch;
    }

    protected static int genRand(int min, int max) {
        Random rand = new Random();
        return (int) (rand.nextInt((max - min) + 1) + min);
    }

    void rysowanie() {
        int warun;
        String zdarzenie="";
        if (!swiat.setJesliWolnePole(polozenie[OX], polozenie[OY], znak)) {
            Organizm napotkany_org = swiat.findOrganizm(polozenie[OX], polozenie[OY], this);
            if(!(napotkany_org==null)) {
                if (!napotkany_org.GetNazwa().equals(this.GetNazwa())) {
                    warun = (int) napotkany_org.kolizja(this);
                    if (warun == WIN) {
                        zdarzenie = "Na polu (" + polozenie[OX] + "," + polozenie[OY] + "), doszlo do kolizji " +
                                this.nazwa + " wygral/a z " + napotkany_org.nazwa + ".\n";
                        swiat.zmienIteratorUsuwanie(this, napotkany_org);
                        swiat.zmienZnakNaPolu(polozenie[OX], polozenie[OY], znak);
                        swiat.dodajZdarzenie(zdarzenie);
                        napotkany_org.delOrganizm();
                    } else if (warun == LOOSE) {
                        zdarzenie = "Na polu (" + polozenie[OX] + "," + polozenie[OY] + "), doszlo do kolizji " +
                                napotkany_org.nazwa + " wygral/a z " + this.nazwa + ".\n";
                        swiat.dodajZdarzenie(zdarzenie);
                        this.delOrganizm();
                    } else if (warun == POISON) {
                        zdarzenie = "Na polu (" + polozenie[OX] + "," + polozenie[OY] + "), doszlo do kolizji " +
                                this.nazwa + " zatrul/a sie jedzac " + napotkany_org.nazwa + ".\n";
                        swiat.zmienIteratorUsuwanie(this, napotkany_org);
                        napotkany_org.delOrganizm();
                        swiat.zwolnijPole(polozenie[OX], polozenie[OY]);
                        swiat.dodajZdarzenie(zdarzenie);
                        this.delOrganizm();
                    }


                    //jesli nie zajdzie zaden z warunkow to wystapil special case ktory jest roziwazany w metodzie kolizja napotakanego organizmu
                } else {
                    rozmnazanie(napotkany_org);
                }
            }
            else{
                swiat.zmienZnakNaPolu(polozenie[OX], polozenie[OY], znak);
            }

        }
    }


    protected int kolizja(Organizm napotkany_org) {
        if (this.sila <= napotkany_org.sila) {
            return WIN;
        } else {
            return LOOSE;
        }
    }
   public void delOrganizm() {
        swiat.usunZwierze(this);
    }

    public void zapiszOrganizm(FileWriter zapis) {
        try{
            zapis.write(znak+"");
            zapis.write(" ");
            zapis.write(polozenie[OX]+"");
            zapis.write( " ");
            zapis.write( polozenie[OY]+"");
            zapis.write(" ");
            zapis.write( wiek+"");
            zapis.write( " ");
        }
        catch(IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

}
