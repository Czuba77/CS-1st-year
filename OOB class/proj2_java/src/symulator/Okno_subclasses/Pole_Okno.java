package symulator.Okno_subclasses;
import symulator.Okno;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;



public class Pole_Okno extends JPanel {
    public MouseListener mouseListener;


    public Pole_Okno(int x, int y, Okno okno) {
        this.setBackground(Color.white);
        this.setPreferredSize(new Dimension(40,40));
        addMouseListener(new MouseAdapter() {
            @Override
            public void mouseReleased(MouseEvent e) {
                if (getBackground().equals(Color.white)) {
                    okno.getSwiat().tworzenieOrganizmow(x,y,okno.GetZaznaczone());
                }
            }

        });
    }


    public void setColour(Color color){
        this.setBackground(color);
    }
}


