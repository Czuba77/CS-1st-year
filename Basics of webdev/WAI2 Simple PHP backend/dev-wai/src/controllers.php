<?php
require_once 'business.php';

function formularz(&$model)
{
	return 'formularz_view';
}

function rejestracja()
{
	return 'rejestracja_view';
}

function logowanie()
{
	return 'logowanie_view';
}

function przyjecie_logowania(&$model)
{	
	$login = $_POST['login'];
	$password = $_POST['pass'];
	if(logowanie_b($login,$password)){
		$przyjecie_logowania=[
		'msg'=>"Logowanie udane",
		'czyudane' =>true
	];
	}
	else{
		$przyjecie_logowania=[
		'msg' => "Logowanie nieudane",
		'czyudane' => false
	];
	}
	$model['przyjecie_logowania']=$przyjecie_logowania;
	return 'przyjecie_logowania_view';
}

function przyjecie_rejestracji(&$model)
{	
	$mail = $_POST['email'];
	$login = $_POST['login'];
	$password = $_POST['pass'];
	$repeat_password = $_POST['repeat_pass'];
	
	if (!($password === $repeat_password)){
		$przyjecie_rejestracji=[
		'wiad'=> "Hasła nie są identyczne",
		'czyudane' =>false
		];
	}
	elseif(rejestracja_b($login,$password,$mail)){
		$przyjecie_rejestracji=[
		'wiad'=> "Rejestracja powiodła się",
		'czyudane' =>true
		];
	}
	else{
		$przyjecie_rejestracji=[
		'wiad'=> "Zajęty login lub e-mail.",
		'czyudane' =>false
		];
	}
	$model['przyjecie_rejestracji']=$przyjecie_rejestracji;
	return 'przyjecie_rejestracji_view';
}

function wylogowanie()
{
	return 'wylogowanie_view';
}


function przyjecie_wylogowania(&$model)
{	
	wyl();
	return 'redirect:galeria';
}


function przesylanie_zdjec(&$model) {
	$plik= $_FILES["fileToUpload"];
	$znakwodny = $_POST["znakWodny"];
	$tytul =  $_POST["tytul"];
	$autor =  $_POST["autor"];
    $sciezkadoprzeslania = $_SERVER["DOCUMENT_ROOT"] . "/images/img/";
    $sciezkadoprzeslaniaMN = $_SERVER["DOCUMENT_ROOT"] . "/images/min/";
	$sciezkadoprzeslaniaZW = $_SERVER["DOCUMENT_ROOT"] . "/images/zw/";

	$zdjecie = [
        '_id' => null
    ];
	$id = null;
	
    $sciezka_do_org = uploadzdj($plik, $sciezkadoprzeslania, $ww1, $ww2);

    if ($sciezka_do_org!=false) {
        $plik_ze_sciezkaZW = zrob_zw($sciezka_do_org,$sciezkadoprzeslaniaZW ,$znakwodny);
        $sciezka_do_mn = zrob_min($sciezka_do_org, $sciezkadoprzeslaniaMN);
		$zdjecie = [
            'plik_ze_sciezka' => $sciezka_do_org,
            'plik_ze_sciezkaZW' => $plik_ze_sciezkaZW,
            'plik_ze_sciezkaMN' => $sciezka_do_mn,
			'tytul' => $tytul,
			'autor' => $autor,
			'nazwa' => basename($sciezka_do_org),
			'wiad' => "Pomyślnie udało się przesłać plik.",
			'w1' => $ww1,
			'w2' => $ww2
		];
		save_zdj($id, $zdjecie);
    } else {
		$zdjecie = [
			'wiad' => "Nie udalo się przesłać pliku, spróbuj ponownie.",
			'w1' => $ww1,
			'w2' => $ww2
		];
	}		
	$model['zdjecie'] = $zdjecie;
	return 'przesylanie_zdjec_view';
}


function galeria(&$model)
{
	if (!empty($_GET['strona'])) {
        $strona = $_GET['strona'];

        $galeria = get_galeria($strona);
        $model['galeria'] = $galeria;
        $model['strona'] = $strona;
    }
    else{
        $galeria = get_galeria(1);
        $model['galeria'] = $galeria;
        $model['strona'] = 1;
    }
    return 'galeria_view';
}

function zdjecie(&$model)
{
    if (!empty($_GET['id'])) {
        $id = $_GET['id'];

        if ($zdjecie = get_zdj($id)) {
            $model['zdjecie'] = $zdjecie;
            return 'zdjecie_view';
        }
    }

    http_response_code(404);
    exit;
}

function usun(&$model)
{
    if (!empty($_REQUEST['id'])) {
        $id = $_REQUEST['id'];

        if ($_SERVER['REQUEST_METHOD'] === 'POST') {
            delete_zdj($id);
            return 'redirect:galeria';

        } else {
            if ($zdjecie = get_zdj($id)) {
                $model['zdjecie'] = $zdjecie;
                return 'usun_view';
            }
        }
    }

    http_response_code(404);
    exit;
}


