#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

static int i=0;
struct data_akun //struct merupakan bagian dari modul 1
{
    char username[50], password[50];
}user, temp[50], temp2[50];
int n, pass_admin;
int pilih = 0, pilih1 = 0, pilih2 = 0, total_harga, total_akun, total, hasil_koma;
void login(void); void reg(void); void menu_utama(void); void harga(void); void admin(void);//void histori_pembelian(void);
void mole(void); void aov(void); void frefi(void); void pubg(void); //void merupakan bagian dari modul 5
char user_admin[50], nama_histori[50]; char hasil_game[50];

int main()
{
    SetConsoleTitle("Joki Game Beta v0.30.8"); //setconsoletitle itu bagian dari coba"
    system("cls");
    printf("\t\tSelamat datang di Program Joki Game\n");
    printf("\t\nGame yang tersedia :\n");
    printf("\n1. ML\t\t\t3. FF");
    printf("\n2. AOV\t\t\t4. PUBG\n\n");

    XY:
    printf("\n\n\t\tSilahkan Login untuk melanjutkan");
    printf("\n\n1. Login\t\t2. Register\t\t3. Admin");
    printf("\n\nMasukkan pilihan mu: ");
    scanf("%d",&n);
    fflush(stdin);
    switch(n) //switch Case itu merupakan modul 2
    {
        case 1: system("cls");
            login();
            break;
        case 2: system("cls");
            reg();
            break;
        case 3: system("cls");
            XY1:
            printf("User dan Pass Admin anda\n");
            printf("Username : ");
            scanf("%s", &user_admin);
            printf("Password : ");
            scanf("%d", &pass_admin);
            fflush(stdin);
            if (strcmp(user_admin, "123456") == 0 && pass_admin == 123456)
            {
                system("cls");
                admin();
                system("cls");
            }
            else
            {
                printf("User dan Pass Admin anda SALAH\n");
                goto XY1;
            }
            break;
        default: printf("\n\n\t\tTidak Ditemukan");
            printf("\n\n\tPress Enter to re-Enter the choice");
            if(getch()==13)
            system("cls");
            goto XY;
    }

    return 0;
}

void reg() //void reg itu merupakan campuran modul 2, 8, 9, 10
{
    system("cls");
    FILE *data = fopen("akun.txt", "a"); //modul 8

    printf("Silahkan Masukkan Username dan Password anda\n");
    printf("Username\t: ");
    gets(user.username); //modul 10
    printf("Password\t: ");
    gets(user.password);
    printf("\n\n\tPress enter jika kamu setuju dengan Username dan Password\n");
    fprintf(data, "%s#%s\n", user.username, user.password);
    fclose(data); //modul 9

    system("cls");
    printf("\n\nKamu Sukses untuk didaftarkan");
    printf("\n\nCoba masuk??\n  ");
    printf("> PRESS 1 FOR YES\n\n> PRESS 2 FOR NO\n\n");
    scanf("%d",&n);
    fflush(stdin);
    switch(n)
    {
        case 1: system("cls");
            login();
        break;
        case 2: system("cls");
            printf("\n\n\nTerima kasih sudah untuk meregister di apalah ini namanya");
        break;
    }
}

void login() //void login itu merupakan campuran modul 2, 4, 8, 9, 10, 11
{
    FILE *data = fopen("akun.txt", "r");
    char c,nama[50],pass[50]; int z=0;
    int cek_user,cek_pass, i, kondisi;

    printf("Zona Login Akun");
    printf("\n-------------------");

    i = 0;
    n = 0;

    while(!feof(data)) //modul 2 dan 4
    {
        fscanf(data, "%[^#]#%s\n", &temp[i].username, &temp[i].password);
        n++;
        i++;
    }
    fclose(data);

    printf("\nMasukkan Username: ");
    gets(nama);
    printf("\nMasukkan Password: ");
    gets(pass);

    for (i = 0; i < n; i++)
    {
        if(strcmp(nama, temp[i].username) == 0 && strcmp(pass, temp[i].password) == 0)
        {
            strcpy(nama_histori,temp[i].username);
            menu_utama();
            kondisi = 0;
            break;
        }

        else
        {
            kondisi = 1;
        }
    }

    if(kondisi != 0)
    {
        printf("\nUsername atau Password tidak terdaftar silahkan login kembali!\n");
        system("pause");
        system("cls");
        login();
    }

}

