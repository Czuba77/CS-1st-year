package symulator.Okno_subclasses;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class RadioButtons extends ButtonGroup implements ActionListener {
    private final JRadioButton[] Radio;
    private int Zaznaczone;

    public RadioButtons (JPanel panel){
        int j=0;
        panel.setLayout(new GridLayout(5,2,1,1));
        Radio = new JRadioButton[10];
        Radio[j] = new JRadioButton("Antylopa");
        Radio[j].setSelected(true);
        Radio[j].addActionListener(this);
        Radio[j++].setBackground(Color.gray);

        Radio[j] = new JRadioButton("Lis");
        Radio[j].addActionListener(this);
        Radio[j++].setBackground(Color.orange);

        Radio[j] = new JRadioButton("Owca");
        Radio[j].addActionListener(this);
        Radio[j].setForeground(Color.white);
        Radio[j++].setBackground(Color.black);

        Radio[j] = new JRadioButton("wilk");
        Radio[j].addActionListener(this);
        Radio[j++].setBackground(Color.red);

        Radio[j] = new JRadioButton("zolw");
        Radio[j].addActionListener(this);
        Radio[j++].setBackground(Color.green);

        Radio[j] = new JRadioButton("Barszcz Sosnowskiego");
        Radio[j].addActionListener(this);
        Radio[j].setForeground(Color.white);
        Radio[j++].setBackground(new Color(119,0,200));

        Radio[j] = new JRadioButton("Guarana");
        Radio[j].addActionListener(this);
        Radio[j++].setBackground(Color.cyan);

        Radio[j] = new JRadioButton("Mlecz");
        Radio[j].addActionListener(this);
        Radio[j++].setBackground(Color.yellow);


        Radio[j] = new JRadioButton("Trawa");
        Radio[j].addActionListener(this);
        Radio[j].setForeground(Color.white);
        Radio[j++].setBackground(new Color(0,50,0));

        Radio[j] = new JRadioButton("Wilcze jagody");
        Radio[j].addActionListener(this);
        Radio[j++].setBackground(Color.pink);
        for (int i = 0; i < Radio.length; i++) {
            this.add(Radio[i]);
            panel.add(Radio[i]);
        }

    }

    @Override
    public void actionPerformed(ActionEvent e) {
        for (int i = 0; i < Radio.length; i++) {
            if (e.getSource() == Radio[i]) {
                Zaznaczone = i;
            }
        }
    }

    public int getZaznaczone(){
        return Zaznaczone;
    }
}
