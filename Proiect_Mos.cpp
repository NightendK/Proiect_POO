#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <list>
#include<set>
# define INF 1000000     // macro pentru setarea distantelor initiale fata de sursa

using namespace std;

typedef struct lis   // structura pentru a realiza o lista inlantuita
{
    char    *jucarie;
    int     pret;
    struct  lis *next;
} t_LISTA;


class Copil                         // Interfata pentru clasa Baiat si Fata
{

public:
    virtual void  SetNume(string n) = 0;   // metode pentru a seta numele persoanei
    virtual void  SetPrenume(string p) = 0; // metoda pentru a seta prenumele
    virtual void  SetVarsta(int v) = 0;     // metoda pentru a seta varsta
    virtual void  SetOras(string o) = 0;    // metoda pentru a seta orasul
    virtual void  SetStat(char st[]) = 0;   // metoda pentru a seta statusul unui copil (rau sau bun)

    virtual string GetNume() = 0;   // metoda de get pentru a returna numele
    virtual string GetPrenume() = 0;
    virtual int   GetVarsta() = 0;
    virtual string GetOras()= 0;
    virtual char *GetStat() = 0;
    virtual int GetBuget() = 0;
};

class Baiat:public Copil
{
private:
    string    nume;
    string    prenume;
    string    oras;
    int     varsta;
    t_LISTA *whislist;    // reprezinta capul listei ce contine jucariile dorite de copil
    char *stats;              // setat pentru a spune daca copilul este bun sau rau
    int buget = 0;                // 10$ daca stats este "rau" si 100$ daca stats este "bun"
    float carbune;         // daca stats este "bun", atunci are valoarea 0. Daca este "rau", atunci este 0.5 si se va adauga la suma finala

public:
    const char Culoare_panglica = 'B';

    void SetNume(string n)
    {
        this -> nume = n;
    }

    void SetPrenume(string p)
    {
        this -> prenume = p;
    }

    void SetVarsta(int v)
    {
        char msg[] = "Varsta nu poate fi negativa!";
        try
        {
            if(v >= 0)
            {
                this -> varsta = v;
            }                           // metoda de try-catch pentru a fi
            //siguri ca varsta este pozitiva
            else
                throw(msg);
        }
        catch(char *msg)
        {
            cout << msg << endl;
            exit(1);
        }
    }

    void SetOras(string o)
    {
        this -> oras = o;
    }

    string GetNume()
    {
        return this -> nume;
    }

    string GetPrenume()
    {
        return this -> prenume;
    }

    string GetOras()
    {
        return this -> oras;
    }

    int GetVarsta()
    {
        return this -> varsta;
    }

    void SetStat(char st[])
    {
        strcpy(this -> stats, st);
    }

    char *GetStat()
    {
        return this -> stats;
    }
    int GetBuget()
    {
        return this -> buget;
    }

    Baiat()                                         // constructor, aloca memoria necesara pentru atribute
    {
        stats = (char*)malloc(sizeof(char));
    }

    void Make_Lista();

    void Show_Lista()
    {
        t_LISTA *p;
        p = (t_LISTA*)malloc(sizeof(t_LISTA));

        for(p = this -> whislist; p != NULL; p = p -> next)
        {
            cout << p -> jucarie << " ";

        }

        cout << endl;
    }

    friend class Elf;
    friend class Trol;
    friend class Doamna_Craciun;
    ~Baiat()
    {
        // destrucorul clasei Baiat, pentru a elibera memoria la finalul programului
        free(stats);
        cout << endl << "Memoria a fost dealocata!" << endl;
    }

};

class Fata:public Copil
{
private:
    string    nume;
    string    prenume;
    string    oras;
    int     varsta;
    t_LISTA *whislist;    // reprezinta capul listei ce contine jucariile dorite de copil
    char *stats;              // setat pentru a spune daca copilul este bun sau rau
    int buget = 0;                // 10$ daca stats este "rau" si 100$ daca stats este "bun"
    float carbune;         // daca stats este "bun", atunci are valoarea 0. Daca este "rau", atunci este 0.5 si se va adauga la suma finala

public:
    const char Culoare_panglica = 'R';

    void SetNume(string n)
    {
        this -> nume = n;
    }

    void SetPrenume(string p)
    {
        this -> prenume = p;
    }

    void SetVarsta(int v)
    {
        char msg[] = "Varsta nu poate fi negativa!";
        try
        {
            if(v >= 0)
            {
                this -> varsta = v;
            }                           // metoda de try-catch pentru a fi
            //siguri ca varsta este pozitiva
            else
                throw(msg);
        }
        catch(char *msg)
        {
            cout << msg << endl;
            exit(1);
        }
    }

