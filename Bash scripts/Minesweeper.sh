#!/bin/bash
# Author           : Antoni Czuba
# Created On       : 26.05.2024
# Last Modified By : Antoni Czuba
# Last Modified On : 28.05.2024
# Version          : 1.00
#
# Description      :
# This Bash script is a command-line version of "Minesweeper." Players uncover cells and flag mines
# on an ASCII grid, with commands to interact with the game. The objective is to reveal all non-mine cells without 
# triggering a mine.
# Opis
# Ten skrypt Bash to wersja gry "Saper" w wierszu poleceń. Gracze odkrywają komórki i oznaczają miny na siatce ASCII, 
# używając poleceń do interakcji z grą. Celem jest odkrycie wszystkich komórek bez min, nie trafiając na żadną z nich.
#
# Licensed under GPL (see /usr/share/common-licenses/GPL for more details

#wypisywanie planszy
sub_board_out_upper(){
clear
if [ "$showAuthor" = true ] ; then
	echo "Autor: Antoni Czuba"
fi
oXgap=""
if [ $Xsize -gt 10 ]; then
	oXgap=" "
fi

if [ $Xsize -gt 10 ]; then
	echo -n "$oXgap   "
	for ((i=0; i<Xsize; i++)); do
		a=$((i%100-i%10))
		a=$((a/10))
		echo -n "$a "
	done
	echo ""
fi
echo -n "$oXgap   "
for ((i=0; i<Xsize; i++)); do
	echo -n "$((i%10)) "
done
echo ""
echo -n "$oXgap  "
for ((i=0; i<Xsize; i++)); do
	echo -n "##"
done
echo -n "#"
echo ""
row=1

if [ $Ysize -gt 10 ]; then
	echo -n "00# " 
else
	echo -n "0# " 
fi

}

board_out() {
sub_board_out_upper
for ((j=0; j<board_size; j++)); do
	if [ "${board_uncovered[$j]}" -eq 1 ]; then
		if [ "${board_covered[$j]}" -ge 10 ]; then
			echo -n "B "
	  	else
			echo -n "${board_covered[$j]} "
	    	fi
	elif [ "${board_uncovered[$j]}" -eq 2 ]; then
		echo -n "F "
	else
	    echo -n "_ "
	fi

	if [ $(( (j + 1) % Xsize )) -eq 0 ] && [ $j -ne $((board_size -1)) ]; then
   		echo -n "#"
   		echo ""
   		if [ $Ysize -gt 10 ] && [ $row -lt 10 ]; then
			echo -n "0"
			echo -n "$row# "
			((row++))
		else
			echo -n "$row# "
			((row++))
		fi
	fi
done
sub_board_out_lower
}

sub_board_out_lower(){
echo -n "#"
echo ""
echo -n "$oXgap  "
for ((i=0; i<Xsize; i++)); do
	echo -n "##"
done
echo -n "#"
echo ""
}

#wypisanie odkrytej planszy
board_out_vis() {
sub_board_out_upper
for ((j=0; j<board_size; j++)); do
	if [ "${board_covered[$j]}" -ge 10 ]; then
		echo -n "B "
  	else
		echo -n "${board_covered[$j]} "
    	fi
	if [ $(( (j + 1) % Xsize )) -eq 0 ] && [ $j -ne $((board_size -1)) ]; then
   		echo -n "#"
   		echo ""
   		if [ $Ysize -gt 10 ] && [ $row -lt 10 ]; then
			echo -n "0"
			echo -n "$row# "
			((row++))
		else
			echo -n "$row# "
			((row++))
		fi
	fi
done
sub_board_out_lower
}

#generowanie bomb 
gen_bombs() {
	bomb_amount=$((board_size/8*difficulty))
	for ((i=0; i<bomb_amount; i++)); do
		index=$((RANDOM % board_size))
		while [ "${board_covered[$index]}" -ge 10 ]; do
		    index=$((RANDOM % board_size))
		done
		board_covered[$index]=10



		if [ $((index)) -ne 0 ] && [ $(( index % Xsize )) -ne 0 ]; then
		    ((board_covered[$((index - 1))]++))
		fi
		if [ $((index)) -ne $((board_size)) ] && [ $(( (index + 1) % Xsize )) -ne 0 ]; then
		    ((board_covered[$((index + 1))]++))
		fi
		
		
		if [ $((index)) -lt $((board_size - Xsize)) ]; then
		    ((board_covered[$((index + Xsize))]++))
		fi
		
		if [ $((index)) -lt $((board_size - Xsize - 1)) ] && [ $(( index % Xsize )) -ne 0 ]; then
		    ((board_covered[$((index + Xsize - 1))]++))
		fi
		
		if [ $((index)) -lt $((board_size - Xsize + 1)) ] && [ $(( (index + 1) % Xsize )) -ne 0 ]; then
		    ((board_covered[$((index + Xsize + 1))]++))
		fi
		
		
		
		if [ $((index)) -ge $((0 + Xsize)) ]; then
		    ((board_covered[$((index - Xsize))]++))
		fi
		
		if [ $((index)) -ge $((0 + Xsize - 1)) ] && [ $(( index % Xsize )) -ne 0 ]; then
		    ((board_covered[$((index - Xsize - 1))]++))
		fi
		
		if [ $((index)) -ge $((0 + Xsize + 1)) ] && [ $(( (index + 1) % Xsize )) -ne 0 ]; then
		    ((board_covered[$((index - Xsize + 1))]++))
		fi
		
		
	done
}

