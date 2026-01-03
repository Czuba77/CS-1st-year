find_f(){
if [ $4 -gt 0 ];
then
	local result=$(find "$1" -type f -name "$2" -size +"$3"c -size -"$4"c -exec grep -l "$5" {} +)
	if [ -n "$result" ]; 
		then
			zenity --info --title "Wynik" --text "Znaleziono plik"
		else
			result=$(find "$1" -type d -name "$2" -size +"$3"c -size -"$4"c)
			if [ -n "$result" ] && [ -z "$5" ]; 
				then
					zenity --info --title "Wynik" --text "Znaleziono katalog"
				else
					zenity --info --title "Wynik" --text "Nie znaleziono pliku ani katalogu"
			fi
	fi
else
	local result=$(find "$1" -type f -name "$2" -size +"$3"c -exec grep -l "$5" {} +)
	if [ -n "$result" ]; 
		then
			zenity --info --title "Wynik" --text "Znaleziono plik"
		else
			result=$(find "$1" -type d -name "$2" -size +"$3"c)
			if [ -n "$result" ] && [ -z "$5" ]; 
				then
					zenity --info --title "Wynik" --text "Znaleziono katalog"
				else
					zenity --info --title "Wynik" --text "Nie znaleziono pliku ani katalogu"
			fi
	fi
fi
}
while [ true ] 
do
read_values=$(zenity --forms --title="Wyszukaj Plik" --text="Wprowadź informację o pliku." \
--add-entry="Nazwa pliku" \
--add-entry="Katalog" \
--add-entry="Większy niż" \
--add-entry="Mniejszy niż" \
--add-entry="Zawartość"\ )
if [ $? -eq 0 ]; then
	IFS="|" read -r name Dir Gt St cont <<< "$read_values"
	if [ -z "$name" ]; then 
		name="*" 
		fi
	if [ -z "$Dir" ]; then 
		Dir="." 
		fi
	if [ -z "$Gt" ]; then 
		Gt=0 
		fi
	if [ -z "$St" ]; then 
		St=0 
		fi
	find_f "$Dir" "$name" "$Gt" "$St" "$cont"
else
exit 0
fi
done
#echo "Nazwa pliku: $name"
#echo "Katalog: $Dir"
#echo "Większy niż: $Gt"
#echo "Mniejszy niż: $St"
#echo "Zawartość: $cont"

