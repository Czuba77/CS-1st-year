package symulator;

abstract public class Roslina extends Organizm{

    public Roslina(Swiat swiat, int ox, int oy, int wiek, int BOARD_WIDTH, int BOARD_HEIGHT) {
        super(swiat, ox, oy, wiek, BOARD_WIDTH, BOARD_HEIGHT);
    }

    protected abstract void zasiej(int x, int y);

    @Override
    protected void akcja(){
        swiat.zwolnijPole(polozenie[OX], polozenie[OY]);
        int chance = genRand(1, EXPAND_CHANCE);
        if (chance == 1) {
            int direction = genRand(0, 3);
            wykonanie_akcji(direction);
        }
    }

    @Override
    void rozmnazanie(Organizm drugi_organizm) {
    }

    @Override
    void setCooldownPorodowy() {

    }

    @Override
    final int GetCooldownPorodowy() {
        return 0;
    }

    @Override
    protected void wykonanie_akcji(int direction) {
        int[] polozenietmp = new int[]{ polozenie[OX] , polozenie[OY] };
        if(swiat.getCzyHex()){
            switch (direction) {
                case LEWOD:
                    if (polozenie[OY] + 1 >= BOARD_WIDTH)
                        polozenietmp[OY] = 0;
                    else
                        polozenietmp[OY] += 1;
                    break;
                case PRAWOG:
                    if (polozenie[OY] - 1 < 0)
                        polozenietmp[OY] = BOARD_WIDTH - 1;
                    else
                        polozenietmp[OY] -= 1;
                    break;
                case PRAWOD:
                    if (polozenie[OX] + 1 >= BOARD_HEIGHT)
                        polozenietmp[OX] = 0;
                    else
                        polozenietmp[OX] += 1;
                    break;
                case LEWOG:
                    if (polozenie[OX] - 1 < 0)
                        polozenietmp[OX] = BOARD_HEIGHT - 1;
                    else
                        polozenietmp[OX] -= 1;
                    break;
                case LEWO:
                    if (polozenie[OX] + 1 >= BOARD_HEIGHT)
                        polozenietmp[OX] = 0;
                    else
                        polozenietmp[OX] += 1;
                    if (polozenie[OY] - 1 < 0)
                        polozenietmp[OY] = BOARD_WIDTH - 1;
                    else
                        polozenietmp[OY] -= 1;
                    break;
                case PRAWO:
                    if (polozenie[OX] - 1 < 0)
                        polozenietmp[OX] = BOARD_HEIGHT - 1;
                    else
                        polozenietmp[OX] -= 1;
                    if (polozenie[OY] + 1 >= BOARD_WIDTH)
                        polozenietmp[OY] = 0;
                    else
                        polozenietmp[OY] += 1;
                    break;

            }
        }
        else {
            switch (direction) {
                case POLUDNIE:
                    if (polozenie[OY] + 1 >= BOARD_WIDTH)
                        polozenietmp[OY] = 0;
                    else
                        polozenietmp[OY] += 1;
                    break;
                case POLNOC:
                    if (polozenie[OY] - 1 < 0)
                        polozenietmp[OY] = BOARD_WIDTH - 1;
                    else
                        polozenietmp[OY] -= 1;
                    break;
                case WSCHOD:
                    if (polozenie[OX] + 1 >= BOARD_HEIGHT)
                        polozenietmp[OX] = 0;
                    else
                        polozenietmp[OX] += 1;
                    break;
                case ZACHOD:
                    if (polozenie[OX] - 1 < 0)
                        polozenietmp[OX] = BOARD_HEIGHT - 1;
                    else
                        polozenietmp[OX] -= 1;
                    break;
            }
        }
        if (swiat.findOrganizm(polozenietmp[OX], polozenietmp[OY], this) == null ) {
            zasiej(polozenietmp[OX], polozenietmp[OY]);
        }
    }


    public final int   GetOy_poprz() {
        return polozenie[OY];
    }

    public final int   GetOx_poprz() {
        return polozenie[OX];
    }
}