void menu_utama() //void menu utama itu merupakan campuran modul 2, 5
{
    int i, na;
    int x[] = {total_harga};
    int *px = x;

    system("cls");
    menu:
    printf("---==Selamat Datang di Jasa Joki Game==---\n");
    printf("\n1. ML\t\t\t3. FF");
    printf("\n2. AOV\t\t\t4. PUBG");
    printf("\n5. List Harga\t\t98. Total belanja");
    printf("\n99. Keluar");
    printf("\n\nMasukkan pilihan kamu : ");
    scanf("%d", &pilih);
    system("cls");

    //Mobile Legend
    if(pilih==1){
    mole();
    }

    //AOV
    else if(pilih==2){
    aov();
    }
    //free fire
    else if(pilih==3){
    frefi();
    }

    //PUBG
    else if(pilih==4){
    pubg();
    }

    //List Harga
    else if(pilih==5){
    harga();
    }

    else if (pilih == 98){
    FILE *histori = fopen("histori.txt", "a+");
    fprintf(histori,"%s %s %d %d\n", nama_histori, hasil_game, pilih2, total_harga);
    fclose(histori);
    printf("Total Harga\n");
    printf("Akun %s memesan game %s dengan %d bintang sebesar Rp", nama_histori, hasil_game, pilih2);
    while (px != &(x[sizeof(x)/sizeof(*x)])) {
        printfcomma (*px);
        px++;
    }

    printf("\n\nApakah mau keMenu Utama\n");
    printf("> PRESS 1 FOR YES\t> PRESS 2 FOR NO\n\n");
    scanf("%d",&na);
    fflush(stdin);
    switch(na)
    {
        case 1: system("cls");
            menu_utama();
        break;
        case 2: system("cls");
            printf("Terima kasih sudah menggunakan jasa kami\n\n");
        break;
    }

    }
}

void mole() //void mole, aov, frefi, pubg itu merupakan campuran modul 1, 2, 3, 5
{
    int gm = 100000; int epic = 150000; int legend =230000; int match_mythics = 25000;
    int bintang_gm = 10000; int bintang_epic = 15000; int bintang_Legend = 19000;
    int akun_gm, akun_epic, akun_legend;
    strcpy(hasil_game, "Mobile_Legend");

    mole:
    system("cls");
    printf("Pilih Tipe Joki ML\n");
    printf("1.Paket Tier GM");
    printf("\n2.Paket Tier Epic ");
    printf("\n3.Paket Tier Legend");
    printf("\n4.Paket Match Mythic");
    printf("\n5.kembali\t0.Keluar");
    printf("\n\nMasukkan pilihan anda : ");
    scanf("%d", &pilih1);
    system("cls");

    pilmole:
    switch (pilih1){
    // GM - ML
        case 1 :
            system("cls");
            printf("Harga bintang yang tersedia di GM");
            printf("\n1. Bintang 1-5");
            printf("\n2. Kembali \t3. Menu utama \t0.Keluar");
            printf("\n\nMasukkan Pilihan : ");
            scanf("%d", &pilih2);
            system("cls");

            switch(pilih2)
            {
            case 1 :
                ulang1:
                printf("Mau berapa bintang GM : ");
                scanf("%d", &akun_gm);
                if (akun_gm <= 5)
                {
                    total_harga = total_harga + gm + (bintang_gm * akun_gm);
                }
                else{
                    printf("Maksimal cuma 5 bintang\n\n");
                    goto ulang1;
                }
                goto pilmole;
            break;
            case 2 :
                goto mole;
            break;
            case 3 :
                menu_utama();
            break;
            case 0 :
                printf("Terima kasih telah menggunakan jasa kami");
                return 0;
            break;
            }
        break;

    // Epic - ML
        case 2 :
            system("cls");
            printf("Harga bintang yang tersedia di Epic");
            printf("\n1. Bintang 1-5");
            printf("\n2. Kembali \t3. Menu utama \t0.Keluar");
            printf("\n\nMasukkan Pilihan : ");
            scanf("%d", &pilih2);
            system("cls");

            switch(pilih2)
            {
            case 1 :
                ulang2:
                printf("Mau berapa bintang GM : ");
                scanf("%d", &akun_epic);
                if (akun_epic <= 5)
                {
                    total_harga = total_harga + epic + (bintang_epic * akun_epic);
                }
                else{
                    printf("Maksimal cuma 5 bintang\n\n");
                    goto ulang2;
                }
                goto pilmole;
            break;
            case 2 :
                goto mole;
            break;
            case 3 :
                menu_utama();
            break;
            case 0 :
                printf("Terima kasih telah menggunakan jasa kami");
                return 0;
            break;
            }
        break;

    // Legend - ML
        case 3 :
            system("cls");
            printf("Harga bintang yang tersedia di Legend");
            printf("\n1. Bintang 1-5");
            printf("\n2. Kembali \t3. Menu utama \t0.Keluar");
            printf("\n\nMasukkan Pilihan : ");
            scanf("%d", &pilih2);
            system("cls");

            switch(pilih2)
            {
            case 1 :
                ulang3:
                printf("Mau berapa bintang Legend : ");
                scanf("%d", &akun_legend);
                if (akun_legend <= 5)
                {
                    total_harga = total_harga + legend + (bintang_Legend * akun_legend);
                }
                else{
                    printf("Maksimal cuma 5 bintang\n\n");
                    goto ulang3;
                }
                goto pilmole;
            break;
            case 2 :
                goto mole;
            break;
            case 3 :
                menu_utama();
            break;
            case 0 :
                printf("Terima kasih telah menggunakan jasa kami");
                return 0;
            break;
            }
        break;

    //Match_Mythic - ML
        case 4 :
            system("cls");
            printf("Harga per Match yang tersedia di Mythic");
            printf("\n1. Bintang 1-5");
            printf("\n2. Kembali \t3. Menu utama \t0.Keluar");
            printf("\n\nMasukkan Pilihan : ");
            scanf("%d", &pilih2);
            system("cls");

            switch(pilih2)
            {
            case 1 :
                ulang4:
                printf("Mau berapa Match : ");
                scanf("%d", &akun_legend);
                if (akun_legend <= 50)
                {
                    total_harga = total_harga + (match_mythics * akun_legend);
                }
                else{
                    printf("Maksimal cuma 50 kali match\n\n");
                    goto ulang4;
                }
                goto pilmole;
            break;
            case 2 :
                goto mole;
            break;
            case 3 :
                menu_utama();
            break;
            case 0 :
                printf("Terima kasih telah menggunakan jasa kami");
                return 0;
            break;
            }
        break;

        case 5 :
            menu_utama();
        break;

        case 0 :
            return 0;
        break;
    }
}

