Rapport oblig 1, C++ våren 2013
---------------------------------------------
Min implementasjon er nok ganske rotete. I og med at dette er det første C++-programmet jeg har laget har
det vært *MYE* prøving og feiling involvert, og jeg har rett og slett ikke hatt tid til å rydde opp skikkelig.
Jeg er heller ikke vant med å kode via terminal, så der er jeg heller ikke så effektiv som jeg kunne vært.
Jeg har allikevel valgt å kode via studssh slik at jeg også fikk testet koden min der underveis, og for å bli
mer vant til det. I begynnelsen brukte jeg Notepad++ på Windows, men gikk over til studssh underveis.

#Problemområder
Jeg har slitt spesielt med å forstå meg på tankegangen bak header-filene. Hva det er tenkt at hver klasse og metode
 skal gjøre osv. Oppsettet er ganske annerledes fra det jeg er vant til fra java-undervisning særlig fordi det 
er et slags kompromiss mellom å være fleksibelt med tanke på utvidelse, og å ikke bli for mye arbeid. Det er også 
mindre kommentarer med forklaringer til hva metodene skal gjøre enn det jeg er vant til. Jeg aner derfor ikke om 
jeg har implementert klassene og metodene slik det er tenkt eller ikke.

Jeg har også hatt en del problemer med generell implementasjon av klasser, da det her også er en del forskjeller 
fra hvordan det er i java.

Jeg har også slitt en del med peker, og særlig takeAction() både i gambler og strategy, der jeg lenge fikk 
segmentation fault.

#Arbeidsmetode
18\. februar: Begynne på card og deck.

19\. februar: Mistet det jeg hadde gjort, så lager card og deck på nytt.

19.-24. februar: Prøver å begynne på de andre klassene, men sliter med å forstå dem.

24.-27. februar: Lager et fungerende blackjack-spill i class_blackjackGame.cpp uten å bruke andre klasser enn card og deck.

27\. februar - 3. mars: Lager og implementerer resten av klassene.


#Om implementasjonen
##class_blackjackGame:
Jeg har valgt å ha cardsDealt, int hero og int dealer som i class_blackjackState for å enkelt kunne nå dem og 
opprette states.
Jeg har valgt å ha en metode for å regne ut poengsummen til en hånd. Hadde jeg hatt bedre tid hadde jeg prøvd å 
finne en metode som ikke må iterere gjennom alle kortene hver gang, men som legger til summen etter hvert som man 
trekker kort.
