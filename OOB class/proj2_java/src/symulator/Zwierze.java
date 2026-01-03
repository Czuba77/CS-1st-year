package symulator;

import java.io.FileWriter;
import java.io.IOException;

@SuppressWarnings("DuplicatedCode")
abstract public class Zwierze extends Organizm{
    protected final int[] poprzednie_polozenie = new int[2];
    protected int cooldown_porodowy;

    public Zwierze(Swiat swiat, int ox, int oy,int oxp, int oyp, int wiek, int BOARD_WIDTH, int BOARD_HEIGHT) {
        super(swiat, ox, oy, wiek, BOARD_WIDTH, BOARD_HEIGHT);
        this.cooldown_porodowy=3;
        this.poprzednie_polozenie[OX] = oxp;
        this.poprzednie_polozenie[OY] = oyp;
    }

    protected abstract void wykonanie_porodu(int x, int y);


     void setCooldownPorodowy() {
         this.cooldown_porodowy = 3;
     }

     protected final int GetCooldownPorodowy() {
         return cooldown_porodowy;
     }


    @Override
    protected void rozmnazanie(Organizm napotkany_org) {
         napotkany_org.SetOx(napotkany_org.GetOx_poprz());
         napotkany_org.SetOy(napotkany_org.GetOy_poprz());
         napotkany_org.GetWorld().setJesliWolnePole(napotkany_org.GetOx(), napotkany_org.GetOy(), napotkany_org.GetZnak());
         if (this.cooldown_porodowy > 0 || napotkany_org.GetCooldownPorodowy()>0) {
             String zdarzenie= nazwa + "(" + polozenie[OX] + "," + polozenie[OY] + ") probowala urodzic, niestety nie byla wstanie\n";
             swiat.dodajZdarzenie(zdarzenie);
             return;
         }
         Organizm pobliskie_pole;
         if (polozenie[OY] != BOARD_WIDTH - 1) {
             pobliskie_pole = swiat.findOrganizm(polozenie[OX], polozenie[OY] + 1, this);
             if(urodz(pobliskie_pole, napotkany_org, polozenie[OX], polozenie[OY] + 1)) return;
         }
         else {
             pobliskie_pole = swiat.findOrganizm(polozenie[OX], 0, this);
             if(urodz(pobliskie_pole, napotkany_org, polozenie[OX], 0)) return;
         }

         if (polozenie[OY] != 0) {
             pobliskie_pole = swiat.findOrganizm(polozenie[OX], polozenie[OY] - 1, this);
             if(urodz(pobliskie_pole, napotkany_org, polozenie[OX], polozenie[OY] - 1)) return;
         }
         else {
             pobliskie_pole = swiat.findOrganizm(polozenie[OX], BOARD_WIDTH - 1, this);
             if(urodz(pobliskie_pole, napotkany_org, polozenie[OX], BOARD_WIDTH - 1)) return;
         }

         if (polozenie[OX] != BOARD_HEIGHT - 1) {
             pobliskie_pole = swiat.findOrganizm(polozenie[OX] + 1, polozenie[OY], this);
             if(urodz(pobliskie_pole, napotkany_org, polozenie[OX] + 1, polozenie[OY])) return;
         }
         else {
             pobliskie_pole = swiat.findOrganizm(0, polozenie[OY], this);
             if(urodz(pobliskie_pole, napotkany_org, 0, polozenie[OY])) return;
         }

         if (polozenie[OX] != 0) {
             pobliskie_pole = swiat.findOrganizm(polozenie[OX] - 1, polozenie[OY], this);
             if(urodz(pobliskie_pole, napotkany_org, polozenie[OX] - 1, polozenie[OY])) return;
         }
         else {
             pobliskie_pole = swiat.findOrganizm(BOARD_HEIGHT - 1, polozenie[OY], this);
             if(urodz(pobliskie_pole, napotkany_org, BOARD_HEIGHT - 1, polozenie[OY])) return;
         }

         if (polozenie[OX] != BOARD_HEIGHT - 1 && polozenie[OY] != BOARD_WIDTH - 1) {
             pobliskie_pole = swiat.findOrganizm(polozenie[OX] + 1, polozenie[OY] + 1, this);
             if(urodz(pobliskie_pole, napotkany_org, polozenie[OX] + 1, polozenie[OY] + 1)) return;
         }
         else if (polozenie[OX] != BOARD_HEIGHT - 1) {
             pobliskie_pole = swiat.findOrganizm(polozenie[OX] + 1, 0, this);
             if (urodz(pobliskie_pole, napotkany_org, polozenie[OX] + 1, 0)) return;
         }
         else if (polozenie[OY] != BOARD_WIDTH - 1) {
             pobliskie_pole = swiat.findOrganizm(0, polozenie[OY] + 1, this);
             if(urodz(pobliskie_pole, napotkany_org, 0, polozenie[OY] + 1)) return;
         }
         else {
             pobliskie_pole = swiat.findOrganizm(0, 0, this);
             if(urodz(pobliskie_pole, napotkany_org, 0, 0)) return;
         }

         if (polozenie[OX] != BOARD_HEIGHT - 1 && polozenie[OY] != 0) {
             pobliskie_pole = swiat.findOrganizm(polozenie[OX] + 1, polozenie[OY] - 1, this);
             if(urodz(pobliskie_pole, napotkany_org, polozenie[OX] + 1, polozenie[OY] - 1)) return;
         }
         else if (polozenie[OY] != 0) {
             pobliskie_pole = swiat.findOrganizm(0, polozenie[OY] - 1, this);
             if (urodz(pobliskie_pole, napotkany_org, 0, polozenie[OY] - 1)) return;
         }
         else if (polozenie[OX] != BOARD_HEIGHT - 1) {
             pobliskie_pole = swiat.findOrganizm(polozenie[OX] + 1, BOARD_WIDTH - 1, this);
             if(urodz(pobliskie_pole, napotkany_org, polozenie[OX] + 1, BOARD_WIDTH - 1)) return;
         }
         else {
             pobliskie_pole = swiat.findOrganizm(0, BOARD_WIDTH - 1, this);
             if(urodz(pobliskie_pole, napotkany_org, 0, BOARD_WIDTH - 1)) return;
         }

         if (polozenie[OX] != 0 && polozenie[OY] != BOARD_WIDTH - 1) {
             pobliskie_pole = swiat.findOrganizm(polozenie[OX] - 1, polozenie[OY] + 1, this);
             if(urodz(pobliskie_pole, napotkany_org, polozenie[OX] - 1, polozenie[OY] + 1)) return;
         }
         else if (polozenie[OY] != BOARD_WIDTH - 1) {
             pobliskie_pole = swiat.findOrganizm(BOARD_HEIGHT - 1, polozenie[OY] + 1, this);
             if (urodz(pobliskie_pole, napotkany_org, BOARD_HEIGHT - 1, polozenie[OY] + 1)) return;
         }
         else if (polozenie[OX] != 0) {
             pobliskie_pole = swiat.findOrganizm(polozenie[OX] - 1, 0, this);
             if(urodz(pobliskie_pole, napotkany_org, polozenie[OX] - 1, 0)) return;
         }
         else {
             pobliskie_pole = swiat.findOrganizm(BOARD_HEIGHT - 1, 0, this);
             if(urodz(pobliskie_pole, napotkany_org, BOARD_HEIGHT - 1, 0)) return;
         }

         if (polozenie[OX] != 0 && polozenie[OY] != 0) {
             pobliskie_pole = swiat.findOrganizm(polozenie[OX] - 1, polozenie[OY] - 1, this);
             if(urodz(pobliskie_pole, napotkany_org, polozenie[OX] - 1, polozenie[OY] - 1)) {
             }
         }
         else if (polozenie[OY] != 0) {
             pobliskie_pole = swiat.findOrganizm(BOARD_HEIGHT - 1, polozenie[OY] - 1, this);
             if (urodz(pobliskie_pole, napotkany_org, BOARD_HEIGHT - 1, polozenie[OY] - 1)) {
             }
         }
         else if (polozenie[OX] != 0) {
             pobliskie_pole = swiat.findOrganizm(polozenie[OX] - 1, BOARD_WIDTH - 1, this);
             if(urodz(pobliskie_pole, napotkany_org, polozenie[OX] - 1, BOARD_WIDTH - 1)) {
             }
         }
         else {
             pobliskie_pole = swiat.findOrganizm(BOARD_HEIGHT - 1, BOARD_WIDTH - 1, this);
             if(urodz(pobliskie_pole, napotkany_org, BOARD_HEIGHT - 1, BOARD_WIDTH - 1)) {
             }
         }
    }