void aov()
{
    int diam = 100000; int conq = 130000; int graconq = 150000;
    int bintang_diam = 7000; int bintang_conq = 8000; int bintang_graconq = 10000;
    int bintang_aov = 0;
    strcpy(hasil_game, "Arena_of_Valor");

    menu_aov:
    system("cls");
    printf("Pilih Tipe Joki ML\n");
    printf("1.Paket Tier Diamond");
    printf("\n2.Paket Tier Conqueror");
    printf("\n3.Paket Tier Grand Conqueror");
    printf("\n4.kembali\t0.Keluar");
    printf("\n\nMasukkan pilihan anda : ");
    scanf("%d", &pilih1);
    system("cls");

    submenu_aov:
    switch (pilih1){
            // diamond -AOV
            case 1 :
                system("cls");
                printf("Harga bintang yang tersedia di Diamond");
                printf("\n1. Bintang 1-5");
                printf("\n2. Kembali \t3. Menu utama \t0.Keluar");
                printf("\n\nMasukkan Pilihan : ");
                scanf("%d", &pilih2);
                system("cls");

                switch(pilih2)
                {
                case 1 :
                    ulang1:
                    printf("Mau berapa bintang Diamond : ");
                    scanf("%d", &bintang_aov);
                    if (bintang_aov <= 5)
                    {
                      total_harga = total_harga + diam + (bintang_diam * bintang_aov);
                    }
                    else{
                        printf("Maksimal cuma 5 bintang\n\n");
                        goto ulang1;
                    }
                    goto submenu_aov;
                break;
                case 2 :
                    goto menu_aov;
                break;
                case 3 :
                    menu_utama();
                break;
                case 0 :
                    printf("Terima kasih telah menggunakan jasa kami");
                    return 0;
                break;
                }
            break;

            // Conqueror -AOV
            case 2 :
                system("cls");
                printf("Harga bintang yang tersedia di Conqueror");
                printf("\n1. Bintang 1-5");
                printf("\n2. Kembali \t3. Menu utama \t0.Keluar");
                printf("\n\nMasukkan Pilihan : ");
                scanf("%d", &pilih2);
                system("cls");

                switch(pilih2)
                {
                case 1 :
                    ulang2:
                    printf("Mau berapa bintang Conqueror : ");
                    scanf("%d", &bintang_aov);
                    if (bintang_aov <= 5)
                    {
                      total_harga = total_harga + conq + (bintang_conq * bintang_aov);
                    }
                    else{
                        printf("Maksimal cuma 5 bintang\n\n");
                        goto ulang2;
                    }
                    goto submenu_aov;
                break;
                case 2 :
                    goto menu_aov;
                break;
                case 3 :
                    menu_utama();
                break;
                case 0 :
                    printf("Terima kasih telah menggunakan jasa kami");
                    return 0;
                break;
                }
            break;


            // Grand Conqueror -AOV
            case 3 :
                system("cls");
                printf("Harga bintang yang tersedia di Grand Conqueror");
                printf("\n1. Bintang 1-5");
                printf("\n2. Kembali \t3. Menu utama \t0.Keluar");
                printf("\n\nMasukkan Pilihan : ");
                scanf("%d", &pilih2);
                system("cls");

                switch(pilih2)
                {
                case 1 :
                    ulang3:
                    printf("Mau berapa bintang Grand Conqueror : ");
                    scanf("%d", &bintang_aov);
                    if (bintang_aov <= 5)
                    {
                      total_harga = total_harga + graconq + (bintang_graconq * bintang_aov);
                    }
                    else{
                        printf("Maksimal cuma 5 bintang\n\n");
                        goto ulang3;
                    }
                    goto submenu_aov;
                break;
                case 2 :
                    goto menu_aov;
                break;
                case 3 :
                    menu_utama();
                break;
                case 0 :
                    printf("Terima kasih telah menggunakan jasa kami");
                    return 0;
                break;
                }
            break;

            case 4 :
                menu_utama();
            break;

            case 0 :
                return 0;
            break;
    }
}

