package symulator.Okno_subclasses;

import symulator.Okno;
import symulator.Swiat;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import static symulator.Swiat.CzlowiekKol;

public class MenuBar extends JPanel implements ActionListener {
    private final JButton Wyjdz;
    private final JButton Zapisz;
    private final JButton Wczytaj;
    private final JButton Ult;
    private final JPanel Sila;
    private final JPanel Status;
    private Swiat swiat;
    private final Okno okno;

    public MenuBar(Swiat swiat1, Okno okno1){
        swiat = swiat1;
        okno = okno1;
        this.setLayout(new GridLayout(6,1));
        Sila = new JPanel();

        Status = new JPanel();
        Status.setBackground(CzlowiekKol);

        Zapisz = new JButton("Zapisz");
        Zapisz.addActionListener(this);
        Wczytaj = new JButton("Wczytaj");
        Wczytaj.addActionListener(this);
        Wyjdz = new JButton("Wyjdz");
        Wyjdz.addActionListener(this);
        Ult = new JButton("Ult");
        Ult.addActionListener(this);

        this.add(Wyjdz);
        this.add(Zapisz);
        this.add(Wczytaj);
        this.add(Ult);
        this.add(Sila);
        this.add(Status);
    }



    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == Zapisz){
            swiat.zapiszGre();
        }
        else if(e.getSource() == Wczytaj){
            swiat.wczytajGreFun();
            okno.setCzekanie(false);
        }
        else if(e.getSource() == Ult){
            swiat.getCzlowiek().ult();
        }
        else if(e.getSource() == Wyjdz){
            System.exit(0);
        }
    }

    public void setStatus(String text) {
        Status.removeAll();
        Status.add(new JLabel(text));
        Status.revalidate();
        Status.repaint();
    }

    public void setSila(String text) {
        Sila.removeAll();
        Sila.add(new JLabel(text));
        Sila.revalidate();
        Sila.repaint();
    }

    public void setSwiat(Swiat swiat1){
        swiat=swiat1;
    }

}