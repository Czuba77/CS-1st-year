package symulator.zwierzeta;

import symulator.Swiat;
import symulator.Zwierze;

import java.io.FileWriter;
import java.io.IOException;

public class czlowiek extends Zwierze {
    private int sila_flat, cooldown_ult;

    public czlowiek(Swiat swiat, int ox, int oy, int wiek, int BOARD_WIDTH, int BOARD_HEIGHT) {
        super(swiat, ox, oy,ox, oy, wiek, BOARD_WIDTH, BOARD_HEIGHT);

        this.nazwa = "Czlowiek";
        this.inicjatywa = 4;
        this.sila = 5;
        this.sila_flat = 5;
        this.cooldown_ult = 0;
        this.znak = 'c';
        swiat.setJesliWolnePole(ox, oy, znak);
    }

    @Override
    protected void wykonanie_porodu(int x, int y) {
        swiat.addOrganizm(new czlowiek( swiat,x, y, swiat.get_and_incrementKtoryUrodzony(),this.BOARD_WIDTH,this.BOARD_HEIGHT));
    }



    public czlowiek(Swiat swiat, int x, int y,  int xp, int yp,int wiek, int sila, int sila_flat, int cooldown_ult,  int cp, int BOARD_WIDTH, int BOARD_HEIGHT) {
        super(swiat, x, y,xp,yp, wiek, BOARD_WIDTH, BOARD_HEIGHT);

        this.nazwa = "Czlowiek";
        this.inicjatywa = 4;
        this.sila = sila;
        this.sila_flat = sila_flat;
        this.cooldown_ult = cooldown_ult;
        this.znak = 'c';
        this.cooldown_porodowy = cp;
    }

    @Override
    public void akcja() {
        if (cooldown_porodowy>0)
            cooldown_porodowy--;
        if (sila > sila_flat) {
            sila--;
            if (sila == sila_flat)
                cooldown_ult = 5;
        }
        else if (cooldown_ult > 0)
            cooldown_ult--;

        swiat.rysujSwiat();
        swiat.wypisz_dziennik();
        poprzednie_polozenie[OX] = polozenie[OX];
        poprzednie_polozenie[OY] = polozenie[OY];


        try {
            swiat.getOkno().Czekanie();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        swiat.czysc_dziennik();
        swiat.zwolnijPole( poprzednie_polozenie[OX], poprzednie_polozenie[OY]);
    }

    public void ult(){
        if (sila == sila_flat && cooldown_ult == 0) {
            sila += 5;
            swiat.rysujSwiat();
            swiat.wypisz_dziennik();
        }
    }


    public String czlowiek_statusr() {
        if(cooldown_ult==0 && sila>sila_flat)
           return "Umiejetnosc specjalna aktywna\n";
        else if(sila==sila_flat && cooldown_ult!=0)
            return "Umiejetnosc specjalna dostepna za " + cooldown_ult + "\n";
        else
            return "Umiejetnosc specjalna gotowa do uzycia\n";
    }

    @Override
    public void zwiekszSile(int oIle) {
        this.sila += oIle;
        this.sila_flat += oIle;
    }

    @Override
    public void delOrganizm() {
        super.delOrganizm();
        swiat.setCzlowiek(null);
        swiat.rysujSwiat();
        try {
            swiat.getOkno().ekranSmierci();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        System.exit(0);
    }

    @Override
    public void zapiszOrganizm(FileWriter zapis) {
        if(sila>sila_flat)
            sila++;
        if(cooldown_ult > 0)
            cooldown_ult++;
        try{
            super.zapiszOrganizm(zapis);
            zapis.write(sila_flat+"");
            zapis.write(" ");
            zapis.write(cooldown_ult+"");
            zapis.write(" ");
            if(sila>sila_flat)
                sila--;
            if(cooldown_ult > 0)
                cooldown_ult--;
        }
        catch(IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }

    }

}
