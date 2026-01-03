package symulator;
import symulator.Okno_subclasses.MenuBar;
import symulator.Okno_subclasses.Pole_Okno;
import symulator.Okno_subclasses.RadioButtons;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

import static java.lang.Thread.sleep;

public class Okno implements KeyListener{
    private final JFrame okno;
    private final JPanel PlanszaO;
    private final JPanel DziennikZdarzenO;
    private JTextArea textArea;
    private final MenuBar Menu;
    private Pole_Okno[][] Pola;
    private final RadioButtons radioButtonsd;
    private int BOARD_WIDTH;
    private int BOARD_HEIGHT;
    private final static int POLNOC = 3;
    private final static int  POLUDNIE = 2 ;
    private final static int WSCHOD = 1;
    private final static int ZACHOD = 0;

    private final static int LEWO = 0;
    private final static int  PRAWO = 1;
    private final static int LEWOG = 4;
    private final static int LEWOD = 5;
    private final static int PRAWOG = 2;
    private final static int PRAWOD = 3;

    private Swiat swiat;
    private boolean czyCzekanie;

    public Okno(int BOARD_WIDTH, int BOARD_HEIGHT, Swiat swiat1){
        swiat = swiat1;
        okno = new JFrame("Sawanna");
        this.BOARD_WIDTH = BOARD_WIDTH;
        this.BOARD_HEIGHT = BOARD_HEIGHT;


        okno.setExtendedState(JFrame.MAXIMIZED_BOTH);

        okno.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        okno.setResizable(true);
        okno.setBackground(Color.black);
        okno.setLayout(new BorderLayout(10,10));


        PlanszaO = new JPanel();
        DziennikZdarzenO = new JPanel();
        Menu = new MenuBar(swiat,this);
        JPanel menuPola = new JPanel();

        PlanszaO.setBackground(Color.black);
        DziennikZdarzenO.setBackground(Color.white);
        Menu.setBackground(Color.white);
        menuPola.setBackground(Color.white);

        PlanszaO.setPreferredSize(new Dimension(100,100));
        int height = 1024;
        DziennikZdarzenO.setPreferredSize(new Dimension(100, height /4));
        int width = 2048;
        Menu.setPreferredSize(new Dimension(width /6,100));
        menuPola.setPreferredSize(new Dimension(width /8,100));

        init_board();
        radioButtonsd = new RadioButtons(menuPola);
        init_tekst();

        okno.addKeyListener(this);
        okno.add(PlanszaO, BorderLayout.CENTER);
        okno.add(DziennikZdarzenO, BorderLayout.SOUTH);
        okno.add(Menu, BorderLayout.EAST);
        okno.add(menuPola, BorderLayout.WEST);

        okno.setVisible(true);
    }
    private void init_board(){
        if(swiat.getCzyHex()){
            PlanszaO.setLayout(new GridLayout(2*BOARD_HEIGHT-1, 1, 1, 1));

            JPanel[] kolumny = new JPanel[2 * BOARD_HEIGHT - 1];
            int iter=BOARD_HEIGHT;
            for(int i=0;i<2*BOARD_HEIGHT-1;i++){
                kolumny[i] = new JPanel();
                if(i<=BOARD_HEIGHT){
                    kolumny[i].setLayout(new GridLayout(1,i+1,1,1));
                }
                else{
                    iter--;
                    kolumny[i].setLayout(new GridLayout(1,iter+1,1,1));
                }
            }

            Pola = new Pole_Okno[BOARD_HEIGHT][BOARD_WIDTH];
            for (int i = 0; i < BOARD_HEIGHT; i++) {
                for (int j = 0; j < BOARD_WIDTH; j++) {
                    Pola[i][j] = new Pole_Okno(i, j, this);
                }
            }
            int ii=1,jj=-1, kk=0, ll=0,mm=0;

            while (true) {

                for(int j=0;j<BOARD_HEIGHT+kk-ll;j++){
                    kolumny[mm].add(new Panel());
                }


                while(ii>kk) {
                    ii--;
                    jj++;
                    kolumny[mm].add(Pola[ii][jj]);
                }

                for(int j=0;j<BOARD_HEIGHT+kk-ll;j++){
                    kolumny[mm].add(new Panel());
                }

                if(ll< BOARD_HEIGHT-1) {
                    ll++;
                }
                else if(kk< BOARD_HEIGHT-1) {
                    kk++;
                }
                else {
                    break;
                }
                mm++;
                ii=ll+1;
                jj=kk-1;
            }
            for(int i=0;i<2*BOARD_HEIGHT-1;i++){
                PlanszaO.add(kolumny[i]);
            }
        }
        else {
            PlanszaO.setLayout(new GridLayout(BOARD_HEIGHT, BOARD_WIDTH, 1, 1));
            Pola = new Pole_Okno[BOARD_HEIGHT][BOARD_WIDTH];
            for (int i = 0; i < BOARD_HEIGHT; i++) {
                for (int j = 0; j < BOARD_WIDTH; j++) {
                    Pola[i][j] = new Pole_Okno(i, j, this);
                    PlanszaO.add(Pola[i][j]);
                }
            }
        }
    }

