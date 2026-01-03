package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy;

import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.atrakcje.Atrakcja;

public class Szczyt extends Atrakcja {
    private double Czas=0.6;
    private String nazwa;

    public Szczyt(String Nazwa){
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