    void SetOras(string o)
    {
        this -> oras = o;
    }

    string GetNume()
    {
        return this -> nume;
    }

    string GetPrenume()
    {
        return this -> prenume;
    }

    string GetOras()
    {
        return this -> oras;
    }

    int GetVarsta()
    {
        return this -> varsta;
    }

    void SetStat(char st[])
    {
        strcpy(this -> stats, st);
    }

    char *GetStat()
    {
        return this -> stats;
    }
    int GetBuget()
    {
        return this -> buget;
    }

    Fata()                                         // constructor, aloca memoria necesara pentru atribute
    {
        stats = (char*)malloc(sizeof(char));
    }

    void Make_Lista();

    void Show_Lista()
    {
        t_LISTA *p;
        p = (t_LISTA*)malloc(sizeof(t_LISTA));

        for(p = this -> whislist; p != NULL; p = p -> next)
        {
            cout << p -> jucarie << " ";

        }

        cout << endl;
    }

    friend class Elf;
    friend class Trol;
    friend class Doamna_Craciun;
    ~Fata()
    {
        // destrucorul clasei Baiat, pentru a elibera memoria la finalul programului
        free(stats);
        cout << endl << "Memoria a fost dealocata!" << endl;
    }

};
void Baiat::Make_Lista()
{
    int i;
    int nr_jucarii;    // reprezinta numarul de jucarii, va fi specificat pentru fiecare copil

    t_LISTA *p;
    t_LISTA *q;

    cout << "Cate jucarii doreste baiatul:";
    cin >> nr_jucarii;
    fflush(stdin);

    if(nr_jucarii == 1)
    {
        p = (t_LISTA*)malloc(sizeof(t_LISTA));
        if(p == NULL)
        {
            cout << "Alocare esuata!" << endl;
            exit(1);
        }
        cout << endl;
        cout << "Introduceti numele jucariei:";
        fflush(stdin);

        p -> jucarie = (char*)malloc(sizeof(char));
        gets(p -> jucarie);
        fflush(stdin);

        cout << "Valoarea jucariei este:";
        cin >> p -> pret;
        fflush(stdin);

        p -> next = NULL;
        this -> whislist = p;
    }
    else
    {
        p = (t_LISTA*)malloc(sizeof(t_LISTA));
        if(p == NULL)
        {
            cout << "Alocare esuata!" << endl;
            exit(1);
        }
        cout << endl;
        cout << "Introduceti numele primei jucarii:";
        fflush(stdin);

        p -> jucarie = (char*)malloc(sizeof(char));
        gets(p -> jucarie);
        fflush(stdin);

        cout << "Valoarea jucariei este:";
        cin >> p -> pret;
        fflush(stdin);

        p -> next = NULL;
        this -> whislist  = p;

        cout << endl;
        cout << "Introduceti restul de jucarii:" << endl;
        fflush(stdin);

        for(i = 2; i <= nr_jucarii; i++)
        {
            q = (t_LISTA*)malloc(sizeof(t_LISTA));
            if(q == NULL)
            {
                cout << "Alocare esuata!";
                exit(1);
            }

            printf("Introduceti numele celei de a %d jucarii:",i);
            q -> jucarie = (char*)malloc(sizeof(char));
            gets(q -> jucarie);
            fflush(stdin);

            cout << "Pretul jucariei este:";
            cin >> q -> pret;
            fflush(stdin);

            q -> next = NULL;
            p -> next = q;
            p = q;

        }
    }

    cout << endl << "Wishlistul a fost creat!" << endl;

}

