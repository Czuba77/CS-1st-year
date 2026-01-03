package symulator;

import symulator.rosliny.*;
import symulator.zwierzeta.*;

import java.awt.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Objects;
import java.util.Scanner;
import java.util.Vector;

@SuppressWarnings("unchecked")
public abstract class Swiat {
    protected boolean czyHex;
    private final static int AntylopaInd = 0;
    private final static int LisInd = 1;
    private final static int OwcaInd = 2;
    private final static int WilkInd = 3;
    private final static int ZolwInd = 4;
    private final static int BarszczInd = 5;
    private final static int GuaranaInd = 6;
    private final static int MleczInd = 7;
    private final static int TrawaInd = 8;
    private final static int JagodyInd = 9;
    final static int CzlowiekInd = 10;

    private final static Color AntylopaKol = Color.gray;
    private final static Color LisKol = Color.orange;
    private final static Color OwcaKol = Color.black;
    private final static Color WilkKol = Color.red;
    private final static Color ZolwKol = Color.green;
    private final static Color BarszczKol = new Color(119,0,200);
    private final static Color GuaranaKol = Color.cyan;
    private final static Color MleczKol = Color.yellow;
    private final static Color TrawaKol = new Color(0,50,0);
    private final static Color JagodyKol = Color.pink;
    public final static Color CzlowiekKol = new Color(217,186,140);



    private boolean zakonczGre = false;
    private boolean wczytajGreB = false;
    protected int HEIGHT;
    protected int WIDTH;
    private int iterator=-1;
    private int ktory_urodzony;
    protected char[][] plansza;
    private Okno okno;
    private String dziennik_zdarzen;
    private Vector<Organizm> Organizmy;
    private czlowiek CzlowiekSwiat;

    int getWIDTH() {
        return WIDTH;
    }

    int getHEIGHT() {
        return HEIGHT;
    }


    private void wczytajGre() {
        wczytajDane();
        wczytajPlansze();
    }

    public void zapiszGre(){
        zapiszDane();
        zapiszPlansze();
        zapiszTypPlanszy();
    }

