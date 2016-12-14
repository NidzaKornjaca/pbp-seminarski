select * from Oglas 
inner join Poslodavac 
on Oglas.Poslodavac_Korisnik_idKorisnik = Poslodavac.Korisnik_idKorisnik;