void Fata::Make_Lista()
{
    int i;
    int nr_jucarii;

    t_LISTA *p;
    t_LISTA *q;

    cout << "Cate jucarii doreste fata:";
    cin >> nr_jucarii;
    fflush(stdin);

    if(nr_jucarii == 1)
    {
        p = (t_LISTA*)malloc(sizeof(t_LISTA));
        if(p == NULL)
        {
            cout << "Alocare esuata!" << endl;
            exit(1);
        }
        cout << endl;
        cout << "Introduceti numele jucariei:";
        fflush(stdin);

        p -> jucarie = (char*)malloc(sizeof(char));
        gets(p -> jucarie);
        fflush(stdin);

        cout << "Valoarea jucariei este:";
        cin >> p -> pret;
        fflush(stdin);

        p -> next = NULL;
        this -> whislist = p;
    }
    else
    {
        p = (t_LISTA*)malloc(sizeof(t_LISTA));
        if(p == NULL)
        {
            cout << "Alocare esuata!" << endl;
            exit(1);
        }
        cout << endl;
        cout << "Introduceti numele primei jucarii:";
        fflush(stdin);

        p -> jucarie = (char*)malloc(sizeof(char));
        gets(p -> jucarie);
        fflush(stdin);

        cout << "Valoarea jucariei este:";
        cin >> p -> pret;
        fflush(stdin);

        p -> next = NULL;
        this -> whislist  = p;

        cout << endl;
        cout << "Introduceti restul de jucarii:" << endl;
        fflush(stdin);

        for(i = 2; i <= nr_jucarii; i++)
        {
            q = (t_LISTA*)malloc(sizeof(t_LISTA));
            if(q == NULL)
            {
                cout << "Alocare esuata!";
                exit(1);
            }

            printf("Introduceti numele celei de a %d jucarii:",i);
            q -> jucarie = (char*)malloc(sizeof(char));
            gets(q -> jucarie);
            fflush(stdin);

            cout << "Pretul jucariei este:";
            cin >> q -> pret;
            fflush(stdin);

            q -> next = NULL;
            p -> next = q;
            p = q;

        }
    }

    cout << endl << "Wishlistul a fost creat!" << endl;

}


class Elf
{
private:
    const char *cadou_bun = "Lego_Star_Wars_Battle_Ship"; // cadoul default pentru Baiat
    const char *cadou_rau = "Spongebob_mini_grill";
    vector <string> BAG;  // sacul de cadouri ce va fi dus de Mos catre fiecare copil
    int nr_acadele;
    int suma_finala;

public:
    t_LISTA *INVENTAR;// capul inventarului
    void Make_Inventar();
    void Show_Inventar();
    void Put_in_bag_Baiat(Baiat *b);  // metoda de a pune jucariile in sac pentru baieti
    void Put_in_bag_Fata(Fata *f);      // metoda de a pune jucariile in sac pentru fete
    void Aloca_buget_Baiat(Baiat *b);   // metoda de alocare a bugetului pentru baieti
    void Aloca_buget_Fata(Fata *f);     // metoda de alocare a bugetului pentru fete
    void Show_Bag();
    void Inventar_Comun(Elf *e1);   // metoda de a egala inventarele pentru mai multi elfi

    friend class Trol;
    friend class Doamna_Craciun;
};



void Elf::Make_Inventar()

{
    int i;
    int nr_jucarii;

    t_LISTA *p;
    t_LISTA *q;

    cout << "Cate jucarii sunt in inventar:";
    cin >> nr_jucarii;
    fflush(stdin);

    if(nr_jucarii == 1)
    {
        p = (t_LISTA*)malloc(sizeof(t_LISTA));
        if(p == NULL)
        {
            cout << "Alocare esuata!" << endl;
            exit(1);
        }
        cout << endl;
        cout << "Introduceti numele jucariei:";
        fflush(stdin);

        p -> jucarie = (char*)malloc(sizeof(char));
        gets(p -> jucarie);
        fflush(stdin);

        cout << "Valoarea jucariei este:";
        cin >> p -> pret;
        fflush(stdin);

        p -> next = NULL;
        this -> INVENTAR = p;
    }
    else
    {
        p = (t_LISTA*)malloc(sizeof(t_LISTA));
        if(p == NULL)
        {
            cout << "Alocare esuata!" << endl;
            exit(1);
        }
        cout << endl;
        cout << "Introduceti numele primei jucarii:";
        fflush(stdin);

        p -> jucarie = (char*)malloc(sizeof(char));
        gets(p -> jucarie);
        fflush(stdin);

        cout << "Valoarea jucariei este:";
        cin >> p -> pret;
        fflush(stdin);

        p -> next = NULL;
        this -> INVENTAR = p;

        cout << endl;
        cout << "Introduceti restul de jucarii:" << endl;
        fflush(stdin);

        for(i = 2; i <= nr_jucarii; i++)
        {
            q = (t_LISTA*)malloc(sizeof(t_LISTA));
            if(q == NULL)
            {
                cout << "Alocare esuata!";
                exit(1);
            }

            printf("Introduceti numele celei de a %d jucarii:",i);
            q -> jucarie = (char*)malloc(sizeof(char));
            gets(q -> jucarie);
            fflush(stdin);

            cout << "Pretul jucariei este:";
            cin >> q -> pret;
            fflush(stdin);

            q -> next = NULL;
            p -> next = q;
            p = q;

        }
    }
    cout << endl << "Inventarul a fost creat!" << endl;
}