    protected abstract void zapiszTypPlanszy();
    protected abstract void wczytajPlansze() ;
    protected abstract void zapiszPlansze();
    private void wczytajDane(){
        try{

            int znakiteratora;
            File zapis=new File("zapis.txt");
            Organizmy=new Vector();
            dziennik_zdarzen = "";
            Scanner s = new Scanner(zapis);
            HEIGHT =s.nextInt();
            WIDTH =s.nextInt();

            plansza = new char [HEIGHT][WIDTH];

            znakiteratora=s.nextInt();
            iterator=s.nextInt();
            if(znakiteratora==0){
                iterator=iterator*(-1);
            }
            ktory_urodzony=s.nextInt();
            ktory_urodzony=0;
            String tmp="";
            tmp=s.nextLine();
            while (!Objects.equals(tmp, "_")) {
                dziennik_zdarzen += tmp + " ";
                if (tmp.endsWith("."))
                    dziennik_zdarzen += "\n";
                tmp=s.nextLine();
            }


            String ctmp;
            ctmp=s.next();
            int sila,silaflat,ox,oy,oxp,oyp,cp,cu,wiek;
            czlowiek czlowiek1;
            while(!ctmp.equals("_")) {
                switch (ctmp)
                {
                    case "a":
                        ox=s.nextInt();
                        oy=s.nextInt();
                        wiek=s.nextInt();
                        sila=s.nextInt();
                        oxp=s.nextInt() ;
                        oyp=s.nextInt();
                        cp=s.nextInt();
                        addOrganizm(new antylopa(this,ox,oy,get_and_incrementKtoryUrodzony(),sila,oxp,oyp,cp, WIDTH, HEIGHT));
                        break;
                    case "c":
                        ox=s.nextInt();
                        oy=s.nextInt();
                        wiek=s.nextInt();
                        sila=s.nextInt();
                        oxp=s.nextInt() ;
                        oyp=s.nextInt();
                        cp=s.nextInt();
                        silaflat=s.nextInt();
                        cu=s.nextInt();
                        czlowiek1 = new czlowiek(this, ox, oy, oxp, oyp, get_and_incrementKtoryUrodzony(), sila, silaflat,cu, cp, WIDTH, HEIGHT);
                        setCzlowiek(czlowiek1);
                        addOrganizm(czlowiek1);
                        break;
                    case "l":
                        ox=s.nextInt();
                        oy=s.nextInt();
                        wiek=s.nextInt();
                        sila=s.nextInt();
                        oxp=s.nextInt() ;
                        oyp=s.nextInt();
                        cp=s.nextInt();
                        addOrganizm(new lis(this,ox,oy,get_and_incrementKtoryUrodzony(),sila,oxp,oyp,cp, WIDTH, HEIGHT));
                        break;
                    case "o":
                        ox=s.nextInt();
                        oy=s.nextInt();
                        wiek=s.nextInt();
                        sila=s.nextInt();
                        oxp=s.nextInt() ;
                        oyp=s.nextInt();
                        cp=s.nextInt();
                        addOrganizm(new owca(this,ox,oy,get_and_incrementKtoryUrodzony(),sila,oxp,oyp,cp, WIDTH, HEIGHT));
                        break;
                    case "w":
                        ox=s.nextInt();
                        oy=s.nextInt();
                        wiek=s.nextInt();
                        sila=s.nextInt();
                        oxp=s.nextInt() ;
                        oyp=s.nextInt();
                        cp=s.nextInt();
                        addOrganizm(new wilk(this,ox,oy,get_and_incrementKtoryUrodzony(),sila,oxp,oyp,cp, WIDTH, HEIGHT));
                        break;
                    case "z":
                        ox=s.nextInt();
                        oy=s.nextInt();
                        wiek=s.nextInt();
                        sila=s.nextInt();
                        oxp=s.nextInt() ;
                        oyp=s.nextInt();
                        cp=s.nextInt();
                        addOrganizm(new zolw(this,ox,oy,get_and_incrementKtoryUrodzony(),sila,oxp,oyp,cp, WIDTH, HEIGHT));
                        break;
                    case "B":
                        ox=s.nextInt();
                        oy=s.nextInt();
                        wiek=s.nextInt();
                        addOrganizm(new symulator.rosliny.barszcz_sosnowskiego(this, ox, oy, get_and_incrementKtoryUrodzony(), WIDTH, HEIGHT));
                        break;
                    case "G":
                        ox=s.nextInt();
                        oy=s.nextInt();
                        wiek=s.nextInt();
                        addOrganizm(new symulator.rosliny.guarana(this, ox, oy,  get_and_incrementKtoryUrodzony(), WIDTH, HEIGHT));
                        break;
                    case "M":
                        ox=s.nextInt();
                        oy=s.nextInt();
                        wiek=s.nextInt();
                        addOrganizm(new mlecz(this, ox, oy,  get_and_incrementKtoryUrodzony(), WIDTH, HEIGHT));
                        break;
                    case "T":
                        ox=s.nextInt();
                        oy=s.nextInt();
                        wiek=s.nextInt();
                        addOrganizm(new trawa(this, ox, oy,  get_and_incrementKtoryUrodzony(), WIDTH, HEIGHT));
                        break;
                    case "W":
                        ox=s.nextInt();
                        oy=s.nextInt();
                        wiek=s.nextInt();
                        addOrganizm(new wilcze_jagody(this,ox, oy,  get_and_incrementKtoryUrodzony(), WIDTH, HEIGHT));
                        break;
                }
                ctmp=s.next();
            }
            s.close();
        }
        catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    private void zapiszDane(){
        try {
            FileWriter zapis = new FileWriter("zapis.txt");
            zapis.write( HEIGHT +"");
            zapis.write( "\n");
            zapis.write( WIDTH +"");
            zapis.write( "\n");
            if(iterator>=0) {
                zapis.write(1 + "");
                zapis.write("\n");
                zapis.write(iterator + "");
                zapis.write("\n");
            }
            else{
                zapis.write(0 + "");
                zapis.write("\n");
                int tmp=iterator*(-1);
                zapis.write(tmp + "");
                zapis.write("\n");
            }
            zapis.write( ktory_urodzony+"");
            zapis.write( "\n");
            zapis.write( dziennik_zdarzen+"");
            zapis.write( '_');
            zapis.write( "\n");
            for (int i = Organizmy.size()-1; i > -1; i--) {
                Organizmy.get(i).zapiszOrganizm(zapis);
                zapis.write( "\n");
            }
            zapis.write("_\n");
            zapis.close();
        }
        catch(IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }


    public Swiat(int HEIGHT1, int WIDTH1) {
    Organizmy=new Vector();
        dziennik_zdarzen="";
        HEIGHT = HEIGHT1;
        WIDTH = WIDTH1;
        iterator = 0;
        ktory_urodzony = 0;
        dziennik_zdarzen = "";
        plansza = new char[HEIGHT][WIDTH];
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                plansza[i][j] = '.';
            }
        }
        int random_numb,ox,oy;

        do {
            ox = Organizm.genRand(0, HEIGHT - 1);
            oy = Organizm.genRand(0, WIDTH - 1);
        } while (getZnakNaPolu(ox, oy) != '.');
        czlowiek czlowiek1 = new czlowiek(this,ox, oy,  ktory_urodzony++, WIDTH, HEIGHT);
        setCzlowiek(czlowiek1);
        addOrganizm(czlowiek1);

        for (int i = 0; i < HEIGHT * WIDTH / 15; i++) {
            random_numb = Organizm.genRand(0, 14);
            do {
                ox = Organizm.genRand(0, HEIGHT - 1);
                oy = Organizm.genRand(0, WIDTH - 1);
            } while (getZnakNaPolu(ox,oy)!='.');
            char[] orglist = {'a', 'l', 'o', 'w', 'z', 'B', 'G', 'M', 'T', 'W', 'a', 'l', 'o', 'w', 'z'};
            switch (orglist[random_numb])
            {
                case 'a':
                    addOrganizm(new antylopa(this,ox, oy,  ktory_urodzony++, WIDTH, HEIGHT));
                    break;
                case 'l':
                    addOrganizm(new lis(this,ox, oy,  ktory_urodzony++, WIDTH, HEIGHT));
                    break;
                case 'o':
                    addOrganizm(new owca(this,ox, oy,  ktory_urodzony++, WIDTH, HEIGHT));
                    addOrganizm(new owca(this,ox, oy,  ktory_urodzony++, WIDTH, HEIGHT));
                    break;
                case 'w':

                    addOrganizm(new wilk(this,ox, oy,  ktory_urodzony++, WIDTH, HEIGHT));
                    break;
                case 'z':

                    addOrganizm(new zolw(this,ox, oy,  ktory_urodzony++, WIDTH, HEIGHT));
                    break;
                case 'B':

                    addOrganizm(new barszcz_sosnowskiego(this,ox, oy,  ktory_urodzony++, WIDTH, HEIGHT));
                    break;
                case 'G':

                    addOrganizm(new guarana(this,ox, oy,  ktory_urodzony++, WIDTH, HEIGHT));
                    break;
                case 'M':

                    addOrganizm(new mlecz(this,ox, oy,  ktory_urodzony++, WIDTH, HEIGHT));
                    break;
                case 'T':

                    addOrganizm(new trawa(this,ox, oy,  ktory_urodzony++, WIDTH, HEIGHT));
                    break;
                case 'W':

                    addOrganizm(new wilcze_jagody(this,ox, oy,  ktory_urodzony++, WIDTH, HEIGHT));
                    break;
            }
        }
    }

