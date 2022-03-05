Cerintele 1 si 2 nu au avut nevoie de implementari complexe.

Cerinta 3:
a) Parcurg lista de produse a serverului cu ajutorul unui iterator list, unde verific daca produsul este unul redus dar si espressor folosindu-ma de get-eri implementati la cerintele anterioare. Cand gasesc un produs care indeplineste cerintele il adaug in lista creata ce va fi returnata de functia Query_3a().

b) Parcurg lista de utilizatori a serverului si verific daca userii sunt de tipuul nonpremium si daca pretul transportului asociat acestor useri este <= 11.5. Daca da, adaug userii in lista pe care o voi returna.

c) Parcurg lista de produse de pe server cautand produsele resigilate. Folosesc apoi dynamic_cast pentru a transforma produsul in unul de tipul Returned Product pentru a putea accesa campul Reason. Daca motivul returnarii este cel cautat, adaug produsul in lista ce urmeaza sa fie returnata la finalul functiei. Inainte de return, folosesc functia price_sort(Product*,Product*), implementata in acelasi fisier, ca si regula de sortare pentru metoda sort() a listei, astfel sortand produsele dupa pret si returnand lista ceruta.

d) Pentru rezolvarea acestei cerinte, in stil asemanator celei de mai sus, am avut nevoie de 3 functii folosite ca regula pentru realizarea sortarii cerute. name_sort permite sortarea produselor dupa nume, country_sort permite sortarea produselor dupa tara de provenienta, dar doar in cazul in care numele a doua produse este acelasi, iar pKG_sort permite sortarea in cazul in care si numele si tara sunt identice. Astfel, apeland sort(fiecare dintre cele 3 functii) una dupa alta, incepand cu name_sort, se va realiza sortarea ceruta.

e) Mai intai am nevoie de mapul counties in care cheia este numele judetului si valoarea este numarul de aparitii al acelui judet ca si adresa pe server, pentru a stabili care este judetul cel mai popular. Am avut nevoie de functia county_check() care verifica daca un judet este deja prezent in map-ul de judete, caz in care doar maresc numarul de aparitii al judetului respectiv in map, sau il adaug in map daca acesta nu fusese deja adaugat.

Parcurgand lista creata si gasind maximul de aparitii si salvand judetul asociat acelui maxim stabilesc care dintre judete este cel mai popular.

Parcurg din nou lista de useri pentru a verifica care dintre useri are judetul gasit ca adresa de facturare(presupunand ca locuiesc la aceasta adresa) si daca au atat adresa de facturare cat si cea de livrare la casa. Adaug utilizatorii gasiti in lista si apoi ii sortez dupa ID cu ajutorul functiei user_id_sort().

f) Parcurg lista de useri de pe server si verific daca acestia sunt de tipul premium. Folosesc variabila ok pentru a tine minte daca am adaugat deja userul respectiv in lista ce trebuie creata, evitand sa adaug userul in lista pentru fiecare produs de tipul cerut pe care il are in lista de discount-uri.

Parcurg apoi lista de produse de pe server, iar pentru fiecare produs de tipul cerut verific daca acesta se afla in lista de discounturi a userului curent. Daca da, iar variabila ok imi indica, de asemenea, ca nu am mai adaugat userul deja in lista (ok==0), atunci adaug userul in lista ce va fi returnata si dau variabilei ok valoarea 1 pentru a nu mai adauga userul in viitor.

Cerinta 4:

Cu primul for parcurg fiecare element din lista de requesturi pe care o primesc. Cu al doilea for verific daca requestul se afla deja in lru, caz in care il sterg. Al treilea for realizeaza mutarea elementelor din lru cu o pozitie la dreapta pentru a face loc pe prima pozitie requestului ce urmeaza sa fie introdus cu ajutorul liniei 35.

Cerinta 5:

Pentru functia requestAddProduct, primul for verifica daca userID-ul primit ca parametru este valid. Daca da, incrementez variabila for si opresc for-ul de parcurgere al listei de useri de pe server.

Incep apoi cu al doilea for parcurgerea produselor de pe server pentru a verifica daca producID-ul primit este valid. Daca da, si userID-ul a fost de asemenea unul valid, verific daca cantitatea ceruta este una valida cu ajutorul functiei checkQuantity ce a fost implementata in cerinte anterioare. Daca da, reduc din cantitatea de produs ce se gaseste pe server, aceasta urmand sa fie adaugata in cosul userului. Continui prin a verifica daca produsul se afla deja in cosul userului pentru a sti daca este nevoie de o adaugare in cos sau doar o incrementare a cantitatii deja existente in cos. Fac asta prin parcurgerea map-ului ce face legatura dintre utilizatori si cosurile ce le sunt adresate si prin parcurgerea produselor aflate in cosul utilizatorului respectiv.

Asemanator pentru functia requestDeleteProduct, unde in final am de verificat daca cantitatea de sters duce sau nu la eliminarea din cos a produsului cerut. De asemenea, modificarea cantitatii de produs de pe server nu se mai face decat dupa ce se verifica daca cantitatea de sters depaseste sau nu cantitatea deja existenta in cos. De asemenea, nu mai este nevoie de utilizarea functiei checkQuantity().