void Elf::Show_Inventar()
{
    cout << "Inventarul este alcatuit din:" << endl;
    t_LISTA *p;

    for(p = this -> INVENTAR; p != NULL; p = p -> next)

    {
        printf("Jucaria cu numele %s are pretul de %d", p -> jucarie, p -> pret);
        cout << endl;
    }
}

void Elf::Aloca_buget_Baiat(Baiat *b)
{
    if(strcmp("bun", b -> stats) == 0)
    {
        b -> buget = 100;
    }
    else
        b -> buget = 10;
}

void Elf::Aloca_buget_Fata(Fata *f)
{
    if(strcmp("bun", f -> stats) == 0)
    {
        f -> buget = 100;
    }
    else
        f -> buget = 10;
}


void Elf::Put_in_bag_Baiat(Baiat *b)
{
    t_LISTA *p1;    // pentru INVENTAR care face parte din clasa ELF
    t_LISTA *p2;   // pentru clasa Baiat/Fata pentru a accesa wishlistul
    this -> suma_finala = 0;
    this -> nr_acadele = 0; // initial initializam atat nr de acadele cat si suma finala cu 0
    p2 = b -> whislist;

    if(p2 == NULL && b -> buget == 100)
    {
        BAG.push_back(this -> cadou_bun);
    }
    else if(p2 == NULL && b -> buget == 10)
    {
        BAG.push_back(this -> cadou_rau);
    }

    else if(p2 -> pret > b -> buget && b -> buget == 100)
    {
        BAG.push_back(this -> cadou_bun);
    }

    else if(p2 -> pret > b -> buget && b -> buget == 10)
    {
        BAG.push_back(this -> cadou_rau);
    }


    else
    {
        for(p1 = this -> INVENTAR; p1 != NULL; p1 = p1 -> next)
        {
            for(p2 = b -> whislist; p2 != NULL; p2 = p2 -> next)
            {
                if(strcmp(p1 -> jucarie, p2 -> jucarie) == 0 && this -> suma_finala <= b -> buget)

                {
                    BAG.push_back(p2 -> jucarie);
                    this -> suma_finala += p2 -> pret;
                    if(this -> suma_finala <= b -> buget)
                        continue;
                    else
                    {
                        this -> suma_finala = this -> suma_finala - p2 -> pret;
                        BAG.pop_back();
                    }
                }
            }

        }
        if(this -> suma_finala == b -> buget)
        {
            cout << "Whislistul acopera in total tot bugetul" << endl;
        }
        else
        {
            this -> nr_acadele = b -> buget - this -> suma_finala ;
            cout << "Nr de acadele pentru copil este " << this -> nr_acadele << endl;
            cout << "Suma finala este " << this -> suma_finala << endl;
        }

    }


}
void Elf::Put_in_bag_Fata(Fata *f)
{
    t_LISTA *p1;
    t_LISTA *p2;
    this -> suma_finala = 0;
    this -> nr_acadele = 0;

    p2 = f -> whislist;

    if(p2 == NULL && f-> buget == 100)
    {
        BAG.push_back(this -> cadou_bun);
    }
    else if(p2 == NULL && f -> buget == 10)
    {
        BAG.push_back(this -> cadou_rau);
    }

    else if(p2 -> pret > f -> buget && f -> buget == 100)
    {
        BAG.push_back(this -> cadou_bun);
    }

    else if(p2 -> pret > f -> buget && f -> buget == 10)
    {
        BAG.push_back(this -> cadou_rau);
    }


    else
    {
        for(p1 = this -> INVENTAR; p1 != NULL; p1 = p1 -> next)
        {
            for(p2 = f -> whislist; p2 != NULL; p2 = p2 -> next)
            {
                if(strcmp(p1 -> jucarie, p2 -> jucarie) == 0 && this -> suma_finala <= f -> buget)

                {
                    BAG.push_back(p2 -> jucarie);
                    this -> suma_finala += p2 -> pret;
                    if(this -> suma_finala <= f -> buget)
                        continue;
                    else
                    {
                        this -> suma_finala = this -> suma_finala - p2 -> pret;
                        BAG.pop_back();
                    }
                }
            }

        }
        if(this -> suma_finala == f -> buget)
        {
            cout << "Whislistul acopera in total tot bugetul" << endl;
        }
        else
        {
            this -> nr_acadele = f -> buget - this -> suma_finala ;
            cout << "Nr de acadele pentru copil este " << this -> nr_acadele << endl;
            cout << "Suma finala este " << this -> suma_finala << endl;
        }

    }

}

