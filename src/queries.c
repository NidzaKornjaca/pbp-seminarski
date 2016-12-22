#include<stdio.h>

void queriesSelectAllOglas(char *queryOut){
	sprintf(queryOut, "select pozicija, datumPostavljanja, datumIsteka, Grad.naziv as Grad, Grad.drzava, Poslodavac.naziv from Oglas inner join Poslodavac on Oglas.Poslodavac_Korisnik_idKorisnik = Poslodavac.Korisnik_idKorisnik join Grad on Oglas.Grad_idGrada = Grad.idGrada;");	
}

void queriesSelectPrijavaForUser(char *queryOut, unsigned userId){
	sprintf(queryOut, "select pozicija, datumIsteka, Grad.naziv as grad, Grad.drzava, Poslodavac.naziv as poslodavac from Prijava join Oglas on Prijava.Oglas_idOglas = Oglas.idOglas inner join Poslodavac on Oglas.Poslodavac_Korisnik_idKorisnik = Poslodavac.Korisnik_idKorisnik join Grad on Oglas.Grad_idGrada = Grad.idGrada where Tragac_Korisnik_idKorisnik = %u;", userId);
}

void queriesInsertPrijava(char *queryOut, unsigned userId, unsigned oglasId){
	sprintf(queryOut, "INSERT INTO `Prijava` (`Tragac_Korisnik_idKorisnik`,`Oglas_idOglas`) VALUES (%u,%u);", userId, oglasId);	
}

void queriesInsertKorisnik(char *queryOut, char *userName, char *pw, char *email){
	sprintf(queryOut, "INSERT INTO `Korisnik` (`korisnickoIme`,`lozinka`,`email`) VALUES ('%s','%s','%s');", userName, pw, email);
}
void queriesDeletePrijava(char *queryOut, unsigned userId, unsigned oglasId){
	sprintf(queryOut, "delete from Prijava where Tragac_Korisnik_idKorisnik = %u and Oglas_idOglas = %u;", userId, oglasId);
}

void queriesInsertOglas(char *queryOut){
	sprintf(queryOut, "INSERT INTO `Oglas` (`pozicija`,`opisPozicije`,`datumPostavljanja`,`datumIsteka`,`Grad_idGrada`,`Poslodavac_Korisnik_idKorisnik`) VALUES ('Public Relations','Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Curabitur sed','2016-03-03 22:38:03','2017-11-16 00:39:46',3,38);");
}