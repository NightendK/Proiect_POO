# Proiect_POO
  Proiectul foloseste cei 4 piloni ai programarii orientate pe obiecte: Mostenire, Incapsulare, Polimorfism si Abstractizare.
Programul foloseste o interfata numita Copil folosita de clasele Baiat si Fata, acestea avand drept caracteristica diferita culoarea plicului, fiind declarata de tip
const char pentru ambele clase. Astfel, clasa Baiat are culoarea panglicii egala cu 'B' iar clasa Fata are culoarea 'R'.

  Informatiile legate de obiectele de tipul Baiat, respectiv Fata sunt luate folosind metode de tip Geters si Seters, informatiile sunt scrise de catre utilizator in main(), inainte de rulare.
Pe langa atributele precum nume, varsta, oras, aceste 2 clase mai au niste atribute importante pentru rularea acestui program, *whislist*, un pointer de tip t_LISTA, unde t_LISTA este o structura definita de mine pentru a folosii liste inlantuite. Whislistul reprezinta capul listei de jucarii pe care fiecare copil o va scrie si care va trece mai departe la elfi.

  Clasa Baiat si Fata au constructori ce aloca memoria dinamic pentru atributul stats, ce determina daca un copil este "rau" sau "bun", iar destructorul elibereaza memoria la finalul executarii programului. Clasele Fata si Baiat au 3 friend class-uri, Elf, Trol si Doamna_Craciun, fiecare cu un rol specific.

  Clasa Elf in prima parte aloca bugetul fiecarui copil analizand statul acestuia, daca stats = "bun", atunci bugetul copilului est 100$, altfel valoarea sa este de 10$, dupa trece mai departe si realizeaza inventarul. 
  Cum avem 2 clase pentru copii, programul merge facand urmatoarea asociatie: pentru fiecare copil va exista un elf. De exemplu, pentru 3 copii vor exista 3 elfi. Acest lucru se intampla deoarece toate metodele elfiilor sunt dublate, de exemplu o astfel de functie este Put_in_Bag care realizeaza sacul cu cadouri pentru fiecare copil. Aceasta metoda se imparte in 2 ramuri, Put_in_Bag_Baiat, respectiv Put_in_Bag_Fata.
  
   Elfii construiesc un inventar cu jucarii disponibile, inventarul este acelasi pentru toti elfii. Dupa se uita la statusul fiecarui copil si, folosind containerul <vector>, elful pune pentru copilul sau cadoul sau codurile specifice, urmarind cerinta problemei.
    
   Elfii de asemenea sunt cei ce pun acadelele si calculeaza suma finala (suma finala reprezinta valoarea cadourilor ce vor fi trimise fiecarui copil)
  
  Clasa Trol are doar metode si atribute statice deoarece va afisa la final cate impachetari au fost efectuate pentru fete, respectiv baieti. Pe langa acest lucru, trolii vor adauga carbuni unde este cazul.
  
   Doamna Craciun calculeaza bugetul extra si l afiseaza pentru fiecare copil. Pentru clasele Doamna Craciun, Trol si Mos Craciun exista doar un singur obiect.
  
   Mos Craciun calculeaza drumul cel mai scurt folosind algoritmul Dijkstra, implementat folosind containere din C++ (vector, list, set). Reprezentarea oraselor in algoritm se face pe baza de noduri de tip int, afisearea finala a drumului folosiind numele acestora fiind posibila datorita stabilirii initiale a oraselor si a distantelor.
   
   **RULAREA IN MAIN**
   Pentru ca algoritmul sa functioneze eficient, este nevoie ca anumite atribute sa fie setate la inceput.
   Odata cu constructia unui obiect de tip fata sau baiat, este important setat statu-ul si whislistul inainte de a trece mai departe la elful asociat care va creea inventarul ce va fi acelasi pentru toti elfii. Setarea acestor 2 atribute este importanta deoarece elful lucreaza mai departe cu acestea pentru a creea sacul cu cadourile finale. Daca acestea nu au fost initializate inainte de a folosii metodele elfului, atunci programul nu va functiona corectspunzator.
   Mai departe se apeleaza trolul care va impacheta cadoul pentru copil si dupa programul trece la Doamna Craciun care va calcula bugetul extra. Acest flow se executa pentru totii copiii.
   La final Mos Craciun calculeaza drumul cel mai scurt si il afiseaza.
   
   
   **Probleme intalnite: **
    
  Daca un copil are mai mult de o jucarie in whislist iar pretul primei jucarii este mai mare decat bugetul, dar pretul celei de al 2-lea este mai mic sau egal decat bugetul, programul va vedea faptul ca pretul primei jucarii este mai mare decat bugetul alocat si va pune in sacosa cadoul default.
  