void Elf::Show_Bag()
{
    int i;
    for(i = 0; i < this -> BAG.size(); i++)
    {
        cout << this -> BAG[i] << " " ;
    }
    cout << endl;
}

void Elf::Inventar_Comun(Elf *e1)

{
    this -> INVENTAR = e1 -> INVENTAR;
}

class Trol
{
public:
    static void Impacheteaza_cadou_baiat(Baiat *b);
    static void Impacheteaza_cadou_fata(Fata *f);
    static int ambalaj_baieti;    // de tip static, astfel la final va afisa numarul
    static int ambalaj_fete;      // final de ambalaj pentru fete, respectiv baieti
};

int Trol::ambalaj_baieti = 0;
int Trol::ambalaj_fete = 0;

void Trol::Impacheteaza_cadou_baiat(Baiat *b)
{
    cout << "Trolul a impachetat cadoul baiatului" << endl;
    ambalaj_baieti++;
    if(strcmp(b -> stats, "rau") == 0)
        b -> carbune = 0.5;
}

void Trol::Impacheteaza_cadou_fata(Fata *f)
{
    cout << "Trolul a impachetat cadoul fetei" << endl;
    ambalaj_fete++;
    if(strcmp(f -> stats, "rau") == 0)
        f -> carbune = 0.5;
}


class Doamna_Craciun
{
public:
    void BugetExtra_B(Baiat *b, Elf *e);
    void BugetExtra_F(Fata *f, Elf *e);
    float buget_extra;
};

void Doamna_Craciun::BugetExtra_B(Baiat *b, Elf *e)
{
    if(strcmp(b -> stats, "rau") == 0)
    {
        this -> buget_extra = b -> carbune + e -> nr_acadele;
    }
    else
        this -> buget_extra = e -> nr_acadele;
}

void Doamna_Craciun::BugetExtra_F(Fata *f, Elf *e)
{
    if(strcmp(f -> stats, "rau") == 0)
    {
        this -> buget_extra = f -> carbune + e -> nr_acadele;
    }
    else
        this -> buget_extra = e -> nr_acadele;
}


class Mos_Craciun
{
private:
    int Nr_Orase;
    list< pair<int, int> > *adjudant;

public:
    Mos_Craciun(int V);  // constructor
    void Adauga_Drum(int u, int v, int w);
    void Drum_Minim(int s);  // foloseste algoritmul Dijkstra pentru a calcula drumul cel mai scurt
};


Mos_Craciun::Mos_Craciun(int V)    // V reprezinta numarul de orase
{
    this -> Nr_Orase = V;
    adjudant = new list< pair<int, int> >[V];
}

void Mos_Craciun::Adauga_Drum(int u, int v, int w)
{
    adjudant[u].push_back(make_pair(v, w)); // realizeaza legatura dintre nodul u si nodul v si specifica nr de km(w)
    adjudant[v].push_back(make_pair(u, w));
}


