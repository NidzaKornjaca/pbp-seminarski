select * from Prijava
join Oglas
on Prijava.Oglas_idOglas = Oglas.idOglas
where Tragac_Korisnik_idKorisnik = 6;