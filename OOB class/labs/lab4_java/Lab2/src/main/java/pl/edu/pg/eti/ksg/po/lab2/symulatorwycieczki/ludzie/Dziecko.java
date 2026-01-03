package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ludzie;

public class Dziecko extends Czlowiek{
    private double wiek;

   public Dziecko(String imie, String nazwisko, Plec plec, double maksymalnaPredkosc) {
       super(imie, nazwisko, plec, maksymalnaPredkosc);
   }

    @Override
    public int getUmiejetnosciNawigacyjne() {
        return 0;
    }
}