void Mos_Craciun::Drum_Minim(int sursa)
{
    set< pair<int, int> > setds;
    vector<int> dist(Nr_Orase, INF);

    setds.insert(make_pair(0, sursa));
    dist[sursa] = 0;

    while (!setds.empty())  // pentru a verifica fiecare nod
    {

        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());

        int u = tmp.second;
        list< pair<int, int> >::iterator i;

        for (i = adjudant[u].begin(); i != adjudant[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (dist[v] > dist[u] + weight)
            {

                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));

                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }

    cout << "Distanta celor 4 orase din Ucraina fata de Rovanien este:" << endl;
    for (int i = 0; i < Nr_Orase; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}




int main(void)

{
    Baiat b1;
    b1.SetStat("bun");
    b1.SetNume("Makar");
    b1.SetPrenume("Alexei");
    b1.SetOras("Kiev");
    b1.SetVarsta(7);
    b1.Make_Lista();

    Elf e1;
    e1.Make_Inventar();
    e1.Aloca_buget_Baiat(&b1);
    e1.Put_in_bag_Baiat(&b1);
    cout << b1.GetNume() << " " << b1.GetPrenume() << " va primii:";
    e1.Show_Bag();

    Trol t1;
    t1.Impacheteaza_cadou_baiat(&b1);
    Doamna_Craciun D;
    D.BugetExtra_B(&b1,&e1);
    cout << "Bugetul extra pentru " << b1.GetNume() << " " << b1.GetPrenume() << " este:" << D.buget_extra;
    cout << endl << endl;

    Baiat b2;
    b2.SetStat("rau");
    b2.SetOras("Oster");
    b2.SetNume("Naum");
    b2.SetPrenume("Andrei");
    b2.SetVarsta(11);
    b2.Make_Lista();

    Elf e2;
    e2.Inventar_Comun(&e1);
    e2.Aloca_buget_Baiat(&b2);
    e2.Put_in_bag_Baiat(&b2);
    cout << b2.GetNume() << " " << b2.GetPrenume() << " va primii:";
    e2.Show_Bag();

    t1.Impacheteaza_cadou_baiat(&b2);
    D.BugetExtra_B(&b2,&e2);
    cout << "Bugetul extra pentru " << b2.GetNume() << " " << b2.GetPrenume() << " este:" << D.buget_extra;
    cout << endl << endl;

    Baiat b3;
    b3.SetStat("bun");
    b3.SetOras("Kaniv");
    b3.SetNume("Kliciko");
    b3.SetPrenume("Vladimir");
    b3.SetVarsta(16);
    b3.Make_Lista();

    Elf e3;
    e3.Inventar_Comun(&e1);
    e3.Aloca_buget_Baiat(&b3);
    e3.Put_in_bag_Baiat(&b3);
    cout << b3.GetNume() << " " << b3.GetPrenume() << " va primii:";
    e3.Show_Bag();

    t1.Impacheteaza_cadou_baiat(&b3);
    D.BugetExtra_B(&b3,&e3);
    cout << "Bugetul extra pentru " << b3.GetNume() << " " << b3.GetPrenume() << " este:" << D.buget_extra;
    cout << endl << endl;

    Fata f1;
    f1.SetStat("bun");
    f1.SetOras("Kiev");
    f1.SetNume("Korman");
    f1.SetPrenume("Anna");
    f1.SetVarsta(9);
    f1.Make_Lista();

    Elf e4;
    e4.Inventar_Comun(&e1);
    e4.Aloca_buget_Fata(&f1);
    e4.Put_in_bag_Fata(&f1);
    cout << f1.GetNume() << " " << f1.GetPrenume() << " va primii:";
    e4.Show_Bag();

    t1.Impacheteaza_cadou_fata(&f1);
    D.BugetExtra_F(&f1,&e4);
    cout << "Bugetul extra pentru " << f1.GetNume() << " " << f1.GetPrenume() << " este:" << D.buget_extra;
    cout << endl << endl;

    Fata f2;
    f2.SetStat("rau");
    f2.SetOras("Odessa");
    f2.SetNume("Ivanov");
    f2.SetPrenume("Ingrid");
    f2.SetVarsta(10);
    f2.Make_Lista();

    Elf e5;
    e5.Inventar_Comun(&e1);
    e5.Aloca_buget_Fata(&f2);
    e5.Put_in_bag_Fata(&f2);
    cout << f2.GetNume() << " " << f2.GetPrenume() << " va primii:";
    e5.Show_Bag();

    t1.Impacheteaza_cadou_fata(&f2);
    D.BugetExtra_F(&f2,&e5);
    cout << "Bugetul extra pentru " << f2.GetNume() << " " << f2.GetPrenume() << " este:" << D.buget_extra;
    cout << endl << endl;

    cout << "Trolii au folosit " << t1.ambalaj_baieti << " ambalaje pentru baieti si " << t1.ambalaj_fete << " ambalaje pentru fete." << endl << endl;

    Mos_Craciun Claus(5);

    Claus.Adauga_Drum(0, 1, 1805);       // 0 Rovanien, 1 Kiev, 2 Odesa , 3 Oster, 4 Kaniv.
    Claus.Adauga_Drum(0, 2, 2245);
    Claus.Adauga_Drum(1, 2, 441);
    Claus.Adauga_Drum(1, 4, 101);
    Claus.Adauga_Drum(2, 3, 497);
    Claus.Adauga_Drum(3, 4, 139);

    Claus.Drum_Minim(0);

    cout << "Drumul lui Mos Craciun este urmatorul :" << endl;
    cout << "Rovanien -> " << b1.GetOras() <<" -> " << b3.GetOras() << " -> " << b2.GetOras() << " -> " << f2.GetOras() << endl;

    return 0;
}
