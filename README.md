# Oglasi za posao

_Autor: Nikola Vlahović_

__Oglas__ se odlikuje _identifikatorom, autorom, datumom postavljanja, tagovima,
pozicijom, opisom pozicije, __gradom__ zaposlenja,
i rokom isteka konkursa_.

Oglase postavljaju *poslodavci*, a na njih se prijalvjuju 
__tragači__.

Svaki korisnik ima _jedinstveno korisničko ime, lozinku i e-mail_.
Osobe u potrazi za poslom mogu uz to dodati _ime i prezime, 
sliku, link ka CV-u, kratak opis, stručnu spremu, grad,
i listu oblasti za koje su zainteresovani_.

Poslodavac obavezno ima _ime firme, adresu, br. telefona_.
Može _imati vebsajt i opis_.

Tragač moze da zaprati poslodavca - mejlom biva obavešten kada
poslodavac okaci oglas.

Poslodavci moraju da uplate kredit da bi mogli da postavljaju
oglase.

__Cenovnik__ sadrži cene raznih usluga kojima mogu da pristupe
poslodavci, npr. viši prioritet oglasa, postavljanje oglasa 
i sl.

__Prioritetni oglasi__ su označeni _datumom završetka pretplate i
identifikatorom oglasa_.

## Entiteti

- Korisnik (Nezavisan)- Poslodavac / Tragač (Nasleđivanje)
- Oglas (Nezavisan)
- Konkurisao (Agregiran)
- Grad (Nezavisan)
- Cenovnik usluga (Nezavisan)
- Prioritetni oglasi (Slab)
- Pracenje (Agregiran)

## Trigeri

- Pri kupovini usluge neophodno je da poslodavac ima dovoljno 
sredstava na računu, i tada se taj iznos skida.
- Ne treba dozvoliti tragačima prijavljivanje na istekle oglase.
- Pri postavljanju oglasa upotrebiti odgovarajucu uslugu.

## Upiti

- Izlistavanje oglasa uz nazive poslodavaca
- Izlistavanje prijava za konkretnog korisnika
- Pravljenje oglasa
- Pravljenje korisnika
- Prijavljivanje korisnika
- Brisanje prijave korisnika