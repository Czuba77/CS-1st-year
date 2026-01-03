#!/bin/bash

write_menu(){
echo -e "1 - Nazwa pliku $2\n2 - Katalog $1\n3 - Większy niż $3\n4 - Mniejszy niż $4\n5 - Zawartość $5\n6 - Szukaj \n7 - Zakończ"
}

find_f(){
if [ $4 -gt 0 ];
	then
		local result=$(find "$1" -type f -name "$2" -size +"$3"c -size -"$4"c -exec grep -l "$5" {} +)
		if [ -n "$result" ]; 
			then
				echo "Znaleziono plik"
			else
				result=$(find "$1" -type d -name "$2" -size +"$3"c -size -"$4"c)
				if [ -n "$result" ] && [ -z "$5" ]; 
					then
						echo "Znaleziono katalog"
					else
						echo "Nie znaleziono pliku ani katalogu"
				fi
		fi
	else
		local result=$(find "$1" -type f -name "$2" -size +"$3"c -exec grep -l "$5" {} +)
		if [ -n "$result" ]; 
			then
				echo "Znaleziono plik"
			else
				result=$(find "$1" -type d -name "$2" -size +"$3"c)
				if [ -n "$result" ] && [ -z "$5" ]; 
					then
						echo "Znaleziono katalog"
					else
						echo "Nie znaleziono pliku ani katalogu"
				fi
		fi
	fi
}





while true; do
write_menu "$Dir" "$name" "$Gt" "$St" "$cont"
read -p "Wybierz opcję: " cond

case $cond in
1)
read -p "Podaj nazwę pliku: " name
;;
2)
read -p "Podaj katalog: " Dir
;;
3)
read -p "Podaj minimalny rozmiar (w bajtach): " Gt
;;
4)
read -p "Podaj maksymalny rozmiar (w bajtach): " St
;;
5)
read -p "Podaj zawartość pliku: " cont
;;
6)
if [ -z $Dir ]; then  
Dir="." 
fi
if [ -z $name ]; then  
name="*" 
fi
if [ -z $Gt ]; then  
Gt=0 
fi
if [ -z $St ]; then  
St=0 
fi
if [ -z $cont ]; then  
cont="" 
fi
find_f "$Dir" "$name" "$Gt" "$St" "$cont"
Dir=""
name=""
Gt=""
St=""
cont=""
;;
7)
break
;;
*)
echo "Niepoprawny wybór"
;;
esac
done
