package symulator.zwierzeta;

import symulator.Organizm;
import symulator.Swiat;
import symulator.Zwierze;

public class zolw extends Zwierze {

    public zolw(Swiat swiat, int ox, int oy, int wiek, int BOARD_WIDTH, int BOARD_HEIGHT) {
        super(swiat, ox, oy,ox, oy, wiek, BOARD_WIDTH, BOARD_HEIGHT);

        this.nazwa = "Zolw";
        this.inicjatywa = 1;
        this.sila = 2;
        this.znak = 'z';
        swiat.setJesliWolnePole(ox, oy, znak);
    }

    @Override
    protected void wykonanie_porodu(int x, int y) {
        swiat.addOrganizm(new zolw( swiat,x, y, swiat.get_and_incrementKtoryUrodzony(),this.BOARD_WIDTH,this.BOARD_HEIGHT));
    }



    public zolw(Swiat swiat, int x, int y,  int wiek, int sila, int xp, int yp, int cp, int BOARD_WIDTH, int BOARD_HEIGHT) {
        super(swiat, x, y,xp,yp, wiek, BOARD_WIDTH, BOARD_HEIGHT);
        this.nazwa = "Zolw";
        this.inicjatywa = 1;
        this.sila = sila;
        this.znak = 'z';
        this.cooldown_porodowy = cp;
    }

    @Override
    public void akcja(){
        if (cooldown_porodowy>0)
            cooldown_porodowy--;
        swiat.zwolnijPole(polozenie[OX], polozenie[OY]);
        int direction = genRand(0, 15);
        poprzednie_polozenie[OX] = polozenie[OX];
        poprzednie_polozenie[OY] = polozenie[OY];
        wykonanie_akcji(direction);
        String zdarzenie="";
        if (direction < 4) {
		/*
		zdarzenie = nazwa + "(" + (poprzednie_polozenie[OX]) + "," + (poprzednie_polozenie[OY]) + ") idzie na pole ("
			+ (polozenie[OX]) + "," + (polozenie[OY]) + ").\n";
			*/
        }
        else {
            zdarzenie = nazwa + "(" + (polozenie[OX]) + "," + (polozenie[OY]) + ") nie ruszyl sie.\n";
        }
        swiat.dodajZdarzenie(zdarzenie);
    }

    @Override
    public int kolizja(Organizm napotkany_org) {
        if (napotkany_org.GetSila() < 5) {
            napotkany_org.SetOx(napotkany_org.GetOx_poprz());
            napotkany_org.SetOy(napotkany_org.GetOy_poprz());
            napotkany_org.GetWorld().setJesliWolnePole(napotkany_org.GetOx(), napotkany_org.GetOy(), napotkany_org.GetZnak());
            String zdarzenie = "Na polu (" + (polozenie[OX]) + "," + (polozenie[OY]) + "), doszlo do kolizji " +
                    this.nazwa + " odbil atak " + napotkany_org.GetNazwa() + ".\n";
            swiat.dodajZdarzenie(zdarzenie);
            return SPECIAL_CASE;
        }
        else if (this.sila <= napotkany_org.GetSila())
        return WIN;
	else
        return LOOSE;
    }
}