void frefi() //M sayyid Abid
{
    int platinum = 100000; int diamond = 150000; int heroic =230000; int gold = 100000;
    int bintang_platinum = 10000; int bintang_diamond = 15000; int bintang_heroic = 18000; int bintang_gold = 5000;
    int akun_platinum, akun_diamond, akun_heroic, akun_gold;
    strcpy(hasil_game, "Free_Fire");

    ff:
    system("cls");
    printf("Pilih Tipe Joki FF\n");
    printf("1. Gold     = 100.000\n");
    printf("2. Platinum = 150.000\n");
    printf("3. Diamond  = 190.000\n");
    printf("4. Heroic   = 200.000\n");
    printf("5. Kembali		0.keluar");
    printf("\nMasukkan pilihan anda : ");
    scanf("%d", &pilih1);
    system("cls");

    menu_ff:
    switch (pilih1){
        // GOLD -FF
        case 1 :
            system("cls");
            printf("Harga bintang yang tersedia di Gold");
            printf("\n1. Bintang 1-3");
            printf("\n2. Kembali \t3. Menu utama \t0.Keluar");
            printf("\n\nMasukkan Pilihan : ");
            scanf("%d", &pilih2);
            system("cls");

            switch(pilih2)
            {
            case 1 :
                ulang1:
                printf("Mau berapa Divisi Gold : ");
                scanf("%d", &akun_gold);
                if (akun_gold <= 3)
                {
                    total_harga = total_harga + gold+ (bintang_gold * akun_gold);
                }
                else{
                    printf("Maksimal cuma 3 bintang\n\n");
                    goto ulang1;
                }
                goto menu_ff;
            break;
            case 2 :
                goto ff;
            break;
            case 3 :
                menu_utama();
            break;
            case 0 :
                printf("Terima kasih telah menggunakan jasa kami");
                return 0;
            break;
            }

        // PLATINUM -FF
        case 2 :
            system("cls");
            printf("Harga Divisi yang tersedia di Platinum");
            printf("\n1. Bintang 1-4");
            printf("\n2. Kembali \t3. Menu utama \t0.Keluar");
            printf("\n\nMasukkan Pilihan : ");
            scanf("%d", &pilih2);
            system("cls");

            switch(pilih2)
            {
            case 1 :
                ulang2:
                printf("Mau berapa Divisi Platinum : ");
                scanf("%d", &akun_platinum);
                if (akun_platinum <= 4)
                {
                    total_harga = total_harga + platinum+ (bintang_platinum * akun_platinum);
                }
                else{
                    printf("Maksimal cuma 4 Divisi\n\n");
                    goto ulang2;
                }
                goto menu_ff;
            break;
            case 2 :
                goto ff;
            break;
            case 3 :
                menu_utama();
            break;
            case 0 :
                printf("Terima kasih telah menggunakan jasa kami");
                return 0;
            break;
            }

        // Diamond -FF
        case 3 :
            system("cls");
            printf("Harga per Divisi yang tersedia di Diamond");
            printf("\n1. Bintang 1-4");
            printf("\n2. Kembali \t3. Menu utama \t0.Keluar");
            printf("\n\nMasukkan Pilihan : ");
            scanf("%d", &pilih2);
            system("cls");

            switch(pilih2)
            {
            case 1 :
                ulang3:
                printf("Mau berapa Divisi Diamond : ");
                scanf("%d", &akun_diamond);
                if (akun_platinum <= 4)
                {
                    total_harga = total_harga + diamond + (bintang_diamond * akun_diamond);
                }
                else{
                    printf("Maksimal cuma 4 Divisi\n\n");
                    goto ulang3;
                }
                goto menu_ff;
            break;
            case 2 :
                goto ff;
            break;
            case 3 :
                menu_utama();
            break;
            case 0 :
                printf("Terima kasih telah menggunakan jasa kami");
                return 0;
            break;
        }

        // Heroic -FF
        case 4 :
            system("cls");
            printf("Harga per Divisi yang tersedia di Heroic");
            printf("\n1. Bintang 1-4");
            printf("\n2. Kembali \t3. Menu utama \t0.Keluar");
            printf("\n\nMasukkan Pilihan : ");
            scanf("%d", &pilih2);
            system("cls");

            switch(pilih2)
            {
            case 1 :
                ulang4:
                printf("Mau berapa Divisi Heroic : ");
                scanf("%d", &akun_diamond);
                if (akun_platinum <= 4)
                {
                    total_harga = total_harga + heroic + (bintang_heroic * akun_heroic);
                }
                else{
                    printf("Maksimal cuma 4 Divisi\n\n");
                    goto ulang4;
                }
                goto menu_ff;
            break;
            case 2 :
                goto ff;
            break;
            case 3 :
                menu_utama();
            break;
            case 0 :
                printf("Terima kasih telah menggunakan jasa kami");
                return 0;
            break;
        }
        break;

        case 5 :
            menu_utama();
        break;

        case 0 :
            printf("Terima kasih telah menggunakan jasa kami");
            return 0;
        break;
    }
}