   public Swiat(Okno okno) {
       this.okno = okno;
       wczytajGre();
    }

    public void czysc_dziennik() {
        dziennik_zdarzen = "";
    }

    public void dodajZdarzenie(String zdarzenie) {
        dziennik_zdarzen += zdarzenie;
    }

    public void  wypisz_dziennik() {
        okno.setTextArea(dziennik_zdarzen);
    }
    public int  get_and_incrementKtoryUrodzony(){
        int ktory_urodzonytmp = ktory_urodzony;
        ktory_urodzony++;
        return ktory_urodzonytmp;
    }

    public void  rysujSwiat() {
        for(int i = 0; i< HEIGHT; i++){
            for (int j = 0; j< WIDTH; j++) {
                switch (plansza[i][j]){
                    case 'a':
                        okno.zmien_kolor(i,j,AntylopaKol);
                        break;
                    case 'w':
                        okno.zmien_kolor(i,j,WilkKol);
                        break;
                    case 'z':
                        okno.zmien_kolor(i,j,ZolwKol);
                        break;
                    case 'o':
                        okno.zmien_kolor(i,j,OwcaKol);
                        break;
                    case 'l':
                        okno.zmien_kolor(i,j,LisKol);
                        break;
                    case 'G':
                        okno.zmien_kolor(i,j,GuaranaKol);
                        break;
                    case 'W':
                        okno.zmien_kolor(i,j,JagodyKol);
                        break;
                    case 'B':
                        okno.zmien_kolor(i,j,BarszczKol);
                        break;
                    case 'T':
                        okno.zmien_kolor(i,j,TrawaKol);
                        break;
                    case 'M':
                        okno.zmien_kolor(i,j,MleczKol);
                        break;
                    case 'c':
                        okno.zmien_kolor(i,j,CzlowiekKol);
                        break;
                    case '.':
                        okno.zmien_kolor(i,j, Color.white);
                        break;
                }
            }
        }
        if(getCzlowiek()==null){
            okno.getMenu().setStatus("Umarles Koniec Gry");
            okno.getMenu().setSila("");
        }
        else {
            okno.getMenu().setStatus(CzlowiekSwiat.czlowiek_statusr());
            okno.getMenu().setSila("Sila wynosi " + CzlowiekSwiat.GetSila());
        }
    }

