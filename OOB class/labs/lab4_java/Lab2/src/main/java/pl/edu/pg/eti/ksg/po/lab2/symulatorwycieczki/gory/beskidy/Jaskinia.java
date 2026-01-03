package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy;

import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.atrakcje.Atrakcja;

public class Jaskinia extends Atrakcja {
    private double Czas=1;
    private String nazwa;

    public Jaskinia(String Nazwa){
        nazwa=Nazwa;
    }
    @Override
    public String getNazwa() {
        return nazwa;
    }
    @Override
    public double getCzas() {
        return Czas;
    }
}
