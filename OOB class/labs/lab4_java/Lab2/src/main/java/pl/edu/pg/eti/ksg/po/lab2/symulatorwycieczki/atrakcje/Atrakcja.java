package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.atrakcje;

import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.ElementWycieczki;

public abstract class Atrakcja implements ElementWycieczki {
    private double Czas;
    private String nazwa;
    @Override
    public String getNazwa() {
        return nazwa;
    }

    public double getCzas() {
        return Czas;
    }
}
