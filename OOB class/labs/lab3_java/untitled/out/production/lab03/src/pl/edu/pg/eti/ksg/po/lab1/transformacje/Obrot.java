package pl.edu.pg.eti.ksg.po.lab1.transformacje;
public class Obrot implements Transformacja{

    private double angle;

    public  Obrot(double angle){
        this.angle = angle;
    }


    public double getAngle(){
        return this.angle;
    }

    @Override
    public Punkt transformuj(Punkt p) {
        double cosAng=java.lang.Math.cos(getAngle()),sinAng=java.lang.Math.sin(getAngle());
        return new Punkt(p.getX()*cosAng-p.getY()*sinAng, p.getX()*sinAng+p.getY()*cosAng);
    }

    @Override
    public Transformacja getTransformacjaOdwrotna() throws BrakTransformacjiOdwrotnejException {
        return new Obrot(-angle);
    }

    @Override
    public String toString() {
        return "Obrot o "+this.angle;
    }
}
