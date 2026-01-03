import symulator.Okno;
import symulator.Okno_subclasses.OptionPane;
import symulator.Swiat;
import symulator.plansze.Hex;
import symulator.plansze.Square;


public static void main(String[] args)
{


    OptionPane o= new OptionPane();
    int HEIGHT=o.getN(), WIDTH=o.getM();
    boolean czyHex= o.getCzyHex();
    Swiat swiat;
    if(czyHex){
        swiat = new Hex(HEIGHT,WIDTH);
    }
    else{
        swiat = new Square(HEIGHT,WIDTH);
    }
    Okno okno = new Okno(WIDTH,HEIGHT,swiat);
    swiat.setOkno(okno);

    swiat.rysujSwiat();
    while (!swiat.getZakonczGre()) {
        swiat.wykonajTure();
        if (swiat.getWczytajGre()) {
            if(Swiat.getCzyHexZapis())
                swiat = new Hex(okno);
            else
                swiat = new Square(okno);
            okno.setSwiat(swiat);
       }
    }
    if (swiat.getCzlowiek() == null) {
        swiat.rysujSwiat();
        swiat.wypisz_dziennik();
    }
}

