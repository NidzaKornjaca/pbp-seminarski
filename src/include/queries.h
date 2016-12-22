#include<mysql.h>

extern void queriesSelectAllOglas(char *queryOut);
extern void queriesSelectPrijavaForUser(char *queryOut, unsigned userId);
extern void queriesInsertPrijava(char *queryOut, unsigned userId, unsigned oglasId);
extern void queriesInsertKorisnik(char *queryOut, char *userName, char *pw, char *email);
extern void queriesDeletePrijava(char *queryOut, unsigned userId, unsigned oglasId);
extern void queriesInsertOglas(char *queryOut);