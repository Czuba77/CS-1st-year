package symulator.rosliny;

import symulator.Organizm;
import symulator.Roslina;
import symulator.Swiat;

public class guarana extends Roslina {


    public guarana(Swiat swiat, int ox, int oy,  int wiek, int BOARD_WIDTH, int BOARD_HEIGHT) {
        super(swiat, ox, oy, wiek, BOARD_WIDTH, BOARD_HEIGHT);

        this.nazwa = "Guarana";
        this.inicjatywa = 0;
        this.sila = 0;
        this.znak = 'G';
        swiat.setJesliWolnePole(ox, oy, znak);
    }

    @Override
    public void zasiej(int x, int y) {
        swiat.addOrganizm(new guarana(swiat,x, y, swiat.get_and_incrementKtoryUrodzony(),BOARD_WIDTH,BOARD_HEIGHT));
    }

    @Override
    public int kolizja(Organizm napotkany_org) {
        napotkany_org.zwiekszSile(3);
        return WIN;
    }


}
