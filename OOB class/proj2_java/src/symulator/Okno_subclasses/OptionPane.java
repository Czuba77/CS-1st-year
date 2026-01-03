package symulator.Okno_subclasses;

import javax.swing.*;

public class OptionPane extends JOptionPane {
    private final int N;
    private final int M;
    private final boolean czyHex;
    public OptionPane() {

        Object[] options = {"Szesciokatnej", "Czworokatnej"};

        int n = JOptionPane.showOptionDialog(null,
                "Czy chcesz grac na planszy szesciokatnej czy czworokatnej?",
                "Ustaw wartość",
                JOptionPane.YES_NO_OPTION,
                JOptionPane.QUESTION_MESSAGE,
                null,
                options,
                options[1]);

        czyHex = (n == JOptionPane.YES_OPTION);

        if (czyHex) {
            N = pobierzLiczbe("Podaj liczbę:");
            M = N;
        } else {
            N = pobierzLiczbe("Podaj pierwszą liczbę:");
            M = pobierzLiczbe("Podaj drugą liczbę:");
        }

    }

    private static int pobierzLiczbe(String komunikat) {
        while (true) {
            String input = JOptionPane.showInputDialog(null, komunikat, "Podaj liczbę", JOptionPane.PLAIN_MESSAGE);
            try {
                int liczba = Integer.parseInt(input);
                if (liczba > 0) {
                    return liczba;
                } else {
                    JOptionPane.showMessageDialog(null, "Proszę podać dodatnią liczbę naturalną.", "Błędne dane", JOptionPane.ERROR_MESSAGE);
                }
            } catch (NumberFormatException e) {
                JOptionPane.showMessageDialog(null, "Proszę podać poprawną liczbę.", "Błędne dane", JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    public int getM(){
        return M;
    }

    public int getN(){
        return N;
    }

    public boolean isHex(){
        return czyHex;
    }

    public boolean getCzyHex() {
        return czyHex;
    }
}