     private boolean urodz(Organizm pobliskie_pole, Organizm napotkany_organizm, int x, int y) {
         String zdarzenie;
         if (pobliskie_pole == null) {
             this.setCooldownPorodowy();
             napotkany_organizm.setCooldownPorodowy();
             zdarzenie = nazwa + "(" + polozenie[OX] + "," + polozenie[OY] + ") urodzil/la na polu (" + x + "," + y + ").\n";
             swiat.dodajZdarzenie(zdarzenie);
             this.wykonanie_porodu(x, y);
             return true;
         }
         return false;
     }

    @Override
     protected void akcja() {
         if (cooldown_porodowy>0)
             cooldown_porodowy--;
         swiat.zwolnijPole(polozenie[OX], polozenie[OY]);
        int kierunek;
         if(swiat.getCzyHex()){
             kierunek=genRand(0, 5);
         }
         else{
             kierunek=genRand(0, 3);
         }
         poprzednie_polozenie[OX] = polozenie[OX];
         poprzednie_polozenie[OY] = polozenie[OY];
         wykonanie_akcji(kierunek);
	/*
	std::string zdarzenie = nazwa + "(" + std::to_string(poprzednie_polozenie[OX]) + "," + std::to_string(poprzednie_polozenie[OY]) + ") idzie na pole ("
		+ std::to_string(polozenie[OX]) + "," + std::to_string(polozenie[OY]) + ").\n";
	swiat->dodajZdarzenie(zdarzenie);
	*/
     }