#wykonywanie sprawdzania pola
move_logic(){
	board_out
	while true; do
		take_input
		check_index=$((Y * Xsize + X))
		if [ "${board_uncovered[$check_index]}" -eq 1 ]; then
			board_out
			echo "To pole zostalo juz sprawdzone, podaj inne wspolrzedne"
		elif [ "${board_uncovered[$check_index]}" -eq 2 ]; then
			board_out
			echo "Na tym polu stoi flaga, podaj inne wspolrzedne"
		elif [ $X -ge $Xsize ] || [ $Y -ge $Ysize ] || [ $X -lt 0 ] || [ $Y -lt 0  ]; then
			board_out
			echo "Niepoprawne wspolrzedne, podaj inne dane"
		else
			break
		fi
	done

	((uncovered_squeres++))
	board_uncovered[$check_index]=1
	if [ "${board_covered[$check_index]}" -ge 10 ]; then
		ifLose=true
	fi
}

#stawianie flagi
flag_logic(){
	board_out
	while true; do
		take_input
		check_index=$((Y * Xsize + X))
		if [ "${board_uncovered[$check_index]}" -eq 1 ]; then
			board_out
			echo "To pole zostalo juz sprawdzone, podaj inne wspolrzedne"
		elif [ $X -ge $Xsize ] || [ $Y -ge $Ysize ] || [ $X -lt 0 ] || [ $Y -lt 0  ]; then
			board_out
			echo "Niepoprawne wspolrzedne, podaj inne dane"
		else
			break
		fi
	done
	if [ "${board_uncovered[$check_index]}" -eq 2 ]; then
		board_uncovered[$check_index]=0
	else
		board_uncovered[$check_index]=2
	fi
}

#pobieranie ruchu gracza
take_input() {
	echo "Podaj wspolrzedna X na jakej chcesz wykonac akcje"
	read X
	echo "Podaj wspolrzedna Y na jakej chcesz wykonac akcje"
	read Y
}

#obsluga warunkow konca gry
end_game() {
	if [ "$ifLose" = true ]; then
		board_out_vis
		echo "Przegrales"
		echo "Odkryles $uncovered_squeres/$board_size pola"
		exit 0
	elif [ $uncovered_squeres -eq $((board_size-bomb_amount)) ]; then
		board_out
		echo "Wygrales"
		exit 0
	fi
}

#wczytywanie wielkosci planszy
read_board_size(){
	echo "Podaj szerokosc plaszy X"
	read Xsize
	echo "Podaj wysokosc planszy Y"
	read Ysize
	board_size=$((Xsize*Ysize))
}

#wybieranie akcji jaka chce wykonac uzytkownik (stawianie flagi, sprawdzanie pola, wyjscie)
choose_action(){
board_out
while true; do
echo "Wybierz akcje"
echo "Aby sprawdzc pole wybierz 1"
echo "Aby postawic lub usunac flage wybierz 2"
echo "Aby wyjsc wybierz 3"
if [ "$isCheat" = true ] ; then
	echo "Aby pokazac plansze kliknij 4"
fi
read choice
case $choice in
	1)
		move_logic
		break
		;;
	2)
		flag_logic
		board_out
		;;
	3)
		exit 1
		;;
	4)
		if [ "$isCheat" = true ]; then
		board_out_vis
		else 
		board_out
		fi
		;;
	*)
		board_out
		echo "Wybierz poprawna opcje"
		;;
	esac
done
}

#obsługa opcji z jakimi zostal uruchomiony skrypt 
OPTSTRING=":ach"
isCheat=false
showAuthor=false
difficulty=1;
while getopts ${OPTSTRING} opt; do
  case ${opt} in
    a)
      showAuthor=true
      ;;
    c)
      isCheat=true
      ;;
    h)
      difficulty=2;
      ;;
    ?)
      echo "Niepoprawna opcja: -${OPTARG}."
      exit 1
      ;;
  esac
done
#inicjalizacja rozgrywki
bomb_amount=0
uncovered_squeres=0
ifLose=false

read_board_size
board_covered=()
for ((i=0; i<board_size; i++)); do
	board_covered+=(0)
done

board_uncovered=()
for ((i=0; i<board_size; i++)); do
	board_uncovered+=(0)
done
gen_bombs

#petla rozgrywki
while true; do
	board_out
	choose_action
	end_game
done
