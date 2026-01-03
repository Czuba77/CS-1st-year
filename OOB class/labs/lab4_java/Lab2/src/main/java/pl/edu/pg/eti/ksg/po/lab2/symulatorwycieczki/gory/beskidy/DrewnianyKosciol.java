package pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.gory.beskidy;
import pl.edu.pg.eti.ksg.po.lab2.symulatorwycieczki.atrakcje.Atrakcja;
public class DrewnianyKosciol extends Atrakcja{
    private double Czas=0.5;
    private String nazwa;

    public DrewnianyKosciol(String Nazwa){
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
