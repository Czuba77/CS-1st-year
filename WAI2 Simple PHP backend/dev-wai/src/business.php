<?php


use MongoDB\BSON\ObjectID;


function uploadzdj($plik, $sciezka_do_up, &$ww1, &$ww2) {
	$blad = 0;
    $adres_pliku = $sciezka_do_up . uniqid() . basename($plik["name"]);
    $typ_pliku = strtolower(pathinfo($adres_pliku, PATHINFO_EXTENSION));

    if ($plik['size'] > 1048576 || (int)$plik['size']==0) {
		$ww1 = "Plik jest za duży." ;
        $blad+=1;
   }

    if ($typ_pliku != "jpg" && $typ_pliku != "png") {
		$ww2 = "Tylko pliki jpg i png dozwolone.";
        $blad+=1;
    }
	
    if($blad==0) {
		move_uploaded_file($plik["tmp_name"], $adres_pliku);
		return $adres_pliku; 
    }
	else {
        return false;
    }
}

function zrob_min($sciezka_do_org, $sciezkadoprzeslaniaMN) {
    list($szer, $wys) = getimagesize($sciezka_do_org);
    $typ_pliku = strtolower(pathinfo($sciezka_do_org, PATHINFO_EXTENSION));
    $miniatura_plik_tym = imagecreatetruecolor(200, 125);

    if ($typ_pliku == "jpg") {
        $orginalny_plik_tym = imagecreatefromjpeg($sciezka_do_org);
    } 
	else {
        $orginalny_plik_tym = imagecreatefrompng($sciezka_do_org);
    }

    imagecopyresampled($miniatura_plik_tym, $orginalny_plik_tym, 0, 0, 0, 0, 200, 125, $szer, $wys);

    $sciezka_do_min = $sciezkadoprzeslaniaMN . 'min_' . basename($sciezka_do_org);

    if ($typ_pliku == "jpg") {
        imagejpeg($miniatura_plik_tym, $sciezka_do_min);
    } 
	else {
        imagepng($miniatura_plik_tym, $sciezka_do_min);
    }

    imagedestroy($miniatura_plik_tym);
    imagedestroy($orginalny_plik_tym);

    return $sciezka_do_min;
}
	
function zrob_zw($sciezka_do_org,$sciezka_do_zw ,$znak_wodny) {
    $typ_pliku = strtolower(pathinfo($sciezka_do_org, PATHINFO_EXTENSION));

    if ($typ_pliku != "jpg" && $typ_pliku != "png") {
        return "Tylko pliki jpg i png dozwolone do tworzenia znaku wodnego.";
    }

    if ($typ_pliku == "jpg") {
        $znak_wodny_plik_tym = imagecreatefromjpeg($sciezka_do_org);
    } elseif ($typ_pliku == "png") {
        $znak_wodny_plik_tym = imagecreatefrompng($sciezka_do_org);
    }


    $fontRoz = 20;
    $kolor = imagecolorallocate($znak_wodny_plik_tym, 255, 255, 255);
    $tekstX = 20;
    $tekstY = imagesy($znak_wodny_plik_tym) - 20;
    $sciezka_do_fontu = $_SERVER["DOCUMENT_ROOT"] .'/static/czcionki/TitilliumWeb-SemiBold.ttf';
    imagettftext($znak_wodny_plik_tym, $fontRoz, 0, $tekstX, $tekstY, $kolor, $sciezka_do_fontu, $znak_wodny);

    $sciezka_do_zw = $sciezka_do_zw .'zw_' . basename($sciezka_do_org);

    if ($typ_pliku == "jpg") {
        imagejpeg($znak_wodny_plik_tym, $sciezka_do_zw);
    } else {
        imagepng($znak_wodny_plik_tym, $sciezka_do_zw);
    }

    imagedestroy($znak_wodny_plik_tym);
    return $sciezka_do_zw;
}


function rejestracja_b($login,$password,$mail){
	$db = get_db();
	if($db->users->findOne(['login' => $login])!== null){
		return false;
	}
	if($db->users->findOne(['mail' => $mail])!== null){
		return false;
	}
	$hash = password_hash($password, PASSWORD_DEFAULT);
	$db->users->insertOne([
	'login' => $login,
	'password' => $hash,
	'mail' => $mail
	]);
	return true;
}

function logowanie_b($login,$pass){
	$db = get_db();
	$user = $db->users->findOne(['login' => $login]);
	if($user!== null && password_verify($pass, $user['password'])){
		session_regenerate_id();
		$_SESSION['user_id'] = $user['_id'];
		return true;
	}
	else{
		return false;
	}

}

function wyl(){
	setcookie(session_name(), "", -10000);
	session_unset();
	session_destroy();
	$_SESSION = array();
}

function save_zdj($id, $zdj)
{
    $db = get_db();

    if ($id == null) {
        $db->galeria->insertOne($zdj);
    } else {
        $db->galeria->replaceOne(['_id' => new ObjectID($id)], $zdj);
    }

    return true;
}

function get_galeria($strona) {
  $strona_n = $strona-1;
  $opt = [
      "limit" => 3,
      "skip" => $strona_n * 3
  ];

  $db = get_db();

  return $db -> galeria ->find([], $opt) -> toArray();
}

function delete_zdj($id)
{
    $db = get_db();
    $db->galeria->deleteOne(['_id' => new ObjectID($id)]);
}

function get_zdj($id)
{
    $db = get_db();
    return $db->galeria->findOne(['_id' => new ObjectID($id)]);
}

function get_db()
{
    $mongo = new MongoDB\Client(
        "mongodb://localhost:27017/wai",
        [
            'username' => 'wai_web',
            'password' => 'w@i_w3b',
        ]);

    $db = $mongo->wai;

    return $db;
}


