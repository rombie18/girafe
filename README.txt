De voorgestelde mappenstructuur is de volgende:
  - 'src' bevat alle code geschreven in C++;
  - 'references' is een lege map, waarin je interessante bronnen/hyperlinks zou kunnen opslaan;
  - 'data' bevat de .graphml file.

In de .gitignore file kan je aanpassen welke bestanden getrackt worden en welke niet.
Op dit moment worden alle bestanden gevolgd. Als je dit wilt aanpassen, open je .gitignore in kladblok en pas je dit aan.
Als je alle bestanden met een bepaalde extensie niet wilt volgen, voeg je bv. '*.txt'
toe in .gitignore. Als je een bepaalde map niet meer wilt volgen, voeg je bv. '/references' toe in .gitignore.
Het is best om volgend stuk te kopiëren naar je .gitignore file:
*.cmake
*.bin
*.make
src/cmake-build-debug
src/.idea
Hiermee vermijd je dat de output van CMake, Clang/GCC en CLion ook meegenomen wordt in je commits.

In Github Desktop (of Github web) maak je best eerst een lege, private repository aan voor dit project.
Vervolgens kan je je groepsgenoot toevoegen via Github web op de volgende manier:
  1. Ga naar de repository van dit project;
  2. Klik op 'settings';
  3. Ga naar 'manage access';
  4. Klik op de groene knop 'invite a collaborator';
  5. Zoek op de username van je groepsgenoot of gebruik zijn/haar e-mailadres gelinkt aan Github-account.

Doe vervolgens de eerste commit op de main branch met de huidige startcode.

Veel succes!