void pubg() //Rama Pratama
{
    int akun, totalpubg;
    strcpy(hasil_game, "PUBGM");
    menu_pubg:
    printf("List Harga Jasa Joki PUBG Mobile\n");
    printf("1.Silver - Gold = 70.000\n");
    printf("2.Gold - Platinum = 100.000\n");
    printf("3.Platinum - Diamond = 180.000\n");
    printf("4.Diamond - Crown = 200.000");
    printf("5.Crown - Ace = 300.000");
    printf("6.kembali		0.Keluar\n");
    printf("Masukkan Pilihan Anda : ");
    scanf("%d", &pilih);
        if(pilih==1){
            printf("Berapa akun yang ingin di joki : ");
            scanf("%d", &akun);
            totalpubg=70000*akun;
            printf("Total Harga Yang akan dibayar = %d", totalpubg);
        }
        if(pilih==2){
            printf("Berapa akun yang ingin di joki : ");
            scanf("%d", &akun);
            totalpubg=100000*akun;
            printf("Total Harga Yang akan dibayar = %d", totalpubg);
        }
        if(pilih==3){
            printf("Berapa akun yang ingin di joki : ");
            scanf("%d", &akun);
            totalpubg=180000*akun;
            printf("Total Harga Yang akan dibayar = %d", totalpubg);
        }
        if(pilih==4){
            printf("Berapa akun yang ingin di joki : ");
            scanf("%d", &akun);
            totalpubg=200000*akun;
            printf("Total Harga Yang akan dibayar = %d", totalpubg);
        }
        if(pilih==5){
            printf("Berapa akun yang ingin di joki : ");
            scanf("%d", &akun);
            totalpubg=300000*akun;
            printf("Total Harga Yang akan dibayar = %d", totalpubg);
        }
        if(pilih==6){
            goto menu_pubg;
        }
        if(pilih==0){
            printf("Terima kasih telah menggunakan jasa kami");
            return 0;
        }

}