    public void setCzlowiek(czlowiek czlowiek) {
        CzlowiekSwiat = czlowiek;
    }

    public czlowiek getCzlowiek() {
        return CzlowiekSwiat;
    }

    public void addOrganizm(Organizm org) {
        Organizmy.add(org);
    }

    public boolean setJesliWolnePole(int x, int y, char znak) {
        if (plansza[x][y] == '.') {
            plansza[x][y] = znak;
            return true;
        }
        else
            return false;

    }

    public void zakonczGreFun() {
        zakonczGre = true;
    }

    public void wczytajGreFun() {
        wczytajGreB = true;
    }

    public boolean getZakonczGre() {
        return zakonczGre;
    }

    public boolean getWczytajGre() {
        return wczytajGreB;
    }

    public void zmienZnakNaPolu(int x, int y, char znak) {
        plansza[x][y] = znak;
    }

    private char getZnakNaPolu(int x, int y) {
        return plansza[x][y];
    }

    public void zwolnijPole(int x, int y) {
        plansza[x][y] = '.';
    }

    public Organizm findOrganizm(int x, int y, Organizm curr_org) {
        for (int i = 0; i < Organizmy.size();i++) {
            if (Organizmy.get(i).GetOx() == x && Organizmy.get(i).GetOy()==y && Organizmy.get(i) != curr_org)
                return Organizmy.get(i);
        }
        return null;
    }


    void usunZwierze(Organizm org) {
        int i = 0;
        while (Organizmy.get(i) != org) {
            i++;
        }
        Organizmy.remove(i);
    }

    public void wykonajTure() {
        sort_q(0, Organizmy.size()-1);
        if (iterator == -1) {
            for (iterator = Organizmy.size() - 1; iterator > -1 && !zakonczGre && !wczytajGreB; iterator--) {
                Organizmy.get(iterator).akcja();
                Organizmy.get(iterator).rysowanie();
            }
        }
        else {
            for (; iterator > -1 && !zakonczGre && !wczytajGreB; iterator--) {
                Organizmy.get(iterator).akcja();
                Organizmy.get(iterator).rysowanie();
            }
        }
    }