    @Override
     protected void wykonanie_akcji(int kierunek) {
         if(swiat.getCzyHex()){
             switch (kierunek) {
                 case LEWOD:
                     if (polozenie[OY] + 1 >= BOARD_WIDTH)
                         polozenie[OY] = 0;
                     else
                         polozenie[OY] += 1;
                     break;
                 case PRAWOG:
                     if (polozenie[OY] - 1 < 0)
                         polozenie[OY] = BOARD_WIDTH - 1;
                     else
                         polozenie[OY] -= 1;
                     break;
                 case PRAWOD:
                     if (polozenie[OX] + 1 >= BOARD_HEIGHT)
                         polozenie[OX] = 0;
                     else
                         polozenie[OX] += 1;
                     break;
                 case LEWOG:
                     if (polozenie[OX] - 1 < 0)
                         polozenie[OX] = BOARD_HEIGHT - 1;
                     else
                         polozenie[OX] -= 1;
                     break;
                 case LEWO:
                     if (polozenie[OX] + 1 >= BOARD_HEIGHT)
                         polozenie[OX] = 0;
                     else
                         polozenie[OX] += 1;
                     if (polozenie[OY] - 1 < 0)
                         polozenie[OY] = BOARD_WIDTH - 1;
                     else
                         polozenie[OY] -= 1;
                     break;
                 case PRAWO:
                     if (polozenie[OX] - 1 < 0)
                         polozenie[OX] = BOARD_HEIGHT - 1;
                     else
                         polozenie[OX] -= 1;
                     if (polozenie[OY] + 1 >= BOARD_WIDTH)
                         polozenie[OY] = 0;
                     else
                         polozenie[OY] += 1;
                     break;
                 default:
                     break;
             }
         }
         else {
             switch (kierunek) {
                 case POLUDNIE:
                     if (polozenie[OY] + 1 >= BOARD_WIDTH)
                         polozenie[OY] = 0;
                     else
                         polozenie[OY] += 1;
                     break;
                 case POLNOC:
                     if (polozenie[OY] - 1 < 0)
                         polozenie[OY] = BOARD_WIDTH - 1;
                     else
                         polozenie[OY] -= 1;
                     break;
                 case WSCHOD:
                     if (polozenie[OX] + 1 >= BOARD_HEIGHT)
                         polozenie[OX] = 0;
                     else
                         polozenie[OX] += 1;
                     break;
                 case ZACHOD:
                     if (polozenie[OX] - 1 < 0)
                         polozenie[OX] = BOARD_HEIGHT - 1;
                     else
                         polozenie[OX] -= 1;
                     break;
                 default:
                     break;
             }
         }
     }


     public final int  GetOy_poprz(){
         return poprzednie_polozenie[OY];
     }

     public final int  GetOx_poprz() {
         return poprzednie_polozenie[OX];
     }

    @Override
    public void zapiszOrganizm(FileWriter zapis) {
         super.zapiszOrganizm(zapis);
         try {
             zapis.write(sila+"");
             zapis.write(" ");
             zapis.write(poprzednie_polozenie[OX]+"");
             zapis.write(" ");
             zapis.write(poprzednie_polozenie[OY]+"");
             zapis.write(" ");
             zapis.write(cooldown_porodowy+"");
             zapis.write(" ");
         }
         catch(IOException e) {
             System.out.println("An error occurred.");
             e.printStackTrace();
         }
     }




}