void harga() //Rama Pratama
{
    printf("List Harga Mobile Legends\n");
    printf("Paketan : \n");
    printf("GM\t- Epic\t = Rp.100.000\n");
    printf("Epic\t- Legend = Rp.150.000\n");
    printf("Legend\t- Mythic = Rp.230.000\n");
    printf("Perbintang : \n");
    printf("GM\t\t= Rp.10000\n");
    printf("Epic\t\t= Rp.15000\n");
    printf("Legend\t\t= Rp.19000\n");
    printf("Mythic/Match\t= Rp.25000\n\n");

    printf("List Harga Arena Of Valor\n");
    printf("Paketan :\n");
    printf("Platinum - Diamond   = Rp.100.000\n");
    printf("Diamond  - Master    = Rp.130.000\n");
    printf("Master   - Conqueror = Rp.150.000\n");
    printf("Perbintang : \n");
    printf("Platinum  = Rp.6000\n");
    printf("Diamond   = Rp.7000\n");
    printf("Master	  = Rp.8000\n");
    printf("Conqueror = Rp.10.000\n\n");

    printf("List Harga PUBGM\n");
    printf("Bronze   - Silver    = Rp.50.000\n");
    printf("Silver   - Gold	     = Rp.70.000\n");
    printf("Gold     - Platinum  = Rp.100.000\n");
    printf("Platinum - Diamond   = Rp.180.000\n");
    printf("Diamond  - Crown     = Rp.200.000\n");
    printf("Crown	 - ACE	     = Rp.300.000\n\n");

    printf("List Harga Free Fire\n");
    printf("Diamond 1  - Master = Rp.150.000\n");
    printf("Platinum 4 - Master = Rp.190.000\n");
    printf("Platinum 3 - Master = Rp.200.000\n");
    printf("Platinum 2 - Master = Rp.210.000\n");
    printf("Gold 	   - Master = Rp.300.000\n");
    system("pause");
    system("cls");
    menu_utama();
}

void printfcomma (int naa) {
    if (naa < 1000) {
        printf ("%d", naa);
        return;
    }
    printfcomma (naa/1000);
    printf (",%03d", naa%1000);
}

void admin()
{
    FILE *histori = fopen("histori.txt", "a+");

    char cek_jumlah_akun_yang_ada_di_file; char pilih_admin;
    int jumlah_akun_yang_ada_di_file = 0;

    char nama_file[50][50], game_file[50][50];
    int bintang_file[50], total_file[50];

    while ((cek_jumlah_akun_yang_ada_di_file = fgetc(histori)) != EOF){
            if (cek_jumlah_akun_yang_ada_di_file == '\n'){
                jumlah_akun_yang_ada_di_file ++;
            }
        }
        jumlah_akun_yang_ada_di_file += 1;
        fseek(histori, 0, SEEK_SET);
        for (i = 0; i < jumlah_akun_yang_ada_di_file; i++){
            fscanf(histori,"%s %s %d %d", nama_file[i], game_file[i], &bintang_file[i], &total_file[i]);
        }
    fclose(histori);

    printf("Histori Pembelian\n\n");
        for(i = 0; i+1 < jumlah_akun_yang_ada_di_file; i++){
            printf("Data ke-%d : \n", i+1);
            printf("Akun %s memesan game %s dengan %d bintang sebesar Rp %d\n", nama_file[i], game_file[i], bintang_file[i], total_file[i]);
            printf("\n");
        }
        system("pause");
        printf("Kembali ke Halaman Utama Y/N? ");
        scanf("%c", &pilih_admin);

        switch(pilih_admin)
        {
            case 'y' : main(); break;
            case 'Y' : main(); break;
            case 'n' || 'N' : return 0; break;
        }

    return 0;
}

//CopyRight By:
//M Sayyid Abid SN
//Raif Haidar Darmawan
//Rama Pratama

//Licensed by:
//Lab Alpro - {PAL - NOL}

/*
Keterangan :
MODUL 1 : Tipe Data dan Komponen Algoritma
MODUL 2 : Percabangan
MODUL 3 : Perulangan
MODUL 4 : Array
MODUL 5 : Prosedur dan Fungsi
MODUL 6 : Sorting
MODUL 7 : Searching
MODUL 8 : Operasi File
MODUL 9 : Printf Formatting
MODUL 10 : Strings
MODUL 11 : Loop Control &
 Math Function
MODUL 12 : Pointers
*/