    void zmienIteratorDodawanie(Organizm iterator_org, Organizm other_org) {
        if (porownajOrg(iterator_org, other_org) == 1)
            iterator++;
    }

    public void zmienIteratorUsuwanie(Organizm iterator_org, Organizm other_org) {
        if (porownajOrg(iterator_org, other_org) == 1)
            iterator--;
    }


    private int porownajOrg(Organizm org1, Organizm org2) {
        if (org1.GetInicjatywa() > org2.GetInicjatywa())
            return 1;
        else if (org1.GetInicjatywa() < org2.GetInicjatywa())
            return 2;
        else {
            if (org1.GetWiek() < org2.GetWiek())
                return 1;
            else if (org1.GetWiek() > org2.GetWiek())
                return 2;
            else
                return 3;
        }
    }

    private int part(int st, int en) {
        Organizm pivot_val = Organizmy.get((st + en) / 2);
        int i = st;
        int j = en;

        while (true) {
            while (porownajOrg(Organizmy.get(i), pivot_val) == 2) {
                i++;
            }
            while (porownajOrg(Organizmy.get(j), pivot_val) == 1) {
                j--;
            }

            if (i >= j) {
                return j;
            }

            if (porownajOrg(Organizmy.get(i), Organizmy.get(j)) == 3) {
                i++;
                j--;
            }
            else {
                Organizm tmp = Organizmy.get(j);
                Organizmy.set(j, Organizmy.get(i));
                Organizmy.set(i, tmp);
                i++;
                j--;
            }
        }
    }

    private void sort_q(int st, int en) {
        if (st < en) {
            int q = part(st, en);
            sort_q(st, q);
            sort_q(q + 1, en);
        }
    }

    private static void clearScreen() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }

    public Okno getOkno() {
        return okno;
    }

    public void tworzenieOrganizmow(int x, int y, int IND){
        switch (IND){
            case AntylopaInd:
                addOrganizm(new antylopa(this,x,y,get_and_incrementKtoryUrodzony(), WIDTH, HEIGHT));
                break;
            case LisInd:
                addOrganizm(new lis(this,x,y,get_and_incrementKtoryUrodzony(), WIDTH, HEIGHT));
                break;
            case OwcaInd:
                addOrganizm(new owca(this,x,y,get_and_incrementKtoryUrodzony(), WIDTH, HEIGHT));
                break;
            case WilkInd:
                addOrganizm(new wilk(this,x,y,get_and_incrementKtoryUrodzony(), WIDTH, HEIGHT));
                break;
            case ZolwInd:
                addOrganizm(new zolw(this,x,y,get_and_incrementKtoryUrodzony(), WIDTH, HEIGHT));
                break;
            case BarszczInd:
                addOrganizm(new barszcz_sosnowskiego(this,x,y,get_and_incrementKtoryUrodzony(), WIDTH, HEIGHT));
                break;
            case GuaranaInd:
                addOrganizm(new guarana(this,x,y,get_and_incrementKtoryUrodzony(), WIDTH, HEIGHT));
                break;
            case TrawaInd:
                addOrganizm(new trawa(this,x,y,get_and_incrementKtoryUrodzony(), WIDTH, HEIGHT));
                break;
            case MleczInd:
                addOrganizm(new mlecz(this,x,y,get_and_incrementKtoryUrodzony(), WIDTH, HEIGHT));
                break;
            case JagodyInd:
                addOrganizm(new wilcze_jagody(this,x,y,get_and_incrementKtoryUrodzony(), WIDTH, HEIGHT));
                break;
        }
        rysujSwiat();
    }

    public void setOkno(Okno okno){ this.okno = okno; }

    public boolean getCzyHex(){
        return czyHex;
    }

    public  static boolean getCzyHexZapis(){
        File zapisT = new File("zapisT.txt");
        try {
            Scanner scanner = new Scanner(zapisT);
            String typ = scanner.next();
            if(Objects.equals(typ, "Hex")) {
                scanner.close();
                return true;
            }
            else{
                scanner.close();
                return false;
            }
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }

    }

}
