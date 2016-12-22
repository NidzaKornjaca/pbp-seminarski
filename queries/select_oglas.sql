#detaljan prikaz
select * from Oglas 
inner join Poslodavac 
on Oglas.Poslodavac_Korisnik_idKorisnik = Poslodavac.Korisnik_idKorisnik;

#kratak prikaz
select pozicija, datumPostavljanja, datumIsteka, Grad.naziv as Grad, Grad.drzava, Poslodavac.naziv from Oglas inner join Poslodavac on Oglas.Poslodavac_Korisnik_idKorisnik = Poslodavac.Korisnik_idKorisnik join Grad on Oglas.Grad_idGrada = Grad.idGrada;