    private void init_tekst(){
        textArea=new JTextArea(10,100);
        textArea.setEditable(false);
        textArea.setLineWrap(true);
        textArea.setWrapStyleWord(true);
        JScrollPane scrollPane = new JScrollPane(textArea);
        scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        scrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);

        DziennikZdarzenO.add(scrollPane, BorderLayout.CENTER);
    }


    public void setTextArea(String text) {
        this.textArea.setText(text);
    }

    public void zmien_kolor(int y, int x, Color color){
        Pola[y][x].setColour(color);
    }

    public void setSwiat(Swiat swiat){
        PlanszaO.removeAll();
        PlanszaO.revalidate();
        PlanszaO.repaint();
        BOARD_WIDTH=swiat.getWIDTH();
        BOARD_HEIGHT=swiat.getHEIGHT();
        this.swiat = swiat;
        init_board();
        Menu.setSwiat(swiat);
    }
    public Swiat getSwiat() {
        return swiat;
    }

    public int GetZaznaczone(){
        return radioButtonsd.getZaznaczone();
    }

    @Override
    public void keyTyped(KeyEvent e) {

    }

    @Override
    public void keyPressed(KeyEvent e) {

    }

    @Override
    public void keyReleased(KeyEvent e) {
            if(swiat.getCzlowiek()==null)
                czyCzekanie=false;
            else {
                if(swiat.getCzyHex()){
                    if (e.getKeyCode() == KeyEvent.VK_ESCAPE) {
                        czyCzekanie = false;
                    } else if (e.getKeyCode() == KeyEvent.VK_Q) {
                        swiat.getCzlowiek().wykonanie_akcji(LEWOG);
                        czyCzekanie = false;
                    } else if (e.getKeyCode() == KeyEvent.VK_W) {
                        swiat.getCzlowiek().wykonanie_akcji(PRAWOG);
                        czyCzekanie = false;
                    } else if (e.getKeyCode() == KeyEvent.VK_A) {
                        swiat.getCzlowiek().wykonanie_akcji(LEWO);
                        czyCzekanie = false;
                    } else if (e.getKeyCode() == KeyEvent.VK_S) {
                        swiat.getCzlowiek().wykonanie_akcji(PRAWO);
                        czyCzekanie = false;
                    }else if (e.getKeyCode() == KeyEvent.VK_Z) {
                        swiat.getCzlowiek().wykonanie_akcji(LEWOD);
                        czyCzekanie = false;
                    } else if (e.getKeyCode() == KeyEvent.VK_X) {
                        swiat.getCzlowiek().wykonanie_akcji(PRAWOD);
                        czyCzekanie = false;
                    }

                }
                else {
                    if (e.getKeyCode() == KeyEvent.VK_ESCAPE) {
                        czyCzekanie = false;
                    } else if (e.getKeyCode() == KeyEvent.VK_A) {
                        swiat.getCzlowiek().wykonanie_akcji(ZACHOD);
                        czyCzekanie = false;
                    } else if (e.getKeyCode() == KeyEvent.VK_D) {
                        swiat.getCzlowiek().wykonanie_akcji(WSCHOD);
                        czyCzekanie = false;
                    } else if (e.getKeyCode() == KeyEvent.VK_W) {
                        swiat.getCzlowiek().wykonanie_akcji(POLNOC);
                        czyCzekanie = false;
                    } else if (e.getKeyCode() == KeyEvent.VK_S) {
                        swiat.getCzlowiek().wykonanie_akcji(POLUDNIE);
                        czyCzekanie = false;
                    }
                }
            }
    }

    public void setCzekanie(boolean czekanie) {
        czyCzekanie = czekanie;
    }

    public void Czekanie() throws InterruptedException {
        czyCzekanie = true;
        while(czyCzekanie){
            sleep(50);
            okno.requestFocusInWindow();
        }
    }

    public void ekranSmierci() throws InterruptedException {
        swiat.wypisz_dziennik();
        czyCzekanie = true;
        while(czyCzekanie){
            sleep(50);
            okno.requestFocusInWindow();
        }
    }

    public MenuBar getMenu() {
        return Menu;
    }
}
