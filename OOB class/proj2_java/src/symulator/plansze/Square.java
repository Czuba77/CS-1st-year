package symulator.plansze;

import symulator.Okno;
import symulator.Swiat;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Square extends Swiat {
    public Square(int HEIGHT1, int WIDTH1) {
        super(HEIGHT1, WIDTH1);
        czyHex = false;
    }

    public Square(Okno okno) {
        super(okno);
        czyHex = false;
    }

    @Override
    protected void zapiszTypPlanszy() {
        try {
            FileWriter zapis = new FileWriter("zapisT.txt");
            zapis.write("Squere");
            zapis.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }


    @Override
    public void zapiszPlansze() {
        FileWriter zapis = null;
        try {
            zapis = new FileWriter("zapisP.txt");
            for (int i = 0; i < HEIGHT; i++) {
                for (int j = 0; j < WIDTH; j++) {
                    zapis.write( plansza[i][j]);
                }
                zapis.write( "\n");
            }
            zapis.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }

    @Override
    public void wczytajPlansze(){
        File zapis=new File("zapisP.txt");
        Scanner s;
        try {
            s = new Scanner(zapis);
            s.useDelimiter("");
            for (int i = 0; i < HEIGHT; i++) {
                for (int j = 0; j < WIDTH; j++) {
                    while (s.hasNext()) {
                        char c = s.next().charAt(0);
                        if (!Character.isWhitespace(c)) {
                            plansza[i][j] = c;
                            break;
                        }
                    }
                }
            }
            s.close();
        }
        catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }
}
