package pl.edu.pg.eti.ksg.po.lab1.transformacje;

public class ZlozenieTransformacji implements Transformacja {

    private Transformacja[] tab;

    public ZlozenieTransformacji(Transformacja[] tab){
            this.tab=tab;
    }

    public Transformacja[] getTab() {
        return tab;
    }

    @Override
    public Punkt transformuj(Punkt p) {
        for (int i = 0; i < tab.length; i++) {
            p = tab[i].transformuj(p);
        }
        return p;
    }

    @Override
    public Transformacja getTransformacjaOdwrotna() throws BrakTransformacjiOdwrotnejException {
        Transformacja[] tmp = new Transformacja[tab.length];
        for (int i = 0; i < tab.length; i++) {
            tmp[i] = tab[tab.length-1-i].getTransformacjaOdwrotna();
        }
        return new ZlozenieTransformacji(tmp);
    }
}
